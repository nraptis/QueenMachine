//
//  GSeedRunKDF_B.cpp
//  MeanMachine
//

#include "GSeedRunKDF_B.hpp"
#include "GQuick.hpp"
#include "Random.hpp"

#include <array>
#include <sstream>

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

const std::array<const char *, 8> kNonceVariableNames = {
    "aNonceByteA",
    "aNonceByteB",
    "aNonceByteC",
    "aNonceByteD",
    "aNonceByteE",
    "aNonceByteF",
    "aNonceByteG",
    "aNonceByteH",
};

std::string NonceLine(const GSymbol &pNonceSymbol,
                      const int pIndex) {
    std::ostringstream aLine;
    aLine << "[[maybe_unused]] std::uint64_t " << pNonceSymbol.mName
          << " = ((pNonce >> " << (pIndex * 8) << "U) & 0xFFULL);";
    return aLine.str();
}

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
                               GAXSFormat pFormat) {
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pBatchName;
    aConfig.mStartLine = "// " + pStageName + " " + pBatchName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pBatchName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = false;
    aConfig.mLaneCounts = {4, 4, 4, 4};
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

void AddKDF_BPrologue(TwistProgramBranch &pBranch) {
    pBranch.AddLine("// [kdf-b]");
    for (int i = 0; i < 8; ++i) {
        pBranch.AddLine(NonceLine(GSymbol::Var(kNonceVariableNames[static_cast<std::size_t>(i)]), i));
    }

    pBranch.AddLine("std::uint64_t aDomainWordIngress = pConstants->mIngress;");
    pBranch.AddLine("std::uint64_t aDomainWordScatter = pConstants->mScatter;");
    pBranch.AddLine("std::uint64_t aDomainWordCross = pConstants->mCross;");

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

GSeedRunStageConfig MakeKDF_B_AConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_B_A",
                                             "kdf_b_loop_a",
                                             GAXSFormat::kN5);
    aConfig.mSlices = {
        {{Slot::kWorkLaneD, Slot::kWorkLaneC, Slot::kWorkLaneB, Slot::kWorkLaneA},
         Slot::kExpansionLaneA,
         false},

        {{Slot::kExpansionLaneA, Slot::kWorkLaneD, Slot::kWorkLaneC, Slot::kWorkLaneB},
         Slot::kExpansionLaneB,
         true},

        {{Slot::kExpansionLaneB, Slot::kExpansionLaneA, Slot::kWorkLaneD, Slot::kWorkLaneC},
         Slot::kExpansionLaneC,
         false},

        {{Slot::kExpansionLaneC, Slot::kExpansionLaneB, Slot::kExpansionLaneA, Slot::kWorkLaneD},
         Slot::kExpansionLaneD,
         true},
    };
    return aConfig;
}

GSeedRunStageConfig MakeKDF_B_BConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_B_B",
                                             "kdf_b_loop_b",
                                             GAXSFormat::kN7);
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

GSeedRunStageConfig MakeKDF_B_CConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_B_C",
                                             "kdf_b_loop_c",
                                             GAXSFormat::kN9);
    aConfig.mSlices = {
        {{Slot::kOperationLaneD, Slot::kOperationLaneC, Slot::kOperationLaneB, Slot::kOperationLaneA},
         Slot::kExpansionLaneA,
         false},

        {{Slot::kExpansionLaneA, Slot::kOperationLaneD, Slot::kOperationLaneC, Slot::kOperationLaneB},
         Slot::kExpansionLaneB,
         true},

        {{Slot::kExpansionLaneB, Slot::kExpansionLaneA, Slot::kOperationLaneD, Slot::kOperationLaneC},
         Slot::kExpansionLaneC,
         false},

        {{Slot::kExpansionLaneC, Slot::kExpansionLaneB, Slot::kExpansionLaneA, Slot::kOperationLaneD},
         Slot::kExpansionLaneD,
         true},
    };
    return aConfig;
}

} // namespace

GSeedRunKDF_B_A::GSeedRunKDF_B_A()
: mStage(MakeKDF_B_AConfig()) {
}

GSeedRunKDF_B_A::~GSeedRunKDF_B_A() {
}

void GSeedRunKDF_B_A::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_B_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_B_A::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    AddKDF_BPrologue(pBranch);
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_B_B::GSeedRunKDF_B_B()
: mStage(MakeKDF_B_BConfig()) {
}

GSeedRunKDF_B_B::~GSeedRunKDF_B_B() {
}

void GSeedRunKDF_B_B::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_B_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_B_B::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_B_C::GSeedRunKDF_B_C()
: mStage(MakeKDF_B_CConfig()) {
}

GSeedRunKDF_B_C::~GSeedRunKDF_B_C() {
}

void GSeedRunKDF_B_C::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_B_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_B_C::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}
