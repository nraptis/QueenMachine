//
//  GSeedRunKDF_A.cpp
//  MeanMachine
//

#include "GSeedRunKDF_A.hpp"
#include "GQuick.hpp"
#include "Random.hpp"

#include <array>

namespace {

const std::array<TwistVariable, 13> kInitialRandomVariables = {
    TwistVariable::kPrevious,
    TwistVariable::kCarry,
    TwistVariable::kWandererA,
    TwistVariable::kWandererB,
    TwistVariable::kWandererC,
    TwistVariable::kWandererD,
    TwistVariable::kWandererE,
    TwistVariable::kWandererF,
    TwistVariable::kWandererG,
    TwistVariable::kWandererH,
    TwistVariable::kWandererI,
    TwistVariable::kWandererJ,
    TwistVariable::kWandererK,
};

std::vector<TwistWorkSpaceSlot> ParamOrbiterAssignSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltOrbiterAssignA,
        Slot::kParamDomainSaltOrbiterAssignB,
        Slot::kParamDomainSaltOrbiterAssignC,
        Slot::kParamDomainSaltOrbiterAssignD,
        Slot::kParamDomainSaltOrbiterAssignE,
        Slot::kParamDomainSaltOrbiterAssignF,
    };
}

std::vector<TwistWorkSpaceSlot> ParamOrbiterUpdateSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltOrbiterUpdateA,
        Slot::kParamDomainSaltOrbiterUpdateB,
        Slot::kParamDomainSaltOrbiterUpdateC,
        Slot::kParamDomainSaltOrbiterUpdateD,
        Slot::kParamDomainSaltOrbiterUpdateE,
        Slot::kParamDomainSaltOrbiterUpdateF,
    };
}

std::vector<TwistWorkSpaceSlot> ParamWandererUpdateSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltWandererUpdateA,
        Slot::kParamDomainSaltWandererUpdateB,
        Slot::kParamDomainSaltWandererUpdateC,
        Slot::kParamDomainSaltWandererUpdateD,
        Slot::kParamDomainSaltWandererUpdateE,
        Slot::kParamDomainSaltWandererUpdateF,
    };
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pBatchName,
                               GAXSFormat pFormat,
                               std::vector<int> pLaneCounts) {
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pBatchName;
    aConfig.mStartLine = "// " + pStageName + " " + pBatchName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pBatchName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = false;
    aConfig.mLaneCounts = pLaneCounts;
    aConfig.mHasDomainMix = true;
    aConfig.mDomain = TwistDomain::kInvalid;
    aConfig.mIsNonKDF = false;
    aConfig.mExpectedSkeletonCount = 6;
    aConfig.mLoopCeiling = S_BLOCK;
    aConfig.mLoopEndText = "S_BLOCK";
    aConfig.mHotPackCount = 12;
    aConfig.mSaltsOrbiterAssign = ParamOrbiterAssignSalts();
    aConfig.mSaltsOrbiterUpdate = ParamOrbiterUpdateSalts();
    aConfig.mSaltsWandererUpdate = ParamWandererUpdateSalts();
    return aConfig;
}

void AddKDF_APrologue(TwistProgramBranch &pBranch) {
    pBranch.AddLine("// [kdf-a]");
    pBranch.AddLine("std::uint64_t aDomainWordIngress = pConstants->mIngress;");
    pBranch.AddLine("std::uint64_t aDomainWordScatter = pConstants->mScatter;");
    pBranch.AddLine("std::uint64_t aDomainWordCross = pConstants->mCross;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;");

    GBatch aInitBatch;
    aInitBatch.mName = "init varz";

    std::vector<GStatement> aInitStatements;
    for (TwistVariable aVariable : kInitialRandomVariables) {
        aInitStatements.push_back(
            GQuick::MakeAssignVariableStatement(GSymbol::Var(aVariable),
                                                GExpr::Const(Random::Get64High())));
    }
    aInitBatch.CommitStatements(&aInitStatements);
    pBranch.AddBatch(aInitBatch);
}

GSeedRunStageConfig MakeKDF_A_AConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_A",
                                             "kdf_a_loop_a",
                                             GAXSFormat::kN11,
                                             {2, 3, 4, 4, 4, 4});
    aConfig.mSlices = {
        {{Slot::kSource, Slot::kSnow},
         Slot::kWorkLaneA,
         false},
        
        {{Slot::kSource, Slot::kSnow, Slot::kWorkLaneA},
         Slot::kWorkLaneB,
         true},
        
        {{Slot::kSource, Slot::kSnow, Slot::kWorkLaneA, Slot::kWorkLaneB},
         Slot::kExpansionLaneA,
         false},
        
        {{Slot::kSnow, Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kExpansionLaneA},
         Slot::kExpansionLaneB,
         true},
        
        {{Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kExpansionLaneA, Slot::kExpansionLaneB},
         Slot::kExpansionLaneC,
         false},
        
        {{Slot::kWorkLaneB, Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC},
         Slot::kExpansionLaneD,
         true},
    };
    return aConfig;
}

GSeedRunStageConfig MakeKDF_A_BConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_B",
                                             "kdf_a_loop_b",
                                             GAXSFormat::kN9,
                                             {4, 4, 4, 4});
    aConfig.mIgnoreNonces = true;
    aConfig.mHasDomainMix = false;
    
    aConfig.mSlices = {
        {{Slot::kExpansionLaneD, Slot::kExpansionLaneC, Slot::kExpansionLaneB, Slot::kExpansionLaneA},
         Slot::kOperationLaneA,
         false},

        {{Slot::kOperationLaneA, Slot::kExpansionLaneD, Slot::kExpansionLaneC, Slot::kExpansionLaneB},
         Slot::kOperationLaneB,
         true},

        {{Slot::kOperationLaneB, Slot::kOperationLaneA, Slot::kExpansionLaneD, Slot::kExpansionLaneC},
         Slot::kOperationLaneC,
         false},

        {{Slot::kOperationLaneC, Slot::kOperationLaneB, Slot::kOperationLaneA, Slot::kExpansionLaneD},
         Slot::kOperationLaneD,
         true},
    };
    return aConfig;
}

GSeedRunStageConfig MakeKDF_A_CConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_C",
                                             "kdf_a_loop_c",
                                             GAXSFormat::kN5,
                                             {4, 4, 4, 4});
    aConfig.mIgnoreNonces = true;
    aConfig.mHasDomainMix = false;
    
    aConfig.mSlices = {
        {{Slot::kOperationLaneD, Slot::kOperationLaneC, Slot::kOperationLaneB, Slot::kOperationLaneA},
         Slot::kWorkLaneA,
         false},

        {{Slot::kWorkLaneA, Slot::kOperationLaneD, Slot::kOperationLaneC, Slot::kOperationLaneB},
         Slot::kWorkLaneB,
         true},

        {{Slot::kWorkLaneB, Slot::kWorkLaneA, Slot::kOperationLaneD, Slot::kOperationLaneC},
         Slot::kWorkLaneC,
         false},

        {{Slot::kWorkLaneC, Slot::kWorkLaneB, Slot::kWorkLaneA, Slot::kOperationLaneD},
         Slot::kWorkLaneD,
         true},
    };
    return aConfig;
}

GSeedRunStageConfig MakeKDF_A_DConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_D",
                                             "kdf_a_loop_d",
                                             GAXSFormat::kN7,
                                             {4, 4, 4, 4});
    aConfig.mIgnoreNonces = true;
    aConfig.mHasDomainMix = false;
    
    aConfig.mSlices = {
        {{Slot::kExpansionLaneD, Slot::kExpansionLaneC, Slot::kExpansionLaneB, Slot::kExpansionLaneA},
         Slot::kWorkLaneA,
         false},

        {{Slot::kWorkLaneA, Slot::kExpansionLaneD, Slot::kExpansionLaneC, Slot::kExpansionLaneB},
         Slot::kWorkLaneB,
         true},

        {{Slot::kWorkLaneB, Slot::kWorkLaneA, Slot::kExpansionLaneD, Slot::kExpansionLaneC},
         Slot::kWorkLaneC,
         false},

        {{Slot::kWorkLaneC, Slot::kWorkLaneB, Slot::kWorkLaneA, Slot::kExpansionLaneD},
         Slot::kWorkLaneD,
         true},
    };
    return aConfig;
}

} // namespace

GSeedRunKDF_A_A::GSeedRunKDF_A_A()
: mStage(MakeKDF_A_AConfig()) {
}

GSeedRunKDF_A_A::~GSeedRunKDF_A_A() {
}

void GSeedRunKDF_A_A::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_A::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    AddKDF_APrologue(pBranch);
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_B::GSeedRunKDF_A_B()
: mStage(MakeKDF_A_BConfig()) {
}

GSeedRunKDF_A_B::~GSeedRunKDF_A_B() {
}

void GSeedRunKDF_A_B::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_B::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_C::GSeedRunKDF_A_C()
: mStage(MakeKDF_A_CConfig()) {
}

GSeedRunKDF_A_C::~GSeedRunKDF_A_C() {
}

void GSeedRunKDF_A_C::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_C::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_D::GSeedRunKDF_A_D()
: mStage(MakeKDF_A_DConfig()) {
}

GSeedRunKDF_A_D::~GSeedRunKDF_A_D() {
}

void GSeedRunKDF_A_D::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_D::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_D::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}
