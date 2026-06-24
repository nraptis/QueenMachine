#include "TwistExpander_Unholy_060.hpp"
#include "TwistDiffuse.hpp"
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

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 13390196447601880395U;
        aCarry = 9875512818207399177U;
        aWandererA = 17097999508359879603U;
        aWandererB = 14216445848961164537U;
        aWandererC = 17427851655902350814U;
        aWandererD = 16842618274915754956U;
        aWandererE = 14797396323227343825U;
        aWandererF = 15243343786587899080U;
        aWandererG = 13980381464041523590U;
        aWandererH = 15610369455681369898U;
        aWandererI = 13179176463817549579U;
        aWandererJ = 17031693426197429304U;
        aWandererK = 16950242394755773545U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 mSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_A_B kdf_a_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_A_C kdf_a_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Unholy_060::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [kdf-b]
    {
        aPrevious = 13007014225271487774U;
        aCarry = 14825012288155034723U;
        aWandererA = 16691196089468742322U;
        aWandererB = 14872033702855077999U;
        aWandererC = 14352605391039985574U;
        aWandererD = 13843113300455227271U;
        aWandererE = 10251362556376692865U;
        aWandererF = 15356525236202516652U;
        aWandererG = 17650637348308758449U;
        aWandererH = 16695764031780429970U;
        aWandererI = 13050731122984302439U;
        aWandererJ = 9954808640165943753U;
        aWandererK = 17619962826050113263U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_B_B kdf_b_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_B_C kdf_b_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    [[maybe_unused]] std::uint8_t *aKeyBoxUnrolledB = &(pWorkSpace->mKeyBoxB[0][0]);
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

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
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    }
    // KDF_B PhaseA invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    }
    // KDF_B PhaseB invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    }
    // KDF_B PhaseC invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    }
    // KDF_B PhaseD invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    }
    // KDF_B PhaseE invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseF invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseG invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneB (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseH invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    // secure zero snow
    TwistMemory::ZeroBlock(aSnowLaneA);
    TwistMemory::ZeroBlock(aSnowLaneB);
    TwistMemory::ZeroBlock(aSnowLaneC);
    TwistMemory::ZeroBlock(aSnowLaneD);
    //
    //
    // ---------------------------------------------------
    // GSeedRunSeed_A seed_loop_a:
    // ---------------------------------------------------
    // read from: source, key_box_a, key_box_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
                 pNonce,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_B seed_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
                 pNonce,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    //
    // ---------------------------------------------------
    // GSeedRunSeed_C seed_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
                 pNonce,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
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
    //
    // ---------------------------------------------------
    // GSeedRunSeed_D seed_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
                 pNonce,
                 mSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    {
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_box_a, key_box_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aTwist_AArx;
    aTwist_AArx.Twist_A(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GTwistRunTwist_B twist_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aTwist_BArx;
    aTwist_BArx.Twist_B(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    // secure zero
    TwistMemory::ZeroBlock(aExpandLaneA);
    TwistMemory::ZeroBlock(aExpandLaneB);
    TwistMemory::ZeroBlock(aExpandLaneC);
    TwistMemory::ZeroBlock(aExpandLaneD);
    //
    //
    // ---------------------------------------------------
    // GTwistRunTwist_C twist_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aTwist_CArx;
    aTwist_CArx.Twist_C(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    {
        TwistDiffuse::Diffuse(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    {
        TwistDiffuse::Diffuse(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5607U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 7194U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3442U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 1210U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 5U)) + 3339283916456813609U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 11339086426180649584U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 16819191669329316585U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 46U)) + 8361916937762630725U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 18031328374429899857U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + 18261756894092897276U) + aPhaseBOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 35U)) + 4250319792907645666U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1492411503643460886U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17369549067879344180U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7301713524358676722U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9209505304067579944U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3522631966146762306U;
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8811497120829041188U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14707301680850257294U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10080595991787801029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 6U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10711U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16224U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14998U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13670U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 10336802574069791273U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 13U)) + 169025388197058936U) + aPhaseBOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 6541354188379168846U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 38U)) + 16223920526599306104U) + aPhaseBOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 19U)) + 12756613707692514808U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 5082475548176484035U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 3U)) + 4907435526952698526U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14236627073831834337U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterJ = RotL64((aOrbiterJ * 3460330807286625917U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3679044835550219497U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10582608424233200966U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4628253464169957835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3798386391743884889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9816600392407327227U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16781971616348376878U;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4807797577690520554U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterB = RotL64((aOrbiterB * 9453302540675483005U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 10U)) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23725U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17175U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22536U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19572U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 27U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 337587740689259575U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 19U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 3742409032569801033U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 51U)) + 1608092659172197650U) + aPhaseBOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 15848744267145717509U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 15300174177963339253U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14162868453323648628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12020167069983729869U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2071080217680099017U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16259538291658723956U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8516686212464112245U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3722184575520553132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15265344442454471986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1093356813820599238U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15170797965325981472U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17826286701992981628U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14710892030473425181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 397194787697553904U;
            aOrbiterE = RotL64((aOrbiterE * 14368930300818752833U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27608U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29258U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32079U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30387U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 60U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 17264605017518259932U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 29U)) + 15209184354580778643U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 19U)) + 3299527965014731384U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 16293096431816127821U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 60U)) + 9188018632448236358U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 11U)) + 13420816400363406556U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2485063384097917101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3089135816938128264U;
            aOrbiterI = RotL64((aOrbiterI * 8813152992957361153U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10730544971770435788U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10431767565618874806U;
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14883796491656899074U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13322163435314643713U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3307316600284371955U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4950101626975919939U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterG = RotL64((aOrbiterG * 7181706961838582889U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17961706029559914243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterK = RotL64((aOrbiterK * 16189559888625084711U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18146616411403012772U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8414050129421955787U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14879448948196182863U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 58U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;

    std::uint64_t aWandererC = 0; std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0;
    std::uint64_t aWandererH = 0; std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [grow key a]
    // GTwistRunGrowKeyA PhaseD salts
    // GTwistRunGrowKeyA grow_key_a_expand_a (start)
    {
        // grow_key_a_expand_a loop 1
        // read from: aWorkLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[aIndex], 57U) ^ RotL64(aWorkLaneD[aIndex], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 50U) ^ RotL64(aWorkLaneB[aIndex], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 3339283916456813609U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 11339086426180649584U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 16819191669329316585U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + 8361916937762630725U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 38U)) + RotL64(aCarry, 39U)) + 18031328374429899857U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18261756894092897276U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4250319792907645666U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7053489184750217963U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1492411503643460886U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17369549067879344180U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7301713524358676722U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2985193736033012535U;
            aOrbiterC = RotL64((aOrbiterC * 7473297294949338265U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14086975808140927408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18205555540941493267U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16967799565443938873U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 28U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_a (end)
    // GTwistRunGrowKeyA grow_key_a_expand_b (start)
    {
        // grow_key_a_expand_b loop 1
        // read from: aWorkLaneD, aExpandLaneA, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[aIndex], 46U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 10U) ^ RotL64(aWorkLaneB[aIndex], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 12U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 10336802574069791273U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 3U)) + 169025388197058936U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 27U)) + 6541354188379168846U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 16223920526599306104U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 57U)) + 12756613707692514808U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4907435526952698526U;
            aOrbiterD = RotL64((aOrbiterD * 1379692095754989215U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14236627073831834337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11502511046130497584U;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3679044835550219497U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11254838916686736746U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8631695922983532915U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10582608424233200966U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10449735026385340313U;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4628253464169957835U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17664454668473204465U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4234720298731378527U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 42U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 44U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
        // read from: aExpandLaneB, aExpandLaneA
        // write to: aKeyRowWriteA (^=)
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[aIndex], 37U) ^ RotL64(aExpandLaneA[aIndex], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 10U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 23U)) + 3339283916456813609U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 11339086426180649584U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 16819191669329316585U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 37U)) + 8361916937762630725U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 57U)) + 18031328374429899857U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18261756894092897276U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4250319792907645666U;
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1492411503643460886U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17369549067879344180U;
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7301713524358676722U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterC = RotL64((aOrbiterC * 7473297294949338265U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14086975808140927408U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10390516547834639800U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18205555540941493267U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 28U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterA, 20U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererD = 0; std::uint64_t aWandererE = 0;
    std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0; std::uint64_t aWandererI = 0;

    // [grow key b]
    // GTwistRunGrowKeyB PhaseD salts
    // GTwistRunGrowKeyB grow_key_b_expand_a (start)
    {
        // grow_key_b_expand_a loop 1
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[aIndex], 29U) ^ RotL64(aWorkLaneB[aIndex], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 13U) ^ RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 5697928251815176134U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 21U)) + 337587740689259575U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 3U)) + 4927686903263973950U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 36U)) + RotL64(aCarry, 39U)) + 3742409032569801033U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 1608092659172197650U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15848744267145717509U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15300174177963339253U;
            aOrbiterD = RotL64((aOrbiterD * 5771922862677667319U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14162868453323648628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12020167069983729869U;
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16259538291658723956U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8516686212464112245U;
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3722184575520553132U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15265344442454471986U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterE, 30U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyB grow_key_b_expand_a (end)
    // GTwistRunGrowKeyB grow_key_b_expand_b (start)
    {
        // grow_key_b_expand_b loop 1
        // read from: aWorkLaneB, aExpandLaneA, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[aIndex], 3U) ^ RotL64(aExpandLaneA[aIndex], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 37U) ^ RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + 12775735908960052604U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 57U)) + 11791373812080296887U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 5537362877706057303U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 2023912048504189380U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 24U)) + RotL64(aCarry, 35U)) + 17668828109963766893U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 558908629933941224U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1479633119685446888U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4447153373540811385U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15460320397843364063U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10059749397555469054U;
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9987633811929693924U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterC = RotL64((aOrbiterC * 13817142288940843815U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4446204415503364254U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9430197906134676162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 34U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterA, 60U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
        // read from: aExpandLaneB, aExpandLaneA
        // write to: aKeyRowWriteB (^=)
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[aIndex], 48U) ^ RotL64(aExpandLaneA[aIndex], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 21U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 11274974230580265396U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 12U)) + 16658438747342741547U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 16612986966106053844U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 9329502236843231290U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 37U)) + 14088261356708344656U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13692608802007789581U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6824473946645682398U;
            aOrbiterB = RotL64((aOrbiterB * 13619437545775237601U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2072915876348570040U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7420507753044460759U;
            aOrbiterE = RotL64((aOrbiterE * 13239288539564571257U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4677557318688502593U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15081678577055628459U;
            aOrbiterF = RotL64((aOrbiterF * 16659305295251177155U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7026792817486507482U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14871665922943969918U;
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6807734532159292872U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17882797335141303280U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 36U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 52U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aKeyRowWriteB[(aIndex) & (W_KEY_B - 1)] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyB twist_key_box_loop_b (end)
}

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseASalts = {
    {
        {
            0x458E0975DCB3A969ULL, 0x780D3F1C2EC979FCULL, 0x99129C85A4B7AFCEULL, 0xAC06F908EF017C4DULL, 
            0xB9C1AA8F8D3EDD82ULL, 0x87EF8B66275B2363ULL, 0xE412A7E99C054930ULL, 0x0F081956CC6E0A0DULL, 
            0xAA783493934457F3ULL, 0x11AD4D754D494EE4ULL, 0x1FAA5D544AE1C4E8ULL, 0xE7FA5BF29B652296ULL, 
            0x8A9BBFE6007B3D87ULL, 0xDA7704F100744F4CULL, 0xFDD573EBFB909916ULL, 0x0A72CB601653B2F2ULL, 
            0xF5353E8C9A7848E3ULL, 0xCB2FB3E7627F97B6ULL, 0x3564EF7D20B5E227ULL, 0xE210030444C44F3DULL, 
            0xC14471247D26C646ULL, 0x47CF6DADAC7BB5C2ULL, 0xB8A6BDAB7BF243F8ULL, 0x4E67524C0774DF54ULL, 
            0x84A404DFBD409719ULL, 0xACDCD3C5D791A328ULL, 0x7B82A0F75B3D35CFULL, 0x3192A56B61572D08ULL, 
            0x6981ECFD9A1B8434ULL, 0xCBBD81B6A1FECC3FULL, 0xD5019812D9E2EBE2ULL, 0x0D3E0FE0E32DC4C1ULL
        },
        {
            0x1C936612CD0F5218ULL, 0x85002710FE6B02C2ULL, 0x3B127EAD20211923ULL, 0xD612FAE0D2F50EEEULL, 
            0x67F127266921BE97ULL, 0x1E7B29655D429C0BULL, 0xEE086BBFAE1F9CFEULL, 0x499DF2C978EB5DA1ULL, 
            0x6B6988E74BA7DA18ULL, 0x52973F6CAF90C36BULL, 0xD5F6213C7CBE048BULL, 0xB2400F6BFA14E73BULL, 
            0x8364A781081FD8C2ULL, 0xE39C89642B2A494BULL, 0x8F30D4EA96131A7CULL, 0x5441F50DE4A14B99ULL, 
            0xF64E7CCCCB1D04DCULL, 0xBFF61E157A58C0B7ULL, 0xAA6F425CDEAC680BULL, 0x1A6C31ECD6A12279ULL, 
            0x21D01DFAEC7A2F4EULL, 0x3D01EDBBB7BBC048ULL, 0x362F00C3096916B4ULL, 0xF79DF28D1EE4E3EFULL, 
            0x6BC81C760F0188B9ULL, 0xBF6F31C8A06DC23FULL, 0xE5D01FD2ED12138FULL, 0x4CA8F19C2F7676C5ULL, 
            0xB9CB2E225D905655ULL, 0xFC8F520DFBC809B4ULL, 0xF202547EFBAC94E7ULL, 0x925C6EA080DDD682ULL
        },
        {
            0xBEA9866FD92630BFULL, 0x45FB2D5A4001BF36ULL, 0xDAA37EE7851479CCULL, 0x1A7917EDC61CE484ULL, 
            0xC84B5B71E07F7C37ULL, 0x8902A12C7401342DULL, 0x5AEEAC5A50D19311ULL, 0x7AD94A0F172DE37AULL, 
            0x86A616CBEA01B50CULL, 0xC06CFCF91F2B955DULL, 0x20950A71E66F88A3ULL, 0x28A7F97A644BD3FDULL, 
            0xD536F521E0151A6EULL, 0x368AAB6F042F66F0ULL, 0x0D664901A1E5900CULL, 0x0C04E210DC431FFAULL, 
            0x5389685A8791B98BULL, 0x57B0E502B1A2D9C8ULL, 0xF9C6F6700513BC9CULL, 0x34DFDA3917874A8BULL, 
            0xA1D1F4E968B15A3FULL, 0xBB02D7A3284651E3ULL, 0x3EF601CF5DFF311DULL, 0x720A95F09DA332BFULL, 
            0x74EA4C84B7F9F1A2ULL, 0x5D3B15378CEB710FULL, 0x27A3EE8A4E57A440ULL, 0x0BA0123FEC395EB9ULL, 
            0xEE2DD432F3B6EF89ULL, 0x6DC922AD96CC1C5BULL, 0x5423D41E423F92EDULL, 0xD3B703562077D53FULL
        },
        {
            0xDA3A0DA63426060FULL, 0x1FD54058C434AC8CULL, 0x51F89FA915EC3F81ULL, 0xAA7975B507B51F46ULL, 
            0x9304AB60889A378DULL, 0x55AC2EBD2D159DA0ULL, 0x3627B62C6873834BULL, 0xBFB0994FFA451BEFULL, 
            0x4ADA04FFA5F55327ULL, 0x16D4D325127A143BULL, 0x2EC5E6DA88C7A079ULL, 0xDFF8A69CF5B965C3ULL, 
            0xDC0A8A2F9D32811FULL, 0xF9412188AEEF8443ULL, 0x090F4A6468165B37ULL, 0xF7C8CAAC0CB72797ULL, 
            0xE05C371945FD58A2ULL, 0xCEAED7817162CFA0ULL, 0xE520CD62E8B7AE9DULL, 0x94F120C043343EA3ULL, 
            0x38EB292D735A982CULL, 0x0A18BB46587A7EF6ULL, 0xCEAD4C9E9F400892ULL, 0xD3ACE3E9C1BF5A2CULL, 
            0xA81E4B2B1B49A7CDULL, 0xCF390D1516350FDAULL, 0x83AB0B5EE7093CDDULL, 0x90CCCE8512C4350CULL, 
            0xF8C5D1688B3CEDAEULL, 0x238C30A46F047FB7ULL, 0x98BF0E563376D142ULL, 0x0BAC0903FCBB5C5BULL
        },
        {
            0xA6690E1E45EA9C3BULL, 0x1E40DC04777A114FULL, 0x81E0326C4D30EE34ULL, 0x0D5D20ED4D9AADE4ULL, 
            0xEA6771BD30134DE3ULL, 0xD70D3C1940B097A8ULL, 0xD33816DD2F810B0AULL, 0x7FC3917108B23161ULL, 
            0x24069BD362543ABDULL, 0xD2565B25B87839AEULL, 0x4E9378C823BA8911ULL, 0x5D4E6E09CF21F08DULL, 
            0x069717CAFE134CF3ULL, 0x1BC32E60296DD7C5ULL, 0xAC46F749E0821B21ULL, 0x8E89F1482DB41698ULL, 
            0xAAE0B08CFEB92925ULL, 0xAD7F0D2294C3B355ULL, 0x54542A3C353DD21AULL, 0xACCEC72793EE1CDDULL, 
            0x59BFD5F52BFE55CDULL, 0x9D1ED68DD79DA234ULL, 0xC5DD16288E1067A5ULL, 0x554A6FA42C3F947BULL, 
            0x93EDB9BEB1676FEEULL, 0x62154612D58646B1ULL, 0x542E57CCEE9BB615ULL, 0x281FC0001DFB9B12ULL, 
            0x1FC5B650F011AEF9ULL, 0x58B3D6FDFBFD28CBULL, 0x8E5DF7CA927B1F02ULL, 0xED073FAD794B60D8ULL
        },
        {
            0x0719C587070A95BEULL, 0x631A226357EFAE00ULL, 0x24E9493AEB9E6BB4ULL, 0x1AA28E01FAD427BEULL, 
            0x59D84C8BC8FC9D82ULL, 0xB50A71F0B4E96BC1ULL, 0x373B74CA1B3ACC0FULL, 0x61F5C2A70F2944A2ULL, 
            0xD2400AD3FAAE9377ULL, 0x2DF738F0F88FE4D9ULL, 0x264AC0EEADF7C6E4ULL, 0x9ECB87EA7F8228C3ULL, 
            0xE1F2AF6D520A0000ULL, 0x4F97BBD837EBB486ULL, 0x3FE60CA45768E5D0ULL, 0xEE49D94285734302ULL, 
            0xAF81A5AB126CBCD3ULL, 0x5C93D8C53A07C31AULL, 0xDAF804D9E3C794E6ULL, 0xD768C35384928CE4ULL, 
            0x62D0BF724EBE0507ULL, 0x9EB73852828EF255ULL, 0x3D2F0258371D7B82ULL, 0xDB639A424ECDAC1EULL, 
            0x683C10AEECA34CD6ULL, 0xC0A7132DDF1A0CF5ULL, 0xA092D235C949ABD3ULL, 0xF23D58471F0A9A3AULL, 
            0x335829AEBD841BA0ULL, 0x260577FB5A86D9A6ULL, 0x31E7DEBBBD2B05F4ULL, 0x8BEAADEF0C0C15A3ULL
        }
    },
    {
        {
            0xC98626B506A95982ULL, 0xF15514FB0EDF5107ULL, 0x1875F3E22223BCD2ULL, 0x8F0FAFAAD7DC1FF2ULL, 
            0x1E2D5D7FF1DA919FULL, 0x0FCB9B70EF684A26ULL, 0xBD54502BDB96E39BULL, 0x0BC7E3B751158885ULL, 
            0xBA71ED6A41F12D4FULL, 0xD15548B3F658AD26ULL, 0x9DF0E073E1011FF2ULL, 0x63E2D97F20898D55ULL, 
            0x4F009C025A41B818ULL, 0xC278CBEFD1C4188DULL, 0x7903A7D43F0BD0D6ULL, 0x45E6160FE0D2FF20ULL, 
            0x7FFC91525B164C97ULL, 0x19B42F854B2D0B99ULL, 0x6245092D0D764C8CULL, 0x5DFF8FED14265D79ULL, 
            0x2645DBCEC942C7CAULL, 0xB610A8623CFEB7A4ULL, 0x65F33767B29D52A4ULL, 0x89C50D7536A3C044ULL, 
            0xC233DC43BC298711ULL, 0x32DD0217014057C7ULL, 0x501436E87C5618B3ULL, 0x4D3F7DCC6320579DULL, 
            0x12BEE6A99D8FFB8DULL, 0x7FCE405136059E4FULL, 0x6466385B7C27FF61ULL, 0x0A1B9B7FE7806A74ULL
        },
        {
            0x0728591A74A0E8A4ULL, 0x9A83238BEEDC2B92ULL, 0x3ADCCF9435BC65A7ULL, 0xC291A1AA05F4793EULL, 
            0x8FB3E573C8A5A3FFULL, 0x459125A3EC227A1CULL, 0xC45954CB2BEF2608ULL, 0x37DA9E7FE9DE0380ULL, 
            0x370D7520613A92DCULL, 0xA38BEA5DCFC56E63ULL, 0x98BE73029F093E1CULL, 0x9AF6A8664245DEB2ULL, 
            0xBF4339DFBF202FA6ULL, 0x03D6E5FB890CA2A9ULL, 0x1F952C6491098D9AULL, 0xBF296C531B3BCAEDULL, 
            0x3DDC5082533C2406ULL, 0xFFA653DC1C1364A3ULL, 0xF449BA08D3F53201ULL, 0x1FD7AFD8076318F8ULL, 
            0x508D4568797D713FULL, 0xD731D69303849878ULL, 0xF389AB7E26F5E9D5ULL, 0x83C80682F65790D4ULL, 
            0x2ED3D5106F463102ULL, 0x66331B4471C38630ULL, 0xD6B152721E70D3EEULL, 0x33BBBD4CAC84844EULL, 
            0xEADA173639D50910ULL, 0x95D7F162A9F5D24FULL, 0x68B4390F820487BAULL, 0x46B23C8C41322BD6ULL
        },
        {
            0x0564F0AA969D24B8ULL, 0x08EC2A06CD0C6016ULL, 0x77A6E39C2E138CDAULL, 0xE96BEBE23E290F96ULL, 
            0x9D7400889FD63199ULL, 0x9CBAF968A9193EF1ULL, 0xD3C5369D80F17020ULL, 0xDAB233A68AEE7583ULL, 
            0x693595DE0587CD6AULL, 0xDE2E9C0E48DA64EEULL, 0xA2B5BA455023C906ULL, 0x12BC2A2FC707D9BFULL, 
            0x59357218EBEDC934ULL, 0x391B279C994EE6F8ULL, 0x44F6B4F1C681A774ULL, 0x433DF86B4085B988ULL, 
            0xEA32F97A01666FECULL, 0x610FC287420A1959ULL, 0x9BE334096AE65020ULL, 0xC3CF3D32BE831050ULL, 
            0xDBF8A529B6545853ULL, 0x4CCD770D86ED337FULL, 0x1B4D9AEFFD016536ULL, 0x5D8C8131818D7983ULL, 
            0x16F68E975B99C864ULL, 0x1345FF0D56CDF11DULL, 0x728D213364270273ULL, 0x34B46870EE080E61ULL, 
            0x872D46483B343A43ULL, 0x6B539C7ED3138EDAULL, 0x62C13E1D199866DFULL, 0xF8F7B12C1E188E4AULL
        },
        {
            0xB5462DAE9CA95601ULL, 0xA5B1AA56F7CA59F8ULL, 0x2DD2A2BBD2F26627ULL, 0x920CCB29413CAFF2ULL, 
            0x82B76D4E828BBBD0ULL, 0xEDF1075588709B07ULL, 0x3A3CCD90856987ACULL, 0x764A441D3D32D7E9ULL, 
            0xE6E9153442BC6C6BULL, 0xF6E4100CC5ECB697ULL, 0x853F48EDDD80A213ULL, 0x4C072DD82D76BD49ULL, 
            0x40486BE00E5673A1ULL, 0xCE83635D3629B519ULL, 0x25EF6D68DE50D85CULL, 0x3B5A429126BA9E6BULL, 
            0x273529CA2EAFFAF5ULL, 0x15AD99D4C6491CF8ULL, 0xA2A64908B19527B0ULL, 0x2A06E1BC48A2E593ULL, 
            0x7A7F73701E5B4498ULL, 0x684C4270035568E7ULL, 0xFBC093C4F1DF1DE9ULL, 0x2A3B4DBD29ECF145ULL, 
            0x4947AEDA638D4DE7ULL, 0x41A5888BB8C1EC36ULL, 0x659A3C6DE6C3316DULL, 0x50DAA28FA16851BAULL, 
            0x52951BA8C96F139BULL, 0x58541E74E904D883ULL, 0x67911244B7D6C281ULL, 0x046D9BCFF7A6B792ULL
        },
        {
            0x16C42D437C9E4740ULL, 0xDBE673DDBD2D3CF6ULL, 0xEDBF2D44B2BAAA66ULL, 0xEF4366536306AB97ULL, 
            0xD4E6664775152E8FULL, 0xBC7B99CCD546CC94ULL, 0xF97C6B9C1EB50AB7ULL, 0x59C4376E20E5445FULL, 
            0xF37EB2E40DBB21BDULL, 0x7EFEE25C04FBA0FFULL, 0x6B57D19FAC9D5CF9ULL, 0xD61796738D024E53ULL, 
            0xE76118307C902A63ULL, 0xE42E5063C1606A1AULL, 0x19090231226BEBBBULL, 0x64F7D6C3F3BBE2DCULL, 
            0xEF4478812EF89389ULL, 0xFDE5490604B23D70ULL, 0x5585650B87A276F7ULL, 0x9D957B76CD265E53ULL, 
            0x5DD5E0B99248CC2FULL, 0xD1FF02A5D0499F82ULL, 0xA8607C0FAADE5683ULL, 0x18E96B5792F5A335ULL, 
            0xF859C5DC7CE7CD2FULL, 0x112FDEB954723853ULL, 0x2670F13C3017E049ULL, 0xE2FCD2A99B2E42F3ULL, 
            0x447AFC0A5663EA3DULL, 0xF7B25BB3612C5909ULL, 0x72B1646FC292E7E0ULL, 0x4CF001974A4DE0E0ULL
        },
        {
            0x3C9B5221E1B79831ULL, 0xAAF4447CB41EEA59ULL, 0xBA77251688BA3C50ULL, 0xE73BFA36A56CE8ECULL, 
            0x682E777DE3D43DA6ULL, 0x541F4C2FF24F128BULL, 0x9069457BBE24775AULL, 0xBE71391904064DFEULL, 
            0xD966401F10161FB9ULL, 0x141FB0E16A486693ULL, 0x9EB8A52E051A82ADULL, 0x1CC16F12E45ECC94ULL, 
            0x8787F5370BF41872ULL, 0x3685B0B8462EF4B7ULL, 0xA49861EF25B545A5ULL, 0x50D388A0290F92F3ULL, 
            0x7BF2DC49CECA92E3ULL, 0x996087987A9FCE50ULL, 0x43C71F9E7D345337ULL, 0x4641A94EB136499DULL, 
            0xAE81125C76C54B80ULL, 0x8D273F92DECAB1DFULL, 0xFDAFC24B1DA8270FULL, 0x1F52720F369171C1ULL, 
            0x5126A9A45FA5EC37ULL, 0xCF1B1DCF95726D22ULL, 0x50352C182BA6CC6CULL, 0x259F92F9FBBB77A7ULL, 
            0xEAB7700733A83445ULL, 0x82FCCE2D77B7C61FULL, 0xB1AF6D6F2C44FA21ULL, 0x15AF872671F26CB6ULL
        }
    },
    {
        {
            0xB2575051EBD62F05ULL, 0xAC5A36271FCDA027ULL, 0xF72B70B7ED6AA01CULL, 0xD4EBCD09A43DC8C2ULL, 
            0xA9B82BE78738234EULL, 0x5B0ACCAD367807A9ULL, 0x4CD3B48BE9F4BE3CULL, 0xC393669B830EFF18ULL, 
            0xB3E8C546CCF539F3ULL, 0x3F78B877E5D36B34ULL, 0x7A3FA9A0895820E2ULL, 0x5ED98AE222625668ULL, 
            0x85D07B6B100E1C61ULL, 0x4BDBA3AB7D3A2051ULL, 0x2F333FC56C27F2BDULL, 0x44DF31E983E84CDCULL, 
            0x67EA627C8A6B876BULL, 0x06B5E6F42DA2F598ULL, 0x6258EDBF65F52897ULL, 0xEB7AF93EC835D6BDULL, 
            0xF104034FADD8A99FULL, 0xEF88811F055DB6B6ULL, 0xFD0B674799DE2C55ULL, 0xB8FD470E1FA0ADA0ULL, 
            0x619B9489FD5A097BULL, 0x5FC402ED9BA29463ULL, 0x41BD733BE8328BF3ULL, 0xE335130AAE6F2C9AULL, 
            0x6BF709B982EAF4D3ULL, 0xC8ECBBEC7AFC007DULL, 0x4F3598510ABCF05BULL, 0x469C729512CF1E83ULL
        },
        {
            0x76494CB7282A320DULL, 0xED9B5B7CA2F0AD7FULL, 0x39882A13D488119CULL, 0x154E5A5C7F502166ULL, 
            0x7A2EFCBFBB73D106ULL, 0x0B927987E5148564ULL, 0xAB7865E78C18C01FULL, 0x07649906CF2B508EULL, 
            0x48474DB413040971ULL, 0x1303F8493D85270BULL, 0x888407072A3025F9ULL, 0x1024CA5C3D69660EULL, 
            0x9F140C4CED859C64ULL, 0x34D99309B964170BULL, 0x54AF51504332BA88ULL, 0x8216C10D92747238ULL, 
            0x0AE1B6724E950E33ULL, 0x436A4EB4073011A3ULL, 0x577BEB92AAF1D79DULL, 0xE7B920100FEFFF9FULL, 
            0x7A9CAE119A4AC14CULL, 0xF28411789A0EB880ULL, 0x3EC486C131E4B839ULL, 0x7CAA5F04940D50CCULL, 
            0x6A8B350A75FBBDE1ULL, 0x5F7E9F296B1F269BULL, 0xF7F54D18622AAEC7ULL, 0xCF3791E7514E7F04ULL, 
            0x7DA076905B8D41FCULL, 0x48C7AB47A4491B6AULL, 0x2F48F12938216136ULL, 0x1ECC03464EE17253ULL
        },
        {
            0x77A220AFB06B25A1ULL, 0x9043EDA08CE3147EULL, 0x415157E43C107EC1ULL, 0xF863206278769941ULL, 
            0xE5B71A50BFDBDFBDULL, 0xF2077122EA41FD4EULL, 0x21536C439B351C40ULL, 0x3780B301741AB7D0ULL, 
            0xA925648CC80FF260ULL, 0x79CFBD452D29E423ULL, 0xEAACD36CAEEEFE26ULL, 0x161B5F4CD02C4B92ULL, 
            0x857F25757462BFBFULL, 0xF17F1F60CB21D111ULL, 0x9D9CE9644A12A41EULL, 0xF29A09CB03B37BD1ULL, 
            0x228BE4DB82C872CCULL, 0xBCE5532F03761378ULL, 0xA862C0B6B796F5BCULL, 0x04F910CA8F34E434ULL, 
            0x6E18A8CEA5A34EB1ULL, 0x070E965FFE01E81FULL, 0xB0DDFEEBD905F9CDULL, 0x96460C9F8499B1CCULL, 
            0x81FD059230B4506BULL, 0x5358C3967D890F50ULL, 0xEE89161A746C3C0BULL, 0x92D648C98384FE9EULL, 
            0x5C96D9FD462B0B7CULL, 0x8019E180789C417BULL, 0xEF207356B38387B1ULL, 0x679D07F0D7E0B368ULL
        },
        {
            0x360729264F2E3374ULL, 0xF9A2C8180D411A29ULL, 0x3295EBDDAA5A8ACBULL, 0x83725299A73315D4ULL, 
            0xD4C0F6572C52A84EULL, 0x8010D9DC52997FB3ULL, 0xCB7A1BDAA4FCCA4AULL, 0xA640C025C08E4598ULL, 
            0x8E06560BE75F5A06ULL, 0x9FA3FF82E52ED2C6ULL, 0xB4899D505138EED5ULL, 0xB3A06276E705AE73ULL, 
            0x5F380365550642A4ULL, 0x990FBB68E71A3949ULL, 0x3D4E287B963BBB96ULL, 0xE15161D50F25A9B7ULL, 
            0x53A69C7CC58F61F4ULL, 0x96D1FE459377C7F2ULL, 0x9044E0BB9AF3D388ULL, 0xC85E63422CE2DBD2ULL, 
            0xEC1FEC941162B422ULL, 0xF214FBA32721D0D2ULL, 0x81019EF74358176FULL, 0x1A08D3B35F7280A7ULL, 
            0xD4DA1492F8E18E96ULL, 0x1F50CD3AB0DF178DULL, 0x7E4DEB48B031E572ULL, 0x56B8D638DDDBCBB6ULL, 
            0x45AC9563AAC81142ULL, 0x5B943BED73727976ULL, 0x669D465928044CF6ULL, 0x27FC1C121488597AULL
        },
        {
            0x755B22947C66E6C2ULL, 0xF7C6C4D410C095DDULL, 0xD02E6449B2950EE7ULL, 0xED590F26F4EF92ADULL, 
            0x252C50F3CBEC3F6FULL, 0xB8E141A6D250F0FDULL, 0x5C0773CB849350F8ULL, 0xD49DAC5AC79A09D6ULL, 
            0x55C3B01D50366331ULL, 0x6437CDBDBC982B5AULL, 0xA46E8A636F3D4116ULL, 0xE1D6CE6F55390B2DULL, 
            0x20A5C26F798497EDULL, 0xA50A8669F11C5579ULL, 0xF80159C8151B661EULL, 0x684DF4092C7B4511ULL, 
            0x623B3688B060338FULL, 0xC54EAE9DB15684D2ULL, 0x2F66F59B600DE18DULL, 0x27759F1EABBE1892ULL, 
            0x5E01597AE5B9A445ULL, 0x5838E15FAAB63E9DULL, 0x2BE441037308BBAAULL, 0x703645E627E014C9ULL, 
            0xCE0943DFA283D328ULL, 0x67D13ECF4CD7CCD6ULL, 0x11349C4E9165602CULL, 0x19559EF003EBEF03ULL, 
            0xC88A099B4A8D8C4AULL, 0x20DC3CC1E7A02EDFULL, 0xB7014E2E250F9096ULL, 0xB82EAEFBCE01D8ADULL
        },
        {
            0xFAC51B619CC72976ULL, 0x7C27B37584101FB4ULL, 0x6670EC8765960A5AULL, 0x7BD506A1CC6D9745ULL, 
            0xEE9C52C867835815ULL, 0x7F774C36410A369EULL, 0xED55903E7ADCA350ULL, 0xD004A7ADD2090A8BULL, 
            0x6C76D0090FA760ACULL, 0x39CB61371834ECE7ULL, 0x6EBDF5B20EBA4B16ULL, 0xA3403AB5DE759F44ULL, 
            0xDF8E5F77E5288A7AULL, 0xD0C51BB3C32F756FULL, 0x19998FF636C77632ULL, 0xAED7F56BA6FAD92CULL, 
            0xF939E6456EA81FDEULL, 0x6DDEE64D2EC75117ULL, 0x7A170FF27CEC6684ULL, 0xBD3F2002B13BE8D3ULL, 
            0x00847788B573246CULL, 0x614F955EA3BB5407ULL, 0x45A68297B86F4837ULL, 0x3E3107229EB4C7E1ULL, 
            0x1109FFF5FF9B21D8ULL, 0x9FC6F5412CC0E94FULL, 0xD1A857D9C6DF6826ULL, 0x61FA26F66072C596ULL, 
            0xCB49BFBA8A0F00D0ULL, 0x71AE58B188604397ULL, 0x0C70A3A3C26FEA03ULL, 0x98356766DE532819ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseAConstants = {
    0xFB9ABBC39056D9D6ULL,
    0x24D82FA7ABDC3169ULL,
    0x449BBD470C19E4A8ULL,
    0xFB9ABBC39056D9D6ULL,
    0x24D82FA7ABDC3169ULL,
    0x449BBD470C19E4A8ULL,
    0x9317B36463CD359EULL,
    0x613F7F603060A60DULL,
    0x65,
    0xF6,
    0x9A,
    0x56,
    0x7A,
    0xA2,
    0x10,
    0x0C
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseBSalts = {
    {
        {
            0x4130A2E719B4D7EAULL, 0xA1DCCDB06BD1F8A8ULL, 0x7C858D46BA4D4D08ULL, 0x861B4A23D24B3B67ULL, 
            0xA282434EBF7DB5B2ULL, 0x68BC9E5C9E95A08FULL, 0xC9B847EDB0C4853BULL, 0x1CB9D6B07E85CE9AULL, 
            0x4AFC532B067598DBULL, 0x195E82EAA0BBCCA2ULL, 0x158D0DB129EE717FULL, 0x5806AE2D87E39916ULL, 
            0x9D94DC4BE02DEFC6ULL, 0xE51B7D403C3E8B06ULL, 0x1D03EA224ED9D69FULL, 0xFBAC5367D1FCDAA8ULL, 
            0x9D279FB67DA8E1D3ULL, 0x15689600CACB5004ULL, 0x52E202FE11785443ULL, 0xB3E285832E5A4F70ULL, 
            0x8F7CB79C4D570973ULL, 0x34CDCEFE59CE5CB6ULL, 0x7D4C4C13E873EA5FULL, 0xD8804C7FB0994E0BULL, 
            0x533B333463164A0BULL, 0x47F88B1289F25C17ULL, 0x6FB6A4A9C7B43CF3ULL, 0xCA14708B116E150AULL, 
            0x16E654C10529D8FAULL, 0xA2AD6B5D5B280EA0ULL, 0xC2236ADEB0A08C4EULL, 0x83C18A29A4010379ULL
        },
        {
            0x9D12ABBDE5A2A579ULL, 0xB2BC6C37EF29E786ULL, 0xEA9D623E9DB17F66ULL, 0x9EB1697AE69A89C4ULL, 
            0x50E215E854E4390AULL, 0x078923D89A2FB929ULL, 0x8F1A409B07E0CCBDULL, 0xDF9A914BFAC2FE8DULL, 
            0xE856442C1D408C1AULL, 0xAE768866BD4A6A99ULL, 0xCFD88A0B80BB063CULL, 0xFA9EC3041740EB39ULL, 
            0xADA9649C3A707106ULL, 0xDC40DA9991BBDAFDULL, 0xE2B816E5ADEC72ECULL, 0xA4E71E0CAD810D89ULL, 
            0x3CC024D6D0B3BCFAULL, 0x33A55580955BF801ULL, 0x205A233BE748A71CULL, 0xB189A530C26806E8ULL, 
            0x05820933CCD9E212ULL, 0xD1248CDB9BDEFC07ULL, 0xB4A516A13DBACB18ULL, 0xD2065CA7D7D59BAAULL, 
            0x3AA7CBEA66A583FDULL, 0xC1E7938CCA6FF75BULL, 0x4526185471580DE7ULL, 0xE6EE9A0727841383ULL, 
            0xD2C274D162550786ULL, 0xE2200AC0D5CA3EBAULL, 0x78A1347E593E4353ULL, 0x89C70C7965B5E3E6ULL
        },
        {
            0xBAE6A433EBCC6238ULL, 0x5CA2B76DBE94D62CULL, 0x201517C8B0907C22ULL, 0x0C11B5BB25B39169ULL, 
            0x18F5F19971305D42ULL, 0x30C6E8CCAAC50D38ULL, 0x1AFDFD1921422C1CULL, 0x21ACF95FA681F11FULL, 
            0x6DD5A02657EBF2E8ULL, 0x49AA38E5A5B6E440ULL, 0x136BCAA13A97E46BULL, 0xC28A9A37B4F534E0ULL, 
            0x32DD494DBF49842CULL, 0x8D4BDB21BF2BD6F1ULL, 0xDC03670C9B1652F4ULL, 0x7280C1FBD0B916CEULL, 
            0xF1185AD85DB34CC3ULL, 0xBF8168793A52C7B5ULL, 0x12C8E2D7FF178416ULL, 0x057BC0E7AF72B4D1ULL, 
            0x2D3687F343DF5034ULL, 0x7FE2C4908A872516ULL, 0x1232CE0557DEC6E9ULL, 0xA8C40B41B0587B7AULL, 
            0xD0C3A646444186CEULL, 0x042B6ED47F030505ULL, 0x5B4E2229C50E54A5ULL, 0xEC0C06BBDB204991ULL, 
            0x2A8FA23147145974ULL, 0xD3D224BAF47DFD81ULL, 0x19863611C7BEFCB0ULL, 0x18517AD59EBEFDAFULL
        },
        {
            0x6225E99F5BE0AC5FULL, 0x7E930113626DFE41ULL, 0xE261B4586BF5CA87ULL, 0x671E64326AE9BF75ULL, 
            0xC176E3DDA3FAF112ULL, 0x2409EB6E75A9C0DEULL, 0x86CD08938FB5144EULL, 0x59BA1DBB9C83F478ULL, 
            0x48A50AA83A1F34E5ULL, 0x102C82AB2966E2A1ULL, 0x8CB38EA7584DA937ULL, 0x98CBACECD6B93C52ULL, 
            0xFB41EE0B0E75AD99ULL, 0xF12724BA55A78AF8ULL, 0xB845E5538BCD969EULL, 0x5E09456D8C9ECE99ULL, 
            0xA1944DCEA063C90FULL, 0x09EC7717168807DFULL, 0x802EAAE6FAE25F12ULL, 0xACE11C8B68D786C1ULL, 
            0x5127DAFC6046C8B2ULL, 0x84D0BB47998DBA7AULL, 0x19B58ABA223D2A21ULL, 0x2A0C262DB790B214ULL, 
            0xBB23E5414859ED1DULL, 0xB9B1D07239887C1DULL, 0x86D041A479C66732ULL, 0x7BF6EDA40CA62D60ULL, 
            0x1BE3FD31FE440E7EULL, 0x55DD1233F16422DFULL, 0x621AE644D7D36065ULL, 0x8567B468878FDC03ULL
        },
        {
            0xDEA487CFC3ACE96EULL, 0x8261632C032ED1CAULL, 0xFD10B0FB9EC5538DULL, 0x0306E543343E9D02ULL, 
            0x767AC5564CD390A6ULL, 0x5278EFDB317E2E4FULL, 0x356C377B5AB455D2ULL, 0x66CC6165D036A394ULL, 
            0xA9DB5240507AD592ULL, 0xABBBED27F51933F6ULL, 0x029AB4B0239813E8ULL, 0x76BFB6C6926B84EBULL, 
            0x6B0CC23465E8B607ULL, 0x69F03ED4A5D74DD4ULL, 0x3C12E3311536B854ULL, 0x0414020234FFB544ULL, 
            0x63664CB083FCE2F6ULL, 0x554B95B14552D61BULL, 0x876A8CC9CE7C4994ULL, 0x48DC7F946359FCD3ULL, 
            0x027D5EE98145218BULL, 0x50B645A06C87E5CFULL, 0x0AE0A149C2758A83ULL, 0x5D82D3778DD942B7ULL, 
            0xB80B275704A0C921ULL, 0xAEA17ED30CB22FDCULL, 0x6B1E68F9CFD5232CULL, 0xF74F71B10B1074DBULL, 
            0x4C39AFC6D1260C91ULL, 0x6E13CBF723229A6AULL, 0x93E8ED8590C31717ULL, 0xADBCB0E80F0CC404ULL
        },
        {
            0x2A42F882734B0793ULL, 0x7173BA94D9DB7148ULL, 0x2CB738D32EFB6211ULL, 0x5745A7C0D93A10B1ULL, 
            0xB5632CFECE3C9030ULL, 0x48BFF1F9EA9423CCULL, 0x9095C9FDE2D82FD5ULL, 0xD0D640901B508EF7ULL, 
            0x8214F1507C342C0EULL, 0x62151CA2C5555BB4ULL, 0xD71531F796D65CFFULL, 0xBA7815D9EEE56225ULL, 
            0xC1B3EA33DE2846DDULL, 0x9CB1B33CDCBEE7E1ULL, 0x9B521BF312F6A956ULL, 0x4A6D3E6E02BC67A9ULL, 
            0xFCCEF937F7697F29ULL, 0x60E221228BB2AACCULL, 0xD53D2EEBA9EB60A0ULL, 0xA0EC58179E012DA7ULL, 
            0x4C4AF9D78735D678ULL, 0x25CF9D79B3182444ULL, 0xDABE0906589AEE54ULL, 0x33DA2D27433ED205ULL, 
            0x8E4471254A483487ULL, 0xD20B0510DE3E9B36ULL, 0x5F60133B1B8FAC55ULL, 0x269CD24E63E65619ULL, 
            0x553E847F38EE0EE8ULL, 0x68BB8B50D288DAFBULL, 0xB3B072BEC5582BE3ULL, 0x1CB7181C5D7DE4A9ULL
        }
    },
    {
        {
            0xB0D58FA5B5149B40ULL, 0x54A17C9FBDD3AED7ULL, 0x78452DADA87EB70DULL, 0x497849E54EB6D234ULL, 
            0xA0CAFD493E060DDAULL, 0xDE9D8C1CFD4A5C2AULL, 0x7CA27F5C98DD094EULL, 0xDE9E81AA51401DB3ULL, 
            0xB66E751140047BC6ULL, 0xED55D8F29FFFF8DEULL, 0xB5C7C721A7EA2D2EULL, 0xC293401F1073E25CULL, 
            0x3BD744945F5FA0EEULL, 0xABA89A8EB06F70D0ULL, 0xFE0ACC1032CEF246ULL, 0xA16C050C4AB4FD1AULL, 
            0xEAB068BEA304BC47ULL, 0xE1158BE25DC5388EULL, 0xEB1AC0B535B3E6BDULL, 0xD0F6C5C494C1360CULL, 
            0xC7F8B19E772A8161ULL, 0x9549AD17718B0B80ULL, 0x7A10C9C5219FC42BULL, 0x4BED8ECB3D72A82AULL, 
            0x214C6F525C30BB0BULL, 0x7513D24C17FA9203ULL, 0x44C645F1A88B95B9ULL, 0x65D4B240E4BF467FULL, 
            0x372581DE642A685FULL, 0xD96C92E5B88981D0ULL, 0x64395CF5C60C643BULL, 0x0530EF07FD390C69ULL
        },
        {
            0xDAE2A709752BCF09ULL, 0x7219947092715AABULL, 0x890E7E464F8F5808ULL, 0x38F60E678BCC1D60ULL, 
            0x49AC522AA573A76FULL, 0x219D31AF94A5AD1AULL, 0xB979BDDBAA4F467BULL, 0x36EF1930E829EC9DULL, 
            0xA121C3BD406C39BEULL, 0xD917FB39119A4A2DULL, 0x6B549197FE60B067ULL, 0xDB394171EF886671ULL, 
            0x989890BA4FF6A5DDULL, 0x531934C443C45D18ULL, 0xDC3813E365E1631FULL, 0x6F1A4B8D39BF0AC1ULL, 
            0x4EEDA9D217E40BA1ULL, 0x1580744D404F659DULL, 0xF1197E128CCFD1A4ULL, 0x53AE039CCDFB8313ULL, 
            0x302B944282D5F238ULL, 0xDF7CB6C3703B03A0ULL, 0x494255194C570B7CULL, 0x2CBD4193263779DBULL, 
            0xDF5C5E2F3C3BCC17ULL, 0x397709C058C8CEF7ULL, 0xE5CE2157F7FAD5FAULL, 0x3511F5914F722A7EULL, 
            0x582DBBEA14DE29C2ULL, 0xA22A6ACE9B8DCE82ULL, 0x3691B3F48B8E1841ULL, 0xB5C3A70C33B5E44BULL
        },
        {
            0x78FB77880681E8D8ULL, 0xBFC6AF0C71747C39ULL, 0x642F24AD4AAA0047ULL, 0x9CD88E3D5AE4E209ULL, 
            0x559C44D900F522D9ULL, 0x6532B203497686B6ULL, 0x54CEB76CF17BD71DULL, 0x7688E30CDB01E2B9ULL, 
            0xA7C84E101A600D44ULL, 0x46FB8488196AC751ULL, 0x4CCDFEC6A405E8BCULL, 0x31BF0350C272EFD6ULL, 
            0xFE6C617B33140F2EULL, 0x4DB2CD93448F8E89ULL, 0xAF925A0726379A5EULL, 0xA9B97B242921D627ULL, 
            0x9B1C6773C257F2DAULL, 0x1EE1264F477AE83FULL, 0x831F1B5E74685095ULL, 0xF28C43222CF4C349ULL, 
            0xBA528751CC22D0B0ULL, 0xDEDDD56A43AAA66BULL, 0x43C2F722513B9DA4ULL, 0x155209F9E9AA611EULL, 
            0x69EA1615B1B85851ULL, 0x424150C5E133FBC1ULL, 0x31DEB983EB7930F6ULL, 0xD6292950FA3BF3A4ULL, 
            0x8B14571F8F7DE68FULL, 0x290E0403738FC160ULL, 0x6E0C0AB401239809ULL, 0xFDEC0212783A2171ULL
        },
        {
            0x6A7ED9DF47C91200ULL, 0x92129206E736AA31ULL, 0x26E023B00CD26368ULL, 0xE3ADEA10F475B6ACULL, 
            0x7BEB03DAE74303D4ULL, 0xFF499A3A708B492BULL, 0x8C6771B54813C1AFULL, 0x9430CB15951D9275ULL, 
            0x39915BAC80600549ULL, 0x9515CBF7EB3AB0A7ULL, 0xDCA5A2FFDACB3221ULL, 0x0D1F9B5008268903ULL, 
            0x66C3DB6A758F3DE5ULL, 0xB61F1F04C81D74AEULL, 0x28E56124F18F4C23ULL, 0xA2F460DBFE78E8A9ULL, 
            0xCCD052C59990CCBBULL, 0xC5017A5975B7B63AULL, 0x78D19EA30484171EULL, 0x3550BBDDBBE83119ULL, 
            0x19AB4D11C4EAB00CULL, 0xBC0AA5D248F848DBULL, 0x08849FBBAA040118ULL, 0x520B516BDB295D05ULL, 
            0x98CED31009ACA457ULL, 0x12050099CE64389BULL, 0x50779E5A9748ACC3ULL, 0x9E20B177DCC11C67ULL, 
            0x7E5CE02DA30489CCULL, 0xF07F476ACBD09CDFULL, 0xDB55632577325C16ULL, 0x3F518D076B102330ULL
        },
        {
            0x7514B3E9ABF33547ULL, 0x545E602E863C65B4ULL, 0x62A56F0265B289FEULL, 0x46CE6F7995CE3255ULL, 
            0x707BDD490B7CCB0EULL, 0xC2615DB8370813ADULL, 0x9CB7E95F50F7D4C5ULL, 0xF77E4B7226FC3F10ULL, 
            0x02A115562268B2F1ULL, 0xA76913D710CEF943ULL, 0xB4D3937DC8E58AFBULL, 0x8D5665635EC19862ULL, 
            0x934027D1AAFD5E01ULL, 0xF2484A0FB78725C8ULL, 0x607968D6A27AC36BULL, 0xCCF36143871B5849ULL, 
            0x5EB0F9967F5F4F79ULL, 0x9496E96C46EAF2BCULL, 0x4B27F6A5D28ADD4FULL, 0xACEEC3F1BA25BC8FULL, 
            0x4D5919293993BED0ULL, 0x9AA9DABBF31644CAULL, 0x4041CA1A981C0184ULL, 0xD90AF1C7E602E062ULL, 
            0x6562814F9B4EFDF9ULL, 0xD6A682F598C5C03FULL, 0x357AE818F9FA1FE7ULL, 0x054B40999D32A715ULL, 
            0xACDB7B3B612BCF33ULL, 0xBBDC31D8CF8389A4ULL, 0x111F8D8586C2183DULL, 0x8B9B044D736C38B7ULL
        },
        {
            0x391061E992448D6EULL, 0x1A51AB96B6FE658DULL, 0x4CC1F191CEB79B51ULL, 0x97727575B21B530AULL, 
            0xBFE54347546BC287ULL, 0xAD6358416B67A3FFULL, 0x85DF3860B82943CFULL, 0xFCA9CD7356C26C4AULL, 
            0x59E05DFB509C0C6CULL, 0x16D403F1471F2BB4ULL, 0x4E216D9761310B98ULL, 0x23C24D9D1D0CE2D0ULL, 
            0xB7749253866B7D75ULL, 0xE58A44DCDB36CDA8ULL, 0xFA9AFEA00DDBEB9DULL, 0x403866A87F8DF68EULL, 
            0x75A7E3B33C04341DULL, 0x130886CC5EB909D0ULL, 0x48040A21D833B36DULL, 0x8AB63E1E2BC8D931ULL, 
            0x1D55702E0B5121C2ULL, 0x6BFD86A1CFCD9BB5ULL, 0x9217E8DFC73F5F00ULL, 0xFB5BD848D0D5B2FCULL, 
            0x8EAA9277D16F3197ULL, 0x08439C79870356A2ULL, 0xD9C86FCB79F2DACBULL, 0x25CD7BFD469AD5DBULL, 
            0x38CBA18B28CC1573ULL, 0x1B78813EE0CE70C6ULL, 0xF5ABA7F993C11AD7ULL, 0x954C81126163DC35ULL
        }
    },
    {
        {
            0xBBE7CBCCAF73E953ULL, 0xD015EDBBB51C3787ULL, 0x1DADD0EC612972A5ULL, 0xADAE9B3945FBA04EULL, 
            0xED9273C8140F9C75ULL, 0xB7F257B8BD5BB2E5ULL, 0x7A785D7C6687ACDEULL, 0x4B8F00415CEB53D4ULL, 
            0x3BE2914BA1085458ULL, 0x15A68D48BFDCF155ULL, 0x2D6D1F971FAFC5A4ULL, 0x2C4D367418AB3E4AULL, 
            0xAD9CBC5B7228E38FULL, 0x538BA4EA6BFF0294ULL, 0x88E887445D2D17A3ULL, 0xC05785DF8533160CULL, 
            0xDA812036D9EA7DE6ULL, 0xDE032DE14C9A071EULL, 0xA61F806311411136ULL, 0x06865968C9766CF1ULL, 
            0xA71B02DE5BA301B3ULL, 0xB06561802880F72AULL, 0xAEF34763DAEB7DD8ULL, 0x7A9DC1B61B4DD9CAULL, 
            0x67477DF1F655F1A7ULL, 0xF2DF4FDB459366B2ULL, 0x95766C6617AD2569ULL, 0xC73EC66FEB2AAD16ULL, 
            0x003ABC0C2A462C20ULL, 0x80A030C6D935C27FULL, 0xFC8D945778BFCFE7ULL, 0xAC9F3FF0E5CB2F18ULL
        },
        {
            0xE695ED9597E4FC42ULL, 0x6088B196BF18C2C2ULL, 0x35D2A2F2FC13C564ULL, 0xA1322ECCF273415EULL, 
            0xF57607AE65B6723BULL, 0xF94B9AF0FAC877EFULL, 0xE563016DD8EE336CULL, 0xFB1A934DAF430853ULL, 
            0x09775174F37198DCULL, 0xEB9580C4A7DC502FULL, 0x97D5B8127752ED2DULL, 0x7B797429F9C5E742ULL, 
            0x6BCEB69875BFC646ULL, 0x554151A57AB6019CULL, 0xDA91A91EDF20550DULL, 0xD40C6CB7FEF9856DULL, 
            0x5B72DC386B3849A0ULL, 0xB7AE9A0F5F7DA575ULL, 0x673408243C0C251BULL, 0x4CC2DD6E60A9CA6CULL, 
            0x7B8D32159B686846ULL, 0x5B2A4243C0C6D296ULL, 0x7CB65104D72A71A5ULL, 0x3022563FB4BF1C29ULL, 
            0xD9E08DA73BA5E99DULL, 0x3A27F8029FAD2715ULL, 0xE7269B302DAD65F3ULL, 0xE00C8A9BD96DD371ULL, 
            0x77F7DB3E82137D95ULL, 0x25E130E4AEB156FFULL, 0x84175E9FAD0C0F08ULL, 0x36B1129259E5BE7FULL
        },
        {
            0xA30E2D9B4C58C116ULL, 0x0F23ED6840A2B936ULL, 0xC13176814BF22B18ULL, 0x8E687F7569592611ULL, 
            0xE2EC554FFF53819FULL, 0x9A11CDE0C8E40839ULL, 0x185A30595BAE0FAEULL, 0x99CAD04EF19A97C2ULL, 
            0xA75643EC9ABBEC62ULL, 0xF964FE35B08773F4ULL, 0xDB3252B8495AC149ULL, 0x94A6EB5D1E285778ULL, 
            0x7C37E443039074FAULL, 0xCBC20CBDAA57EBA6ULL, 0x72EE6DB3F36D4C2BULL, 0xE4D4668B6E464934ULL, 
            0xAAAB890902087FB6ULL, 0x38A2D9E2286CDCDEULL, 0xFB65ABD4528934F1ULL, 0xABF12C371161C762ULL, 
            0xB2EAEEC5D747D71EULL, 0x2A7F1F5BDABF3B70ULL, 0x6E9F274EBB9CD6ABULL, 0xD66798B7D9F6FFB8ULL, 
            0x6905C45F77144E61ULL, 0x475CF0340A1AC92EULL, 0xD0746560D9A1D5C0ULL, 0x6309297DF03DC8F2ULL, 
            0xF34CB9C493A578D8ULL, 0xDF44E8556DB4BB3DULL, 0x472B932E634B3876ULL, 0x8BD58AB3511E0D4CULL
        },
        {
            0xD4C1542450376320ULL, 0xEBE0D04C5361BEB2ULL, 0xE2624083F0EAE9E2ULL, 0x5820030165C35D7DULL, 
            0x2EB02F6A423918A3ULL, 0x69595C1AFADB3F94ULL, 0x6A19F53D21CB7ABDULL, 0x70160B612BA63D23ULL, 
            0xF46CB3CD988E20CCULL, 0xA3FA706C6124DAC8ULL, 0xAD2497BA487B283DULL, 0xCFEC57F08D4B9F28ULL, 
            0xD5B1C00C91E60FE2ULL, 0x0FA756618F36F9D5ULL, 0xDF5321E8C86D7305ULL, 0x27FA76AD9676C34DULL, 
            0xBFDAF741A52743F2ULL, 0xE93C02F9BBCD9E94ULL, 0x04C4D0601212C0ADULL, 0xC64ACE26E827C34FULL, 
            0xF994ADBF50ED0B9DULL, 0xD0C80E45B7725F03ULL, 0x9FA2BBAB037017B2ULL, 0x65C53075C68D9F95ULL, 
            0xEE62BCE137C9A29DULL, 0xFEB86FD2DBF0242FULL, 0x9004B4DDEFDD0637ULL, 0xA39A75C2B96A7844ULL, 
            0x5B7827C31376F682ULL, 0xD1F19A93DA469A59ULL, 0x30AD87A5857ABDF1ULL, 0xA3A5D784BCEC0BCFULL
        },
        {
            0x004D7E4F5AB10102ULL, 0xFB0873C52CA026B3ULL, 0xB5DD919D1838B60AULL, 0x712375452E79F3FEULL, 
            0x9A20E550692917C7ULL, 0xE849117F8B8EEC92ULL, 0x2992FE2B2AEDD728ULL, 0x2A8BB63E77E509B7ULL, 
            0xF0620840B4BFF5C4ULL, 0x8CE34F4A2F8A2ABFULL, 0xEDE69AFA80B0C15CULL, 0x226C7C0848B17AFFULL, 
            0xDC2C2094938CF0ADULL, 0xFF9F62773881B954ULL, 0x15558218B2ED94FEULL, 0x27688D20A401E0E7ULL, 
            0x0D0F6350F54E57FBULL, 0x0CD2499ED35D5C27ULL, 0x1E4639C40BD1B5C6ULL, 0x666F621BDFBA0595ULL, 
            0x1B5DA940E126E436ULL, 0x94305EB5466E7292ULL, 0xCE763602D88DD6A1ULL, 0x6CD2747651BD2140ULL, 
            0x072FC15917A6FB5DULL, 0x2D0CB53879E183B8ULL, 0xE8A39B24E72E73B5ULL, 0x3B071CAF75A84A0FULL, 
            0xB93166BB80956F17ULL, 0x52F600DF12944469ULL, 0xD9CDBBF81A0DAD20ULL, 0xC61999D3B424C5BBULL
        },
        {
            0xF154B377646706B2ULL, 0x3BAF8FF092686DC3ULL, 0x4636DF3C9654D0ADULL, 0x775E1E316121C58AULL, 
            0xACDFC09C541CEDCCULL, 0x04F7014497455B41ULL, 0x59AB940333814F5EULL, 0x566CAB03EEDD2815ULL, 
            0x93C6CA1FD94EBEB8ULL, 0x30612507CEE542C9ULL, 0xDBCAA859C0352362ULL, 0xA205FD8A81ACD0CDULL, 
            0x16DE1BFDD9D6A480ULL, 0xD84C1B611E368FB3ULL, 0x7C8E985D5661AA2FULL, 0xA891B1BB6846E940ULL, 
            0xB7E29BAB62F4C24DULL, 0x41C01374604D5E58ULL, 0x7754D69CA58E4654ULL, 0x621F6DC525BA6596ULL, 
            0x48079B34EE6E6371ULL, 0xF2CA59FCC26EC715ULL, 0x4A98163A5082BD24ULL, 0x69544BAC4A3039D2ULL, 
            0xA404E184D5AB7BD4ULL, 0xDC233A90BDFFFC28ULL, 0xA83C203929A2DB38ULL, 0xF6414D8A1E23D8AFULL, 
            0xEEAAD84E7581E4ACULL, 0x4E501B4D661F9789ULL, 0xF660BD364BA1B4EBULL, 0x53CC45F7DFFA374AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseBConstants = {
    0x14CE0F0C3EB290F9ULL,
    0x82046722DDF1864CULL,
    0xBA95D76C93D32B1BULL,
    0x14CE0F0C3EB290F9ULL,
    0x82046722DDF1864CULL,
    0xBA95D76C93D32B1BULL,
    0xF2E9BDB98CDD655EULL,
    0xA8E13C2F31D4C1F5ULL,
    0x6A,
    0xBA,
    0xD1,
    0x63,
    0xEC,
    0xD3,
    0xE7,
    0x69
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseCSalts = {
    {
        {
            0x58328C3F674E431CULL, 0x1298E10F20888117ULL, 0xD3A4F7730052BF76ULL, 0x854896FE8DD5ED17ULL, 
            0x57B13774362B8F2BULL, 0x588554D3A43EEA7AULL, 0x9FE1E36B4040C0B4ULL, 0x44471C29C7EC8C78ULL, 
            0xD4559D08F62A8244ULL, 0xD29A4E8E9998CDB4ULL, 0x87358282FFE4F99FULL, 0xE78A3A5305E85A51ULL, 
            0xD92C50EDBEB56385ULL, 0xE49292522DC2C98CULL, 0x16997A622A13FF2AULL, 0xAD88D7A8D3EFFAC2ULL, 
            0xC92120255F8AC24CULL, 0x9E5016DE98904A0BULL, 0xCB9BB0320DE30029ULL, 0xD74549BF2322EFCFULL, 
            0xFB2AAFFD8AE0A18FULL, 0x34694B5FBAEFF9CDULL, 0x6D653731173F7994ULL, 0x500A65581C372D3AULL, 
            0xE92B3BAF6E7206B0ULL, 0x91A2770CD531575AULL, 0x49F3A682CA82C5ADULL, 0xD2F38BE957114ED0ULL, 
            0x04645D17B5269792ULL, 0x73832C106184E6FEULL, 0xD89C32CAFBC80D41ULL, 0xF739798B89CD7E83ULL
        },
        {
            0x4FA0117B5D79AC32ULL, 0xE6206997FE0BD5BBULL, 0x15EA44E17DB0F318ULL, 0x4AA74F103A4FD5ECULL, 
            0x78B281758CDB77CCULL, 0x32A8A19CBEF10D8CULL, 0x348F470B74DDB15EULL, 0xA7585E0DC37B9FCCULL, 
            0xCA3C7AA7457F27FAULL, 0x4C2F897BD7307E2FULL, 0xFFA620E82DEF9C17ULL, 0x6E74D87650725073ULL, 
            0x2BD82DBCB2F17084ULL, 0x0F6AD93542ACAC96ULL, 0xD7651B1988442CB4ULL, 0xA0903DE70CF4BAA9ULL, 
            0xC635D1DD5ADF68FBULL, 0x0246E75228A5FFF6ULL, 0x4BB3F2B14B9FB965ULL, 0x641ECA8F66D44CCFULL, 
            0x5C02F6E331B317ACULL, 0xF9DF3CAD7FC02C79ULL, 0xCFD8EC894BBA47C3ULL, 0xDE64A1E05AAB54B9ULL, 
            0x0B0DDB571FEBC4ACULL, 0x2EBB29974D09BEA9ULL, 0x426D3F68E6D56FFFULL, 0xA4EAFCFFB2848B29ULL, 
            0xFDF786BDA5AF9290ULL, 0x9F0D9D8568A7ECBAULL, 0x55CE5638CEEF7F80ULL, 0x39C191A71CCB8517ULL
        },
        {
            0x39D971E50461E8A5ULL, 0x192B07374995EDBEULL, 0x2B6109262F62CCEEULL, 0xA985AD37D18332F7ULL, 
            0x7A3DED55D9D8762DULL, 0x04AC789CBE853EACULL, 0x2FF422309B355F9BULL, 0xCABBB4EAEEC71AD5ULL, 
            0x9D4899A5B40B476DULL, 0x9CA4756E2A4119E6ULL, 0x3C917F5706CB50DFULL, 0xE6F198B03A08724AULL, 
            0xBDB87B32A58DADF5ULL, 0x9170152A7AC487D3ULL, 0x990CCB1FCCC7C56AULL, 0x7089F917968497DAULL, 
            0x743B65EF7E2B6C31ULL, 0xC6E24DB1AC0D7016ULL, 0xA05FE95C396EDCF5ULL, 0x2B3F67563D90F8DDULL, 
            0x9D0ED4239B864CB5ULL, 0xEBA7884055E2A3BCULL, 0x749A5073D5484DFEULL, 0x5EA4196759D3D163ULL, 
            0x7CB95A376D579120ULL, 0x5930F51FBBC104B3ULL, 0xE4173C34914E0616ULL, 0x159637C3FC542DFBULL, 
            0x65038AAA66C4D097ULL, 0xB7E945D098D0A4E1ULL, 0xBC6029A5B6547F5FULL, 0x5777C427546A6BF2ULL
        },
        {
            0xC1A0FA758340D6AEULL, 0x0FF8B75AD5E69AA1ULL, 0x02ED98C5D81C225BULL, 0xB195595B9B0A5F2FULL, 
            0x35C58711C2CF17B2ULL, 0x4213D36B4020BBCEULL, 0xEFEB3A7F675977F3ULL, 0xC8E62325B0C6F92EULL, 
            0x785BFF02F82EE1D7ULL, 0x8F4C723463413D74ULL, 0xB0D6B863A2B84CA5ULL, 0x260C3A4EAFC1CD9CULL, 
            0x27000C5695DFF451ULL, 0x8E25CC5ED66F8BF7ULL, 0x71C26D8767377F84ULL, 0x488459467D0AA28FULL, 
            0xBFA7D49DFD4C961EULL, 0x87596AA0848FA823ULL, 0x022B968D2C5CEC2FULL, 0xA05B479CE8834E29ULL, 
            0x477FA3AB45C59C4EULL, 0x95F93972B2F38916ULL, 0x360CC1BF96033610ULL, 0x47B1AF17F96AA05CULL, 
            0xBF78CD85AF100223ULL, 0xCA3B04A10C914861ULL, 0xE5214AD7A4DD98A8ULL, 0x9F818B18861FA847ULL, 
            0xB2731F8228CE6024ULL, 0x13FDCD1DD470F69FULL, 0x97371944AB68C2F5ULL, 0x0B8EACBD800D4F91ULL
        },
        {
            0x148F57E4A2006EE2ULL, 0x8504579A6CBA6D70ULL, 0x84A3BC047D1E1F0FULL, 0x38B00F48580BF2D9ULL, 
            0x4AADAFE817E13689ULL, 0x2B8FECB327109563ULL, 0xE78860D9E1EE1E35ULL, 0xC9B9D889E9EE5104ULL, 
            0x3313CFF59899473CULL, 0x6842F4CBF266E263ULL, 0xE72B5B188696A134ULL, 0x60E9A28B4B1371BEULL, 
            0xBF8D0EB416091835ULL, 0x1A8B8A850BB9119FULL, 0x5D204CD20FD4CDEFULL, 0x6DDA28DE2E9B4A3EULL, 
            0x4E8C29C4BADBAFC5ULL, 0x67E6BC9F73C5EF68ULL, 0x54303058C54B82CEULL, 0xF877DC362AC41811ULL, 
            0xE3C818AD007C4896ULL, 0x10E7AAA0B7115184ULL, 0x50A18AD4BEA600C0ULL, 0x238030F566752203ULL, 
            0xE22F03B87EB1422EULL, 0x6E964B319D7D8C2AULL, 0xE89F4652BF21C131ULL, 0x0AD4B267EC9902FCULL, 
            0x032BD23D9865065DULL, 0x59106C343CD4C9C0ULL, 0xB60A4C02D21027EFULL, 0x86D5D29DA6F49126ULL
        },
        {
            0x1453F6D821BA71F2ULL, 0x2D451C08A9CE03FBULL, 0xBCE21636E47308ABULL, 0x5DC93033215AB708ULL, 
            0xA83D440BB23E0A94ULL, 0xED7D2B5DB43E060DULL, 0xBEA3F8DB0CC854CDULL, 0xD2294887873A14FDULL, 
            0x26D5DA2D426221ECULL, 0x59A69286EA8E186AULL, 0xE8034A5AF8D27C33ULL, 0x007A185041245446ULL, 
            0x6C42B33D5473A0E1ULL, 0xCA5B55398A2D4A52ULL, 0x66967A789A3433EBULL, 0x599820361B9C95F1ULL, 
            0x8646C69F362A9F63ULL, 0x5E25CE0A46C18F11ULL, 0x6D0D15B21C2A961FULL, 0xD2E08A45280194C8ULL, 
            0xA8BCEC978FC7B828ULL, 0x44A926005AC52198ULL, 0xBB7F93D508D59A9DULL, 0x90231C1197504101ULL, 
            0x9E907687DBB5FD3FULL, 0x66D809A261215882ULL, 0x2C6BB725F3425570ULL, 0xFAE3CC0DC71BAAFFULL, 
            0xA7CD3C8EA8B11917ULL, 0x78948F07A6CA440DULL, 0xDE0C0D5EB7BDF31FULL, 0x20BE008EA3AF5159ULL
        }
    },
    {
        {
            0x66F0E9A2B9D3FD16ULL, 0x9127EA212F4F6029ULL, 0xDC93117227A95C8BULL, 0xAAAC363B9EEA3FD5ULL, 
            0xE9512DC55BAEB8DFULL, 0xB24E45FCB29DE1CCULL, 0x2DECA364FB646498ULL, 0x796AFC5D6A439806ULL, 
            0x7BAD19D6AEEA8AC1ULL, 0x514EFBB314B109A5ULL, 0xB30529164C6D4D80ULL, 0xCB0E5416AD6F50E7ULL, 
            0xBFC7509CE491BDA8ULL, 0xAEB68DEF2ECF6EECULL, 0x0F6B5265CA09B4E0ULL, 0xD8596A0309579E67ULL, 
            0x5AB2F9DFD49A2D56ULL, 0x45E2623A893BA318ULL, 0x96AA13DBA0890BB7ULL, 0x7DDEF2DD62D02880ULL, 
            0x2D0A7D0DA1C5E996ULL, 0xDB486FF88B1B95B5ULL, 0xE9438127EA738385ULL, 0x0F52AD0BCB4C56C4ULL, 
            0x0152E7EF12890FBCULL, 0x5D925F47A1C6D0E1ULL, 0x818D1051B2C20402ULL, 0x1E54ED1B12DF778EULL, 
            0xF50F95EF07F5E0FDULL, 0xD34BC9472DB933A0ULL, 0xD1BACF4FB7287579ULL, 0xC01EB65353140630ULL
        },
        {
            0xAD09186642045F3DULL, 0x71A7BAB1E4BADC65ULL, 0x14C026681E944A08ULL, 0xF91A3AA44DD3C756ULL, 
            0x4A6B32D4423A39E1ULL, 0xE3C55830FD168612ULL, 0xA9F7A5AC0652E447ULL, 0x73493795465CAE0FULL, 
            0x1AAD639970529990ULL, 0xD34F1948A8740387ULL, 0x49F9CA0D3023EC64ULL, 0x0A5A8FDDE8D9370AULL, 
            0x39A4C3F2D63854C1ULL, 0xB4A829A46CDED98DULL, 0xF70392A83EDFA8ACULL, 0x0C60D357CBAD9F0BULL, 
            0x1583CE02C1C3FFBAULL, 0x9E0CE7F933270D60ULL, 0x27D432F7D32A2C42ULL, 0x0F9BCE4DDCE3897DULL, 
            0x6F2FCC6C5F9A97E7ULL, 0x71262937C1859837ULL, 0x7B36F3C3662D802AULL, 0x4055D4AB055A6CCEULL, 
            0x5C7F34B7C4B27F8AULL, 0x9DF15AFF4632CF57ULL, 0x021D0148A85B44ECULL, 0x4C96C6FC53505E6DULL, 
            0xDD52DB43B50EEBAAULL, 0xFC2F109A1DB4EDF8ULL, 0xAFB487BCC8012989ULL, 0xAD84135115175CF6ULL
        },
        {
            0x486CAD3677C48364ULL, 0x9E0564AB2BA6FDF6ULL, 0x0562C2A8BB309E42ULL, 0x84692A361AB166ECULL, 
            0x90629F102372EEDBULL, 0x8ACABF12571DA7D6ULL, 0xCA9A966313B3ADA7ULL, 0xBB02B7C5FB8C0320ULL, 
            0x2C1EE9311633F92AULL, 0xB3006659C5C73D54ULL, 0x2B9F75A78080A793ULL, 0xBFD2FECC81961465ULL, 
            0x19C2E486AF2AB411ULL, 0xBEE74B9692F1A2DCULL, 0x35DA11CD0A50D6A0ULL, 0x3D12EDCE4D93A044ULL, 
            0xDEAB2D824977C3C9ULL, 0x026363FC681BC780ULL, 0xAE0748FE40226EC5ULL, 0x1DCF6DFE9204DBA4ULL, 
            0x0686FFE3F57A8B51ULL, 0x1293744563AEB91CULL, 0x3F4BC6E48E0BDC5EULL, 0x35966B123B2C3C34ULL, 
            0x5E5B48741D64A64EULL, 0xD4CA781B856344F0ULL, 0x5FACE1416D5F1C1EULL, 0x949FB538B6D9C554ULL, 
            0xE49AC67448267A35ULL, 0x01A6DA8193544EF7ULL, 0x7EF347E027133B77ULL, 0x56F505BACB26C283ULL
        },
        {
            0x3680BA0A0A25AED1ULL, 0x0E94F7ED378E93F8ULL, 0x5B29445905561061ULL, 0x1F0482E4E936D309ULL, 
            0x9B1D5B9393F2303CULL, 0x714D6788FD9EC8A8ULL, 0x33C54CC1DED476CBULL, 0xA2A4D9D232856B97ULL, 
            0xE952582C186B5AE2ULL, 0x030C0FDA160CD60DULL, 0x18A2C8E22F88AED0ULL, 0xF00F51D05D366541ULL, 
            0xDB7B9B59D1EE0E28ULL, 0xD87920105674B5FFULL, 0xB927E36382A4BE41ULL, 0x940AE820F546C537ULL, 
            0x111980663AC1E2D2ULL, 0xEB1CF95F26A9B6AFULL, 0xD3D49E1EAF5C64C6ULL, 0xF2BBF628E467FB5DULL, 
            0xC12FA53078ED48E9ULL, 0x599579E29D7395A3ULL, 0x7586BD95C30D19D2ULL, 0x16E6A6876D203B83ULL, 
            0x2CBEC8E375ECEF71ULL, 0xC82FFCDB2D92766AULL, 0xD499EF619199CDB2ULL, 0xAB68B18B75CFCEC6ULL, 
            0x56ABAD5C5C0710EAULL, 0xDA0B9A0580CB801AULL, 0x5862239AF571AF86ULL, 0x1C42F7BEA0EFF0F0ULL
        },
        {
            0xD10E237AC63B9C01ULL, 0xCE0BD52C1D500EF5ULL, 0x24528D457844CEE8ULL, 0xF4379FF24266D4D4ULL, 
            0x4C63B713AFE3B270ULL, 0xF4B9646687A7AC44ULL, 0x1AD7184F9FCEB801ULL, 0x05779C750826E5CDULL, 
            0xFBF4ACD073FA9AD3ULL, 0xF23EF574BF979038ULL, 0x60D0B78108553615ULL, 0xC8842F119588713FULL, 
            0xF3BC1247F1EE5723ULL, 0xE66EF444338E2CF0ULL, 0x19864C356B5E400DULL, 0x97DA32A97FC0E1ECULL, 
            0xF3EC0F601787A3CDULL, 0x1DC8F96945863BD3ULL, 0xB0BC0A987C5C029AULL, 0x1E00E11252DF8F8EULL, 
            0x7F2230065CB06829ULL, 0xDC1221EB6C14E7E7ULL, 0x4ABC623B6390BC65ULL, 0x262559C16262056EULL, 
            0x172B50172AEF09A6ULL, 0x1079E12426797B2BULL, 0xAF0169AC2BD2A258ULL, 0x6CD28ED37EDCF14FULL, 
            0xFE443C7D3E027718ULL, 0x05CECD7C17073220ULL, 0xC4F99A721A99C802ULL, 0x039769EEAEDC38FBULL
        },
        {
            0xE5FEC9D68DB47C2EULL, 0x2DA40C791D4A8CB2ULL, 0xAF6B964C1AEB38BBULL, 0x5B4AD4867DDFE372ULL, 
            0x9B85005EE25C6CDAULL, 0x719D82610A3CF4FFULL, 0xD7751A2CAD300CA5ULL, 0xD25EA425C08921B4ULL, 
            0x4F325B696E422BCCULL, 0x3A397A36BF1D1BD1ULL, 0x9D2D17397B7F2C3FULL, 0x2783C62126233629ULL, 
            0x09E8ADD8015525E7ULL, 0xEEC71E1F80B02292ULL, 0xEDEC8C0B60C88432ULL, 0xEE34B0E6CDD5A464ULL, 
            0x9AD96E0C92EDB25EULL, 0x690F1C8A954195C7ULL, 0xF904A585A272CEE8ULL, 0x1C322BB3B482C2A7ULL, 
            0xABB29969B8C74FC5ULL, 0xF2E963B55F6421F1ULL, 0x853395EC8E484ED4ULL, 0xDC1B547AAC80A9E3ULL, 
            0x93758F3302A2D66BULL, 0x3701B63DC3F0B725ULL, 0xE53758308964B8A3ULL, 0xED99A1DCCEF0C988ULL, 
            0xD6BBA875CB6B8B98ULL, 0xAA8BBBB89470DC09ULL, 0xB3BF8DE417767005ULL, 0xE68497B251630AADULL
        }
    },
    {
        {
            0x7A2DCD68F2D44815ULL, 0xF3723308B5BF6C54ULL, 0xFD5369E7DB9381FBULL, 0x0206E0F7CAC0B9B4ULL, 
            0xB1787349652879DDULL, 0x1AEB291AC3573BEAULL, 0xC64530CAD6E24C68ULL, 0xD3307253667CA3BCULL, 
            0x1BC4B8E5907D9B12ULL, 0xB77A1C2F2FF8FBADULL, 0x882693BB52750D73ULL, 0x96B9759FFDB6433AULL, 
            0xB55C5B7C35526C87ULL, 0x51B6C21D6D2D5CD8ULL, 0xB995C50205CE153EULL, 0x1129F8E007C1AF3BULL, 
            0x60ED6DAFFD5BE12EULL, 0x6366BA5FED7F01AFULL, 0xA7842169A9F957E6ULL, 0xAD6C80BD211708BDULL, 
            0x264F5E67AD862A0BULL, 0x5EC63D388AE99C17ULL, 0x6BF35F870BB2AC48ULL, 0xE125C183E22E06AEULL, 
            0x0D8611BEA70D5121ULL, 0xBF5BFBFC44FA05F9ULL, 0x08FA6E380FA9DA16ULL, 0x17DB07DD71440510ULL, 
            0x581DBE690B612DECULL, 0x0568745AEA524BC0ULL, 0x587CA02AA254FF5EULL, 0xE00C1A9B145FCAE5ULL
        },
        {
            0xDE9BDFEF5080131CULL, 0xF5829E02F9E414A1ULL, 0x46EB96F5E3268BD3ULL, 0x8B747E2EC5E52635ULL, 
            0x2FD2D08E95F30AEAULL, 0x3F000B84D5AFC234ULL, 0x21B8DBEB41C3F5F7ULL, 0xC926EB1DC2F7700CULL, 
            0x947F0BA3EB65BCACULL, 0xE548697D63A90F14ULL, 0x24835E79CC0AB305ULL, 0x25B18F0EBD6F315EULL, 
            0x5F8F78728328A88BULL, 0x3776E05FFCEF277DULL, 0x13F8F54EFBAC94FFULL, 0xE499B262DACBCD00ULL, 
            0xBD7E73AF5FB62AE4ULL, 0x70093FA10F043DAEULL, 0x4409FB19172031EDULL, 0x738D3E6B9E75E78FULL, 
            0x71362D84308A0957ULL, 0x2251C937DC238F09ULL, 0x142642436D282EF3ULL, 0x1185E8896B2F789CULL, 
            0x48BAECDC56DB85F2ULL, 0x883FA08B9D81C07EULL, 0x8C383D6E4E769B3AULL, 0xC7514724A7DE0C18ULL, 
            0x071736A702F01DDAULL, 0xF7EFDF31998B5CB2ULL, 0xA577A11286A5417AULL, 0xC61B16E00E8F7223ULL
        },
        {
            0x39D35544F4FE5093ULL, 0xC1B9F3632E046B5AULL, 0x4CB1B6D5C3476C56ULL, 0xC1DC5D47CE1F143BULL, 
            0x79FB2E4818E1ECF1ULL, 0xCBF49EAC0E5C2941ULL, 0xC7A3D3CF97DC549AULL, 0xEC5E706C4F83F5F1ULL, 
            0x41B26ABD1DB72BECULL, 0xB2D8CC610A0927E1ULL, 0x7D3FEA29327AE9B9ULL, 0x721E9382364AF4FFULL, 
            0x21BC7C7934795EEBULL, 0xFF6D48CBC2AB1171ULL, 0xAA98EE74B51C0DC4ULL, 0x2F48CD16890E8749ULL, 
            0x55868A5650185B71ULL, 0xB32F5192DECF1014ULL, 0x2422402ACABA92D3ULL, 0x648FA8E48D8551A9ULL, 
            0x8302D4ABD673AAB5ULL, 0xAD47D1FBEAC72923ULL, 0x097C19E50A9392BEULL, 0x7D6582939D7887FEULL, 
            0x57EEDCB502E0ACF0ULL, 0xE23378C916AD2E5EULL, 0x3E3225BEEE46411AULL, 0x95847DE4601E57E0ULL, 
            0x660C4F41357A1B7AULL, 0xB83208A2387AB359ULL, 0xDF1C3DAB19DB7F97ULL, 0xE9559393FB560440ULL
        },
        {
            0x5FAB3C77183FE354ULL, 0x0A23144F93923E15ULL, 0x9C98925014A09640ULL, 0x86A474CAFE768D86ULL, 
            0x1CD080E82DC6932EULL, 0x69EE94B212AB7C4FULL, 0x8681DF1A10D3BF99ULL, 0xF09A2C3EA518684CULL, 
            0x2F461C7BCA813665ULL, 0x97C4850B73E2A8E3ULL, 0x9D8C3C913755147EULL, 0xE4F56DD46679BB08ULL, 
            0x0F0C0DED2A7470D2ULL, 0xD9AF2DF732F9D4D2ULL, 0xCBCDD73AE8EEF1F3ULL, 0x65DBD7DB7DA47CA5ULL, 
            0xED2A5C53C2DFCB48ULL, 0x75DF96EF8AE68A98ULL, 0x58C51A7501518F14ULL, 0x55FAA3C72479FB46ULL, 
            0x4CC841E833D44738ULL, 0xE26ABE28D7CF4277ULL, 0x51ED3F1259DBF7E3ULL, 0x9746B522578CB42AULL, 
            0xC82F0B0E1F8BB44BULL, 0x8E49BFF4A3D75F73ULL, 0xA2685B32E3BDE35EULL, 0xF36516D9C18551D2ULL, 
            0xEABF90327982FB2CULL, 0xD438779ABB3FAB86ULL, 0x322348AD860D7A1EULL, 0xE4B0A422EFA7F67EULL
        },
        {
            0xA5635E3E085C426CULL, 0x28E740D1F4F2C180ULL, 0xEBDD971648C8BC93ULL, 0xE3C913AF5E6AA1C0ULL, 
            0x3EBBDC8022A9414CULL, 0xF75DD04AD773E1A9ULL, 0xA3183C3459337FD6ULL, 0x1FCE47B10BF8CA18ULL, 
            0x5D6ACA28FC472053ULL, 0xA3726DCA5BDCF219ULL, 0x7A67E3540644A4D9ULL, 0x6752B53EE2E9165BULL, 
            0x267CDD8B2E7F0F07ULL, 0x5AC87608E6A84C60ULL, 0xA2848C030A529484ULL, 0x8BE1DE0F860EFD7BULL, 
            0xE9F3D4C131FA8E9CULL, 0x7493694EEDD0A390ULL, 0xEA1FBE14990B253CULL, 0xCE86A08211574BAEULL, 
            0x0E9850D9D86C569CULL, 0x8225B25201E4C589ULL, 0xBF2FA22CBE8AB84AULL, 0xBED92830083E3910ULL, 
            0x44BFDD11C0E420FBULL, 0xD11770C38BEA58FDULL, 0x1A09225461D7E7FCULL, 0x295C19C7ED4A048EULL, 
            0xD87FBACDC0775C7FULL, 0xAD490CA07E15EAE8ULL, 0x6C81C915022D51AEULL, 0x2D128FE1868044C0ULL
        },
        {
            0x26865783E8EFAF67ULL, 0xBBFCBE4DC232F692ULL, 0xF987B311E3EBA3EBULL, 0x89C4CE192002D2B5ULL, 
            0xC26CE9C8351E862DULL, 0xC5A1D4D74DF2DBFCULL, 0x585B503656392FB1ULL, 0x82CA490604678232ULL, 
            0x2B0F3D2D33062E82ULL, 0x71E73132D6802400ULL, 0xBBF369C24406BA19ULL, 0x74F367CBAD3F8683ULL, 
            0xC3CD6165F821A60EULL, 0x50AFADFF3E363AA6ULL, 0x96CEC7EB5DD7E3D9ULL, 0x73BE550269A3A4C4ULL, 
            0x1E6468A0D493E3B0ULL, 0x9F679C4FD53F7E50ULL, 0xF1286A3BF131E066ULL, 0x0A1E5B5EDB954BA2ULL, 
            0xDEFF7AD3ECCCB002ULL, 0xB66B3E6DBAC019C5ULL, 0x243B953B27B4E72CULL, 0xC487684619A899F0ULL, 
            0xD486EDD7EF363A3CULL, 0xA0D5EF4ED52813FBULL, 0x49CB429B53C569F2ULL, 0xDDAAD99943C0F3C7ULL, 
            0x17928B86A507AB79ULL, 0xD485D1E87BDF25E6ULL, 0x3AC31D27D0FC9AA0ULL, 0x949041F96EEA75A7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseCConstants = {
    0xAB7326290F568D00ULL,
    0x488DB795B6336B40ULL,
    0xDBFEE630754F7642ULL,
    0xAB7326290F568D00ULL,
    0x488DB795B6336B40ULL,
    0xDBFEE630754F7642ULL,
    0x811FB79BD4C9CE37ULL,
    0xF38B25028A88A07DULL,
    0x2D,
    0x94,
    0x27,
    0xC9,
    0xAE,
    0xE3,
    0xD2,
    0x31
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseDSalts = {
    {
        {
            0xC63CBB8C9F6CB354ULL, 0x4C6BAAE0B4592D03ULL, 0xEBD318F199F40676ULL, 0xA6400DDF9151E319ULL, 
            0x7369B88CC6C16447ULL, 0x7FBF1A26331126B5ULL, 0x55F9AC8F5EB50EC8ULL, 0x14CE83E30EC30220ULL, 
            0xBE392D15CA336BE1ULL, 0x79594CA0ED2D30FCULL, 0x952551708A31572EULL, 0x47C7764EED0DE244ULL, 
            0xDD725CFBAC8F658FULL, 0x9F253F3BD5613FBAULL, 0xA80B0E0FAFD6BC3BULL, 0x2E3F4D86A5F14A86ULL, 
            0xC6853A54479797E8ULL, 0xEC43D45AF458CC05ULL, 0x2B9F744D0E527D0FULL, 0xFC07627B4A714692ULL, 
            0xB7E7CB238F0C81BFULL, 0xA51EA7C5C658E09FULL, 0x30F3DFF6BE509732ULL, 0xD939DD6905A06FFBULL, 
            0x70566A955AB76EB8ULL, 0x14E4610A5D9D124CULL, 0xD57F792592F7C8B9ULL, 0x27E816EC98A2959FULL, 
            0x11D636FD431EEE9BULL, 0xFE54C1F303B58ECCULL, 0xE9680B2E7B176065ULL, 0xE940548AE54C774DULL
        },
        {
            0x1E50F27F53FA05CCULL, 0x480BBC83D15007B9ULL, 0x8193C775B18B972BULL, 0xDCCC48581DA36C9CULL, 
            0xD91E6F0357D31729ULL, 0xE749616489C33FFFULL, 0x0C8A2F09ADF84B9BULL, 0x8DEBDED9E2750DAEULL, 
            0xE829F910BF33DD60ULL, 0x65561F6BB9795E4BULL, 0x3D68F2E0F3FEB4E3ULL, 0x32B4FCCF01FA3551ULL, 
            0x86B7FA1E40E3CC59ULL, 0xE7A81D1BDCAE393BULL, 0xA8F58E6549C36DD6ULL, 0xC1D1FDB0AED7A215ULL, 
            0x5020FDCC587223D5ULL, 0x32E57B8C013D6BA8ULL, 0xA5076AAB482AA987ULL, 0x3E50E41ECE631917ULL, 
            0x971CC6A711D58F0AULL, 0xA4E61945A54716D0ULL, 0x5FB121399996C999ULL, 0x38B5347BECC93179ULL, 
            0xEA0EFBD69EA510A7ULL, 0xC8966848879B30CDULL, 0xC91A657A1782CFF1ULL, 0x8B1BC000955D2FD8ULL, 
            0x20138BE846F1D716ULL, 0x118EAC4D81B63BFEULL, 0x1FB2B0B5F9F4D939ULL, 0xC5ACF9CF8A7CC30DULL
        },
        {
            0x5B3FF3ED27E6C63AULL, 0x4A90B44735849BE8ULL, 0xCB434A284BF175DEULL, 0xD7B821FC214ED219ULL, 
            0x443BF067E9AFBB8BULL, 0x2B6B4488627DDA34ULL, 0xF10BFB00E759ED67ULL, 0x9663642EE286034DULL, 
            0x2EC18AF1E30CE137ULL, 0x69B85A50B565FF38ULL, 0x47411C0618F888D5ULL, 0x8B64D0BFB2FCD949ULL, 
            0xC5769A5B90CB20B2ULL, 0x6F01345509E35DA9ULL, 0x27239DD7DF0F8CE0ULL, 0x05C8F1DC398D55C1ULL, 
            0x545613C60D8AD061ULL, 0x96543AB8A14ED26AULL, 0x7B086731CD6D4B51ULL, 0xA59DE5956C41AFA9ULL, 
            0x87ACB0F085575D7DULL, 0x8175EF11630D8B37ULL, 0xDA38A2161F4F9028ULL, 0x813C692C74F87CC4ULL, 
            0x7E117DB0FE8343F5ULL, 0x3A814DBDB8DA1D8FULL, 0x24F79E13E74BB478ULL, 0x29A023FA5F0BE93AULL, 
            0x2D200B77827B5A51ULL, 0xC28D00DCE8D022BCULL, 0x39B4ACC9D8B86663ULL, 0x705D080F13924B40ULL
        },
        {
            0x0DFC2684ACD0E8CDULL, 0x76552DE3C466D7A0ULL, 0x16B1DDEEB0BF0494ULL, 0x5C03100B10B2AAC2ULL, 
            0x2E53D2C837C84167ULL, 0xF314A063B8B1110DULL, 0x54953080266B36E5ULL, 0xBBDB614BFB0397AFULL, 
            0xF08B92B83D0D7E2EULL, 0xBF26B8D4FE352BE8ULL, 0x8A9A9F1073B5B587ULL, 0x64A70D128267279AULL, 
            0x21B6DF28FCA5DA14ULL, 0x1CDE1F6D16C114DFULL, 0x5109B4E84152FF26ULL, 0xE4E43D3BFC348A60ULL, 
            0xFFA31A3E6AFCD82CULL, 0x558E0DF06C0675DDULL, 0x52D61CEC76AA6A67ULL, 0x46FBFCF7EF54EEAFULL, 
            0xC82E318BD506809DULL, 0xE5CFFE682C26EF5CULL, 0xCAB6EE51BFD165D6ULL, 0xAAD885EF4D31C2A6ULL, 
            0xE6424BDF9212EA9AULL, 0x84D64BFF7B4BFDDDULL, 0x7001FF42FDDF8A4EULL, 0x429C8DAE5DB3EF67ULL, 
            0x0B40FAB719E2116EULL, 0xA4C3D1FD8DE028C9ULL, 0x92DC7675F720F9DCULL, 0x805B2E4D22047DCFULL
        },
        {
            0xB3E524312C76911FULL, 0x43C5A0C9116A51C2ULL, 0x30DA029CF0C21FA1ULL, 0x23F20B824D3872ADULL, 
            0x10165DC0F617BC62ULL, 0x7188876DDCC03FADULL, 0xA449AD2922AFFB0EULL, 0x6CBA6DD24529E3F7ULL, 
            0xA287405CC35BF66CULL, 0xEC9E8DE0BFB09B04ULL, 0xEA75045F7BAC4F6FULL, 0xE81E038694097901ULL, 
            0x093884BFF5D421A7ULL, 0x65DA5E8EB9B3EA6EULL, 0xCE6115E623DA0A02ULL, 0xF091D72B52E7901DULL, 
            0x054FE8DBA3E71D15ULL, 0xE0258A6B757E923EULL, 0xCEC57448CD995A5BULL, 0x0CADFD514B73EC6EULL, 
            0xD4AB2D614565CD42ULL, 0x737F7ADCDB7A49BEULL, 0x15BB5D99802937E8ULL, 0x0B1DAD0886BC15C6ULL, 
            0x50C5473ED07A1DD1ULL, 0x74F956B476541B88ULL, 0x00BEF7DE9E6EE638ULL, 0xEA3081D1C3927FF3ULL, 
            0xD4CBDE4D149602B4ULL, 0xBB6C892639705939ULL, 0x363670FF21B20FBEULL, 0x8D924897DF12714BULL
        },
        {
            0x6C6BEF7656723ECCULL, 0x36AF509E83EB2A30ULL, 0xA466F7E31DC94D6AULL, 0xC8C760B48DF29812ULL, 
            0xAE57034943FA5815ULL, 0xAC77A6D7E89976EBULL, 0xCF9488BDA4307687ULL, 0x509C89B42D497856ULL, 
            0x4F39684F01EE4547ULL, 0x1C8BCBF1F6725393ULL, 0xE91CB3F9FF5E3D63ULL, 0xD85AFBD08CAA0F54ULL, 
            0xE59D00AD5E8642AAULL, 0xD6AB9AA42BE1DC8DULL, 0x7D0BA36A7F6AC992ULL, 0xB776D3B693371137ULL, 
            0xC3B4DEA8D88FEBB6ULL, 0x06F5C9E2249EA15FULL, 0x04B6F9F39216D83AULL, 0x7C2975E0DEB5480EULL, 
            0x9512FE60B843E8D4ULL, 0x757FB2C7089D6CE4ULL, 0x18D487C746A5DEFEULL, 0xC22E57F3D5F2A9FAULL, 
            0xAB98EF916818168DULL, 0x996F14E3406727BBULL, 0x1B907F07E5476AC3ULL, 0x6FDFA46B5E4FE89AULL, 
            0xE97B330A0CDAAC59ULL, 0xD9D591BDDD5AF9B3ULL, 0x0B23931F7A6D7A75ULL, 0x509BF3E59910B465ULL
        }
    },
    {
        {
            0xEE20CDF4E6D2BC00ULL, 0xC204B63446CEACF9ULL, 0x2B677D4966F378B8ULL, 0xEB238D4B35A835A8ULL, 
            0xA45E8559C29334EAULL, 0xD7A3E64010F54399ULL, 0x329BA977B86035A1ULL, 0xDB41A4292C5143F2ULL, 
            0xA68D4EAB9C79A951ULL, 0xAAA7D440C2D742CCULL, 0x588C4CBC25B75041ULL, 0xEAA9F6312B7D092EULL, 
            0x9FEDB9D6E4AE118FULL, 0x4B2CD3C21BB34B53ULL, 0x5355601E52598F21ULL, 0x6F9CF690696159DDULL, 
            0xDD401F555E5CCBA1ULL, 0xB26340E78058EF6EULL, 0xAE0CE023422312E1ULL, 0x71559778FE7CCCB2ULL, 
            0x672AE73349CAC13EULL, 0xBE61DD89E2C3ED40ULL, 0x871DC10DFE4492ACULL, 0x47873D8AC44BD395ULL, 
            0x429BE0BBE19EB3EDULL, 0x70195A5C6FD8D910ULL, 0x29081AF9F8202D10ULL, 0x648837E00E276A7AULL, 
            0x8BCB60E7AADC660FULL, 0x976BF917329B8081ULL, 0x7D327DFEFCA48268ULL, 0xED044AC1F59C73DEULL
        },
        {
            0x4602228F925BB99AULL, 0xC21C7B95F25D138CULL, 0xF96CCA8FED10F494ULL, 0x6A87C8F3F8352D38ULL, 
            0xE700C6E0D48EEB0DULL, 0x74859050FA81D420ULL, 0x65F9B8E48708BD1EULL, 0x1DD0294E59996BB9ULL, 
            0xD1871D6B6534ECBBULL, 0x96DE53A344373FC9ULL, 0x8061BAF46FD0D6ECULL, 0x71CB6749CE54F852ULL, 
            0x1051E20C81E335DBULL, 0x6955F7F50817C56AULL, 0x8E673B711AD496EBULL, 0x4468D17F8961F3DCULL, 
            0x4075CE95A189DC5AULL, 0xBF25326321643F72ULL, 0xFC7AF2E430583D0DULL, 0x2336585867FF94A0ULL, 
            0xBA2E73F1A4C4FE81ULL, 0x84F80BE2F2208809ULL, 0xC11AD1C4A822860DULL, 0xD7AD9CE8AB20896DULL, 
            0x5597549D607045F0ULL, 0xCABFF9482361B47BULL, 0xFFEC886F702F7FDAULL, 0xF9CFF4D6D8918F92ULL, 
            0xD75D4E2B9C641988ULL, 0x6295AF148AA3F433ULL, 0xA35B2792C54423F6ULL, 0xCC157AD473B590B3ULL
        },
        {
            0x3B6B6A3016F116A4ULL, 0xF6670ACD22035170ULL, 0xF59D6FDAEF7CAD1DULL, 0x539E986A6525ECB3ULL, 
            0x3BF7572E6D620993ULL, 0x4460C5B252E2A3CAULL, 0xDE8FA5F1F794BAF0ULL, 0x2B6A8B6F8735D638ULL, 
            0x36AEFF4C2D1A96B9ULL, 0x885347CB0230ACFFULL, 0x160860EDAFE7FC63ULL, 0x619A746F6F8C0E70ULL, 
            0xBF3365B7132DF174ULL, 0xB1AECCC7A2267BC7ULL, 0x9B9099A6CB980517ULL, 0x6710A8CBED45391CULL, 
            0x89257323E10CBA27ULL, 0x76014E59A53A4ACEULL, 0x3D56B5685D99B84CULL, 0xDE1551D266C0BE79ULL, 
            0x06B4469FEDEF331FULL, 0xE87CB357EB39FC9DULL, 0xA00B0CB844C5B26BULL, 0x0C0EA273254901BBULL, 
            0xAA77377C9F80F17DULL, 0x22C7E05BD9980655ULL, 0xD75C543F08A68D93ULL, 0x9380F95AB03D70A9ULL, 
            0xC46800AE0F25C2E8ULL, 0x6CDA3636FA7068BAULL, 0x34E9509AFABFF1D4ULL, 0x2D6898C74053B2E6ULL
        },
        {
            0x3A38E17F581A663BULL, 0xD49BD94DC75B9FB2ULL, 0x7D56E96E573059E4ULL, 0xB3679FF1B9128FBAULL, 
            0xB6856D647748E2F2ULL, 0xED71A30E6DD1662AULL, 0x1D01F0EEBF9ADF1AULL, 0x8F89BD16E8371AC8ULL, 
            0xCE8F2DDA2DC190B3ULL, 0x6DE4D01F09BCEDC6ULL, 0x01421AB8D7220B81ULL, 0x17B381B7ED9F8F03ULL, 
            0x0502C854C794D152ULL, 0x561A640A976D4260ULL, 0x90E22F83FCBA00C3ULL, 0x628268098C63A9F4ULL, 
            0x685C7D87EDD02814ULL, 0xEB0DD38511191E95ULL, 0x8CC2BC4B0BDFBC6AULL, 0x387829B9AF7A66DEULL, 
            0x1D95A8420E709D05ULL, 0x9F03431B222AC353ULL, 0x2A95605C9BC3F76BULL, 0x4DD2FC36B38A99BFULL, 
            0x0064D0795CBE5E05ULL, 0x9B5DF8D20A0448F2ULL, 0x4159820A64FE2833ULL, 0xBFCC921D87E4EAA5ULL, 
            0x9D794E30D2BE2EE7ULL, 0x8DFA43BCF65C2205ULL, 0x8484863C8BDEA4BBULL, 0x929368F3BF6F52BEULL
        },
        {
            0xD9605CB6D08C3958ULL, 0xB8CD2DA82E859A92ULL, 0xFD422883A68B0875ULL, 0x26348CA3F05B5B59ULL, 
            0x5BA97429C71172E3ULL, 0x2296A56DA7E93F5DULL, 0x17A6C140E0C50722ULL, 0xA97580B47D74988FULL, 
            0x34688BDBAAAE19B2ULL, 0xA3C67407B7B873CDULL, 0xA3550B4A46209C00ULL, 0x62B096DAA5F4F5CAULL, 
            0x6C333E0430B6E0F4ULL, 0xA9448B96634125B5ULL, 0x3B9E8046CF73C356ULL, 0x0D154F07A9198607ULL, 
            0x97EC5C4A9022D328ULL, 0xF62C84FE84A531B5ULL, 0xBDBC631B631ACED4ULL, 0x56E6C6F1A3C249EBULL, 
            0x72586CA13AB67E8BULL, 0x9659BD88801E7FF3ULL, 0xEB54744B11226A1FULL, 0x2DDDFF2707D32C60ULL, 
            0xBDE7E611C97AAC85ULL, 0x5506CD9FCAFE7579ULL, 0x5DB3F0FBDD4CC8B2ULL, 0x75315F1296BD3152ULL, 
            0x31C6377D5C57C6D8ULL, 0xC2918FE44B4A5062ULL, 0x6F215C9CB232C5CDULL, 0x6C83138AA70E2BFBULL
        },
        {
            0xB855F6D7DF91DF13ULL, 0xD644F18D176C91DFULL, 0x8C9AB86AFD61E2C2ULL, 0xA83869DF411852D5ULL, 
            0x8B9BB65AFB3768C8ULL, 0x1E7FC5B285117602ULL, 0xF0E4D2213643D717ULL, 0x1FF819495650D7F9ULL, 
            0x2766CBACF5771268ULL, 0x0BBE76199D0F97EEULL, 0xFDEEA26669F3272BULL, 0x4881D588DE4C4DF8ULL, 
            0x0830CA9D4C6707DDULL, 0x7CED5A1218CDE550ULL, 0x6A07ABA268CC8CCAULL, 0xAADC5AD1D9A1D80BULL, 
            0xF7DF17AD0EDC5C3EULL, 0x8F94AF2BFB03D264ULL, 0x752BAF9EBB18ED58ULL, 0x7E67445B94CC2153ULL, 
            0xE39B6B1797F79605ULL, 0x71DC9FD019A3B4E2ULL, 0x0551E1CA3A5DADD1ULL, 0x8E507B0DCCB21F1AULL, 
            0x35F3390A60C20A7CULL, 0x2788BCA510909D38ULL, 0x5E63939FB695EE5FULL, 0x86580D8FE9E270E8ULL, 
            0x7E4606AEBF72B048ULL, 0xFB7ADD1FAF1AB3FCULL, 0x856DA907F4A6A9DFULL, 0x89F239EE0D77604FULL
        }
    },
    {
        {
            0xBE35026AD832FA05ULL, 0x1F8D8D2BF7B96DEDULL, 0x032082FFB620285AULL, 0x3C019EE056F0D128ULL, 
            0x422391811A59A163ULL, 0xE00848AFDA9B31C0ULL, 0x5BD380EACB2F8024ULL, 0xDFD28918C53ACF98ULL, 
            0xA2D1D3A8EBF2F892ULL, 0x4519FD6598980F08ULL, 0xE5B5DA3EB8848723ULL, 0x6AD1983A34ADEC75ULL, 
            0x4078BE3987C5C30CULL, 0x387A7AD0C18248B6ULL, 0x9E1C6380A11D61ECULL, 0xDE2763EB445115D5ULL, 
            0x0AE003A44A7481A1ULL, 0x3F0FC9C18E585C5AULL, 0x7B200196EAA55E1DULL, 0xE28D09290CF13C5FULL, 
            0x938B84E8718F2844ULL, 0x6946AA085C0BE602ULL, 0x016AA9D1BE8657F4ULL, 0xF32EB12E6D2135E1ULL, 
            0x148F99A73A066372ULL, 0x1181E35E733D8AF4ULL, 0x636730F78A357428ULL, 0x61446614231705DAULL, 
            0x6EF9F33804533B0FULL, 0x61498588B18E0BBBULL, 0x9373215DA01E6F3FULL, 0xCA6CF907F79EF8A3ULL
        },
        {
            0x0E69150BF8B500C3ULL, 0xF904C248E3560507ULL, 0xF6C8BCEE27857F56ULL, 0xBB93A217318B9800ULL, 
            0xBAF17FE531C0C406ULL, 0x9AE4B063301121D3ULL, 0xD34EA3223DB62CD0ULL, 0xD9976386647FA7EEULL, 
            0x0E8540236CE440A1ULL, 0x5BD20A5E4EDAD676ULL, 0xA267547A904ED8D3ULL, 0x5A67E8CA259108B0ULL, 
            0x9C8C578B32AC7C71ULL, 0x67CD638477A11A3AULL, 0x513324E02D62FE16ULL, 0xDF50C48B262454CCULL, 
            0xC8A967FECBE67B86ULL, 0xD08A65FBC8E3AF6FULL, 0x2CC94C0FE31D9593ULL, 0xF9AAE3EC281A10D3ULL, 
            0x1B9CEC5502D3CF0CULL, 0xE4912871557926D4ULL, 0xE216BEFF26CE3388ULL, 0x8FD6296E436540B4ULL, 
            0x59507805A51942ECULL, 0x52A38222C8D99BC8ULL, 0x20608BB1A4AC9C9AULL, 0x723C7D39B8555C6FULL, 
            0x0F879242B8C991D8ULL, 0x5A351E9F0699A8CCULL, 0x413AABD1C5627DB7ULL, 0xC2FD15477150E15FULL
        },
        {
            0x2DF92345B293B182ULL, 0xD6F58377E2057C39ULL, 0xC7BAD0AB80964478ULL, 0xF7405DA8BD377637ULL, 
            0x3A909BF3371301E9ULL, 0x6237E97640E727D4ULL, 0xED5348296E1989E3ULL, 0xAA7F189667CBAA8CULL, 
            0xD4CC5543813DF2CAULL, 0xEF30D8D06D6E4A14ULL, 0x358C789FF8FF9473ULL, 0xFA8E15ADE02EE734ULL, 
            0x49135C0BC1878472ULL, 0xA678982DDE5150CEULL, 0xE47C051486A5BB11ULL, 0x463D296129F513C8ULL, 
            0xE72BD9CD00741976ULL, 0x487B9E96C57CBBCDULL, 0x6CAB0CFAE6E37282ULL, 0x9DCBE5301BE72D88ULL, 
            0x7412A97373A6CE15ULL, 0xC1B2F996A37BCA9CULL, 0x6243567E82334A3AULL, 0x635864334C0A76B3ULL, 
            0xAEC59409BE799DADULL, 0xB296A35AB7380A16ULL, 0x80544495C10C2431ULL, 0xD51836EE18AAA4D1ULL, 
            0x3365828FBABA5586ULL, 0xA5C29AADB56A1186ULL, 0x1BCF4E179CB8092EULL, 0xE57E1723A1CE08C0ULL
        },
        {
            0x048AB7903CFD6351ULL, 0x85C2B8905339ADCFULL, 0x92139A48459E498BULL, 0xF5A91CD06F881D25ULL, 
            0xF238FAC21C8F9E66ULL, 0x75F5673D1D102923ULL, 0xB7D02A3771044D1BULL, 0x46E28CBCF734D7D1ULL, 
            0x38ECA36341A9EC86ULL, 0xB7FE0CD256E3B384ULL, 0x9B968D753B15D7DAULL, 0x094427D924BEBED7ULL, 
            0x689114237DE5B271ULL, 0x5556646F6E7F1AEAULL, 0x2192C183424BFFB3ULL, 0xF8A703FA33930B60ULL, 
            0x7F8253F7EDB63CA7ULL, 0xC37FE7D09F8FDA9CULL, 0xF0707ABDFCB60CA3ULL, 0x688A70E310403190ULL, 
            0x9135C454A8F10A8AULL, 0x2CA3D829661FEE45ULL, 0xB3FC6B2269673F42ULL, 0x9CA80B04A7F77309ULL, 
            0x8B0ABEE34E98F9D8ULL, 0x3146F5BD8CB96B8EULL, 0xB8358DC3EC1D69CDULL, 0xBCB1BF844E8F91ABULL, 
            0xCE5CAA322E0A844CULL, 0xF63ED99CBE618A0FULL, 0xFC2EE30FD4FD9BD3ULL, 0x5C2C3F4050A6C668ULL
        },
        {
            0x8F60DE96EC2D2C33ULL, 0x893CFF090CFCBEC6ULL, 0x8F1DE59421C8BE1AULL, 0x25E94F87645DF3E8ULL, 
            0x858E6555596EF0A1ULL, 0xF834316FC7336473ULL, 0x41CB76BD0C6E96AEULL, 0x8A3B8F5AFB5F3B73ULL, 
            0x4F58F128A78AB16CULL, 0x65968C02445199ACULL, 0x02BA27A23BFD09EEULL, 0x924A7F3CBCD4212BULL, 
            0x87942A35C7C7A0F0ULL, 0xBD5AB8DD46F90AFAULL, 0x3B07811D63A9407DULL, 0xF6120A6010721402ULL, 
            0xB31EECE02916AB07ULL, 0x1B7AC2CBF354C51CULL, 0x9522A79B10FCE727ULL, 0xB321E04340378BCFULL, 
            0x3A2D385C75F6EF46ULL, 0x4DA3956ADD1CCE3FULL, 0x63DEF04FDDD81156ULL, 0xEA6022BB145213C0ULL, 
            0x86A774CB154A7EF6ULL, 0x85D6A17FC517990AULL, 0xF173E7C13BDD8870ULL, 0x19E71A28B81729FFULL, 
            0xD5FB3705DF75C93AULL, 0x09BDE80020DC104DULL, 0x15C16B49399129F1ULL, 0xD3FA3C85E66541FAULL
        },
        {
            0x1044397355DA3820ULL, 0xBA373CBAC6095BABULL, 0x76B5F33BCCFEF163ULL, 0x3E8FC0922942B0C1ULL, 
            0x82353F3717D28158ULL, 0x04E318658BB61C33ULL, 0xBA95984FDED5DD31ULL, 0x825070E375D298BBULL, 
            0x9CE26C9D3B83F66AULL, 0x9F458997909E3652ULL, 0xFBFC3EA331A12E5AULL, 0x6A6858829C1DBE49ULL, 
            0x0D00F6BE42240298ULL, 0x78B3439A9DF685FAULL, 0xABDE74177E9EC698ULL, 0x404D2E0D86151DE4ULL, 
            0xF5BB0868E0AD1141ULL, 0xF82577ED0EFD9863ULL, 0x3920535030816B79ULL, 0xAB46F046BD337596ULL, 
            0x16EB79F4374ABDAAULL, 0xDC842AA0978B1CCAULL, 0x90C4CA5CBE946DB6ULL, 0xCC9DFDF8C6B3F1ECULL, 
            0x642C2B50E0266632ULL, 0x79FD3B859ECFC168ULL, 0xF06BC6406433583BULL, 0x96394ADFCF6254C4ULL, 
            0x23E1891CC006A5ADULL, 0xF6FAE9FDCD40B92EULL, 0x4CFBFA6988E9C50AULL, 0xE0E126ACD98A8F40ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseDConstants = {
    0x60A00467F5AF41D6ULL,
    0x78B9014C15AC8F0BULL,
    0x6ED94B3B7C493267ULL,
    0x60A00467F5AF41D6ULL,
    0x78B9014C15AC8F0BULL,
    0x6ED94B3B7C493267ULL,
    0x65BDFAC0C67E6EB0ULL,
    0x27529D7573B85B4FULL,
    0xF0,
    0x50,
    0x58,
    0xEC,
    0xB2,
    0x50,
    0x9E,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseESalts = {
    {
        {
            0xCD9E7525B2FD0042ULL, 0x6C8639035FCDE5B4ULL, 0x634B11B674F77DB3ULL, 0xB42BB8677E77BBD3ULL, 
            0xCFFD70143CD3A82FULL, 0x365EE5EF569540A8ULL, 0xAE61D13299C053A7ULL, 0x4F1B53E8660E4834ULL, 
            0x229A9DDB1BAE789FULL, 0x04993534B31CE420ULL, 0x4ACBCA5C9682FAD0ULL, 0xA301D9AC75A6341FULL, 
            0xF3F1931FB13603FEULL, 0x404E1E584D02B39EULL, 0x38A06C37535296BDULL, 0x498423F3B6D57110ULL, 
            0x9BF32C2D6AE1FC0EULL, 0xCAD4E471B312CDD3ULL, 0x93164616A1AAC338ULL, 0x1EFBDDA9348EE5B3ULL, 
            0x78FBEEF392461FA7ULL, 0xBA3E83EB8E235899ULL, 0x1442DC2BC81FEA34ULL, 0x52F5F8E2A23AAFE9ULL, 
            0x7D50770E99BAE007ULL, 0x5335C729B9A275A7ULL, 0x997A2FC2780E044EULL, 0x6A454B2E644CF8DDULL, 
            0x59564C0F9A61AE02ULL, 0x5BC1D2CFFEB61BD8ULL, 0x66518C2EC1023758ULL, 0x870848CD2094660CULL
        },
        {
            0x5AA1972D8A020AD3ULL, 0x44CAA94B2073FA4BULL, 0x7C84A2D58F38AC58ULL, 0x76CE801A6E499B78ULL, 
            0x9C1B0D3F64815511ULL, 0x653800334DB3D999ULL, 0x17DC5F756E0981D5ULL, 0x8F3761C3BA7276C0ULL, 
            0x84BD33B1DC00DD0DULL, 0x8C66C06F96C84787ULL, 0x7EE54477AADF8E6AULL, 0xF7BF5C6BC2875F5BULL, 
            0xC1E7CB8E1DDAFDF1ULL, 0x40A36971E16C1D74ULL, 0xBFC18A56DF72E2E8ULL, 0x6D630D0F0F8FC65CULL, 
            0xC01F004A61488639ULL, 0xE6E5809B17218C19ULL, 0x2DA252C05500896AULL, 0x11D59840513E7946ULL, 
            0x17FE5E63ED169448ULL, 0x8A2D4A3387D4B4AEULL, 0xDAE26D506850378DULL, 0xEBAE116B730D992BULL, 
            0xC13EFCEB7BCE7555ULL, 0x29953FC97FBF8510ULL, 0x295E3F58C69101E5ULL, 0x13A9A4415FEB6CD5ULL, 
            0xF003C6C9F47C7D63ULL, 0xEEA366FEFB543B88ULL, 0x7E5D4163F2CB1AE8ULL, 0xAFCD60AB7F879EA3ULL
        },
        {
            0x576E0053D0AD8491ULL, 0x8620C4DD17AB46F0ULL, 0xC0407D817C179805ULL, 0xD57DB0CCCC0822EDULL, 
            0x91A07B4030E9A96DULL, 0xF7197ACA898E3F0AULL, 0xD3AC3E68E6628358ULL, 0xD9FC7EA588C681EAULL, 
            0xD22329DA29345369ULL, 0xF93E3DB9AD537EC2ULL, 0x0BCA634D24D00317ULL, 0x85215DD2D3FDCD3BULL, 
            0xC226861904F957B0ULL, 0x07CBA846246F7533ULL, 0xDD50E08F45A9E864ULL, 0xC8588FC89468E547ULL, 
            0x614D5D4581B1B2FEULL, 0xF1B2759E222EAC8CULL, 0x03F424B71220F321ULL, 0x28AB6F5909E1052AULL, 
            0xB4AE5F0E6D1BEF7FULL, 0x8F435A35C4863020ULL, 0xDFC9C06D5C973799ULL, 0xF7783C6674EE7AFFULL, 
            0xC773884C7AA8050BULL, 0xD5F108B9FEA3999AULL, 0xEFA51F351E9499D2ULL, 0x07F22E404E491F08ULL, 
            0x41B61DBB69861F01ULL, 0x2188A78FF2E3E47EULL, 0x77670316ECFD33E7ULL, 0xBD3184BFACAA65C0ULL
        },
        {
            0xC2C29F5F2F2A92CEULL, 0x4E89E619F618782BULL, 0x6AA8F8FED568D610ULL, 0x5A65B53347F69A40ULL, 
            0x66FDA41A589C7D97ULL, 0xD298E890610CD305ULL, 0xE86F1D1FF29B7616ULL, 0x32D91C211342CF10ULL, 
            0x18F747F327154E92ULL, 0x2A65893B77D66C4EULL, 0xD4DCF94CF2A10776ULL, 0xE343BFB2BC00A5C4ULL, 
            0x7742E3FBFD706ABEULL, 0xB71B3AE110A3D859ULL, 0x728BA4B34A776990ULL, 0x5848E387D2279D46ULL, 
            0x39F7A89CC8FC6114ULL, 0xC95EFACA7CC354C2ULL, 0x33DB69FECD7C3957ULL, 0x30C4F65ADF7856DDULL, 
            0xA8AD771482AC35C5ULL, 0x2FE25C9015BBD7FBULL, 0xE2CA1C7B0C7E3A5EULL, 0xE9812D3AE9ABE49DULL, 
            0xCF245521850E1F7EULL, 0xB1E8D196173B0B89ULL, 0xD28D5B104A31561BULL, 0xBF6F5A328F247FB6ULL, 
            0x74340BB016FD8955ULL, 0x5CA312696EB9496AULL, 0x8F6F76E19E1C289CULL, 0x99F5E82B5DC7719AULL
        },
        {
            0xF2B3E08E288CB49CULL, 0xBBE4EA3D376DFDE6ULL, 0xF99787EB9C4EB7C0ULL, 0xD4BE3B8F0C0BE106ULL, 
            0x1FDB286253BC9EF2ULL, 0x1BA9380B2E8E4C25ULL, 0x7B8B254EA2EF5B7BULL, 0x8BC37C7C1562080AULL, 
            0xC054F6122126CE5FULL, 0x04BAE30B31E094CBULL, 0x950D7DA5C0F8DBF7ULL, 0xAF0356378191F290ULL, 
            0xDA6AFD5BF228685FULL, 0xA87FE5E508A3111BULL, 0xBFBA8F5B0E7F2D4FULL, 0x5F56FF36D7366A1CULL, 
            0x38417098E9C4FC0BULL, 0xEC8DDBDBFB2F569DULL, 0x0CBD50478912FA68ULL, 0xF103F8C948CB274DULL, 
            0x5CBB797E5258DF14ULL, 0x39146FAFB5A29F88ULL, 0xB36EFABA61B17B4DULL, 0xD3DEF56654B4245EULL, 
            0xB7F4ABFAE926C00DULL, 0x6EB8DB0CB84B4276ULL, 0xA2FF582174E91238ULL, 0xED1F7D94C94A75ABULL, 
            0x3354C322236CB8C6ULL, 0x1E16F1E774692561ULL, 0xCBB5DCD7DA3A623CULL, 0x2511961DF186F06BULL
        },
        {
            0x1440E6264FCAB0CEULL, 0xF65C8145EBA5624CULL, 0x5D0C21DB3CD62677ULL, 0x0790039280B3B6D0ULL, 
            0x925F5B122C65AC5AULL, 0x467680F73770A0E3ULL, 0xB9C570BA37D3D46DULL, 0xD2FB7EC12F8D747CULL, 
            0x7B330EEE1EE56E0BULL, 0x693CA97B34152962ULL, 0xEE29333657804A1FULL, 0x47FAC4F84E35B78AULL, 
            0x2CEB57AD9D50C183ULL, 0x44ABA8A18E8BF852ULL, 0xE0D5A5C09ABF5A79ULL, 0x710B3B6CE18D6A35ULL, 
            0xC34E574092192BC0ULL, 0xBD5BCC188996D3E9ULL, 0x051445D092A8C2A4ULL, 0x3AF43331091A9787ULL, 
            0xB9E2275C70C07820ULL, 0x384DBFEAD70FA780ULL, 0xE27B29B6CBDD30EEULL, 0x4DF6EFB8A29946EDULL, 
            0xCF25083E212D52BCULL, 0xC2311E57D908B726ULL, 0x4388BA855B168EE6ULL, 0x5FC45BC3746DB302ULL, 
            0x6AFA059D4E2333EEULL, 0xF2B7B3EA067ECCF3ULL, 0xEB86B7F9C624B373ULL, 0x51F2336A596F9216ULL
        }
    },
    {
        {
            0x53B63EB47C43BCF8ULL, 0x7E30DDCAF292768EULL, 0x7BF82E29BC568950ULL, 0x3EED6ED7CB374BD4ULL, 
            0x1D6EFB03AA27C371ULL, 0x455DA0FA1025D82FULL, 0x916FE248AEC1C13FULL, 0xEE9FB41FC77DD376ULL, 
            0xD787545F23B536DEULL, 0x96552D9DF43181AEULL, 0x0B475EA7B18AFBC4ULL, 0x5EE75AB695336DCAULL, 
            0xCE9EAD5CCF3B46FCULL, 0x21A8CC6B86103392ULL, 0x9D9A748AE146A610ULL, 0xD133B64D95848F83ULL, 
            0x8B8A36ADD47A2FD8ULL, 0x3FEA663D07D89376ULL, 0x143F4C68A4DEBA79ULL, 0xBA70169D4B6535F3ULL, 
            0x5B2BC15FA4C754DCULL, 0xE67E480E197AA87AULL, 0x56BB1AACB26A04F4ULL, 0x17F307B269AF1B0FULL, 
            0x7EE81BE0373EE46BULL, 0x5E551DDF979997C3ULL, 0x7548B52B64F171A5ULL, 0x355438CA9A866946ULL, 
            0xDA4F49A0ACC12157ULL, 0xD27622DD2CAE026FULL, 0x6C173DE5F6CF6526ULL, 0x367F03D362C6795FULL
        },
        {
            0x49E590D73BE139E9ULL, 0x64965A3EAE572953ULL, 0x1496363AF59393DCULL, 0x97676C0866DC58FCULL, 
            0x3C1A69DF3EA3FEBDULL, 0xA88D526C7E3E7994ULL, 0xD24EB97DF2F71E75ULL, 0x0E5DBE1C3DC54A80ULL, 
            0x4E69223B936D84D7ULL, 0xF78F7F7E617FF0F2ULL, 0x7B0E857F8F0856F9ULL, 0x9D9983F7C14EFF33ULL, 
            0x9F341F48641A5C08ULL, 0x048D1A92707C0761ULL, 0xE2B40E0D1981D25DULL, 0x150E33611FE873DCULL, 
            0xF885E9F6DC5BE14EULL, 0x9367F645A7D9168BULL, 0x5A7975D4DB85491CULL, 0x111C0460C2F0348CULL, 
            0x93F773C93558BF2EULL, 0x1F44790925034B89ULL, 0x3E3C5562E991783DULL, 0x4E77E28DD6DCF9F9ULL, 
            0x8F6E6310AABF55A5ULL, 0x2A502C76BFC007A3ULL, 0x211CE40CE676369EULL, 0xC2488BFFCC1B20A4ULL, 
            0xA8CACDADC5B1DEBBULL, 0xC726D878FD81C8C5ULL, 0x6592E487EE4EC2B6ULL, 0xF14F2D234D18F490ULL
        },
        {
            0xE64708A2181E051EULL, 0x50B8FAB0A3E44EADULL, 0x2E375E2B5A5247DDULL, 0x294F75D0454A067DULL, 
            0x0A06BD42FDEC0DFDULL, 0x00B2C729279F8114ULL, 0x06EDE27F5D6B05E9ULL, 0x63C44CB47C3BC711ULL, 
            0xF66049B2CFCCD40FULL, 0x3764A602BED13961ULL, 0x4346EBD6F77ED6ADULL, 0xC6CA1D858E5ACCD9ULL, 
            0xDDDED1C7B4852743ULL, 0x0C5ADF31B95AC4BFULL, 0xBD4FD83F2807B34EULL, 0x3D04C4BA2DD16ED8ULL, 
            0x1F46EA1F0A0453BEULL, 0x5685A40AB350E001ULL, 0x25D6AC5E4ADDDC04ULL, 0xA69F8F42296AAB1EULL, 
            0xFB1A394BB7A70B07ULL, 0x2B7C3EED8B21C4C8ULL, 0x429DBFB4F95B762CULL, 0x1B2AF8700157BB58ULL, 
            0xE71D1CB35846D017ULL, 0x71AB181E8EF08937ULL, 0x72FA4EE3A56E50EBULL, 0x567A570C8436EBC8ULL, 
            0xDE722142E8CD9579ULL, 0x879F3C881B3C326AULL, 0x7912EF745E67FF6FULL, 0x8E42370318996245ULL
        },
        {
            0x003538B9D8DF3E9FULL, 0x320D044182C64B3BULL, 0xFC59E46C05C5D2B1ULL, 0xE8430C4765D2CEF6ULL, 
            0x98FFD5ECE6854069ULL, 0x7BC31426E05A9031ULL, 0xA960FFD24663B028ULL, 0x6D0E90B8F58EBFDAULL, 
            0xC01841C7FF958188ULL, 0x87309F71A8D227E9ULL, 0x208EA8A443BC029EULL, 0xB9BC27B42484E334ULL, 
            0x1B58DD791E57CE1FULL, 0x227E5215101AF5A7ULL, 0x1118325655477447ULL, 0xC2F796DCDEF0C065ULL, 
            0x060C359718159ECDULL, 0x1214AC6003D49D22ULL, 0x57FC67B7B73451C8ULL, 0xC4D31135271194AEULL, 
            0x42E13FCFC0F02F06ULL, 0xDD315AFE853DFFA1ULL, 0xC82DCF6E20D2C010ULL, 0xC6B6335DA4EBBDA5ULL, 
            0x0654848D5E62FF11ULL, 0x985347AF5F4523AEULL, 0xD154B42C77E64279ULL, 0xEBC39EC3359A3607ULL, 
            0x77E683EB77FF07F5ULL, 0x1657A4ED79A733A5ULL, 0x43B8D1BCD3B9E7EBULL, 0x4EF5BA06BE833309ULL
        },
        {
            0x422F772AE7738320ULL, 0x65E2AE8541FB790BULL, 0x1779C748F45E4F47ULL, 0x30D2D9E4E33B80EFULL, 
            0x45F4B9CDA2C9D4DCULL, 0x421F654E75C5D020ULL, 0x1B780204B9A7AC52ULL, 0x484BD93A77BA451DULL, 
            0x5C3E33FEECE9B092ULL, 0x3C696438BDCD070CULL, 0x7B17DC10DC2706EEULL, 0xC5A2C0CD8D00A19BULL, 
            0x219FE3308E9F7BFEULL, 0xA0757FD537929BE3ULL, 0xF7009923AA63364EULL, 0x7E1EDE94CF94C011ULL, 
            0x94815B27E01E8006ULL, 0x4B6EF1A90E25E860ULL, 0x76283C88C604314EULL, 0x6B0C6075078D15C2ULL, 
            0xCB202695807CDEE9ULL, 0x32911199BCD19B45ULL, 0xDAD03C79BF9304E5ULL, 0x74E48E12247B405FULL, 
            0x4D4EF961B30F6DC9ULL, 0x618AA8335B6FB0D9ULL, 0x5717E437311C1D28ULL, 0xD2E2C9980597048DULL, 
            0x4475CC51317B9C02ULL, 0xA93F698998E5904BULL, 0xFE9E59AB4A086C30ULL, 0x09EF176E482E988BULL
        },
        {
            0xA86DE3B14473E20FULL, 0x40E8052D83F69A6AULL, 0x0FF111DF522C7D62ULL, 0x64B4ACF9648B9149ULL, 
            0x01C133E5315084E6ULL, 0x2A936DC6B39CD5DDULL, 0x4F41A2DBBEC554DBULL, 0x4D19F4E6B5ED8B73ULL, 
            0x013BF5CAC48DDCD7ULL, 0x9DE9FFF2A2A8C4BFULL, 0xB28651F0C269F1ADULL, 0x966EC2D4A588908CULL, 
            0x50E8246D33961ED6ULL, 0x69ED8A8BD0330C3DULL, 0x94389F4C4BE596A7ULL, 0x3ED28B109C2DB646ULL, 
            0x009E0044E09B400EULL, 0x6EDCB5AF050EA4CBULL, 0x02D03BBD46F4AF3DULL, 0x80BB2209AAFA0ED5ULL, 
            0x096713E1C77A5867ULL, 0xD2DA5615C2F4B108ULL, 0xA206AA2BB6336834ULL, 0xF982C2A85BFF275DULL, 
            0xBA6E763970356203ULL, 0x6E22C5E46F40321FULL, 0x7C15442FB1A78CBCULL, 0xB1F04688BAC92C11ULL, 
            0x528E4610C92E7687ULL, 0x743B16D56B3E45A7ULL, 0x43DCABF502DC6C89ULL, 0x2C00A214F5A6F4B0ULL
        }
    },
    {
        {
            0xA25D5DE3D45D1E10ULL, 0x6A17CF3A29D18E70ULL, 0x8246F8CD07E0262EULL, 0xD9D20F9BA973A4E2ULL, 
            0x4CE6AF1518E81B8DULL, 0xFA376BED2AFEB317ULL, 0xE82B3136CC94173CULL, 0x3ABAD15D941C349DULL, 
            0x7A6C83451EE229B3ULL, 0xED8CE92A1FD1E8D6ULL, 0xCA0F544163F4686DULL, 0x4FDD05E72954307DULL, 
            0x78CE0D4B0DB04737ULL, 0xEFB0DE65B9F1C053ULL, 0x830DA4596D114320ULL, 0x2872869E17ABF3DBULL, 
            0x0FC568EC0A3EEE67ULL, 0x99D349F40AF33179ULL, 0xD42DB032D4917982ULL, 0xB2745548B1CD4E08ULL, 
            0xE2E30D9737C089D0ULL, 0x004FF96134D3D752ULL, 0x00B2B4C079650E60ULL, 0x9FF0FE4387F85E01ULL, 
            0x6ACB5C9B402E26D3ULL, 0x06B17FD3CE967E5DULL, 0xA7878C7A1093307CULL, 0x4F3283191FE77D86ULL, 
            0x77FE7586AB3CB413ULL, 0xAC186FACF002D87AULL, 0x6F27F9DF54CD4D19ULL, 0xE101EE35E4856D3CULL
        },
        {
            0x11350D233EE32DE4ULL, 0x3319DB6BC733C978ULL, 0xDC3B1A9C25B3A655ULL, 0x58C8DBA525FBDCD4ULL, 
            0x7E3455479F924179ULL, 0x663E5D141A3CDAC2ULL, 0x30D5581E6D7039C2ULL, 0x07E783504632B333ULL, 
            0xE4B666086EF11D2BULL, 0xA9674C86D65B4648ULL, 0xD362115BFF083DACULL, 0xC622F7DB192A0C93ULL, 
            0x1F081E7EFBDBD134ULL, 0x8D086A7448EDE1A7ULL, 0x5790962BC6E6D356ULL, 0xEE400FCA7D44C986ULL, 
            0x3B4667C74C1E5A97ULL, 0x259C65589F5DD2D4ULL, 0x3212C33032534091ULL, 0xB5FF034C2ED3A723ULL, 
            0x786874DD2710EEA2ULL, 0x838377EED1452F2FULL, 0x44EF1F0E1187FFEFULL, 0x3D685E802F31D52EULL, 
            0x28F7634AAD1BAC66ULL, 0x3AED1032B0527C0AULL, 0xEF4A5694EA7A90A0ULL, 0x9C6054A4BCA989EAULL, 
            0x53A50E8BEAF60EB5ULL, 0xC9EF2D3A40B97D12ULL, 0xBD0768603CCA370FULL, 0x539E12F2240EF2A3ULL
        },
        {
            0x4DB9F66A448FA2F4ULL, 0xE94A3334C850C63AULL, 0x830505F837A1BFD5ULL, 0xE6E850AC8B00C38FULL, 
            0x79FFC6D4BAAD64A1ULL, 0x68B89F63181B5523ULL, 0xCF637D735BB64D8BULL, 0x030668C1BD55CCCDULL, 
            0xF6CD5CE838F6DE90ULL, 0x4B2188738893A233ULL, 0x6BF920615005323EULL, 0xCF7F0C09358CFA1BULL, 
            0xD65A7C369FA0BE11ULL, 0x3BD5FB32B5DA7299ULL, 0x33E177309BC25A48ULL, 0x538FC05F125A3FCAULL, 
            0x735516DE13E22092ULL, 0xB22BA88D0FCADF59ULL, 0x74F242EC97EE98E3ULL, 0xFB4A1DC66796A325ULL, 
            0xF3BDE9E2BF7809DBULL, 0xFC52FF02E182F3C4ULL, 0xA00CFBF3D035B33DULL, 0x69253CDB887D64B2ULL, 
            0x75A74E3B8B0C5EE3ULL, 0x20AFB1573108E1EDULL, 0xA5C8C4709EBD6750ULL, 0x390C942435F87E4EULL, 
            0xB941FDD49C503897ULL, 0xB6758C265C43792BULL, 0x1BD0A40A59AF3F38ULL, 0x136EA6DCD22BE771ULL
        },
        {
            0x7E52797116BB8BFCULL, 0x83F8ABDC54362DD0ULL, 0x99A9167E2C70C52EULL, 0x07240BBBFE0E9741ULL, 
            0x5BF7B1EDB0873A70ULL, 0x1CF4D452D66E3F83ULL, 0x96758F1ED5E30971ULL, 0xFBDC53EBA4749EC4ULL, 
            0x95E5D7516975A05EULL, 0x0F8012F7C57FCD3FULL, 0xFDFDD07D1A804726ULL, 0x16DE5DFCAF2E0E57ULL, 
            0xE675640F0A4618F3ULL, 0x2E2BF917F5E68D2BULL, 0x094FFF9A0F06C390ULL, 0x065F2B8B44CEBFF8ULL, 
            0xC39B18BD1559B91EULL, 0xED6A34AB8D12936CULL, 0x52A9B474A6CFD30CULL, 0x7B542E115677002AULL, 
            0x5FCE50311F2AD8DBULL, 0x92A68E1B18CE3FB7ULL, 0xF4DE199B1B887A02ULL, 0x0C5319DB76DE59B5ULL, 
            0x3B717642830734D6ULL, 0xF2D204E05623EA34ULL, 0x773190599803E37DULL, 0xDA72759A21DDC715ULL, 
            0xD11A978986CFA879ULL, 0xE4AB0AF935498085ULL, 0x322EE5BBBAF73746ULL, 0xA1970965525A089AULL
        },
        {
            0xD3C038D1DEC4564AULL, 0xAB7E036D2EB6EAF6ULL, 0x39D783397D5CC337ULL, 0xA65D0E945A3130AEULL, 
            0x87949CB76FC05110ULL, 0xAE739CEC9E380C5BULL, 0x556195B835B23299ULL, 0x63F7545824DC8F82ULL, 
            0xC00B83B1C8CE0260ULL, 0x6D4FA87CB6ADECC1ULL, 0x42188947EA5B4C71ULL, 0x80659C4018301764ULL, 
            0x8012238CE85C2F7EULL, 0x323B71316F41767BULL, 0x4A8A6A2E3862007BULL, 0x7DF41EFD37A2D8E6ULL, 
            0x9D1064BEBA468C7AULL, 0xE4676AD8A8C6D5F4ULL, 0x8DFCB66116F689DEULL, 0x8AE58BEE9550C175ULL, 
            0x2A6CCE4EFB5A463FULL, 0x359DA4E5FED0E10AULL, 0xE66A2AD9B05BB00FULL, 0xF32A7D2A3465E7D7ULL, 
            0xD4CF94FB3AD518B4ULL, 0x90FAB05CD31801C5ULL, 0x167716D931B9D9A4ULL, 0x4FC8737314917806ULL, 
            0x568B476BF79561BBULL, 0xB44221C92F7AB3D3ULL, 0xFCD4DFA8580A8D6DULL, 0x76394978E56466DBULL
        },
        {
            0xEE966FD6ADD479F5ULL, 0x6D22287A3BC5ADFFULL, 0x6521D0B048082584ULL, 0x60F4216280A995E0ULL, 
            0x85E7CB8F962CAFD4ULL, 0x41A3A8CC75F05298ULL, 0x23E43E665A2CB32EULL, 0x8950FEFB3BAAF608ULL, 
            0x4B7C16E9461B2E13ULL, 0x3C7EA3F22116E8E9ULL, 0xAED0895E5476BCD7ULL, 0xE2561C94904A35CAULL, 
            0xDCAC4E36AE1A4A6EULL, 0xF9E3159B4DBC0550ULL, 0x992E7934292D816BULL, 0x1173FEB4F20DDADBULL, 
            0xF4D6AFA6D6B9810BULL, 0xD3FE2A2D5039EB5BULL, 0xEAD73AB6743E19CBULL, 0x13838292CC4A780DULL, 
            0x92315006B285A2A2ULL, 0x251EEE0B5E9F1301ULL, 0x95FF477E761289E7ULL, 0x972C74733234C677ULL, 
            0xB36A732F4E935CADULL, 0xB23BD154A998F1FEULL, 0x55FBA84D109BF938ULL, 0xB34D99B2C61D14BCULL, 
            0x94FE4BB700205E84ULL, 0xD6C15FDFB0E174C5ULL, 0x35BCD6C7BC54585AULL, 0x0FBBCF6D48D87081ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseEConstants = {
    0x79340226BCDA84C4ULL,
    0x80B5E37B737E7479ULL,
    0x3766E38057CD9B98ULL,
    0x79340226BCDA84C4ULL,
    0x80B5E37B737E7479ULL,
    0x3766E38057CD9B98ULL,
    0x79867E96C271C59AULL,
    0xD57239C02F04236BULL,
    0x1D,
    0x23,
    0x3E,
    0xF7,
    0x60,
    0xC5,
    0xED,
    0x0A
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseFSalts = {
    {
        {
            0xD1CC58C26A06AE8CULL, 0xF5013DFA748E7F91ULL, 0xA11FC51F25052096ULL, 0xBD902F7A2DE37434ULL, 
            0xF13B53B1A9649348ULL, 0xD547C80D268F6F81ULL, 0x192D931351816E0EULL, 0xCA358DFBACAA56A5ULL, 
            0x94D5EACB7AF8C7C6ULL, 0xEA054479F04FE8DCULL, 0xD96DAC84045FE8A0ULL, 0x4F6911693E69B7AEULL, 
            0xB8F2C3E61AD68006ULL, 0x342E5147C0CA6BDEULL, 0x030864941F6CD37DULL, 0x677438C9482C6022ULL, 
            0xFEA1FFF62AFC45A7ULL, 0xC7AA24B535AECA72ULL, 0x88A3F95F9DC65097ULL, 0x52A79783C207105AULL, 
            0xBD3F5BA5C3AD81C2ULL, 0xF9FB4A36245404BAULL, 0x918A04178D26C349ULL, 0x298E4FF575FCCAB0ULL, 
            0x823B6EBC096C5C9CULL, 0x77291AD14AD8BA28ULL, 0x7AAA4695F88A4339ULL, 0xA97DB6C0B033D733ULL, 
            0xFE23651D2A068399ULL, 0x7F60D36228308D7BULL, 0x524F16B84D8F115FULL, 0xAD5A5885593E3F98ULL
        },
        {
            0x0CBA32D0686D591FULL, 0xE41871975398F0DDULL, 0xA662A835C19474B1ULL, 0x57D6787F2597FE23ULL, 
            0x6F99FC0FF0FC2C37ULL, 0xA63754FADDD2E483ULL, 0xE409E45E9A6A2956ULL, 0xAB412011185A4284ULL, 
            0xB3BD370CF440D11CULL, 0x11DDAA5E6820DBBCULL, 0xC98C5777D02E3C9BULL, 0x79AC9509B6477455ULL, 
            0xA87BA29564843197ULL, 0x181E1133196ADA4EULL, 0x2BBA0B99E6F8D8F8ULL, 0xF2985A5DCC180752ULL, 
            0xE5A93E747544FF7FULL, 0x1E26A0D51CB5D1CDULL, 0xED72B746221E7944ULL, 0x2F9D8C190455531CULL, 
            0x0A05645F415E1A3CULL, 0x6C1D8BEFE20E22B5ULL, 0x049CCE3BC8BFDB6AULL, 0xF67F9C93315FF937ULL, 
            0x0FD708F8A31D52C5ULL, 0x90F3A651DF9F2D02ULL, 0x838A59294C69C808ULL, 0x372431E7D78D13CBULL, 
            0x0E51530F3D165DFEULL, 0xA1C196C598D4353EULL, 0x307D7058E2A557AEULL, 0xF0D61EAA8120FAE6ULL
        },
        {
            0x7481B5EB5A430872ULL, 0xF8DC2445BF65600AULL, 0x05E883EA30AEEA19ULL, 0x7AA643F7B93703A6ULL, 
            0x2DE1C30CD4543635ULL, 0x30E6B553C191A733ULL, 0x5EA9FDFBFAB7090EULL, 0xD93C63809F038562ULL, 
            0xBF980FE085AD8B69ULL, 0x5E015EB433EA76BEULL, 0x63EE7284FD44B89CULL, 0x58FCE370C8F34C91ULL, 
            0x3BE4119CEE795C32ULL, 0x57C1A06D5307FC0AULL, 0xB609BBA26744CA3DULL, 0x5B5D213D648386F3ULL, 
            0x9626E64637C2EDFCULL, 0x1730EAA9236BBCF4ULL, 0x8D78F9CF5CE2C049ULL, 0x44ED69D580F20895ULL, 
            0xABDDD77022683FC8ULL, 0xEE24B46685457ED9ULL, 0x0FE5A78227F04A1CULL, 0x3D95D5B3C7AE316CULL, 
            0x648860E6D96881C1ULL, 0x0FA1DDD27F98DE34ULL, 0x0FEECDEE4175E1C4ULL, 0x175C3E381A8036DBULL, 
            0x761F19DDA5D56FB0ULL, 0x829F942A23D389E8ULL, 0x64E4B0BF5A8BCC69ULL, 0x6F96164A7196F406ULL
        },
        {
            0xF03AADF36C86BE15ULL, 0xBC96D0FFB5F1F61DULL, 0xC3116856941D2EFFULL, 0xDBF52C9F971BEE9EULL, 
            0x68E60A9A2AEE421EULL, 0x374DE7278BB71B6FULL, 0xD5635A1C6FF658DDULL, 0x9271DDB402503798ULL, 
            0x8027237D0B616E9BULL, 0xA49A56E0994CD564ULL, 0x6883590DE29CC135ULL, 0xC1F1732F76FC1229ULL, 
            0x13113AE633923123ULL, 0x41A3CC0760FAA4EEULL, 0x34D9ED7FEBE9BC99ULL, 0x246903002A6242DAULL, 
            0x441F15D6A77A4D98ULL, 0x46B8EE8E8C343A13ULL, 0xD5F38F6F50582DCEULL, 0x12C75F8996EE967EULL, 
            0x83AC8BE7E42525A2ULL, 0x2E28042C1F518DA6ULL, 0xDEB0DE7942C9FA66ULL, 0xF342A8542526B6B0ULL, 
            0xB20F4CD5DB7BB597ULL, 0x3AD8A6B59DDDAEDFULL, 0xD29871A4342588EBULL, 0x1F5AFDCAA3F88111ULL, 
            0x3A718BEB7A0B5D11ULL, 0x74BD8468F1247A0AULL, 0xE05AD2C1F7388595ULL, 0x11891DCD1B180967ULL
        },
        {
            0x2A14E2BAC338C4B4ULL, 0x23A17BC149EC44F6ULL, 0x2CAF91C25AD0E2AEULL, 0x469322B9C04430D2ULL, 
            0x9504659D71A547D8ULL, 0xE705AD9BE71F8823ULL, 0xC25CBEC5A7374985ULL, 0xEB2676AB4F2F3AEDULL, 
            0x5A78382D8BF30D34ULL, 0xA1AFE7EB2B0A8114ULL, 0x627E6DD03A693C23ULL, 0x777735A0EB959245ULL, 
            0xABB157029EE9DC12ULL, 0xA0B4CE69174D2320ULL, 0x028083C2CCC9686AULL, 0x739EAF277E56BCC8ULL, 
            0x7FC114771C9795F6ULL, 0x4EA3B71D23209C7CULL, 0xF3B4C868219EB9F7ULL, 0x902CA5E4805D7334ULL, 
            0x5382C4365D0C1B74ULL, 0x0DF3143783AA2E74ULL, 0x64012DE1E962C730ULL, 0x769E10F1F57FA6D4ULL, 
            0xEEC28F3BFB7A7540ULL, 0xDEDE1036BEC18937ULL, 0xC4D14EC479B81617ULL, 0x0B03597ABC2037F4ULL, 
            0x12ACEC3040CD47A2ULL, 0x09E804243EE4252AULL, 0x9729F82A32ACD365ULL, 0x9F7A5689CEA8001AULL
        },
        {
            0xD54C1573975462E9ULL, 0x54A52FE14B91D3A3ULL, 0x2B1F1D8E75C0F5DEULL, 0x4F21191D9FE6CF50ULL, 
            0x7C089CAE069C2C9EULL, 0xF7B6188FD2AE0C3EULL, 0x2D1936D683886305ULL, 0x28FF48F621898B4FULL, 
            0x27DFEC30F0698EDEULL, 0x2CF956A7C556C0E7ULL, 0x63D41FF5006FCCD0ULL, 0xF7253F69BC20B801ULL, 
            0xC77E14B9B78305DDULL, 0x644AB5FA1AEF760AULL, 0x2EE593C5E647E50AULL, 0x50FC4DD782128D54ULL, 
            0xA9D6FC32784343C1ULL, 0x1C3E6D3589748A0EULL, 0x57466DAF767DC283ULL, 0x5A97415A27C40862ULL, 
            0x2D717B943ADAAD99ULL, 0x311D6D4F233CB35EULL, 0xC84352FE74B209E5ULL, 0x44E1B202871A4DECULL, 
            0x4E9B9D578DE5179BULL, 0xFC18DF0307B804E2ULL, 0xD87B60551B7CBC90ULL, 0x25BE92B1EE706AD3ULL, 
            0x92824B32B5A6C32FULL, 0xBABE290EEE6014BEULL, 0x4110389B9E8D95BFULL, 0x043F2CACF8E3C99EULL
        }
    },
    {
        {
            0x5CF02A41FE407ED1ULL, 0xC1EC22C13ACE9B45ULL, 0x3CBAA42775EF1D42ULL, 0x6E039D95C25EEDB7ULL, 
            0xD9EC44258DBB7990ULL, 0x6926F5C46DC997BBULL, 0x059D5ADD18F57D3FULL, 0xC9B95093E8069E1CULL, 
            0x48F88358613070D4ULL, 0xE3990EAEB4460DF4ULL, 0x1A4C468FE0F0DF31ULL, 0x5663166F46E96A97ULL, 
            0xA96921EFF82A0AF9ULL, 0x373EC51346FF12D2ULL, 0xBD1870F5217079BCULL, 0xA964126E1FBE4D46ULL, 
            0x15BC01186613E1A2ULL, 0xDCA32A379E105AE0ULL, 0x5F978E1990D6FE28ULL, 0x1628696E6C86078EULL, 
            0x4B3DC7B2C7BDA937ULL, 0x1021E847AD443B54ULL, 0x052BB60275DC45FBULL, 0x57F0D9DDFF0F5304ULL, 
            0xFEA3F011A5182212ULL, 0xE5384FAA9A5EE1C0ULL, 0xA2BA410D18DBCEE7ULL, 0x51D7E239E0191987ULL, 
            0xCE56E2D5EB5A15A3ULL, 0x5E7F637789868EA7ULL, 0x141D61A08045A35EULL, 0x455FFAD5CC0C70ECULL
        },
        {
            0x6EC29F10F68957BAULL, 0xF362D691BC8AA663ULL, 0x5680C1F1A701952CULL, 0x2C800E215A04A57FULL, 
            0x01BC39955C5082CAULL, 0xF0BC6AB73896C3D5ULL, 0x1B27BF57CC350284ULL, 0x3C48B8D480352D77ULL, 
            0xA4EFADD171122DDAULL, 0x9046ABF8AFD4F035ULL, 0xF4B4632581CAF153ULL, 0xCC762C08520FF62CULL, 
            0x236AACEE88CA7BB6ULL, 0xEF2501D374B0DAEEULL, 0x8CAD9D31627511A9ULL, 0x4B6EE3EE5EB6CA11ULL, 
            0x51C463CCB67A6CF7ULL, 0x593E64683D0E2446ULL, 0x51EA58EFEEAFD15BULL, 0x72206CE6ACE945FDULL, 
            0xBDC1BF0BECBA605AULL, 0xEE2EFE60C125B123ULL, 0x891C1762BB9E923BULL, 0x55C1B8005369A3ACULL, 
            0x441811D8ACF590A9ULL, 0x1C09E101E523114BULL, 0xED558ED71BFB1CECULL, 0x1D7833F97E8C17F5ULL, 
            0x3A12A872FD028F5BULL, 0x862F19F1072FBDA6ULL, 0x0092DEBC88DDFB38ULL, 0xBFB2FF048AE19484ULL
        },
        {
            0x859CEBA3C7885DD8ULL, 0x5E8CFF298480C873ULL, 0x9778E0E9C2E9FDEEULL, 0x94299049DF800FBBULL, 
            0x5283A78CF65C98DBULL, 0x22C323A0A52D3086ULL, 0x90023E705405DEF4ULL, 0x385806789D07182BULL, 
            0x09FE2A0346AA854FULL, 0x31CEE20A64F8F96DULL, 0x21A1BB47850ECC9AULL, 0x3F54730FEED70906ULL, 
            0xCCDB4D9D4919C428ULL, 0xF3FA7667FF89B50BULL, 0xC5BD8E927C8BFAE4ULL, 0x2CD15F558667A4A5ULL, 
            0x91411CDB8859FBA2ULL, 0x04888123489B1F6DULL, 0x837090749C9A8148ULL, 0x3B8B3D04EC4E9CE4ULL, 
            0xBF7B8BF0D60F4D39ULL, 0x6A471A051A2ECA23ULL, 0x047CAEDA96666A57ULL, 0xB73586CD7B44C409ULL, 
            0xD3FA94631D006F8FULL, 0x9DB653424F90CAEEULL, 0x079CC7895E75246DULL, 0x39D7C7BD7BF4E774ULL, 
            0x049A8743AF0214C4ULL, 0x485DFE5892012B4AULL, 0x6BC5D2290018264DULL, 0xD9DBB5BF1011E231ULL
        },
        {
            0x87BF5A672C5FDB7AULL, 0x1E0812EEDE179E57ULL, 0x16A83D2FADC71D40ULL, 0x20520E39828B070DULL, 
            0x3C6A249B96FE320EULL, 0x5077E0CD1E1AAC48ULL, 0x1F487292C2901561ULL, 0x9841D80AC2293F4FULL, 
            0x858EE64EF26C8F47ULL, 0xA4C4577BE159CA43ULL, 0xA1E8B17460140667ULL, 0xE194536DE75258ABULL, 
            0xB956045706F7F45DULL, 0x23512093392AB6C5ULL, 0x57D47C38C59BE54BULL, 0x70262D0F1A9369D2ULL, 
            0x2D699281377E2469ULL, 0x66A51322B7723C4AULL, 0x738CA7D17BE4DAE4ULL, 0x571F3B544CEDC2BDULL, 
            0x59A628FEA0F770F8ULL, 0xFC9DCB1704B3BB8AULL, 0xDAB1BA872138FD0EULL, 0x5537E60660B2F79BULL, 
            0xC44053CAF5E85712ULL, 0xE350544C715D4F70ULL, 0xCFE4B241601E1484ULL, 0x8B817B59ABD7749DULL, 
            0xE76DBF42A806C645ULL, 0x37DF7C9BE0395305ULL, 0xB55A1BF0817CF840ULL, 0x2663043F072F47C1ULL
        },
        {
            0x3F6ABA08B81F4F75ULL, 0x1902C007A7922BFDULL, 0x5DDCE8FB7FB7F7BBULL, 0x41FCE7F9501905D3ULL, 
            0xAC8286702FAF0DB1ULL, 0x5E05EFC66477E0A3ULL, 0x8992D00AF7EA8C40ULL, 0x9B12704E0141FB06ULL, 
            0x2D8A441DEE813A73ULL, 0x8708415BD9720971ULL, 0x2BF401149116300AULL, 0x00A1B24B1D856134ULL, 
            0xA56377A5563D1EE4ULL, 0x496F1ADA6887C895ULL, 0x103C66C637E17838ULL, 0xF5A74E551362DD16ULL, 
            0xBA9D1A916F19A38BULL, 0xF92FB93F05F112DCULL, 0x05815C7476A731F4ULL, 0xA384AD80E5E9DB2DULL, 
            0xC64FE7D3AF6231B4ULL, 0x393109D8B25EEB13ULL, 0x878BE22B1F08F5BDULL, 0x52B2FD786B5137C4ULL, 
            0xA246C8A009CA3563ULL, 0x2D4B80180526335FULL, 0xACBADA1D69D2B93FULL, 0x483028A138DA3DEFULL, 
            0xFC586FA0759F746FULL, 0x4A909861040B352CULL, 0xC4531A7C705AE763ULL, 0x640C7201F785F912ULL
        },
        {
            0x1D478F71ADDE434FULL, 0x796C25AEE9E21539ULL, 0x34F1CEBE2D696005ULL, 0x1DD2EB8C2085131DULL, 
            0x13DDC0B6674585DDULL, 0xF7FB5344C5BCFDFDULL, 0x929A015BBD012EEAULL, 0x94B75FC0C4098758ULL, 
            0x8B2FD485B93B3687ULL, 0xF738D88B76C79A33ULL, 0x80AFF7F3E730604EULL, 0xA0F1F1865F7353FFULL, 
            0x27024BBB1A8FD3A3ULL, 0xB83DDC9135BE29D3ULL, 0x4B41499C3953541FULL, 0xD51B72F221EA4CCAULL, 
            0x73727F7A5457AA21ULL, 0x48E27A4F49F5DA96ULL, 0xF8E1FF0DF9BF5E5FULL, 0x5E9FAC043C8F9D22ULL, 
            0xC50622F9ACCE5EB1ULL, 0xE05DC2EEAD99D69AULL, 0xDC837E22B9F2FC89ULL, 0xF18753D3C5FABB01ULL, 
            0x36A24F66A9D9BBBEULL, 0x712FB608B14E8889ULL, 0xFF7F56F1AEB4ECEFULL, 0x0927F705EE8C370DULL, 
            0x7602E31F5A6AA08EULL, 0xB962F15D4BEBF121ULL, 0xD11C229FC37965F1ULL, 0x53EA33F2F4BC3BB3ULL
        }
    },
    {
        {
            0x9EDF229E25F8C661ULL, 0x6325C034351F77C9ULL, 0x9698D01392208A46ULL, 0x0ED2B62468FDBA3CULL, 
            0xA47318FEA873B026ULL, 0x6EE7E33E38F217FCULL, 0x85DE952EC265220BULL, 0x3E87750411030ECEULL, 
            0x835D8860919FFCCCULL, 0x2A9CFEEC13C39C45ULL, 0xCA76B7966F409EDFULL, 0x2392F567D060D4CBULL, 
            0x62851E36E3E8BD8CULL, 0x01E6424E417CD4F3ULL, 0xF514C69D7F03109EULL, 0xF21D1F6D8BBE3917ULL, 
            0xA75BDBFD1F249583ULL, 0x79CC0A8928E2DD3FULL, 0x0B6EF5CDFDF35B41ULL, 0xF6F2F0A37BA2DDE5ULL, 
            0xE2F0EF97D33D78A2ULL, 0x1E7E6FBA3397F370ULL, 0x9694037F13349014ULL, 0x839D1A613E01FDDDULL, 
            0xE4550B38B8F3C519ULL, 0xC66C6B42513CE364ULL, 0x0F0D28552A461AA2ULL, 0xE77C83D97973E0DEULL, 
            0x6F010E0DF89F51B0ULL, 0x6A7C26CC97582D4FULL, 0x0D7510967936FE1AULL, 0x146E168865C23D7FULL
        },
        {
            0xF1B1BB69119284C5ULL, 0x7B5EA55B5FFB957EULL, 0xFED489D28BEF3802ULL, 0x938E2603AA03D85CULL, 
            0x34C2690881E51FD6ULL, 0xE6FB7DC0875DD0D7ULL, 0x805D2DAD1A219E55ULL, 0x967C739A5FFED2A9ULL, 
            0xEE3AEA33759E1E28ULL, 0x48C9EB4CED97ECD1ULL, 0x7BB93C1B44FAF261ULL, 0x30C826D7644E4433ULL, 
            0x2DD038F6C191B1F8ULL, 0xA5CE9AA8363FCC04ULL, 0x142109C94081159EULL, 0xA222D949DD71083CULL, 
            0xFC4F99EF5D4E1F41ULL, 0x6116D0A2B1D3AE63ULL, 0xBDCB952233B5A942ULL, 0x39149FCC69D9F570ULL, 
            0xDFB0D44A6DA932B0ULL, 0x4F008925124F49D7ULL, 0xA45200B20184B088ULL, 0x1E8A600D7DCB0FC6ULL, 
            0xDCDBDA6A87F1B47CULL, 0x5EE8B7D212D2C644ULL, 0xD68E5F4E1F69793CULL, 0x83EE5A5198A28B31ULL, 
            0x6B5B015F910D94F2ULL, 0x235BB16AECDA6941ULL, 0x7790A62770260D98ULL, 0xE3AFF9884303DFDBULL
        },
        {
            0xF957FCD108D9C141ULL, 0x22D0B9C5892CF83EULL, 0x67BADC7587AC946EULL, 0x648C03E2525A6EC0ULL, 
            0x92BF19B5E07AF8E0ULL, 0x9F0CA92593152437ULL, 0xC5324DEE403AFF0EULL, 0xD2EE3D4F51514B72ULL, 
            0x12D10E2FA2FEAECFULL, 0xA7E050DB84C0C44CULL, 0x91B5CA87E0732A90ULL, 0x989008EFEEFCC7B2ULL, 
            0xDCAF939683001DF6ULL, 0x07F32B60F95866FEULL, 0xC49EB3C3D3DF5586ULL, 0xB3099B0CF0114582ULL, 
            0x1005DA2CCD24D2D5ULL, 0xF11C47D52117C0DEULL, 0x55AF70E17C57956DULL, 0xF2D05660404DD4DAULL, 
            0x91BD9FFB2A05B59BULL, 0x322A55BE405E3AA3ULL, 0xCBEAAC070785D7A8ULL, 0x57B5BCD4ECCACD34ULL, 
            0x6BBC6ACEACBDFBA2ULL, 0xF94F5EE74F15AB11ULL, 0xD2D63DE83CD28D32ULL, 0x7DAD53C9C9A1F066ULL, 
            0x1E59412D30905E4EULL, 0x3A7BF7DF9D874570ULL, 0xCF34C4CCBAEF6CBDULL, 0xA69C6B64DB078EC2ULL
        },
        {
            0x5150DAAB8303876FULL, 0xC80BE6A85101BBC4ULL, 0xF692FDBE99EB44FAULL, 0xE6792889C11A0A4DULL, 
            0xF59A4648A6A1D651ULL, 0x1E8334D27938D159ULL, 0x05F22C7830CB3B18ULL, 0x308BB5A5011DBF2BULL, 
            0xC1454AA782C2AEECULL, 0x62B61AC0BBE13587ULL, 0xF85C28EDE3EB1CA6ULL, 0x4754D0FCF4C8C473ULL, 
            0xFE1C859131BE07D1ULL, 0xD6446CF55D471CADULL, 0x5F072ECCF2301EE3ULL, 0xCBA4DD74F3760FD6ULL, 
            0xD2CF893B76BA5281ULL, 0xC0BB6E66601D1089ULL, 0xA03C4A9C7B0D64DFULL, 0xFAD6988B85FCD1FEULL, 
            0x818375AC180E3F8AULL, 0xAFF6D231D8E75F99ULL, 0x4599BFBD2A6280C1ULL, 0x578FEC21A178BCF6ULL, 
            0x597364DD6B65BA0DULL, 0x6C42A8502AC6D47AULL, 0x66E12EF72BE6226FULL, 0x4A56EA1AC07EB372ULL, 
            0xB18401A5C9175567ULL, 0x4C17CD80937D67DBULL, 0xFD82898126E60D6AULL, 0xEBE54E01D1BFCC8BULL
        },
        {
            0xAFE3ADC51561C132ULL, 0xC397AA6AEE013035ULL, 0x9BF5D93ACE84D5A9ULL, 0x43E6C43166AF78F9ULL, 
            0x0B5852CDE358EF8AULL, 0x0C21F1077E92E0D4ULL, 0xCD5FA3E213571873ULL, 0x18702A55E16D27BDULL, 
            0x5F83B41DD8F634EFULL, 0xC9D14B85251D83C8ULL, 0x1F3BA3350A7CB80AULL, 0xD178C5B19B3CA1B9ULL, 
            0xDF7799DA3319DB39ULL, 0xB951A5AE8D7BD262ULL, 0x252E413ACE5AC01FULL, 0x490C0D8C370193DDULL, 
            0xE45972FF0A61F7B7ULL, 0xF5920E88C9BB2317ULL, 0x0BE35FAA3EE5EB9AULL, 0x4C8FC9269FD10140ULL, 
            0x6EFB2E431F7E9939ULL, 0xF118CDD7D6BC83DCULL, 0x9EFA3D3D94AAC8FDULL, 0x9509811FDDA7F208ULL, 
            0xA617338828586ECDULL, 0x56F73AE611ADE905ULL, 0x40B783BEBA28F2C5ULL, 0xBC4687D22D416CF5ULL, 
            0xD0823A01A59B19B6ULL, 0x47FFEE66AF58C838ULL, 0x4BE07D70CDE46C2FULL, 0x210222E03C6B968EULL
        },
        {
            0xF44093B4A6836675ULL, 0x98DA870826A3E6D3ULL, 0x22B8ED1DE7F64D6DULL, 0xADD44F6B697D06DEULL, 
            0xA49F8AA32C2776DDULL, 0xA953EDBC09F6E3A3ULL, 0x08CFD35FAC24FDF2ULL, 0x2091458AB68ACA65ULL, 
            0x780F5677D409314BULL, 0xC69CF132A425804FULL, 0x251D6B558027C38BULL, 0xB080FCE661197A33ULL, 
            0x9853F125F2FA7EBFULL, 0x871FA6A080067DD9ULL, 0x1C5D56E5FCF9A4C1ULL, 0xB89972D72E98BE3FULL, 
            0xA8441D13F369C222ULL, 0xF369AB45A62FB2BCULL, 0xE2EDC34362242221ULL, 0x1EB4AA0B092F3EF7ULL, 
            0x3B6D04B7D4931DBFULL, 0xD2A6B05A9E6B72D0ULL, 0xA4B81B35CEE7B295ULL, 0xF9D878E62AE3D966ULL, 
            0xEC50ED1B396CB813ULL, 0xAD4F55E2AF3E39A3ULL, 0x094EAAD7B139D0BAULL, 0x9E8880EE6F394557ULL, 
            0x0FB70FF65BB747F5ULL, 0x2A4DA458FA60CCDCULL, 0xDA60872B5CED6650ULL, 0xAE6954F7C2C3E826ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseFConstants = {
    0xAD4B2B3CEF7F61D8ULL,
    0xB6541EBE69DFC8D9ULL,
    0xCC565C46BA4CCB5CULL,
    0xAD4B2B3CEF7F61D8ULL,
    0xB6541EBE69DFC8D9ULL,
    0xCC565C46BA4CCB5CULL,
    0x44C961460E4B6598ULL,
    0x6A34796A66B0393DULL,
    0xEB,
    0xEC,
    0x71,
    0xF3,
    0x3F,
    0x9B,
    0x88,
    0xA6
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseGSalts = {
    {
        {
            0x9F8CC070EF08F945ULL, 0xC8BD46A7599ACEE6ULL, 0x13541BC170A8E83BULL, 0x00C1901B8B510E2AULL, 
            0xFC57D59B96B14E41ULL, 0x9EE07F15CA194FFFULL, 0xDB870ADF1C44FBE5ULL, 0xE7758194CF4EE4A7ULL, 
            0x3B85633273F0A47BULL, 0x24E597E0E2E22537ULL, 0x649026C78D3F5660ULL, 0x268139B56D56A2EAULL, 
            0x0CA389DC10BAAF48ULL, 0x7F023DB13048E99DULL, 0xD85133C0F668C527ULL, 0x6A92535AACBA03BCULL, 
            0xF0675F11B59F2A12ULL, 0x367B50B86AABA2C7ULL, 0xF1830B4F9350F656ULL, 0x0AF636376110057BULL, 
            0x0360FAC4344E8189ULL, 0x2F49EBC63B0A9BF3ULL, 0x378B16B1023B3754ULL, 0x0D86C0B4E03C33D1ULL, 
            0xAA868B28D598EF8AULL, 0x639CDFAF55B9F711ULL, 0xB2BF48F40596475DULL, 0x05EB4948ABD34491ULL, 
            0x0335C2D933CEBAF2ULL, 0x79A81B57D5E6AE59ULL, 0xA972CE2044D08863ULL, 0x05587FE91BC37354ULL
        },
        {
            0x05FAC6573B1673BBULL, 0x022A436B1313D60DULL, 0xCEBD540AEB8EDEA4ULL, 0x5349AABB342F3E69ULL, 
            0xEA8AF4DE3F63AFFCULL, 0x5A23C527D02868C0ULL, 0x70D2EAA22FFA55C2ULL, 0x4F345B281650F147ULL, 
            0xCE3A4E8B0CDC0097ULL, 0x022B11114BB08188ULL, 0x8E3642B6C9320A85ULL, 0xE67718FACB7D7B55ULL, 
            0x735CCED7DBB9B09AULL, 0x6FD08D2DC44B2FE1ULL, 0xEFDBB03FEC4B8592ULL, 0xF0D0166C3CFAFF09ULL, 
            0x9B8992B591ADD1B6ULL, 0xB3F669DC63E0FDDEULL, 0x60D628D5FDFD1BB5ULL, 0x6C632765BAACF90FULL, 
            0x8B455206221DDD74ULL, 0xD9B709066CD6001AULL, 0x9803CD47CF15CA32ULL, 0xFBDAE638435C36F7ULL, 
            0x56F32E5E89B7999FULL, 0xB563CC6443D9A4E0ULL, 0xCD6D66089D9FF0A0ULL, 0x85E9B97153FFDBBFULL, 
            0xE8F1951CF7FF4FB6ULL, 0x74C85D178D7FD100ULL, 0xC98489C8943729C0ULL, 0x720BB8687F904BBEULL
        },
        {
            0x3BDA33CF204F4F76ULL, 0x0C9B13050711E847ULL, 0x00A80DA62B710DA2ULL, 0x5639B1349CD28F54ULL, 
            0xAD55FE71458591F8ULL, 0xD95C6F30014202B4ULL, 0x962E166CC1EAC8F9ULL, 0xA51713C042C36403ULL, 
            0x207C6A9227C6E167ULL, 0xCC579F3965FB6E3CULL, 0x328EF51B4D1E89ABULL, 0xF57D76CAD646F230ULL, 
            0x7AE97B89AEC287B1ULL, 0x6A63CA37641E3B99ULL, 0x298151FF68431E90ULL, 0xDE01C342F7BADFA5ULL, 
            0x4C137D8603AEFF1FULL, 0x99C60B4327710860ULL, 0x04824CD8AAD54F21ULL, 0xB4E63815885105EBULL, 
            0x918CA832D46679ADULL, 0x4F67132A861E4E3AULL, 0x701004C14218B222ULL, 0x03D688E9AAD3486BULL, 
            0xAE7B2856206AA2B3ULL, 0x76A989DBA1AD9136ULL, 0x86C20A286B3C09B5ULL, 0x67FC9DEDEDF311A9ULL, 
            0x0B0EA9F67B511E49ULL, 0x06F659BA329F3C97ULL, 0xAEE28EB671F9418BULL, 0xB67FE049B9DC94C7ULL
        },
        {
            0x87AB00E81264A83EULL, 0x1D1E115C6E837E94ULL, 0x95F7BF146D37AA17ULL, 0x42687070A1217584ULL, 
            0x59A9D900968A01D2ULL, 0xA62E9F1D342DE41EULL, 0x32DF91C2B938109BULL, 0x0800C2923550C2A1ULL, 
            0xAA643198FB23A038ULL, 0x8D088676FCCEC3CFULL, 0x941CBF687A3DC480ULL, 0x73C5DC3EF5F6651CULL, 
            0x72BB0C9488C27D74ULL, 0x6930B86133001C3DULL, 0x7C55F311096AA58CULL, 0x02DD97B74F59F83CULL, 
            0x8FA9FCDC0323FC3EULL, 0x12857D5D6E911E0DULL, 0xF8309B2577EAA069ULL, 0x91C6B66AA68680F6ULL, 
            0x0F6E24DB004B9DEBULL, 0x094B5121F79FAC20ULL, 0x889F7851E8D78FCBULL, 0x5708BA4448576429ULL, 
            0x7F86ADF8DF5EA420ULL, 0xD03F7D23446A9822ULL, 0xA5664CD85116F0FCULL, 0x1EA63E47FC42F3E4ULL, 
            0x04CE53A27F0C0C07ULL, 0x4C7DEAF7CE458341ULL, 0xA94EC7E9367D9543ULL, 0x4119CEFB37B74398ULL
        },
        {
            0xD7831A9F454F1C83ULL, 0xFC486E5C4FCA834DULL, 0x18609396466D0E60ULL, 0x4E7A447FC576FA30ULL, 
            0xD3FF17C319332DFFULL, 0xAC4D2CBBC032982FULL, 0x04FF1BDDB02DF8EBULL, 0xB9B12AB47102606DULL, 
            0x7E18CC1E8DA63046ULL, 0x261979AFCAC968D8ULL, 0x360D65167A314EEAULL, 0x4F0239DECB708442ULL, 
            0xDEAEE2E94EA47264ULL, 0x8A7423B2B442AFEBULL, 0x64F23C574CC839CFULL, 0xA6036E9624526A8CULL, 
            0x2B3EB25425DC3FD8ULL, 0x464BA95845AEA602ULL, 0xF4168DA20C51C8AEULL, 0x134903763D597CD0ULL, 
            0xAC62AD742224FC1CULL, 0xE33F9B283CB96A8FULL, 0xBAC69F9D9C0B48E9ULL, 0xFD2ACAB2928E4EA7ULL, 
            0x8947C8FF448DAFF2ULL, 0x9C7F8EFD7BCBAB4BULL, 0x5F13EF3D718877A6ULL, 0x6CE921FA112C7DC2ULL, 
            0xE5633B23330CA019ULL, 0x0EBA30AD239D6AD1ULL, 0xBB8428F26807F4B8ULL, 0x424AFA3B7BA486CBULL
        },
        {
            0x5C6EDC24860F65B7ULL, 0x1C91955D475E93FAULL, 0xEC01715DF77AD690ULL, 0x8B3B86467B6714DEULL, 
            0x0E38ECC8A636A910ULL, 0x181F289A5F5D19CEULL, 0x4D79A843E42992D8ULL, 0xB4F3C9DB9D6337CCULL, 
            0x8CCF94F7BFFF82DFULL, 0xD0AEEE20A14F7500ULL, 0xE39865B087E7A6BEULL, 0x1F7BFFBE34D88C90ULL, 
            0x5932A65F7334C66BULL, 0x5F82CD5DD52D801BULL, 0x79FBDA7580D34EFFULL, 0x685008B139B29C63ULL, 
            0x167DE43417B9AC6AULL, 0x01A4A3DA6C3881BBULL, 0xC050064B298504E5ULL, 0x1983127CF65BAB7FULL, 
            0xE832D608E58CCEABULL, 0xD67AA9635DA0B945ULL, 0x1971D6DE48422E46ULL, 0x01C84E6253D17FE0ULL, 
            0x691836DA791D7675ULL, 0x0A74210FCEE7D361ULL, 0xC9C9316E516370C5ULL, 0xD664E7E4B99503AEULL, 
            0xB0F852246BF29012ULL, 0xB1E20DD0426ADE72ULL, 0xB0E60C3F4F68C7CCULL, 0x07B2518BC81CA58DULL
        }
    },
    {
        {
            0x47C591E3469F990BULL, 0x1630449EC4B7C360ULL, 0x605E87E549735108ULL, 0xC7DCBAA6613D3ED6ULL, 
            0x6E7274DE20FE08A1ULL, 0x375DC0883501F15EULL, 0xAB74ED07B6B4EA82ULL, 0x4E0FF9AD688F5D9CULL, 
            0x6B5457DB70D809C6ULL, 0x9C653CCFD29213EDULL, 0x502E18E97D60B3CEULL, 0x8235F624CE793943ULL, 
            0x94B7504B21C7BFEEULL, 0x8A299E9C3EEF4986ULL, 0xDFC1BB87E26C1FB4ULL, 0xDC35AB3111206E31ULL, 
            0x554EAD9F76D1EF31ULL, 0xD0B625B04A2AC8E4ULL, 0x5455186AE2221D19ULL, 0x71C65CD700717193ULL, 
            0xE2EB17CCE78B5EE2ULL, 0x0A7692CAEA5FD952ULL, 0x867BA9D6FCEB93B6ULL, 0xA2722A368B34E9F4ULL, 
            0xC275513FA2F7C532ULL, 0xDEC4D586063831ADULL, 0x1F18A7F7BCF8CE80ULL, 0xC06F3A0EE9FD37CAULL, 
            0x07639811D551CA21ULL, 0x17A721EA50D53B8DULL, 0xB39311394A271AD5ULL, 0xE4FE3A2612FBA800ULL
        },
        {
            0x70DC01A0E03A1312ULL, 0x5C3E3B5E97B7FBF6ULL, 0x2150296C434F65CEULL, 0x712BB15FD461EEB0ULL, 
            0x8915E902FC054135ULL, 0xC19299C0EEA99952ULL, 0x229A7A984BCB520EULL, 0x4908E7090ABF738AULL, 
            0x785778B315FC9013ULL, 0x0B26B4047CD3DD60ULL, 0x7C982643AD334BDBULL, 0x9073ED2DECAE6A7CULL, 
            0xC9081115286BDE9BULL, 0x2FDFD5C011B8897FULL, 0x11B40B3C4FEABA06ULL, 0x9B675B60C0CE7679ULL, 
            0xDD408226C9EF9772ULL, 0x7B1F7BF96C0B1829ULL, 0xCF71B72D95093E84ULL, 0xD9E3D7669B59E7F3ULL, 
            0x92D8DF07DEA205E0ULL, 0x8D150BBBA7964E5EULL, 0xF35F13A68754E945ULL, 0x651F161899D81283ULL, 
            0x2FDA03649518F56FULL, 0x4CAC21F97D2E8AB5ULL, 0x184C10EBDFAFA273ULL, 0x386982619D805973ULL, 
            0xB577EED2E21AAFD9ULL, 0x5AE0A3260A727C0EULL, 0xD55AF3D4B76CFEA0ULL, 0x77332530976B9144ULL
        },
        {
            0x9736338C7E3170D1ULL, 0x526F020A074143D8ULL, 0x1D7B022ADEEBBF8CULL, 0xDE939B7F664B33F8ULL, 
            0x6CAE06A66FDE9AC2ULL, 0x7F1F540A27A178E4ULL, 0xC6A1454E1C764143ULL, 0x153E61F305235549ULL, 
            0xCDAF6D34EBB2372BULL, 0x3E3EA6C6B05ADD86ULL, 0x2477E2FBD61210DEULL, 0xFE31143781667506ULL, 
            0x553C69EF79EC9592ULL, 0x32E655A0A6F7FD5FULL, 0xF7F68659E0D63804ULL, 0xFAE0CA65CF07AC4CULL, 
            0xE616AA374CFA0498ULL, 0x5405A4373EA861ABULL, 0xD6665E9BABC53E1DULL, 0x47CAC01CE5807101ULL, 
            0x0481787D108F6012ULL, 0x85455CD7804C44BDULL, 0x11870DD05B67601DULL, 0xAF59A73875A5A00AULL, 
            0x203D7365B596178AULL, 0xD28BB71FD3F54183ULL, 0xE5AAA4DCA4433948ULL, 0x4CBDF162D5D13FB1ULL, 
            0x40E7D4BC2FB2F67CULL, 0x6878F4FBD45BCDD4ULL, 0x16A81D18A2DCFF3EULL, 0x3001A868662B7C4BULL
        },
        {
            0xFEB197AB26FBC66DULL, 0xEC2E431D1FB90697ULL, 0x33720B4C14752DFEULL, 0x4C79C45DAB22F035ULL, 
            0x8340077FA6DB78DBULL, 0x8C80EA03822B75BDULL, 0x90FB14E2BE0919ECULL, 0xEE75739B58B2843CULL, 
            0x408E4083B34D67FAULL, 0x3CB68D79FE34E895ULL, 0x12E64C9AC28B8F82ULL, 0x1B66A8277236CC41ULL, 
            0xE416FAAC3F957E29ULL, 0x2C4077BE9AB1B093ULL, 0xB7494FDA417123D4ULL, 0x14B6D78047599358ULL, 
            0x0213BFBD34FB1D75ULL, 0x57139EE2B6152392ULL, 0x42B6B8B6E4E945AFULL, 0x86F5685B4382966EULL, 
            0xCA7525E65F7F7E2CULL, 0xE13E2C8A0A498186ULL, 0x01E6B89A61A6539DULL, 0x09C10E8D6DB99F5DULL, 
            0x1C165E8F2DCA0FE8ULL, 0x2854E28CFE478F8EULL, 0xE258CE960AAB99BDULL, 0xB8FEFBEC0A64F869ULL, 
            0xF33EF2853A23D71DULL, 0x65C2BEED219EEA48ULL, 0x7B5590AEE3587760ULL, 0x3E2FCBA122BAB65BULL
        },
        {
            0x6F24032819F5D9FEULL, 0x0DC0772F4CC70FB1ULL, 0xF5D33E8A9A4562A7ULL, 0xDC2895DDAB222193ULL, 
            0x32746B883E6DA6B5ULL, 0xBF4F11C200E04A97ULL, 0x4D2291CDCD29F163ULL, 0x9289A0FA422D9533ULL, 
            0xCD49B4B0556721B4ULL, 0xBDC8B52C9B8E875BULL, 0x2A038497B7D4B10CULL, 0xE253B7B9DCC2F336ULL, 
            0xA54344BFA9BA8D7EULL, 0x176D402FC3E16099ULL, 0x69D2038740176B99ULL, 0x7F10FF1C5146F41BULL, 
            0x19D6E46D8C8BF403ULL, 0x40CD29420FDA3CB1ULL, 0xDECFD64D407BF76EULL, 0x13650A84E1F69A92ULL, 
            0xF78488699EB2386DULL, 0xDE1B3AD291FF5277ULL, 0x8451AC107085A686ULL, 0x6CC37E1268DA9F5CULL, 
            0xF59151D2F6D0F6B8ULL, 0x2F208B77A950AE24ULL, 0x03F9671799FA8458ULL, 0x890A3B76760CB295ULL, 
            0x80A28831FEB26036ULL, 0x5D009FEE705D55D5ULL, 0x58F41B01424B22F4ULL, 0x35165472514996ACULL
        },
        {
            0xC1B65F1855D53293ULL, 0x4BED139B8BA61347ULL, 0xD41778B2A2BEA119ULL, 0x92AD1A15CAB3781DULL, 
            0x6F630321C7D4F1F7ULL, 0x51BB886ABDBB1129ULL, 0x0F49D7E92ADFC8DFULL, 0x4209E37E59267EBAULL, 
            0x86E773F55BE40113ULL, 0x9A97C8E7E9FB01ABULL, 0xB8D465BA9E5EF150ULL, 0x20C1F11BEF6274D2ULL, 
            0x0525F79001AE60CAULL, 0x46E8D83A76E27BB4ULL, 0x8954DA9E996CF1FBULL, 0xEFA76C6157B8F774ULL, 
            0x78BA58EBBC19A8B8ULL, 0xD22C9416AA498A50ULL, 0xC2528354D882F904ULL, 0x4359BDBD5430E75CULL, 
            0x482ECDFC0F55F6D2ULL, 0xDA085539FF8ED33CULL, 0x368E01EA89CF731FULL, 0x7BF46E740F9941D9ULL, 
            0x65A3235B7582A681ULL, 0x2915E78A9BCAB848ULL, 0xAD6621382B20DFF3ULL, 0x5631D1BB0DCB72D9ULL, 
            0x1A577E56DC263F57ULL, 0x42FB11BA578FC6B6ULL, 0x179F8FD116369A2AULL, 0xC4D9532B9CEA9A7CULL
        }
    },
    {
        {
            0x9B0E73423FD2F948ULL, 0xE0F5425B7B8F47D0ULL, 0xD652995F53643B04ULL, 0x52EF663CB1917BBFULL, 
            0x8888CF6B17FCD433ULL, 0x2FA2FDC6EE0A33C9ULL, 0x8E0E3AE61BD84936ULL, 0xF6F570405D580C68ULL, 
            0xD85A5F5D210408C4ULL, 0x5176263B347177D4ULL, 0x38E4EC8C3FD5A139ULL, 0x2A629F63EBA9C8C6ULL, 
            0x744088601962A039ULL, 0x8B5299C537CA58EBULL, 0x9ED6F82D8FAA648EULL, 0x2A1F47F558ECC897ULL, 
            0xB8CFD4319B35D366ULL, 0x82222AE34CB5DFBAULL, 0xD84949FB17049629ULL, 0xA5FCF59F1A3C700BULL, 
            0xCDBC1540D61D5A10ULL, 0x980B7F72C698C8EEULL, 0x69603AA68765E64BULL, 0x3B651B5F152BFD8AULL, 
            0x39EE28CDC703FC95ULL, 0x67CF7A7595FD8E91ULL, 0x27724020B248F277ULL, 0x1B34CF3D9EAB588EULL, 
            0xB1A8A3521889D14EULL, 0xC69FA6FD78F7EA58ULL, 0x48024EC06E92CE9DULL, 0x71B053487E077465ULL
        },
        {
            0xB992D08FE3EB513BULL, 0x4AD23BA604581DFEULL, 0x948E2DC0B7F06856ULL, 0x48C4881BAE43A5F3ULL, 
            0x1CEDBB1B7465647CULL, 0x812F34E134DAB953ULL, 0xC4AECE665E24E72AULL, 0x553524BEA6D92337ULL, 
            0xE61355E8F5DAA532ULL, 0x731EB524E485778FULL, 0x380487BB676A616CULL, 0x990EA46D96882593ULL, 
            0xEF4337E30EFB793DULL, 0xCE0B67ABFE949295ULL, 0x2B295313BE81D256ULL, 0x20ED04408F8AADBDULL, 
            0x17ABA7DE320F64BFULL, 0x06ECDE18E7A9E3E0ULL, 0x19623EB494BC2101ULL, 0x0FDE2369745E0319ULL, 
            0x2885ADECD0E23776ULL, 0xBE7884E5C0433A0EULL, 0x1BA2ED3D02F22EB5ULL, 0xF427658CEA5AB6B9ULL, 
            0xCE7013627E3C4FFEULL, 0x24299EE777223BB7ULL, 0x38C719F426025CC1ULL, 0xC6CB9183C7298E52ULL, 
            0x82A181C9D2531C24ULL, 0x40C068C6F2E12E01ULL, 0xCA688D834834988EULL, 0xC60ABB25ACFB5279ULL
        },
        {
            0xFDDC33B212DF8D38ULL, 0xB5D5BDFCD2F26BE1ULL, 0x58DFEA2697D2DB75ULL, 0xB58778EEA21F6654ULL, 
            0x40E603C7350D864DULL, 0x9D1C20A2F6662B34ULL, 0xEAF0B3D800628CF7ULL, 0x6EF737C84D849430ULL, 
            0x5B715321E0EB3CA9ULL, 0xF02F034B22700875ULL, 0x5734A69D6714773FULL, 0xD915F0828533C63DULL, 
            0x895B7433D8B99C01ULL, 0x6EBF21B1B4ABF7FBULL, 0xFEB39BAC6FA9F0A3ULL, 0x083E840571E88DCEULL, 
            0x5473D27CCE52292EULL, 0x5C21CC13E62F79E8ULL, 0x8901D0FA7E6C1F37ULL, 0xCEE1C71B8AC22610ULL, 
            0xA96C3A206A3A2A90ULL, 0xB52F34A34DE63C2DULL, 0xE72C4BA046253EE2ULL, 0x3F74C9D445015F03ULL, 
            0x3FE43543BC37A802ULL, 0xF657B1619D3DF1FFULL, 0x5EF7DB597991D199ULL, 0x374136891F204F0AULL, 
            0x53832ACC5AA9967EULL, 0x56C5BADBC4AFD04DULL, 0x5B617100428D68A9ULL, 0x99AD9FF468CECDA9ULL
        },
        {
            0xF5DA61DA232CFF36ULL, 0x8F47E94D7927C376ULL, 0x40548F17F877C548ULL, 0x439F1BB0CFAAE2AEULL, 
            0xA45E5FFDC71CC5C8ULL, 0x260C415FBDBA7866ULL, 0x332AFA3256D0AD10ULL, 0x97B856B8A8ED8DF1ULL, 
            0x783434FC68E16A16ULL, 0x402C6EC2129D5357ULL, 0x85E89B5189E5485CULL, 0x91433C2A84323AFFULL, 
            0xCB633359633B3ED8ULL, 0x2D1391B92CEBB769ULL, 0x3F9D7D80004F4138ULL, 0xE39FF533F76D8C96ULL, 
            0xA3CE015B0A19B882ULL, 0x0ECABFE15C0229EFULL, 0xEF6766A2039FECA9ULL, 0xFED7FFC7840D1242ULL, 
            0xCD54FCA4DC306F25ULL, 0xFBC2243DC26AA329ULL, 0x80CBBDDA392BD1BDULL, 0x7DC8BFF6D39321F8ULL, 
            0x7B0611065E990E02ULL, 0x2089B9C402D6F509ULL, 0xB96F1848E87C2641ULL, 0x4494CC9BF8BD393DULL, 
            0xF60302AC80975028ULL, 0x48C9AF6F36465000ULL, 0xE9F7BDCEEBCADE95ULL, 0x248D7373E7265BC5ULL
        },
        {
            0x45ABCF8AFBC1F6E5ULL, 0x944E3C59D6C78D18ULL, 0xF330EF5E25B32202ULL, 0x9C1D6F463186CE00ULL, 
            0x515F451AD01A214BULL, 0x31B7F56D41BF0576ULL, 0x9411C15B9E1DFBFFULL, 0x8631A8A88093646FULL, 
            0x12B0C1DDD2B2B375ULL, 0x146E9BE37BA200EFULL, 0xC5259C69BC68D41CULL, 0x908EBBEE3DFE5942ULL, 
            0x0D4C3C852AB0C62DULL, 0xBC36E04B12702E08ULL, 0x708A9B9F30186060ULL, 0x8C81D51E41D04357ULL, 
            0xABEBBBA6DD8788D1ULL, 0x9DA7F766D53C062BULL, 0xCB11E8EC8A700B3EULL, 0xC965A553AAFCEBD6ULL, 
            0x09CC4AABCB98D300ULL, 0xE84EB58BFB8CD060ULL, 0x28E89D1E1733BB9CULL, 0xA7DC9BDC9F31996DULL, 
            0x4539AF0121971665ULL, 0x70BE0EDE1F006D18ULL, 0x53ACC6AF85F20554ULL, 0x6AB08A7A2D302AE1ULL, 
            0x86D99B832470521FULL, 0x58B4A0E0D20E6BDDULL, 0x49ACC0A94FBB0B2CULL, 0x92E50FFF1BC11D58ULL
        },
        {
            0x98A9DF27543E96E4ULL, 0x7320294DBC247392ULL, 0x08C5B6EB5792DCDEULL, 0xB132859BE44ECCDEULL, 
            0xAE24FFCD41FC2097ULL, 0xD528D6C7A96FFED3ULL, 0x51091063CC9B70EBULL, 0x8B092DAD96EA8D77ULL, 
            0x5FDD11709EB1CB73ULL, 0x7DA6DF604C11F7FDULL, 0x46FFEFA19BA94768ULL, 0x0567561EA5F7AE9DULL, 
            0xFE10AE8AEA4458D9ULL, 0x69354092E2102761ULL, 0x995337C9B73CB994ULL, 0x1108B02BE7478C32ULL, 
            0xFAC7619B29E30D3EULL, 0x7223299EEFCD92BBULL, 0x2578DC3377E52C7EULL, 0xD26570881982A15CULL, 
            0x6DAAA04EE1951153ULL, 0xC014D5DB603D6F66ULL, 0x612FBF0AC62AF137ULL, 0xA4A0E3563AFEB1C2ULL, 
            0x1D551946314CF4ACULL, 0x5CE21C439411373EULL, 0x991B5A9EC107ABC0ULL, 0xB3C262DF35C62BA0ULL, 
            0xE668124058DE3337ULL, 0x257947F299A8FB2EULL, 0x08BA507CFC1C512AULL, 0xBF36832A63612083ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseGConstants = {
    0x5E5D87A6A546199AULL,
    0xF17AA83B852376B8ULL,
    0x7BBAE758B4E75928ULL,
    0x5E5D87A6A546199AULL,
    0xF17AA83B852376B8ULL,
    0x7BBAE758B4E75928ULL,
    0x7351F9FA2146D4A7ULL,
    0xE80D7D77D2B4AA0DULL,
    0x8B,
    0xCF,
    0x27,
    0x9E,
    0xAC,
    0xF3,
    0x1C,
    0xCE
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseHSalts = {
    {
        {
            0x118B35B2A6BC75BBULL, 0x19C48F22D625F4C4ULL, 0x22E77B8BA68493F4ULL, 0x3E6DFD9A7AB451AEULL, 
            0xF7AC3F9C50C5DA05ULL, 0xEBE801FBE860FD72ULL, 0x70C0FC012BAF75FAULL, 0x784BEB0AFB6D27E4ULL, 
            0x4D36362B1B261CC1ULL, 0xDA3C2AF0D8801EC6ULL, 0x6D78CB02E3069F8BULL, 0xDAB8CD9A89871B2FULL, 
            0x0619D0CA5FBF5CF0ULL, 0xB1CC3E9FD12BBC76ULL, 0x0D0501DD00EA1BD4ULL, 0x56E82DC3533C8FB7ULL, 
            0x7A263B48AB5CAFC9ULL, 0xD22E6E0F3D218F38ULL, 0x60857F5BDD172F4AULL, 0x38B981BB7A2FF7B2ULL, 
            0xAFEDF3B7DF1594BEULL, 0x2C0340590D81B532ULL, 0x942FE7649E328D14ULL, 0x720B10EE2148AE46ULL, 
            0x05B38ECF62F7FCD1ULL, 0x4CF6EBECC1340FE4ULL, 0x0E92C1948E5EFF0CULL, 0xDCE18C04735CEB35ULL, 
            0xF7E2D34182CB2986ULL, 0xE12128CC266CC997ULL, 0x322970037E892319ULL, 0x4D615A3760181838ULL
        },
        {
            0x05B42FA355D231C6ULL, 0x9BCE25B8F3D57799ULL, 0xF28FFE62C4936B56ULL, 0xF628873EE9D43BB2ULL, 
            0xFD418FE34AAC89AAULL, 0xD8338A9A12ADA862ULL, 0x651FE75D1B20187AULL, 0x9777B4501361FCF2ULL, 
            0x39024988769E2CF2ULL, 0x1AB44536DA38A22CULL, 0x258FADE4D888729DULL, 0x9D698B19F061B8C3ULL, 
            0xE906824C7C5C6CD8ULL, 0x49B00B75E746B54BULL, 0xBE32A30C68BF9228ULL, 0x80E4956C60059BF9ULL, 
            0x2B27CAD294B64D3CULL, 0xC3F58741D5AAADF8ULL, 0x6E47F7E16BE33CDAULL, 0xD40E8905B4D07686ULL, 
            0x1609694072B5348FULL, 0x58B56831095F8F78ULL, 0x71A18ADF9B335942ULL, 0xEBBEF013D72D0805ULL, 
            0x31CC06DFBA13223EULL, 0x409CC347189EA372ULL, 0xC2AAB421077DEA9CULL, 0x71867E73658FAB26ULL, 
            0x097744C5786D9F05ULL, 0x0E296E392D7A1DCCULL, 0x68F554C3A7833299ULL, 0x8015D9526E083512ULL
        },
        {
            0x275963B126DFB589ULL, 0xC9ED3F5CCD834CC7ULL, 0x9C87586D34F0EDF4ULL, 0x3E2F8CB6CEEF082CULL, 
            0xA181A2CCC779F5CEULL, 0xCC37708702959711ULL, 0x595002B8FAF545D0ULL, 0x332D1A094AEFE57DULL, 
            0x69B64BC28A9B6D33ULL, 0x818FFA57E8A23517ULL, 0xC98BEAEF2BCF37F0ULL, 0xB62FFCA087024135ULL, 
            0xFEF506765F580D0FULL, 0xA37BE9265CB6D0B9ULL, 0xEDD8A7403F1F1BA1ULL, 0xEEA9FF25D5629386ULL, 
            0x10A3635A0ECCADE1ULL, 0xF4FD2E9078385FBBULL, 0x3EA150299254AB9BULL, 0x8C04B5DF89CAE690ULL, 
            0xB7B0798C655C329EULL, 0x4D0DF957FDCA13A6ULL, 0x5E816482853F956EULL, 0xF49C157D5800BF0DULL, 
            0x04DB6666A178895BULL, 0x973E7ADF195CED0CULL, 0x4622EF67714AE0C3ULL, 0xAFB68EAF518D031CULL, 
            0x997F68CBB754ABD1ULL, 0xBBC56FEB29B78D1BULL, 0x02750FF9E5ED66A9ULL, 0x75BB606723DDD919ULL
        },
        {
            0x373E70781B85AA2BULL, 0x09AA4AAD08F3816CULL, 0xA1E82A8D364E5439ULL, 0xA78AE00165E4B46AULL, 
            0xC2E34948013A3F9BULL, 0xAC923D788DCD143CULL, 0x5AD46D1CD58E6F3AULL, 0x464D7128B0552B80ULL, 
            0xB573250505B6864AULL, 0x6CACC90E819DB7A7ULL, 0x4F914A4FB996BD8CULL, 0xDAB0433CCAF37CA3ULL, 
            0x361357E5E9930DDCULL, 0x037A717570338B18ULL, 0xEE7210F30586781AULL, 0xF025A4A2964453B9ULL, 
            0x3F3FB4C4216A2B5AULL, 0xF755F9860171ADA6ULL, 0xCA795845CD70F6B1ULL, 0xBC9C98220868CE12ULL, 
            0x1B570679E4724642ULL, 0xCEBA489DB6340441ULL, 0x4A8D46BA7E157CD3ULL, 0x630F0EEAF174F53EULL, 
            0x74C9E80B97FF4875ULL, 0x9F1C8F7BEFC29644ULL, 0x17B290D02C70B6E4ULL, 0x5E0D0E5940E3A791ULL, 
            0x3ED708B8DEC1B599ULL, 0x3EC1A0368EEC47F3ULL, 0x808AE5FC19AF2875ULL, 0x384E158DA1C3AF47ULL
        },
        {
            0x5988116CC5C3C619ULL, 0xC3768241B4435C03ULL, 0x5420482F47DE8504ULL, 0xA51D6079BA985273ULL, 
            0x003C2D93B8427637ULL, 0x2A78BC283BA6D77BULL, 0x99FA533CD415799BULL, 0x4C49ACC98E2D95F6ULL, 
            0x3B5830DDEFEB9122ULL, 0x6FA27F2A5E0E918CULL, 0xDA0B94B58C9876BBULL, 0xAC444042706BEDCEULL, 
            0x6B9EF272533724B2ULL, 0x5EBA66536AC8ABF3ULL, 0x2C37948076975865ULL, 0x6C6842B3ECC6D3A8ULL, 
            0xD1056CF99F099904ULL, 0x9C5F6CD4347AB179ULL, 0x9E92E8484EECB01BULL, 0x70633B667CBFB9E4ULL, 
            0xE9B5940BAAF591B0ULL, 0x7D36A168498AD8BFULL, 0x0E0273772CA07032ULL, 0x9DA1D5F76AEBF85CULL, 
            0x4A23B88BBC51D8C1ULL, 0xC6A96B69DF6D09DEULL, 0xE89547F5F1C14F0AULL, 0xA7E9824AF5FD2675ULL, 
            0x3CF7399A8F9C464DULL, 0xDAF9313399B976A1ULL, 0xC3E710B6D69C87A1ULL, 0x70B55A728FAA57DCULL
        },
        {
            0x299B6C02FD51040CULL, 0xD72E8D5542F0ACB0ULL, 0x9E5DEA92CFCFD394ULL, 0xA6A5A99806715F05ULL, 
            0xE1AC0032648E7BA0ULL, 0xF70A6ED7DD6EAAEFULL, 0xB347AA2136AA0A68ULL, 0x6E15A253BC349B5DULL, 
            0xBD8CEA0508EB3A4EULL, 0x6F5F9B0F6A5CA51DULL, 0x7D1CA8AB0A228FFCULL, 0x8AA3A21C049CD326ULL, 
            0xECDBAF283F893754ULL, 0xF11C5656672EADB7ULL, 0x29BC9EC2155EA8F3ULL, 0xEF1AC5846EFC0AF4ULL, 
            0x73AAA5D61598556CULL, 0x6D77BDC7CECCC304ULL, 0x1FE9961A41476F15ULL, 0xE171AB831ED9ADD8ULL, 
            0xB6315E9DA17723B7ULL, 0x0CD9CB3581B5BF44ULL, 0x5429EF96259606B0ULL, 0x9C1962B7836022AFULL, 
            0x05A6C9B61C42DAE7ULL, 0xB1D3D0A0F017566EULL, 0x774CE09BF1E7C1AFULL, 0xB0B5E7B9D23A560CULL, 
            0x500BCB227EC033D7ULL, 0x15F0AF435CFA48EAULL, 0xE18C916F5236F34AULL, 0xBB5B25985946BD4AULL
        }
    },
    {
        {
            0xB362722647FBD5BCULL, 0x5E246A6D0660F3E1ULL, 0x67FD1581B7C6B52EULL, 0x131BACF93444792CULL, 
            0xCAFB350E7491754DULL, 0xE6F14CB75F172C31ULL, 0x2A7303AAB3550378ULL, 0x53962EA8AB8DE875ULL, 
            0xACFE4E17F1F3A198ULL, 0x4397775EB577F5BFULL, 0x0CD878AF484917B9ULL, 0x4D7C0CDD99D3C973ULL, 
            0x1AFD3B0FB93B5189ULL, 0x1C01C2B7228ABB6FULL, 0x87EA56799051D6CEULL, 0x207F9138F1E624FAULL, 
            0x29C633FBB8AE5C09ULL, 0x427B39408920E7D6ULL, 0x7CDC411E45DF8169ULL, 0x038F4BA6A8F9F74EULL, 
            0x3B88776F0E69E5E8ULL, 0xD0FB39D4F6245AF6ULL, 0xB7611DF2FEF950C6ULL, 0x3884639BBCBBC5C9ULL, 
            0xA98CA783E637A57DULL, 0x4FAEF7417DEDBACCULL, 0x85BC5D5F1F82515BULL, 0x494C2A98FFAF665EULL, 
            0x4F4DDFD62C604FDCULL, 0x0C01EC185E696831ULL, 0x5C0DA40F97C28BC3ULL, 0xD73F4B81BAB9F8D7ULL
        },
        {
            0xC82B9D9C018513C7ULL, 0xD91D9891C6BF6EA1ULL, 0x9D5B06A5C7C9FD0DULL, 0x92F93208E7DBF47CULL, 
            0xAD5D37CA525727BAULL, 0x488DBB10948A683EULL, 0x59DE775D4DFB7C51ULL, 0xFF6CD96D0854A4E7ULL, 
            0x7907C7878D68FDC7ULL, 0x56EBC82553663CA1ULL, 0x543163C597743FE1ULL, 0x9A0262E233A4E716ULL, 
            0x1C99F8B97844A51EULL, 0xFC3F1018C9EB5B7BULL, 0x44D2E5A83B226A28ULL, 0x8DA331CE99984E1AULL, 
            0xE6FA5D9C511D8CC4ULL, 0x3BCE783445975206ULL, 0x58DA37E9DE26B674ULL, 0x1E47FE3E6A56C1B0ULL, 
            0xDD4C4E6F7D30724BULL, 0x21C284D2E9BB4D18ULL, 0x0ACB892165721589ULL, 0xE4015B54DB8FB40AULL, 
            0x7A93288F58AE3763ULL, 0x2D6AD2A0E6DA9B7BULL, 0x2AB997B4A22231C4ULL, 0x0E77338D152D54D6ULL, 
            0x15AF3ABFD144596AULL, 0x048D8445B6323F6CULL, 0x7671659A9E22782AULL, 0x83EDFF83C656C9D5ULL
        },
        {
            0x2FA3B6283488D9ADULL, 0x839F937DC2CBECDFULL, 0x851829CD989EC36FULL, 0x9E3939596DCD8D01ULL, 
            0x7C117368570C1713ULL, 0xB99DE082AA3612FAULL, 0x67564A3FB10097E2ULL, 0x3C9EE80A4E847A8BULL, 
            0xA6DA5E8C4C6242AFULL, 0xF289752E2D0B1CA7ULL, 0x12B606E9E8E78423ULL, 0x30D428B2DA94E3B9ULL, 
            0x8CE04BC68523E1A0ULL, 0x031A9B0D44BC3CE8ULL, 0x8971E3C4A8991FAFULL, 0x231B3C8D0628B168ULL, 
            0x0220A5E34A22795AULL, 0x4123A0357F5BC30FULL, 0x8E7537BE804AA40AULL, 0xB9937793299206FDULL, 
            0xD4AF01314D3F1D6DULL, 0xEC3C324EF46DE2B5ULL, 0xA7AD8EC7C0AA5083ULL, 0x690E2311D5014973ULL, 
            0x68385806555D7D5FULL, 0x0358ED315A883E6DULL, 0xBD630B0C4FC8D895ULL, 0xBB348332A356AE62ULL, 
            0xC60D58FF39A7CA82ULL, 0x59623F902BFDE682ULL, 0x3C9128D3361D587FULL, 0xD220CC0EB6679531ULL
        },
        {
            0x3E09D18F867E2825ULL, 0x9534F4482B792FB0ULL, 0x56CD7C788F5E68E2ULL, 0x45F35B9E8FD72A29ULL, 
            0xC5A14C973A92B30CULL, 0x635538C6FD8B5921ULL, 0xA5E8FCDB33AD9AB6ULL, 0xE9BC4EB732C64CFBULL, 
            0x79DF5D6739F7E71EULL, 0x229C37A41413C848ULL, 0xBCCC4E8E816D0852ULL, 0x9BFBEC6A11C0A97BULL, 
            0xF700BA1860FD3AC9ULL, 0x9035296F1753A101ULL, 0x4127B05DED637718ULL, 0xA5A45821DC75C6C8ULL, 
            0x9430685ED4D8C6A4ULL, 0x99E4C3B3CCA793DAULL, 0xC31EBE0538885ACAULL, 0x37F092C1EF624542ULL, 
            0x94FC0D902A5E49DFULL, 0x1D07EF2024D9B0D1ULL, 0xC5FD4A3BDA1CA271ULL, 0xBBC780FCC071A88EULL, 
            0x210510C81B761566ULL, 0x138C9555EAB92CAEULL, 0x7836BEBC2E5C9FBEULL, 0x6AD00448F176C6AAULL, 
            0x7F667D3F7BEF41F8ULL, 0x041AED5AC2DD99B7ULL, 0x8F3372DBA8B5817AULL, 0xCC3E4F20EA66FB16ULL
        },
        {
            0xF73BA379A331EE4AULL, 0x1FDEC410764BB44DULL, 0x8A114AA6C0C5BA6FULL, 0x3FF4CB4F032F71B3ULL, 
            0xCF7BD5D4EA186464ULL, 0x1F8898D0C6112B43ULL, 0xE7C84382CA920784ULL, 0x0A0C9BC8B8BE1AF8ULL, 
            0xC729D68838461B0CULL, 0x6A3A1C1A0E558A2AULL, 0x7776ECEA48080DD9ULL, 0x9B89A1BF7D19498BULL, 
            0x77843F6EB063B6E5ULL, 0xC3F9BD3936EB3631ULL, 0xF71A2C0562197557ULL, 0xA55C0DA50F3D6942ULL, 
            0x2E8DE3F34DB284FFULL, 0xAE77406F428C79D0ULL, 0xFC56480F279F85A4ULL, 0x2460075FF75F6A69ULL, 
            0x48C917FF059B4BBBULL, 0xAF8DC730B172C6C8ULL, 0x0D7FE84E8908B72BULL, 0xF7126D4F21A66234ULL, 
            0xF3CF71AF03DFB903ULL, 0x0008CD30DA9A2C5DULL, 0xD1998C9FB28BC068ULL, 0xB30594F114B5EDE4ULL, 
            0x5E683D99CA0CFF5AULL, 0x9FAF738A7AD6E222ULL, 0x5B5FEA8C684CB28DULL, 0x4B12A30BBA59B2C5ULL
        },
        {
            0x4F99843A2D5F999BULL, 0xAE53005C7384CA40ULL, 0xA2A58CD2BB4BF993ULL, 0x9F1126FAA1D32E42ULL, 
            0x6B94D16E05C8F96DULL, 0xFBAE790CC41BD6DDULL, 0x326B1310BCB88930ULL, 0xF5CD69D5738065F7ULL, 
            0xF4772FD7D425683BULL, 0x0DA4E7BFF10DD5EBULL, 0x185575949C186211ULL, 0x260148D02483E02AULL, 
            0x09423EE3B101B5F1ULL, 0xFEC45CD4ECFF8572ULL, 0x110FFBCF6BD20345ULL, 0x7CE9331102DABDA9ULL, 
            0x56F8EC9BEE49ACEEULL, 0xA4D4856D4E2EAF9BULL, 0x39272D15771BAC62ULL, 0xFB9DB5E1BD2A4F6FULL, 
            0x922BA2758FE829A0ULL, 0xD9A6FA5F325C8B9FULL, 0x69B7690BDA245AEEULL, 0x198D211C650F44DFULL, 
            0xFC6091B829DF366AULL, 0x98B63EAA3243D9D3ULL, 0x59314A7E25F892CEULL, 0xD41950F558C48D78ULL, 
            0x3981F86629348B15ULL, 0x4BAC6DD914732CE6ULL, 0x87233026F3A33A66ULL, 0x562812794CF471C9ULL
        }
    },
    {
        {
            0x9051B9EA6F01E071ULL, 0x31F06D157B671737ULL, 0xE923F75E4A9789C9ULL, 0xFA7ACDEBC49E8221ULL, 
            0x01BAA8C312EDA0B3ULL, 0x80496A94C4D94B3FULL, 0x958B9C6433D98E07ULL, 0x0C94D1216FE01E75ULL, 
            0x41F360DAC1C4E5B7ULL, 0xAD77E6881ED1E533ULL, 0x8FA982B01A9B3ECCULL, 0x91D75366D7380968ULL, 
            0x92E44DE55F8056F4ULL, 0xBA2CF430A663130BULL, 0xAB61CFBA26828ABEULL, 0x4780CFDBF3A3A734ULL, 
            0xB420A4BE7E2D4421ULL, 0x432D3C0E0F668F09ULL, 0x6BF128DBC6076656ULL, 0xF529E7B0C74789F8ULL, 
            0x42C9D498271626A7ULL, 0x84D941D3D83ABF95ULL, 0xBAA90605109CB7BBULL, 0x605AFAD7ECDD07EFULL, 
            0x9C06086287EE17CEULL, 0x987772D62971598BULL, 0x178B6CF793CE3BE2ULL, 0xCEB0543D080A89BFULL, 
            0x844D038217904356ULL, 0xD5F843782DD89702ULL, 0xC4F3FC7162C0F94BULL, 0xAC2A29F78FBFE86EULL
        },
        {
            0x3187A3A9F9EE2B08ULL, 0x6B38964125466E5AULL, 0xB0E342B14A58AD02ULL, 0xCA174D2BECE6CD63ULL, 
            0x39B07AC000298B21ULL, 0x65DF9D7FDCAC22F1ULL, 0x40329EA2CF0DE0B6ULL, 0x77CCD96F71B6A8AFULL, 
            0x230547349246B277ULL, 0xE2DE2875C0BC7CB6ULL, 0xB448998737DE8764ULL, 0x9730AA47E83548FFULL, 
            0x4CA073D7D0F9AEEBULL, 0x1590957364520744ULL, 0x90CB43E7F837D23FULL, 0xF0BF56DA80127847ULL, 
            0xC4CB5D29DE9F7D95ULL, 0x74DC8C081DD75E36ULL, 0xE9D27081A3CE7143ULL, 0xC50A73097EAA9AE6ULL, 
            0x595895D82C0D1F60ULL, 0x0D23DEAD233CFAA4ULL, 0x966ADF0CD60FF130ULL, 0xB51D33830DF465FAULL, 
            0x7F3EF481423A4BB5ULL, 0xC07CEED8F0E9470EULL, 0x67610C7F77244B2EULL, 0x03E6A353949315ECULL, 
            0x1953E3585D9DF3E7ULL, 0x697772CBA5106B00ULL, 0x009909C9E499486FULL, 0x168C75F79CBA258DULL
        },
        {
            0x9476049103BDF60AULL, 0x8BA66E91E7750CF4ULL, 0x3503617C3118EE43ULL, 0xC864FEEC5B6A0409ULL, 
            0x51C0D9CD2E1E9A21ULL, 0x5470F4EBCF631BE6ULL, 0xFEE21A7A701BC1FEULL, 0x9A8108CA96B37CFAULL, 
            0x36B448325D010C73ULL, 0xDA64A691D502C174ULL, 0x805D741C3AB3E34CULL, 0x027922C381702F34ULL, 
            0x3CA0A9FCC8772EBEULL, 0x4D6B504F3F2A23E3ULL, 0xDF5B4BB081DC9CBEULL, 0x848F3B12FA02B14DULL, 
            0xD75220DC34DAE707ULL, 0x089E6F222DE340E3ULL, 0x4E32693BD5316B3DULL, 0xCE524BE0D25DF913ULL, 
            0xD3B0FC3B1BAA92A8ULL, 0xCBFE3DF351428E63ULL, 0x3D9CDAA0F153E303ULL, 0xCE4C0BC027B30D60ULL, 
            0xDCF08A56D08058B4ULL, 0x68C0FB57FEE341BEULL, 0x36776DC9DF3F1DE1ULL, 0x100E60C51FDDA762ULL, 
            0xA556DF56EBBCCCFBULL, 0x848DD7D8B6F5F114ULL, 0x1BDFC026D86EB1C0ULL, 0x5E3868B99DC58E4BULL
        },
        {
            0xB4841B38BDBC6564ULL, 0xCF29CFA8EFCAA005ULL, 0xC226EBEDAE87C952ULL, 0x7A68362033FAC716ULL, 
            0xB4FAC9F4AD58EB68ULL, 0x9247235764727392ULL, 0xBA526B673A95B40EULL, 0x47D54ADB42CFE6F0ULL, 
            0x859F94689E6B8F2CULL, 0x482D1D6D5BAB97D8ULL, 0x617EC1D4F0FAF3ABULL, 0x2B78D67D4138D0D8ULL, 
            0x849D7940BF2901D6ULL, 0x692694AD1BE701ADULL, 0xC83EF239394EDEFBULL, 0xDB445C3D8C15465FULL, 
            0x8553E027341C590DULL, 0xBB9837E36F024857ULL, 0x23BB4B34183EFAADULL, 0xE1E1A99F78082949ULL, 
            0x19EF103AB34BDBEAULL, 0xFC6DA15DEF7C4214ULL, 0x8B58BE160F65B9ACULL, 0xCFC0A30B12F38CA0ULL, 
            0x063AA602405CD04FULL, 0x050193CC945BF87CULL, 0xB008C69590803447ULL, 0x54B4E9D6DBDD2DCEULL, 
            0x3EBF237395BA94E2ULL, 0x63CDB14334C2A547ULL, 0x1568D2A502B0E143ULL, 0x14EAC14D9703587DULL
        },
        {
            0xC8A3FF73829CFE17ULL, 0xFD4259C5D356E67BULL, 0x54791919B3200B07ULL, 0x4C1776157D23987AULL, 
            0x5D2EB4BDFDEB65AFULL, 0xFD4A772E7A231CE9ULL, 0x6BC58BBB8C950C07ULL, 0xB0FFAFBC19562481ULL, 
            0x8518430BB5CCE58FULL, 0xE7FC03694CFDFB0DULL, 0x3538A2DEF94C3A95ULL, 0xE0D43ADF39FBA8E7ULL, 
            0xC04C5405C4FC57EFULL, 0x299A1ED1DEE28F97ULL, 0x58FA108CEE9A0ED3ULL, 0x9869529136959A64ULL, 
            0xD5D9FD769FD52D51ULL, 0x679D16ABFA81D699ULL, 0x9DF50F2D07D9E0CDULL, 0xAAEA322875C6EE41ULL, 
            0x9AA07AB8C11756B6ULL, 0xC312671A16702E9CULL, 0xEF1A38E4939CC8FAULL, 0xA2B674802D798443ULL, 
            0x9415D378DD03EFCFULL, 0x1E8ACD709ADB95E5ULL, 0x992DA1BD39F5CA54ULL, 0xF5EBD3649FCFC726ULL, 
            0xEEA99ED991706C1FULL, 0x0C48220C7FFC03CDULL, 0x9754A77C45DBAA4BULL, 0x1A6639D3F2DA55E8ULL
        },
        {
            0x8E76E2C084B7721EULL, 0xEAA1F6AACA9977B1ULL, 0x336E2CF0C0269646ULL, 0x198E096D582D385AULL, 
            0xA8573A5A9D2A4940ULL, 0x87871032EC658AE9ULL, 0xDD196F8E4E21020BULL, 0x85FCC0D8775FA1E2ULL, 
            0x5C1A228AFA9E4C29ULL, 0x7778676971B59EF6ULL, 0x1B7F5D1F43CFC3F7ULL, 0xF66422E5BA854FD8ULL, 
            0x0F6449589C96C074ULL, 0xE0ED390230D7901FULL, 0x246E275E3CC27F57ULL, 0xE0834EE42551E653ULL, 
            0xE2F11CA8E72CE8E1ULL, 0xDB4435C7AA16189EULL, 0x6BC617B758A78387ULL, 0xD0AA420F1AD40DACULL, 
            0xFD39CD445014BB6DULL, 0xC8349A1A03DC0359ULL, 0xF06825A2320DD6F8ULL, 0x7B978E6C9BF6C1A1ULL, 
            0x50BDF92F308E0BA0ULL, 0xB4FB40C7606FDC77ULL, 0x3F37B96FD9B0B620ULL, 0x9C3CF95CE26DC79DULL, 
            0xF4ED5FB470EFF718ULL, 0xA1D72B75E5393B04ULL, 0x5A123DCDFAFAC64DULL, 0xCFD0158956A722E5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseHConstants = {
    0xD51AAF241380A543ULL,
    0xA1AFD7934C25421FULL,
    0x18F2861168DD38B7ULL,
    0xD51AAF241380A543ULL,
    0xA1AFD7934C25421FULL,
    0x18F2861168DD38B7ULL,
    0x11177805EDAD36E2ULL,
    0xB800CFAB3F8E5D28ULL,
    0xB5,
    0x5E,
    0xD4,
    0xB2,
    0x8C,
    0x97,
    0x4E,
    0xE8
};

