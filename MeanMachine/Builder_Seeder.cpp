//
//  Builder_Seeder.cpp
//  MeanMachine
//
//  Created by nicholas on 5/23/26.
//

#include "Builder_Seeder.hpp"
#include "GKDF.hpp"
#include "GSnow.hpp"
#include "GTwistExpander.hpp"
#include "GMemory.hpp"
#include "GFarm.hpp"

#include "Random.hpp"

#include "GSeedRunSeed.hpp"

#include "GRunMatrixDiffusion.hpp"

#include "GSquash.hpp"

namespace {

const char *PhaseConstantsMemberName(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kPhaseB: return "mPhaseBConstants";
        case TwistDomain::kPhaseC: return "mPhaseCConstants";
        case TwistDomain::kPhaseD: return "mPhaseDConstants";
        case TwistDomain::kPhaseE: return "mPhaseEConstants";
        case TwistDomain::kPhaseF: return "mPhaseFConstants";
        case TwistDomain::kPhaseG: return "mPhaseGConstants";
        case TwistDomain::kPhaseH: return "mPhaseHConstants";
        case TwistDomain::kPhaseA:
        default:
            return "mPhaseAConstants";
    }
}

const char *PhaseSubWordName(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kPhaseB: return "PhaseB";
        case TwistDomain::kPhaseC: return "PhaseC";
        case TwistDomain::kPhaseD: return "PhaseD";
        case TwistDomain::kPhaseE: return "PhaseE";
        case TwistDomain::kPhaseF: return "PhaseF";
        case TwistDomain::kPhaseG: return "PhaseG";
        case TwistDomain::kPhaseH: return "PhaseH";
        case TwistDomain::kPhaseA:
        default:
            return "PhaseA";
    }
}

const char *SnowComment(const GSnowType pType) {
    switch (pType) {
        case GSnowType::kAES: return "Making snow counter: aes 256";
        case GSnowType::kChaCha: return "Making snow counter: cha cha 20";
        case GSnowType::kSha: return "Making snow counter: sha 256";
        case GSnowType::kAria: return "Making snow counter: aria 256";
        default:
            return nullptr;
    }
}

void AddSeedDomainWordLines(TwistProgramBranch &pBranch,
                            const TwistDomain pDomain,
                            const bool pDeclare) {
    const std::string aPrefix = pDeclare ? "std::uint64_t " : "";
    const std::string aConstants = std::string("pWorkSpace->mDomainBundle.") +
                                   PhaseConstantsMemberName(pDomain);

    pBranch.AddLine(aPrefix + "aDomainWordIngress = " + aConstants + ".mIngress;");
    pBranch.AddLine(aPrefix + "aDomainWordScatter = " + aConstants + ".mScatter;");
    pBranch.AddLine(aPrefix + "aDomainWordCross = " + aConstants + ".mCross;");
}

template <class T>
bool BuildSeedStage(TwistProgramBranch &pBranch,
                    T &pRunner,
                    const char *pStageName,
                    std::string *pErrorMessage) {
    if (!pRunner.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on ") + pStageName + ".Plan for seed\n" + *pErrorMessage;
        }
        return false;
    }

    if (!pRunner.Build(pBranch, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("Builder_Seeder::Build failed to bake ") + pStageName + ":\n" + *pErrorMessage;
        }
        return false;
    }

    return true;
}

bool AddKDFBInvestCapture(TwistProgramBranch &pBranch,
                          const std::string &pRoundName,
                          const std::vector<GSymbol> &pExpansionLanes,
                          const GSymbol &pInvestLane,
                          std::string *pErrorMessage) {
    if (pExpansionLanes.size() < 4U) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Seeder::AddKDFBInvestCapture requires four expansion lanes.";
        }
        return false;
    }

    std::vector<GStatement> aStatements;
    GSquash aSquash;
    if (!aSquash.Bake(pInvestLane,
                      pExpansionLanes[0],
                      pExpansionLanes[1],
                      pExpansionLanes[2],
                      pExpansionLanes[3],
                      GSymbol::Var(TwistVariable::kIndex),
                      &aStatements,
                      pErrorMessage)) {
        return false;
    }

    pBranch.AddLine("// " + pRoundName + " invest " + BufAliasName(pInvestLane) + " (start)");
    GBatch aBatch;
    aBatch.CommitStatements(&aStatements);
    pBranch.AddBatch(aBatch);
    pBranch.AddLine("// " + pRoundName + " invest " + BufAliasName(pInvestLane) + " (end)");
    pBranch.AddLine("//");

    return true;
}

} // namespace

bool Builder_Seeder::Build(GTwistExpander *pExpander,
                           std::string *pErrorMessage) {
    
    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Seeder::Build received null expander";
        }
        return false;
    }
    
    const GSymbol aSource = GSymbol::Buf(TwistWorkSpaceSlot::kParamInputSource);
    
    pExpander->mSeed.AddLine("// [seed]");
    
    
    std::vector<GStatement> aStatements;
    
    std::vector<GSymbol> aWorkLanes;
    aWorkLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kWorkLaneA));
    aWorkLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kWorkLaneB));
    aWorkLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kWorkLaneC));
    aWorkLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kWorkLaneD));
    
    std::vector<GSymbol> aExpansionLanes;
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneA));
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneB));
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneC));
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneD));
    
    std::vector<TwistDomain> aDomains;
    aDomains.push_back(TwistDomain::kPhaseA);
    aDomains.push_back(TwistDomain::kPhaseB);
    aDomains.push_back(TwistDomain::kPhaseC);
    aDomains.push_back(TwistDomain::kPhaseD);
    aDomains.push_back(TwistDomain::kPhaseE);
    aDomains.push_back(TwistDomain::kPhaseF);
    aDomains.push_back(TwistDomain::kPhaseG);
    aDomains.push_back(TwistDomain::kPhaseH);

    std::vector<GSymbol> aInvestLanes;
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestA));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestB));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestC));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestD));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestE));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestF));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestG));
    aInvestLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kInvestH));
    Random::Shuffle(&aInvestLanes);
    
    std::vector<GSymbol> aSnowLanes;
    aSnowLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kSnowA));
    aSnowLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kSnowB));
    aSnowLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kSnowC));
    aSnowLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kSnowD));
    
    GBatch aMemoryZeroBatch;
    GMemory aMemory;
    if (!aMemory.BakeZeroKeyBoxA(GSymbol::Buf(TwistWorkSpaceSlot::kKeyBoxUnrolledA), &aStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZeroKeyBoxB(GSymbol::Buf(TwistWorkSpaceSlot::kKeyBoxUnrolledB), &aStatements, pErrorMessage)) {
        return false;
    }
    aMemoryZeroBatch.CommitStatements(&aStatements);
    aStatements.clear();
    pExpander->mSeed.AddBatch(aMemoryZeroBatch);
    
    std::vector<GSnowType> aSnowTypes;
    aSnowTypes.push_back(GSnowType::kAES);
    aSnowTypes.push_back(GSnowType::kChaCha);
    aSnowTypes.push_back(GSnowType::kSha);
    aSnowTypes.push_back(GSnowType::kAria);
    Random::Shuffle(&aSnowTypes);

    for (std::size_t aSnowIndex = 0U; aSnowIndex < aSnowLanes.size(); ++aSnowIndex) {
        GBatch aSnowBatch;
        GSnow aSnow;
        const char *aComment = SnowComment(aSnowTypes[aSnowIndex]);
        if (aComment == nullptr) {
            std::printf("bad snow type\n");
            return false;
        }
        aSnowBatch.AddComment(aComment);
        if (!aSnow.Bake(aSnowTypes[aSnowIndex], aSource, aSnowLanes[aSnowIndex], &aStatements, pErrorMessage)) {
            std::printf("snow bake failed: %s\n", (pErrorMessage != nullptr) ? pErrorMessage->c_str() : "");
            return false;
        }
        aSnowBatch.CommitStatements(&aStatements);
        aStatements.clear();
        pExpander->mSeed.AddBatch(aSnowBatch);
    }

    std::vector<GSymbol> aPhaseSnowLanes = aSnowLanes;
    Random::Shuffle(&aPhaseSnowLanes);
    for (std::size_t aReuseIndex = 0U; aPhaseSnowLanes.size() < aDomains.size(); ++aReuseIndex) {
        aPhaseSnowLanes.push_back(aPhaseSnowLanes[aReuseIndex]);
    }

    for (std::size_t aDomainIndex = 0U; aDomainIndex < aDomains.size(); ++aDomainIndex) {
        const std::string aDomainPartialName = PhaseSubWordName(aDomains[aDomainIndex]);
        
        std::vector<GStatement> aStatementsKDFA;
        GKDF_A aKDF_A;
        aKDF_A.mSnow = aPhaseSnowLanes[aDomainIndex];
        if (!aKDF_A.Bake(aDomains[aDomainIndex],
                         GKDFMaterialBundle::kInbuilt,
                         &aStatementsKDFA,
                         pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake inbuilt KDF:\n" + *pErrorMessage;
            }
            return false;
        }
        for (const GStatement &aStatement : aStatementsKDFA) {
            if (!aStatement.IsRawLine()) {
                continue;
            }
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
        std::vector<GStatement> aStatementsFarmA;
        Random::Shuffle(&aExpansionLanes);
        GFarm aFarm;
        if (!aFarm.BakeEphemeral(aExpansionLanes[0],
                                 aExpansionLanes[1],
                                 aExpansionLanes[2],
                                 aExpansionLanes[3],
                                 aDomainPartialName,
                                 &aStatementsFarmA,
                                 pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake farm after KDFA:\n" + *pErrorMessage;
            }
            return false;
        }
        
        pExpander->mSeed.AddLine("// farm");
        for (const GStatement &aStatement : aStatementsFarmA) {
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
        pExpander->mSeed.AddLine("//");
        
        std::vector<GStatement> aStatementsKDFB;
        GKDF_B aKDF_B;
        if (!aKDF_B.Bake(aDomains[aDomainIndex],
                         GKDFMaterialBundle::kEphemeral,
                         &aStatementsKDFB,
                         pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake inbuilt KDF_B:\n" + *pErrorMessage;
            }
            return false;
        }
        for (const GStatement &aStatement : aStatementsKDFB) {
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
        if (!AddKDFBInvestCapture(pExpander->mSeed,
                                  "KDF_B " + aDomainPartialName,
                                  aExpansionLanes,
                                  aInvestLanes[aDomainIndex],
                                  pErrorMessage)) {
            return false;
        }
        
        
        std::vector<GStatement> aStatementsFarmB;
        Random::Shuffle(&aWorkLanes);
        if (!aFarm.BakeWorkspace(aExpansionLanes[0],
                                 aExpansionLanes[1],
                                 aExpansionLanes[2],
                                 aExpansionLanes[3],
                                 aDomainPartialName,
                                 &aStatementsFarmB,
                                 pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = "Builder_Seeder::Build failed to bake farm after KDFA:\n" + *pErrorMessage;
            }
            return false;
        }
        
        
        
        
        for (const GStatement &aStatement : aStatementsFarmB) {
            pExpander->mSeed.AddLine(aStatement.mRawLine);
        }
    }

    std::vector<GStatement> aZeroSnowStatements;
    for (const GSymbol &aSnowLane : aSnowLanes) {
        if (!aMemory.BakeZero(aSnowLane, &aZeroSnowStatements, pErrorMessage)) {
            return false;
        }
    }
    pExpander->mSeed.AddLine("// secure zero snow");
    for (const GStatement &aStatement : aZeroSnowStatements) {
        pExpander->mSeed.AddLine(aStatement.mRawLine);
    }
    pExpander->mSeed.AddLine("//");
    
    
    return Build_PostKDF(pExpander, pErrorMessage);
    
}

bool Builder_Seeder::Build_PostKDF(GTwistExpander *pExpander,
                                   std::string *pErrorMessage) {
    
    std::vector<GSymbol> aExpansionLanes;
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneA));
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneB));
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneC));
    aExpansionLanes.push_back(GSymbol::Buf(TwistWorkSpaceSlot::kExpansionLaneD));
    
    std::vector<GSymbol> aWorkLanes;
    aWorkLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWorkLaneA));
    aWorkLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWorkLaneB));
    aWorkLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWorkLaneC));
    aWorkLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kWorkLaneD));
    
    std::vector<GSymbol> aOperationLanes;
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneA));
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneB));
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneC));
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneD));

    AddSeedDomainWordLines(pExpander->mSeed, TwistDomain::kPhaseA, true);
    GSeedRunSeed_A aRunnerSeedA(true, false);
    if (!BuildSeedStage(pExpander->mSeed, aRunnerSeedA, "GSeedRunSeed_A", pErrorMessage)) {
        return false;
    }
    
    AddSeedDomainWordLines(pExpander->mSeed, TwistDomain::kPhaseB, false);
    GSeedRunSeed_B aRunnerSeedB(true, false);
    if (!BuildSeedStage(pExpander->mSeed, aRunnerSeedB, "GSeedRunSeed_B", pErrorMessage)) {
        return false;
    }
    
    std::vector<GStatement> aZeroStatements;
    GMemory aMemory;
    if (!aMemory.BakeZero(aExpansionLanes[0], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aExpansionLanes[1], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aExpansionLanes[2], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aExpansionLanes[3], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    
    pExpander->mSeed.AddLine("// secure zero");
    for (const GStatement &aStatement : aZeroStatements) {
        pExpander->mSeed.AddLine(aStatement.mRawLine);
    }
    pExpander->mSeed.AddLine("//");
    
    
    AddSeedDomainWordLines(pExpander->mSeed, TwistDomain::kPhaseC, false);
    GSeedRunSeed_C aRunnerSeedC(true, false);
    if (!BuildSeedStage(pExpander->mSeed, aRunnerSeedC, "GSeedRunSeed_C", pErrorMessage)) {
        return false;
    }
    
    pExpander->mSeed.AddLine("std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;");
    pExpander->mSeed.AddLine("std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;");
    
    pExpander->mSeed.AddLine("std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;");
    pExpander->mSeed.AddLine("std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;");
    
    pExpander->mSeed.AddLine("std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;");
    pExpander->mSeed.AddLine("std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;");
    pExpander->mSeed.AddLine("std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;");
    pExpander->mSeed.AddLine("std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;");
    
    
    for (int i=0;i<4;i+=2) {
        
        GRunMatrixDiffusionConfig aDiffusionA;
        aDiffusionA.mInputA = aWorkLanes[i];
        aDiffusionA.mInputB = aWorkLanes[i + 1];
        aDiffusionA.mOutputA = aExpansionLanes[i];
        aDiffusionA.mOutputB =  aExpansionLanes[i + 1];
        
        aDiffusionA.mShuffleEntropyA = aOperationLanes[(i + 2) % 4];
        aDiffusionA.mShuffleEntropyB = aOperationLanes[(i + 3) % 4];
        aDiffusionA.mOperationSourceA = aOperationLanes[(i + 0) % 4];
        aDiffusionA.mOperationSourceB = aOperationLanes[(i + 1) % 4];
        
        aDiffusionA.mUseDomainWords = true;
        
        
        GBatch aBatchDiffusion;
        
        if (!GRunMatrixDiffusion::Bake(aDiffusionA, &aBatchDiffusion, pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = std::string("error on matrix diffusion for ") + std::string("kdf-a") + ": " + *pErrorMessage;
            }
            return false;
        }
        pExpander->mSeed.AddBatch(aBatchDiffusion);
    }
    
    aZeroStatements.clear();
    if (!aMemory.BakeZero(aOperationLanes[0], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aOperationLanes[1], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aOperationLanes[2], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aOperationLanes[3], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aWorkLanes[0], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aWorkLanes[1], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aWorkLanes[2], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aWorkLanes[3], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    
    pExpander->mSeed.AddLine("// secure zero");
    for (const GStatement &aStatement : aZeroStatements) {
        pExpander->mSeed.AddLine(aStatement.mRawLine);
    }
    pExpander->mSeed.AddLine("//");
    
    
    
    
    AddSeedDomainWordLines(pExpander->mSeed, TwistDomain::kPhaseD, false);
    GSeedRunSeed_D aRunnerSeedD(true, false);
    if (!BuildSeedStage(pExpander->mSeed, aRunnerSeedD, "GSeedRunSeed_D", pErrorMessage)) {
        return false;
    }
    
    pExpander->mSeed.AddLine("//");
    
    
    
    aZeroStatements.clear();
    if (!aMemory.BakeZero(aExpansionLanes[0], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aExpansionLanes[1], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aExpansionLanes[2], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    if (!aMemory.BakeZero(aExpansionLanes[3], &aZeroStatements, pErrorMessage)) {
        return false;
    }
    pExpander->mSeed.AddLine("// secure zero");
    for (const GStatement &aStatement : aZeroStatements) {
        pExpander->mSeed.AddLine(aStatement.mRawLine);
    }
    pExpander->mSeed.AddLine("//");
    
    
    std::vector<GStatement> aStatementsSquash;
    GSymbol aIndex = GSymbol::Var(TwistVariable::kIndex);
    GSquash aSquash;
    if (!aSquash.Bake(GSymbol::Var(TwistVariable::kParamOutput),
                      aWorkLanes[0],
                      aWorkLanes[1],
                      aWorkLanes[2],
                      aWorkLanes[3],
                      
                      aIndex,
                      
                      &aStatementsSquash,
                      pErrorMessage)) {
        return false;
    }
    GBatch aFinishBatch;
    aFinishBatch.CommitStatements(&aStatementsSquash);
    pExpander->mSeed.AddBatch(aFinishBatch);
    
    
    
    
    return true;
}
