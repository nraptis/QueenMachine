//
//  GRunMatrixDiffusion.cpp
//  MeanMachine
//
//  Created by Dragon on 5/15/26.
//

#include "GRunMatrixDiffusion.hpp"
#include "GIndexShuffle.hpp"
#include "GM88.hpp"
#include "GQuick.hpp"

#include <initializer_list>
#include <sstream>
#include <vector>

namespace {

void SetError(std::string *pErrorMessage,
              const std::string &pMessage) {
    if (pErrorMessage != nullptr) {
        *pErrorMessage = pMessage;
    }
}

bool EnsureBufferSymbol(const GSymbol &pSymbol,
                        const char *pLabel,
                        std::string *pErrorMessage) {
    if (pSymbol.IsBuf()) {
        return true;
    }
    SetError(pErrorMessage, std::string("GRunMatrixDiffusion expected buffer symbol for ") + pLabel + ".");
    return false;
}

std::string SymbolAliasName(const GSymbol &pSymbol) {
    if (pSymbol.IsBuf()) {
        return BufAliasName(pSymbol);
    }
    if (pSymbol.IsVar()) {
        return pSymbol.mName;
    }
    return "aInvalid";
}

std::string JoinSymbolNames(std::initializer_list<GSymbol> pSymbols) {
    if (pSymbols.size() == 0U) {
        return "(none)";
    }

    std::ostringstream aStream;
    std::size_t aIndex = 0U;
    for (const GSymbol &aSymbol : pSymbols) {
        if (aIndex > 0U) {
            aStream << ", ";
        }
        aStream << SymbolAliasName(aSymbol);
        aIndex += 1U;
    }
    return aStream.str();
}

std::vector<GStatement> LaneFlowCommentStatements(const std::string &pTitle,
                                                  std::initializer_list<GSymbol> pReadSymbols,
                                                  std::initializer_list<GSymbol> pWriteSymbols) {
    std::vector<GStatement> aStatements;
    aStatements.push_back(GStatement::Comment(pTitle));
    aStatements.push_back(GStatement::Comment("read from: " + JoinSymbolNames(pReadSymbols)));
    aStatements.push_back(GStatement::Comment("write to: " + JoinSymbolNames(pWriteSymbols)));
    return aStatements;
}

void AppendLaneFlowCommentStatements(std::vector<GStatement> *pStatements,
                                     const std::string &pTitle,
                                     std::initializer_list<GSymbol> pReadSymbols,
                                     std::initializer_list<GSymbol> pWriteSymbols) {
    if (pStatements == nullptr) {
        return;
    }
    std::vector<GStatement> aComments = LaneFlowCommentStatements(pTitle, pReadSymbols, pWriteSymbols);
    pStatements->insert(pStatements->end(), aComments.begin(), aComments.end());
}

void PrependLaneFlowComments(GLoop *pLoop,
                             const std::string &pTitle,
                             std::initializer_list<GSymbol> pReadSymbols,
                             std::initializer_list<GSymbol> pWriteSymbols) {
    if (pLoop == nullptr) {
        return;
    }
    std::vector<GStatement> aComments = LaneFlowCommentStatements(pTitle, pReadSymbols, pWriteSymbols);
    pLoop->mInitializationStatements.insert(pLoop->mInitializationStatements.begin(),
                                            aComments.begin(),
                                            aComments.end());
}

}

bool GRunMatrixDiffusion::Bake(const GRunMatrixDiffusionConfig &pConfig,
                               GBatch *pBatch,
                               std::string *pErrorMessage) {
    if (pErrorMessage != nullptr) {
        pErrorMessage->clear();
    }
    if (pBatch == nullptr) {
        SetError(pErrorMessage, "GRunMatrixDiffusion requires a batch output.");
        return false;
    }
    
    if (!EnsureBufferSymbol(pConfig.mInputA, "input_a", pErrorMessage)) { return false; }
    if (!EnsureBufferSymbol(pConfig.mInputB, "input_b", pErrorMessage)) { return false; }
    if (!EnsureBufferSymbol(pConfig.mOutputA, "output_a", pErrorMessage)) { return false; }
    if (!EnsureBufferSymbol(pConfig.mOutputB, "output_b", pErrorMessage)) { return false; }
    if (!EnsureBufferSymbol(pConfig.mShuffleEntropyA, "shuffle_entropy_a", pErrorMessage)) { return false; }
    if (!EnsureBufferSymbol(pConfig.mShuffleEntropyB, "shuffle_entropy_b", pErrorMessage)) { return false; }
    
    if (!EnsureBufferSymbol(pConfig.mOperationSourceA, "operation_source_a", pErrorMessage)) { return false; }
    if (!EnsureBufferSymbol(pConfig.mOperationSourceB, "operation_source_b", pErrorMessage)) { return false; }
    
    const GSymbol aIndexListA = BufSymbol(TwistWorkSpaceSlot::kIndexList256A);
    const GSymbol aIndexListB = BufSymbol(TwistWorkSpaceSlot::kIndexList256B);
    const GSymbol aIndexListC = BufSymbol(TwistWorkSpaceSlot::kIndexList256C);
    const GSymbol aIndexListD = BufSymbol(TwistWorkSpaceSlot::kIndexList256D);
    
    const GSymbol aLoopIndex = VarSymbol("aMatrixDiffusionIndex");
    const GSymbol aWriteIndex = VarSymbol("aWriteIndex");
    const GSymbol aReadIndexA = VarSymbol("aReadIndexA");
    const GSymbol aReadIndexB = VarSymbol("aReadIndexB");
    
    
    std::vector<GStatement> aStatements;
    AppendLaneFlowCommentStatements(&aStatements,
                                    pBatch->mName + " index shuffle",
                                    { pConfig.mShuffleEntropyA, pConfig.mShuffleEntropyB },
                                    { aIndexListA, aIndexListB, aIndexListC, aIndexListD });
    if (!GIndexShuffle::BakeA(aIndexListA, pConfig.mShuffleEntropyA, &aStatements, pErrorMessage)) {
        return false;
    }
    if (!GIndexShuffle::BakeA(aIndexListB, pConfig.mShuffleEntropyB, &aStatements, pErrorMessage)) {
        return false;
    }
    if (!GIndexShuffle::BakeB(aIndexListC, pConfig.mShuffleEntropyA, &aStatements, pErrorMessage)) {
        return false;
    }
    if (!GIndexShuffle::BakeB(aIndexListD, pConfig.mShuffleEntropyB, &aStatements, pErrorMessage)) {
        return false;
    }
    aStatements.push_back(GQuick::MakeAssignVariableStatement(aWriteIndex, GExpr::Const64(0ULL)));
    pBatch->CommitStatements(&aStatements);
    
    auto BakeSingleLoop = [&](const GSymbol pIndexListLeft,
                              const GSymbol pIndexListRight,
                              const GSymbol pOutputBuffer,
                              const GSymbol pOperationSource,
                              const GSymbol pUnrollDomainWord,
                              const GSymbol pSelectDomainWord,
                              const int pInputOffsetA,
                              const int pInputOffsetB) -> bool {
        
        GLoop aLoop;
        aLoop.mLoopVariable = aLoopIndex;
        aLoop.mLoopVariableName = aLoopIndex.mName;
        aLoop.mLoopBegin = 0;
        aLoop.mLoopEndText = "256";
        aLoop.mLoopStep = 1;
        
        aLoop.AddBody(GQuick::MakeAssignVariableStatement(
            aReadIndexA,
            GExpr::Add(GExpr::Mul(GQuick::MakeReadBufferOffsetExpression(pIndexListLeft, aLoopIndex, 0U),
                                  GExpr::Const64(128ULL)),
                       GExpr::Const64(static_cast<std::uint64_t>(pInputOffsetA)))));
        aLoop.AddBody(GQuick::MakeAssignVariableStatement(
            aReadIndexB,
            GExpr::Add(GExpr::Mul(GQuick::MakeReadBufferOffsetExpression(pIndexListRight, aLoopIndex, 0U),
                                  GExpr::Const64(128ULL)),
                       GExpr::Const64(static_cast<std::uint64_t>(pInputOffsetB)))));
        
        GM88 aMatrix;
        
        std::vector<GStatement> aIfStatements;
        std::vector<GStatement> aElseStatements;
        
        if (pConfig.mUseDomainWords == false) {
            
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputA,
                                      aReadIndexA,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      &aIfStatements,
                                      pErrorMessage)) {
                return false;
            }
            aIfStatements.push_back(GQuick::AddEqual64(aWriteIndex, 64ULL));
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputB,
                                      aReadIndexB,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      &aIfStatements,
                                      pErrorMessage)) {
                return false;
            }

            
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputB,
                                      aReadIndexB,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      &aElseStatements,
                                      pErrorMessage)) {
                return false;
            }
            aElseStatements.push_back(GQuick::AddEqual64(aWriteIndex, 64ULL));
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputA,
                                      aReadIndexA,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      &aElseStatements,
                                      pErrorMessage)) {
                return false;
            }
            
        } else {
        
            const GSymbol aArgDomainWordA = GSymbol::Var(TwistVariable::kDomainWordMatrixArgA);
            const GSymbol aArgDomainWordB = GSymbol::Var(TwistVariable::kDomainWordMatrixArgB);
            const GSymbol aArgDomainWordC = GSymbol::Var(TwistVariable::kDomainWordMatrixArgC);
            const GSymbol aArgDomainWordD = GSymbol::Var(TwistVariable::kDomainWordMatrixArgD);
            
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputA,
                                      aReadIndexA,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      pUnrollDomainWord,
                                      aArgDomainWordA,
                                      aArgDomainWordB,
                                      aArgDomainWordC,
                                      aArgDomainWordD,
                                      &aIfStatements,
                                      pErrorMessage)) {
                return false;
            }
            aIfStatements.push_back(GQuick::AddEqual64(aWriteIndex, 64ULL));
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputB,
                                      aReadIndexB,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      pUnrollDomainWord,
                                      aArgDomainWordA,
                                      aArgDomainWordB,
                                      aArgDomainWordC,
                                      aArgDomainWordD,
                                      &aIfStatements,
                                      pErrorMessage)) {
                return false;
            }

            
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputB,
                                      aReadIndexB,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      pUnrollDomainWord,
                                      aArgDomainWordA,
                                      aArgDomainWordB,
                                      aArgDomainWordC,
                                      aArgDomainWordD,
                                      &aElseStatements,
                                      pErrorMessage)) {
                return false;
            }
            aElseStatements.push_back(GQuick::AddEqual64(aWriteIndex, 64ULL));
            if (!aMatrix.BakeDispatch(pOperationSource,
                                      aWriteIndex,
                                      pConfig.mInputA,
                                      aReadIndexA,
                                      pOutputBuffer,
                                      aWriteIndex,
                                      pUnrollDomainWord,
                                      aArgDomainWordA,
                                      aArgDomainWordB,
                                      aArgDomainWordC,
                                      aArgDomainWordD,
                                      &aElseStatements,
                                      pErrorMessage)) {
                return false;
            }
        }
        
        if (pConfig.mUseDomainWords == false) {
            
            aLoop.AddBody(GStatement::RawLine("if ((" + BufAliasName(pOperationSource) + "[" + aWriteIndex.mName + "] & 0x7E) > 62) {"));
        } else {
            aLoop.AddBody(GStatement::RawLine("if (((" + BufAliasName(pOperationSource) + "[" + aWriteIndex.mName + "] ^ " + pSelectDomainWord.mName + ") & 0x7E) > 62) {"));
        }
        
        
        aLoop.AddBody(&aIfStatements);
        aLoop.AddBody(GStatement::RawLine("} else {"));
        aLoop.AddBody(&aElseStatements);
        aLoop.AddBody(GStatement::RawLine("}"));
        aLoop.AddBody(GQuick::AddEqual64(aWriteIndex, 64ULL));
        PrependLaneFlowComments(&aLoop,
                                pBatch->mName + " " + SymbolAliasName(pOutputBuffer) + " matrix loop",
                                { pConfig.mInputA, pConfig.mInputB, pOperationSource, pIndexListLeft, pIndexListRight },
                                { pOutputBuffer });
        pBatch->CommitLoop(&aLoop);
        return true;
    };
    
    if (!BakeSingleLoop(aIndexListA,
                        aIndexListB,
                        pConfig.mOutputA,
                        pConfig.mOperationSourceA,
                        GSymbol::Var(TwistVariable::kDomainWordMatrixUnrollA),
                        GSymbol::Var(TwistVariable::kDomainWordMatrixSelectA),
                        0,
                        64)) {
        return false;
    }
    
    aStatements.clear();
    aStatements.push_back(GQuick::MakeAssignVariableStatement(aWriteIndex, GExpr::Const64(0ULL)));
    pBatch->CommitStatements(&aStatements);
    
    if (!BakeSingleLoop(aIndexListC,
                        aIndexListD,
                        pConfig.mOutputB,
                        pConfig.mOperationSourceB,
                        GSymbol::Var(TwistVariable::kDomainWordMatrixUnrollB),
                        GSymbol::Var(TwistVariable::kDomainWordMatrixSelectB),
                        64,
                        0)) {
        return false;
    }
    return true;
}
