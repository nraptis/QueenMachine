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
        aPrevious = 17490337186624593804U;
        aCarry = 16727045804256633119U;
        aWandererA = 16391097343348463197U;
        aWandererB = 15410127955142686602U;
        aWandererC = 12163103975623936486U;
        aWandererD = 11728153259704366005U;
        aWandererE = 16562531279664148929U;
        aWandererF = 11993694860624889633U;
        aWandererG = 17341461760414367284U;
        aWandererH = 14458004346479291935U;
        aWandererI = 13836608499021687536U;
        aWandererJ = 9710405471266410504U;
        aWandererK = 17198790937840693202U;
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
        aPrevious = 13552995006979571850U;
        aCarry = 16102137807473654010U;
        aWandererA = 14804448049074044320U;
        aWandererB = 12964427938773391017U;
        aWandererC = 10972189475835473231U;
        aWandererD = 16131943073200433979U;
        aWandererE = 13917347670945147554U;
        aWandererF = 17973097317697244226U;
        aWandererG = 16352915031984155698U;
        aWandererH = 18257419961353037301U;
        aWandererI = 12131540292266831301U;
        aWandererJ = 11820447032152768501U;
        aWandererK = 15305019837657961644U;
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    }
    // KDF_B PhaseA invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseB invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseC invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseE invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    }
    // KDF_B PhaseF invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseG invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    }
    // KDF_B PhaseH invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    // GSquashInvestToKeyBoxes (start)
    SquashInvestToKeyBoxes();
    // GSquashInvestToKeyBoxes (end)
    //
    //
    // ---------------------------------------------------
    // GSeedRunSeed_A seed_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: work_a, work_b
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
    // temp storage: work_a, work_b
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
    //
    // ---------------------------------------------------
    // GSeedRunSeed_D seed_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: operation_a, operation_b
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
    {
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
    GrowKeyA(pWorkSpace);
    GrowKeyB(pWorkSpace);
    Zero_PostSeed();
}

void TwistExpander_Unholy_060::SquashInvestToKeyBoxes() {
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneE = pWorkSpace->mInvestLaneE;
    [[maybe_unused]] std::uint8_t *aInvestLaneF = pWorkSpace->mInvestLaneF;
    [[maybe_unused]] std::uint8_t *aInvestLaneG = pWorkSpace->mInvestLaneG;
    [[maybe_unused]] std::uint8_t *aInvestLaneH = pWorkSpace->mInvestLaneH;

    // key_box_a row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 25U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 26U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 19U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 18U), *aFragmentH = aInvestLaneH + (W_KEY * 22U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 24U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 19U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 18U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 25U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 30U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 31U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 23U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 25U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 21U), *aFragmentF = aInvestLaneF + (W_KEY * 20U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 29U), *aFragmentH = aInvestLaneH + (W_KEY * 16U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 25U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 20U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 30U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 30U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 31U), *aFragmentB = aInvestLaneB + (W_KEY * 24U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 28U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 20U), *aFragmentH = aInvestLaneH + (W_KEY * 28U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 27U), *aFragmentB = aInvestLaneB + (W_KEY * 30U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 30U), *aFragmentD = aInvestLaneD + (W_KEY * 18U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 23U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 31U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 28U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 24U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 28U), *aFragmentF = aInvestLaneF + (W_KEY * 25U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 19U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 16U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 31U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 27U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 29U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 18U), *aFragmentD = aInvestLaneD + (W_KEY * 21U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 30U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 31U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 20U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 27U), *aFragmentD = aInvestLaneD + (W_KEY * 22U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 24U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 21U), *aFragmentB = aInvestLaneB + (W_KEY * 23U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 25U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 22U), *aFragmentB = aInvestLaneB + (W_KEY * 18U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 21U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 18U), *aFragmentF = aInvestLaneF + (W_KEY * 26U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 20U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 29U), *aFragmentD = aInvestLaneD + (W_KEY * 27U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 27U), *aFragmentF = aInvestLaneF + (W_KEY * 16U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 21U), *aFragmentH = aInvestLaneH + (W_KEY * 21U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 28U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 18U), *aFragmentB = aInvestLaneB + (W_KEY * 17U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 16U), *aFragmentF = aInvestLaneF + (W_KEY * 31U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 22U), *aFragmentH = aInvestLaneH + (W_KEY * 17U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
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
    //
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Unholy_060_Arx aTwist_DArx;
    aTwist_DArx.Twist_D(pWorkSpace,
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
    {
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        GrowKeyA(pWorkSpace);
    } else {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    }
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0;
    std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [grow key a]
    // GTwistRunGrowKeyA PhaseD salts
    // GTwistRunGrowKeyA grow_key_a_expand_a (start)
    {
        // grow_key_a_expand_a loop 1
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneD, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 21U) ^ RotL64(aWorkLaneB[aIndex], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 39U) ^ RotL64(aWorkLaneA[S_BLOCK1 - aIndex], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 3U)) + 3339283916456813609U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 36U)) + RotL64(aCarry, 53U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 51U)) + 16819191669329316585U) + aPhaseDOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 8361916937762630725U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 18031328374429899857U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18261756894092897276U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4250319792907645666U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7053489184750217963U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1492411503643460886U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17369549067879344180U;
            aOrbiterJ = RotL64((aOrbiterJ * 2947354306696216579U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7301713524358676722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2985193736033012535U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14086975808140927408U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10390516547834639800U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18205555540941493267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 54U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 36U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_a (end)
    // GTwistRunGrowKeyA grow_key_a_expand_b (start)
    {
        // grow_key_a_expand_b loop 1
        // read from: aWorkLaneC, aExpandLaneA, aWorkLaneB, aWorkLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 42U) ^ RotL64(aExpandLaneA[aIndex], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[S_BLOCK1 - aIndex], 14U) ^ RotL64(aWorkLaneD[aIndex], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + 10336802574069791273U) + aPhaseDOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 169025388197058936U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 6541354188379168846U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 6U)) + 16223920526599306104U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 12756613707692514808U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5082475548176484035U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4907435526952698526U;
            aOrbiterE = RotL64((aOrbiterE * 1379692095754989215U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14236627073831834337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11502511046130497584U;
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3679044835550219497U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11254838916686736746U;
            aOrbiterJ = RotL64((aOrbiterJ * 8631695922983532915U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10582608424233200966U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10449735026385340313U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4628253464169957835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17664454668473204465U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 48U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 48U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_b (end)
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    TwistMemory::Zero(aKeyRowWriteA, 1024U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[aIndex], 11U) ^ RotL64(aExpandLaneA[aIndex], 48U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 19U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 39U)) + 5697928251815176134U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 337587740689259575U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 4927686903263973950U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 3742409032569801033U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 60U)) + 1608092659172197650U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15848744267145717509U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15300174177963339253U;
            aOrbiterK = RotL64((aOrbiterK * 5771922862677667319U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14162868453323648628U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12020167069983729869U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16259538291658723956U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3722184575520553132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15265344442454471986U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 36U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 12U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aKeyRowWriteA[(aIndex) & W_KEY1] ^= aIngress;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererD = 0; std::uint64_t aWandererE = 0;
    std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0; std::uint64_t aWandererI = 0;
    std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [grow key b]
    // GTwistRunGrowKeyB PhaseD salts
    // GTwistRunGrowKeyB grow_key_b_expand_a (start)
    {
        // grow_key_b_expand_a loop 1
        // read from: aWorkLaneD, aWorkLaneB, aWorkLaneC, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[aIndex], 36U) ^ RotL64(aWorkLaneB[S_BLOCK1 - aIndex], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 11U) ^ RotL64(aWorkLaneA[S_BLOCK1 - aIndex], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 10336802574069791273U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 19U)) + 169025388197058936U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 6541354188379168846U) + aPhaseDOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 46U)) + RotL64(aCarry, 51U)) + 16223920526599306104U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 27U)) + 12756613707692514808U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4907435526952698526U;
            aOrbiterB = RotL64((aOrbiterB * 1379692095754989215U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14236627073831834337U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterI = RotL64((aOrbiterI * 3460330807286625917U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3679044835550219497U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11254838916686736746U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10582608424233200966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterE = RotL64((aOrbiterE * 7363770199734997411U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterI, 14U));
            aWandererE = aWandererE + ((((RotL64(aCross, 18U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyB grow_key_b_expand_a (end)
    // GTwistRunGrowKeyB grow_key_b_expand_b (start)
    {
        // grow_key_b_expand_b loop 1
        // read from: aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[aIndex], 57U) ^ RotL64(aWorkLaneC[aIndex], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 13U) ^ RotL64(aExpandLaneA[aIndex], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 4U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 17264605017518259932U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 53U)) + 15209184354580778643U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 3299527965014731384U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 36U)) + RotL64(aCarry, 23U)) + 16293096431816127821U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 5U)) + 11031983436878828337U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9188018632448236358U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13420816400363406556U;
            aOrbiterK = RotL64((aOrbiterK * 10958221259662190519U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2485063384097917101U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3089135816938128264U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8813152992957361153U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10730544971770435788U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10431767565618874806U;
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14883796491656899074U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13322163435314643713U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 46U) + RotL64(aOrbiterK, 50U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyB grow_key_b_expand_b (end)
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    TwistMemory::Zero(aKeyRowWriteB, 1024U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[aIndex], 5U) ^ RotL64(aExpandLaneA[aIndex], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 53U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 60U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 43U)) + 10336802574069791273U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 169025388197058936U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 6541354188379168846U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 43U)) + 16223920526599306104U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 11U)) + 12756613707692514808U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4907435526952698526U;
            aOrbiterJ = RotL64((aOrbiterJ * 1379692095754989215U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14236627073831834337U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3679044835550219497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11254838916686736746U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10582608424233200966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4628253464169957835U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17664454668473204465U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 28U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aKeyRowWriteB[(aIndex) & W_KEY1] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyB twist_key_box_loop_b (end)
}

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseASalts = {
    {
        {
            0x8718803475596F04ULL, 0xEF57F74F87EFC184ULL, 0xADEED999ACF42D8BULL, 0xFC2A129682A276D3ULL, 
            0x956053649BB92ED5ULL, 0x1F707BC45D88D913ULL, 0xDDA08DB841A7244EULL, 0x6D747D108C88B4ECULL, 
            0x3DF35C54A3BD2F75ULL, 0xB3D1BC3342923815ULL, 0xE06867D31D212D9EULL, 0x07675992FCEE7F77ULL, 
            0x227A128F39916536ULL, 0x341C3F4EEA17B86CULL, 0x9BCB835DA9748250ULL, 0x840FDB02CC4FBD81ULL, 
            0x6BD30B9439866B15ULL, 0x9074EA54F94C17F9ULL, 0xF1649743C181CC8AULL, 0x1EA6E2C5CD79DE4EULL, 
            0x6B99676FFE6EDA23ULL, 0x5C4D12264DEB65EDULL, 0x008FE33A88174944ULL, 0x1E838B44FE510AD0ULL, 
            0xF4CE232D47E05204ULL, 0xF80880B300DDAF3BULL, 0xCB2B59743883CCB8ULL, 0x2B74936929C86433ULL, 
            0xF1D182E70C1D2115ULL, 0xFF60A22A7D337FE9ULL, 0x1EF81A08D5C59A58ULL, 0x82AFE09E7A8FEE03ULL
        },
        {
            0x3586268AFB32FD18ULL, 0xEF6581A5C6D77C7CULL, 0x0FCA7EB2FF6F683FULL, 0xA2B8B2E5E9E79FBAULL, 
            0x1F72729FD75A3319ULL, 0xA2AEA0C582FA779CULL, 0x7EA0B2F5BC15347FULL, 0x2C9F3D5B20BAD94CULL, 
            0xC18CFD52CD7B8A32ULL, 0x5AFFB6CB9E297C45ULL, 0x7C711F9FA45974CDULL, 0xF24F45E63A42FED3ULL, 
            0x08E0E7DADF5DD6FAULL, 0x0C0FE6B413E74696ULL, 0x5115827A50BA0BDAULL, 0x928F5FBB8398CDA8ULL, 
            0x11195A3DF4F81399ULL, 0x73F002B3A2078D8CULL, 0x10EBC50DC52F8F19ULL, 0xFDD0379D9F895137ULL, 
            0x497F57CA26E7CBAFULL, 0x948CBCBA30C4FF23ULL, 0x60DC204633B5B08CULL, 0xAFC5821D5FA3CF1FULL, 
            0xB7A691536862AE3AULL, 0xFA0651FCB8327CD2ULL, 0xEDF542A7A8B7776DULL, 0x4C9E4FDA063C1928ULL, 
            0x91CCDD7C70389FB8ULL, 0x1084E98700CAA9E3ULL, 0xA398A4CDE19C89D2ULL, 0xE5DD247EC3511437ULL
        },
        {
            0x3F98BF3C3F25FF8CULL, 0xFB885954D1A298A5ULL, 0x117EA24D4108EC0DULL, 0x58BEE8642BF17E73ULL, 
            0xFD4B9D21FC74081BULL, 0xD80857A30F54CAE3ULL, 0x588D622CD536D452ULL, 0x3B3CA34C0155DF7BULL, 
            0xFBFB509219CBD202ULL, 0xDEF79CFBABE5C1D8ULL, 0x438EA6A23A5B2457ULL, 0xF9B00B84DC7F388BULL, 
            0xF076E6D898BA29A9ULL, 0xAFB5C54B1BCCD63EULL, 0x66D167D3B56AE833ULL, 0x7D6146D33FB88CFFULL, 
            0xE006176B0146D942ULL, 0x658F84BE07A7AC3EULL, 0x5F886FFE927D186BULL, 0x3D106B88CD208B5CULL, 
            0x6213E9DBCA9E9477ULL, 0xD4BF334A9566A32EULL, 0x93C7985F06AC024DULL, 0x65115E9058492A28ULL, 
            0x368066FC6A8ECFE3ULL, 0x365EDF14D00EA164ULL, 0x9D546CE6F69B9ABFULL, 0x8845B2AD357390B7ULL, 
            0x99BF194A4D4A37FBULL, 0x17328C6829FA3630ULL, 0x39B21CC57579F157ULL, 0x978EB94FAFA53DFBULL
        },
        {
            0x47E389E953BBBBC1ULL, 0xC8231B3F9BA02D41ULL, 0x402D44939C94A2ECULL, 0xE626E91490D851C5ULL, 
            0x99B7F2289D10F6D6ULL, 0xD862C49F48C45B90ULL, 0x862298101B042424ULL, 0xB9BD3AF577ABD3EFULL, 
            0x1131C19AC4C56AC3ULL, 0xD99B40AD69E343E9ULL, 0x7ECD4E7D8EAC974BULL, 0x2CF08684EECF7EABULL, 
            0xB69B219074594D33ULL, 0xE1A42EB89BDC3198ULL, 0xBD71718F091BD9FCULL, 0xCB64AF829F488FE1ULL, 
            0xED8AD73C5C3C0456ULL, 0xF6DEE7A53AC2F51CULL, 0xEBA7F8AD1DDDE651ULL, 0x04586E78CA446671ULL, 
            0xF803A00FC2CCD433ULL, 0x1DBB8C229D34B070ULL, 0x4EA38BA12D1CA2FFULL, 0x6E349BD1A0E3E74EULL, 
            0xAAD7DFDC926B16B4ULL, 0x69DA636C16338789ULL, 0x44FEF866CBA042CEULL, 0x9DE5DDEAC9F607B8ULL, 
            0x3899B3BA06628780ULL, 0x5E534215DA1B3AF8ULL, 0xBB8D3FC9A3F566D0ULL, 0xD7CC0CBB292BB650ULL
        },
        {
            0x8303D46DB8B19035ULL, 0xA43A4DFE25EE0C43ULL, 0xF018D1701AA39784ULL, 0x9F52EB0E738B33D4ULL, 
            0x234EA68572B7BBB4ULL, 0x3A2A475A29F0CFB9ULL, 0x5483C2D6E3852E1DULL, 0x9DD1C98439184202ULL, 
            0xD71E03E5A0D1B357ULL, 0x66AE73296AE86AA6ULL, 0xE20967E193AB616DULL, 0xE58EBA5DE2C9CD46ULL, 
            0x4DBE52B878EF6C5CULL, 0xE0EB40BF9201842DULL, 0x8360648A39EF2E93ULL, 0x90CEBE0217627BBFULL, 
            0xCFA21EB84BCB9220ULL, 0x5A2FE39B3016D03FULL, 0xB1FB25D7A011C390ULL, 0x1234A2FBDE6A89FCULL, 
            0x4E20C284E9DBA5FDULL, 0xA6CC7F424915C0C1ULL, 0x7F9DB3AF1F8F91A6ULL, 0x28B3A028DC108AE7ULL, 
            0x2C7B63EC824DD328ULL, 0x5083B1B9E3811477ULL, 0xBE5224C41B763BB1ULL, 0x59BCE4F00C7CA16BULL, 
            0xA6FC7992B166C17EULL, 0x175C4360E58D7ADCULL, 0x477B7AA05D607B77ULL, 0x3549D915C36648DCULL
        },
        {
            0x3961B3C3B0E80A37ULL, 0x20D9D4164FCB935DULL, 0x478F5EC4D76C2B72ULL, 0x287869351346F7B4ULL, 
            0x1DB8E9AE62494E39ULL, 0x3B400FCFCDE53DEFULL, 0x894EEF58E3DF9332ULL, 0xC23C61144D038076ULL, 
            0x30BF9604C0A64BC4ULL, 0x890DF9A7A17D3C84ULL, 0xE58F7CDA8CB6FBBBULL, 0xF4088067967A76ADULL, 
            0x22FF3859D736A01DULL, 0x43ED098A78CD5E8AULL, 0xA30CE83A90E829B7ULL, 0xE3769D1B1DC789BAULL, 
            0xA879D1D642042243ULL, 0x0667A80B051F0958ULL, 0x7C3FBF3E515EAE83ULL, 0x9548948712D7D06CULL, 
            0x8C560DCB18854FCEULL, 0x7836B0A20BAAD604ULL, 0x0E2C02B775A27724ULL, 0xFC39C91FA1EA4212ULL, 
            0xD8D5C3970589D67EULL, 0xBEE7A1B55FC5F9B7ULL, 0x19638BAEEFE04CFBULL, 0x0FCC7F381D67A8BFULL, 
            0xF4EFB9979195FAF1ULL, 0x5639D3A4F4958B49ULL, 0x7125CD3841299EBFULL, 0x820318EDACB0A59DULL
        }
    },
    {
        {
            0xCE3CD6C3153DCEDAULL, 0x41C6F7E67BEA6560ULL, 0x1B2A1BC7076007F8ULL, 0x1D0AF9A63CE42184ULL, 
            0x6811F2B056153BEAULL, 0x07AB1AE365CA1AF4ULL, 0xD7EE98B8655D8B8BULL, 0xA60BE4630DA6544FULL, 
            0xC9C3A8894DC5A901ULL, 0x2E9AD246436A934BULL, 0x543647B31D010406ULL, 0xE587D5883A6C8F4FULL, 
            0xEB52ED3E1A27103DULL, 0xC957FE18B2CCA187ULL, 0x7C4551B1B4EFF817ULL, 0x808E1B31023E0CA0ULL, 
            0xBCAE70AEEDF2C349ULL, 0xA41A2E88436C02B2ULL, 0x10D00DF30392379CULL, 0x52F27E764E40D2C4ULL, 
            0xB0C01BD5612176EEULL, 0xA8D6A9E27630EE80ULL, 0x0E60BC446A877D72ULL, 0x153295AAC8E2FC1BULL, 
            0x441B9A75723E381FULL, 0xF1729661E597086EULL, 0x7062923E1AFCE65CULL, 0x7A5BF2F942C4D7DAULL, 
            0xF3FC2DB409782472ULL, 0x378E544C76189027ULL, 0x216DD862A5333C22ULL, 0xF4482DE33F82C709ULL
        },
        {
            0x098B6B1A9D325377ULL, 0x410FC8BEFF3F62D7ULL, 0x393EE30942F85C32ULL, 0xB277BE497D1B24C5ULL, 
            0xC2C0880827780A84ULL, 0x6C677D2B466343D1ULL, 0xD5792B2F4C7A4FA0ULL, 0x7F04E4744932BBA1ULL, 
            0x5397E9799570F178ULL, 0x3E2EB473ADAF6C6FULL, 0xEDC1F7AF7A3C6AD5ULL, 0xCF2BD44D66916EDCULL, 
            0x19C3AA573142B658ULL, 0x4598074E333F8CEAULL, 0xEC9E969F928D7E10ULL, 0xC72E9EA1E3A29151ULL, 
            0xEBA65A8A651D97F5ULL, 0x15BEB7F56369475EULL, 0x51652486F2A34270ULL, 0xB49874FEFEE749B0ULL, 
            0x4D9A3940C37F6042ULL, 0xDBA231A84018317DULL, 0x8E4B57203C5A7FD6ULL, 0x884A5945F48C9A7FULL, 
            0x798F57C173F9F254ULL, 0xE577BD3E086577D3ULL, 0xB3FF3677F2EB35A3ULL, 0xC0770A83F30631DDULL, 
            0x6381D5D7ECAB4A65ULL, 0x283808E957798A97ULL, 0x8B06A1D4C27E63F3ULL, 0xCB03F9B2AF191F64ULL
        },
        {
            0x890B9672A6A38A6AULL, 0x546232362EE2D300ULL, 0x959B533664505534ULL, 0xA36EBA39DA3B8721ULL, 
            0x650BE2630BFC7312ULL, 0x6DA62112FE38FD29ULL, 0x3F97E3E0E399FA10ULL, 0x8CB18B70A515A404ULL, 
            0xFF392482F86E788BULL, 0xE8C01284F4D80F9EULL, 0xDEB522D15CC3A23FULL, 0xC9C685B09A5566FAULL, 
            0x66A36879C14633A4ULL, 0xD124F881F8950C71ULL, 0x1F67C19E34E3C16CULL, 0xC9A3E25F8C23B640ULL, 
            0xC9AC9E7A5C262391ULL, 0x4C4C2A90E03F07B1ULL, 0x087CDBC2525C3B34ULL, 0x99C0DD27FFE64869ULL, 
            0x0B8A883CBA9EC62CULL, 0xDEB83766BD9B5640ULL, 0x241C7BA11B231BFCULL, 0x32C77894B1DA2580ULL, 
            0x0F5BB5FC92EB6061ULL, 0xAEDFFFF9D8451F72ULL, 0x581D7F0D445F9242ULL, 0x66545C10828023FDULL, 
            0x94568AC14BD985E9ULL, 0xA890D8CAE41A8700ULL, 0x446E8C52501DBF54ULL, 0x3D4258014E04E8EDULL
        },
        {
            0x25E22BC3CD1D58EDULL, 0x032E7602F5ED0720ULL, 0xA6275B2D5B9AE84EULL, 0xEB55FD2AD8F8B696ULL, 
            0xD5D52317A92F5E91ULL, 0x8C381CE0F7933D38ULL, 0x66D864AB3C160F8AULL, 0x7C2366F7143C0E79ULL, 
            0x606E3E04B6A02464ULL, 0x1069278396F98F87ULL, 0xB4FE4F4872878D60ULL, 0x8F9246AD56B00CE3ULL, 
            0x3270ABB2EC41FEFCULL, 0xB32A2C2895B87E3AULL, 0x1F5C6975D5817F43ULL, 0x2EB630EF72B5C8C7ULL, 
            0x905C0EDFE3B4B9A0ULL, 0x1C88C80F816FBE0CULL, 0x1A6F6ECB70F9338EULL, 0x46079067B7A5F41EULL, 
            0xCEF97636EC5451E9ULL, 0xBA8D5102269CB62AULL, 0xB5D9748161A359F9ULL, 0xB5A77F624B161B80ULL, 
            0x9A8A24C987C32698ULL, 0x95B6726F70926655ULL, 0x6134F239FA4A7EE5ULL, 0x66E5D9E946C2391DULL, 
            0x9A5FE0A74C2F4AA6ULL, 0x7729D72D06937773ULL, 0x3B11B240430BC1CAULL, 0x2D8B75B5B87FEF85ULL
        },
        {
            0x75CEF1E214FE2B85ULL, 0x972D2F438466B460ULL, 0x456F1F2100549E88ULL, 0x1A95443876A98C8EULL, 
            0xE6AC1967BF61C382ULL, 0x2668E4D3B71D2B39ULL, 0xDA5AD82B4526EF9BULL, 0xD0C14A0AB517A3ABULL, 
            0x372C513503169611ULL, 0x06E3CE120621CE01ULL, 0xD04EB61D06684B63ULL, 0xEC4867D17802C5FFULL, 
            0xE992EDBAB49F0C88ULL, 0xF69495E2C4F4DDBCULL, 0x3C5436BFED957CC3ULL, 0xC5748E2CB8A7ABE2ULL, 
            0x42D8D738504A1E62ULL, 0x7CDF23247B62476AULL, 0xCA5D45BDF6D29659ULL, 0xC38E6518AA54CF8AULL, 
            0xDF6B12E142B91679ULL, 0x706F73C0FE55EF93ULL, 0x5C5FE3E6676F950AULL, 0x93DD57D54C6F5166ULL, 
            0x961596A26EAEFCFEULL, 0xBB6FEEBF87341D2EULL, 0xD9B4D304CA387063ULL, 0x4820FC76A7D90E2AULL, 
            0xA7E5360A39EE7B9EULL, 0x91253203CDA4D5A6ULL, 0xF53EC4E14CC5F581ULL, 0xFC5BD27977D0BD0CULL
        },
        {
            0xD42ABE7CF92567F2ULL, 0xC0754529D3048E43ULL, 0x35678D5EDDCA38FAULL, 0x5EC03B70ED057426ULL, 
            0x5A49D3BB2CA2B2BBULL, 0x26A6DCBC9B05AC4AULL, 0x334E86E617F587A6ULL, 0xF34BAE00AC2F607EULL, 
            0x1284F48B33DA8BFDULL, 0x0337E84C279AE252ULL, 0x705256E5696A3151ULL, 0x5409057FC6914810ULL, 
            0x4D6146956DB68179ULL, 0x56FF1B47B173476EULL, 0x7B42F4A09E2F0028ULL, 0xD0A543F64D3EC402ULL, 
            0x9E161EAC2DFF4838ULL, 0xF129C724156BB627ULL, 0x26DC24CD5DEC4F0BULL, 0xDAC8DC9EE7353A52ULL, 
            0x35A592C0E16AE97AULL, 0x39B506176E2062ECULL, 0xAECF24796D991EE4ULL, 0x9E91BBFCA675E7C0ULL, 
            0x35F37AEE22BF7D5DULL, 0x3C70766590D9BAFDULL, 0xC11BD03B2A5FE55AULL, 0x731944E977065D73ULL, 
            0xC972017A16454BD1ULL, 0x084C6BBD05B48C7FULL, 0x132332997C5C51E2ULL, 0x8F91B87F56FFBAB1ULL
        }
    },
    {
        {
            0xE5AD926FC9899620ULL, 0xFDE6345517A1A5A8ULL, 0x861B9D302873687AULL, 0x4B778475DEEC08A6ULL, 
            0x644628BF18BE5445ULL, 0xDB32F191D3188C81ULL, 0x7BB8069B1E648048ULL, 0x48222AE270E42C08ULL, 
            0xD4585B1AFB90E520ULL, 0xBB34DCC0116B0001ULL, 0x8B97541603D175D6ULL, 0xA323ABD7D7387CCEULL, 
            0x2C76C425457CF9BCULL, 0x718F1B9DC86B8DE3ULL, 0x4690CDB86D8B4CD5ULL, 0xDDF2392EED538822ULL, 
            0x7B2AEF75BA6851A6ULL, 0x3816DE9192D64B21ULL, 0x059E10D099D43353ULL, 0x1414AA89B9E7673DULL, 
            0x6E798319DCDE6D4CULL, 0x77C6C3BA0C60B151ULL, 0xABFB7C8A8E0228DBULL, 0xEFDEDC59A26C939BULL, 
            0xE7D5726D378989A2ULL, 0x96481C260EB9088FULL, 0xC3DB7C57AF60FEA3ULL, 0x7CFE3ADE522E5E7CULL, 
            0xE32FC6F6A8DFA951ULL, 0xBD1C49E683931645ULL, 0xC275A4CA5CB12E1BULL, 0xA03A84B707C267A8ULL
        },
        {
            0x8CCFAD9E80B44E0FULL, 0x2D130142FB93AF82ULL, 0x9D9A4CAF79889F3AULL, 0xCC43F8C937EB1988ULL, 
            0xD66CD53F7A2D9C17ULL, 0xB708B3B03A053BD1ULL, 0x04CFCCC7C6C9B24CULL, 0xEDC90AB5DBE7F318ULL, 
            0x730D5AAE2AB74104ULL, 0x14BEF3552F2CE8D9ULL, 0xAD45B4B238E13181ULL, 0xF9FA257186273BCFULL, 
            0x6B3F8D5299F8AA1CULL, 0x7C8B11806D5E408BULL, 0x5A43EE61A8EBFABBULL, 0x7D13CC08FAF77071ULL, 
            0x62BA44E30D16E293ULL, 0xEF4665F843E000AAULL, 0x7B732B73D184BC13ULL, 0xA38723964EFDCF4CULL, 
            0xC0A8DB0B4F4DE567ULL, 0x5913001741CDDAFFULL, 0x29361DF973A85415ULL, 0x6CCC169CDBF1CBCCULL, 
            0x0A97761DC4A89E8BULL, 0xA3574953E59F6573ULL, 0x865DDC32F1250D6EULL, 0xEB24310076122BCAULL, 
            0xB4D4DCF1117A9097ULL, 0x09C89A32512BCABCULL, 0xF217F31727F278E5ULL, 0x1DB87741E30AA402ULL
        },
        {
            0x100AE127BF1EE5F9ULL, 0x5103A9BD3C36984AULL, 0x5863026BC585C24FULL, 0x1024C8D78CA70E7BULL, 
            0x7CBA089402B1B57FULL, 0xBC3FF7AE836CED62ULL, 0xB970E29E242451F1ULL, 0x01623CD72B5BE708ULL, 
            0xC9644B17A1C482D9ULL, 0x1A1450D0B2E3D58AULL, 0xE882A7ECB26425FEULL, 0x00499F826CF6F2ECULL, 
            0x54428301E9A42677ULL, 0x1866391775B5BB84ULL, 0x7838C62C286EA392ULL, 0x4A694C30B9DA8514ULL, 
            0x7A334D73F268680AULL, 0xE0E5ABE363604FC4ULL, 0xFBD9E4C660DA0C0AULL, 0xA1F46D660439736DULL, 
            0x2D10A361E853F3D0ULL, 0xE956F8A38EEDDF81ULL, 0xD35B914EFEFAD8A4ULL, 0xBD93022DFDBC04EEULL, 
            0x8CC6163D4161E292ULL, 0xBB860724AA94C8ADULL, 0x5717ED53FB160CC2ULL, 0x7E67BFB35DADCB46ULL, 
            0x3A644033B1C264F0ULL, 0x6F51B6749D7D39A1ULL, 0x7FBB154387026D7EULL, 0x65452A63FFE243FFULL
        },
        {
            0xCD343935ECB3574CULL, 0xF9980BC3B434967DULL, 0x77DB9F33A389EBF4ULL, 0x6E0EA384AB2E2C90ULL, 
            0x6904CB33A649B19CULL, 0x93716440ABEB3F9DULL, 0x9B0C770A4E6B3FE6ULL, 0x73ACCDAFB719DA14ULL, 
            0x0A3B233164AF4561ULL, 0xBC7147D0DDCC55A9ULL, 0x6886BB9CF860EC91ULL, 0x5C65EADE962F49FFULL, 
            0xD41D378B033E4FA9ULL, 0xDB50626C484B767CULL, 0xEA98B003BB49F35DULL, 0x3ADC7C5B20C645AFULL, 
            0xAFC3989B2A8E1F81ULL, 0x2E17C9620C571EAFULL, 0xF9CD7DD55A795B89ULL, 0xAF7AEB458AF93F6FULL, 
            0x18FE02E0AE81A4B4ULL, 0xEFC27E5F7F388485ULL, 0xE044FB404583B350ULL, 0x13CB10877095BA91ULL, 
            0xC3F0496DFA3356D4ULL, 0x4D57CF0A9877C3C6ULL, 0xB00849ACAFE56715ULL, 0xBBF18178A646237CULL, 
            0xC8BFB0C55B370B74ULL, 0xB7CBF32F7CF4A7E3ULL, 0x19F57E5CF5ACFA53ULL, 0xC87AD4763117855CULL
        },
        {
            0xD3DCFC9AA66380D8ULL, 0x0E216D96B00CD599ULL, 0x785F675A688CD67AULL, 0x5A857C93F168376AULL, 
            0xB4DFF799E194B0CFULL, 0xE81F504DA9AF8C8CULL, 0xC015A68C5AE11BE8ULL, 0xCC710E5A5B712DBBULL, 
            0x56C4D3A52D97BE93ULL, 0x8908DB9F9C18FC04ULL, 0xD5BF875D9544E58BULL, 0x0660AD70B493ECCBULL, 
            0x81CD18F8C9BEDB68ULL, 0x84BD90D8525CEFE2ULL, 0x1451359C63BB1E0CULL, 0xD64D676F204B363AULL, 
            0x4D52FB20F64015AAULL, 0xCF2F18492DBA1C6CULL, 0xA591B638D20F1477ULL, 0x3E07834D25084EB2ULL, 
            0x043937887AC30A95ULL, 0xFBFF2D2AD941602EULL, 0x7F1ED3D64886EE9EULL, 0x81FA3B9DD97E71EEULL, 
            0x4F843172162912B7ULL, 0x396670D93640B6FFULL, 0x1DAE8F5F70656E82ULL, 0xE4A6E04F1E74E77FULL, 
            0x76F6E8314E7A5340ULL, 0xD2BC07FCE866DA8AULL, 0x8ED733DE92F2D5C6ULL, 0x5E723DF792DB1C18ULL
        },
        {
            0xC364B68EA678D066ULL, 0xC7844AF7E1F6450BULL, 0x690F5EFDD98F85C4ULL, 0xDEF48AD1920FB8DBULL, 
            0x27EA1A7B5F43746AULL, 0x45A20062CF2790AFULL, 0xFA3FBE9507FEC757ULL, 0x50A34B9851B3F768ULL, 
            0x22D312EC6176005FULL, 0x1ACC58999ED539C0ULL, 0x86794EF19DAB592BULL, 0x4E193B3B909DC6CEULL, 
            0xEA00AA43CEEC4F63ULL, 0x4B2C89E60E4D0C15ULL, 0x01BF91CACC6951D1ULL, 0x301641DC13729D3BULL, 
            0xF1DD9055A0A8ED69ULL, 0x3B8383795193640BULL, 0x129E83CE89B3D1B6ULL, 0x58FBB99A840297B0ULL, 
            0xFE0E884182BD0990ULL, 0xB3483F248365A9DDULL, 0xD1252E20EB91490EULL, 0x97E758A618AB2F04ULL, 
            0x629DC91517651CA2ULL, 0x0FAF3B029E6A0B4FULL, 0x3423E342A88D2736ULL, 0x6F95EA45D3719930ULL, 
            0xD6E3A152607ED0B0ULL, 0x3CD8275E2AADF7ECULL, 0x69A7959B9C8EA611ULL, 0x2555B9AA2475F9ACULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseAConstants = {
    0x5C2E8A4DA1CAB01FULL,
    0x52F9B103DC0F4554ULL,
    0x23CDB38CDCED28BEULL,
    0x5C2E8A4DA1CAB01FULL,
    0x52F9B103DC0F4554ULL,
    0x23CDB38CDCED28BEULL,
    0x98716322E911B6D9ULL,
    0xA3169EF9563CD977ULL,
    0xEC,
    0x0C,
    0xB5,
    0xE6,
    0xBA,
    0xF0,
    0xE0,
    0x4C
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseBSalts = {
    {
        {
            0xAE8D99858E35F3B0ULL, 0x8CAD87F9F7B1B63DULL, 0x1E2DDB1B6DA8746AULL, 0xE7A3D402C117037BULL, 
            0x052A5DCE4FAE679FULL, 0xAA83818CEE7A7973ULL, 0xDE988A39084C4A19ULL, 0x201EEB62DD71A8BBULL, 
            0x4D4BFA0CACF6D6D1ULL, 0xADFCEBFA826F5EC3ULL, 0x210AF28130E837BBULL, 0x68E82DE7A8F62CAEULL, 
            0xE0E7D3D197DF8976ULL, 0x8CD3535AC959F748ULL, 0x861DC5CC96DD61D7ULL, 0x05E4771AD6025449ULL, 
            0x0125145412C29541ULL, 0x134B1C9594EC361EULL, 0xE97C708E33BFAA2FULL, 0x8988AF92C29CB1B9ULL, 
            0x44CAF4E92D3585BEULL, 0xCBA0956769A6DAA2ULL, 0x9261C0E33090DD78ULL, 0x42E4847B0C07783EULL, 
            0x474589548C473C70ULL, 0x60B5038A392FAEACULL, 0xBD91E7DF4D20AD9AULL, 0x414924BA7507109AULL, 
            0xC30563FDF4284812ULL, 0xDC32E9279DC5A1B7ULL, 0xD0F979983D41D6A9ULL, 0x30EB0496C554EFA9ULL
        },
        {
            0x84A25B3E81BADCE0ULL, 0xD233D2785EDB9FCAULL, 0xC81D366DDF7F1A34ULL, 0x71530DB183539F24ULL, 
            0x607ED64CB58D64C8ULL, 0x9E694AC73C14930EULL, 0xB5FF0572E5AA9E88ULL, 0x3BE0FFB2360C3326ULL, 
            0xF2DE1565DB315FFDULL, 0xBB79BFC0155839E5ULL, 0xD450286E4EA81B93ULL, 0x3686086820A4862AULL, 
            0xB97B0D55B5C861FBULL, 0x99F75B06A346DCFFULL, 0xA5A171235594386DULL, 0x809AF00B57638A9AULL, 
            0x2BA580E61E61D285ULL, 0xE62CC80AA4A3D136ULL, 0x41E4612A2FD57654ULL, 0xC0089C80442991AFULL, 
            0x3BEE62F6A3421C6CULL, 0xE5D3E79E1F5542A0ULL, 0xFE383657BF541119ULL, 0xE7B721372699AC5AULL, 
            0x4A11F723D2EB63D9ULL, 0x033246C7E764E1DFULL, 0x3E5DEA222C0AB2E4ULL, 0x04E8F601D48AAEEFULL, 
            0x20E9040A31DDC329ULL, 0x527A37616A4DFEDBULL, 0x158018979B5AFEB1ULL, 0xC455C1E45A3BA1CDULL
        },
        {
            0x8F53B26B3932DA3AULL, 0x64148855C4ADE28FULL, 0x463350AD11129FA9ULL, 0x50A3F0BC66E6B9B5ULL, 
            0x7BC34F2ADC6BB602ULL, 0x371BA70FF315BDE6ULL, 0xF159C28BD546DDE4ULL, 0xFCAFE01BB4700886ULL, 
            0xC519DEB80AD284B2ULL, 0x7E6CB0680FDF892BULL, 0x0BE09BBA10CE404CULL, 0x3DF81D57EDDD5B22ULL, 
            0x5E025A36626FDB21ULL, 0xA9B9C30EC61B4EA4ULL, 0xC009ACFBD3C7FC3FULL, 0x7B5E2402264AB53AULL, 
            0x5A3BA0DAC5782E46ULL, 0xBAB1E2878FCC4F46ULL, 0x8B0721A6AD725881ULL, 0xAABAAA51BE108C5FULL, 
            0xEFA6D719FBD9BDA9ULL, 0x68AC8C38E0A3908CULL, 0xF5EE63A3F1DB96BBULL, 0x48BA3C0F4FC77E27ULL, 
            0x262AC3C1C99CCD6EULL, 0xD243AC35A960CB5DULL, 0x474215690AB9C53CULL, 0x3D593739178A0BABULL, 
            0x9C2E4D3E2FA50CB2ULL, 0xEDFFFB31640FD00DULL, 0xE5DD68D27A673D1AULL, 0xA04FC6FECF766080ULL
        },
        {
            0x6E231F62E8265ACBULL, 0x4342BA938EAEFCDFULL, 0x5866DF8B4326589DULL, 0xFC97C76669D769DCULL, 
            0x09CC9AE4A312F079ULL, 0x928C8598B8915A58ULL, 0x240293B336B63AD7ULL, 0x1F634881DC1C04FDULL, 
            0x48EA09377A9198E6ULL, 0x80CF211F0DAC235CULL, 0x7D4373BED84AD802ULL, 0xAAE39674BE0530B3ULL, 
            0xFC33B9CE5957F6E9ULL, 0x9F20D9036B125609ULL, 0x5BA38C3E5D6629CEULL, 0x13447CD614C5AE2AULL, 
            0x2B103E62176B532DULL, 0xBCC7438A1BCECB89ULL, 0xA41594286C29FE81ULL, 0x9A2A1A5F4940CE37ULL, 
            0xD7781D984E770DFCULL, 0x9F76F36446B883CEULL, 0xCC4B7852A4D15EF0ULL, 0x894CFE4914B50589ULL, 
            0x227E25F9EFD272BDULL, 0xE420872D9727484EULL, 0xD754B07AAE3F5779ULL, 0x36C3928D339E1EB7ULL, 
            0xB9CE09DD1DF06A38ULL, 0xC921949069D41CEAULL, 0xEE6398376641FCCFULL, 0x88DA89B5C462B77EULL
        },
        {
            0x850D1DCDB6C4AEB8ULL, 0x33A40C7288BE0D18ULL, 0xC510B991088913FFULL, 0x6B7474B9F3B88D37ULL, 
            0x378ABE9D7620DDCAULL, 0xFD5CDDEF3B87A2EDULL, 0xEE2153F4130A93A5ULL, 0xA77C03B4A315D0CEULL, 
            0xFCDFB34506D7D8CEULL, 0xFC573D694C6EB937ULL, 0x088384A83D4BD65AULL, 0x90BBAC1798A5B284ULL, 
            0x03118A438C6183FFULL, 0x435FB85FF10D3A98ULL, 0x2BBFCC23EF944BBBULL, 0x6B43F6CC5449228EULL, 
            0xCC5CFD08B9306A08ULL, 0x455AC0B313ACA1D3ULL, 0xA3C8C4CF51B16014ULL, 0x365655AC81DEF1DBULL, 
            0x12BDFEF9F7D49184ULL, 0x071B8CBBF3E30A1CULL, 0xE7EDFBF3AAD072D6ULL, 0xCEFD0888FA3ADC8CULL, 
            0x2C9536B5451912BEULL, 0x8CA5CF75A1FA2F1AULL, 0x517FF9AC075AEC39ULL, 0x60E95D4D9CB9DFF5ULL, 
            0x2D93757E2407C69EULL, 0x53BA24F45F7BF61CULL, 0x1266AA6D662A053EULL, 0xD73C2E3429355B21ULL
        },
        {
            0x610DC2B63D11D17EULL, 0x65359FDB9DE86C15ULL, 0x39869C39EAA84174ULL, 0xB80D63F86CFC9083ULL, 
            0xF64ABBC32FA8AB4EULL, 0xC299FC2BF5156620ULL, 0xCDADBC78E6DC0F7FULL, 0x85F6E3D08E249F9CULL, 
            0xBEC9886C032F64C5ULL, 0x4E13FD6559C2D598ULL, 0xE5BDFC65F1715909ULL, 0x2EA8CDA037AA7F5FULL, 
            0x9B2030D55AF24BA1ULL, 0x66DC635F329DAB4BULL, 0x1183524662F9A023ULL, 0xB448A7456012D37CULL, 
            0x96277B1CEA34E228ULL, 0xCC65AC8E78C3776FULL, 0xEB80C86CAAB917EDULL, 0xE29ADE1BD92BE31AULL, 
            0x5E66A1A96934F170ULL, 0x07F14B3B98E661E2ULL, 0x0804436443DD4F1AULL, 0xB72A0F3EC57CCCF2ULL, 
            0x798E9FA2C6376586ULL, 0x589BE0B25F20B72FULL, 0xC087FF7139C1AFB9ULL, 0xF5C642D9D310F169ULL, 
            0x9CBBF61A95B6CB54ULL, 0x01802F321A640712ULL, 0x15139B7A4566F604ULL, 0xC64BDC5F2A239985ULL
        }
    },
    {
        {
            0xC36B44D3FA02D964ULL, 0x47B4AA6865E4596DULL, 0x816D9073253A7541ULL, 0x3649CAD8C1F45851ULL, 
            0xBCE4AA5F59E8C72FULL, 0xD054D266D5F781A8ULL, 0xBB05B6BC130E3633ULL, 0xE012E7EE4D8BDC10ULL, 
            0xE17879C3F1BB3BC3ULL, 0xD855B1E3C399615DULL, 0x301D277282CA984CULL, 0x6947A0F265F1E033ULL, 
            0xF7A6DA9937E39E0FULL, 0x946A67D10CD59B1EULL, 0xF7E044BB70987212ULL, 0xA315C62D1ED7864CULL, 
            0x2763F68089BAD9DCULL, 0xE1C4AA305B227EF9ULL, 0x3FF834E3453D3601ULL, 0x246DA4EB428AE618ULL, 
            0x7986010D7662B0DBULL, 0x354D3F1C7C080DD9ULL, 0x2B6E07DF3F521391ULL, 0x1CF393D37EEE82B4ULL, 
            0x4F892C22D374752DULL, 0x58D23528288A4996ULL, 0x1C54A104CBC443BEULL, 0x78762937B42096FFULL, 
            0x3BF19C83DCDD05C6ULL, 0x3FEBFCDCA68BA5BFULL, 0x53B8F50FBF230EAAULL, 0xE997F1658FC24B51ULL
        },
        {
            0x6797C1CE10A7AB4BULL, 0x95374A01381CAFF5ULL, 0x79746284BBEB83C0ULL, 0xEF7666BEBD231E71ULL, 
            0x6C576F2825706C9FULL, 0x297D20F212E610B7ULL, 0x49C0B8E4F64B8F7BULL, 0xC1166BCE932E8099ULL, 
            0xB50024CE3F8915F2ULL, 0xD1A5434840E6DB7BULL, 0x7EAA4AD12E0EB746ULL, 0xE8931A7EFDB1F756ULL, 
            0xA82739C9A1F81FE4ULL, 0x093E87634F4D5BD2ULL, 0x8B1988EAA8D01F1EULL, 0x0979C664242FB95BULL, 
            0xB0F194D7EFD7996FULL, 0x6BD45FC21627CC13ULL, 0x59F487B6156EA054ULL, 0x5FDE0F07A2E5EA98ULL, 
            0xA28D05C8808E9E0BULL, 0xB73DB157B1F389E6ULL, 0x96398A290C034289ULL, 0x152CE8E9F1FBE104ULL, 
            0x2205872A43D70735ULL, 0xCFA77062ED0F036FULL, 0xE2F8FCAB1ADB4124ULL, 0x76A75A7D4CCE1F80ULL, 
            0xC8112D318B6DD441ULL, 0x67BB1A9E63EFD092ULL, 0xEAB9D2FB0FF02B6AULL, 0xA4E684B509281725ULL
        },
        {
            0x6459B3BA610EF206ULL, 0x95BCCDA54BFEB8A4ULL, 0xDA826F548A75EE9BULL, 0x6F204E5E62B8F65CULL, 
            0x8B52993D740B020CULL, 0xB69E78FE3D9C9B4BULL, 0x79033A058B2815EAULL, 0xD58A9D837513BB15ULL, 
            0xE9ECE28F80A3C2B8ULL, 0x801D50EEB17F31ABULL, 0x0ED63FFB764F4374ULL, 0x7AA2583BF3044EFEULL, 
            0xA57405F659A0EE4CULL, 0x6289613CAB27B821ULL, 0xD1B2431B3C52F0CEULL, 0xA176E7AE6B6F2E30ULL, 
            0x281776FF7E9F2059ULL, 0xF43F24DFF1C16317ULL, 0x88043F3F2E241E64ULL, 0xDD08A33B0DBCEDBDULL, 
            0x7AD27C599409AA7EULL, 0x96987B3D9001BF5FULL, 0x0F22AA4E72CA9047ULL, 0x0CC1A45F52404388ULL, 
            0x69C97382F8397536ULL, 0x472DE405621E1865ULL, 0x5244A90D1920CE8FULL, 0xC166BAD2ECD6A739ULL, 
            0x2D1A307EDAD023EBULL, 0x85CD7D1669BBEF13ULL, 0x50A5A4ADDE780EBFULL, 0x410041862B3CBC93ULL
        },
        {
            0x9BC7F25FBD8ABBA9ULL, 0x2ED271486B92C1BCULL, 0xE565F0A486E69B15ULL, 0xA76DBE8BF7D1418AULL, 
            0x64244856412C91C8ULL, 0x0C72BA317D7D38A9ULL, 0x9BE1DF097C4875A1ULL, 0x3AF92049FACEE897ULL, 
            0xBD3608102F6DAAF5ULL, 0xB463D709965C82CBULL, 0xA094EDC7289B812BULL, 0x1DF238E2E51A45D1ULL, 
            0x592C8034983895F5ULL, 0xBA4653EDF3541D72ULL, 0xCB1C3E9CE008F192ULL, 0x9B2ED08E6ACCDFEDULL, 
            0xE31F635ED2A47702ULL, 0x24FB6CFCC733B791ULL, 0x93970BFB73E66FC7ULL, 0xEFED3936793FD45BULL, 
            0x115B8D26606431B5ULL, 0x77227386A4AE2370ULL, 0x476405E868BCE7AFULL, 0x4FE9574360810811ULL, 
            0xF80B3FF2635A2023ULL, 0x3D779393C80807DAULL, 0x239A49CCDD233D98ULL, 0xC097D7343CC19D78ULL, 
            0x1F86C7FEFF5B4709ULL, 0xDF7CD042F4C3AAACULL, 0x506386468C6DB221ULL, 0xA58349FE9FD96C52ULL
        },
        {
            0x4F361F13EBD38D9DULL, 0x4878B17E40D9BCA0ULL, 0x8C3E60E652ACC6C0ULL, 0xDC99F84666DA9429ULL, 
            0xE3A045AC904C9C13ULL, 0x7DE2A670B131D166ULL, 0x81D115922F5DED63ULL, 0xA23D1CAFD074B280ULL, 
            0xAEB82DE29A8C4678ULL, 0x34A2D675B3C4E5E9ULL, 0x4631FFC2F94CC0B8ULL, 0xAA70FAADAA5A8E6AULL, 
            0x655CB54F300C97B3ULL, 0x26589EDB4D6F9834ULL, 0xD4D0A894E5FB555AULL, 0x5F337C440901BC26ULL, 
            0x2C9934BD7D7B66A6ULL, 0x2ABD0513857BDF2FULL, 0x093265E209664C8FULL, 0x8E70F2D199813A3BULL, 
            0x458D6743683777E3ULL, 0x827AF09AF357CB2DULL, 0x43FB8C00CF962A93ULL, 0xEC4865A9B6967D01ULL, 
            0x57E8513BC2837248ULL, 0xA097FC0026A266E8ULL, 0xF7D5653E7E0CF53DULL, 0x21321C961B914BB7ULL, 
            0xE4E882ACB7D31668ULL, 0x01584C5B645BB053ULL, 0xCDC64E5229071D3FULL, 0x94F74E6F3CCC0F13ULL
        },
        {
            0xACF9E2D98F4370B7ULL, 0x571B3E14EC6F1AC2ULL, 0xDAD53235CBA81CB6ULL, 0x369BF3A1494D8FE2ULL, 
            0x56F019CED4A2C297ULL, 0x0ED45B78FBDBF58EULL, 0x1C833A88508891B8ULL, 0xE5E10B61AFD39EB6ULL, 
            0x6EDDBA7B7D1EF0D7ULL, 0x0EB6C61EE524E846ULL, 0x8F80491E46280DCFULL, 0xD7B34A460DEC904BULL, 
            0x4D360B0B4709AAF4ULL, 0x1F5DC8D3367D5D60ULL, 0x2BFF8D1E36A7E49DULL, 0xE7BDF8F87EA3370EULL, 
            0x767F2F7BC2530D29ULL, 0x019744ABE16964C6ULL, 0x678B7E43E77BD6BEULL, 0xD80225846A92CAC1ULL, 
            0x77DD6604C74B2D3FULL, 0xFEB57306F761AFE0ULL, 0xCE32A106DD1B4FF0ULL, 0xD5B7AA5BFF8768E0ULL, 
            0x9212C32A114A2F1BULL, 0xF1F8727803EB63C3ULL, 0xF5E787FF462E4FC9ULL, 0x31205A4793D37CD7ULL, 
            0xA43F2B37DD6EE7AFULL, 0xA8347AD9E240EAB9ULL, 0x86E3E4C6DF73EACEULL, 0x06229CED88206A2DULL
        }
    },
    {
        {
            0x2512585BE2F6DC2FULL, 0x3027BE2F61FFEEBAULL, 0xD656B47FC18A1FA7ULL, 0xFB4FCC87E56D2359ULL, 
            0x29D4B4CEC19D54FBULL, 0x42A93604F830CD13ULL, 0x602A2B3557F380BBULL, 0x9F801F2BC08613A3ULL, 
            0x2AA2AFE58937038CULL, 0xCA939CBAEED1A155ULL, 0xAC9DD72EA9E9911BULL, 0x2B70FFA59DA6D30AULL, 
            0x3D77967A6EBA962BULL, 0x129F39AEDD33529CULL, 0x877011EF479108BFULL, 0xFC5FD64CBE6EDE73ULL, 
            0xB5AA94E6340C2BB6ULL, 0xE10682931BC858A1ULL, 0x36A08BB1F6723E03ULL, 0x3D5935C80F94FBE1ULL, 
            0x6A6F57A2EE1E752CULL, 0x4ECE3EB15769551BULL, 0x9D71C4EA50D48B43ULL, 0x85A23A955D517F40ULL, 
            0x9352DEDACD4AB8B5ULL, 0x3CFE2D14D3CE5C6CULL, 0xFEA1771C8A24DF57ULL, 0x51F347B2730D275DULL, 
            0x9116A6FE67572F29ULL, 0x95A492CDAC76DF2CULL, 0x6E1215A8E0EE2C0FULL, 0xCF4522A553B36609ULL
        },
        {
            0xC8B9A442F1409CBBULL, 0x611320D8478BD9F7ULL, 0x286C2344917D251BULL, 0xE653A20080C8E997ULL, 
            0xC6943F1DB99FD5B0ULL, 0x297D6D52547E9175ULL, 0x79EA96C55F93F20AULL, 0x6F766008415599D8ULL, 
            0xF228BE7C91C85EB3ULL, 0x818A67D80B29F8C6ULL, 0xD92E52014536395BULL, 0xDEB8363C73AAD3FAULL, 
            0x6A642BAF0BC1B95EULL, 0x2D75D1198630526CULL, 0x7021FF7A34071AB7ULL, 0x345B6F1BFE42C0D0ULL, 
            0x429D3F20F3F5E3EEULL, 0xC0FB0F3EC0247C62ULL, 0xBFC49431FBE615F2ULL, 0x0BAA2C73BB00105CULL, 
            0x9E8D184F8B1907EAULL, 0x88A5369C7EC13754ULL, 0xE1D1659D571717EDULL, 0xDF6AA4BA9DB9FEB5ULL, 
            0xC4FE71332BA2DDF5ULL, 0x6D25175959380D6EULL, 0x2984418E9D84D006ULL, 0xB78407CAFAA5A8AFULL, 
            0x1BC680D02CD5192FULL, 0x80410FFA34B4040CULL, 0x0773A7FD01DE32F0ULL, 0x411C53A523D8E2A0ULL
        },
        {
            0x0589E4C47C72CE9AULL, 0x480E3A550495FD76ULL, 0x788AD78FE20C75CDULL, 0x99D6B41A9A062C34ULL, 
            0xCDA9FA974985946BULL, 0x615BD29C098B5141ULL, 0x1E850EE1133C65DBULL, 0x6BBDAE336656F022ULL, 
            0x1FF0E0CA76E4B119ULL, 0x9012E62F12C8DA6DULL, 0x4A916B7F9F23D1E4ULL, 0x2E1CBFCA57BBE323ULL, 
            0x71D37BD05A1A79D6ULL, 0x5906E369C89CFA5BULL, 0xDD282E01390D8B36ULL, 0x7D3A07F04490CCD2ULL, 
            0xFCE25753A5F7A6E8ULL, 0x22645AE45BBA0178ULL, 0x2F60A993E9F95C9AULL, 0xE6B731D39C54E9CCULL, 
            0x0BB94A896D1F351BULL, 0x4F5514E66FCF06C4ULL, 0xE13ECA7E7A681CA5ULL, 0x825949C19563E5C7ULL, 
            0x5CB542CF323FE68BULL, 0xD5D88E00EEF6D79EULL, 0x33A7CD9920D8D898ULL, 0x0A64910C64B1856EULL, 
            0xDBEBC5879CBD05ADULL, 0x646419A498D16BB2ULL, 0x687DDA7205245AC8ULL, 0x86E874B9F8DD7036ULL
        },
        {
            0x9E46F85AD2FF7D21ULL, 0x18CD1FE9DF36181BULL, 0xC25A3D8C772C0393ULL, 0x42E63909003D1D52ULL, 
            0xFF777BCF9DAC785DULL, 0xDC2F964D2F13DFA2ULL, 0x842CFCAF0E7204D1ULL, 0xD27667AC7E595408ULL, 
            0x8E45913ABEC31D58ULL, 0x58A86AC7A696590BULL, 0x5CB7C35DD1192AE8ULL, 0xF104A53C002EAB93ULL, 
            0x25B9E9ECC58286ADULL, 0xACAE89397926770AULL, 0x254809D930029A20ULL, 0xFB89BFFC96CEA48CULL, 
            0x58156B4D1B9393B2ULL, 0x54B242193444A989ULL, 0xCD736EEC09089E79ULL, 0x7361315EFC2C039BULL, 
            0xBF5AB5FC3FC63415ULL, 0xA0B3551882DA3499ULL, 0x7FB97189612FC5A7ULL, 0x23759C518EAC016BULL, 
            0x1951B616CE5D4306ULL, 0x19FECE2B1A2BFD7FULL, 0x470836086C7A61D0ULL, 0x132D3FA5708D1C83ULL, 
            0xF82CBDF85D12DA71ULL, 0x2DE7AB3122857557ULL, 0xEA0F18487C4D620AULL, 0x6420BE810B28F35BULL
        },
        {
            0x58BA956A66B8E879ULL, 0xE14D76709FD38E75ULL, 0x4368FAC8440AAD0DULL, 0xAE1555C920352FB2ULL, 
            0x3961209AEE0F550FULL, 0x6C659B833579E12BULL, 0xB1C1B8978757627AULL, 0xBCDDA10E52193D58ULL, 
            0xABC4165770275F8DULL, 0x79825B501D51A291ULL, 0xAEC8300D9DCE8355ULL, 0x696A01331AAB7610ULL, 
            0x7046F22460102E96ULL, 0xCA1EAE6552D36F40ULL, 0x8126F41D132073D2ULL, 0x45FD9322B721AE22ULL, 
            0x74F620EBA1C2D338ULL, 0x7E3CC8DDB1B759E7ULL, 0xFCEDB24E5A46450FULL, 0x76604392DC00E157ULL, 
            0xE5922FA7D92C1B1EULL, 0xFD2770E3FB734DC0ULL, 0x5473CAFFB0BA8F4FULL, 0x94B32408931DEF19ULL, 
            0x8CBC4FBCCAF18083ULL, 0x9F458954B3AE9D39ULL, 0xBE84C8C962405978ULL, 0x82411582E0313342ULL, 
            0x6A4C2887CA647C64ULL, 0xE8BEACD5C9473DF2ULL, 0xAB8D4D993BC8C849ULL, 0x438716C83957C1E8ULL
        },
        {
            0x74CED07E39B61475ULL, 0x1D1A6C61E2A7A2E2ULL, 0x7D7A2A87DD9344D3ULL, 0xC64D0C495B2DBC17ULL, 
            0x8D085A4FCC120448ULL, 0x624E232DD4FA0408ULL, 0xBFCB182AA054DE59ULL, 0xF828111546F33B00ULL, 
            0x80EE1D358DC02C43ULL, 0xC1F8A6B0CB8B593CULL, 0xCF97B769618510EAULL, 0x93C164A404A8E6F0ULL, 
            0xC3EE6C41B5B573DEULL, 0x5AFB5085E847BA80ULL, 0x701EC7639DD8A7AEULL, 0x4D641DDD024D5331ULL, 
            0x2D19510A4A7D3CC5ULL, 0xF7EB8691789E34A1ULL, 0x3F574F7CC9A62C0DULL, 0x686184FE89EFCCC8ULL, 
            0x06C856BC7CC92B40ULL, 0xBC00047A7F0CFE7AULL, 0xFD26E40C5AFD8DDBULL, 0x4438993525111F5BULL, 
            0x35C4953AB0674211ULL, 0xA3E50A8A6D17A405ULL, 0x541D380A5497E0FDULL, 0x237EB3578EDF862DULL, 
            0xFAF420AED0D43DDFULL, 0x246C31EE5038E5F7ULL, 0x5A1F9EA47B4D5BECULL, 0xDA1B7F9ED1674C82ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseBConstants = {
    0x8F4BE5835B98F2D6ULL,
    0xB029C4C3ADBA90A0ULL,
    0x56F037649A88EA8CULL,
    0x8F4BE5835B98F2D6ULL,
    0xB029C4C3ADBA90A0ULL,
    0x56F037649A88EA8CULL,
    0xCC18B32BAFF7CEA7ULL,
    0xF192BFE26282B139ULL,
    0x92,
    0x24,
    0x56,
    0xE1,
    0x5B,
    0x53,
    0x33,
    0xF3
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseCSalts = {
    {
        {
            0x45501665AD3A48E8ULL, 0x36836E223854B4BDULL, 0x47A1E5615DF94B41ULL, 0x94CB6EA6D1C99E94ULL, 
            0xC9F0ED9A31E82978ULL, 0x07BD0291711767E6ULL, 0x5F46D02BE612C7FAULL, 0x93B437575A476C87ULL, 
            0xE35B4995B331E277ULL, 0x0BC24A8F9507875FULL, 0x69C6ABAB3740C65AULL, 0x8CB21B22E2458BEDULL, 
            0xCA420D347254A16AULL, 0x855C5351A627F45AULL, 0x95C8903EED8BFA11ULL, 0x6DB19296B0F795BAULL, 
            0x0FAE6D3A1253E16EULL, 0xEFC54633DAB0B47FULL, 0x4E1FB1A62E8BA88BULL, 0x36268E36B05576E9ULL, 
            0xD5A59B818E7D9648ULL, 0x6A6E4B6CABFF582CULL, 0x71403D0CEE0C8BA1ULL, 0x160B0EF424F74E4EULL, 
            0x33AA0CA47CF48631ULL, 0x7DCA2C49EDB30204ULL, 0xEF7FEAE8B95D4080ULL, 0x5E44B6D80E0D282DULL, 
            0x273D33E714D6C462ULL, 0x0B4FF6AC965C7892ULL, 0x3208CE49AC8F7C79ULL, 0xE00AF12B96E0C5C7ULL
        },
        {
            0xFD0CABD33465D0E9ULL, 0xB052D082AAFF7148ULL, 0xD90D853A599D9BC5ULL, 0x91529A700738D42FULL, 
            0xE59C4FAC2D2904A7ULL, 0x8B10F8B7AEF85CBAULL, 0x6CCD50A65D15550CULL, 0xA2AAB0DD264622F0ULL, 
            0x906419E17CED736BULL, 0x310F817E799FD925ULL, 0xB07A8768CA35E968ULL, 0x8DAE0BF875553AE4ULL, 
            0xF20CFB0B1EB32E53ULL, 0x74058682EB2D165AULL, 0xE28B6BCB4980C1E7ULL, 0x7471B9E41FAE2255ULL, 
            0x41B47ADE7CDACA88ULL, 0x6DF8445A26364BA4ULL, 0x24757041BA84FF45ULL, 0xD28B3751EC75283BULL, 
            0xCBDC9B3CDACB8148ULL, 0x326C40DED2DA3382ULL, 0x505996A1F35D0D9FULL, 0x9799191C7F62D57CULL, 
            0xEE570A5B5F99471CULL, 0xA8ED24DA14C55757ULL, 0xDD97C20A09D91B01ULL, 0x97110CD86566FE48ULL, 
            0x7AC1C094C7E19D2FULL, 0x62153D4A942C8375ULL, 0xB548365090322FF0ULL, 0xBA6C25AA054732E9ULL
        },
        {
            0x6C4D4212CE2D2801ULL, 0xC6C346508C0B420BULL, 0x0CEBC20724E68A57ULL, 0x77B08B1BA1B514B9ULL, 
            0x79C3298C20335C0AULL, 0x83887A87798F5B05ULL, 0x881E5B7BE0E80B22ULL, 0x42620F2E6CBA2FEFULL, 
            0x581F22A44C217298ULL, 0xF873B87D77C3E382ULL, 0x71552539C6DFEB05ULL, 0xC738CE7AB41E670FULL, 
            0xEAC49AC9EAE12FF0ULL, 0xD9E94D8F7A008210ULL, 0xF85FE0CBB4FF5795ULL, 0x53ED039245BCF4C0ULL, 
            0x80D741E407A472AFULL, 0x1053C295177359E8ULL, 0x81FEDA8FB1DBA2A5ULL, 0x2DD9FC7E36991EEFULL, 
            0x8A9B91AC5AC50A62ULL, 0x5DDBB40DC0FE569AULL, 0x1B5DBF71F55412C0ULL, 0x14E170D4D690C221ULL, 
            0x6E509B3FB79F61E0ULL, 0x205FE1B839F55887ULL, 0xA1A4DD56588267AAULL, 0xFF68EA19D887FE6BULL, 
            0x142EDF30522BFC76ULL, 0x8A79CE48900911BFULL, 0xD0744818A98FCC41ULL, 0x38293A32AEB78B3BULL
        },
        {
            0x314F4C29C0B25824ULL, 0x2597BF0F5D6F6925ULL, 0xBADBE2E615B7CB5EULL, 0x5CDC27095C1A3FAFULL, 
            0x3398610C375B54B5ULL, 0x8D2F23A3877983F6ULL, 0x519CAFCA8B09F076ULL, 0xF66A262B013E5AF6ULL, 
            0xBDB7015EAFBD97A3ULL, 0x227D641CB7E34E84ULL, 0xA698E24B15952482ULL, 0x78FD3586245D5A3FULL, 
            0xE746F1242161E48FULL, 0xF1EA3A22EE6E85B9ULL, 0xFAA35D3F8EB75C71ULL, 0xF9B4A2F9537653C3ULL, 
            0xB5FC9DB3402D1444ULL, 0xC03F3A40A8A36A79ULL, 0x25689B25F3C68F04ULL, 0x2A01FC2CAB7C1770ULL, 
            0xB711B015C17BEDC2ULL, 0xA944F138C92C1973ULL, 0xEDA4DBE231A3148AULL, 0x082A08B47000C53EULL, 
            0x0239752F1DAE4B12ULL, 0x3E0D606E6C3BF176ULL, 0xA36CC74D35E4ABE4ULL, 0xC925620E88BE4639ULL, 
            0x7B35875A59C5D929ULL, 0xCC67E113995289ABULL, 0x9509EF7431861A3EULL, 0xE5FB280693351B0DULL
        },
        {
            0xC13378AFE659BF26ULL, 0x6F3B947AE84EEA37ULL, 0x35234AB60713C8A6ULL, 0xA1742DB355BE40F6ULL, 
            0xBDBAD75E63105D87ULL, 0x628704E6FB7C2621ULL, 0xD5A28E460FC440D3ULL, 0xD0C6425D4EA9AFEBULL, 
            0x3B07CB8B1E30907EULL, 0x3B2478CCFCBBAF9BULL, 0x817514A4D529BE7EULL, 0x7379D81A53223B7DULL, 
            0xF8B2B084B2355B88ULL, 0x1240C211F31190FAULL, 0x7B71C9A2EF57E9C0ULL, 0x71047C1FE5EFD66EULL, 
            0x59830D84AB61C6E4ULL, 0x7B0CA9955A6D5F32ULL, 0x6B891F43DA742D24ULL, 0x48556403202E87A2ULL, 
            0xC2EFAED4607B5F44ULL, 0x616F515E3FF4B5BFULL, 0x9E1560A7342AFA6AULL, 0x835407A711E3BCABULL, 
            0x91D9754CF05DCDACULL, 0x9018993EA497BA94ULL, 0x3D0312829494A246ULL, 0x4324BE6207CB1431ULL, 
            0x967B02A39C8FB7B3ULL, 0x36CBB2D6469C237CULL, 0x29F1FB8528C85368ULL, 0xF096A2F726B036D2ULL
        },
        {
            0xDE96B1A8CDBA6566ULL, 0xB8ACF3FE7A37C46BULL, 0xAAA52E3FB81C8978ULL, 0x613B355C3EFA4D38ULL, 
            0xA9DFA599B6C2427AULL, 0xAD62A2556B827C79ULL, 0x6F073A60E51F0BCAULL, 0x2DAF466FEB51132FULL, 
            0xFF311CB3F3D21D8BULL, 0x0DCE1229189FFA83ULL, 0x57BC15B1300CD2FFULL, 0xFA313F75032A9D00ULL, 
            0xEA8515304460C0DCULL, 0x92EB5A58425E4E9FULL, 0x385A1A4CF12C2A9EULL, 0x7C77C0C14589EEA0ULL, 
            0xDB04CC8437F6D3D8ULL, 0xEF5FC9B7656817C7ULL, 0x0CD80C281FDD93ABULL, 0xDAEFB746BB19BF59ULL, 
            0xE0CE32C529E2EF3CULL, 0x3F1B07D841AE0415ULL, 0xBECEBC6B75D4BCE3ULL, 0xA27539AA525BEE4AULL, 
            0x1A5DC7D29399ADE1ULL, 0x759482435D0A1D43ULL, 0x747D67562EC66C4EULL, 0x0F5DE7156CC092FBULL, 
            0x1B91D0BE6AF253BDULL, 0xEF6BAC3808860234ULL, 0x1C1092E61B38B82FULL, 0x0E5C21882A0FAD48ULL
        }
    },
    {
        {
            0x5E3D9C6A3090E435ULL, 0x3DBFBB8A5892A25DULL, 0x1DDF553DE297E79BULL, 0x8C39A235CC96D328ULL, 
            0x91C7F0B2F8AE2715ULL, 0x1EEFA29C4B65F764ULL, 0x405A4523066E3912ULL, 0x858F6690CACF217AULL, 
            0x34B11FF2E741F1BAULL, 0xBF82165CDD29AA51ULL, 0x883E7CE0A56E1540ULL, 0xCA141586083883B6ULL, 
            0x3DEE9730EED9884EULL, 0xD32279DACE62E8E6ULL, 0x06D635B86D49F6F8ULL, 0x77B06ED2AB6F6A72ULL, 
            0x66C75F0BE008347BULL, 0x4BBACDDFFBDDCE4CULL, 0xF68185DC8866AEBFULL, 0xA4EC2BAFFC4583E6ULL, 
            0x9C651E19FDA3535FULL, 0x6B8F799A8497311FULL, 0x69750CF145B1FBA5ULL, 0x2541B41C8CC6E333ULL, 
            0x24F4A3BF5B96AD4AULL, 0xBF3E979763F6C21AULL, 0x1804144F0F5B9F47ULL, 0x89AF377015DCE851ULL, 
            0x3E3EA938DD617635ULL, 0x3D0B5654C8B402B8ULL, 0x3C5FD9849E699287ULL, 0x692A1A5B7B30107DULL
        },
        {
            0x1F7E23D77442FC9DULL, 0xE8B9B39E859933B8ULL, 0x97627D628FE8A5A3ULL, 0xBD795E0AFB69229BULL, 
            0xEA2DC99211387E2EULL, 0xBC19B48AE7E48177ULL, 0x0BF0A3B52B37057BULL, 0x9AE75F88F482F4A2ULL, 
            0x01555BF610476E39ULL, 0x824EBE9938FA390EULL, 0x1C51B005318E31BCULL, 0xC766B9B872013E35ULL, 
            0xFD4DB6A19602A384ULL, 0xCD7DF44A34B2BAD3ULL, 0xFC5B0A7B4F22B34CULL, 0x52EB57C2A51602B5ULL, 
            0xD64117B16C0372E6ULL, 0x01BE52369A420198ULL, 0xAA07034A68E3E8FDULL, 0x99ED3DB6F240D864ULL, 
            0x9DA5C899AE60CACDULL, 0x183463D3E392CA2BULL, 0x3325B91FF8206241ULL, 0x7A4BBEFE627C4DBDULL, 
            0xFC158D1D5213E244ULL, 0x3E5DBEF0CFD74B2EULL, 0xF0321B56F09F1233ULL, 0x85D3298D71F2A447ULL, 
            0x078A42291EDE6D18ULL, 0x241B38BA86E278EEULL, 0x024C8FC14EABF3DBULL, 0x80ED23E28072D154ULL
        },
        {
            0x47B94A90A1DAECF9ULL, 0x6619A40F55C37B7AULL, 0x32D1913919549EEFULL, 0x32CE607CEF33833BULL, 
            0xD387314999864F60ULL, 0x04326FC5CF722EC1ULL, 0x747F10F459C30AF3ULL, 0xE554BA6F3FEDDC50ULL, 
            0x3E58B9D3A5EA25C5ULL, 0x32409DB1591E250AULL, 0x7048701B70430D01ULL, 0x7C34235502E559ECULL, 
            0x1FDE94F75E7A603DULL, 0xED2EA80C593840B0ULL, 0x755F253BC126288FULL, 0x25F598E9AA0F52ECULL, 
            0x4C80BCDF659964C4ULL, 0x83F38185C4194BC5ULL, 0xC64F3CD2A984B1B4ULL, 0x2FE3ABD34AC9E5B3ULL, 
            0x6CDBE525F755D3F4ULL, 0x5288FC35675049F3ULL, 0x9718E0CB84D63046ULL, 0xD336A125EDCF41D1ULL, 
            0x1F598FE347905DAFULL, 0x061027EF1CA4F34AULL, 0x4BF138F48BEE5D6BULL, 0x9F21C7087619F3C7ULL, 
            0x64D17085369E23F4ULL, 0x7CDE63CA2CD0A774ULL, 0xD9AC07B19419D4F7ULL, 0xBB00927FC694465EULL
        },
        {
            0xF2C2C9C7D8CBAC48ULL, 0xB3D36F6D68726549ULL, 0xC4529C712E50BA0FULL, 0xE341241A71583FB8ULL, 
            0x3E59A78A3FE73E81ULL, 0x14BB7B9EE21A7E8AULL, 0x7E1BF1B7ABE76253ULL, 0x7FD3893EACD1403FULL, 
            0xDB862B14725F3A22ULL, 0x1BF5FBD45A23498CULL, 0x1D08D778B351E804ULL, 0x6C78C2C9CCF0F4F8ULL, 
            0xD8C94EED7C321FB1ULL, 0x2E44C4B659C3DC0FULL, 0x54B62BF907E491A8ULL, 0x0D9CEA8C48375F9AULL, 
            0x96907951A3EFCA5AULL, 0xD18279FE471F8E2EULL, 0x5C3BDF53459B476BULL, 0xB1050C01EA7D48DCULL, 
            0xF7530C60F025D207ULL, 0x82B7478FC1E6FFD0ULL, 0x247339BA8C426C8EULL, 0x1EE7E93D070FEA2BULL, 
            0xC7F2B3D8B4A502E5ULL, 0x508464ABC1E780CDULL, 0x39F8EB1CF079B00DULL, 0xBF3C51C5BBA4733DULL, 
            0x14F9BA3028E364E1ULL, 0x69B8E053849DE445ULL, 0xF6D9C0A1EBCFC497ULL, 0xE3D386E470117695ULL
        },
        {
            0x7EF33FA4F50CD89DULL, 0xF6D914B4F01EF2F8ULL, 0xA4E0E596FC49732EULL, 0xA2E3B1256CEAF09CULL, 
            0xE7FD3440D1B1D800ULL, 0x41AEA2641B79884CULL, 0x0244C8D56D54FFC8ULL, 0x2CA42D921C4CA62CULL, 
            0xEF66575563C89D51ULL, 0x7E70293F0424A193ULL, 0xC98880179F7CCA50ULL, 0x992EEDA490CF77DCULL, 
            0xD610EE5C6E89F8BDULL, 0x20771A12FD49D4DCULL, 0xA3D8C8B1123EE400ULL, 0x9C5261A6AA05F08BULL, 
            0x127D7FFF4E9BD637ULL, 0x870D014980D97DF9ULL, 0xD87B10D708D13188ULL, 0xB4DFBC1C36952C67ULL, 
            0x99D9EAB5BA083506ULL, 0x43686D30F76AD607ULL, 0x8E7AF8C525895A09ULL, 0x906F27DA2FF47DB8ULL, 
            0x27881BD400177244ULL, 0x9707F73850D85033ULL, 0x0068C62E00CD5308ULL, 0x0F5DBFF1BD361404ULL, 
            0x4C2D8972F04A97F4ULL, 0x916472CA8A8322D4ULL, 0xE0CE361EE8F006ABULL, 0x0222BD4DC9F5DAE9ULL
        },
        {
            0x6150731A0B006D3DULL, 0x608F4426BB493AE1ULL, 0xBB9A1664D681137CULL, 0x2BC5644F8BA3EC5EULL, 
            0x185A4684A2409E87ULL, 0xC7F7A620D24B997FULL, 0x2A5767902692719FULL, 0x0579A6DA7F312E70ULL, 
            0x8C41AF86D218B8A8ULL, 0x20AA03BFC1E523D8ULL, 0x095FD4D1A50EF551ULL, 0x0E0E395246A1359BULL, 
            0x50BFCC927876F6B7ULL, 0xFBDC1EFF2CB63B43ULL, 0x7F84B922099E8B67ULL, 0x79503CA6B021D136ULL, 
            0x3DD354FDCA4A1ED9ULL, 0xF2C8BB512D59AEC2ULL, 0xEF9D0F7570797187ULL, 0x21433EC269404FCDULL, 
            0x9ED2454C950CAF57ULL, 0x3BAF2F0BE39AB119ULL, 0x8E63144942D69368ULL, 0xB118FA31D8CF912BULL, 
            0xF473C56A80411113ULL, 0x12B5067F1114E3F6ULL, 0xBC64BCF8B0792CDAULL, 0x555541154FAC9B41ULL, 
            0x65626EEB662FAE01ULL, 0xFC3F2E53A9F4A043ULL, 0x5C99CA3C0ADCA6EAULL, 0x851304B170ED8A55ULL
        }
    },
    {
        {
            0x7AEF28F11F4D4AB6ULL, 0xCFEF87A8E5997729ULL, 0xFC5BD355E95468A7ULL, 0x7D0A6FF5CDBD517FULL, 
            0x0B6A2AC1A8D46C3BULL, 0x82BA17A268A7721AULL, 0x5FE427D8FBEDF48BULL, 0x069A051A3D6CAC3AULL, 
            0x99E7A3F429D9214CULL, 0x965D67B04BF99663ULL, 0xED972D2D9DD6F8B5ULL, 0x594A29F28484B358ULL, 
            0x773B9A5AA312FE71ULL, 0x64D1C27881DB141DULL, 0xDF1D51D57ABD517EULL, 0x52C8B7A5BAA1B04EULL, 
            0x3288DCC384219A8EULL, 0x659B198A3914B49AULL, 0xBBCD44211EEDE8A1ULL, 0x9E40CCD9F58DB33AULL, 
            0xB24B4E033BD4E916ULL, 0x8DDA50E51E209B88ULL, 0xE51C36448D5F39FAULL, 0xFA3E19F162A82B94ULL, 
            0x916ED38D61206A91ULL, 0x50E94977EA1FB551ULL, 0x99AF54320814D88AULL, 0x91E621472C3BA27CULL, 
            0x726E4C10656D5F98ULL, 0x112D60B8463DDAB8ULL, 0xEA1FC91E23F65EFDULL, 0xFA3CA61983DF61A8ULL
        },
        {
            0x52E5208151D5CBBDULL, 0x13D7B8F402BAD9F2ULL, 0x56D2AFE7FC21B89DULL, 0x5A6214BE064B8010ULL, 
            0xFF93BD7F7D71CC2EULL, 0x036E1049626E9271ULL, 0x7BBBC590A24D1DB3ULL, 0xC0165D46040D0809ULL, 
            0xFC09AEEFC05970DEULL, 0xBEB14E88636E765EULL, 0xCA265F58FA1D68C2ULL, 0xCCB2F911DB38B5A2ULL, 
            0xBB9CEC5AF5AB9CEBULL, 0xE8F1D4527AFBF5C6ULL, 0xE2F7F0F840689F66ULL, 0x4F61E898788FF325ULL, 
            0xA0827FDFC5B7F6DEULL, 0x767E411BF9147595ULL, 0x3BF9B46166BB4AC3ULL, 0x5E6D1FB129CAA060ULL, 
            0x6AF326D11B64C530ULL, 0x6B45EECA52305554ULL, 0xFCC61B5902A41079ULL, 0xCF583723D7AFE2B5ULL, 
            0x545CEF591EA5EADFULL, 0x827488E360BE03F3ULL, 0xD6992762BD8C4355ULL, 0x800088A6E87E3C7DULL, 
            0xC79D1436AC8C8E14ULL, 0x6CD5B0D42A6904D5ULL, 0x30D338D8248CD8DBULL, 0x74BB2CA588FC6F68ULL
        },
        {
            0x4CEEBB413BA17EADULL, 0xE03C062B69EF389DULL, 0x84CC16FB344F56AAULL, 0x4483F1F79E068D65ULL, 
            0x5EFFDA05ED74D5D4ULL, 0x4AB25331C3998E19ULL, 0x1C6033DB1F82492EULL, 0x0DE2ED9821FD9D8EULL, 
            0xD798023E6B4CE5BBULL, 0xC8C161E1D2AAA858ULL, 0xAB9C93B23ECBF99CULL, 0x3B08281E5547E2DCULL, 
            0x01837851FC8DEA31ULL, 0xCB030FAD2B97094FULL, 0xF71C127E039FA8E0ULL, 0x796426020A1B97D7ULL, 
            0x770AA6BEDC7454AAULL, 0x98E62890588040B8ULL, 0xB67F11DDB05948D4ULL, 0x0853A4ACE22822CEULL, 
            0x9EF98EE7E58D38D9ULL, 0x8314EAECFC5E5205ULL, 0xA0392CB018D516CAULL, 0xF63CAFEEBDCB9467ULL, 
            0x7F9E4F626A604EAFULL, 0xD5329DD2B5BDCFCAULL, 0xAA6F409AB9F67A87ULL, 0xC3FD18FB9D73F9C9ULL, 
            0x12FDD99AB8D22FF8ULL, 0xB266F0024C76CEDBULL, 0xA118EFABCB83964CULL, 0x1B0B37F6561133C2ULL
        },
        {
            0x74AA760E60226D6FULL, 0x159FAA22F921FB8AULL, 0x77DCF2489DDCAC4FULL, 0x2D4BEB2AD6BF8D79ULL, 
            0x6FFC3CE8EF06BFD9ULL, 0x2FEB81BA4A4EFC15ULL, 0x726C8E8C96BAA15EULL, 0xE8FFE3D776CCCE9AULL, 
            0x95D043641DE65488ULL, 0x7052D26AE9A4B8D4ULL, 0x8CD930869F7CDD95ULL, 0x187418BE757990E3ULL, 
            0xCF0B2F59E68F8B63ULL, 0xB1A33718DCD7C4A1ULL, 0x19A42EAA03D92C0BULL, 0x0E13985E7D68D994ULL, 
            0x486E1F2B932454E1ULL, 0x203D42F220A0FCD3ULL, 0x94BC85C029262EDFULL, 0x6EF5FCDC54E4CB8FULL, 
            0x55E4CA9CFD0E627BULL, 0xAC8C747EFEC5ED9CULL, 0x759A0590CA513C8CULL, 0x38AB5FB300E75712ULL, 
            0x8049BCBEE2494DDAULL, 0xBE28B4F21E0FB1BCULL, 0x54E65E44F47D5CB6ULL, 0x12D8DF4B30E1B768ULL, 
            0x652F94688D26F223ULL, 0xF1F6E034D84AA297ULL, 0x7875DC22042BA836ULL, 0x094120BDC89B643FULL
        },
        {
            0xBDD253789933E336ULL, 0xBFACCCF875172165ULL, 0x1597BC6CDE9DED4FULL, 0xDFF4FC03B13675DDULL, 
            0x6E5CCE34C1B4D2FCULL, 0x518727846E34AAE2ULL, 0x3B0E6BA6B28C1774ULL, 0xF2C20C3FA4408B39ULL, 
            0x5AAFD3EF2C7C0BF4ULL, 0x26C824889E373BE1ULL, 0x1E50071C56EDB962ULL, 0x4CD3F68D19324D0EULL, 
            0x3D0DEE0B11C4B370ULL, 0x12410DFF24CBD457ULL, 0xD00351085E5203F6ULL, 0x5DECD568F09439C2ULL, 
            0xC21A437C1A00A468ULL, 0x9127E0591FB1F399ULL, 0x177B15A8EBEC3DF5ULL, 0xFAA227702EE90883ULL, 
            0xF0A91F61B736E3D6ULL, 0x99929F9A7E354099ULL, 0x67E7B1A36285E8ABULL, 0x14F3EB5CE9543582ULL, 
            0xB7F9776E7F5A4F5AULL, 0x21488B5DAEFC4B9FULL, 0xA5E2667E81D539CDULL, 0x251FC2FB71F3A6C6ULL, 
            0xD47267BA87CE2C12ULL, 0x6B23F489BFF037E2ULL, 0x7AD0AC2A6F6D25CEULL, 0xF4DB593F259F0087ULL
        },
        {
            0x602DEEB904CBDE5FULL, 0xC34B1CAB99978C76ULL, 0x71D1BA604B972C8DULL, 0x5F6997F022901EB5ULL, 
            0xE2DE5C7BC11EC352ULL, 0x959BAE712B7652A0ULL, 0xA010AC7983A26FEBULL, 0x3E395F5DC3402F5DULL, 
            0x89E45D9FEC379E6CULL, 0x1B2D78C509EDEDD3ULL, 0xCABF62807C57F7DBULL, 0xFDCDB43422B8079EULL, 
            0x2FB844A941482E40ULL, 0x9ABD9EC1CFCCF9C5ULL, 0xB30FAFC6A247E0A8ULL, 0x649AA3D383A7319FULL, 
            0xE1741DE6F7FE984AULL, 0x86F2C5E01246FB9BULL, 0x2EB6AF83EF36C895ULL, 0x8ECEFAD16019F77CULL, 
            0x05942853414EF034ULL, 0x858236F82E7FE84AULL, 0x7CF6BAA4D996574CULL, 0x58BFCE4127A15C4DULL, 
            0xED7EFAF913D58116ULL, 0xABCB093D935B1F79ULL, 0xC0DC5AFFC167FC10ULL, 0xC45D080AC96B6372ULL, 
            0xF5D04DF45091C175ULL, 0x08D48CA33BB527D2ULL, 0x024D511D5A648FBDULL, 0x3B23996D41718A27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseCConstants = {
    0x9B42E5065AF5F35EULL,
    0x64EDA95665EB5A4FULL,
    0x811A51F9799F9A4BULL,
    0x9B42E5065AF5F35EULL,
    0x64EDA95665EB5A4FULL,
    0x811A51F9799F9A4BULL,
    0x7E0208B25B4E4CD0ULL,
    0x619C835828790F28ULL,
    0xEA,
    0x33,
    0x6F,
    0x9B,
    0x19,
    0xEB,
    0xEB,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseDSalts = {
    {
        {
            0x5A9CDE7DAE7D9F05ULL, 0x29BFDC0A600F07E8ULL, 0xBBADF158B1C2CD43ULL, 0xAD2215EB2C7B7E3DULL, 
            0xB4DB1F1ED02FD391ULL, 0x351837642A469562ULL, 0xB14902BD0FD01F82ULL, 0x5C2F1C321456F0FBULL, 
            0x9A2409E0868451E4ULL, 0x68BA890DB3FBA7A7ULL, 0x7758041FBD822EEEULL, 0xB56F89AA7E6E8592ULL, 
            0x2622E38D7FE51D35ULL, 0x1ACD37C9D3317325ULL, 0xCB8265A257A81196ULL, 0x30DA499495AE4154ULL, 
            0x6730190BD2D2A790ULL, 0x8ADC0189FE057DF2ULL, 0xFE68769A3150CC0CULL, 0xA347EE132B82D8DBULL, 
            0x2ECCE7C68C7DF308ULL, 0x300BF16D6BBA0A3FULL, 0x4960848C8231BE64ULL, 0x54743351DC4A1BCDULL, 
            0x89AB63A14C9166C9ULL, 0x591823C185E1D6BBULL, 0xAAA8D9C965F7B19DULL, 0xEA597A71AA2D0D4BULL, 
            0xF9E51EB7AEFCD9BBULL, 0x77BBF7FFE75A4FA9ULL, 0xEF948D1A6FD55712ULL, 0x783960688E47C06BULL
        },
        {
            0x6C5CF6E3DB9A3CCCULL, 0xF4EE3DE4F00B1907ULL, 0x8EEC9C37F4DE9C0FULL, 0xFB49D5CD56A790EBULL, 
            0x2E0506F83CD641ECULL, 0xE8F9EF63B74BFB65ULL, 0xA9BC139B6BC168F7ULL, 0x18502616E69E4E3AULL, 
            0xF1D298EE936EAADCULL, 0x43C02037899CE8F7ULL, 0x911196153E28010CULL, 0x796EB9075BF1CD11ULL, 
            0x38909B0942FD90B6ULL, 0x5FDC73292E223AD0ULL, 0x9921B7B46D8BC0E3ULL, 0x1E69D96C9C295968ULL, 
            0xDAC9B502EB6BC063ULL, 0xF83DD8623AB7EB45ULL, 0x2EBCF07327F78B74ULL, 0x058A3FA29A74C55AULL, 
            0xABBEBFDF633BFE63ULL, 0xFED82E40024AB725ULL, 0x69F9824733900D6EULL, 0x25E966575183D1D4ULL, 
            0xEA6B0E141D39D258ULL, 0x7372BC0F22D19542ULL, 0xDBEA2A962B4C775DULL, 0x833D33470156EFFDULL, 
            0xC5944CE69EEF4CCCULL, 0xBDA70B83DC200D04ULL, 0x20B682807B65F5BCULL, 0xABE7E4CFF3C1C387ULL
        },
        {
            0xD080BE34B0B3CC26ULL, 0x74EA22C284104198ULL, 0x36EF185FFAF68573ULL, 0x637CD3B0B282E60CULL, 
            0x6AFEC5B85FB3D471ULL, 0xE4B8E66DCB4E8084ULL, 0x20B4901728E60891ULL, 0x872E1177CEB63F02ULL, 
            0x8B99D00A38C8157AULL, 0x9DBB0C1ECDA502B0ULL, 0x7A25F574DBB4590DULL, 0xE53BCACA20D1A708ULL, 
            0x03829242422FAF22ULL, 0xF4AE9116F54D0E32ULL, 0x3547F5698107EACAULL, 0x3C4885969F6E28B3ULL, 
            0x8724266903AAC9FDULL, 0x4218457865A7F41CULL, 0x53E653080139908FULL, 0x8E054E01A08616D5ULL, 
            0xBB8CEC3C4237D5C4ULL, 0x12425E0F7EE34D34ULL, 0xD6EC2230B08BD0EEULL, 0x98A2AE0FB62C919DULL, 
            0xAEC044EE765C3F80ULL, 0x5D033DF14BCFB224ULL, 0x49DEBED31536D82CULL, 0x11367A1EAAB8DEC2ULL, 
            0xEBF25D0837D30D58ULL, 0xE6B48E271B6C9205ULL, 0x473F4ED81DC07A48ULL, 0xBC048AE47A5CCA64ULL
        },
        {
            0x8223FB4746F39256ULL, 0xE48AC316D72B7502ULL, 0xC03186D3A91A6B0EULL, 0x498FD1B4CB2AB04EULL, 
            0x238D28168F7046D6ULL, 0xBD2E59E15FE9648EULL, 0xF646A7AE2CB0EBBFULL, 0xB98B234FC54A31C9ULL, 
            0xA793492CAB2DA3D6ULL, 0xEB422B68DC7DD09AULL, 0x04D6FCDA5328A6DFULL, 0x96DEE9E03851F178ULL, 
            0x29B1EC480F853F25ULL, 0x1D1D695C9C1BF698ULL, 0x7D240495D776FB09ULL, 0x4DE8B4A0A6754B8EULL, 
            0xC575BDBC19E92E9CULL, 0x7C34563A665859E8ULL, 0xA55ED459532B9B88ULL, 0xFAF4D662C556EB6BULL, 
            0x6090ACCCB5DF6554ULL, 0x84C0C40079AF4075ULL, 0x3EBF82256866889CULL, 0x55D4622918DA8A8FULL, 
            0xDBF51EF947E06650ULL, 0x8A0737E13A6C8A87ULL, 0x6431AFE725508CEDULL, 0x69BD71A6BB2938B7ULL, 
            0x82AE3171BFD57929ULL, 0x2F1416FAA5A0D232ULL, 0x8FD87E6743C6C6F0ULL, 0xE2906E1BE42872D4ULL
        },
        {
            0xCCA1542387352434ULL, 0x1E1C9BE0BF3BB1C0ULL, 0xAC2954EE35FC5155ULL, 0x04D933930D5E6055ULL, 
            0x3C162F185D2EBDB7ULL, 0xF1DCCD0609191D48ULL, 0xC38BE9CEB6EF45EEULL, 0x826F98E9E2A7408BULL, 
            0x77DAB22F12533ADCULL, 0xA2A5409311D00D55ULL, 0x6BB7119781500F06ULL, 0x9ECE89481115C0A3ULL, 
            0x1618EB7C80796739ULL, 0x15C986B1438C46B8ULL, 0x0A02B2E0F286001DULL, 0x12E8343A0A18E65BULL, 
            0xECED2AE52947E778ULL, 0xA167F225E902D613ULL, 0xA22383B17B4BD538ULL, 0xC0E51DF0A2AC3535ULL, 
            0xE73C67F27D4DEC49ULL, 0x06C48C4B281962E9ULL, 0xFCC6877A006C36FEULL, 0x46CE34912B351BEDULL, 
            0xD523A237B6328E6CULL, 0x48100572E9173276ULL, 0x80335A6B570BF8C4ULL, 0xD3D4D1D44D863B75ULL, 
            0x47DF14B33DFE9F71ULL, 0x2A2D3DCEAC97818AULL, 0x7A9C4B64E6DB02B8ULL, 0x290173CB7564421FULL
        },
        {
            0x4EADDE5269CA04F3ULL, 0xBB2BF58857CEC527ULL, 0xC6A3F2B865C07BEBULL, 0x7AEA4677FFF70B77ULL, 
            0x448A4CFECC9DC9BCULL, 0x73BF28F366E288A6ULL, 0x3730D97BFC9E3648ULL, 0xB1C4F193378857D9ULL, 
            0x756A0E71E7D6B832ULL, 0xCA75228FB3CA40CFULL, 0x64C4740A2A3401A6ULL, 0x642C18CB9371FFF6ULL, 
            0xB7ED862AD453BE9AULL, 0x50221F026D83D356ULL, 0xF58942C88B3F9808ULL, 0x0AF037652C585903ULL, 
            0x9D397E4526C695D2ULL, 0xB6977FE0E1784455ULL, 0xA760D300E18F49AAULL, 0xA0913AA9B9C00EFBULL, 
            0x18AF2A1164F842D3ULL, 0x28A591BFA75800D1ULL, 0x33B5966CBCCA56EEULL, 0xDABBBD2146978A7DULL, 
            0xE345ABFD777BE994ULL, 0x5EAB2A2C8B6501DEULL, 0x08CC53D73AE8E270ULL, 0x289AAFB9BD55C889ULL, 
            0x6CADD2EA44917773ULL, 0x3E8E641680662A6DULL, 0x378449BEDC23BBC8ULL, 0x899D5FFFF699CF18ULL
        }
    },
    {
        {
            0x24CAFE9292D4EDA4ULL, 0x083BBC6C9CCD8BD2ULL, 0xAD6DDD5131BBAA49ULL, 0x405715D57DB65760ULL, 
            0x071BB7575C0C897EULL, 0x732F7E1F3C25A810ULL, 0x7F0B642E4D48C32FULL, 0x40E7911053078D72ULL, 
            0x2C5254AE6831F6BDULL, 0xC16F16E671E9B80BULL, 0xB5347DA86A4B78FEULL, 0xA59C848389EB7A1FULL, 
            0x0630F0BF76F72B56ULL, 0xC6808B072074746CULL, 0x214351886721A140ULL, 0xF159B04AB9874928ULL, 
            0xB257A2764529E8D7ULL, 0xA9CE6E635DDD1AD3ULL, 0x8861591C791363FCULL, 0x72E7BA6312E83AB4ULL, 
            0x353250457E3A69E6ULL, 0x3FDE8BC7CA0C59B8ULL, 0x9898BCF29CE0583EULL, 0xE06D8493CCC54622ULL, 
            0x2DF5FCB52977ADB2ULL, 0x34D57520C5F32582ULL, 0x5A522387FF42B9D5ULL, 0x5F31AA288F633640ULL, 
            0x892788AFD6763FCBULL, 0xCFBA2189CE0E15AAULL, 0x79CC4F6B9B901BD4ULL, 0x3BFA852D55352758ULL
        },
        {
            0x517078A689D05F19ULL, 0x4D0FDA8E18018EA8ULL, 0xDF43406DE791CE00ULL, 0xC48D7F5B2F614FB4ULL, 
            0x1C34E1E1830F3A83ULL, 0x1C1BB395AEC18A2EULL, 0x7737C4EC6C352DB1ULL, 0x11F70674B0F0DB30ULL, 
            0x642B6A865A97BE18ULL, 0x1B6625C883C5394DULL, 0xB4A5EB9B992DD99EULL, 0xC33082977AA4C381ULL, 
            0x5FD70E5981EE8BFEULL, 0x58D465FC1612B223ULL, 0x2D170FA194D8F2B1ULL, 0x5F080EB1DC91F89AULL, 
            0xAA1701C53CACC8F9ULL, 0x40A66CAD954E8D36ULL, 0x2A03B19045C12B79ULL, 0x58EB975D065F6A7FULL, 
            0xC0D54C7110198AD8ULL, 0xAC925B3285EE6ADDULL, 0x0D9C9321568D35FDULL, 0x235AEC2DBCC5A82DULL, 
            0x259043F1C36727C3ULL, 0xACDB9C06DC91C2D8ULL, 0x75FFB0DABE13074BULL, 0x6444E6C99C616C21ULL, 
            0x98F83F882E7E5B67ULL, 0xBD45BF2006C37EFBULL, 0x451416BD8AD70306ULL, 0x660DA8271EEC5D7DULL
        },
        {
            0x5104303A4266C4E1ULL, 0xD4896C5726E578FFULL, 0xB1864A6B0E7DAC1AULL, 0xC6218D3735C39669ULL, 
            0xB12B1F8407322A89ULL, 0x493B2CDB3D173C57ULL, 0x8F199435756960D8ULL, 0x7EBB6A818B578561ULL, 
            0x8C5CF2B77A40A88EULL, 0x337F044C10EFD0B0ULL, 0x16B30D72AF63DAFAULL, 0x7E4EEDA8EC406B41ULL, 
            0x484CDCA5FC9167C3ULL, 0x0D8EECD8C45A18FFULL, 0x02F5018DB167B415ULL, 0x571C711E7A4BE5BFULL, 
            0x5EC0238AF98FFC1AULL, 0x7F3C030C64BD3034ULL, 0xC611478655100D6AULL, 0x4DB620178B872829ULL, 
            0x958FAAAF6D357D35ULL, 0x9D7B2316B61D222FULL, 0xD5A5062A85A6C475ULL, 0x6EB205D9854EF5F2ULL, 
            0x156212CAD5F9DFADULL, 0xDE893EBF77B42A4FULL, 0xFD48B9C12FBA3BA6ULL, 0xFEBA3EF72EDC11FDULL, 
            0x4C0F7D515CCD1C2EULL, 0x0007A2236D261C1EULL, 0xEA3751CD72B65238ULL, 0x4B1458403694321EULL
        },
        {
            0x5B3EC51E568B6CFDULL, 0x363ED039742C188DULL, 0x38BC3EC422DB1A9BULL, 0xB6ED9E4C580FC376ULL, 
            0x58A4BD8A0018F647ULL, 0x4C72B3AF62B00A36ULL, 0xA6F84B0071EDF1D3ULL, 0x8E766486252E8995ULL, 
            0xAF5EF55E75BC837AULL, 0x1923FD0F870FC6C9ULL, 0x53EC661CB43E3A02ULL, 0x7C99DCBC93BD9B3BULL, 
            0x764DB0FFAE11D417ULL, 0x9CAC160319D00E09ULL, 0xB859C39BAF234C45ULL, 0x4FE8F8DAD8938F44ULL, 
            0x67CAA375EC56BB1FULL, 0xE3123819012EFF79ULL, 0xDF6FB94C00121F54ULL, 0x09E6491C53C9D9F5ULL, 
            0x6872E06E5FD24896ULL, 0x4355870A122EC26CULL, 0x263E927AA9E9AAB9ULL, 0xCB693FA711BB3264ULL, 
            0x4B5650E000F0CDF0ULL, 0x77148ECED1C2EBCDULL, 0x5CA41D63986327A8ULL, 0xBB2DB9DE555F1574ULL, 
            0xE9BC0656A981570CULL, 0x7D929885DBF6EBD5ULL, 0xBB376492DE17D43BULL, 0xC432C02F48EAE8C4ULL
        },
        {
            0x5F6472C22F5FDEEEULL, 0xB6E0D1608D38E7B6ULL, 0x06712D787F3AB68AULL, 0x1608BECDEBD2BB35ULL, 
            0xAE35F35B2857FE07ULL, 0xFAD238707FF75A8FULL, 0x0C117DCD7D962A07ULL, 0x42F90C67F7EF9499ULL, 
            0xC85345B749E9BACAULL, 0xE24B48524EBDDC80ULL, 0x8BB7FC1DA5635C99ULL, 0x566F3EE5F25B2E5CULL, 
            0x14443C18000F596FULL, 0xEC09AF9232BD8F26ULL, 0xE8BD4026FED703CCULL, 0x361F851C982E1DB4ULL, 
            0x12D88E3FC1A4EC65ULL, 0x161B26FA8BE0024EULL, 0x859005303B227828ULL, 0x6ACE6113D2D2C779ULL, 
            0xD3AEB828E62A94E3ULL, 0x01C1976D205CEC83ULL, 0x58C0385D4C981722ULL, 0xCC10B6B50CBBA499ULL, 
            0xD2D5F46053C00646ULL, 0x8AC86F8989B93F2CULL, 0xA62B8D438DB663F8ULL, 0x9689691539F0A5E6ULL, 
            0x3832479B084AEAD3ULL, 0xABC552546F476702ULL, 0xD97A778197465287ULL, 0xDF09CDE2B8ED4F9AULL
        },
        {
            0xA4BF5132CB8D5D2FULL, 0xD67473CBD100D9B7ULL, 0x809B9C21258F3672ULL, 0x254D3B7D603B228DULL, 
            0xDFFFED210DDA2C5BULL, 0xFC8BE19651ABDF18ULL, 0x0F1EC2CF2511D436ULL, 0x92075187B1C01711ULL, 
            0x228994E56C6D53BAULL, 0xF2522C1BAB1FB53CULL, 0x89AC6E93D4B5432FULL, 0x987103310599C50CULL, 
            0xEFA8BE24043365B9ULL, 0x18C7FCF0E1A505DFULL, 0x46B665EFB90C429AULL, 0x7560FAAC9106A054ULL, 
            0xEA64671FA53B12F9ULL, 0x59F5D1D2D274532BULL, 0xB2691C431407615BULL, 0xB7F35ACA39F5465AULL, 
            0x63F829AF023A78FAULL, 0x8E0668F085FB3744ULL, 0x93AC260A9DEA8A97ULL, 0x5748AF1AFA518731ULL, 
            0x3D4EA67FCEE1BE4FULL, 0x7C4EB2950CB745B6ULL, 0xAB8666C4AEE241DDULL, 0x5ECC349DCC356335ULL, 
            0x181DAB4BF7CC4879ULL, 0x7989F1ED6B947868ULL, 0xDD0FFA364C49FE97ULL, 0x4B244B176BE281E4ULL
        }
    },
    {
        {
            0x0A5ED2EEE731ADD4ULL, 0xD0C6DB4BF43BE010ULL, 0xB9706844C62B7469ULL, 0x778940F6B5F60E94ULL, 
            0x9EB9CFD81B97CCE0ULL, 0x6DD47A8DF2151551ULL, 0xB70A3E02EB63ABA9ULL, 0xA94D972C90D0622EULL, 
            0xA11B86FF495958D0ULL, 0xE22D3AE0972B62EFULL, 0x8FA536F0E2B53AF3ULL, 0xCF0C83D814EBBF3FULL, 
            0x3F3FD49B55845270ULL, 0x6544FFA5D17BB643ULL, 0x2C6148529766EAC9ULL, 0x9E90028A508F7D0DULL, 
            0x69EB7F382E67F06AULL, 0x24C5F2DC5D9F1B9BULL, 0x6A16D3FE5356EC32ULL, 0x467E9D908B7B7052ULL, 
            0x798DDA6B68849ECDULL, 0x13F9410F4A831EECULL, 0x24D48D8AD364BD58ULL, 0xC18A35575BCB1F51ULL, 
            0xBC27DF87CC9FB8D8ULL, 0x56763A7152213AA0ULL, 0x82D757E2F219A5B7ULL, 0x701CAC32981141D7ULL, 
            0x95931B6879643F68ULL, 0x8A10F7395E404B2EULL, 0x21E1B507C4645BDEULL, 0xB39D5C2D4DDC146BULL
        },
        {
            0xDB3A1A70F90DDE45ULL, 0xBE5A7E7BE6791E29ULL, 0x2D5833B31AD4E5A9ULL, 0x4300999A38B920FCULL, 
            0xC3F9D726624F9DF4ULL, 0x3DBEF0CC030CB0C6ULL, 0x6A2E9C30E5EC6484ULL, 0x487E3A9EFCE12B40ULL, 
            0xF29D3E61DAC1D06AULL, 0x41A8A1C617FB0518ULL, 0xB783DD338375320BULL, 0x360E6049AA8FE954ULL, 
            0x1EBA09A7174DF89CULL, 0x48F554B84D196B9DULL, 0x6332D1B16CF689FDULL, 0x2195645A54952349ULL, 
            0x4008E3223A69ED29ULL, 0x626F497D4275E9E7ULL, 0xBF491E63D8037FB9ULL, 0x18CA8454A9FDE3D0ULL, 
            0x2C6B21F1CCFACAF0ULL, 0x4293A38F8817ED2FULL, 0x5BA137630A438EE6ULL, 0x26F9E261C4789010ULL, 
            0x4D139C2746EC980FULL, 0xCC8ACB984DC0FD2CULL, 0xD144F455172901B0ULL, 0xA2EF5A6A0420CCA0ULL, 
            0xCB539663BD6CED84ULL, 0xB2E2E1D209933657ULL, 0xAF781988A3E5C229ULL, 0xE708DEB0B6801EDFULL
        },
        {
            0xEDDDC68A302E92BDULL, 0xABD0920DF4ECC50EULL, 0xBA9093385057867BULL, 0xB577E6245869F432ULL, 
            0x21F5F32F7B579362ULL, 0x1400C327AB463136ULL, 0x2B948EFB430BAE33ULL, 0xEF7746264B7D2FDDULL, 
            0xA8191940FF41EFDFULL, 0x328DE3D63210B6D9ULL, 0xFCDF0235CCAC90D6ULL, 0x86D38BFF4D38C87BULL, 
            0xBF29714491C1CC9EULL, 0x85221F1E4C7D96C9ULL, 0x07C9FF618D97B686ULL, 0x515C03E4279A4B3BULL, 
            0x70B0B99E429C301AULL, 0xA27126A5CA8E610BULL, 0x2262D6F99B41326CULL, 0x6EA7A81F8753E636ULL, 
            0x971E1DC8D2526214ULL, 0xCCE42B645A7F3A27ULL, 0x5986FEA0537E2D8CULL, 0x4D861FAA0E7454FEULL, 
            0xB546A7C85A1B3B4AULL, 0xF5CDA30D70830FE9ULL, 0x8A3BDBCC1FC168F8ULL, 0x20CF0ABD8F409394ULL, 
            0xD01C8BF4B02BB624ULL, 0x09445D5B9A94D044ULL, 0x5F453DE31A8A0242ULL, 0x7E0E37E4F78B7D8EULL
        },
        {
            0x735A5A437E65D3A0ULL, 0x62EF0F9C70D89BFCULL, 0x6023F27A3D1FFCAAULL, 0xDB5EFE39DDA07BBDULL, 
            0x0EB07FB38184167DULL, 0x1DAA21432C12ED90ULL, 0xAB5A0E1E6AB7FFECULL, 0xD5750CC00AB29DD9ULL, 
            0x8FD40C06C298D2E8ULL, 0x3D5FFCC4FCF42AD5ULL, 0x339AD7C6CBC84879ULL, 0x6A8FED65B14EA834ULL, 
            0x1CAD5AC83194616DULL, 0xCCC145AB8BBD1BE2ULL, 0x9B159A3B037027F5ULL, 0x288AC4B3C58DC0D4ULL, 
            0x122953EA3727328FULL, 0x919D6A8C3CD1F546ULL, 0xAE4E83725C90DB04ULL, 0x830CD7EA2D9C2FB6ULL, 
            0x2FB4C0AB32ED0010ULL, 0xA9A3837A0BF2F158ULL, 0x38B5C2F66E10845EULL, 0x23669A7A88EE8096ULL, 
            0x10DD087532730885ULL, 0x8D89C9BD4B9D34C7ULL, 0xD6A435C28BB22E70ULL, 0xED5C85B86AB782D7ULL, 
            0xFF00377FB1361602ULL, 0x8CF05DD9FE27A280ULL, 0xBF6616059A408289ULL, 0x4050DAEB4F0B6B91ULL
        },
        {
            0x7AC6BBD97642669BULL, 0x030687758C38B5ECULL, 0x85F68BBFB7AA797DULL, 0x48B645B636D83106ULL, 
            0xCCB7382ABFCD6FA3ULL, 0x66DFD4E41659019CULL, 0x0825A62FB6FA9D14ULL, 0xC6BBE96FBB027620ULL, 
            0xF6883F0430ACDE36ULL, 0xC51468DC156FAC79ULL, 0x6F0E89921989A242ULL, 0x81BC37C66C19BED0ULL, 
            0x2EA619CE8D15828BULL, 0x870106EC9D4BB12DULL, 0x4DEACE4CA593AB91ULL, 0x67EAFA5FA2DCE5DCULL, 
            0x6DA3CBBCD7DE7AEDULL, 0x078B68138AD11EF1ULL, 0xDB85F820F7D89D84ULL, 0x4897F7B83321E285ULL, 
            0x7A880CB571CD9D4DULL, 0x4749133B722F01C1ULL, 0x242C337E3439FE34ULL, 0x1A3CDBDAE115A5E1ULL, 
            0xF8E7F321650161BEULL, 0x9F967C02620A8607ULL, 0x912E9A629A607B3BULL, 0x5A047F390250C3AEULL, 
            0x3FB59E24C93AF58EULL, 0x920FDA52172F7D66ULL, 0x759F58FF32257F74ULL, 0x0C3807ECFDADE42AULL
        },
        {
            0x9F5A2FAA60A0ED8EULL, 0xA3C30506EBF1F216ULL, 0x4A4753234C41BF7BULL, 0x80A25938AD3C7CDEULL, 
            0x6A1379406C7F7E71ULL, 0x81186295C31A6CA9ULL, 0xC23AAA8CC89B90BEULL, 0x78ED24EDEF1B6971ULL, 
            0x136C2AD1E2647D49ULL, 0x7E2F6B4A3C942381ULL, 0x498A8BFE16340C73ULL, 0x644B2DE34960E2B8ULL, 
            0xB8BE6F3B1231C84FULL, 0x3E36BDF475FE767EULL, 0xC5130ED83BB8871AULL, 0x5B2DDFA2EFA0AD18ULL, 
            0x30E14209B34BCE54ULL, 0xDF9A0C09D47DD8A5ULL, 0x354884E35751F0C4ULL, 0x9E37B419585FF194ULL, 
            0x5199B7C8A12921D6ULL, 0xAD9FA6CABE28E532ULL, 0xE7244AA939470F56ULL, 0xB0B0CD27C51FCA50ULL, 
            0x22C8B809E4F75CEFULL, 0xD98AA48ADAFEB70CULL, 0x33FD7434A0E7CA7EULL, 0x874DEA45E8B4463FULL, 
            0x39A2BF3FF3E76418ULL, 0xFA475F89E6C426A3ULL, 0x089E5333DB48F772ULL, 0xE02BAE3C09951524ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseDConstants = {
    0xFF34FDF358266D74ULL,
    0x7E7D376CBF4453F7ULL,
    0x170044C3392CC952ULL,
    0xFF34FDF358266D74ULL,
    0x7E7D376CBF4453F7ULL,
    0x170044C3392CC952ULL,
    0x08C6E975259584FEULL,
    0x02B1ABFCE4A4E102ULL,
    0x7A,
    0xF0,
    0x39,
    0xC5,
    0x88,
    0xFA,
    0xD7,
    0xFB
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseESalts = {
    {
        {
            0xDC56E7631EABE7D5ULL, 0x915A3770E0F86CCCULL, 0x73263D8DDAD298CAULL, 0x282E93E490FE980DULL, 
            0x2CA9FF49FAC927E9ULL, 0x6468B2B92C0A7F5FULL, 0x9CB8D641C4BBFFB8ULL, 0x18AA2F315FCC536FULL, 
            0x9D6F0666A6259EA4ULL, 0x552755CD52930CCFULL, 0x7528842081444FCEULL, 0xF2A1EDEDE7D12DBCULL, 
            0x3C71C0AF31FD2942ULL, 0x2369F37A870A76F9ULL, 0x97D09209D4142105ULL, 0xB5D4EAE73295871CULL, 
            0x0399BDFC11F437B7ULL, 0x65E7B25977B1AF4BULL, 0x92BF283FDD679874ULL, 0x0939BD1745570B14ULL, 
            0x1762B179BD87BA49ULL, 0xDC358B4826DA5901ULL, 0xEAB3EC140689C84DULL, 0xDAE7EBC8BAB35536ULL, 
            0x52855FDBE936CEF0ULL, 0xE83E1CFED415765FULL, 0x3B839540EA7ADA29ULL, 0xB5666B55274E452FULL, 
            0x94DDC5E97C4092D7ULL, 0xF17C258D067C0EBEULL, 0xF5ABEE51E5E984BDULL, 0x211C2C1C981EA65BULL
        },
        {
            0xF317CDC972822939ULL, 0xCD9C9ED347E1A40BULL, 0x548DA907C334CCCBULL, 0x936B4BC120ABFD7CULL, 
            0x151533B4B44B2AE6ULL, 0x782B929B72A14443ULL, 0x20B471A477377ADCULL, 0x575C991B311EE638ULL, 
            0xC90EE4DDA641888DULL, 0xF7FE38F660427A6DULL, 0x6C3D546F615ED150ULL, 0x539C1B1B165FB1ACULL, 
            0xB647BE130C4004C0ULL, 0xCCA355490CF3F724ULL, 0xC062AE60C8B56473ULL, 0xB843B19009321A1EULL, 
            0xDAB5A9474F71A3A6ULL, 0x170B7C2CF82B2A44ULL, 0x00D8A3A68E11C146ULL, 0x28D998F4970268D9ULL, 
            0x1534DD576FC67AAEULL, 0x0BE625FF68C03164ULL, 0x736B28FB76609FD7ULL, 0x58CF6933AD5F0493ULL, 
            0xF5CED7B7DC66DB57ULL, 0x17D34905FA1C1A38ULL, 0xAE1ADCBDA26D6557ULL, 0x11065A6298A59177ULL, 
            0x4A8FBE2D4FDEF767ULL, 0xD3066DF233472FBEULL, 0x755E2A10AA8ADC85ULL, 0x49E1F0EE609EBC7EULL
        },
        {
            0xEAFC606FE010B504ULL, 0xC04A32571596FAD6ULL, 0xD65B0D52F9AB567AULL, 0x43322CE89A22775EULL, 
            0xA502B87D579387E4ULL, 0x9F3C07ECBDFB8C7CULL, 0xF8503BCCFC961AADULL, 0x384C830F3DC71B00ULL, 
            0xEFDD8E935260DB39ULL, 0xCD3DBE0C0B663122ULL, 0x06FB717244F69904ULL, 0x8FBB4E6F31BCBD7DULL, 
            0xBECBB67C41CA16D3ULL, 0xAD1B2F6D2CB31F38ULL, 0xD98E07A1B1B1BD5AULL, 0x09E5643023789C3AULL, 
            0x60C4FBBC5379D0BAULL, 0xDE779A29C6B21F2FULL, 0xADEF0C4989877457ULL, 0xC9B5E0E3910ECD27ULL, 
            0xA4CABDE3C233A971ULL, 0x0AF6CED9AEA85D58ULL, 0x110F1F1594119171ULL, 0xCCC2D2FFFBBD1888ULL, 
            0x3650F6DE85B163E1ULL, 0x05448FE5C321EF53ULL, 0x411389730AF727A3ULL, 0x1AC4D39DBAFBAC63ULL, 
            0xA5161A724ED967B4ULL, 0x29423BEEEFC8AF53ULL, 0xB77B89937F57291EULL, 0x11BE9F10C2E3847DULL
        },
        {
            0xF59D7A22138B966BULL, 0xDF6ED5E1D507EC23ULL, 0x434853B6B4C0C9ECULL, 0xB6D174B3E786F295ULL, 
            0xE6818F600B027E59ULL, 0xBC2AA0E6AA67E925ULL, 0x3122A9079A7E20FCULL, 0x63790E8B490461C9ULL, 
            0x67F027F2AB8CC910ULL, 0xB3490DAE9F774BD8ULL, 0x8DF97E64F7C033E8ULL, 0xC6F892713EDD68A0ULL, 
            0x44DEC4A35E3EE52AULL, 0x4615A9BEFF526012ULL, 0x92543261B106261FULL, 0x18C6CE1A62C024B3ULL, 
            0xBC35DAE81EE639F8ULL, 0xA95EE130D4C5F6A9ULL, 0x4DF9CAB2545CF473ULL, 0x10065C0A8426E0DEULL, 
            0x4CD7FABFFC9D188BULL, 0x07D05547EF4ADC17ULL, 0x28D39BE7DCC3D872ULL, 0xE58B1D9455BEA2D2ULL, 
            0x8FE8E29EFD679BE8ULL, 0x7B10B2FBAA9678B1ULL, 0x44C7CDC21A4F3101ULL, 0x5EED884B8F4AB46BULL, 
            0x63C7F47514075869ULL, 0x035FC07624375B3EULL, 0x9AEA390DE01C0CB1ULL, 0x6B77D667183AED34ULL
        },
        {
            0x1DCB3FB6FCACE48CULL, 0xC41B72243CDEC86DULL, 0x3BE2CA86B1D0BADCULL, 0x9B253916F651E263ULL, 
            0x8D26FD99FCA72234ULL, 0x0324E2F1FEE91825ULL, 0x603AA175A5B33E96ULL, 0x8198A428C0E29FF9ULL, 
            0xAD9AB05310AABE6AULL, 0xB8B90038904ACB51ULL, 0x327292DDDDFF4271ULL, 0x9F0A59DAD3F98F36ULL, 
            0xFF86875FA7FA4B76ULL, 0x7F32B23AB525F921ULL, 0x55622BD3F00050D2ULL, 0x05DA562C43F9D037ULL, 
            0xBCBE5DEA00FC69DBULL, 0xC74B223CF10BCA02ULL, 0xA1BD0E2BCDD449E2ULL, 0x0077ECECD6AEA8CEULL, 
            0xD5A7CD34D2CBEA3DULL, 0x14D1EA5DBC0219D4ULL, 0x5C1C12C62D4C7D17ULL, 0x0093C9C25F9F3E39ULL, 
            0x713D5B9B6249CE54ULL, 0x1FA1CB89B1ACC59AULL, 0x15D948AEB5453DF5ULL, 0x557EA5549307FFBBULL, 
            0xA72134B73E7A1E37ULL, 0x26C1141CB4660671ULL, 0xF9A55CF7D5FE8A3CULL, 0x96B7D1CEA7752E82ULL
        },
        {
            0x825C4857816762FDULL, 0xF9109575F638513EULL, 0xBE346FEE2D1E8573ULL, 0xA26C9C770484570AULL, 
            0xCF383F61DA8BA76BULL, 0xE21B596BAD513D0DULL, 0x2AC9558893FB143EULL, 0x9FA7B1B47846DEDFULL, 
            0xF129FAEF6443C8D1ULL, 0x34122ABC2BB2FDF8ULL, 0x652870F8C9A02D22ULL, 0xC9EEE7AA5EA66C2EULL, 
            0x197D704A7B7A51EBULL, 0xDB0100CE14AE77D6ULL, 0x8FA79BC05AB52460ULL, 0xD814F3411A47EFF1ULL, 
            0xBDBDE27B18A19D4CULL, 0x9C43F47510F59C2AULL, 0x3AE0C57A976C00C1ULL, 0x1DE1F68AD17B95DFULL, 
            0xEFCAE92EB92ADD9DULL, 0x8B2DDE314E5CF0D7ULL, 0xCB8C34B024A67557ULL, 0xDABEB9C63E9E741AULL, 
            0x0F31B658BAD540A6ULL, 0xC0A386551F4014FDULL, 0x1FE5566EEA691820ULL, 0xC258F4051273FD6DULL, 
            0x68D54DE6AA644A64ULL, 0x3C899F50762AD8DFULL, 0xBEB41D6186C899B3ULL, 0x265824F72ECC8AE0ULL
        }
    },
    {
        {
            0x221D19462637E5B5ULL, 0x47E387C15AF8BBFAULL, 0x10D55496D8987CD3ULL, 0x7F582A049E1A8E68ULL, 
            0x1DEEBCEE52BA1E20ULL, 0x360AD10E66985272ULL, 0xA3BD4215F88B0234ULL, 0xFA4AC29AD2B36CE7ULL, 
            0x33002B092E5B0A33ULL, 0x5BFE34E4C7B1C4FFULL, 0x150CBB51B7FCCEBCULL, 0xF062BA125E245A59ULL, 
            0xFF8F4F2D193B2D65ULL, 0x289A8BC8CC26B6DBULL, 0x33BED65AC4054C80ULL, 0x6D05575F30EDFD45ULL, 
            0x685009B2292F8B89ULL, 0x16DF609E38FB3AA0ULL, 0xB716EC2B75434FE4ULL, 0x8C83C77EEBC63C06ULL, 
            0x9AE15BDD0E472241ULL, 0x8F4ABA5FD338D943ULL, 0x3A19CD956EA06FA7ULL, 0x09C9C452021C2533ULL, 
            0xFB6D21C13DFC3212ULL, 0x43AE9A7F39258BACULL, 0x6210E74DF0717783ULL, 0x6D150E356B1BD794ULL, 
            0x8F89F6C0DEC17498ULL, 0x3272832D1CB50FF6ULL, 0x313F900DF1EF8407ULL, 0x24D9CAF915CA5987ULL
        },
        {
            0x36FC9B04C1A50402ULL, 0xD867E19796A9B42FULL, 0x5835228913EDCC3DULL, 0x1BA6FC5318602D92ULL, 
            0x84DCBE91FD9C7F19ULL, 0xB0874710BAAA4941ULL, 0x80743C0DE1CAA30CULL, 0xF930DE16D2397A4EULL, 
            0x39A534E22E1C6716ULL, 0x14DEE07C0AE6E891ULL, 0xAB215B7B40D149F8ULL, 0x4BC61E3C9D6C1F70ULL, 
            0xEBEBAB66A3682746ULL, 0xC86C9E33172438E0ULL, 0x6FB99EE8F317015BULL, 0x4633E7E3ADF686C5ULL, 
            0x92E9CC2DBBC58599ULL, 0x04B16292BF20E467ULL, 0x5CEF1A128802AA6EULL, 0x63D508F613FEEBCAULL, 
            0xF2E1B46D82DE67AFULL, 0xAB9F2BFC8EA8C85CULL, 0x9F8A5C03BC8E7382ULL, 0xB9E00667504CD213ULL, 
            0x2E0C855F101E05B1ULL, 0xB0D99B1CC93358D4ULL, 0xB0F8988B18C10749ULL, 0x51A604F38D4EDC93ULL, 
            0xBB0FDD336E97D506ULL, 0x13A6F9FCF6E1FD63ULL, 0xCA3256F62363A2BCULL, 0xFFE9ECFEB3B57AF0ULL
        },
        {
            0x30A933B42FFA799CULL, 0x7C5F413FB64555D6ULL, 0xEC9DCA46C05D4FACULL, 0xA1DBB678C9E672C3ULL, 
            0xBAB9E77A3B8799BDULL, 0x778399D8F87DEE86ULL, 0xFBB4E561E4D0E34FULL, 0xD454808156E6D1E1ULL, 
            0xD4DD92D2FA0D365EULL, 0xF25C8D42ADAA53B4ULL, 0x34BEF81AE20F0008ULL, 0xE19823597EA33440ULL, 
            0x50C763DD494964D1ULL, 0x13744F1F10425EBDULL, 0x4EB2CD849F75AFB5ULL, 0xBB029398FD4A0FBBULL, 
            0xDA6A770BE1AA83C4ULL, 0x4C494AD926630950ULL, 0xECF1EB07E71FE523ULL, 0x3703145B12038CC8ULL, 
            0x29AE6015E7BA4EFEULL, 0xCEFC83C261CF91A9ULL, 0x9136C1086CE6697AULL, 0x715DCDAB30B34797ULL, 
            0x86F1DFEBF12DA114ULL, 0x2DA48AB5600B2031ULL, 0xE144B04FD88D44A2ULL, 0x00C41A71F2CE1976ULL, 
            0x652E517FDE1EAB31ULL, 0x43A826A223E8F097ULL, 0x4A3AB6436C23CD2AULL, 0xC0AF6FCB8C1E6A6FULL
        },
        {
            0x64CEC1D4EE2A2F89ULL, 0xA63D9245362AA3AFULL, 0x6025C25507585710ULL, 0x8CC4272227BC8365ULL, 
            0xBAB4047DC2C8B5EBULL, 0x84AFDA5833963F21ULL, 0xDEDB05C783EB1340ULL, 0x307EA5AB68768240ULL, 
            0x3F451F6F356B1623ULL, 0x1A895BD8CE0A8BD3ULL, 0xCED34D74F67EF8ECULL, 0xA9A675127550EE90ULL, 
            0x9A4BBDEB1B32A1D7ULL, 0x6E9CD7D57DD19BBCULL, 0xF519EDBF6D7BFB17ULL, 0x1C2F3CAEBBD415ECULL, 
            0x1A8B01B9AF5D758EULL, 0xE0F42FBDB82E553AULL, 0x1AF591DCE1B44F6DULL, 0x6D32EB907F913971ULL, 
            0xFF6D709C0FF88CF4ULL, 0x7F7EC0172E76FE9AULL, 0x7A83561D1CF89247ULL, 0xA399DA0FE05982FAULL, 
            0x15B86B179CD42D95ULL, 0x5DC47DDB6A209D9CULL, 0xC46FDD5630B4BBEAULL, 0xD1BEF0BD011819A9ULL, 
            0xEB31ADED01C1E1ACULL, 0xD86E41C57CDAEA32ULL, 0x7932A8A879BC81FEULL, 0x53668913F0713C0CULL
        },
        {
            0xF7623672A3CF0820ULL, 0x23534BA45AF1A61AULL, 0x0C775A156D8CA366ULL, 0x57C008F8BB57102CULL, 
            0x569A7D559F00B77BULL, 0x8A23DEBF7A32B2D5ULL, 0xC468843338293F82ULL, 0xADCDD5B87E896FCBULL, 
            0x387D9AD83D4A1CF6ULL, 0x542DAAF10841F008ULL, 0x017067CAE129AD9CULL, 0x090710DDBE8EBE16ULL, 
            0xCA5E7F7B6B94A454ULL, 0x9C2181A47D4D7BAFULL, 0xF50C572BEAAB1C8CULL, 0x7195AF096F2C0E19ULL, 
            0xBC0BB41B9EAA1D67ULL, 0x341745BFAAFCD273ULL, 0xD88E413912C2C57BULL, 0x6A2E4CEE3D6EAAC5ULL, 
            0x871FE575DF6242C7ULL, 0xFF19B9A66F8CF9F1ULL, 0x4E94B9E971A194A8ULL, 0x0E8C1C6A4B76DBAAULL, 
            0x78E54CCFB3F6E63AULL, 0x1FA340FAD3B66E91ULL, 0xB4437A93230EB9CEULL, 0xE516E7CDC9F60133ULL, 
            0xBB49117B24C6EF94ULL, 0x78E1B1846CBEFBF3ULL, 0xE5B16FBD855935F0ULL, 0x0A4A252FF3EE66C2ULL
        },
        {
            0x59EFA3350430C58CULL, 0x52F8E482E2E5B889ULL, 0x1B96D2069C96A3E0ULL, 0xE75E5C08F2EC03C8ULL, 
            0x645CE827B50EEE3CULL, 0x71880FA77BB2CEC1ULL, 0xB02AFDB41C47EF57ULL, 0x0D6B480C20D2E7AEULL, 
            0x8845999CD7F40E88ULL, 0xA9966DCDBD406F05ULL, 0x9B4703CF620B7C25ULL, 0xCE7A3E7E2C51A402ULL, 
            0xEF0481E6D44E0633ULL, 0x62C7DD4263C8DD0AULL, 0xECF4FC033B7DDD2DULL, 0xA551752BF20EEA38ULL, 
            0x61A48BA333C7F567ULL, 0x4924C23F42AD2A37ULL, 0x0DE1B93DFA8CFD03ULL, 0xDF73F35216709E9BULL, 
            0xEDB76551576A0533ULL, 0x916B665D670F54FEULL, 0xA13B6E1F72F026EFULL, 0xC661FC2B13FBBF08ULL, 
            0xCA4A3B4D583FEDF2ULL, 0xBA47474DD29FAFB5ULL, 0x1BFB9F18E4C8DAD1ULL, 0x88183FA36057B6E3ULL, 
            0x3B9BA9415D447E46ULL, 0xC68CD6E5C2C0C412ULL, 0xD9804BA663E9BDABULL, 0x4B00425F7E47212CULL
        }
    },
    {
        {
            0xB1438B98E36E8721ULL, 0xB0C897DAAAB7F866ULL, 0x98132CA2E4619F95ULL, 0x2424D3DD803C96FFULL, 
            0x256A6792DFF4A0DBULL, 0x1F8E42D33C94849CULL, 0x68BA048FDF1FAF21ULL, 0xF2B027F3C5BECEE4ULL, 
            0x8F0B4D5705DE5357ULL, 0x5A640768B6FE4A3AULL, 0x175159D973FEF6A7ULL, 0x6F44EEFD6BB8E8F2ULL, 
            0xA3335FDC9FFF32FBULL, 0xAFD47B5FA8934D6EULL, 0xBA5A967ED8AB3824ULL, 0xA97A87B052AB24E2ULL, 
            0x0F7E06909457E7FBULL, 0xC7A4305E3465B4AEULL, 0x93E3E144EB46D297ULL, 0x1100F1F6F17749DBULL, 
            0x0DEB7A8AC769415CULL, 0x44670EE1110FAF59ULL, 0x7D0AC27CD96B1374ULL, 0x90FF11D091AAC33DULL, 
            0xD5FD9F81D7AF2074ULL, 0xDBAA2E79DAF6718CULL, 0x8661ADD5950576F7ULL, 0xAB359AFCC89DE160ULL, 
            0xDCCDE075375BEF55ULL, 0xC78DFC4BD4654F95ULL, 0x3842028DF16E8D90ULL, 0x4E497A02AF86E498ULL
        },
        {
            0xB01E19BBBDDE5E07ULL, 0x763087E732D0F4B2ULL, 0xCF2AF840EF99D310ULL, 0x306D7F7079F2D739ULL, 
            0x3F3625362368FBC3ULL, 0xAEC07AEA7185C416ULL, 0x879F37F901826741ULL, 0xC61AA8CEA70770FEULL, 
            0x47EE8E1884DA7D0EULL, 0x2E7C27EECB11F6CAULL, 0x9B0E1361E792B910ULL, 0x38CAD9C7FACC02CDULL, 
            0xF9B203029563F8D9ULL, 0x98C08ACEA8D892A4ULL, 0xA12B659F59863FEAULL, 0x3A160A5721C14798ULL, 
            0x9762BE9CD839DF79ULL, 0x336DEE2350A951F6ULL, 0xF976D3D2A5B6FEF6ULL, 0x2529DB6C2E510EA6ULL, 
            0xC552E3968795AC43ULL, 0xE54091FFB35002D0ULL, 0x5DCD6F39800BE015ULL, 0xDF74FCB961A9383EULL, 
            0x176ECA790BEC95F7ULL, 0xAE06B1E26F693968ULL, 0xA125B851EBBC76D6ULL, 0x6EC6FC53756367CEULL, 
            0xB45A4226448CD0CCULL, 0x19DFB30CF5305835ULL, 0x76544453EF1699DEULL, 0x9B6A70953A581C8EULL
        },
        {
            0xCAA3B72E323690A9ULL, 0xCCE0EE7FA21180A5ULL, 0xFEA48544C8513927ULL, 0x51EBB3E7B881F784ULL, 
            0x226ABBEE73520311ULL, 0xB4DE8C6E9DEADB17ULL, 0xA79672B92EF06092ULL, 0x81397C74FD7C31EBULL, 
            0xD5F55C06BE786DEAULL, 0x7732FC03ED40D187ULL, 0x265174D3423097D5ULL, 0x5D5869688E63A3C4ULL, 
            0xAFA49EFCCABECA01ULL, 0x435FB70694B5C125ULL, 0xE98013F80D6314D9ULL, 0xAAAC333FE6647738ULL, 
            0x4D57075F627727D4ULL, 0x3B693724591D5836ULL, 0x45B2B978D05A0FCAULL, 0xCCE7C86143D1E1FDULL, 
            0x7FB901A20D56E74AULL, 0x005F7AE3FE7CD468ULL, 0x993E03090A9B347FULL, 0xC328ADA01B78A469ULL, 
            0x574948EA029C932EULL, 0xA4174DABEB6700D7ULL, 0x3AE697C77309B102ULL, 0x919D4AE77309E6B9ULL, 
            0x0F5940BDDF14C592ULL, 0x551C26B5BE9A28E5ULL, 0x4317230B33292055ULL, 0xD55DEE03CAD67A89ULL
        },
        {
            0x6D6DE6C38FB53548ULL, 0x968A43B83C65BD68ULL, 0x938F18D1320CA37AULL, 0xEFFA1F8FF2FE0C65ULL, 
            0xFDF2F017A2653C2BULL, 0xCFBEB3C9BD3DED2EULL, 0x6E8124B77C476B12ULL, 0xDB670AC441A6B5FDULL, 
            0x040BF31ACA0CA18BULL, 0xD50CFB73E058A976ULL, 0x72C1670233B27822ULL, 0xFFD88E74D236645DULL, 
            0x9AC073958BB91F99ULL, 0xC24700E2BF33FAD9ULL, 0xD8F9518543D59062ULL, 0x146A3355988CFA28ULL, 
            0x94A5268BAE150B59ULL, 0xAF81B17EBD68E75CULL, 0xC44C99DD5DD5C405ULL, 0x673B2921C65F1247ULL, 
            0xA1404102F5ACD7AEULL, 0x49283ACBAEBAABA7ULL, 0x588E035A10C0686DULL, 0x225198EA5E6B855DULL, 
            0xA1B2A6A2821A83F0ULL, 0xA0D11440A9096D75ULL, 0x91423A71494F03B0ULL, 0x34CF57211DD70210ULL, 
            0x2EB6C3DB7CF69ED7ULL, 0x9E96CFC2E700BE10ULL, 0x845C2F0CDC712AFEULL, 0x0B9F10FD278E55C3ULL
        },
        {
            0xD7F8A83584233B15ULL, 0x136B64B7D02ED860ULL, 0x6136FA5C0FA679BAULL, 0xBE9B51C55F215D6EULL, 
            0x16FADECA27F1E235ULL, 0xF4ACC59B55080FEAULL, 0x2D1B5E47D14ADEBEULL, 0x8A00A62B317AE9B6ULL, 
            0xAB83558E0635170DULL, 0x810622797E876451ULL, 0x6EBC9F670A5952ADULL, 0x40255A4C0F2F420EULL, 
            0xC2F19EF3DF6473E7ULL, 0xE55C28F9114D63E3ULL, 0x1949E53D143D8DC7ULL, 0xA2AF0B97080D1DD0ULL, 
            0xDE47A62209F0A87AULL, 0x563BD74CBA4A34CBULL, 0xAE9ED9B9D90A8BD8ULL, 0xF1656C5597AD1ABBULL, 
            0xA3F7047C003D5494ULL, 0x49AE9D5517C05449ULL, 0x230E309913112E57ULL, 0xEE1B258E65FE82BBULL, 
            0x3C4F11E04EE58234ULL, 0x0F007663EAA74829ULL, 0x8E1510D9590023A9ULL, 0xF1D8469FED93B25DULL, 
            0x58621E643198011EULL, 0x8A762C11C47BE071ULL, 0x1173E51969983677ULL, 0xB791BBDF08B37D0AULL
        },
        {
            0x9623401CE5EC5F24ULL, 0xE713461F5DF09332ULL, 0xBA5087D4F706514AULL, 0x6E1B024AED958A9DULL, 
            0x42B8B5A9CFB0555BULL, 0xF521ED349C59515FULL, 0xCB3B408B486E57ACULL, 0x7BFDF64201AC081EULL, 
            0x47E29FB6344B8F3FULL, 0x64195F45691ACBB3ULL, 0x6C60FB5220474964ULL, 0xA0789A59840690E4ULL, 
            0xA947093796973CEDULL, 0x3816B294E1D377A4ULL, 0x78FDDE43B7C9AD9FULL, 0xD58F2DEFC4B3338EULL, 
            0x21D042A13623D66EULL, 0x1C5F513A9D78314DULL, 0x622FCE9097144778ULL, 0x63A90E06DD84E94EULL, 
            0x636CAE91C8191F38ULL, 0x0365F1C9F975E3B0ULL, 0x622065A85742A580ULL, 0x7BAD38640A3C844CULL, 
            0xEB82E2AC4FB7EB66ULL, 0x305E78D1BCD72275ULL, 0x8BC12042C06C3968ULL, 0x059746339E440AC7ULL, 
            0xA2EC68B94751FAC2ULL, 0x2FE46BE98C84FEB7ULL, 0xADD0DDBCB93E570EULL, 0x390A4C082E76F02EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseEConstants = {
    0xA1E89DDBCD0C5C43ULL,
    0xA072EE645B5CEAD2ULL,
    0xA5BB20BBA0C7A7ECULL,
    0xA1E89DDBCD0C5C43ULL,
    0xA072EE645B5CEAD2ULL,
    0xA5BB20BBA0C7A7ECULL,
    0x69C2191CD063923CULL,
    0xBA520757566E4175ULL,
    0xBF,
    0xC8,
    0x97,
    0x6E,
    0x02,
    0x02,
    0x0B,
    0x7B
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseFSalts = {
    {
        {
            0xDA415F47A399B44AULL, 0x53D45525DC5618AEULL, 0xF7C3E4FEB2CD6825ULL, 0x1B43EF6CF40BBDDEULL, 
            0xE845DCF22297AFC8ULL, 0x6D9868682C49CC63ULL, 0xA8CF156A38BCF2BFULL, 0xF754B76D50566772ULL, 
            0x5919D97C28195F2DULL, 0xCEEC995549093261ULL, 0x85730FEF500067BCULL, 0x81D0998A6EA0A0A0ULL, 
            0x6DBE707897945B45ULL, 0x08F291106A0212DDULL, 0x62AA0071FBA57865ULL, 0x01F92A0B5E62C005ULL, 
            0x5A561C8CFA1F1F90ULL, 0xBE676F327153598EULL, 0xCE53C326BFD4E024ULL, 0x6CC7C216328A98FDULL, 
            0x2C8EC024DEB28781ULL, 0x9AE4FA1F08130F9CULL, 0xFA0937E2817B3E9FULL, 0x5E134E2C1242BA3FULL, 
            0xE852820BAE36E0C9ULL, 0x03655FC899B13344ULL, 0xA3A369637003365EULL, 0x7C1D90338730FDA6ULL, 
            0x4F7E6A7F1E4E48A2ULL, 0x4A4EC539DE99EECBULL, 0xBC756E166A25FFF2ULL, 0x5AD6E2874EC306BCULL
        },
        {
            0x615EF2D730737F88ULL, 0xE2D0D966E866FEF5ULL, 0xB914B155CFB0A761ULL, 0x7BA73092957355E9ULL, 
            0x1E4AF6DB3929DCA6ULL, 0x754A3DB3D158F714ULL, 0x6A18C36278B8373BULL, 0x2EABF1F92E762805ULL, 
            0x5C94DF14ED81F901ULL, 0xCC51A6F8D1579506ULL, 0xEEE269E7FB3CC58DULL, 0xCAE41BCBF8DCBEA5ULL, 
            0xBC490DA5B334CCA9ULL, 0x1D075829412D9B4DULL, 0xF0A1B276EEF75936ULL, 0xAC041651EA44B051ULL, 
            0x0068E14430BD1AB2ULL, 0xAF0A444487F138E3ULL, 0xD5F30A32FECB0F2EULL, 0xA8726E51B2973366ULL, 
            0x0A4947C049A5C6BAULL, 0xF552F476B40665CAULL, 0xD53DDBA14C7A82D1ULL, 0x506511E41CD88E98ULL, 
            0x063DD9F776654EB1ULL, 0x53633251B580860EULL, 0x3F67A27124BA6BAAULL, 0xBE8897EEEC470697ULL, 
            0x9C4FBC31B2C6C85BULL, 0xAEB248934F398D04ULL, 0x13810731B52916BCULL, 0xE100839A660C2090ULL
        },
        {
            0x886CE2DD150F0917ULL, 0xE1CAA07AC07E099BULL, 0x35610EC44848DCAAULL, 0x2F4AFCC6D845B7B8ULL, 
            0x9C81BFC641DF9658ULL, 0xD34A7B954F881F84ULL, 0x1352D467BD4381B6ULL, 0x3E5E0726A4B623EEULL, 
            0xFAAD33EA8C4B8181ULL, 0xF98F5D4E911E944AULL, 0x5CD2CA404A8120CAULL, 0x81464627A0769897ULL, 
            0x882CE9C00FD1BF9AULL, 0x5A0E5017EBBC4454ULL, 0x88A824C66032BFE8ULL, 0xB4DC7C599C249E02ULL, 
            0x60560EE470A81B8FULL, 0x7D42CF7ADA5D1673ULL, 0x9B1DCF9CF3A440B6ULL, 0x1A5444A81A041E0BULL, 
            0x87945E583F1DDDF9ULL, 0x927B6227762A74F2ULL, 0xDBA50E759C5C5904ULL, 0x580785FCC1787107ULL, 
            0x69AB298770261BC5ULL, 0xF90E5B5B6732D9BDULL, 0xB98E75DB706EC427ULL, 0xEBEEAC97F6701947ULL, 
            0xEB0BAAB6F72B2FDEULL, 0xFB8032AAB51BBF6EULL, 0x5643F4135439BB1BULL, 0x4EB930AF2DA1AC25ULL
        },
        {
            0x20DA93A296F47787ULL, 0x463AAF5594774BF1ULL, 0x73402B8BFB417479ULL, 0x9A92461CFC48A714ULL, 
            0x35AA11D1543ACEFDULL, 0xD7FBF5173E59A1F8ULL, 0xB2422B4F4520028AULL, 0xD9373D65A977AEFDULL, 
            0x11953DFE6DBB3B20ULL, 0xB7192FAB150FDF18ULL, 0xBAF89540A0CA8715ULL, 0x4D75C3EE878FF266ULL, 
            0x2600BB0C889B5CABULL, 0xB522397FE41FCECFULL, 0x0533E267DB7CBBDFULL, 0x045BE1EF74625AB5ULL, 
            0x629A08DF1A1270C6ULL, 0x27630EB6C505A3A9ULL, 0xD8931D8AE07DB0EBULL, 0x2490E15F6CD3C7C7ULL, 
            0x2BAC4A0951C95F9BULL, 0xB0E2F2166E61C0F0ULL, 0xFE0E2B0DDED1207DULL, 0x6A30DA9104E3A698ULL, 
            0x386AF4A7DB941AD1ULL, 0x03199565948F0900ULL, 0xA4ACD1E0F174CEF0ULL, 0xE4EB33DF3C898855ULL, 
            0x6DF5BFE9D927B159ULL, 0xB1510DE261FAF1CDULL, 0xFF5627A3AF963866ULL, 0x404AFF766941CC06ULL
        },
        {
            0xCAE40303401731D8ULL, 0x00EAEC4F7C8058ABULL, 0x33CEB5EA8E67E9C6ULL, 0xC583E253E4FD724DULL, 
            0x0EFCE05DE8DE9279ULL, 0x16F228EB36D8F9B0ULL, 0xE984080DB94FD3C5ULL, 0x3E6CB25F8CB438DEULL, 
            0xF8CF58D39C8414B1ULL, 0xC529CDEF997E483CULL, 0x4408302C0BD79417ULL, 0x9F5C3C1643424746ULL, 
            0x7A12ED5D1B144E28ULL, 0xE38BCA4AD69D9DC6ULL, 0x41943DD561840588ULL, 0x3A39C4963C692D2DULL, 
            0xFFB915B7028050A1ULL, 0x9DD4735E739EE728ULL, 0x5AF8BCEBA5405AD0ULL, 0x0FF405C4027DDCADULL, 
            0x90BDA796F599CD80ULL, 0x6FFCA5A9A1246412ULL, 0x9BB6482F4C866103ULL, 0x3AABB93558F8B547ULL, 
            0x82CFEED16EA47037ULL, 0x4E8181B71F344C18ULL, 0xDA42D920BC03C77CULL, 0xAD49707A9840D4F3ULL, 
            0x55F3F42B3EE4B2A2ULL, 0xD06FCA1C1C166AE5ULL, 0x2FF52AB05EC1FB1BULL, 0x73EDF59329731645ULL
        },
        {
            0x6354234CE38AF443ULL, 0x7A17D2C6DB779EDBULL, 0xD39330C641FAA028ULL, 0x5BDE74644F257BD2ULL, 
            0x409E7958E8084091ULL, 0x7D6617BDEA143EDEULL, 0x270AE090FA55F311ULL, 0x571565B0B9EA2034ULL, 
            0x96127398C7155AA2ULL, 0xC7E46B9E2BA53B20ULL, 0xC4BA032644582818ULL, 0x2099CF188D87DD11ULL, 
            0x7D2B133B96DDAD15ULL, 0x048A74589219DC3BULL, 0x25D57AC67AD12DB8ULL, 0xC06BD538689E056EULL, 
            0x0FD8980559649444ULL, 0xF0C32040320C6BF6ULL, 0x44498A638DFD92EAULL, 0xE54D9E48792FB323ULL, 
            0x71AD26BCA1B5BFA8ULL, 0x83F6731CAAED985DULL, 0x6C188C8EBCD229B9ULL, 0xAD57EFB3418116A8ULL, 
            0x0BAD4E04A52C76A4ULL, 0x050D5AF8F5E33673ULL, 0xB217655737DAB026ULL, 0xF0A405441CA1B81EULL, 
            0x4B1B0896F565619CULL, 0xA800311BA992B68CULL, 0x2A44FFB27DE46577ULL, 0x95B91E14028CF56EULL
        }
    },
    {
        {
            0x494748B9D607D52EULL, 0x92E10754F54AA0F1ULL, 0x009FEBC3C5673B4DULL, 0x216D67D41A893BE2ULL, 
            0x9C21D495C2E2F81BULL, 0xAF732226864EDDACULL, 0xE147D39838A2D3CAULL, 0x64DBB9E240608353ULL, 
            0xA5DBCD432D1811A7ULL, 0x474957A08B733C48ULL, 0x59A090351D2B04E3ULL, 0x213D26489559DC00ULL, 
            0x4F02D15C87FCD460ULL, 0x9022163E1866EAA6ULL, 0x7E67CC4FC8B9D116ULL, 0x7DC05CC9C5ECBF6FULL, 
            0x69D6D45B8DA8D906ULL, 0x4B710BB69EF8AE7EULL, 0x5F27D5E9B07A5702ULL, 0x370533F3E0EEDD85ULL, 
            0x291D950A4B5D8138ULL, 0x2858FBD6AFCEF587ULL, 0x4273D49F67313EC4ULL, 0xF026D31C04EFF11FULL, 
            0x0142D81BE6D2E74EULL, 0x8D448517BAE1A129ULL, 0xA150E8B8EBC75047ULL, 0xAA28FEF80FE1AA3BULL, 
            0x27832DF024937475ULL, 0x110D7B2E82128FCBULL, 0x52B20D4AD3DDF698ULL, 0xFCD6A338B3C1FF44ULL
        },
        {
            0xD01C31E7315A437CULL, 0x164C2BA414B698FFULL, 0x94591395626AF0BFULL, 0x6279899D41A7A578ULL, 
            0x2C2D1F2BED28D249ULL, 0x5CBA3B0B8B212892ULL, 0x34250278EBB410B5ULL, 0xD6A69ECD08BAC800ULL, 
            0x9D499050298368F8ULL, 0x13BEAD3A4B740906ULL, 0x1667128264930FEFULL, 0x407ACBF7C3881739ULL, 
            0xC58D31EBEA96E8A6ULL, 0x627BEB2846F4B45DULL, 0x1B33A2DB914F0B3CULL, 0xD93114B8AB33A866ULL, 
            0xB1C00A3E4D740A81ULL, 0x906F53F29C51114AULL, 0x21184ED630541CDFULL, 0x32FC57E89898ADA4ULL, 
            0x81C976DE17811BF9ULL, 0xF0DF07B99EFEAB1FULL, 0xC2549C413773AC19ULL, 0x5B8C1CD28B01BF0DULL, 
            0x25BA1C35767FB1F1ULL, 0xDD639FD6F5C7A954ULL, 0x00DB2240AE009DF6ULL, 0xB170B6FD38CB9B86ULL, 
            0x7FEDCDAEAC3A4AE3ULL, 0x8153C33F7DF5C736ULL, 0x5857E4A40146F1CCULL, 0x46B66F74951A1C40ULL
        },
        {
            0xD522B436CAEC5718ULL, 0xAEDE1F40FBD509CAULL, 0xDF83248C9204BBC8ULL, 0xC2878FAAB9359C9AULL, 
            0x595AFDB6300350EDULL, 0xF69901C5DE83622DULL, 0xC2B84C01461DA622ULL, 0xCA73B90AC2E23D75ULL, 
            0x6AFE566B2D0EED00ULL, 0xD9D05049822C5B71ULL, 0xB1DC0C4015B53000ULL, 0x1B06DB92B4962353ULL, 
            0x972ED687B91DC376ULL, 0x07A4BC16A4C7BD74ULL, 0xF3CCE0FD713EE55EULL, 0xB33F3940BDDB0BCDULL, 
            0xA202BD748C16905DULL, 0x7E4E9FE87731DEFEULL, 0x228DB5302024CAA2ULL, 0x781BC79509A730B1ULL, 
            0xE5148034C65C36ADULL, 0xF45C4EB415B46185ULL, 0xEBA14F51354CC05AULL, 0xC4575C37DCE6FD4AULL, 
            0x74AFA1745A6BA565ULL, 0xDAC456357AA978DCULL, 0x4F0BDDD00E5EA011ULL, 0x389557665EB2CEB2ULL, 
            0x2DFCE00C338DDD07ULL, 0x691D8C05EFD8833FULL, 0x0E622AACADF7B5F1ULL, 0xF4DA5D9BF6D70552ULL
        },
        {
            0x963F9F1A41B8720CULL, 0x19706462DF2AC59DULL, 0xE75DB812CD90ECC4ULL, 0x07767F205520DE7DULL, 
            0x38BCEE3A19F715BBULL, 0x311A20696B7F4B3DULL, 0x497937662BC8F650ULL, 0xF0B46A5299A126AAULL, 
            0x8C01D9B381BD8948ULL, 0xD4A1442CE68E5D2EULL, 0x88DDE5476CA5E941ULL, 0x4C59B106B402308EULL, 
            0xAF07D46D0CCD1684ULL, 0x99B9400C3ADA2066ULL, 0x8942F7D6B9CC0821ULL, 0xFFAAD4D9686DEC78ULL, 
            0x15FADCBED2BAE218ULL, 0xE2B1C38A55A97308ULL, 0x7184FE3503A46736ULL, 0x360E146BCCE1266CULL, 
            0xBBE9260DC5652D2BULL, 0xA3F6F7A9FCDFC437ULL, 0x89F7AD3DAF0D8736ULL, 0xA108E39F7FF0C509ULL, 
            0x74A4977226A96C9FULL, 0xFABE6F909F669833ULL, 0x29B98A598DDFFDF1ULL, 0xCFC24DB71E2256D9ULL, 
            0x6C5BAE3CF4D0407DULL, 0x76FC76F517596A80ULL, 0x996A2B385D8ACE00ULL, 0x68F4FDE064C6DEA6ULL
        },
        {
            0xAA171DBFB37A8616ULL, 0x161D19370CD58020ULL, 0x4AC3576885F5FBBEULL, 0x27B079B01140FF1EULL, 
            0xB42A7715A4934A68ULL, 0xE4C1360F65B2EACDULL, 0x76A7331B08C54BFFULL, 0xA2DC6758BCE312E9ULL, 
            0x94335E7761057DF9ULL, 0x8EF3E7E1DEB5FF4AULL, 0xC4A87A01BCB25B34ULL, 0xC164C95A99011E5DULL, 
            0xC885C9F087352066ULL, 0x3B5F5E511402EED5ULL, 0x75A3C524EC64552FULL, 0xB54E43851D951538ULL, 
            0xB139D587127E0A8FULL, 0x33577A104AF07F39ULL, 0x6AC09F8FEEF55B55ULL, 0x55A246C2156CF9F7ULL, 
            0xB493A9B01B0AE238ULL, 0xFAAF120DF351CA71ULL, 0x00CDB9C31AAC1D58ULL, 0xC00055F9C3B0350CULL, 
            0xB21057A6B26916BCULL, 0x8839FC7A2F0384AAULL, 0x8D8827596E831CD2ULL, 0xD008955F94E87470ULL, 
            0xBA816636F3DF142FULL, 0x0C39BC4999A80FEFULL, 0xA75E23C42681D58FULL, 0x3F31AFFEACCE7416ULL
        },
        {
            0xBCA5C8CA38C54538ULL, 0xF97E163C4260E209ULL, 0x2940900885A5B51BULL, 0x6291DB64F6EC90FCULL, 
            0xA29A594AF1D94128ULL, 0x28EF5574D11CE216ULL, 0xB3C9D1AAD07510FDULL, 0xAAE376895038B17BULL, 
            0x45BF6FA4CDBEDD35ULL, 0x3132CA5A16A46882ULL, 0x69569C73344E0A27ULL, 0x66B72C17EF8C7B08ULL, 
            0x4C1DC283289D295EULL, 0x02DC2D48F3CBF5D9ULL, 0xDF59A5A20CFDC272ULL, 0x0A8856748CD57944ULL, 
            0x9779092339524535ULL, 0xB4E6A905303FC46DULL, 0xB055D3C22C48F247ULL, 0xE71940A2CA18BA33ULL, 
            0x4E8D924AEEE30103ULL, 0x64E34C817B9A606AULL, 0xA5B58CDC0EA57C06ULL, 0x63252E8A532E7A86ULL, 
            0x928B7D64C2695F17ULL, 0xE2784332544B8EDDULL, 0xD782F2D7DF4FBEE1ULL, 0x61ECF96C9AF72915ULL, 
            0x35FD769B9F4BDB95ULL, 0x1A748E53569BA272ULL, 0xAC6F0E8E06C44EDBULL, 0x30C84C61395CA07DULL
        }
    },
    {
        {
            0x90E61281D99F766EULL, 0xA42F5A2DC15B1E77ULL, 0xDED1829C606A14C3ULL, 0x3AA15B667DEE81ADULL, 
            0xFB81A78CEF54D710ULL, 0xA8C168F6184DA176ULL, 0x8797740319B6B469ULL, 0xB6CEA5D5D2628E11ULL, 
            0xA4342F6B17A62B84ULL, 0x36320B1685017BF1ULL, 0x839904C918AB7531ULL, 0x0A9851DC524358DAULL, 
            0xBFBD79555DDE1713ULL, 0xB6E6353982E83950ULL, 0x832A5CA811AFF561ULL, 0xE3A3F9D8456C3568ULL, 
            0x59AFABAE251B1D35ULL, 0xA7BD0C66D7F134E2ULL, 0x8993060D0E1A7CCDULL, 0xE5D0F141E7AD05C9ULL, 
            0xC503D5FC2D103FA4ULL, 0x44F7B4D710403A60ULL, 0xC3FFC3D12A761CAEULL, 0x82AC86ECCC4D08F8ULL, 
            0x64116F32AB531085ULL, 0x3DEECCD33055014CULL, 0x13810B488C0B57A6ULL, 0x218C9538E88E7D02ULL, 
            0x35CB0748A11EA06BULL, 0xAB8CAF6779B7EA00ULL, 0x006ABBF2B6630A1EULL, 0x8D91BC80EC6F1E9FULL
        },
        {
            0xB75532EE01CE96C0ULL, 0xF08ACE3C07A76558ULL, 0x2A08ADD2BB4ECCEDULL, 0x66A4C5CD644EF3F9ULL, 
            0x0461434625F4600BULL, 0xCA4FDFE624483B75ULL, 0x26FE51476774B6CFULL, 0x27868F8B642AC7DFULL, 
            0x2635D41F44F16E89ULL, 0x056E7D9673071BD7ULL, 0x646D6B03A70FF1C8ULL, 0x8C36A74B75661A74ULL, 
            0x57F184EB456332A1ULL, 0x9D8AC5E7697CF565ULL, 0xD5C747D7A1DEEE79ULL, 0x9D10A483F2CCB036ULL, 
            0xCF18D8A04E7A0CBDULL, 0x5EAF9BBB2844ECCCULL, 0xAD046AA17FE5F69EULL, 0x84BE909007EC042AULL, 
            0x453C463DF20EE15AULL, 0x27D976E4D93C3DC2ULL, 0x6D549EEC8D728BC6ULL, 0xC3D75BA35F3F1433ULL, 
            0xD4CDAF8CC9C8D429ULL, 0x870DE9509EF7296AULL, 0xC544DE29F1CE8D63ULL, 0x5C876EDDE5552979ULL, 
            0x2452B41864F79E8CULL, 0xD4C12011FA0861CFULL, 0xE02837DFD6750382ULL, 0x804F09825CC91B91ULL
        },
        {
            0x17551843B1534EABULL, 0x37CE683F1A369393ULL, 0x1A92F1ED3A0AB92FULL, 0x321794B8E98D5866ULL, 
            0xE20F00547BF62C82ULL, 0x629DB205C8A7C058ULL, 0x366C3F435243D384ULL, 0xD7117C5F979D5E35ULL, 
            0x6296E81C965DABB3ULL, 0x0E2A7CC46EE9DAC7ULL, 0xD493A5A671D5B354ULL, 0x1D309E55183F795FULL, 
            0xEB38AF24CF3441DAULL, 0x18D527BE651EEBEDULL, 0xAB2F0B45A48969F0ULL, 0x15026E9551E0E590ULL, 
            0xB0E9D6A44F2D5A18ULL, 0x96367415BF661A84ULL, 0xE735296798DF21B6ULL, 0x254C0EE05768B728ULL, 
            0x93E6C23431267714ULL, 0x5305994152E7C454ULL, 0xC694A250F5547519ULL, 0xBB70F9A007C8B1CFULL, 
            0x4D757330D03E05EDULL, 0xB9CFE690A947A578ULL, 0x7E75CF9D9E2C15B1ULL, 0xF76DDE60279CD5A3ULL, 
            0x486EEC0B6293CF5CULL, 0xFF72FFA91711C3CEULL, 0xE458333237C58A41ULL, 0xB6A37EC7FC8803EBULL
        },
        {
            0xE4D35090F51B2500ULL, 0x96603828B7A4AACAULL, 0x681818B17ACD1849ULL, 0x71E34E9F798D1DC2ULL, 
            0xE44404EA8AE7FF26ULL, 0xB72B364604B08342ULL, 0x0022C00F20CBC02BULL, 0xEAB62AA86F3B34DEULL, 
            0x8868D21B1EA77452ULL, 0xA03029F41829F8AEULL, 0x732700D7021B9E04ULL, 0xD0C73EA97215FA6AULL, 
            0xA8E9FB31A3EA109CULL, 0x0B579F090F6890CAULL, 0x97055A71B57BBE11ULL, 0xF3F0BAC9149B7591ULL, 
            0x6866EC173E8948CFULL, 0x2AC0EE3076058DB8ULL, 0x14FA3347DE2E9C62ULL, 0x4018B05A39C5FA76ULL, 
            0x704292D67BA529E2ULL, 0xA5F62DE12F1BD4A7ULL, 0x3B91FB4C73975E30ULL, 0xAC58E9D91BB70A04ULL, 
            0x8BD5BB3FB4D94FDFULL, 0xA068BFF2E5C43B1EULL, 0x6FD7C7277C0BF22EULL, 0x58296C8F4B67C983ULL, 
            0x7C82227C3F8FBF6AULL, 0xFAFEE0BB40C2F784ULL, 0x9274F2EB1FCBABA3ULL, 0x055046CD47D00E0DULL
        },
        {
            0x527CBDCA8A301C41ULL, 0xF871A58A549D4C98ULL, 0xD276F66DA09D62FEULL, 0xEEF31C0D489775B1ULL, 
            0x866EC3EEFD8DA5B5ULL, 0x1DFFDA8E852149B3ULL, 0x6E160FFDEA81E66EULL, 0x422E3B495651589EULL, 
            0x3FF43C6CB717C796ULL, 0xEF562198057E26B5ULL, 0x1CDE0E9338043A5AULL, 0xF8B47122D1152851ULL, 
            0xA02E2C8C53E7F909ULL, 0xE9DB42D2641D6863ULL, 0x10E26C3CEDAAE0C4ULL, 0x0B4660B955AA356AULL, 
            0x0A1FBC1DD70C33C1ULL, 0x9EBD7141298DE734ULL, 0xC7A73DCCFEDEF6C1ULL, 0xD00765B6ABBF1256ULL, 
            0x14D1A6AAFAFC1EE1ULL, 0xA9892F3D1C052675ULL, 0xE82DCD2AA9886846ULL, 0x87D4A6C6DA44E40CULL, 
            0xDBD41EC6ACB59B3CULL, 0x618BBA8458973C75ULL, 0x8C035EB76A87678FULL, 0xA711A70391B9FF44ULL, 
            0x8E0E24398FAE9119ULL, 0x7B6E1912AA8AEB26ULL, 0xCB2AC39692947F17ULL, 0xB5A4480B2AA7A3C3ULL
        },
        {
            0xEA26069B2F908518ULL, 0x5AD626F9E87DB0D2ULL, 0x24D30570FDD3C091ULL, 0x1541E37C34C61B55ULL, 
            0xB1624BB29C1491DFULL, 0xE75DCEF0C1D7E0D6ULL, 0xC88389A881F919F1ULL, 0xFE91ED846A5B44C0ULL, 
            0x469F67969637E972ULL, 0x2D5A0DAD96FA7B18ULL, 0xA4BBDE083F641AF6ULL, 0x906309971CA095C2ULL, 
            0x718961CE552A56BEULL, 0x90A7871B81403FDDULL, 0xB3EBDA9FB66AF483ULL, 0x3B3DBA084295C6E2ULL, 
            0xBE298824C0711B5EULL, 0xB8F3862F4CCF434BULL, 0x0A0E2EDDC97CA28AULL, 0xA22C753682C84D8DULL, 
            0x1CACCD978B8DD486ULL, 0xC2C38F48DA251C2DULL, 0x9D57212C46FF1248ULL, 0xBB9397165CEB5DE4ULL, 
            0x8D72A04D8156C305ULL, 0x2256A8E71B8474D4ULL, 0x9DEC819BA5E96DC4ULL, 0x8DB1400C218C4AB2ULL, 
            0x1793F4344FD5DD74ULL, 0xFC00305FE01D848CULL, 0x8B80B65157DDEA02ULL, 0xC512FC9AE22662EAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseFConstants = {
    0x163D8844579C47DCULL,
    0xC99F590BC3678481ULL,
    0x62FD437FA8021056ULL,
    0x163D8844579C47DCULL,
    0xC99F590BC3678481ULL,
    0x62FD437FA8021056ULL,
    0xCCA65E046428B549ULL,
    0xC1961DE9B3153397ULL,
    0xBE,
    0xD8,
    0x74,
    0x22,
    0xC2,
    0xB5,
    0x12,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseGSalts = {
    {
        {
            0x5423B2AADA29EFFEULL, 0x758360F06EB68D7AULL, 0xA5F3A00D15ED250AULL, 0xE2CC12A7BF812FB7ULL, 
            0x318FA406AE6E2E89ULL, 0x09BD9C13AE5224B0ULL, 0xCBD9C8C82A9F9D13ULL, 0x38987DEDDB1ABF61ULL, 
            0x1150F4CB07C0F0B4ULL, 0xCCFDBAE4C6F2AD1FULL, 0xB62DCE2E24747A51ULL, 0x958BE1CC87031CEFULL, 
            0x199B00AB95553398ULL, 0x1EDBD218B7B0F591ULL, 0xBA79F678F3B6D1B3ULL, 0xCCF08012B754601EULL, 
            0xAA596E513FB11B02ULL, 0x542806C721903D32ULL, 0x8631DC619238BC4DULL, 0xE8E00DFD927817FAULL, 
            0x7F0A67DD3E6AA8DEULL, 0x4AA1F9D4E3BC4EE4ULL, 0x8421986DD09A5115ULL, 0xC861FAAA69D785B8ULL, 
            0x3BBB089355912CB5ULL, 0xBF64681ED915570DULL, 0xA5994FE228023EA8ULL, 0x5A5145CA7A23E2CBULL, 
            0x9B480034C62A64FCULL, 0x6E9EBA5140CAD93DULL, 0xC8C762D6ACF012A9ULL, 0x754638869DEBB8CFULL
        },
        {
            0xA1221DBC2150B120ULL, 0x1085EA3B82273430ULL, 0x17CC35BB8BF6C14FULL, 0x279CF0FCCBAEE560ULL, 
            0x4FD70D408B59321CULL, 0xA92112F825A00FD6ULL, 0x1F0CAB7946D96F4AULL, 0x7F7E4EBCEF003CEBULL, 
            0xC12FC508DBB5125CULL, 0x3BAA934B18F0889AULL, 0xB14258D77BBF217EULL, 0x4EF937D8FD5C3380ULL, 
            0xE6EF7F8E6144D458ULL, 0x326B6F51D3709B47ULL, 0x5E3DF134DE357FB4ULL, 0xC5661FD71DEC1B0CULL, 
            0x92BDEE3D41BA52E6ULL, 0x72E9668EB7E291F3ULL, 0xDFE08611309EA851ULL, 0xFC19630F5CB9F31BULL, 
            0x9D54322940163E7DULL, 0xB6BACF0BE4D9A86EULL, 0xA6851B5D47A4672AULL, 0x0A0F7E555C46A0ACULL, 
            0x0A0FD40AF15ECA7BULL, 0x65CE3180AD775BC8ULL, 0x71D3981BAFA6312CULL, 0xCB68BF676B31B030ULL, 
            0x60F293A2E673E604ULL, 0x6323096CBD70E499ULL, 0x65B072A1F3BADE5AULL, 0x4BD51C5DEC99EA22ULL
        },
        {
            0xAA423AD600B72385ULL, 0x808420FB193B8784ULL, 0xAFE25614A8E23A5BULL, 0x850991EFDAC902A9ULL, 
            0x5023A6A805BEFC49ULL, 0x53CED6D6C1B54D9BULL, 0x9DF4B8E2B51C1414ULL, 0x9088E34732A29792ULL, 
            0x2051D173716365FDULL, 0xD7365D40F2D99C06ULL, 0xD50D0BCE4CB03DBEULL, 0xD164F7F009918AF9ULL, 
            0xBE366686402B2B8AULL, 0x35A2E17934B5E7F3ULL, 0x11231813D25ECEBDULL, 0xFF18EBCA13A533C9ULL, 
            0x27CD8B27A5AC8511ULL, 0xC8E1E9083071E3F1ULL, 0x3C466FC9FC70312CULL, 0x7997DAD64FFCB1FCULL, 
            0x90FC23A5BE2D5A0BULL, 0xDF76E4E7828E6625ULL, 0x487DDDFE3F78F468ULL, 0x30931B0B616C3C1AULL, 
            0xC1A7F10E173B4F3CULL, 0xCBA977C79C772969ULL, 0xE580E1F9D8B9760FULL, 0xA074EC93F56A9619ULL, 
            0xA21DD4FB66FCF009ULL, 0x9420A0CDDA79E432ULL, 0x4CE0947E59AC842CULL, 0xCE5AC04A5D29B9B8ULL
        },
        {
            0x429988FF41CB1AA3ULL, 0x9401465B2865A962ULL, 0xC4E49D0A1BCD4C28ULL, 0x6398BE2954E06621ULL, 
            0x6875707E813A065FULL, 0x61138B4986139A67ULL, 0xF765603A5F837E18ULL, 0x2BD63560F5A43BCEULL, 
            0x16FA41EE599264D4ULL, 0x8BE636FE42495C24ULL, 0x51C3A547506D5C84ULL, 0x553C6A85670FCA6EULL, 
            0xA12244A8CC8034BAULL, 0x3756A8464C7ABE88ULL, 0xA48983CC42772E08ULL, 0xA50F4BCE2DCDB903ULL, 
            0xB2D7F31E79EEB784ULL, 0xD1EAE27109873B01ULL, 0x78AC9D7FF3FE85FEULL, 0x559B6E556B780E3EULL, 
            0xF7D4BDB95A255DD5ULL, 0xBDA09E9B11DD2277ULL, 0x897562AC26BBA66CULL, 0xE5C221F87A6E56A3ULL, 
            0x1A20EDDBE50D7B76ULL, 0xCA2737D7FDF33A51ULL, 0xB6AC7515E01E87EFULL, 0x19A6454A5EE07938ULL, 
            0xF5EF4C334329D758ULL, 0xB6594D1DBCD2859AULL, 0x8A0A6E4E50E2129FULL, 0x648CE474CD7A7544ULL
        },
        {
            0x8D3D5B37578491E8ULL, 0xF00561CD80873A6FULL, 0x501F913026BE2CFAULL, 0x50E11A0768CF4CA6ULL, 
            0xF7BFEB42593061DAULL, 0xFC54A1146FE77E66ULL, 0x126F37F93CFE5EFFULL, 0x21CD010C292A3271ULL, 
            0x405D2988D3B1D86BULL, 0x7090899FA4157E3CULL, 0x7CA3F4D87C97B180ULL, 0x76BFD4224D794C61ULL, 
            0x2CCDC4B56B4F1911ULL, 0x236F4949D4746075ULL, 0x3746F37D82832704ULL, 0xA58CE96F849FCB32ULL, 
            0xF64553D693768A17ULL, 0xA4FE590EDC89BBADULL, 0xB41B5058858D3E77ULL, 0x4EE197399BC464E0ULL, 
            0xDBDEC98856ECB38DULL, 0xCEEB235F845F2041ULL, 0xE02DB9FBE3347918ULL, 0x874DE7BB0FF1DCF2ULL, 
            0xBC4740E73EE28BA9ULL, 0x0F26671368F48024ULL, 0x3135DFE47DFDA04EULL, 0x337724027B4E6155ULL, 
            0x38FFC6FB9E4D11C2ULL, 0x6532C4DF674B2EF6ULL, 0xF32BB03DE5B4AAA7ULL, 0xD6CC5534F0240530ULL
        },
        {
            0xCDE42A7C708EC1C5ULL, 0x9C266FF1D57D7EE8ULL, 0x0FEF7F06332A9FD3ULL, 0x00915B8BFE0A83EAULL, 
            0x9710B40D09D77B1DULL, 0x05CC47A4976A91E6ULL, 0xF860BC1ABDBEBD0AULL, 0x5D68D8A048BAC978ULL, 
            0x46EA92DAEF0D2CD8ULL, 0x374AA35AA90554BBULL, 0x0EAD553F4C2A0E35ULL, 0x1124365832D2DE63ULL, 
            0xC61CBB3E67A20152ULL, 0x72A4D72E41F766A4ULL, 0xE9D47A99C0100B40ULL, 0x270BABA79361F17BULL, 
            0x05C9ED212F1AFD99ULL, 0xCC9E645BF105548BULL, 0xE1777835036D37BEULL, 0x6A3274488CEDF967ULL, 
            0x7A69D57E1073AA52ULL, 0xADAF1984A2BC7114ULL, 0x0B74101415E96102ULL, 0x60508FAEFE034CA8ULL, 
            0xC0D15A4F85EC1761ULL, 0x2A655CDEE163D8E1ULL, 0xEF2DCA8971115179ULL, 0xFDC1AAA44157380FULL, 
            0xA0CC26C3458C37D1ULL, 0x799C9EB6339B0D7DULL, 0x6786D05E17FB6417ULL, 0xA1541DC2A2434E0BULL
        }
    },
    {
        {
            0xE3EE8BDFA9F59F78ULL, 0x72CD15CB7CB71BA5ULL, 0x03ED06202347B780ULL, 0xCB4A745A132AF2F7ULL, 
            0xDC840C3AF733E306ULL, 0xB8944E5D30156BB4ULL, 0xF7C20CF1259BC958ULL, 0xA174375C58CF2DD5ULL, 
            0x3B85E999A15EF415ULL, 0x6903F059B3BFC883ULL, 0x30D2214440082E94ULL, 0x7934C357F59E2AE1ULL, 
            0xE630AC9C59BCF2A2ULL, 0xEFACE94C663C7D50ULL, 0xAFC8AA5F4A9138FAULL, 0xAB055A6263BE17FCULL, 
            0x6F4BD51006350E96ULL, 0x8F0113CA5A8C24EEULL, 0x8CB0CF9CF101AD39ULL, 0x36DDDC03C2EB96B3ULL, 
            0x1580EC162AF16B8CULL, 0x2B1FF2F748151D10ULL, 0x8ECD172485B13F19ULL, 0x4C4DC26D1F569696ULL, 
            0x44EF87039DB1C099ULL, 0xA8EC41033F245059ULL, 0x8952ECDA620AA5ABULL, 0xA8EC98C479F1F78BULL, 
            0x9FFBC3EC6173FA36ULL, 0x7E1A283DE351FC03ULL, 0x8396C1D24377FA21ULL, 0xBDFFC9F6E1757A60ULL
        },
        {
            0x5BE01569CCCE6436ULL, 0x2F89478B86A43DF5ULL, 0xF95C6C2A7431653AULL, 0xC4E1F487D7ADA293ULL, 
            0x3FA37B9F820CA218ULL, 0x986B7B2DD5936736ULL, 0x048908ADBD64512FULL, 0x8A21C71333E47D6AULL, 
            0xCAFB908701E10EC9ULL, 0x52F65D6B88B9D632ULL, 0x125F7F7FCE20A9BAULL, 0x542A506640241E01ULL, 
            0x572286BAEA0A3E78ULL, 0x6F08479CAF381811ULL, 0xF99354484B1CC7ECULL, 0xB0660613ED52CC66ULL, 
            0xA7A38A95081832A2ULL, 0x5E39221F3DBE33D3ULL, 0xA9E654C4BECC86E0ULL, 0x4BB84D95DECB586BULL, 
            0xAF861CAB443562DCULL, 0xA82FBC7F6E7EB547ULL, 0x9C8867F334AA9C12ULL, 0x79DBFF1C949EE61CULL, 
            0x379A169D7A7E520EULL, 0xD884E3DE332020A2ULL, 0x31B6D8BC91BF3CE9ULL, 0xB8969253412EDBDEULL, 
            0x1D77E8F8B5E16874ULL, 0x8F51CAC2A98D045FULL, 0x83292E5E4FB2A986ULL, 0x2572225DE364C387ULL
        },
        {
            0x8F8F91FFB708419BULL, 0x8C9889D4FB73532FULL, 0xD44872D60D2AA646ULL, 0x27772099B22968AEULL, 
            0xAF3EC4E196D09E29ULL, 0xEE06DB003B708137ULL, 0x79213CB6734FF129ULL, 0xCE7FC76212708A8BULL, 
            0x8AF9D9B8B87B95F4ULL, 0x4E24BA7BC7889646ULL, 0x608DB7314925D266ULL, 0xC370D2AEBAA84E89ULL, 
            0x5BCD299810280664ULL, 0xFA233D10BF1D3672ULL, 0xA4132828CD9F77D7ULL, 0xB37FD98EF3C136DCULL, 
            0x740B7619D236D5A1ULL, 0x378732013F52AFBDULL, 0xEEC29809F2D9D906ULL, 0xA844F8DE683B377EULL, 
            0xA9A8B9A26CBEA575ULL, 0xB31DFFEA2EFD70BCULL, 0x664A08B1E4781ECBULL, 0x11288B4C265191CDULL, 
            0x1FE8EFC68193F710ULL, 0x634D52F9A31363C9ULL, 0x20602675BBCF1C68ULL, 0xBAAE45DED974F282ULL, 
            0xCD4B2DCB42E643BDULL, 0xAF2BF31010BB1266ULL, 0x77A3CB7FD35853ECULL, 0x955EDD52239AA10EULL
        },
        {
            0x86326E37777F92DCULL, 0xCC109A06688CF02AULL, 0xF112421DD10DAD49ULL, 0xE623A7FA763203CAULL, 
            0xACDEED9C92D7E03FULL, 0x2AF1CB71D5B6FB1DULL, 0x7187B11ACA4BA4BAULL, 0x03A1081D99A57016ULL, 
            0x5A42809E368F248BULL, 0x4B8D70572C537190ULL, 0x1D2187A63938250EULL, 0x76E398B4DBA4224DULL, 
            0x916B37EEE0340109ULL, 0xEE5C3811958FCC5EULL, 0x84693909877D724EULL, 0xB21C1B1C543B2010ULL, 
            0x913121406580950CULL, 0x6A89C80F5514D286ULL, 0xB56A9EE6AD1B9164ULL, 0xDDD13479E53B5708ULL, 
            0x598BA760B7A78FF6ULL, 0x66682E6F845B6974ULL, 0x5ADDFD6829A44F60ULL, 0x93C5F3E5C230CA76ULL, 
            0x4A39849BAB671B3AULL, 0xF8EBEC02C213F366ULL, 0x8218E61B456E98D4ULL, 0x2B040082DB6C2882ULL, 
            0xC7B11B80FD818621ULL, 0x4F762FA5C13BD863ULL, 0x17E4471C93046013ULL, 0xBAAC226130791691ULL
        },
        {
            0xDB0CD0C1CAB02163ULL, 0x72E7EABF1258D98EULL, 0x93FD4A48B54AE790ULL, 0x51D02ADAC9FDC98AULL, 
            0xFAA427F4BA6FDAD7ULL, 0x35C59CBCC3FB8133ULL, 0x8D5C3493E93F4755ULL, 0x5D11C576A0F9B104ULL, 
            0x94A1467037EBC71EULL, 0x50D9C64C3E6D5AA9ULL, 0xDB4687A3C662EFBAULL, 0xED1492026691DA4FULL, 
            0xA02CBAA28126C508ULL, 0x5063D72F89A8BBA9ULL, 0xEA121383B5DEEA3FULL, 0x9B55F1816BDFC7B8ULL, 
            0xEC7C4413D8BA5D0DULL, 0x84CC1EA31F2F4E3FULL, 0xBF32F054C24D297EULL, 0x26307E1E0B0AE03CULL, 
            0x11F88810949A9C9EULL, 0x98020096F9A57D2CULL, 0xECD5C6E1618C720CULL, 0x39D02DBF034509DAULL, 
            0x7CEF3C838EE6D80BULL, 0xFDEFD504D7F0A008ULL, 0xC4BED7BBC50A1F2CULL, 0x0B6936FDFC736FA1ULL, 
            0xF2CB8FB0FF04B855ULL, 0x2CBFB314EABB42AAULL, 0x48402C5342169B3CULL, 0xC63C0E2C3F9EC630ULL
        },
        {
            0xD79C87F7184B236FULL, 0xF5A9119356614906ULL, 0xADD370D9CF78CB99ULL, 0x8E793574E5AD6DE9ULL, 
            0x5ED921C5CB447C2CULL, 0x477D72F70CEB814AULL, 0x16AF2CBD406E7FCCULL, 0x8648D8D3B52A187BULL, 
            0xEB60BA139672B599ULL, 0x20A61CA59AF61A3AULL, 0xF4D573B9C6751CF1ULL, 0x169253935670592FULL, 
            0x7344E7B671B0426AULL, 0x886C54327C21F02FULL, 0x33A2463FDFA99C8FULL, 0x042A9D66E878A820ULL, 
            0xDB6ED2A0EBE515BCULL, 0x3723E0C3B66FB0EEULL, 0xF175965374E9536AULL, 0xCD135726C8E2445AULL, 
            0xF88541F083432F36ULL, 0x289A7D2EBC3AC99EULL, 0xE54E6F6C09B5337DULL, 0x71C6E213258DB3B4ULL, 
            0x1B30845E958B69EBULL, 0x26E71EA1611F37D8ULL, 0x6C6DF26D629ED19FULL, 0x16D4A33FE6646EA2ULL, 
            0x4C75DA0DA1D75C03ULL, 0xF180A0700FABB1C9ULL, 0x3E89A62B5952CE26ULL, 0x5DF3C4DBE872E0D7ULL
        }
    },
    {
        {
            0x47D39BDC5CD84D0DULL, 0x8091A31B7A3F0C85ULL, 0x765743143DD0326BULL, 0xE57BBFF3939336A5ULL, 
            0x0DC7A3BB863B3646ULL, 0x42831CC656B7BC04ULL, 0x87DD522A9DC94DFFULL, 0xF41F37D66C570952ULL, 
            0xD099146BB11B890DULL, 0x5ED616BE780E43DEULL, 0xB65B29F65D724332ULL, 0x9311625B886FACD8ULL, 
            0xBC41FDA009F68411ULL, 0x34C1D83B78EE950CULL, 0xC4EAD5BE28D08AD4ULL, 0xE83237F0A46ECFE7ULL, 
            0x25EE9668609EE2DEULL, 0xDC2EC4B94D002965ULL, 0x9BA404E06E905E14ULL, 0xE1DF7FBF8287F954ULL, 
            0x5C9BE9F0D161F257ULL, 0xAB397AA16F77CB53ULL, 0x13608EDECFF16550ULL, 0xDBA85263D8594C3BULL, 
            0x7A02671DEC5B729CULL, 0x8D5A1D69B8E366DDULL, 0x0178CC72C8CEE2ABULL, 0xFB215BE97190B8A8ULL, 
            0x934EF2DFEEE6DB35ULL, 0x16EB82C452BFD81DULL, 0xC40C01E5637C1EAEULL, 0x6A785D1DD3362488ULL
        },
        {
            0x48DD24882EA9D6FCULL, 0x1F90DD828266F7F1ULL, 0x4D2A4BCC109F4D66ULL, 0xCD604BC4B095B85CULL, 
            0xC95EF17C32CE60CFULL, 0x736CB461988A5D21ULL, 0x15B813BF217BA472ULL, 0x8ED734D0EA884FEDULL, 
            0xC46437EA6D57DE68ULL, 0x53DCFC3E8C749DB2ULL, 0x43AFD8296CE7D124ULL, 0x25B802A690E36312ULL, 
            0x0FD8DFE623D70722ULL, 0x26FA94021192ECFEULL, 0xE60EE3328A8E825AULL, 0x0647B5D91C8E88F9ULL, 
            0x7E7A2D9498EEF892ULL, 0xD7FF6FCFB8765E5FULL, 0x0585C1CA2670C27EULL, 0x896F205A25990403ULL, 
            0x24D6D0086002C52DULL, 0xA94BA200BBE7F79CULL, 0xA7CCE65DEA37A8EEULL, 0xFFA48FB71714BCFAULL, 
            0xEDD7139B531D5D5AULL, 0x309FA78AA9E88FFCULL, 0x3F4424293C241699ULL, 0x4ECEC5DCAF11A257ULL, 
            0xF1A77CDA7586DA73ULL, 0x53DA8757FBC9BC2CULL, 0x219CD2F82167CED0ULL, 0x0D64F088DCB0A474ULL
        },
        {
            0x5F5C5B2B525E49E1ULL, 0xD950D311857C7975ULL, 0x86AA552FB25102ACULL, 0xA885217BCE27247BULL, 
            0x5B1C054733FEFB43ULL, 0x24BD503E21B2ED24ULL, 0xD162EC9651476EF2ULL, 0x599DA25727124A82ULL, 
            0x668C188FF9B8398CULL, 0xC73B13C401AE4751ULL, 0x2B69C508AD16296FULL, 0x869469E61FF842C4ULL, 
            0xB5A1E993A65B2817ULL, 0x43B539F99A2EE3BDULL, 0xECCA66188E2F53C6ULL, 0x04FF326B2F87ADA8ULL, 
            0xBE5705414AAC621FULL, 0x9BA7F88144A9FF51ULL, 0xBCC47199BC68DE1AULL, 0x315EACF0D4F8E0A5ULL, 
            0xFEF3BF4A4CA9B960ULL, 0x2A5FBABAC8B75419ULL, 0x6CA3A409ABBE182FULL, 0xFBBAA1522D58BAC4ULL, 
            0x7F6E128F97F60CA6ULL, 0x7088F97D46CA4374ULL, 0x8C17DAD5A72DE1EAULL, 0xC912E74B4BBEF361ULL, 
            0xA555346F6869A7BBULL, 0x2C2D276D5C69F10AULL, 0x239533CAD2ACA9ECULL, 0xC06FF2EC1DBA4CE0ULL
        },
        {
            0x40ABFBBCD201DF3BULL, 0x3A74EE1C51D2EBCDULL, 0x3B955A52843D6FBBULL, 0xC5F9BA696976C980ULL, 
            0xFB74B71E71D669ABULL, 0xB9AC161F55FE1CD6ULL, 0xD7863A44F62F3003ULL, 0x7D37FD16A789F834ULL, 
            0x9862E20D0B3ABF33ULL, 0x44EA319FA6D5A274ULL, 0x33921CFE0536F130ULL, 0x62CFA8975E588CF5ULL, 
            0x5BE910735C09BECFULL, 0x8EA1453AD71D24C8ULL, 0xB90D55994D183D49ULL, 0xCCC8D02D5B139E2EULL, 
            0xBF936D895EC5E93CULL, 0x0C01CB58299486F8ULL, 0xBD93D4A5D0EC10A8ULL, 0xABEF296A607E8E3CULL, 
            0x44A166E71C24CC77ULL, 0xE37EDEAF4F161634ULL, 0x1EE48D30426AB838ULL, 0x1D118F9F39585D88ULL, 
            0xE311F4F4496E29EFULL, 0x91D886C8675CC59AULL, 0xB7DEE1A0B61D826DULL, 0x010A3855E6C20DBEULL, 
            0xA8E86D56CEA960ECULL, 0xD85EA400DC41CB64ULL, 0xEAC0081347E245D5ULL, 0x1D6D94A1A7E7F738ULL
        },
        {
            0x4BF4DF15678C67A8ULL, 0xB33036395DE1BA72ULL, 0x6C992E746D36E1E5ULL, 0xA8155C3BC9DC9C4EULL, 
            0x3663E8F001347AC3ULL, 0xCE8DC600F0621387ULL, 0xB07FC95AB624C324ULL, 0x7AE78F196F08F454ULL, 
            0x1CBE75E26169FAF4ULL, 0x0EE40DBDAA7C3E5AULL, 0x7A88AFE1F226A595ULL, 0x8A16D777956506A8ULL, 
            0x16174831BC68CFA4ULL, 0x6DAC060D36D35BDBULL, 0x69ED79AE55F73E61ULL, 0x49E48F1AD0DEB9A1ULL, 
            0x6E58E1D81F1D8ADDULL, 0x0C26EEFF9947E2C8ULL, 0xC799191F03F9B941ULL, 0xA549BAEBF64C30D7ULL, 
            0x618A1ACD3443407DULL, 0x862B03048D2C9A2DULL, 0x70CBF12EE3B56947ULL, 0xDE1A64EBC5C11BF1ULL, 
            0x4595CA5497391BB3ULL, 0x7C208AB55EFB94F6ULL, 0x4014BAB393F3F063ULL, 0x2BD4150645588A2FULL, 
            0xC3DD3F4C8581408FULL, 0x1A3CFB9AD100BC0EULL, 0x875D5DD1575E6621ULL, 0x08ACD3A8EAC5F0A6ULL
        },
        {
            0x4AB02CE5F203AB58ULL, 0xDA52DE88AD524112ULL, 0x65A79C5ECD4B0B02ULL, 0xE59A0292CD2BE896ULL, 
            0x9FAFE9016BF94AA9ULL, 0x2C568A0E92DB06F0ULL, 0x7D8A89021BF7699AULL, 0x57DC8BBD52542F77ULL, 
            0x303A97256026BD56ULL, 0x73D075D61B091623ULL, 0x1035A12E90CBF79DULL, 0x8248A40E27BA585AULL, 
            0x130CF742F809C5CEULL, 0x79EEFF78BB5DE259ULL, 0x20505BFAA1D557B5ULL, 0xDE28D54C478CD0DFULL, 
            0xE0D7675ED65FFD06ULL, 0x44F3D75E6287EB13ULL, 0x78E32B073FC9BFD0ULL, 0xDAEF37AF49032C1EULL, 
            0xD75F10F83B20AEC6ULL, 0x335B9738419B263BULL, 0xF263A1FC8ABB7213ULL, 0x779CBF3C3F7DA57EULL, 
            0x8863671E75756EBAULL, 0x4F01B6CD9A4080ABULL, 0x8358D9D0A37AD929ULL, 0xE5C4431911E26267ULL, 
            0x8FF0568D983D3940ULL, 0x139B1E40883C1A23ULL, 0x309B1F603F0D5663ULL, 0x21B3A45F94C9C54BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseGConstants = {
    0x7FF8CA86B14F13BDULL,
    0x4D23CDA564EC6F58ULL,
    0xC2EC5249C2FE5FD7ULL,
    0x7FF8CA86B14F13BDULL,
    0x4D23CDA564EC6F58ULL,
    0xC2EC5249C2FE5FD7ULL,
    0x5E21E8A21FE6308EULL,
    0x77DD4B5ADCAC4BF5ULL,
    0x85,
    0x52,
    0xC2,
    0xA7,
    0x46,
    0x94,
    0x7D,
    0x89
};

const TwistDomainSaltSet TwistExpander_Unholy_060::kPhaseHSalts = {
    {
        {
            0x503C35C372E549E0ULL, 0xBC370D1E89E5F49BULL, 0xEC0D7170731AE401ULL, 0x6DD605E2FA9653BEULL, 
            0xB263154221F520FEULL, 0x440C5E9379D4788AULL, 0x9B0DBF273B28C13DULL, 0x7100C2A3556D78A8ULL, 
            0x630837649E26D130ULL, 0x08FBCA3274E92547ULL, 0x88D32DB1D964683EULL, 0xE991019714077E09ULL, 
            0x1F15748A713F7516ULL, 0xAD3ED26B475FBC1BULL, 0x9DD42761B53094B1ULL, 0x360BF89335CE7F1BULL, 
            0x5AD817AD4E9053F4ULL, 0x504B2283158DFA68ULL, 0x80509F174746CEADULL, 0x3C10A8741656F97DULL, 
            0xD569D02DD1A987D8ULL, 0x6DC42DF62A4C12E3ULL, 0xB96B428F7739CCD6ULL, 0x9F40FB5AD07EE649ULL, 
            0xE5E5F41A07EFC2FBULL, 0x82461D5C94B222DEULL, 0x76D98B5D288EA65DULL, 0x118C1D7D7997379AULL, 
            0xEEBC4E59629257C5ULL, 0xE4B60CDEFD668CAEULL, 0x68CCF5156E510716ULL, 0xC5286FA2A1648A70ULL
        },
        {
            0x1134E4A287638B4EULL, 0xC2F6666B38A4415AULL, 0x64110B09D05A7E2AULL, 0xF27447A9C71CACA1ULL, 
            0xB9CB586DB0942ECCULL, 0x720DA5458D70C8C0ULL, 0xAF3423AE776393C0ULL, 0x8A2ABA41E02F630EULL, 
            0xD56034F7FDAA0BECULL, 0xA4F35CD05DFB1EF6ULL, 0x27E21B4C19ABF341ULL, 0x7539054AB7189C37ULL, 
            0xE08D90CCA4A0346AULL, 0xF5F8B6F5EB26E1B2ULL, 0x33EC39C0FD5C0115ULL, 0xA99BD3B34BF8834DULL, 
            0x8009AE6F600C4011ULL, 0xBA411C901EB6D20BULL, 0xEC11900DFE4E6CF4ULL, 0x4AA6604E94715E58ULL, 
            0x444EC93F2A0E3495ULL, 0xCA355EC824BEF0E4ULL, 0x9B97E25EEBD6C994ULL, 0xFA7081F85AB56108ULL, 
            0xDD49E8DFA1B63B18ULL, 0x015FAF7A9826FC05ULL, 0x422093332730A8CDULL, 0xC080496F8D34DC47ULL, 
            0x2CC52A93C41C0F65ULL, 0x9EB702359FABA45EULL, 0x93854C9B8B89F665ULL, 0x7299CA79D3D5C51AULL
        },
        {
            0xBED3AF9EB2E12396ULL, 0xFAD58C47514CAD02ULL, 0x8D5422CEF4FCC451ULL, 0xFC0EB72593D7DD73ULL, 
            0xC931B8E7DADE6771ULL, 0x2D3B50ED242AB62EULL, 0x6EDADDC5B04DDECAULL, 0x23D6EA03CCEA2216ULL, 
            0x8C6F33BDBEA5E47DULL, 0xC067D7D176563CCAULL, 0x902CC8CD8C7CAE08ULL, 0x1976C4BF7CFAF7C3ULL, 
            0x013CA94958B8D2EDULL, 0x03F7CF1E8096FB5DULL, 0xD8824924BD48B991ULL, 0xD6C9262CF9EBC13AULL, 
            0x1862DFCF5B921527ULL, 0x59A5E9F28EB9B853ULL, 0xDE393C5CD0D7BD71ULL, 0x7D284498FDA476B8ULL, 
            0xEF5D7E227E1278D3ULL, 0x7FCB341257E6AFA1ULL, 0x5A93569F29D973AEULL, 0x62BDB5356B6D469DULL, 
            0x3F3EE8369FD72DC5ULL, 0x55DED3AFBC0CA883ULL, 0xBB39421438A6AB7AULL, 0x270B118C9C8707DDULL, 
            0xDB5ED3025579B32FULL, 0x106148356C1A4063ULL, 0xEA27E83AAEA50840ULL, 0xA1E79EB5E6BF6691ULL
        },
        {
            0x9DC6EC7E0B8925F1ULL, 0x5E358634785F17BEULL, 0x7D2C477E64F1DB67ULL, 0xEF773B15E5102607ULL, 
            0x942740B5192B2CEEULL, 0x768105B0C72415F2ULL, 0x8D021970706AEF9EULL, 0x35444DE5FCF84DD7ULL, 
            0x2EEF392382F28774ULL, 0xA787B822B91C6F69ULL, 0x4EBC39F09F3BF383ULL, 0x79BBBAECADAB5876ULL, 
            0x85091F9FBB62771DULL, 0xCD61572DDB04F478ULL, 0xD8FA86525511FE46ULL, 0x92F3159CD84D5F76ULL, 
            0x0C13F626FDE0E5B3ULL, 0x1C5E5C09A1ED8843ULL, 0x8DCE300D32CA7ED3ULL, 0xC82413F46E32C9BFULL, 
            0x428B158000E73930ULL, 0x54C32E7F3E60C77DULL, 0x2AF43A457CB784DEULL, 0x2FFAA1BC7F151A49ULL, 
            0x24411608B98D0AFEULL, 0xA597A7645305CC8DULL, 0xB570D4152EC37FC1ULL, 0x9ED37A234BB2E7ACULL, 
            0xA9B8D9D8DD2823E5ULL, 0x980E2A11145D0067ULL, 0xD5AC1EBE586A83AAULL, 0x630B93AA0944A01BULL
        },
        {
            0x8BB9BF3C02A75912ULL, 0xBD3B2265FE5FC921ULL, 0x13041048F28BAD72ULL, 0x05779D43576EC5B8ULL, 
            0x2C8F729255C52FCAULL, 0xA8EB1466349881E8ULL, 0x15916F6C6390B675ULL, 0x8B4B49769635364CULL, 
            0xE78DF5926D8CF235ULL, 0xF3E3C8F84BDE9CFBULL, 0x9F297DCFE7DF0716ULL, 0x2BA740E0CC5EFBB7ULL, 
            0x7DC3AB37FAE6B824ULL, 0x8A5B6C9431703C7FULL, 0xF76758DE543D11FCULL, 0x194525E4897C781AULL, 
            0xC34D9BDCF1E390FEULL, 0xB61C370D89A47F5DULL, 0xC1E04B29D86AB553ULL, 0xD73A6C31336C0BB9ULL, 
            0x8CBECE4566D84DC3ULL, 0xCEDF66E8ED8C72D6ULL, 0xE92A5D115A4931ECULL, 0x27DCE7F08A6CFB0AULL, 
            0x907185263B6D1B05ULL, 0xFE61D0FEC972CF64ULL, 0xF455150EECACEA1CULL, 0x241776590B909D65ULL, 
            0x607137372B653BB6ULL, 0x2F6D880C1F067415ULL, 0xF84BCB9A6E53B007ULL, 0xBE8A2D8E44E41030ULL
        },
        {
            0xEB0A9F240D095A47ULL, 0xEF3363F206676498ULL, 0x55309AD90FBD0007ULL, 0x588BA4E28B1CEDB8ULL, 
            0x6B3407BE06237962ULL, 0x99B8F6CC4AA5110FULL, 0x5629C86FBC2511B5ULL, 0xABBED669E2C59168ULL, 
            0x5969E14B5FFCC226ULL, 0x78E884A2BC117B93ULL, 0x84BF683439DC25AFULL, 0xB79EA2C4A311AEDAULL, 
            0x7FEF3AAC1A57B319ULL, 0x53850A4234FB44EEULL, 0x384CA318EBE5965BULL, 0x105DB4A6E63D0051ULL, 
            0xE38EB265D8AAB291ULL, 0xB5051AA284479377ULL, 0x5E5F58125E1B1058ULL, 0xA984C0E9E6D6AF91ULL, 
            0x46E56F821AB27498ULL, 0x7B83320AA14D2CF2ULL, 0xBC38E5E0B102C84CULL, 0x3D14F061ADB6B197ULL, 
            0x494DA7010E63CCCFULL, 0xAD7F8BDD66928F29ULL, 0x0CAA7CFA629B3C8CULL, 0x2EC46CE90E6E461AULL, 
            0x2642ED4B0969409AULL, 0xE1963BF11F58BD44ULL, 0x34290CE271A563B2ULL, 0x7B8C7B09D73B9314ULL
        }
    },
    {
        {
            0x8054B5A8EA345D32ULL, 0x89CC041D05B57811ULL, 0x3D1666616CC33E61ULL, 0xCF8C388A300F7E85ULL, 
            0x84FE7D32FD5D0FD2ULL, 0x3FF3F4BF82885D8EULL, 0xFB66A472C90199D5ULL, 0x83AC5B9171E1E793ULL, 
            0x64E198C09323A512ULL, 0xF638C0F8A6D07BBFULL, 0x1CBAAC925F945DB7ULL, 0xB3707EAEA8766826ULL, 
            0x48CD6EB92CFDC96BULL, 0x60326FD01939D5D3ULL, 0xB9480E7251AD3C4FULL, 0xD7E8168E964D3429ULL, 
            0x089625DD2E57CF28ULL, 0x754535FC2AC2A576ULL, 0x840F533483AF8F20ULL, 0xC9C3264896E11331ULL, 
            0x40BCAFF05274E7A7ULL, 0x9BC7D143DDFB7F48ULL, 0xCE9836B5F1DA4159ULL, 0x4D2AA3DD639AA0D3ULL, 
            0xAF94980711B7F56DULL, 0x56ABA9000FD58857ULL, 0xE316D0973C753CDAULL, 0x42A2FFF3A8EA08FBULL, 
            0x1EBC31263CA55244ULL, 0x652154D787D992A7ULL, 0xD864CA1FD098D7BFULL, 0x1EAC4CA7D0EE7A9AULL
        },
        {
            0xC722F59C66A6200EULL, 0xCD441A270C17D03EULL, 0x6475C48E1ABB0C38ULL, 0xE0C6DD0A7391185BULL, 
            0xC8184AF2FFF66DB2ULL, 0x9F16E482312022ECULL, 0x4BCAF9D46519F8A7ULL, 0x575B6CC50609E7CBULL, 
            0x1FD89F667E0B0AEFULL, 0xA7C969B79877CA27ULL, 0xD285A1B498F21FC6ULL, 0x75441FD4FD105B81ULL, 
            0xEE4C77C0CFC5406BULL, 0xD2160F380677D0E8ULL, 0x609262296D975389ULL, 0x9C8213EA25212EEEULL, 
            0x3EFE70C7ADDEC1F8ULL, 0xF4C6CA837BB7FE2BULL, 0x0B01E772779A4C66ULL, 0x1A09FE770883DF13ULL, 
            0xF53FB44420BFF166ULL, 0x7CFF6D50273ED794ULL, 0xE4D1AEFAD483DB39ULL, 0xB8104B2E0CDF8C3DULL, 
            0xB40E418AB06F2E22ULL, 0x4F5F38B2CD7F219DULL, 0x6DC90B17AF5D1242ULL, 0xC7807EB36A18DD22ULL, 
            0xCB98AA47B4C1210CULL, 0x1F99C29A52477954ULL, 0xC84BCDF9EB8BA376ULL, 0x84E6BA798C940C25ULL
        },
        {
            0xA9604BFB3E2C99DFULL, 0x613DBC9ECE75CEC2ULL, 0x8D4F690202D58F7DULL, 0x2177C9F90B7C0519ULL, 
            0x538ED879F943F837ULL, 0x890DFD0B93126165ULL, 0x325234FCEB73C79CULL, 0xEA3E63C4A1E7B2CDULL, 
            0x12722A6B782B150AULL, 0xDD2CBE50A74BE70EULL, 0x8EC802148CA8DC7CULL, 0x46D704EDF8E643ADULL, 
            0x295631D9A2385E53ULL, 0x294B4C8512E14964ULL, 0xCB77559D7D86C758ULL, 0x09D37EAF9FF56736ULL, 
            0xD821851F295D946DULL, 0x06B3A528EC4E7177ULL, 0x9ABE0F37BE98102BULL, 0x6C28D4141F425863ULL, 
            0xC03A6017D3623CFAULL, 0x5FF90F48424EEEF0ULL, 0x831573FEA58A91E9ULL, 0xA8FC1D073DEFBE0FULL, 
            0x3A8176945F21A54FULL, 0xAEB280E5482480CAULL, 0xE564F780E75885F2ULL, 0xA72B9470163D9176ULL, 
            0x28236B605B2A8968ULL, 0x163709E7D1149F56ULL, 0x7C15BC35BEEA709BULL, 0xC3C63F3F084B8B88ULL
        },
        {
            0x1D14420A5F5924E9ULL, 0xE87654FC0AC7BE6DULL, 0xC256904CE34636F0ULL, 0x563A7AB597C65735ULL, 
            0xC79EAAB5A625EB52ULL, 0x0E3CFD0BAD8BC460ULL, 0x25FDC4BA8EA2C7F9ULL, 0x6C77331054A4B262ULL, 
            0xA5A15F88DB90904AULL, 0x80B36F419DC22AB7ULL, 0x431ACB9B8D580824ULL, 0xEEC15AB69EDA37ACULL, 
            0x89D5A7B930240C60ULL, 0x93DA994C72EAFB95ULL, 0x8F66323B56FA0D18ULL, 0x5D8C30253D26FBF0ULL, 
            0x13A11C0F7505D1E7ULL, 0x014C771CD7438FE7ULL, 0xBFC3F279AE8FA8DDULL, 0xDD9D48886A6BBBADULL, 
            0x5C5A33288797BC36ULL, 0xAFA7F4AA55A063E7ULL, 0xF04A8876A9A90886ULL, 0x139B038EAEABC91DULL, 
            0xF8F0EF0C66815F03ULL, 0xD44805F64C9CE57AULL, 0x7420582E5B6493F5ULL, 0xECB40F0CA9B26927ULL, 
            0x29288218583FDB1FULL, 0x2472C2790ABE0A8CULL, 0x4C7A96A1648E0B36ULL, 0x442A45A33BCC28FBULL
        },
        {
            0xFE730BE74684056EULL, 0x317ABE4DA99C8954ULL, 0xC83896DA1F1D9FA4ULL, 0x73A9999D9C36D44CULL, 
            0xF444F275B072DDD4ULL, 0x5AAB5D190E2637EEULL, 0x2FA509AECA216FADULL, 0xC1B563DA189763D8ULL, 
            0xC20CAB2B273995FBULL, 0x4546E568C684208EULL, 0x0C3E740205928B61ULL, 0x1874A0D72093FD03ULL, 
            0x1C96ED019965D3D4ULL, 0x984EFA35C355AEBBULL, 0xCBCB93EF5C656030ULL, 0xECE1F7A73C7B0577ULL, 
            0xED390CD3ACA789CEULL, 0x1F60553DF4045BA3ULL, 0xC13B0A797186753DULL, 0x5E992E11ABCC4001ULL, 
            0x11B08CBB3AA5990FULL, 0x73C6E44F17BA6C92ULL, 0xABCF058614AB02F6ULL, 0xDD1D90C7677A0BC5ULL, 
            0x2702076F3938AEA7ULL, 0xB4F421BEAFDD425BULL, 0x95FB21930343A39DULL, 0x3A68AD07587F0142ULL, 
            0x2B85208BC7072BB7ULL, 0xD41E58E543788696ULL, 0x6B9FD88F8128B57EULL, 0x49BC758B4B169A96ULL
        },
        {
            0xCE59D4257D2FA435ULL, 0xD5614A52B50E449FULL, 0x284F7C11C4350CF6ULL, 0x3019E9B6723CF002ULL, 
            0xCDF1D96661ACAE31ULL, 0xF2874AEAF3DD6784ULL, 0x73BFAB0C1BA1BF09ULL, 0x41F1F8C00D5D4F8CULL, 
            0x547457BEBDA50B7AULL, 0x1C1E1C78E8AF5128ULL, 0xE1E049FDD33626B7ULL, 0xBBF597D89800C9CBULL, 
            0x73DDA57D0F460BA0ULL, 0x4D6F44D0E1B14CB0ULL, 0x9FBE07C4E726F7C3ULL, 0xE33CCDD3FDFA0714ULL, 
            0x6E6DBBEAFC3F788FULL, 0x91A56CFED362E733ULL, 0x95CE33EAC31095DAULL, 0x198E29D564DEBD85ULL, 
            0x59972D6092FF5909ULL, 0xFDA7B721074AE566ULL, 0x9E78DF7A2C3E5C59ULL, 0x6CBC54A923D84E07ULL, 
            0x4750EE56BF92F3F9ULL, 0xD18094E24D4DA5E0ULL, 0x942B5C178679607DULL, 0x0BE247C2CC8ACBE3ULL, 
            0xD5E04AA4B63E6106ULL, 0xF9BB4873C04373F0ULL, 0x4FF45AE843AED7AEULL, 0xBFD49ED88C2EFAC9ULL
        }
    },
    {
        {
            0xAD93C0B0D281A780ULL, 0x15C22A5B15E86E92ULL, 0x3C63C5EC9F4D11B3ULL, 0x897FF555E2E7B8BCULL, 
            0x78C9ED1DF63AEDBEULL, 0x4EC2BF15F9FC3926ULL, 0x07E76C6A46900CD9ULL, 0x933DF46738F42FFBULL, 
            0xDC9F2103CF9D91D2ULL, 0x0D8ED307C37DA657ULL, 0x96155AE97373DE4AULL, 0xE459C8F1C080E246ULL, 
            0x7142815BBBF670B7ULL, 0x56C76BD6856419EAULL, 0x643C26913802B5DDULL, 0x9115312414133586ULL, 
            0xD6D56659A52E8B89ULL, 0xC1949C5FFAFEB205ULL, 0xABF28CF2E2B5F45BULL, 0x8D57B6C042ADC2E6ULL, 
            0xBD18F5F29B5DF0E2ULL, 0x9E9E32F56FD78617ULL, 0x555DB8204A566F2BULL, 0xFF2C91227B0B7E0AULL, 
            0x6652FA137659BE2EULL, 0x45AA778969F9CC41ULL, 0x597C1AEFE4C49E7FULL, 0x1E1ED1F68E44F422ULL, 
            0x0203E5F49A7DCB02ULL, 0x1262EC0B35B183C7ULL, 0x31CAC17C6C1F1E0FULL, 0xE284DB01D084EABDULL
        },
        {
            0x2869894233A29932ULL, 0x8521885A40A9289DULL, 0xE55F82646654A144ULL, 0x48F774BA0945A900ULL, 
            0x417A7F3EDF85D887ULL, 0xAAC4E599ED3D55F2ULL, 0xCD91149F2A63C799ULL, 0x6AFA0C4F0A1D532CULL, 
            0x61B259254EDFD041ULL, 0xB242773AEDD320A5ULL, 0x0E03EA0AFA3BFD28ULL, 0xF35CA5A927D51B2CULL, 
            0x1239E632E6EE05F9ULL, 0x58873439A209E541ULL, 0xCA893D655A8252DEULL, 0xFDD52FB1D5EACE2DULL, 
            0xF5396B4E98E9E707ULL, 0x39265681FB4EE6DFULL, 0x37FE48AC63DAC90FULL, 0x60BF63DE537C7A73ULL, 
            0x8DDAD8D06ED58B2DULL, 0x14F323F2C08458FDULL, 0xE44732FC3F98A937ULL, 0x8B3ACB6D04662A45ULL, 
            0x7E51E883CD429822ULL, 0x8F52854867DFF4E3ULL, 0xD8156DE70E1B6E28ULL, 0xCEE18D19CFA33E5DULL, 
            0x5AFB950229ADB516ULL, 0x99B092757DBDAF18ULL, 0x4BEE7A7E2EF575B5ULL, 0x24E9127E05D18C98ULL
        },
        {
            0x11C27FC3D3BDD042ULL, 0xED0E293D4A1DA30DULL, 0x89A0DF2BC609D8D5ULL, 0x69A9AA14727B39D8ULL, 
            0x93209D4FE4E4F05BULL, 0x910314550A4F28A1ULL, 0x434B49ED2D7602E8ULL, 0x21910A324FAC16F8ULL, 
            0x77A8BEDDE1AE972FULL, 0xDEEB9A1E3C4B4103ULL, 0xB30E33AE442D033AULL, 0xC17F94C7CFE2F3B2ULL, 
            0x814F3A5DF1CE4BF8ULL, 0x6A3B90EF3BE5320DULL, 0xFD12A1367E7C724BULL, 0x36AA8F5D8342CD5DULL, 
            0xEE68FC7E0DD6D54EULL, 0x83DAF7A072A2FD90ULL, 0x909FB16A550D14DEULL, 0x9E705404ADA45788ULL, 
            0xAF08019326CE16C2ULL, 0x6812146562338B1BULL, 0x18FF3E427B084015ULL, 0xF4D670D2F5E69D02ULL, 
            0x342283484A2EF7F5ULL, 0x5AF34855B002FAD8ULL, 0xCCD8B7A5E110CB46ULL, 0xD70A6F0195978E78ULL, 
            0x0AFB573068F5479DULL, 0x75E6009DDFABBD48ULL, 0x78B0BD6DDAC26BBEULL, 0x9501B1359DC41D33ULL
        },
        {
            0xEB6C5F6502EA9E43ULL, 0x298DB0E67B3DE2F2ULL, 0x1C0CF3654984FDF5ULL, 0xD8FED71F8781D1F4ULL, 
            0xB318C45ADCCB57E2ULL, 0xB1AD020ACD5487BFULL, 0xF258D9555BF63140ULL, 0x1B2B7A949555F9E0ULL, 
            0x971EC8A0710C39F4ULL, 0x166CE40284F7E25AULL, 0xE5AD7B3B0CE08CB6ULL, 0xD7ABEE45D27EB2FDULL, 
            0x60D1DB7D204C367AULL, 0xBF69BE71E67F948FULL, 0x40C330F509BC2EF3ULL, 0x52B1F2EE44C70D2CULL, 
            0x263DDC4423D2EB6AULL, 0x299E858F4E5D4025ULL, 0x0EEB40CC749D0EFAULL, 0x01B09C3F9F169381ULL, 
            0xB7553E2A8FA20A3DULL, 0x44456541C6BCDFA6ULL, 0xF96ED289588B936CULL, 0x77896EDDC5881B27ULL, 
            0x56B9617E579918C7ULL, 0x98832B9883F13FC4ULL, 0xC7E564E7CC6B555DULL, 0x5D877B43533FB170ULL, 
            0xA1EA910CA5D77FDCULL, 0xAC2E22207AD4D188ULL, 0xDCFFCAA9C51109D0ULL, 0xBF084BBB0C6329C5ULL
        },
        {
            0xC4F1C754D91E838AULL, 0xE27008C93EC057B3ULL, 0x1FFE8453D4BF14D4ULL, 0x56BB5085062C3B90ULL, 
            0x8B55A40A09C71E55ULL, 0x3D0F3853A9779430ULL, 0xF867A6C80337B4BDULL, 0xAD85CC15A16F1D11ULL, 
            0xEFF446FA6A0993B8ULL, 0xE24EDE6F5E9B9A8BULL, 0x97BC7A267E991197ULL, 0x0EA0B2B7D335258DULL, 
            0xB3603A0152287F9BULL, 0x3B2EE58821001C68ULL, 0x8925FA9F334BB8F7ULL, 0x97781BE59DD28826ULL, 
            0xF136C507EEDCC4D2ULL, 0x89A0B5E3DA9740FFULL, 0x8C899BA05A570C02ULL, 0x90E41667439CE973ULL, 
            0x28A0ACA104670CA9ULL, 0x2215429CE91D0613ULL, 0x04277F5DA47BAFE4ULL, 0xC714B7795318C995ULL, 
            0x1B9EC15F7779994DULL, 0xF4A77AA292C45760ULL, 0x03315F60B0748118ULL, 0xBF820828F4CB4170ULL, 
            0xCA5BFCDC876EFAE5ULL, 0x8A337807DB33CAB8ULL, 0xDBE99D5B2CB61CBFULL, 0x46514D911F582225ULL
        },
        {
            0xA3B7A8076428EC8FULL, 0xCCEBDC7FF63E3270ULL, 0xB8DF160DFE70DD44ULL, 0x6AFE7DC600C972F6ULL, 
            0x1EB5346450166C43ULL, 0x5BDBC8D10A2A5CCDULL, 0xA8DAC1EB81358DC0ULL, 0x9005A97487DECE92ULL, 
            0x9AA0D67351EF698BULL, 0x0669F0F007247511ULL, 0xEB9DE413C42FBBAAULL, 0xB60DDFFB99C0D8F8ULL, 
            0xD5285311CADE85ADULL, 0x6F1A392C37CEF93DULL, 0xF4ED006239F96B70ULL, 0xC41B456D0DAAE2C1ULL, 
            0xE1FA73D39F0F4C2FULL, 0xF91D59B1154548CDULL, 0xA92120E109774649ULL, 0x033157F351C9DBD8ULL, 
            0x8E80ABACB00DCF25ULL, 0x3A29E86DD428F67DULL, 0x8D311C4C7AE140DAULL, 0x873C7F1CEC3ECA51ULL, 
            0x2F111B88E4EAED8FULL, 0x2EC093C86B6942F1ULL, 0x257A440384EF0A8BULL, 0xA2EC9FC9451B3B2EULL, 
            0x05EABE77A521DA1EULL, 0x2AB902ECB8669673ULL, 0x021939E5F0F5B7B0ULL, 0x05DB0305D2507046ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Unholy_060::kPhaseHConstants = {
    0x1B21286FF66150BEULL,
    0x505B4D09EE14B7ABULL,
    0xFA622D6BEAB38B9FULL,
    0x1B21286FF66150BEULL,
    0x505B4D09EE14B7ABULL,
    0xFA622D6BEAB38B9FULL,
    0x5EF2CFEBA216B302ULL,
    0x44BCD20C8EDDF78FULL,
    0xDF,
    0xFA,
    0x95,
    0xF6,
    0x73,
    0x2F,
    0x07,
    0x06
};

