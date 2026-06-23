#include "TwistExpander_Unholy_060.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistMemory.hpp"
#include "TwistShiftBox.hpp"
#include "TwistSnow.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Unholy_060::TwistExpander_Unholy_060()
: TwistExpander() {
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleInbuilt.mPhaseESalts = kPhaseESalts;
    mDomainBundleInbuilt.mPhaseEConstants = kPhaseEConstants;
    mDomainBundleInbuilt.mPhaseFSalts = kPhaseFSalts;
    mDomainBundleInbuilt.mPhaseFConstants = kPhaseFConstants;
    mDomainBundleInbuilt.mPhaseGSalts = kPhaseGSalts;
    mDomainBundleInbuilt.mPhaseGConstants = kPhaseGConstants;
    mDomainBundleInbuilt.mPhaseHSalts = kPhaseHSalts;
    mDomainBundleInbuilt.mPhaseHConstants = kPhaseHConstants;
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
}

void TwistExpander_Unholy_060::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    std::uint64_t aWriteIndex = 0; std::uint64_t aReadIndexA = 0; std::uint64_t aReadIndexB = 0;

    // [kdf-a]
    [[maybe_unused]] std::uint64_t aNonceByteA = ((pNonce >> 0U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteB = ((pNonce >> 8U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteC = ((pNonce >> 16U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteD = ((pNonce >> 24U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteE = ((pNonce >> 32U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteF = ((pNonce >> 40U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteG = ((pNonce >> 48U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteH = ((pNonce >> 56U) & 0xFFULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 15079010930071565682U;
        aCarry = 15779565980404415919U;
        aWandererA = 9651046840280355311U;
        aWandererB = 12869377028145744859U;
        aWandererC = 15500520124598643078U;
        aWandererD = 16848218382464389964U;
        aWandererE = 12516549915037792466U;
        aWandererF = 14397193248758254761U;
        aWandererG = 9691457940354050576U;
        aWandererH = 15429587255581506632U;
        aWandererI = 14979931810737603012U;
        aWandererJ = 13970139081689011647U;
        aWandererK = 16799982400218962089U;
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (start)
    {
        // GSeedRunKDF_A_A kdf_a_loop_a lane group
        // read from: mSource, mSnow, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, mSnow
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteF, 5U) ^ RotL64(aNonceByteD, 58U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7429U)) & S_BLOCK1], 39U) ^ RotL64(mSnow[((aIndex + 4938U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: aExpandLaneA, mSource, mSnow
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteG, 10U) ^ RotL64(aNonceByteB, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15671U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 8601U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, mSource, mSnow
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 27U) ^ RotL64(aNonceByteH, 57U)) ^ RotL64(aNonceByteC, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22996U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 20772U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteF, 29U) ^ RotL64(aNonceByteB, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27743U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25469U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (end)
    // GSeedRunKDF_A_B kdf_a_loop_b (start)
    {
        // GSeedRunKDF_A_B kdf_a_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteF, 29U) ^ RotL64(aNonceByteG, 21U)) ^ RotL64(aNonceByteH, 50U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4246U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2245U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteG, 21U) ^ RotL64(aNonceByteH, 46U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13871U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 13772U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteG, 52U) ^ RotL64(aNonceByteC, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23291U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22042U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteE, 19U) ^ RotL64(aNonceByteA, 46U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31825U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 26260U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_B kdf_a_loop_b (end)
    // GSeedRunKDF_A_C kdf_a_loop_c (start)
    {
        // GSeedRunKDF_A_C kdf_a_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteA, 53U) ^ RotL64(aNonceByteG, 44U)) ^ RotL64(aNonceByteH, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6807U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 480U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 53U) ^ RotL64(aNonceByteC, 26U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9587U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10476U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 41U) ^ RotL64(aNonceByteD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21159U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 21266U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 60U) ^ RotL64(aNonceByteD, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31363U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 30183U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)
    {
        // kdf-a-matrix-diffusion: yeah
    
        // twist_seed_batch index shuffle
        // read from: aOperationLaneA, aOperationLaneB
        // write to: aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D
        TwistIndexShuffle::ExecuteA(aIndexList256A, aOperationLaneA);
        TwistIndexShuffle::ExecuteA(aIndexList256B, aOperationLaneB);
        TwistIndexShuffle::ExecuteB(aIndexList256C, aOperationLaneA);
        TwistIndexShuffle::ExecuteB(aIndexList256D, aOperationLaneB);
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneA matrix loop
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aIndexList256A, aIndexList256B
        // write to: aExpandLaneA
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = aIndexList256A[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            aReadIndexB = (aIndexList256B[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            if (((aOperationLaneC[aWriteIndex] ^ aDomainWordMatrixSelectA) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneB matrix loop
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aIndexList256C, aIndexList256D
        // write to: aExpandLaneB
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = (aIndexList256C[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            aReadIndexB = aIndexList256D[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            if (((aOperationLaneD[aWriteIndex] ^ aDomainWordMatrixSelectB) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    }
    {
        // kdf-a-matrix-diffusion: yeah
    
        // twist_seed_batch index shuffle
        // read from: aOperationLaneC, aOperationLaneD
        // write to: aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D
        TwistIndexShuffle::ExecuteA(aIndexList256A, aOperationLaneC);
        TwistIndexShuffle::ExecuteA(aIndexList256B, aOperationLaneD);
        TwistIndexShuffle::ExecuteB(aIndexList256C, aOperationLaneC);
        TwistIndexShuffle::ExecuteB(aIndexList256D, aOperationLaneD);
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneC matrix loop
        // read from: aWorkLaneC, aWorkLaneD, aOperationLaneA, aIndexList256A, aIndexList256B
        // write to: aExpandLaneC
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = aIndexList256A[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            aReadIndexB = (aIndexList256B[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            if (((aOperationLaneA[aWriteIndex] ^ aDomainWordMatrixSelectA) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneD matrix loop
        // read from: aWorkLaneC, aWorkLaneD, aOperationLaneB, aIndexList256C, aIndexList256D
        // write to: aExpandLaneD
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = (aIndexList256C[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            aReadIndexB = aIndexList256D[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            if (((aOperationLaneB[aWriteIndex] ^ aDomainWordMatrixSelectB) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        // GSeedRunKDF_A_D kdf_a_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 53U) ^ RotL64(aNonceByteE, 13U)) ^ RotL64(aNonceByteF, 22U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3261U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1260U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 53U) ^ RotL64(aNonceByteF, 24U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10953U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 8765U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 27U) ^ RotL64(aNonceByteF, 19U)) ^ RotL64(aNonceByteD, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22783U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20711U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteD, 27U) ^ RotL64(aNonceByteC, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30634U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 28889U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)
}

void TwistExpander_Unholy_060::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [kdf-b]
    [[maybe_unused]] std::uint64_t aNonceByteA = ((pNonce >> 0U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteB = ((pNonce >> 8U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteC = ((pNonce >> 16U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteD = ((pNonce >> 24U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteE = ((pNonce >> 32U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteF = ((pNonce >> 40U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteG = ((pNonce >> 48U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteH = ((pNonce >> 56U) & 0xFFULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    {
        aPrevious = 12733142234183791650U;
        aCarry = 11630760553222663949U;
        aWandererA = 14741728298721920556U;
        aWandererB = 16661588862374609568U;
        aWandererC = 11855515789691601112U;
        aWandererD = 13638914875326425575U;
        aWandererE = 14509784964747588861U;
        aWandererF = 14668267454665539633U;
        aWandererG = 17037903818595200909U;
        aWandererH = 16528659459313713943U;
        aWandererI = 16789293822589094194U;
        aWandererJ = 12338906239900717611U;
        aWandererK = 16771420296137671575U;
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        // GSeedRunKDF_B_A kdf_b_loop_a lane group
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 5U) ^ RotL64(aNonceByteA, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1714U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 5378U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // read from: aExpandLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 5U) ^ RotL64(aNonceByteF, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13942U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((aIndex + 16279U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteE, 12U) ^ RotL64(aNonceByteG, 57U)) ^ RotL64(aNonceByteF, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22652U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20280U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneD
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 13U) ^ RotL64(aNonceByteF, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32587U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 30834U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)
    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        // GSeedRunKDF_B_B kdf_b_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 52U) ^ RotL64(aNonceByteD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5354U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 6289U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteC, 53U) ^ RotL64(aNonceByteE, 13U)) ^ RotL64(aNonceByteD, 24U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12641U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13162U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 58U) ^ RotL64(aNonceByteH, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19309U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23746U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 10U) ^ RotL64(aNonceByteF, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25351U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28747U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)
    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        // GSeedRunKDF_B_C kdf_b_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteD, 56U) ^ RotL64(aNonceByteH, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6761U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3434U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // read from: aExpandLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteG, 36U) ^ RotL64(aNonceByteF, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11868U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 8682U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // read from: aExpandLaneB, aExpandLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 57U) ^ RotL64(aNonceByteG, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16603U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 20652U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneD
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 57U) ^ RotL64(aNonceByteA, 11U)) ^ RotL64(aNonceByteD, 22U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25264U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28945U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)
}

void TwistExpander_Unholy_060::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pSourceInput,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pSourceInput, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr) || (pSourceInput == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneE = pWorkSpace->mInvestLaneE;
    [[maybe_unused]] std::uint8_t *aInvestLaneF = pWorkSpace->mInvestLaneF;
    [[maybe_unused]] std::uint8_t *aInvestLaneG = pWorkSpace->mInvestLaneG;
    [[maybe_unused]] std::uint8_t *aInvestLaneH = pWorkSpace->mInvestLaneH;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    [[maybe_unused]] std::uint8_t *aKeyBoxUnrolledA = &(pWorkSpace->mKeyBoxA[0][0]);
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    std::uint64_t aIngress = 0;

    std::uint64_t aWriteIndex = 0; std::uint64_t aReadIndexA = 0; std::uint64_t aReadIndexB = 0;

    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    // [seed]
    {
        TwistMemory::ZeroKeyBoxA(aKeyBoxUnrolledA);
        TwistMemory::ZeroKeyBoxB(aKeyBoxUnrolledB);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    }
    // KDF_B PhaseA invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneA (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    }
    // KDF_B PhaseB invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseC invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneE (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseD invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseE invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    }
    // KDF_B PhaseF invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    }
    // KDF_B PhaseG invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseH invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    // secure zero snow
    TwistMemory::ZeroBlock(aSnowLaneA);
    TwistMemory::ZeroBlock(aSnowLaneB);
    TwistMemory::ZeroBlock(aSnowLaneC);
    TwistMemory::ZeroBlock(aSnowLaneD);
    //
    std::uint64_t aDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    std::uint64_t aDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    std::uint64_t aDomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    [[maybe_unused]] std::uint64_t aNonceByteA = ((pNonce >> 0U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteB = ((pNonce >> 8U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteC = ((pNonce >> 16U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteD = ((pNonce >> 24U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteE = ((pNonce >> 32U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteF = ((pNonce >> 40U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteG = ((pNonce >> 48U) & 0xFFULL);
    [[maybe_unused]] std::uint64_t aNonceByteH = ((pNonce >> 56U) & 0xFFULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // read from: mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteB, 3U) ^ RotL64(aNonceByteE, 35U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2845U)) & S_BLOCK1], 57U) ^ RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 1930U)) & (S_KEY_A - 1)], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 3U) ^ RotL64(aNonceByteC, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15913U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15449U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteF, 54U) ^ RotL64(aNonceByteD, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22806U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22608U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteB, 3U) ^ RotL64(aNonceByteA, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25573U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 31970U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)
    aDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    aDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    aDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    // GSeedRunSeed_B seed_loop_b (start)
    {
        // GSeedRunSeed_B seed_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 200U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 1674U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9996U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16030U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18575U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 17914U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29481U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25500U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_b (end)
    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    aDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    aDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    aDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    // GSeedRunSeed_C seed_loop_c (start)
    {
        // GSeedRunSeed_C seed_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2500U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7730U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aWorkLaneA[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8467U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 9875U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18895U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21962U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aWorkLaneC[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29382U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26800U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aWorkLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_c (end)
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    {
        // seedur-matrix-diffusion: yeah
    
        // twist_seed_batch index shuffle
        // read from: aOperationLaneC, aOperationLaneD
        // write to: aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D
        TwistIndexShuffle::ExecuteA(aIndexList256A, aOperationLaneC);
        TwistIndexShuffle::ExecuteA(aIndexList256B, aOperationLaneD);
        TwistIndexShuffle::ExecuteB(aIndexList256C, aOperationLaneC);
        TwistIndexShuffle::ExecuteB(aIndexList256D, aOperationLaneD);
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneA matrix loop
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aIndexList256A, aIndexList256B
        // write to: aExpandLaneA
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = aIndexList256A[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            aReadIndexB = (aIndexList256B[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            if (((aOperationLaneA[aWriteIndex] ^ aDomainWordMatrixSelectA) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneA, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneB matrix loop
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aIndexList256C, aIndexList256D
        // write to: aExpandLaneB
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = (aIndexList256C[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            aReadIndexB = aIndexList256D[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            if (((aOperationLaneB[aWriteIndex] ^ aDomainWordMatrixSelectB) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneB, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    }
    {
        // seedur-matrix-diffusion: yeah
    
        // twist_seed_batch index shuffle
        // read from: aOperationLaneA, aOperationLaneB
        // write to: aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D
        TwistIndexShuffle::ExecuteA(aIndexList256A, aOperationLaneA);
        TwistIndexShuffle::ExecuteA(aIndexList256B, aOperationLaneB);
        TwistIndexShuffle::ExecuteB(aIndexList256C, aOperationLaneA);
        TwistIndexShuffle::ExecuteB(aIndexList256D, aOperationLaneB);
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneC matrix loop
        // read from: aWorkLaneC, aWorkLaneD, aOperationLaneC, aIndexList256A, aIndexList256B
        // write to: aExpandLaneC
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = aIndexList256A[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            aReadIndexB = (aIndexList256B[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            if (((aOperationLaneC[aWriteIndex] ^ aDomainWordMatrixSelectA) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneC, aWriteIndex,
    							aDomainWordMatrixUnrollA,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneD matrix loop
        // read from: aWorkLaneC, aWorkLaneD, aOperationLaneD, aIndexList256C, aIndexList256D
        // write to: aExpandLaneD
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = (aIndexList256C[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            aReadIndexB = aIndexList256D[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            if (((aOperationLaneD[aWriteIndex] ^ aDomainWordMatrixSelectB) & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            } else {
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneD, aWriteIndex,
    							aDomainWordMatrixUnrollB,
    							aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    }
    // secure zero
    TwistMemory::ZeroBlock(aOperationLaneA);
    TwistMemory::ZeroBlock(aOperationLaneB);
    TwistMemory::ZeroBlock(aOperationLaneC);
    TwistMemory::ZeroBlock(aOperationLaneD);
    TwistMemory::ZeroBlock(aWorkLaneA);
    TwistMemory::ZeroBlock(aWorkLaneB);
    TwistMemory::ZeroBlock(aWorkLaneC);
    TwistMemory::ZeroBlock(aWorkLaneD);
    //
    aDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    aDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    aDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 104U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7447U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10763U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 9685U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19965U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 20618U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25492U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30481U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_d (end)
    //
    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    {
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
}

void TwistExpander_Unholy_060::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSourceInput,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSourceInput, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    [[maybe_unused]] std::uint8_t *aKeyBoxUnrolledA = &(pWorkSpace->mKeyBoxA[0][0]);
    std::uint64_t aIngress = 0;

    std::uint64_t aWriteIndex = 0; std::uint64_t aReadIndexA = 0; std::uint64_t aReadIndexB = 0;

    // [seed]
    // GTwistRunTwist_A twist_loop_a (start)
    {
        // GTwistRunTwist_A twist_loop_a lane group
        // read from: mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // read from: mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4160U)) & S_BLOCK1], 18U) ^ RotL64(aKeyBoxUnrolledA[((aIndex + 3085U)) & (S_KEY_A - 1)], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13468U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13849U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23372U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23907U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28368U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 28184U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)
    // GTwistRunTwist_B twist_loop_b (start)
    {
        // GTwistRunTwist_B twist_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5500U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6489U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9798U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 10793U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24534U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 17210U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28295U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26098U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)
    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    // GTwistRunTwist_C twist_loop_c (start)
    {
        // GTwistRunTwist_C twist_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6879U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1530U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aWorkLaneA[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13087U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9755U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17124U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19922U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aWorkLaneC[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25634U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 24716U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aWorkLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)
    {
        // seedur-matrix-diffusion: yeah
    
        // twist_seed_batch index shuffle
        // read from: aOperationLaneC, aOperationLaneD
        // write to: aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D
        TwistIndexShuffle::ExecuteA(aIndexList256A, aOperationLaneC);
        TwistIndexShuffle::ExecuteA(aIndexList256B, aOperationLaneD);
        TwistIndexShuffle::ExecuteB(aIndexList256C, aOperationLaneC);
        TwistIndexShuffle::ExecuteB(aIndexList256D, aOperationLaneD);
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneA matrix loop
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aIndexList256A, aIndexList256B
        // write to: aExpandLaneA
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = aIndexList256A[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            aReadIndexB = (aIndexList256B[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            if ((aOperationLaneA[aWriteIndex] & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneA, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneA, aWriteIndex);
            } else {
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneA, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneA, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneA, aWriteIndex);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneB matrix loop
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aIndexList256C, aIndexList256D
        // write to: aExpandLaneB
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = (aIndexList256C[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            aReadIndexB = aIndexList256D[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            if ((aOperationLaneB[aWriteIndex] & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneB, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneB, aWriteIndex);
            } else {
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneB, aReadIndexB,
    							aExpandLaneB, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneB, aWriteIndex,
    							aWorkLaneA, aReadIndexA,
    							aExpandLaneB, aWriteIndex);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    }
    {
        // seedur-matrix-diffusion: yeah
    
        // twist_seed_batch index shuffle
        // read from: aOperationLaneA, aOperationLaneB
        // write to: aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D
        TwistIndexShuffle::ExecuteA(aIndexList256A, aOperationLaneA);
        TwistIndexShuffle::ExecuteA(aIndexList256B, aOperationLaneB);
        TwistIndexShuffle::ExecuteB(aIndexList256C, aOperationLaneA);
        TwistIndexShuffle::ExecuteB(aIndexList256D, aOperationLaneB);
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneC matrix loop
        // read from: aWorkLaneC, aWorkLaneD, aOperationLaneC, aIndexList256A, aIndexList256B
        // write to: aExpandLaneC
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = aIndexList256A[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            aReadIndexB = (aIndexList256B[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            if ((aOperationLaneC[aWriteIndex] & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneC, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneC, aWriteIndex);
            } else {
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneC, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneC, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneC, aWriteIndex);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    
        aWriteIndex = 0U;
    
        // twist_seed_batch aExpandLaneD matrix loop
        // read from: aWorkLaneC, aWorkLaneD, aOperationLaneD, aIndexList256C, aIndexList256D
        // write to: aExpandLaneD
        for (std::size_t aMatrixDiffusionIndex = 0U; aMatrixDiffusionIndex < static_cast<std::size_t>(256); aMatrixDiffusionIndex += 1U) {
            aReadIndexA = (aIndexList256C[(aMatrixDiffusionIndex) & S_SBOX1] * 128U) + 64U;
            aReadIndexB = aIndexList256D[(aMatrixDiffusionIndex) & S_SBOX1] * 128U;
            if ((aOperationLaneD[aWriteIndex] & 0x7E) > 62) {
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneD, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneD, aWriteIndex);
            } else {
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneD, aReadIndexB,
    							aExpandLaneD, aWriteIndex);
            aWriteIndex = aWriteIndex + 64U;
            	mMatrix.Dispatch(aOperationLaneD, aWriteIndex,
    							aWorkLaneC, aReadIndexA,
    							aExpandLaneD, aWriteIndex);
            }
            aWriteIndex = aWriteIndex + 64U;
        }
    }
    // secure zero
    TwistMemory::ZeroBlock(aOperationLaneA);
    TwistMemory::ZeroBlock(aOperationLaneB);
    TwistMemory::ZeroBlock(aOperationLaneC);
    TwistMemory::ZeroBlock(aOperationLaneD);
    TwistMemory::ZeroBlock(aWorkLaneA);
    TwistMemory::ZeroBlock(aWorkLaneB);
    TwistMemory::ZeroBlock(aWorkLaneC);
    TwistMemory::ZeroBlock(aWorkLaneD);
    //
    // GTwistRunTwist_D twist_loop_d (start)
    {
        // GTwistRunTwist_D twist_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4366U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3104U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16311U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15115U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17137U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 20191U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28326U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 31084U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)
    //
    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    {
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
    std::memcpy(pDestination, pWorkSpace->mWorkLaneD, S_BLOCK);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY_A)) {
        GrowKeyA(pWorkSpace);
    } else {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    }
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY_B)) {
        GrowKeyB(pWorkSpace);
    } else {
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    }
}

void TwistExpander_Unholy_060::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyA(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);
    std::uint64_t aIngress = 0;

    // [grow key a]
    // GTwistRunGrowKeyA grow_key_a_expand_a (start)
    {
        // grow_key_a_expand_a loop 1
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneD, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 42U) ^ RotL64(aWorkLaneB[aIndex], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_a (end)
    // GTwistRunGrowKeyA grow_key_a_expand_b (start)
    {
        // grow_key_a_expand_b loop 1
        // read from: aWorkLaneC, aWorkLaneD, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 44U) ^ RotL64(aWorkLaneD[aIndex], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_b (end)
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    TwistMemory::Zero(aKeyRowWriteA, 2048U);
    // GTwistRunGrowKeyA twist_key_box_loop_a (start)
    {
        // twist_key_box_loop_a loop 1
        // read from: aExpandLaneA, aExpandLaneB
        // write to: aKeyRowWriteA (^=)
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[aIndex], 29U) ^ RotL64(aExpandLaneB[aIndex], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aKeyRowWriteA[(aIndex) & W_KEY_A1] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyA twist_key_box_loop_a (end)
}

void TwistExpander_Unholy_060::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);
    std::uint64_t aIngress = 0;

    // [grow key b]
    // GTwistRunGrowKeyB grow_key_b_expand_a (start)
    {
        // grow_key_b_expand_a loop 1
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[aIndex], 10U) ^ RotL64(aWorkLaneB[S_BLOCK1 - aIndex], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyB grow_key_b_expand_a (end)
    // GTwistRunGrowKeyB grow_key_b_expand_b (start)
    {
        // grow_key_b_expand_b loop 1
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneD, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 37U) ^ RotL64(aWorkLaneB[aIndex], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyB grow_key_b_expand_b (end)
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    TwistMemory::Zero(aKeyRowWriteB, 2048U);
    // GTwistRunGrowKeyB twist_key_box_loop_b (start)
    {
        // twist_key_box_loop_b loop 1
        // read from: aExpandLaneA, aExpandLaneB
        // write to: aKeyRowWriteB (^=)
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[aIndex], 57U) ^ RotL64(aExpandLaneB[aIndex], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aKeyRowWriteB[(aIndex) & (W_KEY_B - 1)] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyB twist_key_box_loop_b (end)
}

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseASalts = {
    {
        {
            0xEDFC12785163309CULL, 0x8CD70DE3F3789990ULL, 0x1E56AD7E2FFAF318ULL, 0xCC4386A774585E92ULL, 
            0x173E645B033E4C52ULL, 0x7DEAE36366A28DF3ULL, 0x5FB4941E9FADE6B6ULL, 0x8E41C41A76107DEFULL, 
            0x9E325A37A7976193ULL, 0xC770D4C3F273E7C4ULL, 0xA1E9A8C8B120F571ULL, 0x5EB927A5EFFD904AULL, 
            0x7198F401011F3431ULL, 0xFFA5CDB6A535E126ULL, 0xBD240BF144F17E16ULL, 0x942FE50DA7487377ULL, 
            0x89B43F72DC25A8D5ULL, 0x38B1D19E30E865B9ULL, 0xD425753A509D9CC2ULL, 0x0BE6B36E97DF8D4BULL, 
            0x835AF04F47AA15AAULL, 0x3FC8B202F27A3908ULL, 0xFEC88BB7C12B03EFULL, 0xC80798C8513E3821ULL, 
            0xA44E26A7E932F230ULL, 0xB137E52AB3E1B959ULL, 0x031DC5DD77A29EE7ULL, 0x751034ADE8134321ULL, 
            0x889E0F3C230FEEE3ULL, 0x5E0464797E3042DFULL, 0xE1F4D3C23AD25157ULL, 0x38392526946F11FBULL
        },
        {
            0xA490ED2595CD6D88ULL, 0x67E38FC1D297DE58ULL, 0x84E914B965FB34B4ULL, 0xEE2777D44E665850ULL, 
            0x93087185C479670CULL, 0xB2128369983472C5ULL, 0xCF51DF71E79F9ED6ULL, 0xE358966B1193BBA4ULL, 
            0xDE68EA6CAE8C7CEFULL, 0x442F3E87ED4FF028ULL, 0x8FA22151F78D6AB8ULL, 0x9365B26C18F7E138ULL, 
            0x0FD108802F6273C8ULL, 0x4BEEA342C320D38DULL, 0x357F573ED249A0C1ULL, 0x872FD0A531591533ULL, 
            0xE077A02B563B6B7CULL, 0xED852C8F4C6CBF56ULL, 0x963F5CA8E42EA742ULL, 0x72EF4BC908B8F8D4ULL, 
            0x308A5C8E6A2E08D1ULL, 0xE7F44DCBD24B7C34ULL, 0x530A09C69FD175ACULL, 0xD25BE16E868667C0ULL, 
            0x09F29C69F8A1F6FAULL, 0xD268A47C013DF805ULL, 0x6298B94C55EE7292ULL, 0x4A5BBA13019A436CULL, 
            0xC3261679EC4170FAULL, 0x604523B12E41D467ULL, 0x786A7C2F70A0CE11ULL, 0x5204040545DEABBBULL
        },
        {
            0x840F0A0E713ECD2CULL, 0x7B0AB0D333ACA924ULL, 0xA7D20ACB59984F47ULL, 0x284314D10D64A1C4ULL, 
            0x2EF49455FC549437ULL, 0x39B55A32118803F3ULL, 0x88D86D6D91E8D3B6ULL, 0x84F7C4C632638A63ULL, 
            0xC933667BB640C0EAULL, 0x753120658AB2CC28ULL, 0x7A068C6722201691ULL, 0x2A4112BCE8854791ULL, 
            0x00B534E462043165ULL, 0xC0A6504ECF34C0BEULL, 0x481DE7F4602C8966ULL, 0x2CF0020BE7862743ULL, 
            0x1F2DFA790A354ED9ULL, 0xAB90C35C57920D3CULL, 0x1B08FE3AFFD04F92ULL, 0x0B8C78690240343CULL, 
            0xA3FFA2E1D9A4D92FULL, 0x5F017C35C0B57132ULL, 0x77FD327BBC7C589AULL, 0xF064D378180A2C38ULL, 
            0x0B2B3232CC8394D3ULL, 0xCAC1C22E05E39E85ULL, 0x797189E4F683CB35ULL, 0x69A6556EAEE3921BULL, 
            0xAD467659E18F6F4BULL, 0xFC224C64D71D4CE4ULL, 0x2F11AE934F22A987ULL, 0x30BF0E8D4EF4879CULL
        },
        {
            0x279FCF20D65C568DULL, 0x0D3F1B80F19EFC49ULL, 0xC44F98B346C6C09AULL, 0xF049C219A30DB1C5ULL, 
            0x51AEB49EC5C086E3ULL, 0x798FD1E1F6EA5317ULL, 0xCEE73A4118567593ULL, 0x4A7E3615F7151CB7ULL, 
            0xA4ED2D9E58CA22B9ULL, 0xF95A70B896F26A64ULL, 0x625026B856CF65F4ULL, 0x345B6D7F16F3F414ULL, 
            0xCA7D50F455B85F8CULL, 0x2FD899E534CDC01DULL, 0x0985DF7A57150AA1ULL, 0x3D4A57B643622A30ULL, 
            0x0E95CEB10AA47CF4ULL, 0x4F7F65AB6819B08CULL, 0xA523E78A498526B3ULL, 0x7B1B03660302B457ULL, 
            0xD720E59819552E07ULL, 0x88343AF0046D0907ULL, 0xB9C35CE07070286EULL, 0x065D3F3DF765F66FULL, 
            0x943EC756DFAEF9EDULL, 0x1362EFCF356FA268ULL, 0x465C0F9AD6FDBDC7ULL, 0x9B1DE1E10CD6A6AEULL, 
            0xE0024449F011C0E3ULL, 0x1B039B3AF8524471ULL, 0x0EDF7848069AE2FCULL, 0x5A9DDA368D465D42ULL
        },
        {
            0xEC5A68C7BBAD6D3BULL, 0xEF5544F58C4DC453ULL, 0x1452C2CED7BD887BULL, 0x59CDE45278AFE114ULL, 
            0x7B6E61AC05DDAF30ULL, 0xC32AFCC78996B36BULL, 0x0D124E582A40C7CAULL, 0xC3C87A82464503BDULL, 
            0x5AAE85AA2A60C0D5ULL, 0xF8E14F96183A2A2EULL, 0x343D057A06D6FE1AULL, 0xA2F03B0B18B3387FULL, 
            0x81B99DD6C6EEFC12ULL, 0x879313DFAF7CAB91ULL, 0xABD9725A4083F549ULL, 0xA23833BADD30B5BCULL, 
            0xE5F609F7CF18495CULL, 0x4665331680F8A439ULL, 0x3B8DF377DA7F0120ULL, 0xE7885A155AE74B31ULL, 
            0x457F0A048193AF69ULL, 0x4E1888AFE558E007ULL, 0xD65F4AADE42D56C1ULL, 0x9ED8919EC7495D66ULL, 
            0xC1EC7572906BF027ULL, 0xD357CC2AD2AC033FULL, 0xE936789498A75EAEULL, 0x0EAEFDD289B69478ULL, 
            0x46503636CC0DDB6EULL, 0x94F6A023E0774409ULL, 0x4FD54F53890C2ED5ULL, 0xDFFB94BE70533338ULL
        },
        {
            0x83F8A640DB36C7C7ULL, 0x49DE725D4FFCCD55ULL, 0x78EB702A1B3C594BULL, 0xE23A5BF3E01C56D8ULL, 
            0x8322C97C08CA2C17ULL, 0xA0C02495E7DA0A15ULL, 0xA17A52B1EC037809ULL, 0x6D8AAC38B4556168ULL, 
            0xA83F5D39E53824E7ULL, 0xC1C85F14E2320D7AULL, 0x1A8193466DB63E7AULL, 0xE3A4708B0CE3EC3CULL, 
            0xEA4E6B705C56B30EULL, 0xD3579DED0D7F1E91ULL, 0x9D6388D69D01276AULL, 0xB53E86B0413E8E55ULL, 
            0x05ED035682221D16ULL, 0x58BBBCCD9D9A730BULL, 0x8BF59FCFD0321F27ULL, 0x983A6B676EB62FDBULL, 
            0x0BBBC48B17A61E92ULL, 0x44E889DBDA925824ULL, 0xD7CD01F0FA66F8B9ULL, 0x59CD62939021A8DBULL, 
            0xA8DDF3ECA241F7FAULL, 0xD10D9BC01DD8EED3ULL, 0x3C29F4744E1941F4ULL, 0x545AA7625C4127ACULL, 
            0x5F288A2E75359880ULL, 0xBA797B3A8D9561B9ULL, 0x10C99DE58885E970ULL, 0x125F0DD00B8E47B4ULL
        }
    },
    {
        {
            0xFBD6A4FD441F3ED3ULL, 0x24C360B7BBF35450ULL, 0x41549E69C1731CC4ULL, 0xC0118CE4BD5CF275ULL, 
            0x72EEA367BBA4319FULL, 0xB71C7C604CF7ADE6ULL, 0x84D52CB4DAF97AE6ULL, 0x9A84E8241E755F4EULL, 
            0xD012203D9BD5289AULL, 0x473609503F39F4FBULL, 0xA231A8EDFA154241ULL, 0xA6E7709B7AB64EEFULL, 
            0xB3C5D6E33F01CA64ULL, 0x3B4E83CCF56E9FF6ULL, 0x8BCAB24DA539D864ULL, 0x3001C18B829CAC82ULL, 
            0xD7D674BF77F82F2CULL, 0x553E79BBA5CBDE5BULL, 0xD2FA1921B1E4198FULL, 0x3EC566247358C2CEULL, 
            0xCD5972211649E11FULL, 0xA277ECC49F3E57A6ULL, 0xD0E3DC0A2FA313CEULL, 0x3B86086C2F13E325ULL, 
            0x55ED3645F7D48F0BULL, 0x64410B9EDE73F71BULL, 0x01B738DD4FCC2094ULL, 0xDF109636F6492135ULL, 
            0x16917FFE5BDBC98FULL, 0xD58478AA91B0A86AULL, 0x0BBE620E1F44F18EULL, 0x8250A687AA933120ULL
        },
        {
            0x338E0D7AAAFFE204ULL, 0x561F6A06C6544082ULL, 0xF85CA608152CFA5FULL, 0x239D44C757ABD84FULL, 
            0x77441D3E16FF65EDULL, 0xDDEC422D02C50100ULL, 0x0BE13BA6CF28D74DULL, 0xFD43F69B9608129CULL, 
            0xE90E4681F9DE63C7ULL, 0xE3EE3F4DF0A3500CULL, 0xE69159D29EA9F14FULL, 0x19CB8DF2ED02AED7ULL, 
            0x44B2FD1E34B1D212ULL, 0x3816F76527327A38ULL, 0x928A812FF79D0C40ULL, 0x813FCD6FB1073CFDULL, 
            0x8C466023DFB7BBEFULL, 0x6FAA12F86F3FB98EULL, 0x5A47B6726DEB8860ULL, 0x75A437623010DED5ULL, 
            0x181B9DC45A64881EULL, 0x3372607EAC2C5D70ULL, 0xCAE1D46290A5BE8BULL, 0xB50B3FDB782E534EULL, 
            0xEC69A62D72D6CE80ULL, 0x693EDD9EE70D3670ULL, 0xA0AECA8529ECDE4DULL, 0x07E0138A25C182EAULL, 
            0xC729B3DE6A3E73F2ULL, 0xBC3249F3D567CA10ULL, 0xF6FD4593E6642138ULL, 0x4376B83828420D19ULL
        },
        {
            0xF9F63527C37AB3A6ULL, 0x74A371EC5D21B64BULL, 0x3260049BB2233AFBULL, 0x7DA84522E31A7A2DULL, 
            0xCDB65D6E6E452E2DULL, 0xB0DE8D210F4DA885ULL, 0xB24737521A95D6CFULL, 0x8DA8C6FC362873FFULL, 
            0x3D47F8454BFCEF20ULL, 0xE535B9D25721C77EULL, 0x7697B90210BCD53AULL, 0xD78C0EA6B049F0BAULL, 
            0x29D676DF89A8075FULL, 0x65D36B66F47CC7CDULL, 0x9B66884B3C49BA0AULL, 0x0D72855740B906CBULL, 
            0x3DE5B352DC06DB35ULL, 0x5CAC4D1C6034A5D8ULL, 0x161D7642369004F0ULL, 0x6E46E9C540672E1EULL, 
            0x376AF7B93FCEBA77ULL, 0x3A6D7F7D9FC50A9BULL, 0x5EF1DE087DB3E2BAULL, 0x7772BF96475F7451ULL, 
            0x3B5A319BCC38AE23ULL, 0x4AA0E299EFDAA49AULL, 0x1474D094BE5ED20DULL, 0x23E3D9432151B2CBULL, 
            0x009B48B53B9819D8ULL, 0xF8933C3B8B941280ULL, 0xE7A96F1417D20957ULL, 0xC497BB62A32078E1ULL
        },
        {
            0x1DCBFDDD53CBAD18ULL, 0xC732A717F6EA6EADULL, 0x0595273E17CC3CF0ULL, 0xA0A70DBC0DD46D93ULL, 
            0x2E253146AF92107AULL, 0xE6D59D74BF82254DULL, 0xB916516A7345B6E9ULL, 0x453C7864BEFDF068ULL, 
            0x144BB951EF7653F5ULL, 0x1BB518C69D0CD85AULL, 0x9249428E998B3490ULL, 0x9B0DF7592FE65F81ULL, 
            0x3D0BBFB2D0E382CFULL, 0x2E7AAF7680F7D820ULL, 0x1D141B555B6F0D11ULL, 0xEB43D56C33A1C20BULL, 
            0x97CC2201B722BB58ULL, 0xD05E92A8204CA989ULL, 0xA3CA6EA818733693ULL, 0x467EBA6BBB7EE11CULL, 
            0xA46E3E4D26530EFEULL, 0x80BAD10AB4646E68ULL, 0x6CF0346D55B912E2ULL, 0x2D015E2368A44531ULL, 
            0xACE82533F53E1064ULL, 0xDAD07CD6878C955EULL, 0x41BF9761559917DEULL, 0xA2B9572E53CCA078ULL, 
            0x385DA8F1CB2C9A52ULL, 0xD47E7D60B3D34EDEULL, 0xC497A500606D2D31ULL, 0x221C120AB908C47CULL
        },
        {
            0x8403A6281CDBF428ULL, 0x4C438FFF3E2F73CAULL, 0x50A3AF4AD9937395ULL, 0x26F2061783817386ULL, 
            0x5C0FCF46E0B72755ULL, 0xC2B08F69A9CA408DULL, 0xD886B22598D46B63ULL, 0xE13C1F1DAD2837F1ULL, 
            0x5BA0042E07CB0236ULL, 0xD5C39BCC8A1D20ACULL, 0xB861BC60E5264160ULL, 0xF3F7325AEF5B1BC9ULL, 
            0xEE2172CEDAFB8FECULL, 0x4DA849B6E6BC9D68ULL, 0x1CB6023C42073A88ULL, 0x32A5C6E051234B8BULL, 
            0xF312A1247C309830ULL, 0x57C1463443F60882ULL, 0x541BF67FCAA07A9AULL, 0x5747F3A106411626ULL, 
            0x79205B2251C5F841ULL, 0xCA5039FCACA41E3BULL, 0xDF194A413B307F3AULL, 0xC38B03644762742AULL, 
            0x30CFB78BB8EF1396ULL, 0x264E70C2C6CF6157ULL, 0x293EAB89910E8B81ULL, 0x8EE115AE8BCCB578ULL, 
            0x4111C2117C29823AULL, 0x7F7734522F97E096ULL, 0xBF65E0235A921F7DULL, 0xEF7840219F01FA8EULL
        },
        {
            0xAB2091178D49D6C0ULL, 0xA87FBD9B82342CDDULL, 0x1E9DAFF9E4984743ULL, 0xFB10C80820D46EE9ULL, 
            0xFA974D475FD2AE30ULL, 0x57F743E808E40A20ULL, 0x235E6CEB54ADC35AULL, 0xA0E2CF26FE590D26ULL, 
            0x88F81E11DE2C3B41ULL, 0xC98BF5CF33CBAABCULL, 0x0A7FC3A2EFA24D49ULL, 0x9BD07637B6CE6E39ULL, 
            0x9D90F3C2E71D765DULL, 0x719C952A49932751ULL, 0x05D57AC29A6788E8ULL, 0x83D49C2509FA1834ULL, 
            0xF7B067F2BA797155ULL, 0x7A0C44E4C50665AEULL, 0x4612200AAB0AEC5BULL, 0x21E400E7FF85E5C1ULL, 
            0x18761EB0C2D7DBFEULL, 0x565A67D7C90D05E0ULL, 0x1707BF8C0CA15892ULL, 0x4B28B0D6926BB95BULL, 
            0xDB8ACB27730FCB3DULL, 0xB6662033CA3DE02FULL, 0xB5676EF0AD3A4409ULL, 0x25BE9E0B7C157D4DULL, 
            0x0D563B130D6F3DD6ULL, 0x8647626CD74FEE25ULL, 0xEC385AC34A481661ULL, 0xA6EBB13BABEF48BCULL
        }
    },
    {
        {
            0xCE20CE8C063C4A84ULL, 0x376E55A199851E35ULL, 0xEAA2ABEC2A9A068FULL, 0x65FC546F14CC4F00ULL, 
            0xC35BC1469C977B3EULL, 0x30B51F8C8252DFB3ULL, 0x4A317FEA33A381A4ULL, 0x14131CA3EA794827ULL, 
            0x86E66A0957D4282BULL, 0x7AFD4F2422E32684ULL, 0x3AF9543AD9E6591DULL, 0x4E3E2E6398187665ULL, 
            0x4567696A89A5BA59ULL, 0x702F918E22042B19ULL, 0x07B1C4BE64D14CC6ULL, 0xD0510017AEE66C37ULL, 
            0x7AB904A3614995DBULL, 0x858C526D92AB1505ULL, 0x3066AECEF99DC23AULL, 0x8F940B09A6CED991ULL, 
            0xFE824F6B03FAD439ULL, 0x10DE278C044DBEF6ULL, 0x913E58EAF3740DFDULL, 0xF8E1B78DFA7B8736ULL, 
            0xCAA22CBD88B29A0BULL, 0xD47CE67C8FCCC51FULL, 0xCB322D9954B54D02ULL, 0x59A9ADBE18BBFCAFULL, 
            0x222643E9EAA4D947ULL, 0xE2AB9A0C33F9E483ULL, 0x2F0CD0F4F8E92DBFULL, 0xEC3A70B95CCDDC40ULL
        },
        {
            0x47CE4D7ED64ECBAAULL, 0xFE9B7F8DF6D7C4CFULL, 0xD523C4A36B327113ULL, 0x47B5D58EC8ADA2BEULL, 
            0x778596ED79561861ULL, 0x02AB6161330CD733ULL, 0x1F7FB92CEAC3DCBEULL, 0xB2D939E9224CABE9ULL, 
            0x1B1BB7F84D074633ULL, 0xE563DF5BB13E4923ULL, 0xCFCD9874099C6A51ULL, 0x60332F4E2A609DECULL, 
            0x3EC959F122535B8BULL, 0xD1A68E548C1D41CFULL, 0x5AD7DC87185338F4ULL, 0xDB78977A2025A040ULL, 
            0x67135DAFF6FEA793ULL, 0xB4D71BB1DE33E74FULL, 0xE9E54B55E719051CULL, 0xFCE965357661F541ULL, 
            0x545CF01E86CA94A7ULL, 0x44DBE732C09687B7ULL, 0x41676EBC2684ACBFULL, 0xF6A5300E6C660C0CULL, 
            0x18FDAC8F9E1F6726ULL, 0xCE87935E53D45C73ULL, 0xA66320731DE2421DULL, 0x6902F8F0F059133CULL, 
            0x38AB660EC721C18BULL, 0xE88A07DA766AB66EULL, 0x7701983B06B03932ULL, 0xEC50CE83F26891B0ULL
        },
        {
            0x63B0B7844FDEC6C8ULL, 0x409B939C5D958703ULL, 0x6FEBC6BD667938F2ULL, 0xCC0F8221EFB3D189ULL, 
            0x9B9E5C1E8BB17F55ULL, 0xB084420A6C1929C4ULL, 0xA9B9F887034824B5ULL, 0x8EDCF81ECE515851ULL, 
            0x1BAF308BAC92AF8DULL, 0x28F5ECE772426E7BULL, 0x49387A997B6FCA36ULL, 0xB9ECEED79B68C13CULL, 
            0xB1DDF5B869D49364ULL, 0x1D0E57186D0380F3ULL, 0x123A69A1E36E437BULL, 0x5C21223AF47F5E9FULL, 
            0xB7848A2474A610D3ULL, 0xAB53524B0AC94775ULL, 0x0E7B37378474A00CULL, 0x272B049020C96604ULL, 
            0xDFAA293F38019189ULL, 0xE388397B4DA37DD3ULL, 0xC833C5CCB86D89C5ULL, 0x5E8724A03ECAAB00ULL, 
            0x42F40EC3EC006E10ULL, 0xD9D9968407AEC8F5ULL, 0x66A9BFB64F88321BULL, 0xABFDB28DCE2F1682ULL, 
            0xDA4EB49F671FEF50ULL, 0x06D14F989A2108C8ULL, 0x36B0DBE7AD225BF7ULL, 0xA37E06C47CEC58F5ULL
        },
        {
            0x56C9FD849B2DCF91ULL, 0x9E3D32F78A912082ULL, 0xAE247962F9F4A257ULL, 0x396015E387994150ULL, 
            0xEFDE45448CF7120CULL, 0xF796396F2F039C34ULL, 0x33311118CFB5DDD9ULL, 0xA31EF98C870A9DCCULL, 
            0x4F891EEED711EE18ULL, 0x890D89A8F1EBAE0EULL, 0x4A6356F6DCD7C96AULL, 0x751BA70137CDEAEFULL, 
            0x90CAE0E4ADF61E78ULL, 0x74AF6D99085AA8D9ULL, 0x9F87887C9CC06D77ULL, 0x79224C5EA6BB839FULL, 
            0x37071D438924893DULL, 0x9B991A1BDF0988A7ULL, 0xA8DF1620EE9AF568ULL, 0x8EEA4CC98929E79FULL, 
            0x363876A4A34110E5ULL, 0xCFC5636E0F38F2B5ULL, 0xF6D8D0FE03148CE1ULL, 0x673BCCC3C9336D15ULL, 
            0x1AD2960584790BFAULL, 0x70C8E429DBB9F41DULL, 0x72CE6407705FFD00ULL, 0xE0875D8B8AF774C0ULL, 
            0x6F443760F9C103A4ULL, 0xD04219EA3442F973ULL, 0x671F66BE5DE910B2ULL, 0xA24A7AD890907110ULL
        },
        {
            0x30F1A5A0B5D068EBULL, 0x14C3A80A3811CCE7ULL, 0x0EAFDF0A3D5753A9ULL, 0xE740B6003DF7D982ULL, 
            0x3AA875C2A1107290ULL, 0xB9BDA013F7C30ABBULL, 0x2C76300801D0B368ULL, 0x53F8C126AB4025B0ULL, 
            0xEE3DEC90EEC96BB0ULL, 0x1F99F9312F55AC7FULL, 0x14D4D4C544B4C61DULL, 0x51FBB72D98E2FB6EULL, 
            0xDE8F180DBE339F2FULL, 0xAFF86D7B1E5B39B9ULL, 0x4B5176CC94C153A3ULL, 0xFE559C1C89E77710ULL, 
            0x057F40D90DBA0D01ULL, 0x1984301F6BB1CA06ULL, 0x779F6A029A4AEC8AULL, 0xDDCA35F24EED3239ULL, 
            0x7B74366BAA9E8ACFULL, 0x4E99710E136DE861ULL, 0xFF392DF3EDC70D9CULL, 0x4E5AD5902AD2D8C1ULL, 
            0x7F8CD88750C937B9ULL, 0x92B6D33341426D35ULL, 0xF6F7DAAEA5893447ULL, 0x22C428EBE5A738C6ULL, 
            0x64A642A9CC9A2A21ULL, 0x577E0B7ABE141B3AULL, 0x43CF9A05D734EB25ULL, 0x2296EBE510725C71ULL
        },
        {
            0xBADC7726013AED5DULL, 0xBF1EF2D4FFCAAD89ULL, 0x3AE30C40066CB353ULL, 0xE49917D71D50FE9EULL, 
            0xDC912B072B05BC15ULL, 0xDB833421E36B8DB7ULL, 0x84DBC57BA3AAC6ECULL, 0x0A26701DE060D8FBULL, 
            0xF066A75BB7F29DC6ULL, 0xEEEC211972D5D1F6ULL, 0x5A602297BE514C4FULL, 0x2F1B8F9C3AAFC1A2ULL, 
            0xAF6573A7D62CCA41ULL, 0xE9291E39E8D66168ULL, 0x766863C74EC34D40ULL, 0x3F0CE5802534A026ULL, 
            0xC580821649D752C2ULL, 0x30FED7D3592F0672ULL, 0x49BDF03575AFA124ULL, 0x43F0F53B21BFCC26ULL, 
            0x4B4F2DD5872701A8ULL, 0x8ACD0D2E4204961EULL, 0x086907E06A79A8A4ULL, 0xC56683D141B79A21ULL, 
            0x8810BCFE3ECA9A52ULL, 0xDE395CDB69CCB99AULL, 0x236C83EA77BD1FDCULL, 0x4178F67B8933DBAAULL, 
            0x4DA9B49C1165AEC1ULL, 0xFEC81D22BCBD3969ULL, 0xFA939FB938E88209ULL, 0xF33037722635B8B3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseAConstants = {
    0xD09E07F9F7FEA5E0ULL,
    0x04F405A3C3A3684FULL,
    0xDC8FDDF423D9CE43ULL,
    0xD09E07F9F7FEA5E0ULL,
    0x04F405A3C3A3684FULL,
    0xDC8FDDF423D9CE43ULL,
    0xB94672EAC9B12C06ULL,
    0xC9ECB3328349CC03ULL,
    0xFD,
    0xA5,
    0xB3,
    0xAC,
    0x01,
    0x9B,
    0x20,
    0xF3
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseBSalts = {
    {
        {
            0xE6611477F21EA265ULL, 0x8A18CDCB3AD94E8BULL, 0xA93A768CE20DFF73ULL, 0x186DA5ACCD5A42BAULL, 
            0x4129C794E965AFBCULL, 0xDA80291F7FE453FEULL, 0xFA02B577FB67DC7CULL, 0x1F8602DDA21ABD9FULL, 
            0xB728DB5B258EA68AULL, 0x2B6B377660273F42ULL, 0x8F4769949496E6C8ULL, 0x2FF49AF8C1FBD253ULL, 
            0xD9B3647ADD101D93ULL, 0x1E3F34EC21BEAFB7ULL, 0x6251F2D3E23FCDA9ULL, 0x530050EBAF82CDF9ULL, 
            0xC1C228543A037AE5ULL, 0x26275B1EDBA860C2ULL, 0x9ACFA6020B9FA401ULL, 0x0A0758F586CE00D4ULL, 
            0x240968959F466608ULL, 0xEC9D5F0ECB1AF24AULL, 0xF6674E6D64824C4AULL, 0xB2ED7C6E72FD88F4ULL, 
            0x35DFD713258C8AC1ULL, 0xA8C59F1CC268CC0AULL, 0xDBC1BB39C717DC7CULL, 0x9E7A243E0EA3A760ULL, 
            0x22455D4011D2DE6BULL, 0xE9ABD92D52484E38ULL, 0xE6A1CC5D1647EF2EULL, 0xF8418423EFACBD1BULL
        },
        {
            0xE4F82BEA4F6D1FECULL, 0xA305978592EE9F34ULL, 0x7DA3377E36FD6BF1ULL, 0x24DB270A7A45E984ULL, 
            0xB57E807AEA0FC14EULL, 0xD424109664C263B0ULL, 0xA593CDE725C2B92EULL, 0xA4DBA8840CCE55FEULL, 
            0x6C51177C0BB70772ULL, 0xD3662FF79BC843EDULL, 0x03E2A9EEAFCB020AULL, 0x43015A76BF182344ULL, 
            0x0CEE6014587528FAULL, 0xA46F35CA83BAF95AULL, 0x5E6087FE4586CF0BULL, 0xA021A4EE69EAFBE7ULL, 
            0xF394F93CD1059275ULL, 0x080B0D7279619ECAULL, 0x15DF0FFEEB8D6C4CULL, 0xDFB87D0A2574F01BULL, 
            0x09F07255D62194E8ULL, 0x9021C41BAB9B4F23ULL, 0xEC885F2CFA3275FDULL, 0x5A83CB8140C56621ULL, 
            0x219B88A53F678944ULL, 0xA2F53888F66D07A4ULL, 0xE661AF12A72FF19EULL, 0x59F32E9B68A79556ULL, 
            0x826F82E454523C4EULL, 0x8CDCB87FFE4D3052ULL, 0x28B86D69FCD29589ULL, 0x017E7FFBC53B8450ULL
        },
        {
            0x725FF9F2EA709250ULL, 0xF991AFF9B84868DCULL, 0x2A13FABF29721E42ULL, 0x86BFDFD3613FC76CULL, 
            0xA787A465891EEAE8ULL, 0xA3B2778DEFFAF319ULL, 0x9C5F42DD28D7BCFAULL, 0xA3546B2261BD5FF2ULL, 
            0x4A9E0E8715E648B8ULL, 0x0451A68213724510ULL, 0x3E681D0FE77DA6ECULL, 0xDC8A6172FC817F16ULL, 
            0xD8F5E8DA810281EFULL, 0xCF84CABD7CFC4552ULL, 0x4A40D190AED260AFULL, 0x0D9CF3DC4B08771BULL, 
            0x3BCAD290131F38F0ULL, 0x806CFFBDC188BADBULL, 0x80A59DD8122A2342ULL, 0xF6CCCE10E38836DFULL, 
            0x54509BC845F936D0ULL, 0xED0017CBAE31B149ULL, 0x45B5867F433EE642ULL, 0x1D131586AD043B78ULL, 
            0x199A853A69DD44FFULL, 0xE64CD0E40A6C1699ULL, 0xA08D187821AA14CAULL, 0x777093F0A4499659ULL, 
            0xD1F9AE739A98828AULL, 0xA2AB30A97ED236FEULL, 0xC5593F982E02DD2DULL, 0x51C263C5B1753346ULL
        },
        {
            0x897418780A0EC9DAULL, 0x2D676C70FB876E78ULL, 0xC9D155986D54D583ULL, 0x6D1A04D68CC0A7EEULL, 
            0x5C1CE2075DE4E303ULL, 0x4303E329D0E50789ULL, 0x59C507C9BBDE7F3DULL, 0x8DD7F44F2CE8AC34ULL, 
            0xED38E63F09F93DD2ULL, 0xD62375CD4B669A7DULL, 0x2F6FCDE3B6A2E1C2ULL, 0x4E3F6AB32153DA8DULL, 
            0x3EB003F958E5FE60ULL, 0x892946149FD22C44ULL, 0xAC35205B4E1FC3D1ULL, 0x5B2A7D44C55BA7F2ULL, 
            0x81510A12170A31E8ULL, 0x9FCB4575FB6043D7ULL, 0x3F0EF74482D88C1AULL, 0xC5026A4CD0771F36ULL, 
            0x1374A75FDA270D7BULL, 0xBE7B54BF65B30410ULL, 0x76E132AB394445A8ULL, 0x9A03326ED4D05894ULL, 
            0x7F765E8A9E77F83AULL, 0x2324EAF15928061DULL, 0xABB62CC4B9488E01ULL, 0xF39AFB1E340F36DAULL, 
            0xADB068E51C0703A1ULL, 0x4F10B326871C18E3ULL, 0x171AF05055E93F26ULL, 0x9CC2197C9BD5FE54ULL
        },
        {
            0xCB410329B142074EULL, 0x30F03B845F74F95CULL, 0xB32048E4F5C57E75ULL, 0x2645ECCBFB5F325BULL, 
            0xB27BDCD4950AEAD3ULL, 0x4AB78E5E31DD2C04ULL, 0x1E4856A128EBADAAULL, 0x7CD6E0F8D0EEA40EULL, 
            0x68ECB0CA15CEBB6FULL, 0x2B9850121F5984A4ULL, 0xE68B57C7E8425E6EULL, 0x5389806D6AB4F75EULL, 
            0xA08FCD43FB111D7DULL, 0xADD6A9AEAA20ABEEULL, 0xD26ABD0122CC1FD2ULL, 0x3EF177A760C036B8ULL, 
            0xFC312B3ED36E2C2EULL, 0x7920B7BCC2EE6866ULL, 0x3A0339DBFE403D5FULL, 0x73A5308BEAAEF3FEULL, 
            0xE36B44F169D7C01DULL, 0x79F4DCA27AE376F5ULL, 0x4493FAE5061C6256ULL, 0x6868AAC7A20E1F79ULL, 
            0xCC965D66093E609CULL, 0xC9B0A61E9107706CULL, 0x7C37C80519DCCDC7ULL, 0xFA0274A6EDF77CDBULL, 
            0xE75E34982F954203ULL, 0x682056BCEDE4B549ULL, 0xB1E570580FE2B6E0ULL, 0x3BD9F7CDA896FF3AULL
        },
        {
            0xBD56C9F498968772ULL, 0x96660AEEE4F80138ULL, 0x4A30A1DAD8003B39ULL, 0x76F1D47B5AC9CE66ULL, 
            0xFB40EADC313371B4ULL, 0xE6883DF0175FCBE3ULL, 0x432593A492289558ULL, 0xB8740E521E849BCFULL, 
            0xCF22700FBBB5FB01ULL, 0xECB2E5087D2AF700ULL, 0x5AA2CCB329D55481ULL, 0xF59B1E0C06F9FA08ULL, 
            0x7C4280A45FB829A3ULL, 0xB7D156CA921812CCULL, 0xFA3D2F0C5F96213CULL, 0x82ECAED8F357AF41ULL, 
            0x64368C533E4CA939ULL, 0x18B58857E2E104FCULL, 0xB14659C17042DB49ULL, 0x04DE00215E970561ULL, 
            0x5B210050E00290D8ULL, 0x8386556643B396C1ULL, 0xE3B4F806727C5C7FULL, 0xBED2E3458F1DE243ULL, 
            0x6C6F03A88077EF66ULL, 0x4158A215B7DA2213ULL, 0xB745AEC8E03BACF6ULL, 0xE199B38006C17C28ULL, 
            0xA55E2B0E9D2ABEC3ULL, 0x39B7904D2294ED31ULL, 0xC6D9169F9BD110FFULL, 0x7E475B12E0552C12ULL
        }
    },
    {
        {
            0x99A1277A68F4F024ULL, 0x63D3F65F9A0FC7C6ULL, 0x0DA5B9DEDC090487ULL, 0xAA57D49327433C01ULL, 
            0x1C7F44B01CD846C8ULL, 0x9023F8A07FACB807ULL, 0xE2A6C48FE5717991ULL, 0x2D7DA614BFBAA3F0ULL, 
            0x02462A2854449C14ULL, 0x3C718E6E81FB82CDULL, 0xC9115F1E671D0643ULL, 0xEEAAD52650FF9398ULL, 
            0xD20BD100F0D25F03ULL, 0xDD9B985C8775E4CEULL, 0xB058C3DF8005D6AAULL, 0x9141022B84567155ULL, 
            0x893FD550097328DBULL, 0x3BBFCCA0AB770395ULL, 0x1348FE960BAAA253ULL, 0x18D5D172F95F0663ULL, 
            0x995C0239666BBC40ULL, 0x08F1858D8A5E953EULL, 0x6FD91BE1014085A9ULL, 0xE3F7F945A08B29E6ULL, 
            0xA2018A8121D261E0ULL, 0x53EC29AF8BF7C5DFULL, 0xF66B4C1C0BA8DF10ULL, 0x260B7C2B771C147AULL, 
            0x00DAFC1BCF7438A4ULL, 0x9005393D6EEFC3C8ULL, 0x29EECE69B53E4204ULL, 0x7AFD05F96D907C74ULL
        },
        {
            0xD4C8DE08CBD97D57ULL, 0x1EA9FEFA4C33BA7DULL, 0x58ABD10CB7664185ULL, 0xF3591DA61E28370CULL, 
            0x232467B5E3406EC6ULL, 0xD3D94B3D14595944ULL, 0xA6C32FF6743E4704ULL, 0x00BC11751B794B79ULL, 
            0x497263169D4C1CDFULL, 0xF09B63BB883B508CULL, 0xEB7EADA722CFF9B3ULL, 0xAFC35E6EFC705856ULL, 
            0x08B8CE392E56E5F4ULL, 0xEE2903715DF020A6ULL, 0xEBAC79D4DB49368CULL, 0x8CF247C7ADF55EB5ULL, 
            0x694A393F74DCBE87ULL, 0xE5CFC4A25F2366B7ULL, 0xE4482ACB6F734B14ULL, 0x9E55B77470F680B6ULL, 
            0x395EAF7C397849AAULL, 0x481912D5A2216EFEULL, 0x9412C13AB5978B1CULL, 0x74402366993DA940ULL, 
            0xC722A40EB7062418ULL, 0x098F5308E5FD2D37ULL, 0x151845C82DA1BC30ULL, 0x92EF182F44B17255ULL, 
            0xEC42A5DC601A3D41ULL, 0xBF67137EBAD17B55ULL, 0x3050C027E9F46B2DULL, 0x397E9B5F5DDA5844ULL
        },
        {
            0x85DBD01227C749D1ULL, 0x2AEB59571D05575FULL, 0xC365BF1AEDAD0EF8ULL, 0x9F194A13C8285B06ULL, 
            0x110B9725D3D7A975ULL, 0x25C52D798A6E2651ULL, 0x06A83E043112F810ULL, 0x794FB16B48BF3830ULL, 
            0xC483AC503EDC0A19ULL, 0xC33BC5146E9DEF31ULL, 0x33BFB76C19F497DEULL, 0xEA90B8C280794EC1ULL, 
            0x35569567FC0211EAULL, 0xFC93011F5B2E1BC7ULL, 0x921F01787A235E22ULL, 0xC75D8AF820F455DFULL, 
            0xAD58FBF3FCB2CFF9ULL, 0x7874246CCE874C62ULL, 0x25F3C6842AAD0407ULL, 0x295F1AC4D54D4411ULL, 
            0x705A808FB5630039ULL, 0x9CB67E7BD35D4EB1ULL, 0x3D4A9608EA3D3D13ULL, 0x2DA5786ACB589324ULL, 
            0x017A4F840F9580D1ULL, 0xB4153E1066096A68ULL, 0x88F1E55422BF8A3CULL, 0x1EB1690AE44BF9DEULL, 
            0xAF7B8F5D936A2E2AULL, 0x2437685D3AEDD968ULL, 0x46069A7690C2E7CAULL, 0xD6498EE3AD83EAF5ULL
        },
        {
            0x30D2EB155A30D965ULL, 0x9AFEA773DA57927BULL, 0x7F94295230641575ULL, 0xE5537324F12710BBULL, 
            0xE9A10B950B1D6939ULL, 0xF036970BDCB54454ULL, 0x1DAC83ADFB5859C8ULL, 0xF2771168AC114E56ULL, 
            0x96152A95AEA03470ULL, 0xBD7F94E1D6522A69ULL, 0xCFD9C4701E7F8994ULL, 0x72192F224F55308AULL, 
            0xC8D05AE1A327B521ULL, 0x03985EEAC8F98588ULL, 0x8730CDE76CD7B300ULL, 0x716C78825F939C2EULL, 
            0x8151C4173A40DB2EULL, 0xB65F52A1209B8D21ULL, 0x13CDCF66CD763939ULL, 0x9934D33727E5D43CULL, 
            0xED2282619DF06826ULL, 0xEF321CE03C06380AULL, 0xBAF95CE31B91FF17ULL, 0xA653DF216AF7355DULL, 
            0xAF22AF62F898DCFFULL, 0xDFD60542A7D24E67ULL, 0x001B800CCED85201ULL, 0x11A210A6BC78EB97ULL, 
            0xD1E575C9103CAC77ULL, 0x7F1AF29410631895ULL, 0x7C3D61354E2EF2A1ULL, 0x932798B9FE98901EULL
        },
        {
            0xF12B1D48C7C1B87CULL, 0x4465FF91822C2C0AULL, 0xFDEE0BE68D1E4397ULL, 0xB8CC4E26D6D79A6AULL, 
            0x4CB2B32BEBD8AE2CULL, 0xFC42297EF3B6708BULL, 0xBCDD7C7661B17137ULL, 0x92301F2402A8EF7DULL, 
            0xD8AC407AF332D88FULL, 0x8B12BA74FE3B91C4ULL, 0xA8E5FB7BDAA665ADULL, 0xBE59D02603B09890ULL, 
            0x5EB619728CAB8EACULL, 0x198EF86AA04AB869ULL, 0xEA6051466C12DEF6ULL, 0x9575B6BE4ECAFCEFULL, 
            0x7081729B827799ADULL, 0xD004FB62D60C4966ULL, 0xF8C49B2F0F6E52DEULL, 0xCB456D1D904F2F94ULL, 
            0x9B6FE58EA011C722ULL, 0x611F5A0E3214D5D5ULL, 0xE0D1BDB05C8E1640ULL, 0x78E1399732D17808ULL, 
            0x3B39E7DD2544D3D1ULL, 0xBEC5C6369AE1C9C1ULL, 0xB84340475162BD2CULL, 0x8AC216B26DC79671ULL, 
            0x506D27A0DD197186ULL, 0x30604BA2360C9CB7ULL, 0x31B52B7F4DE4F2ACULL, 0xB670DB6276178D74ULL
        },
        {
            0x1E8C13E72608C331ULL, 0x93C2DA1F49B05F7EULL, 0x4B8C1AC93D0FB1EAULL, 0x9E3DE6FC8B13A473ULL, 
            0x60959982E439E873ULL, 0x1377F4CF1F1E785CULL, 0x5B168DF3405FB6B2ULL, 0x70BB25A815A8036DULL, 
            0x03202D161539BD93ULL, 0x7DEFF3B274381581ULL, 0x954408FB999481A3ULL, 0x248B3F9A53B06909ULL, 
            0x41C01EA904191F7DULL, 0x6B51BF44129A3C68ULL, 0x00F94EB948675FF4ULL, 0x7B97D15001A09372ULL, 
            0xED2A14F7CCCBE676ULL, 0x1FC9EDFB27AD5C8CULL, 0x03BD015441FF5C0CULL, 0xE5973DD9F2CB4145ULL, 
            0x7522982DCE4BA89EULL, 0x3C422D7B8B137322ULL, 0x05137F72A7ABE086ULL, 0xDD613972168EA6F4ULL, 
            0xAB87AAC55714B03FULL, 0x932166E36C91F8EDULL, 0x3E95758053865A4EULL, 0x37DD0EF2A8E96188ULL, 
            0x584905A6C3B81EEEULL, 0x079AE29C90110A8EULL, 0xEB44F3E5991578FAULL, 0x9204B4B26AFDB25AULL
        }
    },
    {
        {
            0x8C2A98C7508DEC95ULL, 0x85E00DE986C2FFEAULL, 0x577F6A6044C9B09FULL, 0x2CE310062D9B1B03ULL, 
            0xDFA9A57039BDFB27ULL, 0xDF81DE617535DE85ULL, 0x127188A59F7CDB00ULL, 0x4D43AA61C6E12D13ULL, 
            0x2BFD9F05DEDB3E2FULL, 0x186E98D63481F6BCULL, 0xB9E133A73FE615DDULL, 0x691C5128505B91ACULL, 
            0xCAEAB95A13376C0EULL, 0x467E5C41271255D7ULL, 0x9F251E2261F730D5ULL, 0xDADC219B96BA2DA4ULL, 
            0xF3CBC76DD1F55D07ULL, 0xA3B273AC93678612ULL, 0x54DA52F6A6B501BBULL, 0x84E518AB621D492EULL, 
            0x98484E6CB0FE3552ULL, 0x2A081B549C387195ULL, 0xEF337A2AB252EE9DULL, 0x0A1B1E05DFE86BFCULL, 
            0x7B4A025C50261C24ULL, 0x50A98933F3AE5C51ULL, 0x775A1606F3EC4F1AULL, 0x9D743146F126B08AULL, 
            0xAD2DBEFB13C7235EULL, 0x56ADE4EF7C1E232CULL, 0xF0B4AD7EE7DDACB9ULL, 0x84F50A073243D2F4ULL
        },
        {
            0xB42C554CFE858101ULL, 0x4AEC7B5C5AD5C839ULL, 0xCD9AE36E0B8A0517ULL, 0x17070DAE0467E4D9ULL, 
            0xEBDF90B91FE6FBCAULL, 0x04062EB5AC510E2BULL, 0x60CD497CAE99B187ULL, 0x2E8C78E71E97B1E7ULL, 
            0x6B2FBD887EB3E1FFULL, 0xC6686C4352F8BEB6ULL, 0x6DBAA277420CB9C3ULL, 0xB9439934949516AEULL, 
            0x39AD3FA623A8EE2DULL, 0x12C850C2593147CEULL, 0x4E53C0EDD76CD730ULL, 0x4E364ADB53C4D14FULL, 
            0x5555306711A280B8ULL, 0xF420C6350ABC6F4AULL, 0x33D4FE4EA13461C8ULL, 0x21B94856240880E5ULL, 
            0x8308835D822C4AD8ULL, 0x447FD862A641B873ULL, 0x59A8044B1E5E7CF0ULL, 0x6D0C8DE12F2F5CD1ULL, 
            0xFD3FD936F0702FAAULL, 0x482E1F7DD7F9FFB5ULL, 0x3715420DAAE90695ULL, 0x8E02B40B48B41851ULL, 
            0xC516D72846AF0E1CULL, 0x770D34E340522C64ULL, 0xA15669103196D44DULL, 0x020AFB26605565A8ULL
        },
        {
            0xB6B65C02D530B0A2ULL, 0xFB083316BA49E1FEULL, 0x20711D26CC9EEEF8ULL, 0x5890CC8A9A29B72EULL, 
            0xD8583490A5A1D156ULL, 0x5E1F2025D59ED715ULL, 0xA761EDAA50EAD218ULL, 0x2F018B1985C28728ULL, 
            0x4C978B4E47173157ULL, 0x6664A9D1E445B3FAULL, 0xEB9C2E0F41FFF0BCULL, 0x1AD09726141D6C97ULL, 
            0xD25EE4887800754CULL, 0x4A67BA1C7F98D7E2ULL, 0xC32C5D1F3E2DC29BULL, 0x75F103E35A16C5A9ULL, 
            0x8D4F200A4B12CF1EULL, 0xB1E03EA55E68D53DULL, 0x9C95F4D6C15ABFE6ULL, 0x0E39D9758796D191ULL, 
            0xCE6F078FBEF129BDULL, 0xD08B31A971382F10ULL, 0xD82E5C12A87637BEULL, 0x4CF506C9946BCCB0ULL, 
            0xD2B3DD2A268E6817ULL, 0x9DB5F368E7E8F748ULL, 0xEC58307D5D63F7C8ULL, 0xFB53F7890D6C27E6ULL, 
            0x1F64E40FD8B82FD8ULL, 0xFAC8D4C827BAF649ULL, 0x0C556C5533D73AC8ULL, 0x05E36F05C67E66C7ULL
        },
        {
            0x8493CED6326939F0ULL, 0x96F65985F80BEA18ULL, 0x96F2D7B664A53BD8ULL, 0xA28F35A831008FE3ULL, 
            0xE29C5C16F4314DDCULL, 0xFD35D74860306025ULL, 0x8B531E18EA69B5BEULL, 0xA9C1CB5A5D7268A5ULL, 
            0x41ADD66BCFDB479AULL, 0x8E053AC5AB8B7EE7ULL, 0xE0C1237A80FE828DULL, 0xD8D529C89E91B2E3ULL, 
            0x7AD5953FD5B0B98AULL, 0x1AB6E9D80975D6A6ULL, 0x254CC470F0257FA7ULL, 0xD182C64DB0657CC2ULL, 
            0x60D4254F924CB948ULL, 0x2DB3E5BC5476CF8EULL, 0x7B63765403C93B6DULL, 0xC7A6742C710D9191ULL, 
            0xF6DDD26386098AF9ULL, 0x60203DDD2EA1D925ULL, 0xC4BBFA366A54644DULL, 0x5C3E0152FB005C27ULL, 
            0x2861E46A2234B05BULL, 0xDD405D7E14D1202EULL, 0xC3824030FA9CC037ULL, 0x0AF87BDDCEA64F5CULL, 
            0xD82532D9FE8BE9ECULL, 0xADC98B0AA3746499ULL, 0x1E20C51193576657ULL, 0x22A549B3194B5D4CULL
        },
        {
            0xFCD6C0F86390CF68ULL, 0x4F054A7C6C6DB5C1ULL, 0x6BE9A377CC5703E5ULL, 0xB918C89E4CA3C718ULL, 
            0xF813E58358BB6FC5ULL, 0x1D0AE9EE7D368FC0ULL, 0xC4CD41DEF492EA91ULL, 0x3E19ECE9D0E29E4DULL, 
            0xA231A3BF6E79210DULL, 0xAFF411F4D51EB387ULL, 0x9612DF40B18567B2ULL, 0xA0AEC1B7315D250AULL, 
            0x222D64B4DAA96AD3ULL, 0x5C1BE96BAD259F7AULL, 0x962B365C411BBFFAULL, 0x3D6A00295255A83CULL, 
            0x05D406A2FBBE4FBAULL, 0x962F4EB8320BEF21ULL, 0xDF65C99CFF768BF7ULL, 0xE663B3FFDABDB401ULL, 
            0xD4EDAC98DE5EA2F3ULL, 0x694F849D2B961FD4ULL, 0xAA2F38D083F2558DULL, 0x8CEA2355835A4564ULL, 
            0x8B4A4EF0110B18AAULL, 0x79978009096BE9E5ULL, 0x354C859C986EA52AULL, 0x981FEF138C07D58AULL, 
            0xFF119AA89ABC561CULL, 0x5E323889F7D8EC57ULL, 0x273D11A86E14C754ULL, 0x22D0CD997B6A5787ULL
        },
        {
            0x937AB00714BFC442ULL, 0x0689E7A7F6130975ULL, 0x2AC6CC44D276B6A1ULL, 0xFD912D08382E9FB2ULL, 
            0x1226903973ECE30FULL, 0x3A75010C2141DE94ULL, 0x5CF437BAFB9B2C8CULL, 0x0E0B995EC9769A57ULL, 
            0x251A320FF9DC52CFULL, 0xA069A631B5E9D7E1ULL, 0x199E23A5229C55A8ULL, 0x4045BBEF50E101DEULL, 
            0x47B823207621C428ULL, 0x05229575F38CADBBULL, 0x854C795193A80CF3ULL, 0x520C9A0CF22E2459ULL, 
            0x18B51F728E4B8BC4ULL, 0xA53A931B008AE01DULL, 0x240B0E9C9E5A1C0EULL, 0x7F83C6BFE2BFBBF6ULL, 
            0xDA1DDB4E6050965AULL, 0x067D040D464A1BCEULL, 0xEEA079315B6E0718ULL, 0x0C00299F4F348728ULL, 
            0xAF65EAE221122E66ULL, 0x4532938420444EDFULL, 0xD383600EE031D510ULL, 0x3FA5BF5173FD6BDFULL, 
            0x0277C3BA72A2DAB7ULL, 0x5171CEF1B55215A1ULL, 0x4265D6EC0DBA822DULL, 0x47F47FD326BE89DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseBConstants = {
    0x52FCC31BC3B8C678ULL,
    0xD3C509865D3423CCULL,
    0x8A7311601BC580D6ULL,
    0x52FCC31BC3B8C678ULL,
    0xD3C509865D3423CCULL,
    0x8A7311601BC580D6ULL,
    0xA360690070D59A22ULL,
    0xDD72F490E2BFA214ULL,
    0xFE,
    0x34,
    0x61,
    0x72,
    0x67,
    0x6D,
    0x48,
    0xC2
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseCSalts = {
    {
        {
            0x67547B879AB03215ULL, 0x6233C464496B2939ULL, 0x9B49729AD8FC6BC8ULL, 0x2355D7E574F29758ULL, 
            0xDFD58D9F922BE714ULL, 0x8806CE916201A849ULL, 0x2B6F285300297352ULL, 0x7888F2E7B85F6F26ULL, 
            0xE321B72762AC88C9ULL, 0x1448BF892658C5A1ULL, 0x0FBC98DA2C66181CULL, 0x4DFC0D905CE27DD8ULL, 
            0x4826EA74BC680177ULL, 0x6FD6722AC835F9F1ULL, 0x43411D9D5EE61E7DULL, 0xFD2C336E962081C7ULL, 
            0x2E60729DA9C4A0F8ULL, 0xC7E7522BB6909E02ULL, 0x866AA048BB3DB7C4ULL, 0xEEFA02F35F9CD6ADULL, 
            0xB395A2B3572F21A0ULL, 0x72BB7F5C2A1F67DBULL, 0x04E39C21C0C9D45CULL, 0x32ACE7883E20774FULL, 
            0xB7E040BE6B33F51CULL, 0xF940FFBCE5442C30ULL, 0xE2EF12AA42CA1346ULL, 0x88A871AEDA5A7399ULL, 
            0x668CC5D1ED00F4D1ULL, 0xF7DC9EE84E673B4AULL, 0x7806847143810338ULL, 0x78C8C9B59F8CFC7BULL
        },
        {
            0xCA2FCEB2F8A972ACULL, 0xD6EF6CAA5E223786ULL, 0xBC3D87328F3C09B2ULL, 0xDC87681AFABBB855ULL, 
            0x63C5D02DC4E87B7DULL, 0xBE1D0DF68202CA95ULL, 0x8FC4D22EAAC932D4ULL, 0xE9C9F1214B5E1DF9ULL, 
            0xC0C0704A58F715F6ULL, 0x9384C05268D1DBD5ULL, 0xACC79D977921D250ULL, 0xCE748C375EB7773CULL, 
            0x8CD4C832969F2DC3ULL, 0x472628CB7B7CFD36ULL, 0x68A6A6B9C8AF7961ULL, 0x19E01194C06129AEULL, 
            0xF6CC3B13965AE146ULL, 0x30922F792BE7646DULL, 0xFB41E183EAE6A09DULL, 0x1C38131697AEBBFBULL, 
            0x3B0089CD76DD081EULL, 0x27DF60858FEBCC83ULL, 0x3D2DB358EEA42295ULL, 0x43950DDE7DAC0D4EULL, 
            0x91D22CAE2CF13E44ULL, 0xBB474FE2F6FA78F5ULL, 0x0776A340D3A9A86FULL, 0x40E91F7F5C06D0C2ULL, 
            0x9058207CA685F564ULL, 0xD5EC481DFD1AB62CULL, 0x8A73F5727422993BULL, 0x47A6F8DE6BB971F2ULL
        },
        {
            0xA0431320B2E3CAD5ULL, 0xF7864112669CD44FULL, 0xA60CEB472E811FEFULL, 0x073CCB8D515B2ED5ULL, 
            0x884234889543220EULL, 0x511A7A83C9C88265ULL, 0x7EDD4CE379B7DBBCULL, 0xAEA528CC0E4376CFULL, 
            0xA58CE76621E29504ULL, 0x2A0847F713B77D9CULL, 0x124AF54E1425C7FCULL, 0x32DE6A0AB594BF17ULL, 
            0xB4A4415EA14681EEULL, 0x5F7FA0C44F69AC0FULL, 0x82A69E7495F90FC1ULL, 0x32E4740BA677DEFCULL, 
            0xBDF45104956282DCULL, 0x0C183E6B51358F54ULL, 0x95498C57A36CA602ULL, 0xBA6727F1405D7858ULL, 
            0x52EDED3A337F4AF2ULL, 0x38CB41B39396C235ULL, 0xC16F731550674CA9ULL, 0x2169369101FE0F47ULL, 
            0x3161819BEA614A20ULL, 0x0D12DBCE8F2026C1ULL, 0x6F5956EDB7981001ULL, 0xD8FFC5F71584CB31ULL, 
            0xC243903143C052EAULL, 0x427694C5F2C5459AULL, 0x901F975767A14C6DULL, 0x0B67A196BCAE521DULL
        },
        {
            0x2697C2903DA4B9C4ULL, 0x694362AA022A626BULL, 0xF94B51CDD96F1B9BULL, 0x700A13391E7F38A8ULL, 
            0x6E7E591107389292ULL, 0x59D7F6FCE0E1D3ACULL, 0x026E235EEE9AD6FFULL, 0x8363A2DF88EFB63CULL, 
            0xAE60FE46668C23EAULL, 0xA6DAEDBE0CFE2267ULL, 0x5CB919F2B7B0AF03ULL, 0x533610E7D6E61C81ULL, 
            0xDB8172D05FAA50ADULL, 0x64DEA2E79E54DA70ULL, 0x5254C751705CC091ULL, 0xF7C3B6698CA6920BULL, 
            0x98305F13253AEFD6ULL, 0xB573BE99AC7CB653ULL, 0xB5B4B4E5B0C78F7BULL, 0xC9298BB657A4BABFULL, 
            0x657E492F1C1F4EE4ULL, 0x0B1E337614A8AFC5ULL, 0x526DEB05C7100DDBULL, 0x0BFA4F52C1EB6A93ULL, 
            0xEEDE476FA053EFE0ULL, 0x5E7BDE3542F7ADDBULL, 0xCC4FD91A04DEA3A9ULL, 0xA3384C20A32BF214ULL, 
            0x2BB3102BFE14516CULL, 0xA59C26FC7ECEEB82ULL, 0x6C43D7C35E3C7A89ULL, 0xEA9EEA54390A2426ULL
        },
        {
            0xB5BCC2B356C54885ULL, 0xABF37F5A24CF7CC3ULL, 0x5BFED10DB1E4B0ADULL, 0x274E364F9D1E7F8EULL, 
            0xA6C69877B4EC4988ULL, 0x6CE868BE50F5DE2CULL, 0xA6A8D9E7779ABC4BULL, 0xF8F48FD53EB33F72ULL, 
            0xF629BA4A5223874BULL, 0x5DDDCFE1BEFFB1F8ULL, 0x5FAF918A50880483ULL, 0xBF013D8F75CCA1A6ULL, 
            0x6194D7B2717DB9D2ULL, 0x30D15CB412E7D5D6ULL, 0xE4D507AEFAD13CDDULL, 0xEF8016B96FBF32B5ULL, 
            0x11486F3F2ACF6B26ULL, 0x4B588CB21CACEDB9ULL, 0x212851A8781AB6E7ULL, 0xC62918A535697A79ULL, 
            0x071458E108AD98A5ULL, 0x5D05CD0321AAC3B9ULL, 0xE7370586180995FCULL, 0xD723D0A3C427A9BBULL, 
            0x00EC796684D726F1ULL, 0x51AF1FF677E9A97DULL, 0x8E6BF86164025FA7ULL, 0xB6FFB8577F5CE80DULL, 
            0xA41C0901579E1D73ULL, 0xAC7B6D6D00A5EF00ULL, 0xDF7553629A5A13CBULL, 0x41042C0BF0F8B5D6ULL
        },
        {
            0x5FC1982004DEE932ULL, 0xEA3C521858BA9DF4ULL, 0xFBE0B2B55287D6EFULL, 0x02B2894321D78454ULL, 
            0x7C844EF04AB62004ULL, 0xBE818483239057AFULL, 0x0050B00DB503C686ULL, 0x47E46B3268551595ULL, 
            0x259618F05216D0ABULL, 0x8D7E64E7E9E9331BULL, 0x63F8A19D54620748ULL, 0x2CB8B6D68C151F19ULL, 
            0x330559BF760D801DULL, 0xCD6496A69D8D538FULL, 0xB18496B28FC71D81ULL, 0x59786866E9E926B8ULL, 
            0x30EFB0C17EE0F07CULL, 0x6A976DEC2940A9A7ULL, 0xFCFFF6565596D59AULL, 0x7DA2BBE29AE26168ULL, 
            0x62A8AA8FF09C22EFULL, 0x053C7A93373B7FF0ULL, 0x72349736B9C5C8F8ULL, 0x6E943779500A3158ULL, 
            0x0FD1D955A2F4B50AULL, 0x5387B7CADF3F43B5ULL, 0x30538FA30A632605ULL, 0xDDBB0BF4DD508C24ULL, 
            0x4E0677D3D278607DULL, 0xE689CB80E1970519ULL, 0xAEB8A9A70B5FDEFBULL, 0x7CA1D857AAD05C04ULL
        }
    },
    {
        {
            0x5B6BA126A90598D1ULL, 0x07BF2BB3F3F956FDULL, 0xDB874C94F4ADDCE5ULL, 0x7E127A69BF7562F3ULL, 
            0xF144A10286FC12CDULL, 0xDD517C1BA18E2251ULL, 0x209E909A18999D7AULL, 0xB6B80673783777AFULL, 
            0x62FBCB372813B6B3ULL, 0xE183AE163C431CF7ULL, 0xCE99E95DC874D5DAULL, 0x9480C780D3437BD7ULL, 
            0x2C770C555D71A479ULL, 0x021B4D2A36134A38ULL, 0xE517299284EA1C8CULL, 0x5996E1EB1DF86A18ULL, 
            0x25F561F1BCD45D2DULL, 0x124C12ABFF0B35E7ULL, 0x0DE6F59E9A762628ULL, 0x3ACB5C6C83AD9C69ULL, 
            0x7A1F70A5A1B88BAFULL, 0x86D8216C6B3BD5CEULL, 0xAE33F0C01345F27FULL, 0xCF67B7D713018C0FULL, 
            0x9F1778661FF558CEULL, 0xCFAB341C2F9E1E47ULL, 0xEF9464E851518951ULL, 0x9E14EC1A848EF40FULL, 
            0xC7B85013A2C788BDULL, 0x3A7BB2A37C739DAFULL, 0x7E0870A618C4DE5AULL, 0xB1202DDA52BDEC22ULL
        },
        {
            0x6D69C657C6146C85ULL, 0x861EC83FD4EAD18FULL, 0xFE5EFF111C59B756ULL, 0x7CC22F7AEAF604D0ULL, 
            0x33FDBA016827698DULL, 0x2FC07F4AF31E9B28ULL, 0x930760B0FA2D27C0ULL, 0x37833E67A66DFD07ULL, 
            0x3A8362216FC0F917ULL, 0x313279DE7C8666E5ULL, 0x5902EBEA15E1BD22ULL, 0xC6167EBED265DAFCULL, 
            0xCF9E75E5C2282002ULL, 0xCE814052BB04F589ULL, 0x478853CA7FEDFCAAULL, 0x59A65AF974202AD7ULL, 
            0x8F009D21E7700513ULL, 0x3E31A6A1CAEE0BACULL, 0xA868FC4E151A509CULL, 0x5B30D286EA8176D0ULL, 
            0xFE9A6DCFB2F0023EULL, 0x0181C36223155B7DULL, 0x17D54ACBA4A3DB7FULL, 0x0E8ABB78653B1983ULL, 
            0x38863489FD740D29ULL, 0xA5B60DBD76DDFFDBULL, 0x8F40D2E8A251157CULL, 0xD7A94599090362EFULL, 
            0x0EAC35F4F267DFDEULL, 0x77B188ED87BF1905ULL, 0x4AD6A521FD92894AULL, 0x727F8A90DFF3BE0FULL
        },
        {
            0x41D7851D030AFCA6ULL, 0x21EFE9829ADE6105ULL, 0x9075D00AABD14483ULL, 0x57E734391968B66DULL, 
            0x87F24BD5121C140BULL, 0xCBA399E041153B80ULL, 0xB0C92AAEBE3141A7ULL, 0x3F003D76C5F3AB35ULL, 
            0x7959757E8038D19EULL, 0xAC64BD980FAF10D8ULL, 0x45A4123B6AC9B16FULL, 0x2EE4B0916A5FFC67ULL, 
            0x511BD692AB3B69C8ULL, 0x14E17B08315F74ACULL, 0x6F6E59645EF9FD36ULL, 0xB7A83CCEE9F80F95ULL, 
            0x995E317072BE5C78ULL, 0x4E4DF7680BA4A735ULL, 0x5AA6AB87C564613AULL, 0x490C1F0AD6EF1D60ULL, 
            0x54E96EEF436A0DA6ULL, 0x994B5710600575CFULL, 0x578AA3BA7DF3BF51ULL, 0x7B92C6E6BDED2704ULL, 
            0xC01F971101DF54AFULL, 0x0D18B8D59966900BULL, 0xE3EB7340E8D2B185ULL, 0x69B703EBD70CA9D0ULL, 
            0x0F0BD59B33CDB466ULL, 0x921D91C0BBDAA216ULL, 0xC7A77E0F9C34D13CULL, 0x9331491964B3D0D5ULL
        },
        {
            0x3B3EC392CB651A5BULL, 0xD7481946C28D3992ULL, 0xE472A74B4C8F5EE8ULL, 0x2400E73A4BD74F31ULL, 
            0x3B238B26F9E553B5ULL, 0x1C49253F4434FD93ULL, 0x8738F37E51999695ULL, 0xB56590AA19E9F947ULL, 
            0x85569A1B6FA726E6ULL, 0x25DDA9B42F5FCD56ULL, 0x93C2641B74720D18ULL, 0xF0C92002E1072AF8ULL, 
            0x00689F864EA45152ULL, 0xC36D6E76AD179298ULL, 0x276D8A72A0D9797FULL, 0x6ECB51DE21DF6C47ULL, 
            0x589425144B5048C5ULL, 0xFFCE30E4E786070EULL, 0xDD46F0ECAD087F2FULL, 0xBC7FCFF2300B2513ULL, 
            0x1049F2383999F8F3ULL, 0x33E18CDAEDC8E1ACULL, 0xB94074EE29901D4CULL, 0x4BCFB5884FA72C4CULL, 
            0x70E05D6EE4670457ULL, 0x9FD05AD50AE50056ULL, 0xE81C8621DB0DDD7FULL, 0xA2C3C98E2311EA9BULL, 
            0x8A41F05F88C9311CULL, 0xEA3EA6B545CBA870ULL, 0x0CC54426FFE66300ULL, 0x12560E54FEBB0795ULL
        },
        {
            0x271906965563F5B7ULL, 0xE078E76B3E948D3CULL, 0xE0B9DD02C6C399D0ULL, 0xA2167A5460E6B981ULL, 
            0xACB59EB9C328FF2BULL, 0xDE4AC1A59928CA21ULL, 0x1F9BA41E8494E38EULL, 0x84A0A6BB2E8FA762ULL, 
            0x63111CBBDCF067FAULL, 0xD22C8EE1E3442D97ULL, 0xAC43AAD5652C400DULL, 0x6373D7BBA11F923EULL, 
            0x212D0F437934CD9EULL, 0xE796FD61F65067DDULL, 0xAC339482954EC912ULL, 0x987743B39DC8E0BAULL, 
            0x5E27B08A6DED5F34ULL, 0x0356F3524C6D0B5EULL, 0x4D17CE4A898F9E37ULL, 0xFCFAB8795A2CCF79ULL, 
            0x13742B7FAF41B131ULL, 0x6688338CC28C6C95ULL, 0x2135D5DD196F73BFULL, 0x1E0CA6FFBDA8C769ULL, 
            0xCCE4D650BC94280CULL, 0xE82499370AF3747EULL, 0x074A145B3A87B8ECULL, 0x00A3EAE4740A3455ULL, 
            0x4E14321848824371ULL, 0x94B10A5D022C22DBULL, 0x2D939F4D41D4D035ULL, 0x10FA04DC14827F3DULL
        },
        {
            0x2165DF5CBEE08DFBULL, 0x5BA9C80F304F72E0ULL, 0x176E97FF70763330ULL, 0xF323CED09D643A37ULL, 
            0xEE38254DAFBAB3A1ULL, 0xF8172E5F05CBA2ACULL, 0x596B41FFAAF57A54ULL, 0x83F453A9F470E467ULL, 
            0xA368507AA2B06D69ULL, 0x1A80ED338C1A86D0ULL, 0x014C2723F0FEFEF5ULL, 0xF4CE10A631FC9698ULL, 
            0xB1E63FD45AAE131FULL, 0x7DC96E12698F923EULL, 0x49256DB89A662F4CULL, 0x2F2568CCB010EC30ULL, 
            0xE04733B0FC8A698CULL, 0xD9D2CEA9E2EEF40CULL, 0xE687F38A31C565B6ULL, 0x0074E4B6326E617CULL, 
            0x31BF2BADF978991FULL, 0x57222D70EB42A96AULL, 0x613A93CBD8FF1F31ULL, 0x753E69ADF063D719ULL, 
            0x9A084D8C8CCEA274ULL, 0x14FDD85849AF5A1BULL, 0xA5EB5785E535ADE0ULL, 0xFF764473A668B3EDULL, 
            0x2B1BE2DB47392E18ULL, 0x66C87DBB06EE00DEULL, 0xE2BBF6AD5809F4D6ULL, 0xDE2A8B81259351E9ULL
        }
    },
    {
        {
            0x656DA64C759A3F83ULL, 0x86100322836006C4ULL, 0xDB72D45189DE1060ULL, 0x8CBE23D64C960C2DULL, 
            0xD27D125F33E3164AULL, 0x8905142ECCDC989EULL, 0x22E437F0DE52BCCFULL, 0x990CB26642F665ACULL, 
            0x67EB37E640FCAFD0ULL, 0xEEFA96E510B1919AULL, 0x14B4EB83CBC1A1E3ULL, 0x64F52691DE24F6E5ULL, 
            0x3A9244A2C02F2B82ULL, 0xFB209F0B747E8E41ULL, 0x215B6F2322EC2C8AULL, 0xD33A5423B3054857ULL, 
            0x6538CA41EACD5A92ULL, 0x8C0EBAF80118AC26ULL, 0x9BFF6EFFE2823959ULL, 0xE1325D313D7C7DAFULL, 
            0xC8DB9CAAD5E0D72DULL, 0x83176F99E839E967ULL, 0xFA984A3D7766A076ULL, 0x96863BBBBEDC87FEULL, 
            0xC108992F06AFE9B1ULL, 0x9AF2B825936ED210ULL, 0x3843A10E3FC3FB21ULL, 0x1A601206FF9A0F72ULL, 
            0x2F162110DD6E7418ULL, 0xC11040DF102F6E81ULL, 0x016B9807065B881CULL, 0x6917F251A38E2A93ULL
        },
        {
            0xC5B2140F44511282ULL, 0xF28C9A9F51F74A52ULL, 0x88F301F2205E9D67ULL, 0xB1F1E34F8772E148ULL, 
            0x4ECA0CBFABCFDBFBULL, 0x393CA1FB5AF14427ULL, 0xEC60141AA2FF81C1ULL, 0x2F255415436B84E4ULL, 
            0xBC27689779C91D81ULL, 0xCA6D1C4DD73086AAULL, 0x064A75207D80E084ULL, 0xC7734849A93CD687ULL, 
            0x732480181DD47556ULL, 0x1C47E15BFE0DC498ULL, 0x6D71EF9DEC19B628ULL, 0xCC94C682838E4065ULL, 
            0x9048316F14DD41EAULL, 0xBFEBCE1EBD40BDD7ULL, 0x15CC1C09345F2375ULL, 0xA34710EED0E3635AULL, 
            0xF24D4B15552B4EE8ULL, 0x673DB4C68C50DBF4ULL, 0xED6CE98EE3D7AF31ULL, 0x18C2370BDDDD7E9FULL, 
            0x8C66EABC01DCD816ULL, 0x59598A668EB0FD0AULL, 0xF03D4C4EA3B156C5ULL, 0xEEF2A2318A562B81ULL, 
            0x5FFC6191A38D2D4CULL, 0x88E6CE75CF21DDA2ULL, 0x257B934D593EFCCAULL, 0xB83C7EE38EE2827DULL
        },
        {
            0xA594D0D335B86A19ULL, 0x0E4BD0A278A2A3AFULL, 0x41E1885D07F9EC41ULL, 0x90D09C801371ACA9ULL, 
            0x0E958703C7627805ULL, 0x60E0E199A2E6997DULL, 0xA5A6E99C69FD572AULL, 0x5D86950B167B6135ULL, 
            0x13F930594DB97F1DULL, 0x630266F0AEC63981ULL, 0xE7D367133B5B2F2DULL, 0x019DA1C7C74E1EB8ULL, 
            0xF1FDDED205047F3FULL, 0x90CA557165E8F1C3ULL, 0x2A1DC2EF0B82C224ULL, 0x4FC452B404CE796FULL, 
            0x5E0CA376AA31C16BULL, 0x1B3E95A7C63895A1ULL, 0x0A24C0F94986B81BULL, 0x9B22B41A096A5483ULL, 
            0xB398166AE7BA16B2ULL, 0x572929CD47DC602EULL, 0x3D3683B6B1D60325ULL, 0x4DBCD0AD565315DEULL, 
            0x6AAA1A1C71F37022ULL, 0x7443359C4332ACBBULL, 0x0B217971BBFBC90DULL, 0xAFD28036F72AE0EEULL, 
            0x280323101E0C3DA2ULL, 0x5ECF750A7CBEDD52ULL, 0xD0E46E22A81588BEULL, 0x88049141198A1966ULL
        },
        {
            0xAD7DC3F31BE4D5D6ULL, 0x5220F16E1BE2CE8BULL, 0x1550D109AB9A8C54ULL, 0x97DD6F079B7AB34AULL, 
            0xB9C4AE135EEE272DULL, 0x0E9EC11AD7900E2EULL, 0xCBC1B4177435C1EFULL, 0xE4258A5D8EFBE862ULL, 
            0x965395A753F16EB7ULL, 0xA3BBAA6CDE4128B3ULL, 0x6B9A0E8303D3A683ULL, 0xE4154BD9E151569CULL, 
            0x0C2FD3B63AB3CECEULL, 0x1632855B58B56C7CULL, 0xEE83C16AE4178E85ULL, 0x3A8B2EC247A7218DULL, 
            0xB50EE33A7DE859EEULL, 0x2F97D92BACECC195ULL, 0x7D02781E71CC3011ULL, 0xBBCA398D330CAFD1ULL, 
            0x41FBD2B4468C7CF4ULL, 0x9EDD7409EFBA8F48ULL, 0x3CDA607A5001C786ULL, 0x3F050D7EC2BE1896ULL, 
            0x09C2A5BD4F2AD1B3ULL, 0xF64C5DC48E19F08BULL, 0xC6CA9B560A9292A5ULL, 0x285CE05612F19EAEULL, 
            0xFB83E7DD4EA40AA1ULL, 0x958D08E9BB33263CULL, 0xD31143D5DAA465AAULL, 0x90B732DCB37F7028ULL
        },
        {
            0x2A818191F30EA3EEULL, 0x5510972C26B9F7FAULL, 0x9DBF3D92856654BAULL, 0x439B56C50810BAC1ULL, 
            0x737A65FCE0244834ULL, 0x2E9D36BE6A5F0821ULL, 0xB738ED220438C4E1ULL, 0xF256EC81C6656A47ULL, 
            0x867A01279032C259ULL, 0xD22FA90754AA444CULL, 0xBDF31D40126BE048ULL, 0x933F82CDBF293C0BULL, 
            0xF8233705C5063BDDULL, 0x2A0EE8E039958EA2ULL, 0x405744B821578033ULL, 0xB9F95EAB5B1A0152ULL, 
            0x69DA0DB843205561ULL, 0xDAA75E5308417D14ULL, 0xB51B4A53E6C85B92ULL, 0xFB500C3D77068247ULL, 
            0x7BAC214683A6A477ULL, 0x5E8ABF025A44C893ULL, 0x1981C37C97A5504BULL, 0xB1105A68834BA1BBULL, 
            0xFCCEFEAB665BF529ULL, 0x42F23B8F60831ED6ULL, 0xAB6CC3BA24C2A83BULL, 0x0D05B832F0C9C89AULL, 
            0x1FB1CACC16E1EF2BULL, 0xDB26387EE2B3CF7AULL, 0x21975D263A07A2C5ULL, 0x771E2A5E565928B8ULL
        },
        {
            0x3906CD7CE88F1ACCULL, 0xAA1A111163306032ULL, 0xE31C6E7C8925662BULL, 0xEFE852AA389B3300ULL, 
            0xD414F634AB025F64ULL, 0x3E7116ADFAF461BDULL, 0x9F0C07AEF0097982ULL, 0x29EFFD03652C6E72ULL, 
            0x55F10692E1DF27C6ULL, 0xDE18B98134FCC3EFULL, 0x7BEC8A4C7FA93217ULL, 0x1D14D0A2EF805674ULL, 
            0x37DCC8BD31E66544ULL, 0xDF732139004B2E4AULL, 0x887305313E00C9EEULL, 0x376CA6969B6B198AULL, 
            0x06EF0BFCF60682D9ULL, 0x269C0601EC4AE049ULL, 0x5C3A9B498B6FEC90ULL, 0xCE1818C84F172AB6ULL, 
            0xB17A44DD0EF5C202ULL, 0xB1F69179CC6FACFBULL, 0x91B86D5E776BE828ULL, 0x8A0B8097ECB73D7CULL, 
            0x23D0FA21F28E0B0EULL, 0x68DA68AD8B7B9B12ULL, 0x1CCF3C69CA9E05B6ULL, 0x72DA9AC5C7D9653EULL, 
            0xF86D814396F00605ULL, 0xA080A35E9D75D19DULL, 0x5AEA212FB30305D3ULL, 0x4A630E4CA920BF1CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseCConstants = {
    0x00ABDD02D4CD3E1DULL,
    0x47E3469899DC2909ULL,
    0x2BB8CC930867F37CULL,
    0x00ABDD02D4CD3E1DULL,
    0x47E3469899DC2909ULL,
    0x2BB8CC930867F37CULL,
    0x848C184C94EB7525ULL,
    0xD4E0DEF986ED477BULL,
    0xAB,
    0x08,
    0x84,
    0x1D,
    0x48,
    0x6B,
    0x1E,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseDSalts = {
    {
        {
            0x31045F76B259B6A0ULL, 0xED70393F6C28FDCAULL, 0x2A269CE2BEA7ACD6ULL, 0xCEF7BAAA7F48B97DULL, 
            0x3451DF4919B20BC8ULL, 0xD1BC2643F40F0634ULL, 0x951E827580C0D9BFULL, 0x5A06C5F61D09F078ULL, 
            0x793ECA5812EB8B09ULL, 0x39CF564C46C41FEFULL, 0xE8F2FA17F6EA211EULL, 0x15DC4D314D0420F1ULL, 
            0xB61A5870E548D28DULL, 0xD0B87945A97832B4ULL, 0xAB50DC2606B629CDULL, 0x744E248E698B4E2FULL, 
            0xA8ADE36486D521F5ULL, 0x46E5BF53026F2CF3ULL, 0x8968960F54369201ULL, 0xAAFA6DAABA6EE9F6ULL, 
            0x47A6AFA7E5937310ULL, 0x6D102C30D7CD9A7BULL, 0xE03CFC1EF6D9CA04ULL, 0x6A3AD20BE490FC52ULL, 
            0x1C9119A32B11B711ULL, 0x0454AE262846277CULL, 0xF0E6AC38E716CE19ULL, 0x0DDB5A43614FD404ULL, 
            0x7C646202194C7C39ULL, 0xADAEDCEB101DAF5FULL, 0x6BCDFD1520C77B2CULL, 0xC185D6B2D7C77A65ULL
        },
        {
            0xC56C2B052F30D1F7ULL, 0xF63FD750FFA2761BULL, 0x8FA87F57805C4942ULL, 0x449014092297D2E7ULL, 
            0x96414A8586BE0EC2ULL, 0x4139F226EB40238EULL, 0xFBAB50BE6D9CE8D5ULL, 0x133913B6E5C95913ULL, 
            0x7E3C494E266A93CEULL, 0xDFE05D9E5BA600D7ULL, 0xE2DAE896009F146AULL, 0x2CB7A5DADCED9262ULL, 
            0x5C8FB71EE7844E0BULL, 0xB95B38C9466F40C6ULL, 0xBA94DC81A0DEB6B3ULL, 0xCCF95A2559713712ULL, 
            0xE951943007F69F12ULL, 0x10FB8E30D22BAC6CULL, 0x3D9953A0A04AAC47ULL, 0xBB5982745B7D185EULL, 
            0xF8459B950F903236ULL, 0x6E81E789CAC8DD7EULL, 0x2474F248E246EA51ULL, 0xDB91A56026F4DE7FULL, 
            0x71A8094EE6A2B241ULL, 0x4D126262DC3C61E9ULL, 0xA6BAC8DEF331EC2BULL, 0x07B97AE7B0CAD44FULL, 
            0xD26021C7A09D68FFULL, 0x58D6F08A510577CDULL, 0x2A75364D1866FF04ULL, 0x4B97A453790CF532ULL
        },
        {
            0x9E81CF04B1E1D5E3ULL, 0x47A7B07FAEE35CCEULL, 0xE2E75C67AE491E98ULL, 0x4B130DE193A6281EULL, 
            0x82DE1499C6FFE30DULL, 0x82753E07C1144625ULL, 0x980594B0E5D54B75ULL, 0x7D283B3C2A98778AULL, 
            0x0F6EEB803B2765B0ULL, 0x8F1999585D99391AULL, 0x2722A9116EFC0020ULL, 0xFE857C64BE923555ULL, 
            0x8E1AF41490D6DB04ULL, 0xDD23220F9FE30A4FULL, 0xB28CA90A8C56A5FFULL, 0x0A22FF926205F41AULL, 
            0x758E5779BDF2DF37ULL, 0x67C3F8CFAE234616ULL, 0x152553F065F2C99CULL, 0x7FF8D15B69E3938FULL, 
            0xAC322DFC0D719F02ULL, 0xB565E1A0DB5B0AE5ULL, 0x08647E148C2C9145ULL, 0xD1EE5DAC2E0043A7ULL, 
            0x20369480283DCBEDULL, 0x1BD5A3BFF24CA3F9ULL, 0x910417BBCC3F5583ULL, 0x37FE6D3613DE0888ULL, 
            0x5FCAAD8DD027C55EULL, 0xC5E7CA378B7FDCEDULL, 0x1F9F5DCDE08B4847ULL, 0xC0B80989F5E18351ULL
        },
        {
            0xFAC275FED05DE34DULL, 0x748CA60FF0D5835FULL, 0xF857A1685B5D4372ULL, 0x3EA70CD0DFF4C8DAULL, 
            0xCFBB9B023522256BULL, 0x31C167BE50634FC7ULL, 0xD697228FD26A3DAEULL, 0x46A05BD463B1DE87ULL, 
            0x2D4542C9BCAC3097ULL, 0x6EE4DAEE7F0CB14DULL, 0x3381D7226E7451A8ULL, 0xB7E26C5E3E12613FULL, 
            0x7289F283872E83F2ULL, 0x312D0ACF707D1440ULL, 0xF9FCC87A5CB7FB6AULL, 0x68A842E740F6B2D8ULL, 
            0x520313FA325BE082ULL, 0xEF65527A4F820791ULL, 0xBBD95BAE9FF9BA96ULL, 0xEA4C007703D9C827ULL, 
            0x7ED13E1826042F0CULL, 0x753FCF5D61E2DAC9ULL, 0xB04804D48D31AD9CULL, 0xE822CCA799B7F5E8ULL, 
            0xBDF2C67276790E44ULL, 0x6FB9CB5D79EFF93CULL, 0x5EFC480A879528B8ULL, 0xBA092A7DEC236D45ULL, 
            0x06BB428154FEC504ULL, 0xD0021A5B95880BA4ULL, 0xB77827F6F7F9D56CULL, 0x95C083D524873B97ULL
        },
        {
            0x266A044234FD7BA7ULL, 0x87F49DE9486291E4ULL, 0x133248FF3D6EB4C1ULL, 0x5EBB6A66A13D06F9ULL, 
            0xDA60A1A53B11AF33ULL, 0x44481F4A9C815270ULL, 0x211A0BF2EE8E94ACULL, 0x4FC38135A806BE3AULL, 
            0xE617DA08B13E301AULL, 0xA222CD6E9B8D8DE5ULL, 0xBC957CBEB306453CULL, 0x826053E0F6952D94ULL, 
            0xC216BBE49734E299ULL, 0x3B4BE2EAAFEE2385ULL, 0x30254DABA326E796ULL, 0x302505EC36813E40ULL, 
            0xA2EEA6126BC1520EULL, 0xECDF1C134D793BC6ULL, 0x203F4D2E11DB00A0ULL, 0x45331C223D188B38ULL, 
            0x28857FCF9A17C4DEULL, 0xAB66D26982702EB7ULL, 0xE3FDB3B7AA980FB3ULL, 0xDFA615EFE89161D0ULL, 
            0x038378CF83615D53ULL, 0x0685876A08864505ULL, 0xA0E9868A4B0D809CULL, 0x655FE009A6BE4C6AULL, 
            0x302EF639CB6B9384ULL, 0x4061B7D1C4E4E1A7ULL, 0x9976C7C6129AC66EULL, 0x749EE3B917B63792ULL
        },
        {
            0xE9B8F7870CF12157ULL, 0x2E6C530402C203CFULL, 0xF4E5EA298AD9F0D5ULL, 0x5096363C023AC228ULL, 
            0x20A75869C91CC930ULL, 0x5AD8666C1E94A104ULL, 0x6F8DC9977938DFFDULL, 0x4BDB3F9FEAD5116CULL, 
            0x25AE3A44493A6578ULL, 0x9F676B9198A4AE3CULL, 0xF7E83309E5CECD4DULL, 0xB01F2C55EE0786BDULL, 
            0x52DC9BF8E13293F4ULL, 0x7FAAB66A6C571264ULL, 0x9F10C8367CDD5A2BULL, 0xCDD3ECAF87EAE702ULL, 
            0x5EE8432320C24B4AULL, 0xF8F326D7A6139DE2ULL, 0xDED85AA57A029FFDULL, 0x5993FC7B73F44A6CULL, 
            0xF8A411C72F8075EEULL, 0x4828B214AE17154AULL, 0xA28F305A9459A115ULL, 0x10C4375A7A4F4791ULL, 
            0xD4941298F1174F8AULL, 0xA27ADECDC9719F3DULL, 0x7336454349472ED0ULL, 0x98AC3761A7AD9C46ULL, 
            0x1274CF82442E9EB2ULL, 0x62913719558314B6ULL, 0xBB8D0D2FE2E14FD4ULL, 0x4A37ED17EDAC81BDULL
        }
    },
    {
        {
            0x8D126781BCECDA27ULL, 0xBCEF5FB2CE3F1420ULL, 0xDF5A590E2725418CULL, 0x2E4C7D08A01885FDULL, 
            0x631C048216C860F8ULL, 0x489569C9A1B7CD89ULL, 0x0CA0A23297A21CA8ULL, 0x544E67E057251158ULL, 
            0xA07F8CFD268DBAD5ULL, 0x0542CB681F89E410ULL, 0x429B202CBF92A8DBULL, 0xF7E78F69AEEDA266ULL, 
            0xCA15463922618A7AULL, 0xBE5B2AE209B77718ULL, 0xB00311A8C93D3508ULL, 0xD2555EB83919B0ABULL, 
            0x0963682B62C0E99AULL, 0x109F2871B5A4972FULL, 0xC4E879F2934DB71BULL, 0xF852637AB8E0A5DCULL, 
            0xAF8B6C524FB92106ULL, 0x6ACA8965FDBB652FULL, 0x06ECDCDB8ADD8545ULL, 0x6C32AF7F45372259ULL, 
            0x08955E681F544632ULL, 0xF7E283359BA17721ULL, 0x75D683953136C7ECULL, 0x064A09000F3FCFA0ULL, 
            0x7C1312CD2DB37CB9ULL, 0xC6857857418033A4ULL, 0xFB0A533333A0461BULL, 0x18CC282635EA3356ULL
        },
        {
            0x1FBBBDE43F6E31BDULL, 0x48F825984C6265E6ULL, 0x83E706A7F8E68E5DULL, 0xF26B32B0693F29EFULL, 
            0x4EDC1E141353632AULL, 0x4356F2A30F8A7B3DULL, 0x5D9B5CF7A05833DCULL, 0x5F9FBF57494341A4ULL, 
            0x8FB4D8CB277AB94DULL, 0x766B083624357F37ULL, 0x650EC9B0086AD166ULL, 0x0F9861BFB0B0724BULL, 
            0xA3A02BA5CF2B109BULL, 0xC577619CF350BB7DULL, 0xB0AC793FED5FD82CULL, 0x5EC9DCE7D97BC63CULL, 
            0xDF16203445398F6AULL, 0x2F3486DF3B1FA2D3ULL, 0xD1ACAC9887D0FFFCULL, 0xD95665DF18DB2E9DULL, 
            0x9128724AD16D2F3EULL, 0xBE847BB809C4AA53ULL, 0xC49D4D5956FE9DD7ULL, 0xE9D4D77E1934E2E1ULL, 
            0x598F53FAC10CAC5BULL, 0xC7B24BF134C31856ULL, 0x06A80F284E4467DCULL, 0xA84373629E296DDEULL, 
            0x8B5CAC97B0174BDBULL, 0xB85C745E4D162E66ULL, 0x5D5E302C6C07C89CULL, 0x1B73A6EDE7D1972FULL
        },
        {
            0x013DC326A5B8683AULL, 0xDA56EA7A8E0F0F84ULL, 0x633935241E307A63ULL, 0xC583446AD6C581E3ULL, 
            0x9F48E7CFD6A1C494ULL, 0x6C630E49C9E85E04ULL, 0x11AD6843430E0E6DULL, 0x24819DA211A62777ULL, 
            0x8372343D417CFBA4ULL, 0xF28D66C023E8D7D4ULL, 0xD404BF0902F7F1CCULL, 0xB9172C24DCF0E2FCULL, 
            0x1AA73745E3A39CFAULL, 0x938F37AEDF191024ULL, 0x10F8B04B11FE3A78ULL, 0xF2761FE1C9B4EA0EULL, 
            0x871A6234B6A0DA79ULL, 0x2341DC951B49DE0DULL, 0xA9C14DCA03248463ULL, 0x6C3BC34DAFD67310ULL, 
            0xF344889106240B31ULL, 0xC7016F28A2BB3DEAULL, 0xBA2302B1D7AEAE7EULL, 0x2D71307BF516ABCDULL, 
            0xED8075EFEFDC5D99ULL, 0x4E5CE0F0AB6AD8FCULL, 0xAFC73F7538844099ULL, 0x6C7A4E16FE13573BULL, 
            0x4F08521D9F3E39C7ULL, 0xAEE9E19604D0E1BDULL, 0x5544B0F2FB6F7FCAULL, 0x461D9632F197ACD3ULL
        },
        {
            0x7A7E56CD3C709919ULL, 0xFC675F412C930426ULL, 0x913DB227F54C3620ULL, 0xC62A3982BC5450A2ULL, 
            0xE3A9959D1830C48CULL, 0x287ACC10303BD169ULL, 0x69402A9BE5B71934ULL, 0xEDD103EB442D3B47ULL, 
            0xD0ACDCF54115E85BULL, 0xEBD0D449828B8BE4ULL, 0x988E3F2B961907C7ULL, 0x8FA840D8591C21FBULL, 
            0x3FFA8726451B43F0ULL, 0xCC93765D9629CEC4ULL, 0x8DB57B8540C3ED86ULL, 0x23D09C02E294835DULL, 
            0x0819C092D5F93C9FULL, 0x44CC77BAFD503A31ULL, 0xAEBBAA5C567C742FULL, 0x5D29BFCBA89DBDFDULL, 
            0x3EB20BFF0EB692FAULL, 0x4B6F7B029325D8AEULL, 0xF0B19156CBBE935BULL, 0xAD20821BEE58D905ULL, 
            0xD22F40F4819AFAD2ULL, 0x0BD8F3930FD3C4CDULL, 0xFEA08B1DA098BAB7ULL, 0x5FD46438F4EF6C05ULL, 
            0x5D3FA48462015D38ULL, 0x2E178A3D561680F8ULL, 0x05BD954FDA54BC3CULL, 0x3FDB6195FCD785BDULL
        },
        {
            0x4CFEC5C3157CF035ULL, 0xAD1114C9AABBE541ULL, 0xD402BB1D5509E4FBULL, 0xEC15FF13A0C2E172ULL, 
            0x16D76CCA04503D8BULL, 0x1A74A1FF16BEE7FBULL, 0x14232C7E385D8CDFULL, 0xDF2DF483C8A43E93ULL, 
            0xC459FB903A3EED52ULL, 0x0123348AF41BDCD9ULL, 0xCDFA97710349D7A3ULL, 0xA70D2AC35B9150A9ULL, 
            0xF1C5DCAD7CDDAD1AULL, 0x6D23C2FAEE91EB83ULL, 0xEBF87948A65F7B3AULL, 0xD82B6CF7AD6A99ECULL, 
            0xF7176DC980F57716ULL, 0x56A75C5BB38A87FCULL, 0xF2DDE08D91D7C8DFULL, 0xD807FBEC91D687CEULL, 
            0x9E80ECF577F6B980ULL, 0xE73C112F88EE1C3CULL, 0xA4963204769C45B8ULL, 0x01CF1B84127EA0A7ULL, 
            0xFF904D58969B1F95ULL, 0x62FFCD480FB4A3F6ULL, 0xE9DD4F62CED9AD22ULL, 0x427838AA6C058C89ULL, 
            0xE61F3CA3AF53E7F0ULL, 0xD74450838299C0F3ULL, 0x8891B595D007635BULL, 0x7BA20FDA8A622FE0ULL
        },
        {
            0x17658C8C6174B4BDULL, 0x456ED027BFB23962ULL, 0x19A55B4714650750ULL, 0x18150D23F15BF75AULL, 
            0x6383F74C0B2AE132ULL, 0x48801F4B446103CBULL, 0xD68ED8E118C10889ULL, 0xDBCFA11D1CBF456CULL, 
            0x04A9A75B2799A5B0ULL, 0x39F8BB3AB25FD35BULL, 0x8661A08E607B1B8EULL, 0x39C8F338D5325D0FULL, 
            0xAC1D3F24FE3B712FULL, 0xD1889D628F1E3CA9ULL, 0x2C2969D3E627E2DEULL, 0x141FC73D6B3474C6ULL, 
            0xD93E6B8FB33A74D5ULL, 0x6389660B0B4AC385ULL, 0x64317ADDC7CD6CD5ULL, 0x637CC27787B3D10CULL, 
            0xA1F9CF5C7CC359C0ULL, 0x49BE5F50AD6CCA8AULL, 0x77F367DC690226A6ULL, 0xF7F9487C650B1774ULL, 
            0xE28FCB73F527DA3CULL, 0xBE759B0E22CBBEE2ULL, 0xA04835EEEF979AE3ULL, 0x306C80C313D9227DULL, 
            0xD233778A102A39DEULL, 0xECDC71B18536FE11ULL, 0x766BE5753F44F13BULL, 0xCB079C4D281BC64FULL
        }
    },
    {
        {
            0xBC6CDE809E93F120ULL, 0x75EDA059D54A1B98ULL, 0xCF28432E217CF8B5ULL, 0x4FC0089FC70CCD73ULL, 
            0xA2481068438833E4ULL, 0xF1A76688B977E30CULL, 0x82971F0A785DC32EULL, 0x8C4AFDE9103C8E3BULL, 
            0x8BAAF06DF6538B15ULL, 0xD04C05DAAF78FD6FULL, 0x252EA2A2E5B8022BULL, 0x2971B75831D37238ULL, 
            0x0C4DDEE62ECE7780ULL, 0x30075897891B1072ULL, 0x508B7CA326DA12C4ULL, 0x88C3D71CE998F7A4ULL, 
            0xC9A13F30CB8A877DULL, 0x9A07F3F18A453211ULL, 0x6B63B86D5B621FF1ULL, 0x04847A0F8557750FULL, 
            0xF274D6EF2057B316ULL, 0xE8DC11FE2BA9C23BULL, 0xA87009D3B3C830BDULL, 0x218399E81E48AE51ULL, 
            0x84C88AC57121F830ULL, 0xDC7ADEF51BF957C1ULL, 0xCF00BE0F3F0E6105ULL, 0xC4BA76AA2836FF5AULL, 
            0x86C1BC4324FBFA33ULL, 0x9C7872E04CA312F6ULL, 0x739FA4A577CC196EULL, 0x652D7856A37FA5CFULL
        },
        {
            0x4B64D77802278B7AULL, 0x6DD9212F6F7290F4ULL, 0xE8E8C67CCF2A78B1ULL, 0x4E7EE8F9802B6C0FULL, 
            0xD6613C7884782CDCULL, 0xEFD1F2E644BBE2EDULL, 0x99237297EEEB4834ULL, 0xFDC7AED20053B8E2ULL, 
            0x87409EF816943DCCULL, 0x0083E41608DA7DE5ULL, 0x08865F26044232D2ULL, 0x4EFA41972FCCD901ULL, 
            0x6D5CDEC2E1D9DA88ULL, 0xEC85520176B40F44ULL, 0x42BFC72C586B4029ULL, 0xEB30FB2EC6363BB1ULL, 
            0x7D6B7DD40D34492FULL, 0x4BB527B8C966ADD2ULL, 0x706967E5768B9C37ULL, 0x3D8BC6F52596AA2BULL, 
            0x3D88C9FC82A53793ULL, 0xEA51A116100AB486ULL, 0xED6F7B3C62226457ULL, 0x4DECCB2109206EF4ULL, 
            0xA3B5AF6CA01EDFB8ULL, 0x3BCD72A955005A21ULL, 0xEC0EF4F1C7B9D2F8ULL, 0x9BB14EB6EB1525B7ULL, 
            0xD2CAB1184D17A045ULL, 0x6977F516FADC4223ULL, 0xF9658053C2B3E8D0ULL, 0x600842BBBF94A6AEULL
        },
        {
            0x78DBA4F24231D8F6ULL, 0xEA1FF68F59D16290ULL, 0xBD75694A6D6B2282ULL, 0xA4FE0659D28F6AD1ULL, 
            0xB3943F683A77EB92ULL, 0x346917F48A9D5B96ULL, 0x40765E0DF293D75DULL, 0xB7C6EC1DF3F72F9BULL, 
            0x44EB04F481D79232ULL, 0x3F8F1230CA2539F8ULL, 0x95EB02B6C668E1BEULL, 0x3B5077F983CB444BULL, 
            0x39290851E8E4A5C4ULL, 0x615DA1E0B75B2C56ULL, 0xB68F0E44FB849EB8ULL, 0xD64227712BDA83FDULL, 
            0x2183DE557B58A2F8ULL, 0xD37206E21937469DULL, 0xC7CE956DCBF2EFC2ULL, 0x310B25A0430EF4C5ULL, 
            0x48626A6655B1775DULL, 0x54AF5A3D9FCEE1F6ULL, 0xC7D968C323215A77ULL, 0x643CCA2063B708AAULL, 
            0xA3BA182870A19424ULL, 0xA90E25E94783A6F1ULL, 0xA80ADA4EE5D8C97EULL, 0xC92BC5E80BC0CDC4ULL, 
            0x1B3C3521957E0146ULL, 0x13BDAA78EE1F0F6FULL, 0x29F87C475160E6D7ULL, 0xE5C64E4700180E40ULL
        },
        {
            0xFAC3B9BCC3B48A15ULL, 0x5FA1C6BCE6A9C4BFULL, 0x878D32BC289AA5F8ULL, 0x2B7AB9098540D7FAULL, 
            0x104EAE449DDB0690ULL, 0xB5AF2096D26B565BULL, 0xCB3B6352BA68A05CULL, 0xB003A195E80AACAEULL, 
            0x206E667A5740660AULL, 0xC282237E3E6E6D5AULL, 0xEA477098A9907B61ULL, 0xA5645EECB2309F93ULL, 
            0xA5728B27523B9AC1ULL, 0x0CF01D7DA0424BB2ULL, 0xFC0023C36F9F16CCULL, 0x9F125C2C3CF75CD2ULL, 
            0x69BFA24D0D1C065CULL, 0x1FE59F26604A357FULL, 0xAD70AB8BC50FF932ULL, 0x7D0DA62146DB675EULL, 
            0xEC93035E2915A25FULL, 0xB7C43CC817EEAC5CULL, 0xB05E036FC8ACE2D8ULL, 0x058631AD31E0400FULL, 
            0xB9CD6B97FC1ED488ULL, 0x9CCF18662ACE77AAULL, 0x936BF2ED7F04754EULL, 0x745E2FF71160B394ULL, 
            0x762FB7274A9BC712ULL, 0x734354B776B6173DULL, 0x3A7102075B80C358ULL, 0x1CEA6EA155DAA216ULL
        },
        {
            0xC3F31E2673751923ULL, 0x52B3248BE908CC55ULL, 0x9E0330574F06F822ULL, 0xA9EE9CD91A0AA2C7ULL, 
            0x7FA72DF087B4F983ULL, 0x7694D71D995BF166ULL, 0xB0F4F8A7F59B4516ULL, 0xEE603AEFEB185492ULL, 
            0x8B4FE1B930EB2712ULL, 0x6D5AF0CAC51A8A6EULL, 0x40529C3C4F145738ULL, 0xA8D238F9E5B0EB2AULL, 
            0xE12CE5ACA4077009ULL, 0xAC8B3194B374F816ULL, 0x61265644DEBB3841ULL, 0x2BA51DE1534AC852ULL, 
            0x772D8BCE94F8EC5DULL, 0x61F33ECB383C6C41ULL, 0x77075F5A496DF9B9ULL, 0x0A8350F2E9F2CC01ULL, 
            0x7E41F63729E90C41ULL, 0x1A8D1EC804F25277ULL, 0x675C676F080E1E8FULL, 0xC36D14514425C1CDULL, 
            0xCAF2728AFBF670E0ULL, 0xFEDED852843EC628ULL, 0xC302CF189048DFDBULL, 0x6D5A50BBF9842081ULL, 
            0x5C24F7D7EC65673CULL, 0x6AE0814446EC3B4CULL, 0xD74AB98D58CF342AULL, 0x47075EE168B5D2CEULL
        },
        {
            0x6D201918686FFEB4ULL, 0x3214D63DB0192539ULL, 0x87B6683B72F0EC3EULL, 0xCCE8CE4F19379CDDULL, 
            0xF5FFB463CCCC6117ULL, 0x63CA69C91D5669C6ULL, 0xA3476F14AA286CBFULL, 0xDC2AE694E13FA87DULL, 
            0x089EE5C989A8C129ULL, 0x175A8604FF881599ULL, 0xD26787DC6133002FULL, 0xE72BB0D3A559CA78ULL, 
            0x7A24A075DE336824ULL, 0x3F965F3644FC8FC9ULL, 0x4AB90CDA5B331F28ULL, 0xEECCDC6A60D7D0F2ULL, 
            0xC18F92D7FE9EF1F0ULL, 0xBA823DD7A67F8526ULL, 0x024DDB9E41A28577ULL, 0x38D58240C3C37B18ULL, 
            0xD232238AE9BE14BFULL, 0xD55AB64724733C55ULL, 0xF87975CAC1824EA0ULL, 0xCE4FBCC3ECE622ABULL, 
            0x8BC66FCFF2ABF687ULL, 0x46E96285038FA447ULL, 0xD72401A05F43BB30ULL, 0x9B4DC9BBC6B47D80ULL, 
            0xD5606D0B6B7E9713ULL, 0xE8620277CF402895ULL, 0xA4231DE2F971BD0AULL, 0x76D7B392C4FB7691ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseDConstants = {
    0xA402FA86BA8D0A71ULL,
    0x538F1EBF60BACB76ULL,
    0x0B6D0CEFC8E9D9ABULL,
    0xA402FA86BA8D0A71ULL,
    0x538F1EBF60BACB76ULL,
    0x0B6D0CEFC8E9D9ABULL,
    0x668755156A0BF6E1ULL,
    0xAB80EF88A13A7C8CULL,
    0xF9,
    0xD7,
    0x57,
    0x4B,
    0xEB,
    0x6E,
    0x13,
    0x95
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseESalts = {
    {
        {
            0x6228345B25EF3C74ULL, 0x038A9A14F43F4BDBULL, 0x245911DF4652F023ULL, 0x05C902E53424EA1AULL, 
            0x1C75141839E52839ULL, 0x0C11A66D455E74ACULL, 0xEFF4984B15024F40ULL, 0x6802C7372802B617ULL, 
            0xF26F5ECD446B9519ULL, 0xFF97A056BC175F0DULL, 0xA096AE5EB432B728ULL, 0x7C49681A2CF6D0E4ULL, 
            0x90EEA862626A7DC5ULL, 0x47878E56AE4DC7F2ULL, 0xDB20C3700D118205ULL, 0xB1E5958A3F35B53FULL, 
            0x174E928A79AD24FCULL, 0x160926D631499638ULL, 0xD36DFB4015BC2147ULL, 0x19B3078F84DFFD52ULL, 
            0x2BB092E23B8C76F8ULL, 0xBB76226183CA7CECULL, 0x8A119A68BDFAB0EDULL, 0x16FC31F75398A865ULL, 
            0xF05D873A6D0B12A4ULL, 0xC4765E01DA532D73ULL, 0x76E0C58521A7362AULL, 0x75A1829B5CE4A2E2ULL, 
            0xA35272ACB2DF797BULL, 0xD6032D1811E8B008ULL, 0x93817CFF9A53E965ULL, 0x9D8B62E8E4E795D7ULL
        },
        {
            0xBEEC4AB1E2BB6488ULL, 0x9FAFEF836885E3C7ULL, 0x76611AB930A11AABULL, 0x8FCB391E454DEC7EULL, 
            0x3388A03166FBE06EULL, 0x753B19A498643A04ULL, 0xFEE44D7FA9F6F72DULL, 0x3B324F19F27BA1F3ULL, 
            0xC73E87996B76793AULL, 0x0768FF8F21F11232ULL, 0xE2E5D2CADBE6567EULL, 0xEDD397F0669B7E99ULL, 
            0x9CCC5BD3FBDF0CC9ULL, 0x020D67CD428AF517ULL, 0x4CF259F53E1A0CB3ULL, 0x2916705984050CA5ULL, 
            0xC7BC22C5E2CF5FF7ULL, 0xAB77C6E06B61ECFBULL, 0xC98690C83795112AULL, 0x4D02285D14D8B3F4ULL, 
            0x00ABA45ABBE582E5ULL, 0xCFC04CAAE73221E3ULL, 0x288445E054950FBFULL, 0x7BE903A4BC6997E3ULL, 
            0xE0B55FBEA544F083ULL, 0xD3A14B32CE0D9192ULL, 0x328BCE7C76C29EC9ULL, 0x55E1D263BE11CF36ULL, 
            0xDD547BFD810B0541ULL, 0x0DFF95BB24B9D171ULL, 0xAB38890B8481EC75ULL, 0x39ED9D4BF289FE4BULL
        },
        {
            0x25D7111FE0A96D8EULL, 0xF6FA833A5A24361EULL, 0x88159DC06EC1FB87ULL, 0x00C95382FD17A4F5ULL, 
            0xA098BC9C565FA620ULL, 0xD7628B7553C48484ULL, 0x7AB8541DC2707581ULL, 0xBFA63BFA0F040BA9ULL, 
            0xAE7A1E8F4C8D635FULL, 0xD4A7FF60D04AB60EULL, 0x7FD540037426E7E0ULL, 0xF6078FB223CC9772ULL, 
            0x98BE34FB24AD1288ULL, 0xC8BD15A7E1CAC543ULL, 0x8E11580A6CFF7FB7ULL, 0xB571A51DBBBCA436ULL, 
            0xD253A41C63BBCACBULL, 0xD6FF02AC1B4E50EDULL, 0x010DD49096FCAEF6ULL, 0xAC6B9F95020B5FE8ULL, 
            0x161DFD237F55A3A4ULL, 0x2588AB55CED904D6ULL, 0xE9207D83ECA0D1E7ULL, 0x2D59AA6A2BB7C473ULL, 
            0x6AAD26DCDC797B03ULL, 0x4E290E749F5B0BF0ULL, 0x3E455B1136860B9FULL, 0xF062B90720931772ULL, 
            0xE0264CA0B0D588B4ULL, 0x2603D8B3D9D38F36ULL, 0xC35A12C46112AF58ULL, 0xE1F7E363913E05C5ULL
        },
        {
            0x94064550BF844445ULL, 0x90CE6034B3208567ULL, 0x55C762A0252B4113ULL, 0x88919D5DE9F96671ULL, 
            0x762315C93E8BE8D0ULL, 0xD626376A45136D3FULL, 0xCE95894D8D97C241ULL, 0xEBACACEA8341C3A2ULL, 
            0x2CC09BA713C997A4ULL, 0x0FB76973F7180545ULL, 0x336F5ABF04537AA6ULL, 0xD62DF20834343FA1ULL, 
            0x61365C3A6E95F2AFULL, 0x5B9530C214008596ULL, 0x30936F627DA65B7FULL, 0xC6944B37973E4B61ULL, 
            0xE94459A42D884C04ULL, 0x50C60EF93EBAFEFDULL, 0x7CD77733C1CAA846ULL, 0x42F81196154D8A9CULL, 
            0xBD3CF40ECD3EE4D5ULL, 0x5F56AF85A31A9C26ULL, 0xE70933343E227490ULL, 0x5256719687EE21D8ULL, 
            0x8E4E7C76EFD4A216ULL, 0xBC1A9ECA52D4443DULL, 0x4EBA47E7036B2A51ULL, 0x044F28FC8A228F41ULL, 
            0x44B4EA78DFEF5370ULL, 0x2912905A9A4E835FULL, 0xB549A82B5EEF54C3ULL, 0x452DBDC185896471ULL
        },
        {
            0xE6311A7B1574BE72ULL, 0x04A809AB1C8496EBULL, 0x35446FF61C41762AULL, 0x76C517F7261C5A69ULL, 
            0x227FF336E666670EULL, 0x54AF855338B0992BULL, 0xA82FE5D9B647ECECULL, 0x21B25612BBA48DAAULL, 
            0xD5C1DC7A704AB360ULL, 0xAF48DE22D8655DFAULL, 0x169A9567D008BA4EULL, 0x0DAB72C80572657EULL, 
            0xF36B1E112F92FE22ULL, 0xCA72CDBCDCD55946ULL, 0xD1DE9542402BBED7ULL, 0x304FCF7317423C01ULL, 
            0x72B2B56B0C646855ULL, 0x808CC306E835C70CULL, 0xCB950F3F6AD9951DULL, 0x85EF043E60F8EF90ULL, 
            0xB7C442C57BE7AA28ULL, 0x5DB0395E0F7AEC80ULL, 0x3A867AFEEEFE9633ULL, 0x84EE71899B7B7AE7ULL, 
            0xB437ADFA41C981A9ULL, 0xA21C231211EC114AULL, 0xB3A9F21DD6050E5DULL, 0xEB0E93725CDCACA5ULL, 
            0x9C8DA905ABED2337ULL, 0x486B71F5B5503E0DULL, 0x792A96A6D4DEB0A5ULL, 0xFED085D5D44D3296ULL
        },
        {
            0x16425D5EC7427EC7ULL, 0x591B36BE027F521AULL, 0x27772C15F1935511ULL, 0xDA1983773BDAAF92ULL, 
            0xEFA54A16D79048BEULL, 0x51CD3CBC07C64884ULL, 0xA57F143B8DE7870DULL, 0x1CDFDEA1CDB1EF39ULL, 
            0x3821A03E475591BCULL, 0xF134C7618A56E3B4ULL, 0xF816E6A55F61A719ULL, 0xB81ED0E0CB4DC9BAULL, 
            0xEAEAEC70B5176A88ULL, 0x12D370C1217527AEULL, 0xB3CF196A3B36187CULL, 0xF00CB166C9025CA8ULL, 
            0xED05CFA41E1EE852ULL, 0xCFEAD2D6B1B01B7BULL, 0x1FE8FD1526FC1947ULL, 0xB1FD1B72590A19D0ULL, 
            0xFDD019DFBCB6CE25ULL, 0xE39B5DE64F004785ULL, 0x81EACBB5FE4A3EB0ULL, 0x5B4F69F9745AAF1CULL, 
            0x3D287345110A6416ULL, 0x38C196AB1DDE3D56ULL, 0x160091ABF31FAEC3ULL, 0xCE03AEA02D68E126ULL, 
            0x2F442B0F73ED9308ULL, 0xF70C6623187B0DFCULL, 0x40D553607CFF14F7ULL, 0xA3135A15EAAA8FACULL
        }
    },
    {
        {
            0xE27BAF42DADE54ADULL, 0x008BC66DE371ED93ULL, 0x97172E525DCEBD84ULL, 0x1FBE07029F8419A1ULL, 
            0x1D277959163B0409ULL, 0x01B080AD3D6131ACULL, 0xAE9846DF7F0DB68DULL, 0x29AEBAC24DDB25E7ULL, 
            0xCEDF28E2B07DEE7CULL, 0xBD11B641B39C3767ULL, 0xB811CAF1134B4475ULL, 0x70CBCE22BD3EAB7BULL, 
            0x499200240F15EF98ULL, 0x19A27C7207F5E925ULL, 0xE123A3A173DBDCD4ULL, 0x54B1CB6FCB18DDAAULL, 
            0x2B4ACA620EFE9927ULL, 0x4216EBB623A316B4ULL, 0xA9F2F60A9440A215ULL, 0xE48F365C8BD6FBEFULL, 
            0x9642957E4EBCBD77ULL, 0x83441970E68D8E7EULL, 0xE4387B748A423B81ULL, 0x3F3C3614A110E81DULL, 
            0xEFBC87EC4F632814ULL, 0xDCE812B5B451CFB3ULL, 0xF0C59CA91C2B93C1ULL, 0x902B5C55EF7854CFULL, 
            0x54C44C9B8AD03F91ULL, 0xE0538B4BDF1003CDULL, 0x0CC81790CDAA8105ULL, 0x00F25F08A7CC86C5ULL
        },
        {
            0x005F81E08D785B62ULL, 0xDB8B0BC020415AFDULL, 0x8C8685C2752B86B4ULL, 0x4F4A5EDAD419B04CULL, 
            0x6522E1CC3832DACEULL, 0xE4469AEDDDECB75EULL, 0xB435563D6CD3E655ULL, 0x073F4B73B7E47CA0ULL, 
            0xFEBDB91A2EA494A0ULL, 0xB1CCE023F1E1D15FULL, 0x92F51C679E94169CULL, 0x63AD1052C4566561ULL, 
            0xFA60965F83291292ULL, 0xBA62B8A0DD379617ULL, 0x3FBE3DF736EC8F8FULL, 0xF21CB1251140FAD8ULL, 
            0xDE72C9264A3EE35FULL, 0x9B8F96093B0CC052ULL, 0x0C90CBAF10F4CDBAULL, 0x8FD95DDBD794807BULL, 
            0xB76F3D5CB80481B2ULL, 0xA0776117CEDE2393ULL, 0xE6469E9B19886ED6ULL, 0xEBBBAB1C69230F34ULL, 
            0x1640C662BFD7D1AFULL, 0x2A5AC5D781A09191ULL, 0x563FD311EDFD0E49ULL, 0xD346E17CAAB15A27ULL, 
            0xB73844E74BA502F7ULL, 0xE0D3D39E2FEFB0F2ULL, 0x889A07ECD46E1752ULL, 0x3CBE37905F0938B1ULL
        },
        {
            0xBCDBB5790152130FULL, 0x210FE95D47BD2AFDULL, 0x4FABDED91F685DC6ULL, 0x9CA7640C0C0AC6D2ULL, 
            0x217ADB30EA4C8A68ULL, 0xBB69D6771F74B0BAULL, 0x3BBE6250DD229B7DULL, 0x687EE008596B4D4EULL, 
            0xDAA05C51C6476F89ULL, 0x1C6276C3F6A45C0AULL, 0x94A6FDE594FB19B9ULL, 0xCE4962C4D5A32D5BULL, 
            0xBF267F9ED8172137ULL, 0x961BB1A47307E853ULL, 0x525DCBBA69EF1814ULL, 0xC55B667E60D35D38ULL, 
            0xAE96316915F3C0CEULL, 0xF698316B88DF7ECAULL, 0x0F60613A58193DA2ULL, 0x8DED09320FBA048DULL, 
            0x9A73A32DB79DDD73ULL, 0xA1366DEC9D247FBEULL, 0x81FCEDD7B2747D40ULL, 0x55E373C6ECD61BC4ULL, 
            0x9E12C4A39D267170ULL, 0x36A26F6CD795029DULL, 0x91CBC1A3B4750187ULL, 0xFD2C2FE4E47EC278ULL, 
            0x957EDED2273C6286ULL, 0x1FBDAAC4E9030819ULL, 0x37B8924194788CFCULL, 0x57F948D0AE3A8B5AULL
        },
        {
            0xC6D80DEB3C52F19BULL, 0xFF11F4D56696C066ULL, 0xF556AFF972095801ULL, 0xE78AE0FC64D715EEULL, 
            0xDBCFE7FBC72FD2CEULL, 0xE8FFC6E4FA33A878ULL, 0x74CD63C8FA996B46ULL, 0x9243B5B25AABDF87ULL, 
            0x28E82948F9E41CD6ULL, 0xA9BD8296AE89B142ULL, 0xD120ED37D648628CULL, 0xC43D81331A85D75CULL, 
            0xDD69283DA73BFA48ULL, 0xD17B948DDB3394C0ULL, 0x0388C0B9D6E84F13ULL, 0x5F57DB3B2EC00AAEULL, 
            0xD1BCA22620D375B9ULL, 0xE3EB32A467DF44DDULL, 0xEC6B5C2C3CADB57EULL, 0xADDBDC5CE2C2546CULL, 
            0x2BB8334DF56D3FAFULL, 0x37AC4CEBFB83B5A8ULL, 0xE8A7DE85B0B96DD1ULL, 0x64FBC2A3D8B1EC2CULL, 
            0xB6FB469AE5B3C16DULL, 0xBD53D7CA2505A4D0ULL, 0x5A8DF8AC95A7561AULL, 0x34B85FE89AF02F81ULL, 
            0xB6070857FA8D2D55ULL, 0xFE761478FB609EEAULL, 0x7C0C408517D0A4D6ULL, 0xC42EF684BE1AFA73ULL
        },
        {
            0x0278F3E8BD4A7B11ULL, 0xE67668E51A40AC6FULL, 0xA821E8CB96EA46D3ULL, 0xD6F1460E79705BEFULL, 
            0x84E574F21BB90AE8ULL, 0xCFA20B9D2A30E164ULL, 0x3BD3AF19CE04D6C1ULL, 0xA5F09D67B566EF4BULL, 
            0x7727DD05CFC7EECDULL, 0x0C63965BA25C1425ULL, 0x244D9CAE6D2F4107ULL, 0x5931A85EAD292D13ULL, 
            0x7A13CFEDFDBAB52EULL, 0x8414F947894F6725ULL, 0x26C126DECECB01CBULL, 0x8D4E37FC84901298ULL, 
            0x6767CC9BBD57ED29ULL, 0x95722D48E3A5FF80ULL, 0x88A2F8ACBD710F0BULL, 0x76EB1E0888AF85ABULL, 
            0xF064744550CBE73AULL, 0xD5F50227D72A8226ULL, 0x53138CAFC6518512ULL, 0x45D302C09C74CD7BULL, 
            0xC7A69C7BEE7A8FA3ULL, 0xAFB319AF6D93C13CULL, 0x69F9E3B10F726C28ULL, 0x878F7590E96BE95CULL, 
            0xCEF6BA9584D6D25DULL, 0x406520B8B7D81DFAULL, 0x30EA61A63CBC3C5CULL, 0x32B1D0EE76A0FFCAULL
        },
        {
            0x3C4540EB45D3F4DFULL, 0x69C24276CA722687ULL, 0x0F7AB422D64A6665ULL, 0x10B87D24979617B6ULL, 
            0xBB345926BC84564BULL, 0x23F38CDCB33D4DBEULL, 0xE69D7DE0044EE4F8ULL, 0x37A12EFB3E4F5681ULL, 
            0x3EB4106B00706C05ULL, 0x9D2B8359C448E723ULL, 0x8E863608F03307D1ULL, 0x4958E500F9ECCA6FULL, 
            0x984CBB676F5443A1ULL, 0xBE7DFC95890B8E67ULL, 0x13DB2C4DA976E420ULL, 0x1937D782B2B84AF9ULL, 
            0x5CA2167884C67233ULL, 0xD3D03FDC4CF85514ULL, 0xF9292D68DB850BE3ULL, 0x9FD9E396F07D5EBBULL, 
            0x90F7ADB364F20A79ULL, 0x3C5A9119C1142432ULL, 0xCF1832F84CCE3AFCULL, 0x5916813462881C66ULL, 
            0xDE56BC79A9E0CB44ULL, 0xC9D757EC135060F4ULL, 0xB35E883687B46902ULL, 0xA47A0CD0BE76464EULL, 
            0x7FD0731BE4240055ULL, 0xB623D2A2A7F15283ULL, 0x90FFD69B83657D7CULL, 0x247707C9573B5777ULL
        }
    },
    {
        {
            0xEAF467AB624E61BEULL, 0x1B194D1B40CE5F33ULL, 0x8AD4687326ADFDAAULL, 0x63E2185EA5F3ADB8ULL, 
            0xAEA9EEFECA82F475ULL, 0x6E4BED52B8E6314FULL, 0x6F8553197B6B5345ULL, 0xCD2CDF9C4716121EULL, 
            0x16A17ADED6367909ULL, 0xF76227BB095BEB63ULL, 0xED3EE424CAC2F6D9ULL, 0x9B5DED035A8EC908ULL, 
            0x0BDE3BD72AE83E4BULL, 0x0300AD4F6A15E7B1ULL, 0x8BFC46B654085F50ULL, 0x19EB5AF03A89D0D1ULL, 
            0xF712DDEE2B1F8B87ULL, 0xDC36FA31F5429D5FULL, 0x4E38736B8A531AFCULL, 0xEDD446C5CCF9B2BCULL, 
            0x8E346D7E6DBD8888ULL, 0x777040FC7342ED4FULL, 0x3DB093532C938D9EULL, 0x3AE58FCE678DC3AAULL, 
            0xFDA677F45E6A1C3CULL, 0x5A54C1DD7E76FBF1ULL, 0x4051FFB7B261E40EULL, 0xEC434B3DEE34C786ULL, 
            0x1B52B751C92E77B9ULL, 0xEE64E797A1F607E0ULL, 0x79E9A406607A51A9ULL, 0x1AD973CD44C3CB55ULL
        },
        {
            0x2C8541AC00ED1236ULL, 0xBC4DC5C2BE64972BULL, 0x392D74F197927EA0ULL, 0x81FF7AEC38E7D407ULL, 
            0x58442D55387D9EDDULL, 0x048664975F9EF9B8ULL, 0x743A8736E03CF8F7ULL, 0x3E3BA8B3ABB283EBULL, 
            0x16D12D7AB43233D4ULL, 0x6E50FB53972C96D0ULL, 0x538F60677A0F654CULL, 0x3A4A9252E90548C7ULL, 
            0xAE82CED5CB538C32ULL, 0x37877591F26C0752ULL, 0xBD1674614BE72236ULL, 0x363472C0B272BB17ULL, 
            0xE316C0CCAC60881EULL, 0x68F3AC3FA94B2BF5ULL, 0x4B0E60EB1064A585ULL, 0xACDCAB66DB009508ULL, 
            0x48EB7CC7082662EEULL, 0xC2052C887495198BULL, 0x4EFF12ACBD02F491ULL, 0xD54A4BB5E3DF1DA6ULL, 
            0x1E22295AA564ACB4ULL, 0x7C1979DC3957D6E8ULL, 0x2FEC2615296B33E1ULL, 0xAE0A2F5492351508ULL, 
            0x0D2550EBD38BFF1FULL, 0x2D21000694CF175AULL, 0xC1DB008DC1903FACULL, 0x72460136976CC0A7ULL
        },
        {
            0xB2C87ACE172D49BFULL, 0x89FE96F9D8CA176FULL, 0x2C776007949A2DACULL, 0xD73E621608D970FEULL, 
            0x1E76DD12BEB98BB4ULL, 0x306571D62B22C048ULL, 0xEC48567E6672644AULL, 0xFC43CEDF8BAC060AULL, 
            0xFEE319F1C1EFDB9BULL, 0x301A44839259D3BAULL, 0x9BF03526D288162AULL, 0x30BF002571D2C7E5ULL, 
            0x8F46E6DA76B60112ULL, 0x69BC8B2EA5206D3EULL, 0x8D5BD337769C6EECULL, 0xED7F9223041479E2ULL, 
            0xC313CDEDAF6E01C7ULL, 0xD69BDEDE05BE0AADULL, 0x1C22416F1AFD83F6ULL, 0xA343AC7DD2DAB527ULL, 
            0xC71563A8438D633FULL, 0xBCC1AD4C63450856ULL, 0x0E330936B1D179C6ULL, 0x5E8650A47512B385ULL, 
            0x0836F7F33AC265F0ULL, 0xBF588ECA4E748BF4ULL, 0x3C3ED859D062F936ULL, 0x12BF5A02551261D7ULL, 
            0x7A10E2D1554B2501ULL, 0xCA6E58312E0CADD7ULL, 0xA9170094634C4757ULL, 0x2660B9CD304BED33ULL
        },
        {
            0x7E52787CB751CFA0ULL, 0x0EC296C53C014308ULL, 0xEB5DDAA49C1631D3ULL, 0x4D591BE4C3C4D5F0ULL, 
            0xD5542A75DD7436B3ULL, 0x88BEF0EC4846B392ULL, 0xCB46AB28C49C9C28ULL, 0xDF3106882348E388ULL, 
            0xB3528EE6B64E3BDDULL, 0xF6BAB55DF2A1EFA8ULL, 0x4CDDF2A97E8C317FULL, 0xA3AD4A9AC9A37DF8ULL, 
            0xD3178FBE13B46003ULL, 0x348A58C9F4152907ULL, 0x8FBF82A590504788ULL, 0x3289086F72666827ULL, 
            0xDDADECB7AB1013FEULL, 0xC6CC1F0401556EB7ULL, 0x72B1B2786A3F3F60ULL, 0x0D03B94F4A0B6EB3ULL, 
            0x662AAE936D473266ULL, 0x74720E5629C8825EULL, 0x67FA01C13C5707D7ULL, 0x142F52FCFC90E73FULL, 
            0xC3EB7BA9FF3737EFULL, 0xC1877303F6963F7AULL, 0x16068087EFBDB78FULL, 0xBF11F29683394B16ULL, 
            0x66E0C5D73D807C1DULL, 0x4CDD9C75CECAE77AULL, 0x65B8388CCD784CBAULL, 0x1171B6F42CA9B8DCULL
        },
        {
            0xB7820B144FF262AFULL, 0xDC1F120C4217578CULL, 0xD34A729E34DDE6B2ULL, 0x8FA2E36F57C8AD2CULL, 
            0x80F85B693C1F7F75ULL, 0xCE42E68FB4EFC58FULL, 0x45F989C52E729FBFULL, 0xEE54143F31233667ULL, 
            0xB376EF5FF43D2A5AULL, 0x9290D2892E98D628ULL, 0x69C856CAF2B646EAULL, 0x9B0D94CBDDF6B6FDULL, 
            0x4638C9263D126D70ULL, 0x9E426DCA5BE73C3DULL, 0x96712E3E709105E9ULL, 0x06CC697594FF9821ULL, 
            0x6BFD294A2E77C1BFULL, 0x90D4725477A3E12BULL, 0xE2069748F70B5FAEULL, 0xA363CE7B5BDDF8E1ULL, 
            0x89416B2747FD2E84ULL, 0x5D26EE65EB8A3213ULL, 0x8EB524CE1ADDE65FULL, 0xC15BFAF2CC2C00E9ULL, 
            0x11C35ECA3B61FC84ULL, 0x217302ECDCD8DDD5ULL, 0x1F38B1F6F6D7AD53ULL, 0xBA1F9AA39B03BF13ULL, 
            0xCD2A068AF2E0DED6ULL, 0x76F915EA19EF8F55ULL, 0x674255C8D075EBF7ULL, 0x3CC18E728A60BA75ULL
        },
        {
            0x117D3D77E7503943ULL, 0x6EAB16D842FC0D55ULL, 0x757D41427F02F50BULL, 0xDAFB21B810F0A0BAULL, 
            0x0924C298DAEC60E8ULL, 0xC97A73DAA4B1DD20ULL, 0xA27AF1CC19C68989ULL, 0x5A41178EB69E932DULL, 
            0x72199E5B4AA0AB89ULL, 0x53A9245961A39131ULL, 0xC0E940FC42E15C9FULL, 0x64FCEB932BFE105EULL, 
            0x25203AA7662424C0ULL, 0x5C0922A8012889F2ULL, 0x1CB3C5D02043A758ULL, 0x957E129E12978F28ULL, 
            0xA7E08B5DAF1B0218ULL, 0xE9E5740631E051F0ULL, 0xAD422C1F44181CC9ULL, 0xAA549D79DC8ECCF8ULL, 
            0x2E592085AD2229DFULL, 0x638C9AC958997105ULL, 0x8A18B28A708F004DULL, 0x2C78A916D7A0A113ULL, 
            0x98EC9E6D94881713ULL, 0x72637E6A16FE3B01ULL, 0x5480F6F88AA690ECULL, 0xE1066A205C4F8C53ULL, 
            0x5F8B64C446003A3EULL, 0x2E5A6EB2018818DCULL, 0x5F16AA38FFA827ACULL, 0xBA221E5F90AB9EBCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseEConstants = {
    0x226B48538C5008A8ULL,
    0x72494197EF52B02BULL,
    0xAFF0D40802FA5465ULL,
    0x226B48538C5008A8ULL,
    0x72494197EF52B02BULL,
    0xAFF0D40802FA5465ULL,
    0x0E45CB0B307D0AF6ULL,
    0x7DB4CAE6DF2993F4ULL,
    0xC0,
    0xD5,
    0x78,
    0x19,
    0xB6,
    0x0C,
    0x8D,
    0x53
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseFSalts = {
    {
        {
            0x945B2DD5113CD67BULL, 0x74A7087DB79A723EULL, 0x4550F3B9CCF2698BULL, 0xC5B19C47F190AAC1ULL, 
            0xB9D3C314ED54C2C3ULL, 0xAF4D7A602D7278ECULL, 0x1993E8679B89B950ULL, 0x0F8F3ED9BE2A7E7AULL, 
            0x89A9A56E4F4CC24CULL, 0x0A5AEBFE28C8D6BFULL, 0x82565110D194140AULL, 0xAA4CD953C75DC8B0ULL, 
            0xECC22500615A37BCULL, 0x93759CD905B10822ULL, 0xBBAF32EF4617A2B3ULL, 0x09B381E31A7B9927ULL, 
            0x530C1636DE79DA4EULL, 0xB4DEAEEE48E2810DULL, 0x02E59A45A73F2D34ULL, 0x8B72AB4CDCAF5700ULL, 
            0x900165D8AFE7173AULL, 0xD54E9DDB80E6D9B3ULL, 0x739E121CC0D3F5E4ULL, 0xDBF49B08907D97C8ULL, 
            0x28547B82D08F49FBULL, 0xE1BC5E5A762169FFULL, 0x1AED48EB0C130A71ULL, 0xC273B6715C5680C8ULL, 
            0xB9F190B509894BD4ULL, 0xDA937C1A2A188695ULL, 0x88DA1FAAF2205E38ULL, 0xC5389018A12E494EULL
        },
        {
            0xA48D2E7D3E8356D6ULL, 0xBBA9B4201E6FA408ULL, 0x2EFFEA0756DD8A83ULL, 0xAAC29DFFE27E71C7ULL, 
            0xCB2BE392F7FD285CULL, 0x5141EAE8F98FE8CDULL, 0x5E4C7DA88D19A9D0ULL, 0xBA73FB61586E1FE6ULL, 
            0xBE9D00A1D422CBE9ULL, 0xD1577ECC4BE8848DULL, 0xA4628BAC6E78F2C3ULL, 0x35A9D20B9E97F703ULL, 
            0x6662838F709969D9ULL, 0xCCCF02C3ED63EAB3ULL, 0x5EE09E9DAAB677F2ULL, 0x1A267C3F30E3CA3AULL, 
            0x435840D843B52731ULL, 0xD72ACEBD157B3BA2ULL, 0xA43D7F8EE00ECF11ULL, 0xACF31953693AC00FULL, 
            0x881BF9AE004CFAEFULL, 0xBF2E7EE745CDD7B6ULL, 0xC6573A379ACCA912ULL, 0x1769F818A666D518ULL, 
            0xBE4C49C843DC951DULL, 0xADF9956DFAAAB998ULL, 0xFD4B36DB357C6B14ULL, 0x66F2F3861DB1B9A6ULL, 
            0xC01C110DCCA812FDULL, 0x1BE0F7BAC9C7947BULL, 0x91A919672930BECEULL, 0xFF60501FEABB53A6ULL
        },
        {
            0x8E7AFABE95BFA7A4ULL, 0xCD74ACD935A83AFEULL, 0x496F86D7BE4EFF4DULL, 0x50AB527658834E3BULL, 
            0x1B7A584961A7F1D1ULL, 0x70D6200EFC6713CFULL, 0x276116E03DA4947DULL, 0xFD0E4A7D378BA07EULL, 
            0x97D7FB736C285C0DULL, 0x70CC328E84AD5E71ULL, 0x8DF8220CD546BEA3ULL, 0x231427111E44E022ULL, 
            0xB46140F0AE409690ULL, 0x041746E10D94A2A8ULL, 0x4AABAD29D6189677ULL, 0xF7D6CEE87F6D9757ULL, 
            0xE91DE8A0155CD539ULL, 0x68A6CFC7ED0EEA08ULL, 0xA8F71C8DA22BB119ULL, 0x662663CCED44658FULL, 
            0x0D439A0276721A3AULL, 0x03546F43B50E5ABEULL, 0xEF6E14C91AC7821BULL, 0xA7628CD9C4932B4BULL, 
            0x2E37DF490E972AC0ULL, 0x335CEB39D78C5F16ULL, 0xCE922C3664C1ADCEULL, 0xCA39721C5C67C203ULL, 
            0x115D34BE21E3A3C1ULL, 0xD4222BDF52AC7402ULL, 0x369B873FB2D90893ULL, 0xACF543F2160C070FULL
        },
        {
            0x58BC7306AED1DE5FULL, 0x47D90D762049E1C4ULL, 0x1C135380FB79CA9EULL, 0xBF0FE415F43BD123ULL, 
            0x41F98220A8CB1774ULL, 0x80811B5AB7E3705BULL, 0x06B8CC2E72E804C2ULL, 0xB64949883427F8DBULL, 
            0x92F62FF6FA207C2AULL, 0x654C3A6A8018B3C6ULL, 0x681A1A50399023E4ULL, 0x8087F2109B632C0CULL, 
            0x18EE3A5B407272FCULL, 0xDB9A8C223C60CBF6ULL, 0xFA43479BB5D3E081ULL, 0x73A7E8E4D77C8863ULL, 
            0x5968F67501922DA9ULL, 0x55560F44DDFFA62EULL, 0xF22F714E477FDFD1ULL, 0xE662534DFD467096ULL, 
            0x5E158E7D8D43C901ULL, 0x1C7387C621EEA641ULL, 0xCE9C2266BD524A31ULL, 0x5BBA34062AB8E43AULL, 
            0x1F4FA9C0C631DA81ULL, 0x738A03B0C0A62563ULL, 0x8C341E6C7E26018FULL, 0x140B2C52493B2274ULL, 
            0xE0F2FB576CD042E6ULL, 0x1199A7F6FC052479ULL, 0x049BEBB5B4621FA9ULL, 0xEB2AD6BD4C9D033EULL
        },
        {
            0xDADF7940B978B8E9ULL, 0x02F38AB6F1E767E7ULL, 0x066BEFE4C3BEA509ULL, 0x7A0BC4516EF8CB97ULL, 
            0xC3AE845272C6F93BULL, 0xAA22355F05897A81ULL, 0xCE576D4FBDFE87C5ULL, 0x569271A6A9D21A43ULL, 
            0xBF3FE13E739C292BULL, 0xBBAA900232B0163CULL, 0x9199D7F07C35F2C4ULL, 0x3777479327B324F7ULL, 
            0x4A15F48D70BEB299ULL, 0xFBA4F8303C9B6E85ULL, 0xA7E798E8A5A3B0FBULL, 0xF4AAF95CBAF33C03ULL, 
            0xF92D790666A71CAFULL, 0xD694ACA46793B220ULL, 0x1A61AB8BE1764AFAULL, 0x4D3CC4738E66D3A9ULL, 
            0x5B0262E58B890390ULL, 0x763E617D8AF0718DULL, 0xBDB5BA911C7913DBULL, 0x2FD45BD86FDDFDD1ULL, 
            0x2477145BE3FC3C79ULL, 0x5C9C87A8F6668FABULL, 0xCD4030668EAE2CB1ULL, 0xD9EDF5771490BC5BULL, 
            0x41DE0E5BE19DA523ULL, 0x039776F5EB2BE469ULL, 0xB7665E9821B61989ULL, 0x6381A9308557325AULL
        },
        {
            0x3FC4FEA5A4D9ADA6ULL, 0xF2544DE7A839D012ULL, 0x26B375E070933F4AULL, 0xA6C40F51501C962CULL, 
            0x4E6632C5B09280E3ULL, 0x13C0F5A81EC804EBULL, 0x294C499C4045A74BULL, 0xCFFA28835A6C54F5ULL, 
            0x8CC2FFE970B2DB30ULL, 0x138EA6D8709DE000ULL, 0x3B36064BC33D309EULL, 0x079BB6375F50B4BBULL, 
            0x766A5F4E9D82BFBCULL, 0x79F4B73B2AEF95D2ULL, 0x80ED6D2A28A9A451ULL, 0x35E9363A0AE77FB0ULL, 
            0x000FC06B0A455A13ULL, 0x8B546576951C05EDULL, 0x62DDBD336C78BFF6ULL, 0x336BFEDC4BA34589ULL, 
            0x68B273CC620EFA93ULL, 0x0E4D7971D4E82BE9ULL, 0x7169A5DBAF215FC1ULL, 0xABB3730CCCA6C51DULL, 
            0x47D409F6A9948DEDULL, 0x06CA1ED79633FAF5ULL, 0x8FCB1677ACEEF0B1ULL, 0x5077CF2A0C6A4A43ULL, 
            0x0FDAE75AD2E661D2ULL, 0xC1DCC81487E8394CULL, 0xFC2FE46D296F843BULL, 0x4AADB7059DCA38CCULL
        }
    },
    {
        {
            0x52AAA3233AF5901EULL, 0xFB4B58D2301557BAULL, 0xBCDBC8629B5AAAABULL, 0xFE674AD2EAD17C64ULL, 
            0x7B03F047B1ABE9D2ULL, 0x2D2CC3574F3D4042ULL, 0x235675DB327A3AACULL, 0xB54B96C584376E91ULL, 
            0x86C94346F6B97F51ULL, 0x6B2C84D8F522243EULL, 0x5EEBA238D92B40F1ULL, 0x92AA669D55FF1514ULL, 
            0xB328CAD4385F6BA6ULL, 0xE3C12625321B1608ULL, 0x193B03410E9D8334ULL, 0x8C299D9B5EF81A7BULL, 
            0xBEC2C06843B3DF07ULL, 0xB02F6B01D4E3D8E1ULL, 0xEB7DF06195C49C3CULL, 0x7B6196A87B4905B6ULL, 
            0xBABE436C4E7CAD85ULL, 0x269AA7A0FE2242A0ULL, 0x85CCE5461D4F6605ULL, 0x9BF4298B95B2CA2BULL, 
            0x4757AE5A2C9A4DEDULL, 0x0512EFBBCFC92AE1ULL, 0x365E584A3750F266ULL, 0x5BAE0BA58CA2A0DCULL, 
            0x402C685480ED5679ULL, 0x011BC179366FC331ULL, 0x506AAEFE954E0981ULL, 0x383625E6D4B4EE41ULL
        },
        {
            0xA6B2D6FBCD15CB99ULL, 0x0E8ABD028C636402ULL, 0x9813AC34E3250557ULL, 0xD11A32A71459B28FULL, 
            0x3828F2AFA5F3AB0CULL, 0x2DE11740F404BE99ULL, 0xE7BC97C993269344ULL, 0xB112D16704A40E14ULL, 
            0x7AA529FB53CCEA35ULL, 0x4CD584977CCEEA40ULL, 0xFC848425801A2B97ULL, 0xEE513A7695F714F0ULL, 
            0x132927ADA42DFD52ULL, 0x3B5A55DCEC1521C7ULL, 0x57772C5B7B4F80F4ULL, 0xE18299FC21A48209ULL, 
            0xBB6A8ECC47088631ULL, 0x17B2AD24490B44E8ULL, 0xFC8DBC9E824D5589ULL, 0xD3D31BE7ABAC61B4ULL, 
            0xF8268A44BAC3B9EFULL, 0x700DA54FB8940504ULL, 0x46C87894C045F73AULL, 0x27C43484EED5B388ULL, 
            0x9A04267FBC32C352ULL, 0x6954CCF6802BF417ULL, 0xF6478D4ACEF3887BULL, 0xBE967D7174FA9144ULL, 
            0x8650E249893D7F7AULL, 0x09970E83038CA4AEULL, 0x528D34CBBD0C9B12ULL, 0xABE52973A2E66BD5ULL
        },
        {
            0x75A7051E166AA020ULL, 0xC7A28EF76759DD66ULL, 0x001FBC5526428B34ULL, 0x936DCF77830D3DC5ULL, 
            0x8DA040171CB34835ULL, 0x7BB5B555BE4032F1ULL, 0xB0709A447CC295A3ULL, 0x954AF15797EFF433ULL, 
            0x4BF1F0733B81DCA9ULL, 0x468D227B1C8B86A1ULL, 0x18DCD18BC5D9430AULL, 0x77C7D43C1C9B8C69ULL, 
            0xEE266FD2EB42FA47ULL, 0x5C4AB2E3F527C303ULL, 0xAB55D09DD9DF6451ULL, 0x79AA3A0FB9AB4BECULL, 
            0x88795FD5113780F9ULL, 0x49F0B6D6237EBEEDULL, 0x65D2E5EDD394ADB5ULL, 0x7D2BCA3DD3AFBA8EULL, 
            0x353AE16A23B9E211ULL, 0x5630B11F48935A07ULL, 0x45A72D06D1D0C64FULL, 0x9A15D55091037652ULL, 
            0xE5AD24238A0AEEECULL, 0x5D069A28B43F933DULL, 0x20369250E8036387ULL, 0x15AA4470C7E9A2CCULL, 
            0x0872DA2B69FA7EB9ULL, 0x7FFEA2C56C6BBF20ULL, 0xD63C5FA1D9D23FA2ULL, 0x5A39989108386E08ULL
        },
        {
            0x7621C7570CDDC051ULL, 0xCC088D2A5FCD7E3BULL, 0xE61F5BA8AEE8CA55ULL, 0xD7463AF302884B22ULL, 
            0x9F0DD2ACCFB83D60ULL, 0x5CC064B980EF849FULL, 0xB6E49125D679C63EULL, 0x6621FC25D40196CFULL, 
            0xD79C6C5BAA8F5BFAULL, 0x5DD402F5CCDFF0F8ULL, 0xC2EAACE0D784AE57ULL, 0x0EDAFAD25BED2DC4ULL, 
            0x4142DBE136728EFFULL, 0x8EF6104F86A46BDFULL, 0x849E862DBA475624ULL, 0x6FB050388D7C11DDULL, 
            0xFFEF7AC19F5CFA6DULL, 0xFDC48411DFEAC333ULL, 0x8B031B77C6A9E02DULL, 0xE2535312090B5293ULL, 
            0xAC84D12E8E8C89B4ULL, 0x854E53DBD5EA7009ULL, 0x98AFB3FA7E738DE2ULL, 0xAB12B3C1ECE09F3BULL, 
            0x82A519DEA98D4ED5ULL, 0xD5FCE21B2148341DULL, 0x7FE616211422866DULL, 0xEB16BAE986846030ULL, 
            0x5BEBB0780EF628C2ULL, 0x21410DD973B3F879ULL, 0x75EF78A1999BEE88ULL, 0x0768B5B1A8CE56ECULL
        },
        {
            0x8FCCD8F24DD73F9AULL, 0x62F2432ABEC2F080ULL, 0xD682D61C114FFBACULL, 0xC8BE6D16E4ADE1DFULL, 
            0x8DCAC0A657BED9CEULL, 0x010CB9EB0DFD82E3ULL, 0xF745CAE820A3927BULL, 0x019957EA7E88089FULL, 
            0xB6BAFA6323FF51CEULL, 0x02A6CFB8EFD27CA0ULL, 0x0B7B56807A7346FFULL, 0x47074461B68FA446ULL, 
            0x5F40E158F4139DBCULL, 0x1AB0A3AA859C049CULL, 0x3CB9AC33E43CAFB9ULL, 0x24DBF5429E45CFB4ULL, 
            0xF5E3E17179ED475FULL, 0x03B3C80989036ABEULL, 0xA0023E6D0B3DF646ULL, 0x136E11CB711450B8ULL, 
            0x5A3C7E017ECD7F12ULL, 0xF604F2D4E9719C5EULL, 0x974908C846AF156FULL, 0x846DEB5B6B632DFAULL, 
            0xA992363B1250FC61ULL, 0xBFC246B3E9189CD7ULL, 0x5550AD60E084D0A1ULL, 0x90F0C72C1B625C5CULL, 
            0xA47AF2C8912FF1BBULL, 0x32693F29B97341A9ULL, 0xC7B08B2F6F2BEA13ULL, 0x0A02898757A992D1ULL
        },
        {
            0x4C75635FFA13CF6BULL, 0xCFADD1F53B97642FULL, 0x34F5330592F78A79ULL, 0x71169D9202F12E02ULL, 
            0x820A12384518418AULL, 0x666ABEA380E5CD7AULL, 0x77365BA9DE48D521ULL, 0x5AF7175C992580CEULL, 
            0x6265F4E699EE1341ULL, 0x4193378F4180908DULL, 0xA33B12BC3D3112B6ULL, 0x25C53E1308A3E5B3ULL, 
            0x686D29A838F45AD0ULL, 0x58026F66A0E4D13DULL, 0xFE850E01E27A621AULL, 0x4F55173FD684BFC8ULL, 
            0xFDB81DE36EDCCBFCULL, 0x4FC73F56BFF98F53ULL, 0xAD54B9A4CD823477ULL, 0x78AE47711FC88200ULL, 
            0xC20F082A4E885790ULL, 0x53A8F1FB5D25F50BULL, 0x8226099A75DDC5C2ULL, 0xB8A13DC4E2B8CA99ULL, 
            0xCF6CE95FD5FED4C2ULL, 0x24AEC2D9A8E46971ULL, 0xE85090D1420EE1FCULL, 0x726A608495120E83ULL, 
            0x82CB1C27DC2EFEF0ULL, 0xB7CD264C7692DAA5ULL, 0xE06508EDD54E3D1DULL, 0xB28EF1BA481E8AC5ULL
        }
    },
    {
        {
            0xDC06375B5DAEC7B6ULL, 0xD73C008F73117658ULL, 0x462F8882AD0C4A08ULL, 0xE3FB4483021B0496ULL, 
            0x07F07A8317A6C9CFULL, 0x85E6EDC2E59C0957ULL, 0xC67A44EF9B46C5FDULL, 0xE580B69FA02B9219ULL, 
            0x62E95C247F203FF7ULL, 0x226EE4C4C32EDA14ULL, 0xCD88BD7D59AB4DB7ULL, 0xA3F2E446BF289012ULL, 
            0xE3D3D019D4F893FBULL, 0x4EB0CCD8E0960EA3ULL, 0x6B49368DB5F51627ULL, 0xF90607918EF30B43ULL, 
            0x39CC42F054B37BA8ULL, 0xBE580970528DA8BBULL, 0xFD415A87C7D905A5ULL, 0x81062A4F3C7EE06AULL, 
            0xDE93797C4D398B59ULL, 0x06E0B8580EE1A7C4ULL, 0x0611471664D867E4ULL, 0x4E26D2F0B07760B1ULL, 
            0xCECE13B9DCA6560CULL, 0x2AAC905370A56094ULL, 0x4584154375E7D508ULL, 0xFB4F522CBBA3A76AULL, 
            0x5A64BAAB1BD27BE0ULL, 0xA831C4E508EF98AFULL, 0x4CAC2407F5F458FFULL, 0x6F8856020EBCC8D1ULL
        },
        {
            0xADCC3CE7DB13E609ULL, 0x3DB678F579F04F3BULL, 0xCBD4FCC71C633B6CULL, 0xE4AFF1A2D917A2A0ULL, 
            0xAF428AC839DCF54AULL, 0x2FFAB90A3D94E8A6ULL, 0xE2F2800C74CD2075ULL, 0x669EF411F12B422DULL, 
            0xA8A4E1453B26DC41ULL, 0x6CFC477183DC453DULL, 0xF3DA108D72F30927ULL, 0xC46B188F62631B82ULL, 
            0xAD61F1EEC9D505B2ULL, 0x188A7EA67F72CE3EULL, 0xF9494004CC50202BULL, 0xDD4AFB34BCA8A3C4ULL, 
            0xB6FA1B0D9FEC4B62ULL, 0xBFDBE62E170E3FFCULL, 0xFEE585D3253291F6ULL, 0x9FFD2DD5831045D9ULL, 
            0xD19B1674B7A48BDCULL, 0x21E3A2C09A0AB949ULL, 0xD39D1ED96857E4DCULL, 0x77C74532E68CF800ULL, 
            0xF3FEF0713985645AULL, 0xECB9CB0E874471C0ULL, 0xD788CA58B0123332ULL, 0xA367EB0FC0F8216AULL, 
            0x241CE7D34ECE4B27ULL, 0x10F2FDE6306186A9ULL, 0xAC06F54B4F05D464ULL, 0xC13919F1C3A5387BULL
        },
        {
            0x3F33D83609F4D272ULL, 0x9D67B290FC9B77DDULL, 0x8B7B02FE897B7500ULL, 0xBBF26DA8B00073ABULL, 
            0x78E047E215154315ULL, 0xD53E3369D3E46055ULL, 0x66BC8AE56C58D2DAULL, 0x684D41BB9F9C2B9DULL, 
            0x9948D473D57DB5FAULL, 0x62FCEEA81C5BC578ULL, 0x93A4172E61C728B4ULL, 0x792631E758DF73E7ULL, 
            0x0D690CEF73F04CEAULL, 0xFF837D0299DAB45EULL, 0xBFC84AD1D2CC201EULL, 0x8C51C290E6C78F69ULL, 
            0x9DC2215B4506B4BEULL, 0x675D4BB93607214FULL, 0x038B930252F090EAULL, 0x86DCD28E58001634ULL, 
            0xFC4F384D6EF49DE7ULL, 0x48D3221E9289BEF2ULL, 0xC9FA0CA3BC096E60ULL, 0x6730452BAF5C160EULL, 
            0xF3979A64E2F7A9B0ULL, 0x943865154D29037DULL, 0x72453FA3F650E9D3ULL, 0xFE21345BAD627926ULL, 
            0x94D66D0E63636103ULL, 0xD91A581A1E268E81ULL, 0x6DA03A514E71DD97ULL, 0x9A75FEA1245539D1ULL
        },
        {
            0xC076D0159BC1DAE2ULL, 0x2DE80E5DA3AD4A73ULL, 0x4C55F4C0AE46D4BBULL, 0x854B4D2763C7CD30ULL, 
            0x26BF4F049AFDB335ULL, 0x47D038864CD0A156ULL, 0x11140B28B0DBBF93ULL, 0x3678ED31A55C9224ULL, 
            0x0324243490ED2B41ULL, 0x7BC2897714A3E352ULL, 0x1ABBDAD6FCD7F25DULL, 0xEF9DC1C9959F4166ULL, 
            0x90F65756A79DEB1DULL, 0x46407A1BE8AF6386ULL, 0x52618C5F64CE5C0CULL, 0x3C975C5AA4FA7400ULL, 
            0x68B180EFC1C0725FULL, 0x3977DB096BD91361ULL, 0xF253B3DE76854550ULL, 0x7803DC3FA4F21A5DULL, 
            0x3C1343633B6F8CEBULL, 0x82703203B33EE0A7ULL, 0x68DAA0FCA5E89831ULL, 0xCFD55DC32B184F1FULL, 
            0xFE23C1F2A6CDC309ULL, 0xB02F1A1FB54EF80DULL, 0x73904AC5280DEEBAULL, 0x7F9CC5A10DFE8396ULL, 
            0x95EBC585C233363AULL, 0x5849612EB653613BULL, 0xB033BDFF03D2BEE7ULL, 0x980B7A1BE498BF57ULL
        },
        {
            0xB970BEFD381B3CCFULL, 0x357923E112919203ULL, 0x75B00D3F00357F3BULL, 0x0725D8177FEFF932ULL, 
            0x7E548D75EAC8C191ULL, 0x28C05EABAE09DE6CULL, 0xACAA2F0C4E9597C5ULL, 0xE6FE25DBAE1E66ABULL, 
            0x49E4630BAB6D55C2ULL, 0xF38A246D345C4FD9ULL, 0xB1814BDB6AD8E14DULL, 0x634CE90A450A6D5EULL, 
            0xFF71ED48533AFEB0ULL, 0xFDB6C0A137D98504ULL, 0xB37A4C00290B40FBULL, 0xF44151C7D717ABECULL, 
            0x06F05F5107CC329EULL, 0xA701E68568AE0DD7ULL, 0x0101742D1D83772EULL, 0xF701C0A4512C7BB9ULL, 
            0x24D5853270097807ULL, 0x6D9CD5C3A0783507ULL, 0xF5144EF79A84C16BULL, 0x6E5032C4BDC194E8ULL, 
            0x839968F0D193AE1DULL, 0x69F032D035C63A91ULL, 0xCD981D83F4B3C52FULL, 0x4F439085F7084A1AULL, 
            0x8973966087E5FE71ULL, 0x563A24726F63053CULL, 0x07538FDEBB6E5EEDULL, 0xCD4398BA894F0A48ULL
        },
        {
            0x2FA6F734A6130669ULL, 0x1C4F9EA9FB7B041AULL, 0x4E50AAF79A58C72DULL, 0x006305124A926E13ULL, 
            0x8889AD375C609162ULL, 0xD2D390C2981E6AFFULL, 0x1C840AC2D7D26C8EULL, 0x8AD248443C351736ULL, 
            0xDDA57F21B7D7082EULL, 0x6F7E5A22B569E8E5ULL, 0x260FD034FB5C6179ULL, 0x767587E45AD687F9ULL, 
            0x7C73BBF1BDBEC54EULL, 0x313D1626F953C03FULL, 0xB9B1152C54ED7D83ULL, 0xEAF62010481A65B4ULL, 
            0xDCDEC0F631920C4DULL, 0xB5C98E2DB17ADA45ULL, 0xC3602AAB1429D007ULL, 0x1D4317C10B6779E2ULL, 
            0x149E2998EB474C1FULL, 0xD4AE0976C329F0B9ULL, 0x1218A7C436A5AE55ULL, 0xAE4931F388130E99ULL, 
            0x95F28B134EE3A6BEULL, 0x95FBA7610D20D624ULL, 0x9A6D77DA90B714F5ULL, 0x16BBC91CE3B06B68ULL, 
            0x2C3BEC959A63684FULL, 0x4A688A91A08C193BULL, 0xBE1470F619BEF920ULL, 0x9A8D2CA79BFDCFF8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseFConstants = {
    0x6CFF7C712DBE4C56ULL,
    0xC46CCB8A7C9C180CULL,
    0x74D4115088224081ULL,
    0x6CFF7C712DBE4C56ULL,
    0xC46CCB8A7C9C180CULL,
    0x74D4115088224081ULL,
    0x8DE7229758CAFD90ULL,
    0xC8CD6CA4CA8EDB1BULL,
    0x9B,
    0x9D,
    0x69,
    0xC4,
    0x1F,
    0xB6,
    0xCF,
    0x29
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseGSalts = {
    {
        {
            0xB546C8336F93FBB4ULL, 0x63B2AD682D2DD523ULL, 0x8CF5194537B1CDF1ULL, 0x114A2C72BBDEFF4DULL, 
            0xFD907876B0DD8949ULL, 0xEDC6133EA338E6ABULL, 0xBAB7767E64844344ULL, 0xA59BFD9BD1B1ED23ULL, 
            0x262A8C89CD502BB5ULL, 0x102CA8B86AD31B5CULL, 0xEDF17DF88B0F646EULL, 0xDC30318207C614A8ULL, 
            0xDB5111544D0A18E8ULL, 0x6733513CDE113B17ULL, 0x679B679DB9A31EB1ULL, 0x557410757F0D4871ULL, 
            0x79CC00B014EB1161ULL, 0x0A91A0E2B7499A69ULL, 0x6372A9544436B484ULL, 0x2BEE55492EFE8C86ULL, 
            0xDDB6E7964F708601ULL, 0x18F571042566EFB1ULL, 0x3236E2C030C9CCA1ULL, 0xDFD1DC4E00F8821DULL, 
            0x7EB36AA54CBDEDECULL, 0x3624637B4AFF7ECFULL, 0xD36EC14A039AA197ULL, 0xECF760EEAA071CD7ULL, 
            0x795AA5F9F844F0CAULL, 0xADF9C094739BD2B0ULL, 0x174694420F6F8C9AULL, 0xC3A859DAA1C8D73DULL
        },
        {
            0x1FD02DCE8FDE1E3BULL, 0xA03CA800913D5C54ULL, 0x40ED823350930990ULL, 0xA2BB3D60821D3AB0ULL, 
            0xB8340A49E5AC2B5DULL, 0x5FB48D5B08B29764ULL, 0x23A1453CF22DB636ULL, 0xC23E17E1638E4C9CULL, 
            0x8E02795DD233805FULL, 0xCAF7A85357EB1AA4ULL, 0x18ED8D540372F8B9ULL, 0x4667297FBDC63F3DULL, 
            0x60C485EBF7098C8AULL, 0xAD896A93589D7D38ULL, 0x7C31D6A061965EAFULL, 0xF2148B5B9D0C0D3FULL, 
            0xD442F133348F909DULL, 0xD3BE84DF6E1AD478ULL, 0x39AA6FDBECF1D03BULL, 0xEC845DBBFEB584A9ULL, 
            0x5569A6FBE8D0B056ULL, 0x2B97593D916F97DFULL, 0xE87011CE9C772B46ULL, 0x069562FAB74DBB38ULL, 
            0x2852AB4F8AB94B03ULL, 0xBE43E9D2462BF6A6ULL, 0x4C43C6D3B3F3F736ULL, 0x9F67F9671031C2E8ULL, 
            0x38552F5322489961ULL, 0xD1243A6D0616AAE5ULL, 0xAA481D0E1279E729ULL, 0xA092113573F6F601ULL
        },
        {
            0xAE6069B712F4C3C3ULL, 0x2CB6DB0270D106A2ULL, 0x916CE848CB20DDE6ULL, 0x945BDD8EC602A9F6ULL, 
            0xE41DF7BD9428A4A9ULL, 0xD9A772AD5E046A49ULL, 0xF5D0F1690A121D56ULL, 0x43CCC4F7C2450CFFULL, 
            0x6A626E61AA96A7ACULL, 0xF791ED4BBED93EB4ULL, 0xD2F69FA1F984F067ULL, 0x55777DF62E94B21EULL, 
            0xF2BFA5935C41C3B0ULL, 0xDA0FCF6B8D7C7130ULL, 0x79419634793AA279ULL, 0xD5FCF4F0FB064743ULL, 
            0x5F82DB8436999358ULL, 0x8F2F7B6CEC92F5FEULL, 0x2C291425575E0F02ULL, 0x29061378AEDF3C36ULL, 
            0x33F6FD150E4E046FULL, 0x6E2741742A4FD0A5ULL, 0xA161FBDE67ED6F53ULL, 0xF3BADBED56C8FB1BULL, 
            0x1B8DEB6A49FFB2C8ULL, 0x62B5514BD4BA4C3EULL, 0x0C818D9FA40D8B6BULL, 0x1EE85899BD8E2164ULL, 
            0xBADA51731952CBF2ULL, 0x35D207F05955B08AULL, 0xC4158DD292FC64BFULL, 0xCDD9E527DE47C88BULL
        },
        {
            0x49BA4C6E7F1DACDAULL, 0xC6EBB4096EB90271ULL, 0xCF650C15FE255D7FULL, 0x170D5EB3ABA69451ULL, 
            0xE8C9BDE798A0387CULL, 0x77C1934ADD3EB393ULL, 0xB2DD6A53A74F382EULL, 0xEEB2A94F07D24BAEULL, 
            0xF5A2473BC9AEC834ULL, 0x8EF414100690FBE0ULL, 0xBD4942FAF17254E7ULL, 0x4781DF2B8FB5E625ULL, 
            0xB3D06DF7A7C4238BULL, 0x82F29D4BD715D181ULL, 0x52E1940176561EDCULL, 0x45184F8C6D92301FULL, 
            0x381077150A8147CDULL, 0xD1152EA1A1872C4EULL, 0x07E0833C7A4AAC0BULL, 0x6620888C5C3E38F9ULL, 
            0xE669302F6E9E1024ULL, 0x17FF7EA2583EFBE3ULL, 0x521A87787536FBCBULL, 0x5A7DD608983A5C46ULL, 
            0xE4909D4168ECB5CEULL, 0x8322FE9F271A8864ULL, 0x95E158675B556391ULL, 0xE9691D85ADA442E6ULL, 
            0x4D8935294170CC63ULL, 0xBA8D7549909E1B26ULL, 0x5588FEF9875119F4ULL, 0x7AB57D93C0FE31AEULL
        },
        {
            0x6D64F2B7ADEDCD78ULL, 0xB856B5E562CAB881ULL, 0x9EB06B65189925C8ULL, 0x92E0A0C0ADC00BD9ULL, 
            0xC8ABE7CF451B0766ULL, 0x820CB0E68BF8758CULL, 0xD83E05BC32EFE5D9ULL, 0x6493CE99FFEA4570ULL, 
            0xE3B744E41C62ECE6ULL, 0x206F9693D2A052D4ULL, 0x849883AADF62FFE6ULL, 0x60606EB9DE7A57EEULL, 
            0x63C9379EAF953006ULL, 0xBB962562259D24E2ULL, 0x0E13BD99302D1EECULL, 0x8CAA2B9C30409D4CULL, 
            0xE0C9FF42ADD31EA7ULL, 0x5D1369681A4D5411ULL, 0xD6214275E3567190ULL, 0x448999DC7FDBB8A5ULL, 
            0x56DB9081ADAFB450ULL, 0x1C9C636244A96109ULL, 0xC36A345CEFBC0853ULL, 0x81C6A37190381012ULL, 
            0xF040059B9D68A080ULL, 0xC0EE3F8FC0A1ECC7ULL, 0xFB43EAF82DD9AD7BULL, 0x4EBA4C8C38EDB34EULL, 
            0x524D568D6F3B4892ULL, 0x72C154ACE8B0513EULL, 0x5AA0B8373CD8DF53ULL, 0x7612221C779F5A68ULL
        },
        {
            0x106FE1C7941AC1C4ULL, 0x8EE9C346B4361B7BULL, 0x69926980FA685837ULL, 0x72FED2C499E29F4CULL, 
            0x2C120DAD4C5D0265ULL, 0x4EB7844789CECF44ULL, 0xB8C77B948FC62522ULL, 0x6E6B4EB9F15B48ABULL, 
            0xD2AE10AC039840C8ULL, 0xA6CC3FE28E0766D1ULL, 0x1B1445D33AA07603ULL, 0x2B0C717CB313D9CCULL, 
            0x3E33F320CF8E8329ULL, 0x21A54FBAE248E7F3ULL, 0x92F0DBD5992E2A9DULL, 0xD5D35D758B599892ULL, 
            0xFA72CB8A50B88CDCULL, 0x4BEEE81EE3FD61C6ULL, 0xBA477F62F8C9DF37ULL, 0x874CFE6162EF8386ULL, 
            0xFB7F365D1A3267ABULL, 0x7AC6D5047E67E3FEULL, 0x7282E022EB95D604ULL, 0x4DFDD3618283C6A9ULL, 
            0xFFF3D2001F840798ULL, 0x33CC01C60BBA200FULL, 0xB963A7C7527B47B2ULL, 0xE422E9EA958E9F0CULL, 
            0xAD532CD922A166C7ULL, 0xEBAFE822DA9784E4ULL, 0x96DC1AC588C38B89ULL, 0x9CA49B9B43C0C7B7ULL
        }
    },
    {
        {
            0x268EE324896BD955ULL, 0xE3DDE13224F42AA0ULL, 0xCD5C168257F55360ULL, 0x4F84F1376B371232ULL, 
            0x401E5CDA49D43C0EULL, 0x6CFD0349AED7573CULL, 0x3C747162FA75B4D4ULL, 0x1CD09AC3B1E258DAULL, 
            0x7CA4C8B0DAF6409EULL, 0x651FFF95126BD295ULL, 0x2CB1B46554A71A6DULL, 0xE3D397469E55A237ULL, 
            0xBB96E7E0D989875DULL, 0xA091CE1DB82B0F7FULL, 0x7A1F16484815E1FBULL, 0xB3BC6134F8792455ULL, 
            0xA0DAA371FB672259ULL, 0x185AD667B471BA4BULL, 0x328ADA82FB3F3F3BULL, 0x4BAD091E1E1650D4ULL, 
            0x4CF1982FAE8A3465ULL, 0xDD8BA43FF3DC50A6ULL, 0x90C0CDA96ACF1998ULL, 0x7A9FE69CC2BDA0FFULL, 
            0x7DCB53AEC4D49BEEULL, 0xEA9C0EB5269FCCB5ULL, 0x090EB9093EE57E09ULL, 0x4FBEE6C32B442D33ULL, 
            0xFF45E933440DBF60ULL, 0x9A8DE32F6FCF60CDULL, 0xCF8FF319F0A2C270ULL, 0x734949EB0BC47A71ULL
        },
        {
            0x8135FC095FB2B701ULL, 0x54E975885018AB9FULL, 0xE25EC14991816A1FULL, 0x9379AE52DB62FEA9ULL, 
            0x8E0A0F946E86261CULL, 0xF782EAA504EBB24EULL, 0x03EBD46EA95D59C5ULL, 0x50285418E248052FULL, 
            0x05065F6ACE9A9E92ULL, 0x32DE049826D24F00ULL, 0x00243600D2892F08ULL, 0x72C9B14A21965EB3ULL, 
            0xE2FB3A8BEA5DFB24ULL, 0x307FEE8310C7AAE3ULL, 0x75B88FA22F05860DULL, 0xA51403AB5FA55CDEULL, 
            0xACBA41C3500CF756ULL, 0x96DB0B8E3C7E8CB2ULL, 0x56758D28FE79EB18ULL, 0x4D20EB287A6065ADULL, 
            0xC583C1CA328EC531ULL, 0xA6297E69398197BAULL, 0x3469E3262F10A27DULL, 0x7E789D02E91E482DULL, 
            0xA1E01103F34D6E94ULL, 0x1791E7D452EBE11FULL, 0x0AA9869EFCBB21C5ULL, 0xFF509DB429A8FDC4ULL, 
            0x4584FD1C60CC3E6CULL, 0xFB0087867A8FF204ULL, 0x5886E335430CE437ULL, 0xB629F6D48D9D27FCULL
        },
        {
            0xDD0E0FED1362C28AULL, 0x5F2677D717C45938ULL, 0x1DDC8AC5A0644DD2ULL, 0x183B04B6F986A70EULL, 
            0x6435AD3A563781E1ULL, 0xA42F213317C3DA64ULL, 0x7FDABCF1E3B68287ULL, 0x62C213E5B6066EDCULL, 
            0x5BD494D5F183F278ULL, 0xDB86FA7B58B2F82AULL, 0x423B7778D61EBB10ULL, 0x9C79AF136C6548EBULL, 
            0xBEB23175C47899C2ULL, 0x97F11C7009532C73ULL, 0x185D094EF0E629F9ULL, 0x4FDDCB6EADBA42C8ULL, 
            0x59670D6E1DA6DB9EULL, 0x20DF9586C040C62EULL, 0x3E22816337A3D67AULL, 0x8CB07ED1970E7A8EULL, 
            0x49F3EB42380A91D6ULL, 0xF2576C78EB92B32CULL, 0xD75C6BB4F25E9196ULL, 0x669C2DE2B845574AULL, 
            0xED6FFE6F65A0165AULL, 0x39C1AA438F7322F6ULL, 0xC329AB95794EC1A6ULL, 0xBAA824102C01E466ULL, 
            0x1DED92ABC5AF6426ULL, 0x0D46F48DAE792F41ULL, 0x3B0F9330CAFF4D23ULL, 0x58614938EA634245ULL
        },
        {
            0xC11AC8B35A6920CFULL, 0x5012A75F166D8202ULL, 0x38C096FE59E1E3E9ULL, 0x86C32250AD6287A7ULL, 
            0xB929D25D34EA7869ULL, 0xA70D1868A75D467DULL, 0x86F2B1E8D309F1A5ULL, 0x692D37E267D6E05DULL, 
            0x7E27EC781849F806ULL, 0x03EC8AF97304BC0AULL, 0x2F10D2DF0E12CE3CULL, 0xB9FA79F886DFD2DFULL, 
            0xEB33F07D63B88228ULL, 0x97028C8F8A3F762CULL, 0xF90414F33C1CE278ULL, 0x212B1DA04874725AULL, 
            0x31B695494FA4F16BULL, 0x3931DDD6A7A4D6F2ULL, 0x7B48003A94DF7F31ULL, 0x0E541B3FE4C1BFE4ULL, 
            0xD8ADB19759C1A007ULL, 0x12635D914DF64A9EULL, 0x91E93228F4F91F74ULL, 0x81438F2243DD4CABULL, 
            0x99EC2B2B19393805ULL, 0xEA1F2D8A4856C41DULL, 0x7C73D270E9A3C965ULL, 0x711499AA8E7ADC18ULL, 
            0xC692EBAAABE68441ULL, 0x19ABBEF62FD19EBCULL, 0x9ABF74FEBA2A1CC6ULL, 0x53B3AABDD10EE55CULL
        },
        {
            0x7588B90934BEEB09ULL, 0x959D31B1A129A50CULL, 0x8228CEB4D07E646EULL, 0xC7CAEF27E34C8DC3ULL, 
            0xAF18A5CF4447513FULL, 0x1B327F8430E683D3ULL, 0xF2E95CCE25D401F6ULL, 0x4232BCB2391E6D19ULL, 
            0x9C123841EDD0592AULL, 0x368DDA5A7C210216ULL, 0x43F503AFA596F97EULL, 0x30E301F5547DA1A1ULL, 
            0xDFC78C21203DD6C1ULL, 0x783D7564A572368AULL, 0x033682EB79684137ULL, 0x7A6ED10CA032A475ULL, 
            0xC1ADEA3C3F3711DBULL, 0x07B4DAC9668425F8ULL, 0xD39078852B2523D4ULL, 0xE88FD17054CCE0D6ULL, 
            0xD06B08E9B1451070ULL, 0x860B5200518C886FULL, 0xD10829B3BB150228ULL, 0x853CB283C12A6A2FULL, 
            0x150546E744739FE7ULL, 0x35FC7228042F9B39ULL, 0x739FEF709C8A3D2CULL, 0x3BED63D09FCA8002ULL, 
            0x37642E72D25B97FBULL, 0x5EFD34A1E1CAC1C0ULL, 0x3ADC5BFC9A669406ULL, 0x85163404C3C3D3BBULL
        },
        {
            0x383D689D39FD7E4AULL, 0xF8C31612D32FC7EEULL, 0x224AFCB75D25BF5AULL, 0xFC16E2E5B5F979EFULL, 
            0xA758FB4EA1A9C4D5ULL, 0x21B74ACBACBD46C2ULL, 0x038BA8D544BFDA71ULL, 0xF93DF11B8554306DULL, 
            0xFAAA56C5FAA20D76ULL, 0xBB5A4FD1D1BA0DE2ULL, 0x2EA4FDEB9F0EBB40ULL, 0x28EDD874261BBA5CULL, 
            0x5084A46E6D9EE2ECULL, 0xBFF24C30A2B0A399ULL, 0xBF77E62EEE8A69DDULL, 0x7EBE5CE5D5E63ABAULL, 
            0x013BC38E6EBDFB38ULL, 0xFE00375F32ED14BCULL, 0x86C018A4A649D216ULL, 0x0F11CFE1F79A5B5AULL, 
            0x6B3D62FA6CEE7E6DULL, 0xB20B607D8765E094ULL, 0x4F3D93B95F1CD763ULL, 0xAD5EA8A4EC2B403CULL, 
            0x351EFB7DEDD6ABBEULL, 0xFA2B68470527C25CULL, 0x3ECBE7E6326BAAA5ULL, 0xE2667B1A13B67281ULL, 
            0xBC4CC40A7417548CULL, 0x63049600B53D43F1ULL, 0x1B454488F109B732ULL, 0x03C60F6C6AECB431ULL
        }
    },
    {
        {
            0x41019144E7CA7EE5ULL, 0xBDDF0A86EA0D4059ULL, 0x5FC033BAEBCBB5C5ULL, 0xF5C2805C9F79C322ULL, 
            0x496254F4BC2D101CULL, 0x2E77BED8ACABA5C6ULL, 0x491B30E930AB04FEULL, 0x90E3975956DCF646ULL, 
            0xEDFCC513A94B92B3ULL, 0xC9913828F4C41774ULL, 0x4549903B17172AB8ULL, 0xC5BEE7A6DD13CC95ULL, 
            0xC4A9CD2C9419B275ULL, 0x7130FE5A72A9E022ULL, 0x1E0F2DE1F5F9EB52ULL, 0x0A043012CAB336F8ULL, 
            0xCE081A03CB4DA97BULL, 0x60CFBA91769A8B23ULL, 0x71B86D3B6AE75468ULL, 0x631B51E656C6351CULL, 
            0x75578098A4E4283FULL, 0x9B013785DFFDEDE1ULL, 0xB1191F0979214ABBULL, 0x49FEC0488A59025AULL, 
            0x43FCA674D96B0940ULL, 0x09CC89F921E8A745ULL, 0xE5A15AD0A64C41C4ULL, 0xD20F29A719538FF1ULL, 
            0x147DD84A82659CFAULL, 0x186807B5A392FBDCULL, 0xA2F636FD8360F980ULL, 0x64EDD53CB8123B32ULL
        },
        {
            0x270BC9B1729CF029ULL, 0x476E8D7F72946714ULL, 0x14260A94F0866BD3ULL, 0x4F663D01FC40F952ULL, 
            0xA989240D3170E21BULL, 0x44F3A0EE1FCFCE71ULL, 0x4FA19245B1E3DD49ULL, 0x31DB27B85681C4E7ULL, 
            0xDBD69279B0C71B89ULL, 0x735DE851EFA23A1DULL, 0xA7A4146CD890C2E4ULL, 0x7D52DBFF9A0F1B64ULL, 
            0x3C97D59A9564E38DULL, 0xDF44D892E8B25AFDULL, 0x2E7D687C7F360998ULL, 0x56088244C63B794CULL, 
            0x59C735C130F1DC29ULL, 0x6F57B6514F4732D1ULL, 0xAF6DC1919C3DE463ULL, 0x3F851899F4210F3EULL, 
            0x831F47A47D249E4FULL, 0x7284DD7F7CE7593FULL, 0xC43FDB591B864874ULL, 0x1A4B7A7E4085AEACULL, 
            0xD66F61732CCB347BULL, 0x5312FB1D8DF28544ULL, 0xBD87E1758DB9D08DULL, 0x4A6D4CAB84A811BAULL, 
            0x9DCC7BA9918E659AULL, 0x5B35ED71500E4D42ULL, 0x183C17C1FECDAC47ULL, 0x0BF06607D5C8BFEBULL
        },
        {
            0xE3FB12C65E9E3194ULL, 0xF28A7E63357CE9A5ULL, 0xF0979CD7BE8DBAC1ULL, 0x321F4D2CFB188A5BULL, 
            0xB4D06C398889DF50ULL, 0xD66BCBF7E16F5D7EULL, 0xB28045F0FD032623ULL, 0xCA80555AD8FFFB2BULL, 
            0x578526406629FFB0ULL, 0xD0605AD1B88AA2A4ULL, 0x9F7220CAA81A01ACULL, 0x36DD239D871884F8ULL, 
            0xA2FB7E2052EBF609ULL, 0x414C6DF07521045BULL, 0xE6984FB4B5824E92ULL, 0xAB5CE8DCCBC71FAAULL, 
            0xDDDAF5D5DCB4C040ULL, 0x9A4309C8B59899A9ULL, 0xB781EB6EF1A0AE68ULL, 0xA0CBFFCBFC30D80BULL, 
            0x904819BF56DE2692ULL, 0xBB6844AB1419CBA4ULL, 0xEE86B1EB7EA6412DULL, 0x17FD9AF5463613D9ULL, 
            0x58DA49AAC7B5AA16ULL, 0xFDA48A9A7F54B4D0ULL, 0x21C0CD726B819D37ULL, 0x22E7D0D812CEDA19ULL, 
            0x0CC9D7E44E0B4088ULL, 0xA5A1F56CEB322911ULL, 0xED22C7E700CBE19DULL, 0xC4A2225A336F6FC2ULL
        },
        {
            0xF7AB5D66A9B48E8BULL, 0x253D97E07EFA5D81ULL, 0x093046BB5D3BDDB3ULL, 0xF03DFBBCD4868678ULL, 
            0x64C19835864DA788ULL, 0x726B6C8C36F8C925ULL, 0xD92619B32946D1E9ULL, 0x90E9229D656B8893ULL, 
            0x2BA3AD258F858DA4ULL, 0x773BC7D59C7B08DFULL, 0xC09212EA5D868A4AULL, 0x59F6D6176563F6F1ULL, 
            0x2EC3AADA66B962FCULL, 0x83933C0E81BC8598ULL, 0x307B27C49A3F96F6ULL, 0x356A2B958C6CECFCULL, 
            0x61BB893F161A2C1CULL, 0xF2C15216385153B6ULL, 0x3929625F66B86A03ULL, 0x66DFA670784D2A10ULL, 
            0xBBD2BA64331E320FULL, 0xE6DBBEA566501015ULL, 0x455E86932B12913AULL, 0xEEFA2C292F293CC5ULL, 
            0xFA3A38B7564937B7ULL, 0xF34CA2FFE688FAD9ULL, 0x3845196621939274ULL, 0x8E2F88C11C4B6178ULL, 
            0xC2BD77A1C466C151ULL, 0xD356F2B80749DC8FULL, 0x31A0C4560B24F254ULL, 0x4AFA025091ECB7A7ULL
        },
        {
            0xED1853ABD8415888ULL, 0xB565DD3D4DE03F61ULL, 0xE7984A053A8883C8ULL, 0x17F0325F9A37333AULL, 
            0x4035877BF77C0983ULL, 0xDD660470D4A145C2ULL, 0x10831CDAD486A6ECULL, 0x7C48998E19BF8473ULL, 
            0xA8083306B69752D0ULL, 0xD04CB8F0DDB7DAF3ULL, 0x7FC0E3C5016C1A54ULL, 0xA2FFC71F94CDAAFCULL, 
            0xBF7861A4BCD7E995ULL, 0x8CCA52DE91E9F984ULL, 0x253812D5699E41F1ULL, 0x2F9AE3CB49240010ULL, 
            0x75611D0143E6A3D1ULL, 0x9C87F91005D95D3AULL, 0xE3A2E95D2675B242ULL, 0x734950FBCC272D39ULL, 
            0x32623D3285551AA8ULL, 0xEBBEDAA99F277D6EULL, 0x5C91406C5158048FULL, 0xC218511D3A916000ULL, 
            0x87B76FD97FDCD640ULL, 0x6BBDF82D42F6A169ULL, 0xF4A317BA55134360ULL, 0x13D0EB3A66AC5777ULL, 
            0xD183AF534B8E0392ULL, 0xB9C73D8875F4A364ULL, 0x26D7477335F03096ULL, 0x142D1E926B69EEA0ULL
        },
        {
            0xF0A0C07071CA69C8ULL, 0x6B946DB38CBC14ABULL, 0x8D41251F18E4C031ULL, 0x110640A5867DF1A2ULL, 
            0xDA9106AC5454C0FFULL, 0x7B95911E761D891DULL, 0x9F270DD6759588D9ULL, 0xFCB0DED328E95A0EULL, 
            0x3501EDF88C0D4A9CULL, 0x67DE20770507AEA1ULL, 0x1D1322963214AF55ULL, 0x06F31624FEA8D734ULL, 
            0xB60B18A92D53F4EEULL, 0x002E6F5B2200D7D4ULL, 0xCB91DBF378C20B67ULL, 0x77B8193FAC20A275ULL, 
            0x92A393FE0330DC7CULL, 0x0EBF69E74AB0491DULL, 0x2C7E4272DFE1B9C1ULL, 0x5D101BB442B7F128ULL, 
            0x8B117B760339B492ULL, 0x928C1B9A922487FEULL, 0x3291897E321EDF19ULL, 0x13F7DEB02ADB9F7DULL, 
            0xD8E1D962D24D09E0ULL, 0x3A4190FE5864189BULL, 0x8A79388823AC59CDULL, 0xAC9C0F2AF91CD66EULL, 
            0xB60B652E842A808EULL, 0x5CEE83F34BFC910FULL, 0x5B5F1C754628B47BULL, 0x258EE64E37AF7123ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseGConstants = {
    0x08E746BD9C16CC6EULL,
    0x85DC50E1DD8B2EC5ULL,
    0x671B757C8F404112ULL,
    0x08E746BD9C16CC6EULL,
    0x85DC50E1DD8B2EC5ULL,
    0x671B757C8F404112ULL,
    0xF417C763A9BE3511ULL,
    0x3CE23C66ED933E2AULL,
    0xA7,
    0xD2,
    0xDB,
    0xD7,
    0x48,
    0x48,
    0xAD,
    0x8B
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseHSalts = {
    {
        {
            0x88B1C348117ED03CULL, 0xEABB50762BE3A26AULL, 0xDC1639D55A754A51ULL, 0x91A35279627C20FCULL, 
            0x6A9E7289D9EFC16EULL, 0x26152BCC70D71ADBULL, 0x49FEEB5ED164152BULL, 0xFC7430E8ABE762F0ULL, 
            0x6C7AEE8CDC5F4387ULL, 0x7AAE0C914547C111ULL, 0x10190F403D0FD2A4ULL, 0x9A15D9F0DDF29B3BULL, 
            0xE4AD891AA047DF0AULL, 0x3CE69C1E03E90EFFULL, 0x09C0957C87731054ULL, 0x37857E3332A45BEFULL, 
            0x76517CDEE21427E4ULL, 0x3D4A927B80C30169ULL, 0x44FF6C6B4ACAD355ULL, 0xD332FD352C23FFC7ULL, 
            0xA9477F86B7BAD044ULL, 0x8EE63B02EB1359CEULL, 0x314B2B3CD56C8C03ULL, 0x4E0D2A35601F92EEULL, 
            0xBAD231BEBA9475CDULL, 0x03558E8EBB6E0D0CULL, 0x430CF7E18B029E11ULL, 0x7D13B5CB3C994E84ULL, 
            0xA75092BFF03521C5ULL, 0x0D0B99C35606B132ULL, 0x6C81F67ABCAD3A93ULL, 0x34AA1BE01F6BB1E5ULL
        },
        {
            0xFA3235751C12934BULL, 0xD64A18A8A1DD0311ULL, 0xB811BFA397FDD8C4ULL, 0xF6C43DC6E3BF6F99ULL, 
            0xA1C60073514EC137ULL, 0x8499B1D4B2ACC846ULL, 0xB03136761EB1C21CULL, 0x86E360D8097CD435ULL, 
            0x9E21AF3F5A52BEB5ULL, 0x84AE8424697204E6ULL, 0x02ADCC5636BA8EB6ULL, 0x4BE4B57B02814B06ULL, 
            0xB34F2D81D3052EC1ULL, 0xC5DAF041D05BC67CULL, 0xA679732331157C17ULL, 0x6B5097AE9B35F183ULL, 
            0xBC7DD5B71DA7091BULL, 0xD6A84D52CA5A8B09ULL, 0x162AB89970459D96ULL, 0xCEB56C56C0567DCBULL, 
            0xF689FC8E63D468CFULL, 0x96C47E1B14565158ULL, 0x9A56F7C8E447CF49ULL, 0x667F6BF2B2253E06ULL, 
            0x97A6E17837392331ULL, 0x5B8E1D8BC0CF176DULL, 0x3BF2CADC9B651901ULL, 0xB824668BDC2FB8E3ULL, 
            0x6E5B69175824F789ULL, 0x742AC12371EF63B3ULL, 0x142EB95BF4283362ULL, 0x451589F291B83324ULL
        },
        {
            0x13CF1411A9B64CEAULL, 0x21FDDC0ED792C5EAULL, 0xBBF87980A7558F23ULL, 0x30CEF577756A06FBULL, 
            0xE8713027DBA37867ULL, 0x2A8ABC7871C9D1A7ULL, 0x127284C69D6BEB08ULL, 0x0632C0718536A5D2ULL, 
            0x2F81CEE4D49FF415ULL, 0x7C2F3C8464EC069BULL, 0x43D5C3E83F00C6F5ULL, 0x004713B5A699EFB2ULL, 
            0x42C5CFF026C7B448ULL, 0xB3FFF0660EA87CDEULL, 0x7B53F4C7560C762FULL, 0x640766B479798337ULL, 
            0xC2E7D342F49F583BULL, 0x88CE1EFD1492FCB6ULL, 0xA7FFE8DFA83AB576ULL, 0x919F3B1445DD27C6ULL, 
            0x9AE843E3417C6355ULL, 0xB1B0B4D88E3CB3C9ULL, 0x922EA16A35F6BB6DULL, 0x838324F74B868031ULL, 
            0xB082AAEEF10D04DBULL, 0x1F41A3B2BAEA1169ULL, 0x6211DE91D4EA81DBULL, 0x2E00C9D621E75FE1ULL, 
            0x8DB6C117080247DDULL, 0x294D922D5B6AA1FCULL, 0xA4CA92373E419739ULL, 0x18F2CD10CEE3995AULL
        },
        {
            0x8B538AE45D68B755ULL, 0x59D63582029001F5ULL, 0x529C80EE7E7BEB1DULL, 0x1D70339948304E5EULL, 
            0x4E5A27E6303A934FULL, 0x8D83902DA30609D0ULL, 0xC2CE02BD4263C5F2ULL, 0x5638CE17299BB5CEULL, 
            0xDC76B4869EDE4568ULL, 0x4990124C4F44B626ULL, 0x61CF6AA0743AF3BAULL, 0x1172EC48C6C88FAEULL, 
            0x9B7FC2A6706D2D30ULL, 0x847802896307012DULL, 0x554D5AD01BE0D075ULL, 0x9DBFB7670765B481ULL, 
            0x16C124E42BB5F73EULL, 0xB506D1A9C922748BULL, 0xCB9C403B4DEE7999ULL, 0x9FE4579463AC6090ULL, 
            0x9C77A15CDCED98E9ULL, 0x846C8B031FC36843ULL, 0x4CC4EDE8122CBD7EULL, 0x7DCFE9B0DAFADF5AULL, 
            0x915A96ED9A7B13B2ULL, 0x46DF107DCB8C3297ULL, 0x94B4074B1A82BA30ULL, 0xD30C41FB5F8976F9ULL, 
            0x7A442D51B32FBC25ULL, 0x0C934ACD92CAB0CCULL, 0x4A7018CD76301BEBULL, 0xB684AB240FAC6B67ULL
        },
        {
            0x950FA5F37B9182FFULL, 0x7DDB3C351679E65DULL, 0xA5F57A19245B560CULL, 0x85D781AC966277FDULL, 
            0xD0128A21315FA5F5ULL, 0xB7C257319A27223AULL, 0x1242C1D71BD87F16ULL, 0xEBE8172FF49C6685ULL, 
            0x06BEDDC429178054ULL, 0xDAF62578081305C0ULL, 0x7DFE645AA89D44A0ULL, 0x17431256F57CE2D6ULL, 
            0x10D958AD9E7D9D11ULL, 0x5F8779C71C23B7A8ULL, 0x6FD38B4EE49B1FE5ULL, 0x3E57A6F2DA291D66ULL, 
            0x652B23E9971D0079ULL, 0xBA71C5FEB07A2CC0ULL, 0xDB85BA74867FC8DBULL, 0x66F3BE7A8B3A1A09ULL, 
            0xD66937232EDEE50AULL, 0xAC8515A8B11C749DULL, 0xDDC62EBC49DAC481ULL, 0x6ECED26CB1B4EB6BULL, 
            0xF15E1B318A9A4579ULL, 0x9AA9F68C7C65B4D9ULL, 0x294C2132EDC06AF3ULL, 0x6341081799885AFDULL, 
            0x8DE476EA8A73A9D5ULL, 0xEA4925B5B5E26A8EULL, 0x02D2DCA99E2EAFF0ULL, 0xB9D1E6CAA04A039BULL
        },
        {
            0x6064BF60832EEC18ULL, 0x08F30A54BD40E8E0ULL, 0x7313C0E303B84C01ULL, 0xE7D41F602F59878FULL, 
            0x6B640757C9E57B4CULL, 0x8B5C7174AE57E473ULL, 0x282B5D3DEC4733B0ULL, 0x24610F614864858EULL, 
            0x363E0D28F6DCF54AULL, 0x3CD11B1FCFAF947DULL, 0x383F47287F261945ULL, 0x25A150F54C7175C6ULL, 
            0x1FED0DAF4F14DC67ULL, 0x92DD6E1AF0EF22BBULL, 0x6B1888AB54B21885ULL, 0xB6DCC5BD1722A1DDULL, 
            0xE7F1E004D6CD7BB1ULL, 0x9FCBA5A5D65F3A78ULL, 0xF9512432AEFCFD3AULL, 0xACD3A5AEFA6EC788ULL, 
            0xF3AF3D71F722A3EFULL, 0x72D49A8FCD431E6DULL, 0x8D64CE301F26D20BULL, 0x634A85B62CFBD167ULL, 
            0xE08A63A3BCA8FF08ULL, 0xA9F339BA5B392C3AULL, 0x71536E920B7564E5ULL, 0x5F84C5A7E5C77E67ULL, 
            0xD70840CE7F3D191EULL, 0x715D157DCAED7753ULL, 0x504FE32BFD1D57A7ULL, 0xE8591EC13B2B83C5ULL
        }
    },
    {
        {
            0x07641E1B803B2738ULL, 0x71AF8ED8231C73E2ULL, 0x459300D557FF3459ULL, 0xA501DC9ABCC35A3EULL, 
            0x9E783DC372DFC816ULL, 0x22DEABC667BF5597ULL, 0x2CB6F6B19A83B112ULL, 0x27376A0E33322B85ULL, 
            0x07E1FD30AB019D7FULL, 0x65EB42D029590E0CULL, 0x6A67D6F5C60C1CC0ULL, 0x9D7A0B54725E630FULL, 
            0x22C5B172DFD3CB87ULL, 0x2F8E44E99F48F5F2ULL, 0xC0D17B384D524AC4ULL, 0x4F4F141DCF9B1187ULL, 
            0x7F9E5D07E80CB252ULL, 0x6C0FA6D34CA58D3CULL, 0xD2DA233985702286ULL, 0x71FA326457C814C3ULL, 
            0x8DBF07045A9E3EC1ULL, 0xA09689F6F66AE0E9ULL, 0xA3489BA160A7ACF4ULL, 0x20A916199668DBC2ULL, 
            0xABD773DDD7E851E6ULL, 0xDE0F0037E00E7142ULL, 0x6120F8F029C97E18ULL, 0x000517BA011083E7ULL, 
            0xA442FEAF56BE0C63ULL, 0xF9E2D828A29DEE0AULL, 0x7A8C0C54BC4B96D0ULL, 0x5F3A160ECE977A8FULL
        },
        {
            0x64D2916D35E86EFBULL, 0x47B929F1FE9B11DFULL, 0x3073604F2B81F0AFULL, 0x6B8BEDDF39C06B07ULL, 
            0xE01E32AF4FE8CD25ULL, 0xA86466CA77974704ULL, 0x321ADF9176A3047CULL, 0x9D03DE170B321FFDULL, 
            0x9E626B2ED7F546C4ULL, 0xEEF1E13B24BF2F85ULL, 0x98346AA97475761EULL, 0xDF843AF2912F0AD2ULL, 
            0xE4ED4754E157FDEAULL, 0xD3B592ECE83A869DULL, 0x2DB46DF4CB9C55FAULL, 0xC9259FC8A6162F67ULL, 
            0x3085C37A66B2A6B8ULL, 0x4CF4D55472FC1CFDULL, 0x863FC31D83A26812ULL, 0xFB9A4D46996D57E1ULL, 
            0x96EAB30C3E08CAB2ULL, 0x6DC40D9BAF878E1EULL, 0x8BBA9E03996E09E0ULL, 0x0554C89828E6CECFULL, 
            0x38EC49FA0857005EULL, 0x472BB3894190EFECULL, 0xCA25F00C996D6209ULL, 0xB753285416895CD5ULL, 
            0x199B4D140FC4E31CULL, 0x7D312FF213D842D9ULL, 0x248049AFEE5F7A76ULL, 0xA678DEE9AF20D5EBULL
        },
        {
            0xA9A1DEFCC8D92D43ULL, 0xDAD5DDC1C968C3AEULL, 0x313D899BAA95CAC2ULL, 0x897A311DDDE8B410ULL, 
            0xFA7FDA76E4F67E84ULL, 0x9214826DF4158FF8ULL, 0x68EA3D121CF0FFACULL, 0xE6F2BE4DFA83D601ULL, 
            0xF833F3BAEC43B989ULL, 0x80C876BEB2C50377ULL, 0xF4159C29E151AA46ULL, 0x348C1E3FE8CFD8D3ULL, 
            0xDAA36F07F87AA848ULL, 0x52BE29566F0E241FULL, 0x8A3BE7902AB3BDFEULL, 0x0E105885AFF7A2ECULL, 
            0xC4049C060CC339F1ULL, 0xA9DEBBCAEF25B2B2ULL, 0x3E5773687070C0A2ULL, 0x129C1566173370F9ULL, 
            0xF039943104E3E852ULL, 0x12A29969F38E3699ULL, 0x10FAE6BBD7FAC897ULL, 0x4AA2AAE9A8DB43F5ULL, 
            0x8560384416977D6BULL, 0xBFC04D5D74B32D5BULL, 0x4AE886776C64057EULL, 0x310160D9BC709C7BULL, 
            0x2BB17C12FF8B5FCBULL, 0xDA5BF69F7D428433ULL, 0x2CCDAA39FCFD9FE3ULL, 0x2B1F46B337EF4881ULL
        },
        {
            0x761383DF7B1CF27BULL, 0xB9E4F6755B60BC4DULL, 0x0A48EC20980255E7ULL, 0x52922097371DE389ULL, 
            0x393C59F4B1BD5829ULL, 0x9F212BC818582FF6ULL, 0x921960E0B8A0BB68ULL, 0x232745A5CDC1524CULL, 
            0x7CC9402A36C736B9ULL, 0x6C1F2D3DDE790AB6ULL, 0x01AEB2ED8969A1FAULL, 0x065268108C7E8482ULL, 
            0x2DF76B8E9A7A04C5ULL, 0xD6112959997CD29EULL, 0xAE091B3D2960CD64ULL, 0xAF3D7E004CB4C183ULL, 
            0x9696585E2CE2149DULL, 0x82B9DF64143BB193ULL, 0x54D6999958F464FFULL, 0x385CFD3FA99D4C5DULL, 
            0xE7A670AC7F9D125EULL, 0xCEE7D8D1A70C46E3ULL, 0x0583C36C94BD9610ULL, 0x42498426CC7775A4ULL, 
            0x41A45C9EF61A5565ULL, 0x092FC91DF9D8339EULL, 0x5362A75D794061FDULL, 0x0F42B4C385DB2A30ULL, 
            0x1CBA65D670386974ULL, 0x161C140A5372AE66ULL, 0x22500F1B3A897F21ULL, 0x875F12F2DFB2917FULL
        },
        {
            0xABE461190352FF9BULL, 0x967E1036F2BD7DE9ULL, 0xED213042E04C2559ULL, 0x536C1A853FFB5BF5ULL, 
            0xA983828642D1A2FAULL, 0x728FBC9C99B084C6ULL, 0xA9A5468E506D998FULL, 0x4091ABA1656D442DULL, 
            0xFF5911FC4838D742ULL, 0x8C0FC0AA04C2EC64ULL, 0x2AC0F698790AF315ULL, 0xD4AC522C7498BCAEULL, 
            0x028206188AF1967FULL, 0x2CAD430892B43133ULL, 0xDAE541FBC40D5429ULL, 0x9123F08CE79160CEULL, 
            0x6C4FFF6A353C726AULL, 0x9ECEAD7C5F44EF8EULL, 0xC5D91E9BFA702AABULL, 0xA9E46A3B3FBF32FCULL, 
            0x9D0D14DBAA1CDFDDULL, 0xD33FAB82729BAB90ULL, 0xE68889D3EBAE9414ULL, 0xFC96D87E63917A2EULL, 
            0xEAA122C73C7A8780ULL, 0xDA216947CF696C9EULL, 0x9570999635460687ULL, 0xC050E2FF92DCA271ULL, 
            0x530AF808508CF4DCULL, 0x122C86D19ABD7318ULL, 0x660147974461452EULL, 0x81960043560CF556ULL
        },
        {
            0xBDF1D9889A4375CAULL, 0xF4D52D430A5B2C8CULL, 0xE357A37198B73269ULL, 0x118CCF73E41CFBCBULL, 
            0x65E5978C9DE5C1BBULL, 0x94229D156A51730AULL, 0xC9500CE0252F4AEEULL, 0xECE71234939629FAULL, 
            0xB82696D8EE31080DULL, 0x6BC7A32125C370C5ULL, 0x15C08E1818ECA602ULL, 0x8417AF923C1253E2ULL, 
            0x98D371E5FC28A67DULL, 0xDE9FF890EB5391E4ULL, 0x443CFD812E03546FULL, 0x002ACEDD5B9CA49FULL, 
            0xBFBA8DCB439EA0D7ULL, 0x7974D57A6F5F08F8ULL, 0x2647DFF8A6211554ULL, 0xBF37295F60D4A0B3ULL, 
            0xCEC6FC0C4492C87EULL, 0xF04A5B686C7F5B86ULL, 0x7EEA4E8C4E15B7F1ULL, 0xF7B022C1F259181FULL, 
            0x25143AB57095411AULL, 0xE285BB15DC1BECA9ULL, 0xE2296760A0AFA2DFULL, 0xFCD1D7A01AE25456ULL, 
            0x8B84AB3C4D9C3C2BULL, 0x1BEDE4A4A7766FA1ULL, 0xFBB9B3EEDEB4A6F7ULL, 0x146A3712DC657A72ULL
        }
    },
    {
        {
            0x991780ECA3906998ULL, 0xDA3D9A6A92157BDFULL, 0xA687F9761041E9B9ULL, 0xD2908D3DF2E882F6ULL, 
            0x3EC08678E09B6E7AULL, 0x65598C19C076E63FULL, 0xF3DD63F165D29A0BULL, 0xB4A909BAB9A65C56ULL, 
            0x3CA32A870E4FB297ULL, 0x9CFBB8EE8A02EE82ULL, 0x17461B37329F0D39ULL, 0x2D57C4D0965BB627ULL, 
            0xAEA3B4F5C2584E28ULL, 0xD4AFCEBE82753BA5ULL, 0xEFCE6B4BEB37F10DULL, 0x492872C3F42D76F1ULL, 
            0xF222DF56C0681EB2ULL, 0x229ACBB698A246DBULL, 0x5122B3C8E7835FF3ULL, 0xD2ABCD0214CAAF2DULL, 
            0xAE6F8DC74B7AB359ULL, 0x2DCD0F26AA0341A1ULL, 0xCBA856752B5BAC47ULL, 0x921B2DB56A6658B1ULL, 
            0x090D8527F90F1E36ULL, 0x1D0936618D2FB3CFULL, 0x36BBD1D1FDCF567AULL, 0xEC6CD1E88FE590C5ULL, 
            0x6B3ED2BAD84D164DULL, 0xA64FF38281C5218EULL, 0x8803EC02CC573BB3ULL, 0x2EC5BEBCD3348D93ULL
        },
        {
            0x21D69BF7D57FE803ULL, 0x1583221DC8DF2908ULL, 0x2CAC5DA9DFEC2E8FULL, 0xDB7EEE4C11E8A5EAULL, 
            0x971FB4B10D87BEF1ULL, 0xE7CF3ED55A2987E8ULL, 0x96ED0853F8309345ULL, 0x549D36C4D2ADD26CULL, 
            0xEEBB4ABBC15064A5ULL, 0x2DE97B53F6A2153DULL, 0x90E0AC6E325224BEULL, 0xC092783452025C1CULL, 
            0xEB5A9649D879E330ULL, 0x9AB9F28A25C386C2ULL, 0xCD922D0F1A1312FDULL, 0x8876AF0B80ABA545ULL, 
            0x2E97FB1C444EA49CULL, 0xD9F3A4DDDCBE54ABULL, 0xC5F9083A39FAC34EULL, 0x64AD4FCE94125612ULL, 
            0x19C96495117D9F0CULL, 0xBC0EEE659A9F2DFFULL, 0xDC2DABB6F1478084ULL, 0x68A8790DD0DB447CULL, 
            0xF586409DF932D1DCULL, 0xECB8F0D5B59E8690ULL, 0x0978A346CD43CB46ULL, 0x9BF20E3351A1C7A5ULL, 
            0x09AB29BB36D186D2ULL, 0xFCAABE55B131C8F1ULL, 0x551C6396CCE38DFDULL, 0x0E65B5B5EE21A088ULL
        },
        {
            0x4D44DD5D87651360ULL, 0xDBE1BD4A45CC013CULL, 0x461911EBF5BA360EULL, 0x244A36864F41AF31ULL, 
            0xA79BC47BD712226EULL, 0x90723329E64332F6ULL, 0xBF51BA4AD4D908F3ULL, 0x58DFEE7B07587504ULL, 
            0x88F341170A711193ULL, 0x4EFA8B4593197839ULL, 0x1A49D090A87A7F59ULL, 0x92DC8CEC14B505D5ULL, 
            0xEBE1CF3A940237C1ULL, 0x9860654E3D5269A7ULL, 0x0CF72EE4AA74C1D7ULL, 0xD8A5B48E5375AB7AULL, 
            0x44FB521F7E88B195ULL, 0xE3175B7CECB42F50ULL, 0x9C9C0175E858F3FEULL, 0xD7CF79B818CF5BA1ULL, 
            0x0C6049B68AF300E4ULL, 0x5A9E99FEF61C43AFULL, 0x08526289F92C3A39ULL, 0x138FCD947AF5981EULL, 
            0x41C978E00C5667EEULL, 0x978BEBDD1B54A811ULL, 0x5F4468DD8B4F6598ULL, 0x6242E34CF03A225EULL, 
            0xE76C352195D050FDULL, 0xBEE81684937A89BEULL, 0xE880BCCB0B346407ULL, 0xE51C21CEDE785A27ULL
        },
        {
            0x0F46928EDB0D88AEULL, 0x452E116475B94D35ULL, 0x55AF2F2EFFD1E2CCULL, 0xC76AE4E549205A1BULL, 
            0x183FCAE26544C8EDULL, 0x569E684147320CA6ULL, 0xB30522F39BC7F7DCULL, 0x75E6ACFC5292FA14ULL, 
            0xA11F231009965442ULL, 0xFD5DCC2C7D779710ULL, 0xAEE9F6C2A5050FBEULL, 0x9C29F612736E580EULL, 
            0x97FC44E32ACB3BE5ULL, 0xA0E336B16E5D5D80ULL, 0x09F8B4FBDE15050FULL, 0xE0F03F99574BDEFDULL, 
            0xAF3D77A7D3B82E8CULL, 0x2F602266CACC557EULL, 0x1C1508EBF27294BFULL, 0xD979782E17F77E81ULL, 
            0x00E2D8B88BE3D4B7ULL, 0x2F66E30A9F968D92ULL, 0x2226CC53A2AC7BC6ULL, 0xF0525CF6254453FCULL, 
            0x114AB14D772F7753ULL, 0x4AECF69AD15D31A9ULL, 0x3C86198F47A7C82AULL, 0x50306160EA11849FULL, 
            0x91C72722B6195C3CULL, 0xFD998341751AC52EULL, 0xC4F895A9DFF84994ULL, 0x835A012F8AA0C62BULL
        },
        {
            0xF7AD17E628B40421ULL, 0xC13A99920DE804AFULL, 0x0E1D6A9EA9EF091DULL, 0xDF5ED242DE3F3FC0ULL, 
            0xF1EB899407BB4D1CULL, 0x624D2F71EEE7A357ULL, 0x5EA60D67B73A81F4ULL, 0x7F2DF0E884BF3417ULL, 
            0xB3485601FA079BF3ULL, 0xA6C2685DB40B6C8BULL, 0x77B5D22B7A7D46B8ULL, 0x3CCA4DC4136519CAULL, 
            0x98384BB9DEBA86C8ULL, 0x1602E6F5EF78BA1BULL, 0xAB2BC1A7AF18841DULL, 0x2469EED7095EABB9ULL, 
            0x2C48C957DE6781F7ULL, 0xB17DB8B5F19799ACULL, 0x341376440080BBB8ULL, 0x7383CCEDA85524ADULL, 
            0x2EB3819A49C58530ULL, 0xDAAA9996FBAD5A5FULL, 0x60DEE9CC86A1EB74ULL, 0x1FB0C91764D20119ULL, 
            0xFF274F920A961D60ULL, 0xCEF31C489A470544ULL, 0x11D6D1CB2E72EBD7ULL, 0xCC61B8FF50D88544ULL, 
            0x1E04EE4CC306FED6ULL, 0x03258AE566D24F2CULL, 0x0A68B78C54CD6786ULL, 0xF6D472FD57B165D4ULL
        },
        {
            0x748ADEB7855505CBULL, 0x1759F329F734C1A2ULL, 0xB22C84385E998848ULL, 0x0390B0F5CF35BC32ULL, 
            0x120945AF95FFE3F8ULL, 0x3622CED5917AE316ULL, 0x4F7F90BC17C873E4ULL, 0xA7B0FC387709250BULL, 
            0x8CEF74AE02E8180EULL, 0xACF189DD1A57D28FULL, 0x57A7898DB7725DCAULL, 0x0CA0AD08DBA9B2D0ULL, 
            0xBB327E212794D3D3ULL, 0xA80B17FABA4E1369ULL, 0x05E2FB2C6577B2E2ULL, 0x23144E9845C66AC2ULL, 
            0x6FB036854020FDB5ULL, 0x240998352646B1EBULL, 0x087F3AD1D42B3D47ULL, 0xED89C30E50B12F5BULL, 
            0xF93A4A52E500C67CULL, 0x74BF4D6BEB0C2BDEULL, 0x21E92F3A4DDDCD4CULL, 0x8B3985970D836692ULL, 
            0xA8C77D52913B0163ULL, 0xC3F452D8B630D421ULL, 0xC56471E0B34594F0ULL, 0x28492360088080E7ULL, 
            0xC1C818BB623D1356ULL, 0x909C41A55C151530ULL, 0x3AFC938A0F83A923ULL, 0xF570DF7B2F54C347ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseHConstants = {
    0x889F99EED614838DULL,
    0x409F2A6E72191014ULL,
    0x3C8D16A5403557FBULL,
    0x889F99EED614838DULL,
    0x409F2A6E72191014ULL,
    0x3C8D16A5403557FBULL,
    0x29CE6B959203FC8DULL,
    0xD19839AD81D86433ULL,
    0x1E,
    0x7B,
    0x96,
    0x3A,
    0x73,
    0x15,
    0xE2,
    0xD6
};

