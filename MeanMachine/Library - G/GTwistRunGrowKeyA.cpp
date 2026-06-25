//
//  GTwistRunGrowKeyA.cpp
//  MeanMachine
//

#include "GTwistRunGrowKeyA.hpp"

#include "GMemory.hpp"
#include "GShiftBox.hpp"
#include "Random.hpp"

namespace {

struct GrowKeyLoopRange {
    int             mLoopBegin = 0;
    std::string     mLoopBeginText;
    int             mLoopCeiling = S_BLOCK;
    std::string     mLoopEndText = "S_BLOCK";
};

void AddRawStatements(TwistProgramBranch &pBranch,
                      const std::vector<GStatement> &pStatements) {
    for (const GStatement &aStatement : pStatements) {
        if (aStatement.IsRawLine()) {
            pBranch.AddLine(aStatement.mRawLine);
        }
    }
}

std::vector<TwistWorkSpaceSlot> PhaseDSalts(const TwistWorkSpaceSlot pBaseSlot,
                                            const int pLaneCount) {
    const int aBase = static_cast<int>(pBaseSlot);

    std::vector<TwistWorkSpaceSlot> aResult;
    aResult.reserve(static_cast<std::size_t>(pLaneCount));
    for (int i = 0; i < pLaneCount; ++i) {
        aResult.push_back(static_cast<TwistWorkSpaceSlot>(aBase + i));
    }
    return aResult;
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pLoopName,
                               const GAssignType pAssignType,
                               std::vector<int> pLaneCounts,
                               const GrowKeyLoopRange &pRange) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pLoopName;
    aConfig.mStartLine = "// " + pStageName + " " + pLoopName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pLoopName + " (end)";
    aConfig.mFormat = GAXSFormat::kN5;
    aConfig.mIgnoreNonces = true;
    aConfig.mLaneCounts = pLaneCounts;
    aConfig.mHasDomainMix = false;
    aConfig.mAssignType = pAssignType;
    aConfig.mDomain = TwistDomain::kPhaseD;
    aConfig.mIsNonKDF = true;
    aConfig.mExpectedSkeletonCount = 6;
    aConfig.mLoopBegin = pRange.mLoopBegin;
    aConfig.mLoopBeginText = pRange.mLoopBeginText;
    aConfig.mLoopCeiling = pRange.mLoopCeiling;
    aConfig.mLoopEndText = pRange.mLoopEndText;
    aConfig.mHotPackCount = 12;
    aConfig.mSaltsOrbiterAssign = PhaseDSalts(Slot::kPhaseDSaltOrbiterAssignA, 6);
    aConfig.mSaltsOrbiterUpdate = PhaseDSalts(Slot::kPhaseDSaltOrbiterUpdateA, 6);
    aConfig.mSaltsWandererUpdate = PhaseDSalts(Slot::kPhaseDSaltWandererUpdateA, 6);
    aConfig.mAutoRangeAdjust = false;
    aConfig.mEmitGroupLaneFlowComments = false;
    return aConfig;
}

GrowKeyLoopRange RangeA() {
    GrowKeyLoopRange aRange;
    aRange.mLoopBegin = 0;
    aRange.mLoopCeiling = S_BLOCK >> 1;
    aRange.mLoopEndText = "(S_BLOCK >> 1)";
    return aRange;
}

GrowKeyLoopRange RangeB() {
    GrowKeyLoopRange aRange;
    aRange.mLoopBegin = S_BLOCK >> 1;
    aRange.mLoopBeginText = "(S_BLOCK >> 1)";
    aRange.mLoopCeiling = S_BLOCK;
    aRange.mLoopEndText = "S_BLOCK";
    return aRange;
}

std::vector<TwistWorkSpaceSlot> RandomizedSources(std::initializer_list<TwistWorkSpaceSlot> pSources) {
    std::vector<TwistWorkSpaceSlot> aSources(pSources);
    Random::Shuffle(&aSources);
    return aSources;
}

GSeedRunStageSliceSpec MakeSlice(std::vector<TwistWorkSpaceSlot> pSources,
                                 TwistWorkSpaceSlot pDest,
                                 bool pDestWriteInverted) {
    GSeedRunStageSliceSpec aSlice({}, pDest, pDestWriteInverted);
    aSlice.mSources = pSources;
    return aSlice;
}

GSeedRunStageConfig MakeExpandAConfig(const std::string &pStageName,
                                      const std::string &pLoopName,
                                      const GrowKeyLoopRange &pRange) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig(pStageName,
                                             pLoopName,
                                             GAssignType::kSet,
                                             {4, 4, 4, 4},
                                             pRange);
    aConfig.mSlices = {
        MakeSlice(RandomizedSources({
                      Slot::kWorkLaneA,
                      Slot::kWorkLaneB,
                      Slot::kWorkLaneC,
                      Slot::kWorkLaneD,
                  }),
                  Slot::kExpansionLaneA,
                  false),
    };
    return aConfig;
}

GSeedRunStageConfig MakeExpandBConfig(const std::string &pStageName,
                                      const std::string &pLoopName,
                                      const GrowKeyLoopRange &pRange) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig(pStageName,
                                             pLoopName,
                                             GAssignType::kSet,
                                             {4, 4, 4, 4},
                                             pRange);
    aConfig.mSlices = {
        MakeSlice(RandomizedSources({
                      Slot::kExpansionLaneA,
                      Slot::kWorkLaneB,
                      Slot::kWorkLaneC,
                      Slot::kWorkLaneD,
                  }),
                  Slot::kExpansionLaneB,
                  false),
    };
    return aConfig;
}

GSeedRunStageConfig MakeKeyRowConfig(const std::string &pStageName,
                                     const std::string &pLoopName,
                                     const GrowKeyLoopRange &pRange,
                                     const TwistWorkSpaceSlot pDest) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig(pStageName,
                                             pLoopName,
                                             GAssignType::kXorAssign,
                                             {2, 2, 2, 2},
                                             pRange);
    aConfig.mSlices = {
        MakeSlice(RandomizedSources({
                      Slot::kExpansionLaneA,
                      Slot::kExpansionLaneB,
                  }),
                  pDest,
                  false),
    };
    return aConfig;
}

bool AddShiftAndZero(TwistProgramBranch &pBranch,
                     const bool pUseKeyBoxA,
                     std::string *pErrorMessage) {
    std::vector<GStatement> aStatements;
    GShiftBox aShiftBox;
    if (pUseKeyBoxA) {
        if (!aShiftBox.BakeShiftKeyBoxA(&aStatements, pErrorMessage)) {
            return false;
        }
    } else {
        if (!aShiftBox.BakeShiftKeyBoxB(&aStatements, pErrorMessage)) {
            return false;
        }
    }

    GMemory aMemory;
    if (!aMemory.BakeZero(GSymbol::Buf(pUseKeyBoxA ?
                                       TwistWorkSpaceSlot::kKeyRowWriteA :
                                       TwistWorkSpaceSlot::kKeyRowWriteB),
                          W_KEY,
                          &aStatements,
                          pErrorMessage)) {
        return false;
    }
    AddRawStatements(pBranch, aStatements);
    return true;
}

} // namespace

GTwistRunGrowKeyA::GTwistRunGrowKeyA()
: mExpandAStage(MakeExpandAConfig("GTwistRunGrowKeyA",
                                  "grow_key_a_expand_a",
                                  RangeA())),
  mExpandBStage(MakeExpandBConfig("GTwistRunGrowKeyA",
                                  "grow_key_a_expand_b",
                                  RangeA())),
  mKeyRowStage(MakeKeyRowConfig("GTwistRunGrowKeyA",
                                "twist_key_box_loop_a",
                                RangeA(),
                                TwistWorkSpaceSlot::kKeyRowWriteA)) {
}

GTwistRunGrowKeyA::~GTwistRunGrowKeyA() {
}

void GTwistRunGrowKeyA::Reset() {
    mExpandAStage.Reset();
    mExpandBStage.Reset();
    mKeyRowStage.Reset();
}

bool GTwistRunGrowKeyA::Plan(std::string *pErrorMessage) {
    Reset();
    if (!mExpandAStage.Plan(pErrorMessage)) {
        return false;
    }
    if (!mExpandBStage.Plan(pErrorMessage)) {
        return false;
    }
    return mKeyRowStage.Plan(pErrorMessage);
}

bool GTwistRunGrowKeyA::Build(TwistProgramBranch &pBranch,
                              std::string *pErrorMessage) {
    pBranch.AddLine("// GTwistRunGrowKeyA PhaseD salts");
    if (!mExpandAStage.Build(pBranch, pErrorMessage)) {
        return false;
    }
    if (!mExpandBStage.Build(pBranch, pErrorMessage)) {
        return false;
    }

    if (!AddShiftAndZero(pBranch, true, pErrorMessage)) {
        return false;
    }

    return mKeyRowStage.Build(pBranch, pErrorMessage);
}

GTwistRunGrowKeyB::GTwistRunGrowKeyB()
: mExpandAStage(MakeExpandAConfig("GTwistRunGrowKeyB",
                                  "grow_key_b_expand_a",
                                  RangeB())),
  mExpandBStage(MakeExpandBConfig("GTwistRunGrowKeyB",
                                  "grow_key_b_expand_b",
                                  RangeB())),
  mKeyRowStage(MakeKeyRowConfig("GTwistRunGrowKeyB",
                                "twist_key_box_loop_b",
                                RangeB(),
                                TwistWorkSpaceSlot::kKeyRowWriteB)) {
}

GTwistRunGrowKeyB::~GTwistRunGrowKeyB() {
}

void GTwistRunGrowKeyB::Reset() {
    mExpandAStage.Reset();
    mExpandBStage.Reset();
    mKeyRowStage.Reset();
}

bool GTwistRunGrowKeyB::Plan(std::string *pErrorMessage) {
    Reset();
    if (!mExpandAStage.Plan(pErrorMessage)) {
        return false;
    }
    if (!mExpandBStage.Plan(pErrorMessage)) {
        return false;
    }
    return mKeyRowStage.Plan(pErrorMessage);
}

bool GTwistRunGrowKeyB::Build(TwistProgramBranch &pBranch,
                              std::string *pErrorMessage) {
    pBranch.AddLine("// GTwistRunGrowKeyB PhaseD salts");
    if (!mExpandAStage.Build(pBranch, pErrorMessage)) {
        return false;
    }
    if (!mExpandBStage.Build(pBranch, pErrorMessage)) {
        return false;
    }

    if (!AddShiftAndZero(pBranch, false, pErrorMessage)) {
        return false;
    }

    return mKeyRowStage.Build(pBranch, pErrorMessage);
}
