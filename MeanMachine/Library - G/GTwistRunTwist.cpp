//
//  GTwistRunTwist.cpp
//  MeanMachine
//

#include "GTwistRunTwist.hpp"

namespace {

int PhaseIndex(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kPhaseB: return 1;
        case TwistDomain::kPhaseC: return 2;
        case TwistDomain::kPhaseD: return 3;
        case TwistDomain::kPhaseE: return 4;
        case TwistDomain::kPhaseF: return 5;
        case TwistDomain::kPhaseG: return 6;
        case TwistDomain::kPhaseH: return 7;
        case TwistDomain::kPhaseA:
        default:
            return 0;
    }
}

std::vector<TwistWorkSpaceSlot> PhaseSalts(const TwistDomain pDomain,
                                           const TwistWorkSpaceSlot pBaseSlot,
                                           const int pLaneCount) {
    const int aBase = static_cast<int>(pBaseSlot);
    const int aOffset = PhaseIndex(pDomain) * 18;
    
    std::vector<TwistWorkSpaceSlot> aResult;
    aResult.reserve(static_cast<std::size_t>(pLaneCount));
    for (int i = 0; i < pLaneCount; ++i) {
        aResult.push_back(static_cast<TwistWorkSpaceSlot>(aBase + aOffset + i));
    }
    return aResult;
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pLoopName,
                               const TwistDomain pDomain,
                               const GAXSFormat pFormat,
                               std::vector<int> pLaneCounts) {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pLoopName;
    aConfig.mStartLine = "// " + pStageName + " " + pLoopName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pLoopName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = true;
    aConfig.mLaneCounts = pLaneCounts;
    aConfig.mHasDomainMix = false;
    aConfig.mDomain = pDomain;
    aConfig.mIsNonKDF = true;
    aConfig.mSaltsOrbiterAssign = PhaseSalts(pDomain, Slot::kPhaseASaltOrbiterAssignA, 6);
    aConfig.mSaltsOrbiterUpdate = PhaseSalts(pDomain, Slot::kPhaseASaltOrbiterUpdateA, 6);
    aConfig.mSaltsWandererUpdate = PhaseSalts(pDomain, Slot::kPhaseASaltWandererUpdateA, 6);
    return aConfig;
}

GSeedRunStageConfig MakeTwist_AConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_A",
                                             "twist_loop_a",
                                             TwistDomain::kPhaseA,
                                             GAXSFormat::kN9,
                                             {3, 4, 4, 4});
    aConfig.mSlices = {
        {{Slot::kSource,
            Slot::kKeyRowReadA,
            Slot::kKeyRowReadB},
            Slot::kExpansionLaneA,
            false},
        
        {{Slot::kExpansionLaneA,
            Slot::kSource,
            Slot::kKeyRowReadA,
            Slot::kKeyRowReadB},
            Slot::kExpansionLaneB,
            true},
        
        {{Slot::kExpansionLaneB,
            Slot::kExpansionLaneA,
            Slot::kKeyRowReadA,
            Slot::kKeyRowReadB},
            Slot::kExpansionLaneC,
            false},
        
        {{Slot::kExpansionLaneC,
            Slot::kExpansionLaneB,
            Slot::kExpansionLaneA,
            Slot::kSource},
            Slot::kExpansionLaneD,
            true},
    };
    return aConfig;
}

GSeedRunStageConfig MakeTwist_BConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_B",
                                             "twist_loop_b",
                                             TwistDomain::kPhaseB,
                                             GAXSFormat::kN5,
                                             {4, 4, 4, 4});
    aConfig.mSlices = {
        {{Slot::kExpansionLaneD,
            Slot::kExpansionLaneC,
            Slot::kExpansionLaneB,
            Slot::kExpansionLaneA},
            Slot::kOperationLaneA,
            false},
        
        {{Slot::kOperationLaneA,
            Slot::kExpansionLaneD,
            Slot::kExpansionLaneC,
            Slot::kExpansionLaneB},
            Slot::kOperationLaneB,
            true},
        
        {{Slot::kOperationLaneB,
            Slot::kOperationLaneA,
            Slot::kExpansionLaneD,
            Slot::kExpansionLaneC},
            Slot::kOperationLaneC,
            false},
        
        {{Slot::kOperationLaneC,
            Slot::kOperationLaneB,
            Slot::kOperationLaneA,
            Slot::kExpansionLaneD},
            Slot::kOperationLaneD,
            true},
        
    };
    return aConfig;
}

GSeedRunStageConfig MakeTwist_CConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_C",
                                             "twist_loop_c",
                                             TwistDomain::kPhaseC,
                                             GAXSFormat::kN7,
                                             {4, 4, 4, 4});
    aConfig.mSlices = {
        {{Slot::kOperationLaneD,
            Slot::kOperationLaneC,
            Slot::kOperationLaneB,
            Slot::kOperationLaneA},
            Slot::kWorkLaneA,
            false},
        
        {{Slot::kWorkLaneA,
            Slot::kOperationLaneD,
            Slot::kOperationLaneC,
            Slot::kOperationLaneB},
            Slot::kWorkLaneB,
            true},
        
        {{Slot::kWorkLaneB,
            Slot::kWorkLaneA,
            Slot::kOperationLaneD,
            Slot::kOperationLaneC},
            Slot::kWorkLaneC,
            false},
        
        {{Slot::kWorkLaneC,
            Slot::kWorkLaneB,
            Slot::kWorkLaneA,
            Slot::kOperationLaneD},
            Slot::kWorkLaneD,
            true},
    };
    return aConfig;
}

GSeedRunStageConfig MakeTwist_DConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_D",
                                             "twist_loop_d",
                                             TwistDomain::kPhaseD,
                                             GAXSFormat::kN5,
                                             {4, 4, 4, 4});
    aConfig.mSlices = {
        {{Slot::kExpansionLaneD,
            Slot::kExpansionLaneC,
            Slot::kExpansionLaneB,
            Slot::kExpansionLaneA},
            Slot::kWorkLaneA,
            false},
        
        {{Slot::kWorkLaneA,
            Slot::kExpansionLaneD,
            Slot::kExpansionLaneC,
            Slot::kExpansionLaneB},
            Slot::kWorkLaneB,
            true},
        
        {{Slot::kWorkLaneB,
            Slot::kWorkLaneA,
            Slot::kExpansionLaneD,
            Slot::kExpansionLaneC},
            Slot::kWorkLaneC,
            false},
        
        {{Slot::kWorkLaneC,
            Slot::kWorkLaneB,
            Slot::kWorkLaneA,
            Slot::kExpansionLaneD},
            Slot::kWorkLaneD,
            true},
    };
    return aConfig;
}

} // namespace


GTwistRunTwist_A::GTwistRunTwist_A()
: mStage(MakeTwist_AConfig()) {
}

GTwistRunTwist_A::~GTwistRunTwist_A() {
}

void GTwistRunTwist_A::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_A::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_B::GTwistRunTwist_B()
: mStage(MakeTwist_BConfig()) {
}

GTwistRunTwist_B::~GTwistRunTwist_B() {
}

void GTwistRunTwist_B::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_B::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_C::GTwistRunTwist_C()
: mStage(MakeTwist_CConfig()) {
}

GTwistRunTwist_C::~GTwistRunTwist_C() {
}

void GTwistRunTwist_C::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_C::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_D::GTwistRunTwist_D()
: mStage(MakeTwist_DConfig()) {
}

GTwistRunTwist_D::~GTwistRunTwist_D() {
}

void GTwistRunTwist_D::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_D::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_D::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}
