//
//  GSeedRunSeed.cpp
//  MeanMachine
//

#include "GSeedRunSeed.hpp"
#include "Random.hpp"

#include <array>
#include <sstream>

namespace {

const std::array<const char *, 8> kNonceVariableNames = {
    "aNonceWordA",
    "aNonceWordB",
    "aNonceWordC",
    "aNonceWordD",
    "aNonceWordE",
    "aNonceWordF",
    "aNonceWordG",
    "aNonceWordH",
};

const std::array<const char *, 3> kNonceDiffuseNames = {
    "DiffuseA",
    "DiffuseB",
    "DiffuseC",
};

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

char PhaseLetterLower(const TwistDomain pDomain) {
    return static_cast<char>('a' + PhaseIndex(pDomain));
}

std::string SeedLoopName(const TwistDomain pDomain) {
    std::string aResult = "seed_loop_";
    aResult.push_back(PhaseLetterLower(pDomain));
    return aResult;
}

std::string UInt64Literal(const std::uint64_t pValue) {
    std::ostringstream aStream;
    aStream << "0x" << std::uppercase << std::hex << pValue << "ULL";
    return aStream.str();
}

const char *RandomNonceDiffuseName() {
    return kNonceDiffuseNames[static_cast<std::size_t>(Random::Get(static_cast<int>(kNonceDiffuseNames.size())))];
}

std::string NonceDeclareLine(const GSymbol &pNonceSymbol,
                             const int pIndex) {
    (void)pIndex;
    const std::uint64_t aMultiplyWord = Random::Get64HighOdd();
    const std::uint64_t aAddWord = Random::Get64High();
    const char *aDiffuseName = RandomNonceDiffuseName();

    std::ostringstream aLine;
    aLine << "std::uint64_t " << pNonceSymbol.mName << " = TwistMix64::"
          << aDiffuseName
          << "(pNonce * "
          << UInt64Literal(aMultiplyWord)
          << " + "
          << UInt64Literal(aAddWord) << ");";
    return aLine.str();
}

void AddSeedNoncePrologue(TwistProgramBranch &pBranch) {
    for (int i = 0; i < 8; ++i) {
        pBranch.AddLine(NonceDeclareLine(GSymbol::Var(kNonceVariableNames[static_cast<std::size_t>(i)]), i));
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
                               const TwistDomain pDomain,
                               const bool pUseNonces,
                               const GAXSFormat pFormat,
                               std::vector<int> pLaneCounts) {
    using Slot = TwistWorkSpaceSlot;

    const std::string aLoopName = SeedLoopName(pDomain);

    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = aLoopName;
    aConfig.mStartLine = "// " + pStageName + " " + aLoopName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + aLoopName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = !pUseNonces;
    aConfig.mLaneCounts = pLaneCounts;
    aConfig.mHasDomainMix = true;
    aConfig.mDomain = pDomain;
    aConfig.mIsNonKDF = true;
    aConfig.mExpectedSkeletonCount = 6;
    aConfig.mLoopCeiling = S_BLOCK;
    aConfig.mLoopEndText = "S_BLOCK";
    aConfig.mHotPackCount = 12;
    aConfig.mSaltsOrbiterAssign = PhaseSalts(pDomain, Slot::kPhaseASaltOrbiterAssignA, 6);
    aConfig.mSaltsOrbiterUpdate = PhaseSalts(pDomain, Slot::kPhaseASaltOrbiterUpdateA, 6);
    aConfig.mSaltsWandererUpdate = PhaseSalts(pDomain, Slot::kPhaseASaltWandererUpdateA, 6);
    return aConfig;
}

GSeedRunStageConfig MakeSeed_AConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_A",
                                             TwistDomain::kPhaseA,
                                             pUseNonces,
                                             GAXSFormat::kN7,
                                             {3, 4, 4, 4});
    aConfig.mSlices = {
        {{Slot::kSource,
          Slot::kKeyBoxUnrolledA,
          Slot::kKeyBoxUnrolledB},
         Slot::kExpansionLaneA,
         false},

        {{Slot::kExpansionLaneA,
          Slot::kSource,
          Slot::kKeyBoxUnrolledA,
          Slot::kKeyBoxUnrolledB},
         Slot::kExpansionLaneB,
         true},

        {{Slot::kExpansionLaneB,
          Slot::kExpansionLaneA,
          Slot::kKeyBoxUnrolledA,
          Slot::kKeyBoxUnrolledB},
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

GSeedRunStageConfig MakeSeed_BConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_B",
                                             TwistDomain::kPhaseB,
                                             pUseNonces,
                                             GAXSFormat::kN11,
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

GSeedRunStageConfig MakeSeed_CConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_C",
                                             TwistDomain::kPhaseC,
                                             pUseNonces,
                                             GAXSFormat::kN9,
                                             {4, 4, 4, 4});
    
    aConfig.mSlices = {
        {{Slot::kOperationLaneD,
          Slot::kOperationLaneC,
          Slot::kOperationLaneB,
          Slot::kOperationLaneA},
         Slot::kWorkLaneA,
         true},

        {{Slot::kWorkLaneA,
          Slot::kOperationLaneD,
          Slot::kOperationLaneC,
          Slot::kOperationLaneB},
         Slot::kWorkLaneB,
         false},

        {{Slot::kWorkLaneB,
          Slot::kWorkLaneA,
          Slot::kOperationLaneD,
          Slot::kOperationLaneC},
         Slot::kWorkLaneC,
         true},

        {{Slot::kWorkLaneC,
          Slot::kWorkLaneB,
          Slot::kWorkLaneA,
          Slot::kOperationLaneD},
         Slot::kWorkLaneD,
         false},
    };
    return aConfig;
}

GSeedRunStageConfig MakeSeed_DConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_D",
                                             TwistDomain::kPhaseD,
                                             pUseNonces,
                                             GAXSFormat::kN7,
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

GSeedRunSeed_A::GSeedRunSeed_A(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_AConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_A::~GSeedRunSeed_A() {
}

void GSeedRunSeed_A::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_A::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_B::GSeedRunSeed_B(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_BConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_B::~GSeedRunSeed_B() {
}

void GSeedRunSeed_B::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_B::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_C::GSeedRunSeed_C(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_CConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_C::~GSeedRunSeed_C() {
}

void GSeedRunSeed_C::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_C::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_D::GSeedRunSeed_D(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_DConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_D::~GSeedRunSeed_D() {
}

void GSeedRunSeed_D::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_D::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_D::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}
