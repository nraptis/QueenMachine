//
//  Builder_Twister.cpp
//  MeanMachine
//
//  Created by nicholas on 5/23/26.
//

#include "Builder_Twister.hpp"
#include "GTwistExpander.hpp"
#include "GTwistRunGrowKeyA.hpp"
#include "GTwistRunTwist.hpp"

#include "GSquash.hpp"

#include "GRunMatrixDiffusion.hpp"

bool Builder_Twister::Build(GTwistExpander *pExpander,
                            std::string *pErrorMessage) {
    
    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Seeder::Build received null expander";
        }
        return false;
    }
    
    const GSymbol aSource = GSymbol::Buf(TwistWorkSpaceSlot::kParamInputSource);
    
    pExpander->mTwister.AddLine("// [seed]");
    
    
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
    
    std::vector<GSymbol> aOperationLanes;
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneA));
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneB));
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneC));
    aOperationLanes.push_back(BufSymbol(TwistWorkSpaceSlot::kOperationLaneD));
    
    std::vector<GStatement> aStatementsSeed6;
    GTwistRunTwist_A aRunnerTwistA;
    
    if (!aRunnerTwistA.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on GTwistRunTwist_A.Plan for ") + "twist-a" + "\n" + *pErrorMessage;
        }
        return false;
    }
    
    if (!aRunnerTwistA.Build(pExpander->mTwister, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to bake GTwistRunTwist_A:\n" + *pErrorMessage;
        }
        return false;
    }
    for (const GStatement &aStatement : aStatementsSeed6) {
        if (!aStatement.IsRawLine()) {
            continue;
        }
        pExpander->mTwister.AddLine(aStatement.mRawLine);
    }
    
    std::vector<GStatement> aStatementsHate16;
    GTwistRunTwist_B aRunnerTwistB;
    
    if (!aRunnerTwistB.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on GTwistRunTwist_B.Plan for ") + "twist-b" + "\n" + *pErrorMessage;
        }
        return false;
    }
    
    if (!aRunnerTwistB.Build(pExpander->mTwister, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to bake GTwistRunTwist_B:\n" + *pErrorMessage;
        }
        return false;
    }
    for (const GStatement &aStatement : aStatementsHate16) {
        if (!aStatement.IsRawLine()) {
            continue;
        }
        pExpander->mTwister.AddLine(aStatement.mRawLine);
    }
    
    std::vector<GStatement> aStatementsSeed8;
    GTwistRunTwist_C aRunnerTwistC;
    
    if (!aRunnerTwistC.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on GTwistRunTwist_C.Plan for ") + "twist-c" + "\n" + *pErrorMessage;
        }
        return false;
    }
    
    if (!aRunnerTwistC.Build(pExpander->mTwister, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to bake GTwistRunTwist_C:\n" + *pErrorMessage;
        }
        return false;
    }
    for (const GStatement &aStatement : aStatementsSeed8) {
        if (!aStatement.IsRawLine()) {
            continue;
        }
        pExpander->mTwister.AddLine(aStatement.mRawLine);
    }
    
    
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
        
        aDiffusionA.mUseDomainWords = false;
        
        GBatch aBatchDiffusion;
        
        if (!GRunMatrixDiffusion::Bake(aDiffusionA, &aBatchDiffusion, pErrorMessage)) {
            if (pErrorMessage != nullptr) {
                *pErrorMessage = std::string("error on matrix diffusion for ") + std::string("kdf-a") + ": " + *pErrorMessage;
            }
            return false;
        }
        pExpander->mTwister.AddBatch(aBatchDiffusion);
    }
    
    std::vector<GStatement> aStatementsSeed9;
    GTwistRunTwist_D aRunnerTwistD;
    
    if (!aRunnerTwistD.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = std::string("error on GTwistRunTwist_D.Plan for ") + "twist-d" + "\n" + *pErrorMessage;
        }
        return false;
    }
    
    if (!aRunnerTwistD.Build(pExpander->mTwister, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to bake GTwistRunTwist_D:\n" + *pErrorMessage;
        }
        return false;
    }
    for (const GStatement &aStatement : aStatementsSeed9) {
        if (!aStatement.IsRawLine()) {
            continue;
        }
        pExpander->mTwister.AddLine(aStatement.mRawLine);
    }
    
    pExpander->mTwister.AddLine("//");
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
    pExpander->mTwister.AddBatch(aFinishBatch);
    
    
    
    
    pExpander->mGrowKeyA.AddLine("// [grow key a]");
    GTwistRunGrowKeyA aRunnerGrowKeyA;
    if (!aRunnerGrowKeyA.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to plan GTwistRunGrowKeyA:\n" + *pErrorMessage;
        }
        return false;
    }
    if (!aRunnerGrowKeyA.Build(pExpander->mGrowKeyA, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to bake GTwistRunGrowKeyA:\n" + *pErrorMessage;
        }
        return false;
    }
    
    pExpander->mGrowKeyB.AddLine("// [grow key b]");
    GTwistRunGrowKeyB aRunnerGrowKeyB;
    if (!aRunnerGrowKeyB.Plan(pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to plan GTwistRunGrowKeyB:\n" + *pErrorMessage;
        }
        return false;
    }
    if (!aRunnerGrowKeyB.Build(pExpander->mGrowKeyB, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build failed to bake GTwistRunGrowKeyB:\n" + *pErrorMessage;
        }
        return false;
    }
    
    return true;
    
}
