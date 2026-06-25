//
//  GSeedRunStage.hpp
//  MeanMachine
//

#ifndef GSeedRunStage_hpp
#define GSeedRunStage_hpp

#include "CSPRNGV2.hpp"
#include "GMagicNumbers.hpp"
#include "GTwistExpander.hpp"
#include <cstddef>
#include <cstdio>
#include <initializer_list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct GSeedRunStageSliceSpec {
    GSeedRunStageSliceSpec(std::initializer_list<TwistWorkSpaceSlot> pSources,
                           TwistWorkSpaceSlot pDest,
                           bool pDestWriteInverted)
    : mSources(pSources),
      mDest(pDest),
      mDestWriteInverted(pDestWriteInverted) {
    }

    std::vector<TwistWorkSpaceSlot>         mSources;
    TwistWorkSpaceSlot                      mDest;
    bool                                    mDestWriteInverted;
};

struct GSeedRunStageConfig {
    std::string                             mStageName;
    std::string                             mBatchName;
    std::string                             mStartLine;
    std::string                             mEndLine;

    GAXSFormat                              mFormat = GAXSFormat::kInvalid;
    bool                                    mIgnoreNonces = false;
    std::vector<int>                        mLaneCounts;
    bool                                    mHasDomainMix = true;
    GAssignType                             mAssignType = GAssignType::kSet;
    TwistDomain                             mDomain = TwistDomain::kInvalid;
    bool                                    mIsNonKDF = true;
    int                                     mExpectedSkeletonCount = 6;
    int                                     mLoopBegin = 0;
    std::string                             mLoopBeginText;
    int                                     mLoopCeiling = S_BLOCK;
    std::string                             mLoopEndText = "S_BLOCK";
    int                                     mHotPackCount = 12;
    bool                                    mAutoRangeAdjust = true;
    bool                                    mEmitLaneFlowComments = true;
    bool                                    mEmitGroupLaneFlowComments = true;

    std::vector<TwistWorkSpaceSlot>         mSaltsOrbiterAssign;
    std::vector<TwistWorkSpaceSlot>         mSaltsOrbiterUpdate;
    std::vector<TwistWorkSpaceSlot>         mSaltsWandererUpdate;
    std::vector<GSeedRunStageSliceSpec>     mSlices;
};

class GSeedRunStage {
public:
    explicit GSeedRunStage(GSeedRunStageConfig pConfig)
    : mConfig(std::move(pConfig)) {
        Reset();
    }

    void Reset() {
        mSaltsOrbiterAssign = SymbolsForSlots(mConfig.mSaltsOrbiterAssign);
        mSaltsOrbiterUpdate = SymbolsForSlots(mConfig.mSaltsOrbiterUpdate);
        mSaltsWandererUpdate = SymbolsForSlots(mConfig.mSaltsWandererUpdate);
        mARXSkeletons.clear();
        mHotPacks = GMagicNumbers::GetHotPacks(mConfig.mHotPackCount);
    }

    bool Plan(std::string *pErrorMessage) {
        ClearError(pErrorMessage);
        Reset();

        GAXSK aAXSK;
        if (!aAXSK.Bake(mConfig.mFormat,
                        mConfig.mIgnoreNonces,
                        mConfig.mLaneCounts,
                        mConfig.mHasDomainMix,
                        mConfig.mAssignType,
                        &mARXSkeletons,
                        pErrorMessage)) {
            if ((pErrorMessage != nullptr) && pErrorMessage->empty()) {
                *pErrorMessage = "GAXSK::Bake failed while planning " + mConfig.mStageName;
            }
            return false;
        }

        return true;
    }

    bool Build(TwistProgramBranch &pBranch,
               std::string *pErrorMessage) {
        ClearError(pErrorMessage);

        if (mARXSkeletons.size() != static_cast<std::size_t>(mConfig.mExpectedSkeletonCount)) {
            SetError(pErrorMessage, mConfig.mStageName + " had incorrect GAXSK skeleton counts");
            return false;
        }

        if (mHotPacks.size() < mConfig.mSlices.size()) {
            SetError(pErrorMessage, mConfig.mStageName + " had insufficient hot packs");
            return false;
        }

        if (mARXSkeletons.size() < mConfig.mSlices.size()) {
            SetError(pErrorMessage, mConfig.mStageName + " had fewer skeletons than slices");
            return false;
        }

        if (!mConfig.mStartLine.empty()) {
            pBranch.AddLine(mConfig.mStartLine);
        }

        std::vector<CSPRNGV2Slice> aSlices;
        for (std::size_t aIndex = 0; aIndex < mConfig.mSlices.size(); ++aIndex) {
            const GSeedRunStageSliceSpec &aSpec = mConfig.mSlices[aIndex];
            if (aSpec.mSources.size() > 4U) {
                SetError(pErrorMessage,
                         mConfig.mStageName + " " + mConfig.mBatchName +
                         " slice " + std::to_string(aIndex + 1U) +
                         " had more than 4 input lanes");
                return false;
            }

            CSPRNGV2Slice aSlice = {};
            aSlice.mARXSkeleton = mARXSkeletons[aIndex];
            aSlice.mDest = GSymbol::Buf(aSpec.mDest);
            aSlice.mDestWriteInverted = aSpec.mDestWriteInverted;
            aSlice.mHotPack = mHotPacks[aIndex];
            aSlice.mLoopBegin = mConfig.mLoopBegin;
            aSlice.mLoopBeginText = mConfig.mLoopBeginText;
            aSlice.mLoopCeiling = mConfig.mLoopCeiling;
            aSlice.mLoopEndText = mConfig.mLoopEndText;

            for (TwistWorkSpaceSlot aSlot : aSpec.mSources) {
                aSlice.mSources.push_back(GSymbol::Buf(aSlot));
            }

            aSlices.push_back(aSlice);
        }

        std::vector<GLoop> aLoops;
        if (!CSPRNGV2::Bake(mConfig.mIsNonKDF,
                            mConfig.mDomain,
                            aSlices,
                            mSaltsOrbiterAssign,
                            mSaltsOrbiterUpdate,
                            mSaltsWandererUpdate,
                            &aLoops,
                            mConfig.mAutoRangeAdjust,
                            pErrorMessage)) {
            const char *aErrorText = (pErrorMessage != nullptr) ? pErrorMessage->c_str() : "unknown error";
            std::printf("error with CSPRNGV2::Bake %s => %s\n",
                        mConfig.mStageName.c_str(),
                        aErrorText);
            return false;
        }

        GBatch aBatch;
        aBatch.mName = mConfig.mBatchName;
        if (mConfig.mEmitLaneFlowComments &&
            mConfig.mEmitGroupLaneFlowComments &&
            (mConfig.mSlices.size() > 1U)) {
            AddLaneFlowCommentBlock(&aBatch,
                                    mConfig.mStageName + " " + mConfig.mBatchName + " lane group",
                                    CollectGroupReadSlots(),
                                    CollectGroupWriteSlots(),
                                    true);
        }
        for (std::size_t aIndex = 0U; aIndex < aLoops.size(); ++aIndex) {
            GLoop aLoop = aLoops[aIndex];
            if (mConfig.mEmitLaneFlowComments && (aIndex < mConfig.mSlices.size())) {
                const GSeedRunStageSliceSpec &aSpec = mConfig.mSlices[aIndex];
                AddLoopLaneFlowComments(&aLoop,
                                        mConfig.mBatchName + " loop " + std::to_string(aIndex + 1U),
                                        aSpec.mSources,
                                        { aSpec.mDest });
            }
            aBatch.CommitLoop(aLoop);
        }
        pBranch.AddBatch(aBatch);

        if (!mConfig.mEndLine.empty()) {
            pBranch.AddLine(mConfig.mEndLine);
        }

        return true;
    }

private:
    static void ClearError(std::string *pErrorMessage) {
        if (pErrorMessage != nullptr) {
            pErrorMessage->clear();
        }
    }

    static void SetError(std::string *pErrorMessage,
                         const std::string &pMessage) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = pMessage;
        }
    }

    static std::vector<GSymbol> SymbolsForSlots(const std::vector<TwistWorkSpaceSlot> &pSlots) {
        std::vector<GSymbol> aResult;
        aResult.reserve(pSlots.size());

        for (TwistWorkSpaceSlot aSlot : pSlots) {
            aResult.push_back(GSymbol::Buf(aSlot));
        }

        return aResult;
    }

    static void AppendUniqueSlot(std::vector<TwistWorkSpaceSlot> *pSlots,
                                 const TwistWorkSpaceSlot pSlot) {
        if (pSlots == nullptr) {
            return;
        }
        for (TwistWorkSpaceSlot aSlot : *pSlots) {
            if (aSlot == pSlot) {
                return;
            }
        }
        pSlots->push_back(pSlot);
    }

    static std::string AssignSuffix(const GAssignType pAssignType) {
        switch (pAssignType) {
            case GAssignType::kAddAssign: return " (+=)";
            case GAssignType::kXorAssign: return " (^=)";
            case GAssignType::kOrAssign: return " (|=)";
            default: return "";
        }
    }

    static std::string JoinLaneNames(const std::vector<TwistWorkSpaceSlot> &pSlots,
                                     const GAssignType pAssignType = GAssignType::kSet) {
        if (pSlots.empty()) {
            return "(none)";
        }

        std::ostringstream aStream;
        for (std::size_t aIndex = 0U; aIndex < pSlots.size(); ++aIndex) {
            if (aIndex > 0U) {
                aStream << ", ";
            }
            aStream << BufAliasName(pSlots[aIndex]);
            if (pAssignType != GAssignType::kSet) {
                aStream << AssignSuffix(pAssignType);
            }
        }
        return aStream.str();
    }

    std::vector<TwistWorkSpaceSlot> CollectGroupReadSlots() const {
        std::vector<TwistWorkSpaceSlot> aResult;
        for (const GSeedRunStageSliceSpec &aSpec : mConfig.mSlices) {
            for (TwistWorkSpaceSlot aSlot : aSpec.mSources) {
                AppendUniqueSlot(&aResult, aSlot);
            }
        }
        return aResult;
    }

    std::vector<TwistWorkSpaceSlot> CollectGroupWriteSlots() const {
        std::vector<TwistWorkSpaceSlot> aResult;
        for (const GSeedRunStageSliceSpec &aSpec : mConfig.mSlices) {
            AppendUniqueSlot(&aResult, aSpec.mDest);
        }
        return aResult;
    }

    static std::vector<GStatement> LaneFlowCommentStatements(const std::string &pTitle,
                                                             const std::vector<TwistWorkSpaceSlot> &pReadSlots,
                                                             const std::vector<TwistWorkSpaceSlot> &pWriteSlots,
                                                             const GAssignType pAssignType) {
        std::vector<GStatement> aStatements;
        aStatements.push_back(GStatement::Comment(pTitle));
        aStatements.push_back(GStatement::Comment("read from: " + JoinLaneNames(pReadSlots)));
        aStatements.push_back(GStatement::Comment("write to: " + JoinLaneNames(pWriteSlots, pAssignType)));
        return aStatements;
    }

    void AddLaneFlowCommentBlock(GBatch *pBatch,
                                 const std::string &pTitle,
                                 const std::vector<TwistWorkSpaceSlot> &pReadSlots,
                                 const std::vector<TwistWorkSpaceSlot> &pWriteSlots,
                                 const bool pUseAssignSuffix) const {
        if (pBatch == nullptr) {
            return;
        }
        std::vector<GStatement> aStatements = LaneFlowCommentStatements(
            pTitle,
            pReadSlots,
            pWriteSlots,
            pUseAssignSuffix ? mConfig.mAssignType : GAssignType::kSet);
        pBatch->CommitStatements(&aStatements);
    }

    void AddLoopLaneFlowComments(GLoop *pLoop,
                                 const std::string &pTitle,
                                 const std::vector<TwistWorkSpaceSlot> &pReadSlots,
                                 const std::vector<TwistWorkSpaceSlot> &pWriteSlots) const {
        if (pLoop == nullptr) {
            return;
        }
        std::vector<GStatement> aStatements = LaneFlowCommentStatements(
            pTitle,
            pReadSlots,
            pWriteSlots,
            mConfig.mAssignType);
        pLoop->mInitializationStatements.insert(pLoop->mInitializationStatements.begin(),
                                                aStatements.begin(),
                                                aStatements.end());
    }

    GSeedRunStageConfig                     mConfig;
    std::vector<GSymbol>                    mSaltsOrbiterAssign;
    std::vector<GSymbol>                    mSaltsOrbiterUpdate;
    std::vector<GSymbol>                    mSaltsWandererUpdate;
    std::vector<GAXSKSkeleton>              mARXSkeletons;
    std::vector<GHotPack>                   mHotPacks;
};

#endif /* GSeedRunStage_hpp */
