#include "Candidate_A.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistInvest.hpp"
#include "TwistMemory.hpp"
#include "TwistShiftBox.hpp"
#include "TwistSnow.hpp"

#include <cstdint>
#include <cstring>

Candidate_A::Candidate_A()
: TwistExpander() {
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
}

void Candidate_A::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
        aPrevious = 15869108861639048278U;
        aCarry = 17490388157257486959U;
        aWandererA = 9644734246001857842U;
        aWandererB = 11997377509180780368U;
        aWandererC = 9471408574306015365U;
        aWandererD = 12371360740806770110U;
        aWandererE = 17931219435055689403U;
        aWandererF = 11676499435457409150U;
        aWandererG = 9507039976100238934U;
        aWandererH = 12866200269249143243U;
        aWandererI = 17800009993497323755U;
        aWandererJ = 13169409853608644043U;
        aWandererK = 10975295374571330769U;
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 28U) ^ RotL64(aNonceByteG, 3U)) ^ RotL64(aNonceByteH, 19U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1145U)) & S_BLOCK1], 51U) ^ RotL64(mSnow[((aIndex + 4468U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteB, 43U) ^ RotL64(aNonceByteE, 3U));
            aCross = aCross ^ (RotL64(mSnow[((S_BLOCK1 - aIndex + 3887U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7712U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 12775735908960052604U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 53U)) + 11791373812080296887U) + aOrbiterAssignSaltA[((aIndex + 6961U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + 5537362877706057303U) + aOrbiterAssignSaltE[((aIndex + 6188U)) & S_SALT1]) + RotL64(aNonceByteE, 53U);
            aOrbiterB = (aWandererB + RotL64(aScatter, 60U)) + 2023912048504189380U;
            aOrbiterG = (aWandererG + RotL64(aCross, 3U)) + 17668828109963766893U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 558908629933941224U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 1479633119685446888U) + RotL64(aNonceByteB, 26U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15460320397843364063U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10059749397555469054U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7893U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9987633811929693924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 380U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4446204415503364254U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15106063243302192717U) ^ RotL64(aNonceByteH, 25U);
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9430197906134676162U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10611580584157624739U) + aOrbiterUpdateSaltA[((aIndex + 3149U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3177U)) & S_SALT1]) ^ RotL64(aNonceByteC, 21U);
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9327201928815412810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7890659377013147073U;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10675114832750356941U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8804440385852327267U;
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aNonceByteA, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceByteF, 29U)) + aWandererUpdateSaltD[((aIndex + 1227U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 36U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 3875U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: aExpandLaneA, mSource, mSnow
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 13U) ^ RotL64(aNonceByteA, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13161U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 10849U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteF, 41U) ^ RotL64(aNonceByteG, 20U));
            aCross = aCross ^ (RotL64(mSnow[((S_BLOCK1 - aIndex + 11676U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8713U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 3339283916456813609U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 18U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + 16819191669329316585U) + RotL64(aNonceByteA, 29U);
            aOrbiterH = ((aWandererI + RotL64(aCross, 3U)) + 8361916937762630725U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3849U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 29U)) + 18031328374429899857U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 18261756894092897276U) + RotL64(aNonceByteF, 13U);
            aOrbiterJ = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 4250319792907645666U) + aOrbiterAssignSaltC[((aIndex + 1840U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1492411503643460886U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 2216U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17369549067879344180U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5108U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7301713524358676722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2985193736033012535U;
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18205555540941493267U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 1629U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 9209505304067579944U) + aOrbiterUpdateSaltC[((aIndex + 6955U)) & S_SALT1]) + RotL64(aNonceByteB, 14U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3522631966146762306U;
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8811497120829041188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10080595991787801029U) + RotL64(aNonceByteH, 43U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterJ = RotL64((aOrbiterJ * 7417016898027778287U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 22U));
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 7639U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 57U)) + RotL64(aNonceByteE, 15U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + RotL64(aNonceByteD, 19U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3033U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, mSource, mSnow
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 19U) ^ RotL64(aNonceByteE, 11U)) ^ RotL64(aNonceByteA, 28U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16912U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 23901U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteC, 3U) ^ RotL64(aNonceByteG, 40U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 22408U)) & S_BLOCK1], 53U) ^ RotL64(mSnow[((aIndex + 20875U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 19U)) + 17264605017518259932U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 60U)) + 15209184354580778643U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 3299527965014731384U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + 16293096431816127821U) + aOrbiterAssignSaltF[((aIndex + 1915U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + 11031983436878828337U) + RotL64(aNonceByteC, 53U);
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 9188018632448236358U) + aOrbiterAssignSaltB[(((31U - aIndex) + 1757U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 13420816400363406556U) + RotL64(pNonce, 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2485063384097917101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3089135816938128264U;
            aOrbiterB = RotL64((aOrbiterB * 8813152992957361153U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10730544971770435788U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3885U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 14883796491656899074U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5483U)) & S_SALT1]) + RotL64(aNonceByteF, 20U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3862U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13322163435314643713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4950101626975919939U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2596253994220103666U;
            aOrbiterF = RotL64((aOrbiterF * 7181706961838582889U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17961706029559914243U) + RotL64(aNonceByteH, 37U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltB[((aIndex + 6065U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18146616411403012772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8414050129421955787U;
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltA[((aIndex + 2828U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 50U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + RotL64(aNonceByteB, 25U));
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 1511U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + RotL64(aNonceByteD, 39U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 53U) ^ RotL64(aNonceByteG, 43U)) ^ RotL64(aNonceByteH, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30140U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 25123U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteB, 35U) ^ RotL64(aNonceByteE, 23U)) ^ RotL64(aNonceByteF, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24638U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28664U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 11274974230580265396U) + aOrbiterAssignSaltE[((aIndex + 2597U)) & S_SALT1]) + RotL64(aNonceByteC, 29U);
            aOrbiterI = ((((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 16658438747342741547U) + aOrbiterAssignSaltA[(((31U - aIndex) + 1304U)) & S_SALT1]) + RotL64(aNonceByteF, 26U);
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 16612986966106053844U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 5U)) + 9329502236843231290U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 13U)) + 14088261356708344656U;
            aOrbiterG = (aWandererB + RotL64(aCross, 42U)) + 13692608802007789581U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 35U)) + 6824473946645682398U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2072915876348570040U) + aOrbiterUpdateSaltA[((aIndex + 1465U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltF[((aIndex + 5108U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4677557318688502593U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15081678577055628459U) ^ RotL64(aNonceByteG, 31U);
            aOrbiterG = RotL64((aOrbiterG * 16659305295251177155U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7026792817486507482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14871665922943969918U;
            aOrbiterI = RotL64((aOrbiterI * 694073180313083145U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6807734532159292872U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4027U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9233542707022629190U) + aOrbiterUpdateSaltC[((aIndex + 1443U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1205501586581350876U;
            aOrbiterF = RotL64((aOrbiterF * 2596053290311090589U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10878718669747466677U) + RotL64(aNonceByteA, 37U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8066049063548639241U;
            aOrbiterB = RotL64((aOrbiterB * 3031382633089381605U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 861295180226875235U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterD = RotL64((aOrbiterD * 7565008208670843555U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 42U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 915U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aNonceByteD, 17U));
            aWandererB = aWandererB + ((((RotL64(aCross, 38U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7460U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aNonceByteH, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteC, 29U) ^ RotL64(aNonceByteE, 38U)) ^ RotL64(aNonceByteA, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1442U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 2533U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteD, 53U) ^ RotL64(aNonceByteG, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3507U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 4748U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 51U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aIngress, 47U)) + 17264605017518259932U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 15209184354580778643U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 60U)) + 3299527965014731384U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7095U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 51U)) + 16293096431816127821U) + RotL64(aNonceByteF, 59U);
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 11031983436878828337U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 9188018632448236358U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 13420816400363406556U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 53U)) + 2485063384097917101U) + RotL64(aNonceByteC, 14U);
            aOrbiterK = (aWandererB + RotL64(aScatter, 36U)) + 3089135816938128264U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + 10730544971770435788U) + aOrbiterAssignSaltC[(((31U - aIndex) + 1773U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 13U)) + 10431767565618874806U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14883796491656899074U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3240U)) & S_SALT1]) ^ RotL64(aNonceByteE, 23U);
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13322163435314643713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3307316600284371955U;
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4950101626975919939U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 17961706029559914243U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 683U)) & S_SALT1]) + RotL64(aNonceByteH, 21U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltD[((aIndex + 1176U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11739172334166341121U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7936637782633487291U) ^ aOrbiterUpdateSaltC[((aIndex + 3478U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14940929920543800413U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3160044627483874242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16816384076887379704U;
            aOrbiterF = RotL64((aOrbiterF * 5052772186568301951U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8101560104988710226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8851416379738817624U;
            aOrbiterI = RotL64((aOrbiterI * 16767420038937389027U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9941784290055185679U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14495651885701938495U;
            aOrbiterC = RotL64((aOrbiterC * 1540692851998143607U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10599676325220702167U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16092000942942971187U;
            aOrbiterD = RotL64((aOrbiterD * 2457268192247656817U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16168470945107928109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17264605017518259932U;
            aOrbiterJ = RotL64((aOrbiterJ * 15038386057529909273U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 50U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + RotL64(aNonceByteG, 31U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 58U));
            aWandererF = aWandererF + (((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltD[((aIndex + 3461U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 807U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + RotL64(aNonceByteB, 45U));
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 30U));
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteD, 43U) ^ RotL64(aNonceByteF, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9760U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 13815U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 19U) ^ RotL64(aNonceByteC, 40U)) ^ RotL64(aNonceByteH, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10827U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12872U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 3339283916456813609U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5688U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 11339086426180649584U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 37U)) + 16819191669329316585U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 46U)) + 8361916937762630725U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 18031328374429899857U) + RotL64(aNonceByteC, 3U);
            aOrbiterB = (aWandererB + RotL64(aPrevious, 23U)) + 18261756894092897276U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 4250319792907645666U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 27U)) + 1492411503643460886U) + aOrbiterAssignSaltF[(((31U - aIndex) + 2845U)) & S_SALT1]) + RotL64(aNonceByteG, 47U);
            aOrbiterC = (aWandererI + RotL64(aScatter, 19U)) + 17369549067879344180U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 48U)) + 7301713524358676722U;
            aOrbiterA = (aWandererK + RotL64(aCross, 41U)) + 2985193736033012535U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18205555540941493267U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9209505304067579944U) + aOrbiterUpdateSaltD[((aIndex + 250U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8811497120829041188U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14707301680850257294U;
            aOrbiterE = RotL64((aOrbiterE * 11383709499376464085U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10080595991787801029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1981637172055758689U) + aOrbiterUpdateSaltF[((aIndex + 6095U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8383837717361569465U) + RotL64(aNonceByteD, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2788511294985017326U;
            aOrbiterF = RotL64((aOrbiterF * 2809163242875130677U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3529607472855930041U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8850940802020173766U;
            aOrbiterB = RotL64((aOrbiterB * 7821450253655655943U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7469160295100147267U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 16973986572163482061U) ^ aOrbiterUpdateSaltE[((aIndex + 555U)) & S_SALT1]) ^ RotL64(aNonceByteB, 25U);
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12371372942863279718U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12098525148034303633U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 2061U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11234127652230231751U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5138683482859889480U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3339283916456813609U;
            aOrbiterA = RotL64((aOrbiterA * 10975353228235695455U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 54U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5749U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 54U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + RotL64(aNonceByteA, 42U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aNonceByteF, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 38U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 42U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 36U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteD, 3U) ^ RotL64(aNonceByteC, 38U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16590U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 22659U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteF, 27U) ^ RotL64(aNonceByteB, 10U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21892U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 24374U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 12775735908960052604U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 39U)) + 11791373812080296887U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + RotL64(pNonce, 53U);
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 5537362877706057303U;
            aOrbiterC = (aWandererI + RotL64(aCross, 3U)) + 2023912048504189380U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + 17668828109963766893U) + RotL64(aNonceByteF, 7U);
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 558908629933941224U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 14U)) + 1479633119685446888U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 37U)) + 15460320397843364063U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 27U)) + 10059749397555469054U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 21U)) + 9987633811929693924U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 5U)) + 10087337844580228269U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6449U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4446204415503364254U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 2341U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9430197906134676162U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1226048679997253363U;
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10611580584157624739U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterJ = RotL64((aOrbiterJ * 5462682413239873181U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9327201928815412810U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5768U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10675114832750356941U) + aOrbiterUpdateSaltC[((aIndex + 4423U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8804440385852327267U;
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12871947817782057116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11015991745792051390U;
            aOrbiterI = RotL64((aOrbiterI * 17152451500505815031U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6320437975845673731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 702457937087191287U;
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16629064896250312921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6054107387816339103U) ^ RotL64(aNonceByteG, 61U);
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13274874838094190290U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12211422735294360321U;
            aOrbiterH = RotL64((aOrbiterH * 5113738196151089817U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15338616110718583619U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1475787183754511373U) ^ RotL64(aNonceByteE, 50U);
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15486810401396777742U) + aOrbiterUpdateSaltB[((aIndex + 6252U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12775735908960052604U;
            aOrbiterG = RotL64((aOrbiterG * 7478156942468930207U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 39U)) + RotL64(aNonceByteA, 55U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltB[((aIndex + 5363U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 60U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aNonceByteH, 13U)) + aWandererUpdateSaltE[((aIndex + 2712U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 46U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteA, 50U) ^ RotL64(aNonceByteH, 3U)) ^ RotL64(aNonceByteG, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28169U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26804U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteF, 27U) ^ RotL64(aNonceByteC, 58U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28278U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32459U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 10336802574069791273U) + aOrbiterAssignSaltC[((aIndex + 5073U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 60U)) + 169025388197058936U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 6541354188379168846U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 43U)) + 16223920526599306104U) + RotL64(aNonceByteH, 15U);
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 37U)) + 12756613707692514808U) + aOrbiterAssignSaltE[((aIndex + 7751U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 39U)) + 5082475548176484035U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 4907435526952698526U) + RotL64(aNonceByteE, 20U);
            aOrbiterI = (aWandererB + RotL64(aCross, 53U)) + 14236627073831834337U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 3U)) + 11502511046130497584U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 48U)) + 3679044835550219497U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 35U)) + 11254838916686736746U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10582608424233200966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterE = RotL64((aOrbiterE * 7363770199734997411U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4628253464169957835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3798386391743884889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9816600392407327227U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterH = RotL64((aOrbiterH * 12503867584828289879U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4807797577690520554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7909676419643119585U) + aOrbiterUpdateSaltE[((aIndex + 8043U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 256053568910383007U;
            aOrbiterG = RotL64((aOrbiterG * 11965085163352053161U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16179914439220412472U) + RotL64(aNonceByteB, 35U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3968867762761955845U;
            aOrbiterB = RotL64((aOrbiterB * 7473632378251893139U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7474832923901283742U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4294U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4736994731050735779U;
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 596484364660389193U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 2564U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13822222274464306169U) ^ RotL64(aNonceByteF, 5U);
            aOrbiterK = RotL64((aOrbiterK * 1723502278319885511U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16307920280681985443U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3505106171801702915U) ^ aOrbiterUpdateSaltC[((aIndex + 5421U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4987142580981135150U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10336802574069791273U;
            aOrbiterJ = RotL64((aOrbiterJ * 2670706512498539705U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aNonceByteA, 9U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 58U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 652U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 6435U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 28U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aNonceByteD, 41U));
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 21U) ^ RotL64(aNonceByteB, 53U)) ^ RotL64(aNonceByteA, 30U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3012U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 4990U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 19U) ^ RotL64(aNonceByteF, 37U)) ^ RotL64(aNonceByteD, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3000U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 1369U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 29U)) + (RotL64(aIngress, 12U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 11274974230580265396U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 60U)) + 16658438747342741547U) + aOrbiterAssignSaltF[((aIndex + 4532U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 27U)) + 16612986966106053844U) + RotL64(aNonceByteD, 24U);
            aOrbiterI = ((aWandererF + RotL64(aCross, 21U)) + 9329502236843231290U) + aOrbiterAssignSaltE[((aIndex + 3976U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 14088261356708344656U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 5U)) + 13692608802007789581U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 35U)) + 6824473946645682398U) + RotL64(aNonceByteE, 37U);
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 2072915876348570040U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 10U)) + RotL64(aCarry, 5U)) + 7420507753044460759U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4677557318688502593U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterA = RotL64((aOrbiterA * 16659305295251177155U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7026792817486507482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14871665922943969918U;
            aOrbiterK = RotL64((aOrbiterK * 694073180313083145U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6807734532159292872U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17882797335141303280U;
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9233542707022629190U) + RotL64(aNonceByteB, 47U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1205501586581350876U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7163U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10878718669747466677U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 861295180226875235U) + aOrbiterUpdateSaltB[((aIndex + 268U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9134969787937288583U) ^ RotL64(aNonceByteH, 23U);
            aOrbiterI = RotL64((aOrbiterI * 7565008208670843555U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6726642007159809594U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8061661744643240470U;
            aOrbiterG = RotL64((aOrbiterG * 6703498926835391813U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13541412083111962884U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3661U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8617442758729315637U;
            aOrbiterJ = RotL64((aOrbiterJ * 15471862889276160953U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16884403561131293362U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9490680911678221233U) ^ aOrbiterUpdateSaltE[((aIndex + 6357U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15988763830018001033U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 452U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 48U)) + RotL64(aNonceByteG, 55U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aNonceByteF, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3587U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 28U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 51U) ^ RotL64(aNonceByteA, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16364U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13518U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 57U) ^ RotL64(aNonceByteH, 19U)) ^ RotL64(aNonceByteB, 44U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12300U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 9823U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 29U)) + 3339283916456813609U) + aOrbiterAssignSaltA[((aIndex + 2115U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 11339086426180649584U) + aOrbiterAssignSaltD[((aIndex + 4713U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 16819191669329316585U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 18U)) + 8361916937762630725U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 43U)) + 18031328374429899857U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 5U)) + 18261756894092897276U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 23U)) + 4250319792907645666U) + RotL64(aNonceByteH, 25U);
            aOrbiterF = (((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 47U)) + 1492411503643460886U) + RotL64(aNonceByteG, 58U);
            aOrbiterB = (aWandererI + RotL64(aIngress, 51U)) + 17369549067879344180U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7301713524358676722U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2985193736033012535U) ^ aOrbiterUpdateSaltF[((aIndex + 1751U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14086975808140927408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18205555540941493267U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9209505304067579944U) + aOrbiterUpdateSaltB[((aIndex + 7510U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6479U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8811497120829041188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10080595991787801029U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterK = RotL64((aOrbiterK * 7417016898027778287U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1981637172055758689U) + RotL64(aNonceByteE, 61U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8383837717361569465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2788511294985017326U;
            aOrbiterJ = RotL64((aOrbiterJ * 2809163242875130677U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 3529607472855930041U) + aOrbiterUpdateSaltC[((aIndex + 7924U)) & S_SALT1]) + RotL64(aNonceByteF, 47U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8850940802020173766U;
            aOrbiterE = RotL64((aOrbiterE * 7821450253655655943U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 28U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 60U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltD[((aIndex + 5360U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + RotL64(aNonceByteD, 55U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltB[((aIndex + 2429U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 48U)) + RotL64(aNonceByteA, 31U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 21U) ^ RotL64(aNonceByteB, 38U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17971U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 17142U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteA, 5U) ^ RotL64(aNonceByteG, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19927U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22834U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aIngress, 58U)) + 17264605017518259932U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 27U)) + 15209184354580778643U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8174U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 5U)) + 3299527965014731384U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 53U)) + 16293096431816127821U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 11031983436878828337U) + RotL64(aNonceByteD, 57U);
            aOrbiterH = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 9188018632448236358U) + RotL64(aNonceByteC, 61U);
            aOrbiterB = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 13420816400363406556U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 48U)) + 2485063384097917101U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 23U)) + 3089135816938128264U) + aOrbiterAssignSaltB[((aIndex + 7683U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10730544971770435788U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10431767565618874806U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 1655U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14883796491656899074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13322163435314643713U) + aOrbiterUpdateSaltF[((aIndex + 3081U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3307316600284371955U) ^ RotL64(aNonceByteE, 45U);
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4950101626975919939U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2596253994220103666U;
            aOrbiterI = RotL64((aOrbiterI * 7181706961838582889U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18146616411403012772U) + RotL64(aNonceByteF, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11739172334166341121U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7936637782633487291U;
            aOrbiterB = RotL64((aOrbiterB * 14940929920543800413U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3160044627483874242U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5866U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16816384076887379704U;
            aOrbiterD = RotL64((aOrbiterD * 5052772186568301951U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8101560104988710226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5309U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterF, 36U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 14U)) + aOrbiterH) + RotL64(aNonceByteA, 50U));
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 5284U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceByteB, 37U)) + aWandererUpdateSaltE[((aIndex + 5136U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteE, 11U) ^ RotL64(aNonceByteH, 3U)) ^ RotL64(aNonceByteC, 20U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32241U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26915U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteF, 5U) ^ RotL64(aNonceByteD, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25085U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 32550U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 12775735908960052604U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 11791373812080296887U) + aOrbiterAssignSaltF[(((31U - aIndex) + 245U)) & S_SALT1]) + RotL64(aNonceByteE, 61U);
            aOrbiterA = (aWandererD + RotL64(aPrevious, 5U)) + 5537362877706057303U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 58U)) + 2023912048504189380U;
            aOrbiterK = (aWandererK + RotL64(aCross, 23U)) + 17668828109963766893U;
            aOrbiterH = ((((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 558908629933941224U) + aOrbiterAssignSaltE[((aIndex + 2957U)) & S_SALT1]) + RotL64(aNonceByteB, 46U);
            aOrbiterF = (aWandererA + RotL64(aScatter, 11U)) + 1479633119685446888U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 57U)) + 15460320397843364063U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 41U)) + 10059749397555469054U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9987633811929693924U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltE[((aIndex + 5588U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13817142288940843815U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 4446204415503364254U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4859U)) & S_SALT1]) + RotL64(aNonceByteA, 31U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10611580584157624739U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3137391249289641509U;
            aOrbiterJ = RotL64((aOrbiterJ * 5462682413239873181U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9327201928815412810U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 997U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7890659377013147073U) ^ RotL64(pNonce, 49U);
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12871947817782057116U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11015991745792051390U;
            aOrbiterC = RotL64((aOrbiterC * 17152451500505815031U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6320437975845673731U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 702457937087191287U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 2959U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17491257114676739589U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16629064896250312921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 34U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterB, 60U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + RotL64(aNonceByteC, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7538U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 569U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + RotL64(aNonceByteG, 59U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteF, 12U) ^ RotL64(aNonceByteD, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7368U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7243U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteC, 47U) ^ RotL64(aNonceByteA, 20U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4663U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6857U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 5697928251815176134U) + aOrbiterAssignSaltE[(((31U - aIndex) + 729U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 39U)) + 337587740689259575U) + RotL64(aNonceByteH, 22U);
            aOrbiterC = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 4927686903263973950U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 43U)) + 3742409032569801033U) + aOrbiterAssignSaltC[(((31U - aIndex) + 679U)) & S_SALT1]) + RotL64(pNonce, 5U);
            aOrbiterG = (aWandererD + RotL64(aPrevious, 51U)) + 1608092659172197650U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15848744267145717509U) + aOrbiterUpdateSaltA[((aIndex + 3889U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15300174177963339253U;
            aOrbiterC = RotL64((aOrbiterC * 5771922862677667319U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14162868453323648628U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12020167069983729869U;
            aOrbiterB = RotL64((aOrbiterB * 2071080217680099017U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16259538291658723956U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltC[((aIndex + 3987U)) & S_SALT1]) ^ RotL64(aNonceByteE, 37U);
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 3722184575520553132U) + aOrbiterUpdateSaltD[((aIndex + 4424U)) & S_SALT1]) + RotL64(aNonceByteB, 59U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterH = RotL64((aOrbiterH * 14364218128780764749U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15265344442454471986U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6671U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 52U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U)) + RotL64(aNonceByteC, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 12U)) + aWandererUpdateSaltA[((aIndex + 3286U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 35U)) + RotL64(aNonceByteG, 49U)) + aWandererUpdateSaltB[((aIndex + 5189U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 5U) ^ RotL64(aNonceByteH, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10301U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13834U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteA, 36U) ^ RotL64(aNonceByteG, 21U)) ^ RotL64(aNonceByteB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10137U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12664U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 12775735908960052604U) + aOrbiterAssignSaltD[(((31U - aIndex) + 2184U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 11791373812080296887U) + RotL64(aNonceByteE, 29U);
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 5537362877706057303U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 5U)) + 2023912048504189380U) + aOrbiterAssignSaltF[(((31U - aIndex) + 2831U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 21U)) + 17668828109963766893U) + RotL64(aNonceByteB, 59U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 558908629933941224U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1479633119685446888U;
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15460320397843364063U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10059749397555469054U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6929U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8671817118586065469U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9987633811929693924U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltE[((aIndex + 5836U)) & S_SALT1]) ^ RotL64(aNonceByteG, 39U);
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 4446204415503364254U) + aOrbiterUpdateSaltB[((aIndex + 1379U)) & S_SALT1]) + RotL64(aNonceByteF, 31U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltF[((aIndex + 6169U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[((aIndex + 5744U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 48U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + RotL64(aCarry, 3U)) + RotL64(aNonceByteD, 52U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + RotL64(aNonceByteA, 15U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5001U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 13U) ^ RotL64(aNonceByteC, 27U)) ^ RotL64(aNonceByteD, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17964U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 20546U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteE, 58U) ^ RotL64(aNonceByteF, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24369U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21775U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 19U)) + 11274974230580265396U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 16658438747342741547U) + RotL64(aNonceByteA, 19U);
            aOrbiterF = ((aWandererF + RotL64(aCross, 51U)) + 16612986966106053844U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7921U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 9329502236843231290U) + RotL64(aNonceByteH, 45U);
            aOrbiterC = (((aWandererB + RotL64(aCross, 28U)) + RotL64(aCarry, 51U)) + 14088261356708344656U) + aOrbiterAssignSaltA[((aIndex + 2423U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13692608802007789581U) + RotL64(aNonceByteD, 49U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6824473946645682398U;
            aOrbiterF = RotL64((aOrbiterF * 13619437545775237601U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2072915876348570040U) + aOrbiterUpdateSaltC[((aIndex + 7866U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltB[((aIndex + 2329U)) & S_SALT1]) ^ RotL64(aNonceByteE, 17U);
            aOrbiterA = RotL64((aOrbiterA * 13239288539564571257U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4677557318688502593U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltE[((aIndex + 7452U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7026792817486507482U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7157U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6807734532159292872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 56U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 4148U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 57U)) + RotL64(aNonceByteF, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + RotL64(aNonceByteG, 10U));
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 123U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteG, 19U) ^ RotL64(aNonceByteB, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27937U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 30621U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteE, 41U) ^ RotL64(aNonceByteH, 10U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26301U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 28674U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 5U)) + 17264605017518259932U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3933U)) & S_SALT1]) + RotL64(aNonceByteF, 29U);
            aOrbiterI = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 15209184354580778643U) + aOrbiterAssignSaltE[((aIndex + 170U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 3299527965014731384U) + RotL64(aNonceByteE, 38U);
            aOrbiterK = (aWandererF + RotL64(aIngress, 50U)) + 16293096431816127821U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 11031983436878828337U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 9188018632448236358U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4489U)) & S_SALT1]) + RotL64(aNonceByteG, 17U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13420816400363406556U) ^ aOrbiterUpdateSaltD[((aIndex + 203U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10958221259662190519U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2485063384097917101U) + RotL64(aNonceByteD, 15U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 1295U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8813152992957361153U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10730544971770435788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14883796491656899074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13465877783538483706U;
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13322163435314643713U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6489U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12337846092069506365U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + RotL64(aNonceByteC, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 18U)) + aWandererUpdateSaltB[(((31U - aIndex) + 1997U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 41U)) + RotL64(aNonceByteA, 11U)) + aWandererUpdateSaltA[((aIndex + 263U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)
}

void Candidate_A::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
        aPrevious = 17619584634669216652U;
        aCarry = 18190197680583767508U;
        aWandererA = 11116565557420023631U;
        aWandererB = 14504694397452635132U;
        aWandererC = 14906349213199562577U;
        aWandererD = 11721754742793757098U;
        aWandererE = 10644861144768673100U;
        aWandererF = 17639886816648427431U;
        aWandererG = 18333039161388851101U;
        aWandererH = 16956453470079320053U;
        aWandererI = 13574491708745719332U;
        aWandererJ = 9254193090437654262U;
        aWandererK = 13613057360946465963U;
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 57U) ^ RotL64(aNonceByteC, 11U)) ^ RotL64(aNonceByteD, 46U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1235U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5069U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteF, 43U) ^ RotL64(aNonceByteG, 11U)) ^ RotL64(aNonceByteH, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 381U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6267U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 17264605017518259932U) + aOrbiterAssignSaltF[((aIndex + 1939U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 39U)) + 15209184354580778643U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 3299527965014731384U) + RotL64(aNonceByteD, 59U);
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 16293096431816127821U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7261U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 58U)) + 11031983436878828337U) + RotL64(aNonceByteH, 17U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 9188018632448236358U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7301U)) & S_SALT1]) + RotL64(aNonceByteA, 25U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13420816400363406556U;
            aOrbiterC = RotL64((aOrbiterC * 10958221259662190519U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2485063384097917101U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltD[((aIndex + 7292U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10730544971770435788U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10431767565618874806U) ^ aOrbiterUpdateSaltC[((aIndex + 2905U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14883796491656899074U) + RotL64(aNonceByteC, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13322163435314643713U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6484U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12337846092069506365U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + RotL64(aNonceByteB, 9U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7528U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + RotL64(aNonceByteE, 56U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // read from: aExpandLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 29U) ^ RotL64(aNonceByteF, 52U)) ^ RotL64(aNonceByteA, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15641U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 8672U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 29U) ^ RotL64(aNonceByteH, 41U)) ^ RotL64(aNonceByteB, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15479U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9498U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + 5697928251815176134U) + RotL64(aNonceByteG, 9U);
            aOrbiterD = (((aWandererI + RotL64(aScatter, 4U)) + RotL64(aCarry, 19U)) + 337587740689259575U) + aOrbiterAssignSaltB[((aIndex + 1357U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 21U)) + 4927686903263973950U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 3742409032569801033U) + RotL64(aNonceByteD, 57U);
            aOrbiterJ = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 1608092659172197650U) + aOrbiterAssignSaltE[((aIndex + 6970U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15848744267145717509U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15300174177963339253U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4975U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5771922862677667319U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 14162868453323648628U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5845U)) & S_SALT1]) + RotL64(aNonceByteB, 27U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12020167069983729869U) ^ RotL64(aNonceByteF, 3U);
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16259538291658723956U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltE[((aIndex + 4007U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4731296903548893627U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3722184575520553132U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 2173U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aNonceByteA, 25U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3543U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 176U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 53U)) + RotL64(aNonceByteE, 56U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteH, 37U) ^ RotL64(aNonceByteG, 51U)) ^ RotL64(aNonceByteA, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19104U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 20766U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 13U) ^ RotL64(aNonceByteB, 56U)) ^ RotL64(aNonceByteC, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18906U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21225U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 11274974230580265396U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 35U)) + 16658438747342741547U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 22U)) + RotL64(aCarry, 13U)) + 16612986966106053844U) + RotL64(aNonceByteB, 10U);
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + 9329502236843231290U) + aOrbiterAssignSaltD[(((31U - aIndex) + 1573U)) & S_SALT1];
            aOrbiterG = ((((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 14088261356708344656U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7377U)) & S_SALT1]) + RotL64(aNonceByteE, 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13692608802007789581U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6824473946645682398U;
            aOrbiterK = RotL64((aOrbiterK * 13619437545775237601U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2072915876348570040U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7420507753044460759U) ^ RotL64(aNonceByteF, 31U);
            aOrbiterD = RotL64((aOrbiterD * 13239288539564571257U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4677557318688502593U) + RotL64(aNonceByteA, 15U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4397U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16659305295251177155U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7026792817486507482U) + aOrbiterUpdateSaltD[((aIndex + 2039U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterA = RotL64((aOrbiterA * 694073180313083145U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6807734532159292872U) + aOrbiterUpdateSaltC[((aIndex + 6427U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 1063U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 39U)) + RotL64(aNonceByteG, 41U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + RotL64(aNonceByteD, 61U)) + aWandererUpdateSaltA[((aIndex + 2332U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 2064U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneD
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteC, 3U) ^ RotL64(aNonceByteG, 52U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24929U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28846U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteB, 3U) ^ RotL64(aNonceByteD, 29U)) ^ RotL64(aNonceByteE, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29881U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26532U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 48U)) + 3339283916456813609U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 11339086426180649584U) + RotL64(aNonceByteB, 21U);
            aOrbiterB = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 16819191669329316585U) + aOrbiterAssignSaltC[((aIndex + 6255U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 8361916937762630725U) + RotL64(aNonceByteH, 14U);
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 5U)) + 18031328374429899857U) + aOrbiterAssignSaltF[((aIndex + 7401U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18261756894092897276U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4250319792907645666U;
            aOrbiterB = RotL64((aOrbiterB * 7053489184750217963U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1492411503643460886U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3251U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 17369549067879344180U) ^ aOrbiterUpdateSaltB[((aIndex + 2512U)) & S_SALT1]) ^ RotL64(aNonceByteE, 51U);
            aOrbiterK = RotL64((aOrbiterK * 2947354306696216579U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7301713524358676722U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7543U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterD = RotL64((aOrbiterD * 7473297294949338265U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14086975808140927408U) + RotL64(aNonceByteA, 17U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltE[((aIndex + 2937U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterK, 24U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7377U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(pNonce, 19U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 54U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5291U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aNonceByteF, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 19U) ^ RotL64(aNonceByteE, 11U)) ^ RotL64(aNonceByteA, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6074U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 7677U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteG, 42U) ^ RotL64(aNonceByteF, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3822U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 1001U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 22U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 47U)) + 5697928251815176134U) + RotL64(aNonceByteB, 26U);
            aOrbiterH = ((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 43U)) + 337587740689259575U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 4927686903263973950U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 3742409032569801033U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 29U)) + 1608092659172197650U) + aOrbiterAssignSaltB[((aIndex + 7599U)) & S_SALT1]) + RotL64(aNonceByteD, 19U);
            aOrbiterG = (aWandererH + RotL64(aCross, 19U)) + 15848744267145717509U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 15300174177963339253U) + aOrbiterAssignSaltC[((aIndex + 2843U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14162868453323648628U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6990U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12020167069983729869U) ^ RotL64(aNonceByteH, 61U);
            aOrbiterF = RotL64((aOrbiterF * 2071080217680099017U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16259538291658723956U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8516686212464112245U;
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3722184575520553132U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5780U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15265344442454471986U) + aOrbiterUpdateSaltB[((aIndex + 6000U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3050323350098829515U;
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1093356813820599238U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15167726103772238440U) ^ RotL64(aNonceByteA, 57U);
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15170797965325981472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14710892030473425181U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 397194787697553904U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4501U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + RotL64(aCarry, 3U)) + RotL64(pNonce, 31U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 42U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 42U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 7657U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 2730U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + RotL64(aNonceByteC, 59U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 12U) ^ RotL64(aNonceByteG, 29U)) ^ RotL64(aNonceByteH, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14710U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11519U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteB, 47U) ^ RotL64(aNonceByteE, 20U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10224U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15286U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 57U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererC + RotL64(aCross, 44U)) + RotL64(aCarry, 41U)) + 3339283916456813609U) + RotL64(aNonceByteH, 27U);
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 11339086426180649584U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 16819191669329316585U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 5U)) + 8361916937762630725U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 18031328374429899857U) + aOrbiterAssignSaltD[(((31U - aIndex) + 2233U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 51U)) + 18261756894092897276U) + aOrbiterAssignSaltE[((aIndex + 6388U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + 4250319792907645666U) + RotL64(aNonceByteB, 55U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1492411503643460886U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17369549067879344180U;
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7301713524358676722U) + aOrbiterUpdateSaltF[((aIndex + 2726U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 18205555540941493267U) + RotL64(aNonceByteA, 17U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9209505304067579944U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltE[((aIndex + 5902U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3441982898533162599U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8811497120829041188U) + aOrbiterUpdateSaltA[((aIndex + 2069U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4188U)) & S_SALT1]) ^ RotL64(aNonceByteC, 31U);
            aOrbiterE = RotL64((aOrbiterE * 11383709499376464085U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10080595991787801029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6822892187784299166U;
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 28U)) + aOrbiterC) + RotL64(aNonceByteF, 28U)) + aWandererUpdateSaltD[((aIndex + 4452U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + RotL64(aNonceByteD, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6605U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 60U) ^ RotL64(aNonceByteF, 19U)) ^ RotL64(aNonceByteH, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21000U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19780U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteD, 5U) ^ RotL64(aNonceByteA, 29U)) ^ RotL64(aNonceByteG, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23953U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 16812U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 10336802574069791273U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 169025388197058936U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 47U)) + 6541354188379168846U) + RotL64(aNonceByteH, 39U);
            aOrbiterH = (aWandererJ + RotL64(aIngress, 41U)) + 16223920526599306104U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 12756613707692514808U) + aOrbiterAssignSaltA[((aIndex + 1938U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 5082475548176484035U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 34U)) + 4907435526952698526U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4828U)) & S_SALT1]) + RotL64(aNonceByteE, 31U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14236627073831834337U) + RotL64(aNonceByteA, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11502511046130497584U;
            aOrbiterI = RotL64((aOrbiterI * 3460330807286625917U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3679044835550219497U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4593U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterJ = RotL64((aOrbiterJ * 8631695922983532915U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4628253464169957835U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3805U)) & S_SALT1]) ^ RotL64(aNonceByteF, 43U);
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3798386391743884889U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5869U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9816600392407327227U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 1656U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16781971616348376878U;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4807797577690520554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterG = RotL64((aOrbiterG * 9453302540675483005U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + RotL64(aNonceByteG, 8U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 2469U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 7961U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 37U)) + RotL64(aNonceByteC, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteF, 4U) ^ RotL64(aNonceByteA, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26876U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29803U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteG, 18U) ^ RotL64(aNonceByteC, 27U)) ^ RotL64(aNonceByteH, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28759U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25010U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCross, 44U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 12775735908960052604U;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 11791373812080296887U) + aOrbiterAssignSaltB[((aIndex + 3915U)) & S_SALT1]) + RotL64(aNonceByteG, 23U);
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 60U)) + 5537362877706057303U) + aOrbiterAssignSaltC[((aIndex + 2617U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 35U)) + 2023912048504189380U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 17668828109963766893U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 41U)) + 558908629933941224U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 1479633119685446888U) + RotL64(aNonceByteE, 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15460320397843364063U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10059749397555469054U;
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9987633811929693924U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3312U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 4446204415503364254U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4049U)) & S_SALT1]) + RotL64(aNonceByteH, 19U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 467U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9430197906134676162U) + RotL64(aNonceByteB, 6U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10611580584157624739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3137391249289641509U;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9327201928815412810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10675114832750356941U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 1381U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 12U)) + aWandererUpdateSaltF[(((31U - aIndex) + 1518U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aNonceByteF, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 2183U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 21U)) + RotL64(aNonceByteD, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteE, 43U) ^ RotL64(aNonceByteH, 51U)) ^ RotL64(aNonceByteA, 4U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3623U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2136U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteC, 46U) ^ RotL64(aNonceByteB, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7380U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3121U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 12775735908960052604U) + RotL64(aNonceByteH, 45U);
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 57U)) + 11791373812080296887U) + aOrbiterAssignSaltE[(((31U - aIndex) + 661U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 48U)) + 5537362877706057303U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 53U)) + 2023912048504189380U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 17668828109963766893U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 558908629933941224U) + RotL64(aNonceByteE, 25U);
            aOrbiterH = (aWandererG + RotL64(aPrevious, 37U)) + 1479633119685446888U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 44U)) + 15460320397843364063U) + aOrbiterAssignSaltC[(((31U - aIndex) + 1294U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 10059749397555469054U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9987633811929693924U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6288U)) & S_SALT1]) ^ RotL64(aNonceByteD, 22U);
            aOrbiterJ = RotL64((aOrbiterJ * 13817142288940843815U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4446204415503364254U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15106063243302192717U) ^ RotL64(aNonceByteG, 3U);
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9430197906134676162U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterD = RotL64((aOrbiterD * 14247538885252664127U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10611580584157624739U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3137391249289641509U;
            aOrbiterE = RotL64((aOrbiterE * 5462682413239873181U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9327201928815412810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7890659377013147073U;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10675114832750356941U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltF[((aIndex + 6729U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8520671775587260601U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12871947817782057116U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4324U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17152451500505815031U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6320437975845673731U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 702457937087191287U;
            aOrbiterI = RotL64((aOrbiterI * 17491257114676739589U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16629064896250312921U) + aOrbiterUpdateSaltA[((aIndex + 4403U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6054107387816339103U;
            aOrbiterG = RotL64((aOrbiterG * 6983767878966747219U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 10U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 27U)) + RotL64(aNonceByteF, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 52U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6310U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 1645U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + RotL64(pNonce, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // read from: aExpandLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteE, 43U) ^ RotL64(aNonceByteH, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12676U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12586U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteA, 36U) ^ RotL64(aNonceByteG, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15528U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12627U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 40U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 10336802574069791273U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + 169025388197058936U) + RotL64(aNonceByteA, 13U);
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 52U)) + 6541354188379168846U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4457U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 16223920526599306104U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 12756613707692514808U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 3U)) + 5082475548176484035U;
            aOrbiterC = (aWandererG + RotL64(aCross, 30U)) + 4907435526952698526U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 14236627073831834337U) + RotL64(aNonceByteC, 7U);
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 39U)) + 11502511046130497584U) + aOrbiterAssignSaltF[(((31U - aIndex) + 199U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3679044835550219497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11254838916686736746U;
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10582608424233200966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4628253464169957835U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17664454668473204465U) ^ RotL64(aNonceByteE, 5U);
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3798386391743884889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltE[((aIndex + 6059U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9816600392407327227U) + aOrbiterUpdateSaltF[((aIndex + 7861U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16781971616348376878U;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4807797577690520554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 7909676419643119585U) + aOrbiterUpdateSaltB[((aIndex + 3571U)) & S_SALT1]) + RotL64(aNonceByteB, 9U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 256053568910383007U;
            aOrbiterA = RotL64((aOrbiterA * 11965085163352053161U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16179914439220412472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3968867762761955845U;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7474832923901283742U) + aOrbiterUpdateSaltD[((aIndex + 6427U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4736994731050735779U;
            aOrbiterE = RotL64((aOrbiterE * 9839654409121414047U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 52U)) + RotL64(aNonceByteF, 8U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3578U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 1041U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 12U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aNonceByteD, 3U));
            aWandererD = aWandererD + ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // read from: aExpandLaneB, aExpandLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 11U) ^ RotL64(aNonceByteB, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19921U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 19739U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteG, 23U) ^ RotL64(aNonceByteD, 11U)) ^ RotL64(aNonceByteF, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17704U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21193U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 23U)) + 3339283916456813609U) + RotL64(aNonceByteH, 13U);
            aOrbiterB = (aWandererK + RotL64(aScatter, 39U)) + 11339086426180649584U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 16819191669329316585U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 8361916937762630725U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3677U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 14U)) + 18031328374429899857U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 53U)) + 18261756894092897276U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4906U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 3U)) + 4250319792907645666U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 43U)) + 1492411503643460886U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 17369549067879344180U) + RotL64(aNonceByteF, 55U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7301713524358676722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2985193736033012535U;
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18205555540941493267U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 1395U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltF[((aIndex + 4622U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9209505304067579944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3522631966146762306U;
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8811497120829041188U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14707301680850257294U;
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10080595991787801029U) + RotL64(aNonceByteE, 19U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6822892187784299166U) ^ RotL64(aNonceByteA, 59U);
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1981637172055758689U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8022U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16463077485583119324U;
            aOrbiterJ = RotL64((aOrbiterJ * 2876782050665869121U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8383837717361569465U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterK = RotL64((aOrbiterK * 2809163242875130677U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3529607472855930041U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4067U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8850940802020173766U;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 54U)) + aWandererUpdateSaltA[((aIndex + 5487U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aNonceByteC, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 4658U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 28U)) + RotL64(aNonceByteD, 20U));
            aWandererD = aWandererD + ((RotL64(aCross, 4U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneD
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteA, 54U) ^ RotL64(aNonceByteH, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27942U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28646U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 3U) ^ RotL64(aNonceByteG, 19U)) ^ RotL64(aNonceByteB, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25913U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31153U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 17264605017518259932U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 43U)) + 15209184354580778643U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 39U)) + 3299527965014731384U) + aOrbiterAssignSaltC[((aIndex + 868U)) & S_SALT1]) + RotL64(aNonceByteG, 19U);
            aOrbiterI = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 16293096431816127821U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3059U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 57U)) + 11031983436878828337U) + RotL64(aNonceByteF, 48U);
            aOrbiterC = (aWandererG + RotL64(aIngress, 27U)) + 9188018632448236358U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 13420816400363406556U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 3U)) + 2485063384097917101U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 46U)) + 3089135816938128264U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 10730544971770435788U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 2351U)) & S_SALT1]) + RotL64(aNonceByteE, 57U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14883796491656899074U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltF[((aIndex + 3192U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4950101626975919939U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 455U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2596253994220103666U;
            aOrbiterE = RotL64((aOrbiterE * 7181706961838582889U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17961706029559914243U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4251U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 18146616411403012772U) + RotL64(aNonceByteB, 3U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11739172334166341121U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7936637782633487291U;
            aOrbiterG = RotL64((aOrbiterG * 14940929920543800413U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3160044627483874242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16816384076887379704U;
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8101560104988710226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8851416379738817624U;
            aOrbiterA = RotL64((aOrbiterA * 16767420038937389027U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + RotL64(aNonceByteD, 59U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 53U)) + RotL64(aNonceByteC, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 38U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 592U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltF[((aIndex + 3176U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 58U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)
}

void Candidate_A::Seed(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    [[maybe_unused]] std::uint8_t *aKeyBoxUnrolledA = &(pWorkSpace->mKeyBoxA[0][0]);
    [[maybe_unused]] std::uint8_t *aKeyBoxUnrolledB = &(pWorkSpace->mKeyBoxB[0][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    std::uint64_t aWriteIndex = 0; std::uint64_t aReadIndexA = 0; std::uint64_t aReadIndexB = 0;
    std::uint32_t aSquash = 0;

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
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneA);
    }
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // invest
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneA, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneB, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneC, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneD, pWorkSpace);
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    // secure zero
    TwistMemory::ZeroBlock(aSnowLaneA);
    //
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneB);
    }
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // invest
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneA, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneB, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneC, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneD, pWorkSpace);
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    // secure zero
    TwistMemory::ZeroBlock(aSnowLaneB);
    //
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
    }
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // invest
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneA, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneB, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneC, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneD, pWorkSpace);
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    // secure zero
    TwistMemory::ZeroBlock(aSnowLaneC);
    //
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // invest
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneA, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneB, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxA(aWorkLaneC, pWorkSpace);
    TwistInvest::InvestBlockKeyBoxB(aWorkLaneD, pWorkSpace);
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    // secure zero
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteE, 19U) ^ RotL64(aNonceByteC, 38U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2956U)) & S_BLOCK1], 27U) ^ RotL64(aKeyBoxUnrolledA[((aIndex + 1585U)) & (S_KEY - 1)], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteA, 43U) ^ RotL64(aNonceByteB, 18U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledB[(((4095U - aIndex) + 1093U)) & (S_KEY - 1)], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2699U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 38U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 12775735908960052604U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7122U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 5U)) + 11791373812080296887U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 21U)) + 5537362877706057303U) + RotL64(aNonceByteE, 59U);
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 13U)) + 2023912048504189380U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 17668828109963766893U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + 558908629933941224U) + aPhaseAOrbiterAssignSaltB[((aIndex + 4316U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 1479633119685446888U) + RotL64(aNonceByteD, 61U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15460320397843364063U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5745U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10059749397555469054U;
            aOrbiterC = RotL64((aOrbiterC * 8671817118586065469U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 9987633811929693924U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6251U)) & S_SALT1]) + RotL64(pNonce, 29U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10087337844580228269U;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4446204415503364254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 339U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1226048679997253363U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 2234U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10611580584157624739U) + RotL64(aNonceByteF, 27U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterB = RotL64((aOrbiterB * 5462682413239873181U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9327201928815412810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7890659377013147073U;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10675114832750356941U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8804440385852327267U;
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + RotL64(aNonceByteG, 39U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + RotL64(aNonceByteH, 46U)) + aPhaseAWandererUpdateSaltA[((aIndex + 648U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3429U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 6U) + RotL64(aOrbiterH, 4U)) + aOrbiterI) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceByteC, 11U) ^ RotL64(aNonceByteF, 52U)) ^ RotL64(aNonceByteD, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9385U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8242U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 29U) ^ RotL64(aNonceByteA, 58U)) ^ RotL64(aNonceByteB, 43U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((4095U - aIndex) + 15518U)) & (S_KEY - 1)], 13U) ^ RotL64(aKeyBoxUnrolledB[(((4095U - aIndex) + 13569U)) & (S_KEY - 1)], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 51U)) + 10336802574069791273U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 169025388197058936U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 3U)) + 6541354188379168846U) + aPhaseAOrbiterAssignSaltF[((aIndex + 901U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 57U)) + 16223920526599306104U) + RotL64(aNonceByteF, 7U);
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 41U)) + 12756613707692514808U) + RotL64(aNonceByteB, 49U);
            aOrbiterJ = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 5082475548176484035U) + aPhaseAOrbiterAssignSaltA[((aIndex + 455U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 13U)) + 4907435526952698526U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14236627073831834337U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 1747U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11502511046130497584U;
            aOrbiterG = RotL64((aOrbiterG * 3460330807286625917U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3679044835550219497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 3798386391743884889U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 989U)) & S_SALT1]) + RotL64(aNonceByteH, 41U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1379331161819246587U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 5737U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9816600392407327227U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16781971616348376878U) ^ RotL64(aNonceByteD, 51U);
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4807797577690520554U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 1648U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + RotL64(aCarry, 11U)) + RotL64(aNonceByteA, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 18U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 2933U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aNonceByteG, 36U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5003U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteG, 39U) ^ RotL64(aNonceByteD, 20U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21056U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17751U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteB, 5U) ^ RotL64(aNonceByteA, 50U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((4095U - aIndex) + 19642U)) & (S_KEY - 1)], 41U) ^ RotL64(aKeyBoxUnrolledB[(((4095U - aIndex) + 20472U)) & (S_KEY - 1)], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 60U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 17264605017518259932U) + RotL64(aNonceByteD, 51U);
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 15209184354580778643U;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7318U)) & S_SALT1]) + RotL64(aNonceByteA, 11U);
            aOrbiterI = (aWandererB + RotL64(aPrevious, 47U)) + 16293096431816127821U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 41U)) + 11031983436878828337U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 7629U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 11U)) + 9188018632448236358U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 18U)) + 13420816400363406556U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2485063384097917101U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 2504U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3089135816938128264U;
            aOrbiterE = RotL64((aOrbiterE * 8813152992957361153U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10730544971770435788U) + RotL64(aNonceByteF, 9U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14883796491656899074U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 303U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13465877783538483706U) ^ RotL64(aNonceByteE, 4U);
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3675U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4950101626975919939U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2596253994220103666U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7737U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17961706029559914243U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10321902557977495175U;
            aOrbiterB = RotL64((aOrbiterB * 16189559888625084711U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltB[((aIndex + 2232U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + RotL64(aCarry, 27U)) + RotL64(aNonceByteC, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 10U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3729U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aNonceByteH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 36U) ^ RotL64(aNonceByteF, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27233U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26104U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteC, 29U) ^ RotL64(aNonceByteE, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30215U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26966U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 54U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 5697928251815176134U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3183U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 13U)) + 337587740689259575U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + 4927686903263973950U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 5707U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 57U)) + 3742409032569801033U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 1608092659172197650U) + RotL64(aNonceByteE, 6U);
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 36U)) + RotL64(aCarry, 13U)) + 15848744267145717509U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + 15300174177963339253U) + RotL64(aNonceByteG, 49U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14162868453323648628U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12020167069983729869U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 2429U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2071080217680099017U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16259538291658723956U) + RotL64(aNonceByteB, 29U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3722184575520553132U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5663609293306386784U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5124U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15265344442454471986U) + RotL64(aNonceByteA, 41U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1093356813820599238U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15167726103772238440U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7963U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14710892030473425181U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 397194787697553904U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7546U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14368930300818752833U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 48U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 1929U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + RotL64(aNonceByteH, 19U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 58U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aNonceByteD, 21U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 2321U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 36U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1916U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 4532U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5772U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2320U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 5697928251815176134U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 29U)) + 337587740689259575U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 4927686903263973950U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 3742409032569801033U) + aPhaseBOrbiterAssignSaltB[((aIndex + 2332U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 42U)) + 1608092659172197650U) + aPhaseBOrbiterAssignSaltC[((aIndex + 2107U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15848744267145717509U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 2513U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15300174177963339253U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 1176U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5771922862677667319U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14162868453323648628U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 2231U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12020167069983729869U;
            aOrbiterA = RotL64((aOrbiterA * 2071080217680099017U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16259538291658723956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3722184575520553132U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5663609293306386784U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 5945U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15265344442454471986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltB[((aIndex + 680U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 58U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 2407U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8748U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 8921U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11295U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 8536U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 10336802574069791273U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3064U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 29U)) + 169025388197058936U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 56U)) + 6541354188379168846U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 16223920526599306104U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 3884U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 12756613707692514808U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5082475548176484035U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4907435526952698526U;
            aOrbiterA = RotL64((aOrbiterA * 1379692095754989215U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14236627073831834337U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 6665U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterE = RotL64((aOrbiterE * 3460330807286625917U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3679044835550219497U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5746U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8631695922983532915U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10582608424233200966U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10449735026385340313U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 2897U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4628253464169957835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17664454668473204465U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 1237U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltE[((aIndex + 4103U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltA[((aIndex + 4591U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 12U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19533U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 21907U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24084U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 16952U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 3339283916456813609U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 11U)) + 11339086426180649584U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 1499U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 19U)) + 16819191669329316585U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5031U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 8361916937762630725U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 3U)) + 18031328374429899857U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 18261756894092897276U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7653U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4250319792907645666U;
            aOrbiterE = RotL64((aOrbiterE * 7053489184750217963U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1492411503643460886U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17369549067879344180U;
            aOrbiterB = RotL64((aOrbiterB * 2947354306696216579U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7301713524358676722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2985193736033012535U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 6012U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14086975808140927408U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 692U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18205555540941493267U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16967799565443938873U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7921U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aPhaseBWandererUpdateSaltF[((aIndex + 2163U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 12U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 6160U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32469U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 30407U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31654U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31372U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 12775735908960052604U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 11791373812080296887U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5811U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 41U)) + 5537362877706057303U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 2023912048504189380U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 1393U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 29U)) + 17668828109963766893U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 558908629933941224U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 8026U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1479633119685446888U;
            aOrbiterB = RotL64((aOrbiterB * 4447153373540811385U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15460320397843364063U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 4251U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10059749397555469054U;
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9987633811929693924U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 2781U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4446204415503364254U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 4072U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 783U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 54U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 5948U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6386U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7424U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6017U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1765U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 22U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 5U)) + 17264605017518259932U;
            aOrbiterF = (aWandererI + RotL64(aCross, 51U)) + 15209184354580778643U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 57U)) + 3299527965014731384U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 39U)) + 16293096431816127821U) + aPhaseCOrbiterAssignSaltA[((aIndex + 2473U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 27U)) + 11031983436878828337U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 9188018632448236358U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 13U)) + 13420816400363406556U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 840U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 2485063384097917101U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 3089135816938128264U;
            aOrbiterI = (aWandererK + RotL64(aCross, 3U)) + 10730544971770435788U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 48U)) + 10431767565618874806U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14883796491656899074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13322163435314643713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4950101626975919939U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2596253994220103666U;
            aOrbiterE = RotL64((aOrbiterE * 7181706961838582889U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17961706029559914243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 18146616411403012772U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 4747U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11739172334166341121U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7936637782633487291U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 7675U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14940929920543800413U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3160044627483874242U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 5006U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16816384076887379704U;
            aOrbiterC = RotL64((aOrbiterC * 5052772186568301951U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8101560104988710226U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3494U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8851416379738817624U;
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9941784290055185679U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14495651885701938495U;
            aOrbiterG = RotL64((aOrbiterG * 1540692851998143607U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10599676325220702167U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16092000942942971187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2457268192247656817U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16168470945107928109U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17264605017518259932U;
            aOrbiterI = RotL64((aOrbiterI * 15038386057529909273U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 60U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + aPhaseCWandererUpdateSaltD[((aIndex + 1519U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 4465U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererA, 28U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14010U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 14709U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10583U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 14658U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 43U)) + 5697928251815176134U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 53U)) + 337587740689259575U;
            aOrbiterA = (aWandererE + RotL64(aCross, 24U)) + 4927686903263973950U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 35U)) + 3742409032569801033U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 1608092659172197650U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 51U)) + 15848744267145717509U) + aPhaseCOrbiterAssignSaltE[((aIndex + 2731U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 15300174177963339253U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 14162868453323648628U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 18U)) + 12020167069983729869U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 5U)) + 16259538291658723956U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 3U)) + 8516686212464112245U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3357U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3722184575520553132U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3086U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15265344442454471986U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1093356813820599238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15167726103772238440U;
            aOrbiterC = RotL64((aOrbiterC * 5719466863561311069U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15170797965325981472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterE = RotL64((aOrbiterE * 11186808881726573677U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14710892030473425181U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 397194787697553904U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 973U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14368930300818752833U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1273724124862533034U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13018397560392545616U;
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9638716186445643730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7255587739807843785U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 3207U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6055682981584011189U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9272350563697399628U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12128124729613601747U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2285238815562202219U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3685U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15398840993074390573U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6339113298619163493U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5911895708485037040U;
            aOrbiterF = RotL64((aOrbiterF * 3271006139923200439U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7601399508218901328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5697928251815176134U;
            aOrbiterG = RotL64((aOrbiterG * 8184257916861355735U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 60U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[((aIndex + 7240U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 18U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 27U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 138U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18437U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 20359U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22905U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 21439U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aIngress, 56U)) + 3339283916456813609U;
            aOrbiterG = (aWandererB + RotL64(aCross, 39U)) + 11339086426180649584U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 16819191669329316585U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 23U)) + 8361916937762630725U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 37U)) + 18031328374429899857U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 41U)) + 18261756894092897276U;
            aOrbiterB = (aWandererK + RotL64(aCross, 27U)) + 4250319792907645666U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 1492411503643460886U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 7256U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 35U)) + 17369549067879344180U) + aPhaseCOrbiterAssignSaltB[((aIndex + 4325U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 3U)) + 7301713524358676722U;
            aOrbiterC = (aWandererG + RotL64(aCross, 53U)) + 2985193736033012535U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14086975808140927408U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5969U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9209505304067579944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8811497120829041188U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 855U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterE = RotL64((aOrbiterE * 11383709499376464085U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10080595991787801029U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6822892187784299166U;
            aOrbiterD = RotL64((aOrbiterD * 7417016898027778287U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1981637172055758689U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16463077485583119324U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5519U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2876782050665869121U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8383837717361569465U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2788511294985017326U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 6004U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2809163242875130677U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3529607472855930041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8850940802020173766U;
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7469160295100147267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16973986572163482061U;
            aOrbiterB = RotL64((aOrbiterB * 15660743778376905023U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12371372942863279718U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12098525148034303633U;
            aOrbiterF = RotL64((aOrbiterF * 11234127652230231751U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5138683482859889480U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3339283916456813609U;
            aOrbiterC = RotL64((aOrbiterC * 10975353228235695455U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 10U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[((aIndex + 6886U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 3091U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterB, 48U));
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24990U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 26762U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24623U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26994U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 34U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 37U)) + 11274974230580265396U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 22U)) + 16658438747342741547U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + 16612986966106053844U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6019U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 53U)) + 9329502236843231290U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + 14088261356708344656U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7954U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 13692608802007789581U;
            aOrbiterE = (aWandererD + RotL64(aCross, 5U)) + 6824473946645682398U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 2072915876348570040U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 47U)) + 7420507753044460759U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 4677557318688502593U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 58U)) + 15081678577055628459U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7026792817486507482U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6807734532159292872U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17882797335141303280U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5361U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9233542707022629190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1205501586581350876U;
            aOrbiterB = RotL64((aOrbiterB * 2596053290311090589U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10878718669747466677U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7824U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 861295180226875235U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterI = RotL64((aOrbiterI * 7565008208670843555U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6726642007159809594U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8061661744643240470U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3246U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6703498926835391813U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13541412083111962884U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8617442758729315637U;
            aOrbiterA = RotL64((aOrbiterA * 15471862889276160953U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16884403561131293362U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9490680911678221233U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 956U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15988763830018001033U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10486145044311386738U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10200001044821063684U;
            aOrbiterF = RotL64((aOrbiterF * 16149790736141571017U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6997073594007878034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13585783612009989767U;
            aOrbiterK = RotL64((aOrbiterK * 11425303157774550449U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3847846040256340653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11274974230580265396U;
            aOrbiterJ = RotL64((aOrbiterJ * 13970270689108369205U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA + ((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterG, 42U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3799U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 3581U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2643U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 447U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7397U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 8011U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 17264605017518259932U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 47U)) + 15209184354580778643U) + aPhaseDOrbiterAssignSaltD[((aIndex + 2588U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 52U)) + RotL64(aCarry, 27U)) + 3299527965014731384U;
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 16293096431816127821U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 57U)) + 11031983436878828337U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 9188018632448236358U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 4U)) + 13420816400363406556U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + 2485063384097917101U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 1689U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 23U)) + 3089135816938128264U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10730544971770435788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10431767565618874806U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7911U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4723078464590561545U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14883796491656899074U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13465877783538483706U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4123U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13322163435314643713U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6606U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4950101626975919939U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2596253994220103666U;
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18146616411403012772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8414050129421955787U;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11739172334166341121U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7936637782633487291U;
            aOrbiterD = RotL64((aOrbiterD * 14940929920543800413U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3160044627483874242U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16816384076887379704U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 7907U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8101560104988710226U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8851416379738817624U;
            aOrbiterJ = RotL64((aOrbiterJ * 16767420038937389027U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 10U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 7098U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 48U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 44U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltB[((aIndex + 2895U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15993U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10147U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16068U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 15016U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 10336802574069791273U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 169025388197058936U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 6541354188379168846U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 60U)) + 16223920526599306104U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4121U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 19U)) + 12756613707692514808U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 37U)) + 5082475548176484035U) + aPhaseDOrbiterAssignSaltE[((aIndex + 662U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 27U)) + 4907435526952698526U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 44U)) + 14236627073831834337U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 13U)) + 11502511046130497584U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3679044835550219497U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 525U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11254838916686736746U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6355U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8631695922983532915U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10582608424233200966U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4628253464169957835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17664454668473204465U;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3798386391743884889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1379331161819246587U;
            aOrbiterC = RotL64((aOrbiterC * 13086160171095077295U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7909676419643119585U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4497U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 256053568910383007U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6120U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11965085163352053161U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16179914439220412472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3968867762761955845U;
            aOrbiterK = RotL64((aOrbiterK * 7473632378251893139U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7474832923901283742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 10U) + RotL64(aOrbiterK, 14U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 2196U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterF, 28U)) + aPhaseDWandererUpdateSaltA[((aIndex + 880U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17866U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 24257U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24355U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24308U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 23U)) + 3339283916456813609U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 13U)) + 11339086426180649584U;
            aOrbiterF = (aWandererK + RotL64(aCross, 35U)) + 16819191669329316585U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 11U)) + 8361916937762630725U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 53U)) + 18031328374429899857U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 47U)) + 18261756894092897276U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 57U)) + 4250319792907645666U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7659U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 35U)) + 1492411503643460886U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 17369549067879344180U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 5411U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7301713524358676722U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 204U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18205555540941493267U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9209505304067579944U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 8134U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8811497120829041188U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10080595991787801029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1981637172055758689U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16463077485583119324U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6329U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2876782050665869121U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8383837717361569465U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 533U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterC = RotL64((aOrbiterC * 2809163242875130677U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3529607472855930041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8850940802020173766U;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 38U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterD, 56U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 676U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 794U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 22U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31127U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25169U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25123U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 27863U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 12775735908960052604U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 6U)) + 11791373812080296887U;
            aOrbiterK = (aWandererK + RotL64(aCross, 39U)) + 5537362877706057303U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 29U)) + 2023912048504189380U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 17668828109963766893U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 558908629933941224U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 43U)) + 1479633119685446888U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 23U)) + 15460320397843364063U) + aPhaseDOrbiterAssignSaltC[((aIndex + 4940U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 18U)) + 10059749397555469054U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6246U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9987633811929693924U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6742U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10087337844580228269U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 6873U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4446204415503364254U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterI = RotL64((aOrbiterI * 13273756657334709803U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9430197906134676162U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3192U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10611580584157624739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3137391249289641509U;
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9327201928815412810U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4691U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7890659377013147073U;
            aOrbiterA = RotL64((aOrbiterA * 13827717178378062047U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12871947817782057116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11015991745792051390U;
            aOrbiterB = RotL64((aOrbiterB * 17152451500505815031U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6320437975845673731U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 702457937087191287U;
            aOrbiterJ = RotL64((aOrbiterJ * 17491257114676739589U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16629064896250312921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6054107387816339103U;
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterH, 22U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5259U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterE, 26U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 4909U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            aSquash = static_cast<std::uint32_t>(aWorkLaneA[aIndex]) << 0U;
            aSquash |= static_cast<std::uint32_t>(aWorkLaneB[aIndex]) << 8U;
            aSquash |= static_cast<std::uint32_t>(aWorkLaneC[aIndex]) << 16U;
            aSquash |= static_cast<std::uint32_t>(aWorkLaneD[aIndex]) << 24U;
            pDestination[aIndex] = TwistMix32::DiffuseC(aSquash);
        }
    }
}

void Candidate_A::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aKeyBoxUnrolledB = &(pWorkSpace->mKeyBoxB[0][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    std::uint64_t aWriteIndex = 0; std::uint64_t aReadIndexA = 0; std::uint64_t aReadIndexB = 0;
    std::uint32_t aSquash = 0;

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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 424U)) & S_BLOCK1], 4U) ^ RotL64(aKeyBoxUnrolledA[(((4095U - aIndex) + 3683U)) & (S_KEY - 1)], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledB[(((4095U - aIndex) + 6502U)) & (S_KEY - 1)], 54U) ^ RotL64(aKeyBoxUnrolledA[((aIndex + 5698U)) & (S_KEY - 1)], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 38U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 5697928251815176134U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 52U)) + 337587740689259575U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 4927686903263973950U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5937U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 3742409032569801033U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 1608092659172197650U) + aPhaseAOrbiterAssignSaltF[((aIndex + 2194U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15848744267145717509U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 1080U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15300174177963339253U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 5802U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5771922862677667319U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14162868453323648628U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 1925U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12020167069983729869U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7494U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2071080217680099017U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16259538291658723956U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8516686212464112245U;
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3722184575520553132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15265344442454471986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 52U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 24U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5053U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 4U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4659U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15314U)) & S_BLOCK1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13978U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((4095U - aIndex) + 8822U)) & (S_KEY - 1)], 57U) ^ RotL64(aKeyBoxUnrolledB[(((4095U - aIndex) + 15288U)) & (S_KEY - 1)], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 12775735908960052604U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 47U)) + 11791373812080296887U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 21U)) + 5537362877706057303U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4015U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 2023912048504189380U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 2394U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 17668828109963766893U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 558908629933941224U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1479633119685446888U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 1286U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4447153373540811385U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15460320397843364063U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 2545U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10059749397555469054U;
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9987633811929693924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10087337844580228269U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 2698U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4446204415503364254U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15106063243302192717U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3879U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9430197906134676162U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 56U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltA[((aIndex + 470U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5682U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI + (((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20844U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20322U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((4095U - aIndex) + 17828U)) & (S_KEY - 1)], 3U) ^ RotL64(aKeyBoxUnrolledB[((aIndex + 19785U)) & (S_KEY - 1)], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 3339283916456813609U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3655U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 11339086426180649584U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6007U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 41U)) + 16819191669329316585U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 8361916937762630725U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 3U)) + 18031328374429899857U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18261756894092897276U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4250319792907645666U;
            aOrbiterI = RotL64((aOrbiterI * 7053489184750217963U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1492411503643460886U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 7790U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17369549067879344180U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7347U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2947354306696216579U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7301713524358676722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2985193736033012535U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14086975808140927408U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 785U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18205555540941493267U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16967799565443938873U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 1557U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 52U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[((aIndex + 7595U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 46U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 752U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30130U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32016U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29433U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31439U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 24U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 5U)) + 17264605017518259932U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 30U)) + 15209184354580778643U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5027U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 2388U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 16293096431816127821U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 11031983436878828337U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9188018632448236358U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13420816400363406556U;
            aOrbiterD = RotL64((aOrbiterD * 10958221259662190519U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2485063384097917101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3089135816938128264U;
            aOrbiterG = RotL64((aOrbiterG * 8813152992957361153U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10730544971770435788U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4699U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10431767565618874806U;
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14883796491656899074U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 57U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13465877783538483706U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4525U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13322163435314643713U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3307316600284371955U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 6694U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7247U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[((aIndex + 7497U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5484U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 4634U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1380U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3757U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 11274974230580265396U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 20U)) + RotL64(aCarry, 37U)) + 16658438747342741547U) + aPhaseBOrbiterAssignSaltB[((aIndex + 940U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + 16612986966106053844U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7641U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 9329502236843231290U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 43U)) + 14088261356708344656U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13692608802007789581U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6824473946645682398U;
            aOrbiterE = RotL64((aOrbiterE * 13619437545775237601U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2072915876348570040U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 2877U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7420507753044460759U;
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4677557318688502593U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 532U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7026792817486507482U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 2632U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14871665922943969918U;
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6807734532159292872U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17882797335141303280U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3185U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 711U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 54U) + RotL64(aOrbiterC, 43U)) + aOrbiterG) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 6203U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 56U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11468U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16094U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13678U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9408U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 19U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 12775735908960052604U) + aPhaseBOrbiterAssignSaltC[((aIndex + 470U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 35U)) + 11791373812080296887U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 5537362877706057303U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2023912048504189380U) + aPhaseBOrbiterAssignSaltD[((aIndex + 4361U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 60U)) + 17668828109963766893U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 558908629933941224U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4293U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1479633119685446888U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 6535U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4447153373540811385U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15460320397843364063U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10059749397555469054U;
            aOrbiterG = RotL64((aOrbiterG * 8671817118586065469U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9987633811929693924U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4047U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4446204415503364254U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 1036U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15106063243302192717U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9430197906134676162U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 18U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 1533U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 4686U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24168U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 22818U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17727U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 17512U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 5697928251815176134U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 337587740689259575U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltF[((aIndex + 7977U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 50U)) + RotL64(aCarry, 41U)) + 3742409032569801033U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 11U)) + 1608092659172197650U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 6902U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15848744267145717509U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3149U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15300174177963339253U;
            aOrbiterE = RotL64((aOrbiterE * 5771922862677667319U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14162868453323648628U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 698U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12020167069983729869U;
            aOrbiterD = RotL64((aOrbiterD * 2071080217680099017U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16259538291658723956U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8516686212464112245U;
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3722184575520553132U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 682U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5663609293306386784U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 7203U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7741U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 56U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + aPhaseBWandererUpdateSaltD[((aIndex + 2420U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25533U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 27692U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32705U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 32631U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 42U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 17264605017518259932U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 15209184354580778643U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 3299527965014731384U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4489U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 12U)) + 16293096431816127821U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 39U)) + 11031983436878828337U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5561U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9188018632448236358U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13420816400363406556U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7050U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10958221259662190519U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2485063384097917101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3089135816938128264U;
            aOrbiterK = RotL64((aOrbiterK * 8813152992957361153U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10730544971770435788U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 1814U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10431767565618874806U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 743U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14883796491656899074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13322163435314643713U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 1627U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterB, 6U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3308U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7051U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7781U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 7904U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2361U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 809U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 23U)) + 17264605017518259932U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 408U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 15209184354580778643U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 3299527965014731384U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 16293096431816127821U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6867U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 37U)) + 11031983436878828337U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 9188018632448236358U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 13U)) + 13420816400363406556U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2485063384097917101U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3089135816938128264U;
            aOrbiterE = RotL64((aOrbiterE * 8813152992957361153U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10730544971770435788U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6026U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14883796491656899074U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5141U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13322163435314643713U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3307316600284371955U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5347U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4950101626975919939U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18146616411403012772U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8414050129421955787U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3017U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14879448948196182863U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aCross, 28U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltB[((aIndex + 1991U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 6660U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 50U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB, mSource, aKeyBoxUnrolledA, aKeyBoxUnrolledB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14345U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11229U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13136U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 15178U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 40U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 3339283916456813609U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 11339086426180649584U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + 16819191669329316585U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 5398U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 35U)) + 8361916937762630725U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + 18031328374429899857U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 2605U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 29U)) + 18261756894092897276U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 22U)) + RotL64(aCarry, 29U)) + 4250319792907645666U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1492411503643460886U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17369549067879344180U;
            aOrbiterE = RotL64((aOrbiterE * 2947354306696216579U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7301713524358676722U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 2267U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2985193736033012535U;
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18205555540941493267U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16967799565443938873U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4275U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3009081009044782443U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9209505304067579944U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3522631966146762306U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 4041U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8811497120829041188U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10080595991787801029U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6822892187784299166U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5259U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 1496U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 48U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltD[((aIndex + 6789U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 4U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 42U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21996U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21097U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19726U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19732U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 12775735908960052604U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 11791373812080296887U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3749U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 5537362877706057303U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 43U)) + 2023912048504189380U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 58U)) + 17668828109963766893U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 5901U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 558908629933941224U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 3U)) + 1479633119685446888U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15460320397843364063U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10059749397555469054U;
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9987633811929693924U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10087337844580228269U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 7022U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4446204415503364254U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15106063243302192717U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7402U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10611580584157624739U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6553U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3137391249289641509U;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9327201928815412810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10675114832750356941U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8804440385852327267U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6327U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterB, 26U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltA[((aIndex + 6563U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 253U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27346U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32125U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27412U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 29590U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 11274974230580265396U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 16658438747342741547U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 5U)) + 16612986966106053844U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7317U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 29U)) + 9329502236843231290U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 14088261356708344656U) + aPhaseCOrbiterAssignSaltC[((aIndex + 7472U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 50U)) + 13692608802007789581U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 57U)) + 6824473946645682398U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2072915876348570040U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7420507753044460759U;
            aOrbiterF = RotL64((aOrbiterF * 13239288539564571257U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4677557318688502593U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15081678577055628459U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5565U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7026792817486507482U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 4745U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6807734532159292872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17882797335141303280U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 4119U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9233542707022629190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10878718669747466677U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8066049063548639241U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6673U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 861295180226875235U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterE = RotL64((aOrbiterE * 7565008208670843555U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 12U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[((aIndex + 2603U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 7406U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5108U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6251U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 386U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 4924U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 17264605017518259932U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 15209184354580778643U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 3299527965014731384U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3641U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 44U)) + 16293096431816127821U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 51U)) + 11031983436878828337U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 35U)) + 9188018632448236358U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 11U)) + 13420816400363406556U) + aPhaseBOrbiterAssignSaltE[((aIndex + 5653U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2485063384097917101U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3089135816938128264U;
            aOrbiterC = RotL64((aOrbiterC * 8813152992957361153U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10730544971770435788U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 1331U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14883796491656899074U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13465877783538483706U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 2173U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13322163435314643713U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6039U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3307316600284371955U;
            aOrbiterJ = RotL64((aOrbiterJ * 12337846092069506365U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4950101626975919939U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterI = RotL64((aOrbiterI * 7181706961838582889U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17961706029559914243U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18146616411403012772U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8414050129421955787U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7461U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aPhaseBWandererUpdateSaltF[((aIndex + 8116U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 54U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 2994U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10867U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 16135U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14177U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 13556U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 5697928251815176134U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 337587740689259575U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 53U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5685U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 3742409032569801033U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 1608092659172197650U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 21U)) + 15848744267145717509U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6032U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 60U)) + 15300174177963339253U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14162868453323648628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12020167069983729869U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 1573U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2071080217680099017U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16259538291658723956U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 4815U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8516686212464112245U;
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3722184575520553132U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 7924U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15265344442454471986U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 5348U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1093356813820599238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15170797965325981472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17826286701992981628U;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14710892030473425181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 397194787697553904U;
            aOrbiterE = RotL64((aOrbiterE * 14368930300818752833U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 2285U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 28U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 4462U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21305U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20162U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19027U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 17457U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 21U)) + 11274974230580265396U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 16658438747342741547U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 16612986966106053844U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + 9329502236843231290U) + aPhaseBOrbiterAssignSaltA[((aIndex + 8043U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 43U)) + 14088261356708344656U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 13692608802007789581U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 36U)) + 6824473946645682398U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7433U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2072915876348570040U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7420507753044460759U;
            aOrbiterD = RotL64((aOrbiterD * 13239288539564571257U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4677557318688502593U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 6516U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 1274U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7026792817486507482U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14871665922943969918U;
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6807734532159292872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9233542707022629190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1205501586581350876U;
            aOrbiterF = RotL64((aOrbiterF * 2596053290311090589U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10878718669747466677U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7548U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8066049063548639241U;
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 861295180226875235U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 1757U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9134969787937288583U;
            aOrbiterB = RotL64((aOrbiterB * 7565008208670843555U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4179U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 60U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 1935U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28328U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26572U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27239U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32413U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 5U)) + 12775735908960052604U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 51U)) + 11791373812080296887U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 57U)) + 5537362877706057303U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 2023912048504189380U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 13U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 764U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 558908629933941224U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4374U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 39U)) + 1479633119685446888U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15460320397843364063U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3093U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10059749397555469054U;
            aOrbiterJ = RotL64((aOrbiterJ * 8671817118586065469U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9987633811929693924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4446204415503364254U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15106063243302192717U;
            aOrbiterB = RotL64((aOrbiterB * 13273756657334709803U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9430197906134676162U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1226048679997253363U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6979U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10611580584157624739U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4441U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3137391249289641509U;
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9327201928815412810U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 43U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10675114832750356941U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 4684U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aPhaseBWandererUpdateSaltF[((aIndex + 2314U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            aSquash = static_cast<std::uint32_t>(aWorkLaneA[aIndex]) << 0U;
            aSquash |= static_cast<std::uint32_t>(aWorkLaneB[aIndex]) << 8U;
            aSquash |= static_cast<std::uint32_t>(aWorkLaneC[aIndex]) << 16U;
            aSquash |= static_cast<std::uint32_t>(aWorkLaneD[aIndex]) << 24U;
            pDestination[aIndex] = TwistMix32::DiffuseC(aSquash);
        }
    }
    std::memcpy(pDestination, pWorkSpace->mWorkLaneD, S_BLOCK);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        GrowKeyA(pWorkSpace);
    } else {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    }
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        printf("key b GROW [%d of %d]\n", (int)pBlockIndex, (int)pBlockCount);
        GrowKeyB(pWorkSpace);
    } else {
        printf("key b SHIFT [%d of %d]\n", (int)pBlockIndex, (int)pBlockCount);
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    }
}

void Candidate_A::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0; std::uint64_t aWandererE = 0;
    std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0; std::uint64_t aWandererI = 0;
    std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [grow key a]
    // GTwistRunGrowKeyA grow_key_a_expand_a (start)
    {
        // grow_key_a_expand_a loop 1
        // read from: aWorkLaneC, aWorkLaneD, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 60U) ^ RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[S_BLOCK1 - aIndex], 57U) ^ RotL64(aWorkLaneB[aIndex], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 23U)) + 11274974230580265396U) + aPhaseDOrbiterAssignSaltB[((aIndex + 6458U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 16658438747342741547U) + aPhaseDOrbiterAssignSaltC[((aIndex + 2349U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 16612986966106053844U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 9329502236843231290U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 13U)) + 14088261356708344656U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13692608802007789581U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6824473946645682398U;
            aOrbiterA = RotL64((aOrbiterA * 13619437545775237601U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2072915876348570040U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7420507753044460759U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4105U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13239288539564571257U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4677557318688502593U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7012U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15081678577055628459U;
            aOrbiterF = RotL64((aOrbiterF * 16659305295251177155U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7026792817486507482U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 1685U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 155U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 36U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6822U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 679U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_a (end)
    // GTwistRunGrowKeyA grow_key_a_expand_b (start)
    {
        // grow_key_a_expand_b loop 1
        // read from: aExpandLaneA, aWorkLaneC, aWorkLaneD, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[aIndex], 34U) ^ RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 50U) ^ RotL64(aWorkLaneB[aIndex], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 10336802574069791273U) + aPhaseDOrbiterAssignSaltB[((aIndex + 2855U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 12U)) + 169025388197058936U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 6541354188379168846U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 283U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 16223920526599306104U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 53U)) + 12756613707692514808U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 4260U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4907435526952698526U;
            aOrbiterE = RotL64((aOrbiterE * 1379692095754989215U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14236627073831834337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11502511046130497584U;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3679044835550219497U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5751U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10582608424233200966U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3537U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4628253464169957835U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17664454668473204465U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 2045U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 3404U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 8018U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterI, 38U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyA grow_key_a_expand_b (end)
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    TwistMemory::Zero(aKeyRowWriteA, 512U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[aIndex], 14U) ^ RotL64(aExpandLaneA[aIndex], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 37U) ^ RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 3339283916456813609U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 1430U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 11339086426180649584U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 51U)) + 16819191669329316585U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 8361916937762630725U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 22U)) + 18031328374429899857U) + aPhaseDOrbiterAssignSaltB[((aIndex + 7739U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 18261756894092897276U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6909U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4250319792907645666U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4687U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7053489184750217963U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1492411503643460886U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17369549067879344180U;
            aOrbiterK = RotL64((aOrbiterK * 2947354306696216579U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7301713524358676722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2985193736033012535U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14086975808140927408U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10390516547834639800U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 2418U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18205555540941493267U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 1168U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterJ, 24U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 2005U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 1927U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aKeyRowWriteA[(aIndex) & W_KEY1] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyA twist_key_box_loop_a (end)
}

void Candidate_A::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererH = 0; std::uint64_t aWandererI = 0;
    std::uint64_t aWandererK = 0;

    // [grow key b]
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[aIndex], 54U) ^ RotL64(aWorkLaneB[aIndex], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 26U) ^ RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 12775735908960052604U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 11791373812080296887U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5747U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 5537362877706057303U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5646U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 2023912048504189380U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 52U)) + 17668828109963766893U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 558908629933941224U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1479633119685446888U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4554U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4447153373540811385U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15460320397843364063U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6511U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10059749397555469054U;
            aOrbiterC = RotL64((aOrbiterC * 8671817118586065469U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9987633811929693924U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10087337844580228269U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5892U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13817142288940843815U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9430197906134676162U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1226048679997253363U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6676U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aPhaseDWandererUpdateSaltE[((aIndex + 1880U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4844U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    }
    // GTwistRunGrowKeyB grow_key_b_expand_a (end)
    // GTwistRunGrowKeyB grow_key_b_expand_b (start)
    {
        // grow_key_b_expand_b loop 1
        // read from: aWorkLaneB, aWorkLaneD, aExpandLaneA, aWorkLaneC
        // write to: aExpandLaneB
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[aIndex], 29U) ^ RotL64(aWorkLaneD[aIndex], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 29U) ^ RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 11274974230580265396U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 16658438747342741547U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 508U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 16612986966106053844U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 13U)) + 9329502236843231290U) + aPhaseDOrbiterAssignSaltB[((aIndex + 1206U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 30U)) + 14088261356708344656U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13692608802007789581U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6824473946645682398U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 1579U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13619437545775237601U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2072915876348570040U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7420507753044460759U;
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4677557318688502593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7026792817486507482U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3673U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3323U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17882797335141303280U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3962U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 20U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 50U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7027U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 4750U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
        // read from: aExpandLaneA, aExpandLaneB
        // write to: aKeyRowWriteB (^=)
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[aIndex], 29U) ^ RotL64(aExpandLaneB[aIndex], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 54U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 40U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 11274974230580265396U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 16658438747342741547U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 16612986966106053844U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3473U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 52U)) + 9329502236843231290U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 8136U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 14088261356708344656U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13692608802007789581U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6824473946645682398U;
            aOrbiterE = RotL64((aOrbiterE * 13619437545775237601U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2072915876348570040U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 2277U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7420507753044460759U;
            aOrbiterA = RotL64((aOrbiterA * 13239288539564571257U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4677557318688502593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7026792817486507482U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7092U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14871665922943969918U;
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 6919U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17882797335141303280U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4407U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 4508U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 6091U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 26U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 18U)) + aOrbiterA) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aKeyRowWriteB[(aIndex) & W_KEY1] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyB twist_key_box_loop_b (end)
}

const TwistDomainSaltSet Candidate_A::kPhaseASalts = {
    {
        {
            0x48A63595F374BB26ULL, 0xF34ED107BAE37FF4ULL, 0x99C4D58D5BF69BD5ULL, 0x2A3214B4CE769DFAULL, 
            0x8B34FAEF43CEA57EULL, 0x9BD43933BCF89675ULL, 0x3CBEAF4D0CE9F7B7ULL, 0x6DDAE5D5EBCEC3E4ULL, 
            0x05ACDB16C582038BULL, 0x8857875C4C020D3CULL, 0x1EE4D1FEB98FFD80ULL, 0x4BCCFE6EB9256CD5ULL, 
            0x3344CCD5F5F34FF4ULL, 0x75AFFBD1F3DC7C6FULL, 0x93396E26F79120CFULL, 0x704D141C26AFAD8CULL, 
            0x398CD73F903FD8FFULL, 0x195075AF75BC0A7FULL, 0x12B471C8A7816ABCULL, 0x7D2C0C22FB2EEC7EULL, 
            0x6820A82643DA4C82ULL, 0x7F9E4CF4AA37AA06ULL, 0x0460243EC292E934ULL, 0x4565C9C7D3ACDE46ULL, 
            0x568C199BC3302C5AULL, 0xCE9267CB071D03A4ULL, 0x8BCA2AD9813FC7D1ULL, 0xC33AF239D6498982ULL, 
            0xD5A57744DB67AD8FULL, 0x977D3EA3FD6E2765ULL, 0x64B1DCE1CD98619FULL, 0xFB67B80C0E3E400FULL
        },
        {
            0xA98B0D34090588AFULL, 0x90625E7BA0E419E2ULL, 0xE69437F68BEDB96BULL, 0x9A5284694E13DB99ULL, 
            0x66975C54563F05E9ULL, 0xF20414A7A0E3178AULL, 0x6704E1707B728915ULL, 0xE4F9E4F29130D86EULL, 
            0xD7D71F4AD9273AF7ULL, 0x63EE7D76CEDD8E9DULL, 0xA9081A27FF0AE176ULL, 0xC6EB2DFE0D0D6B54ULL, 
            0x7956325A26FD72A3ULL, 0xD4E1FB86910C0329ULL, 0x69C93398A2658112ULL, 0x686D8591939CAA5AULL, 
            0xD43F5959A29DBD98ULL, 0x21F4006294283810ULL, 0x10D86AF77B59F867ULL, 0x16EF840272D1C065ULL, 
            0x41E038B782B8F3A1ULL, 0x1650DD6EF6ABDE42ULL, 0xAFEBA0EF7A1D6F81ULL, 0xA322083548DDA8A2ULL, 
            0x76C5F1561D073CCFULL, 0x62CF2795D18E8CD8ULL, 0xCC0F0046273B1A6BULL, 0x86D4E13D6F6B36DAULL, 
            0x791070A53669E016ULL, 0x62AC1585B5C1FF01ULL, 0x5B9D6104B10B79B6ULL, 0xDB3D7DE1A571A3A6ULL
        },
        {
            0x3F829B4435849382ULL, 0x84A22D5E76124039ULL, 0xC2564741A5DB1C66ULL, 0x66CCBE126746D552ULL, 
            0xB9BA80F52C1CEC9AULL, 0x455029C6FAEEB688ULL, 0xBDD7668E44B0CD1AULL, 0xD0474CE991CE4B49ULL, 
            0x168077E24D15182AULL, 0x18591734D9DFA5A5ULL, 0xE9DFF5D27B1BC9BFULL, 0x4F74EA81B369DCE3ULL, 
            0x64CBFB6AAD0C7D0BULL, 0x835E3EE40D7D51E6ULL, 0xB1CD718F743E803FULL, 0x835EA3015A2A1514ULL, 
            0xEBEC0D56A04D9839ULL, 0x237192ECFFD99488ULL, 0x0D56813119F6B0E2ULL, 0x54377BE42D5EEE66ULL, 
            0x384D5A80E025DC47ULL, 0xE091A714D1883858ULL, 0xBF2572184C2DE2FAULL, 0x8F70E91496CC910CULL, 
            0xFDC1AE3099B01B75ULL, 0x4012C38F3EC3FA01ULL, 0xAB50D7846B22C959ULL, 0x63D2F40C1F28770DULL, 
            0x30043D9BFC998618ULL, 0x06C7F22DD7EBE4A6ULL, 0xFC345B1D49E30048ULL, 0x83BCCDA4BBD7E731ULL
        },
        {
            0x199EDC3FEF5A8F42ULL, 0x7F25CC0E113B54C1ULL, 0x1746CB26BFF5F10CULL, 0x918AD944D6C48F3CULL, 
            0x0B3FEF1ECAB243D5ULL, 0x5B11053DA7F585A0ULL, 0x8A49F885C9B42CE7ULL, 0x9418305B51AF0B5EULL, 
            0xC8947345C333E916ULL, 0x39EDB8404B3B0490ULL, 0x3FF5E1523493C4F9ULL, 0xD34294C01E730410ULL, 
            0x75F0ED6A23EF9B32ULL, 0xFDA756D5019ECCCBULL, 0x9B6E5D96C7D8CF44ULL, 0x1D36D92458B5BAC1ULL, 
            0xB4F4EB26B66A218EULL, 0xD345494B4F07A6C0ULL, 0xC3F0B412BD93E628ULL, 0xB806B8AE6FEB481CULL, 
            0x724B7E71403E10FAULL, 0x51B75E8AB329738EULL, 0x2911C520086F5A8AULL, 0x487E3DFCC06B2169ULL, 
            0x49ADE63322949205ULL, 0xAB90396DA4AD7A54ULL, 0x92A6C65E128D19C5ULL, 0x070D8311E4186C7AULL, 
            0x92F2B72CF555BFE4ULL, 0x33C1AAFE2514363AULL, 0x41184F2568CB1599ULL, 0x54FE9D362E733E14ULL
        },
        {
            0x3ED1ABEA7434EC52ULL, 0x2F9E8A99B23B0BD9ULL, 0x0B161138F92EF8C3ULL, 0x91AD6911DBF30ED6ULL, 
            0x62A90A1FEDA854D5ULL, 0x3EF1372283585331ULL, 0xBA9CBA35217A5FCCULL, 0xC04875E01812DB26ULL, 
            0x0D12CF766952ECB8ULL, 0xCC095AD0B51E6403ULL, 0x8BF42B7E5533D1ECULL, 0xCE2C192C5A602EB2ULL, 
            0x82428C05F56EDE91ULL, 0xF21275588AEEDF85ULL, 0x561E80914D773DACULL, 0xE16A334F85C2FBD3ULL, 
            0x20F4B3B1AA9E0583ULL, 0x237128F0950B59C9ULL, 0xDCBE6AD174D954F9ULL, 0x141D665E68612790ULL, 
            0x445D4938B755B252ULL, 0x225C8E46A9E8D707ULL, 0x9396BB82987B2226ULL, 0x1339CE36E27802B4ULL, 
            0x3701226BCBF48E48ULL, 0x5C4504679BB9A7BAULL, 0x69A4116531B1A2C7ULL, 0x08314A29236D983FULL, 
            0x71C3E4005914D295ULL, 0x239322E30E04A18BULL, 0x469EC55864C4AB2AULL, 0x16E8C9B390503AD3ULL
        },
        {
            0x77F1248EE916D220ULL, 0xB0703324F3B5DE6BULL, 0x896F447D83946AE5ULL, 0xE64932EE3C4C15DCULL, 
            0x15F86D13A01EB2E6ULL, 0x8468A31A399593AFULL, 0xA36D60C1BB373AE9ULL, 0xA39B2FABCE8205F7ULL, 
            0x94A6026CDC41D50EULL, 0x98A9DE0BA9086953ULL, 0x6A2B7984ED82D7A3ULL, 0x6B315D87024DA1A2ULL, 
            0x4D22274B270A12E3ULL, 0xFAE675E35F782B78ULL, 0x3FF3D30062B157B8ULL, 0x739577B708C68297ULL, 
            0x86453EB27BAE30F0ULL, 0xD7D9B8ACEC8083D2ULL, 0x0D6EB9C0D38C9F97ULL, 0x4034A689030C0FF9ULL, 
            0x58F797E129B90ABDULL, 0x64BB7FA202644920ULL, 0xCE54C360E92B126EULL, 0xF516435E2D10D0E8ULL, 
            0x0EEAB33E615ABFA3ULL, 0x52FA28B0CFA9B345ULL, 0xD2A9351C190DB4B5ULL, 0x7D9491B982F530A1ULL, 
            0xFCB1BB69E1DC66DAULL, 0x0A97833051781E57ULL, 0x25B2082DE30C8FFFULL, 0x102FEAFA4DBA069FULL
        }
    },
    {
        {
            0xB28716F2D8D73018ULL, 0x7D9461E6E96B1C24ULL, 0x534B803EB7092137ULL, 0x8810E40306C37A10ULL, 
            0x0DF2419705424211ULL, 0x70AF218A26CF88A4ULL, 0x1A368D216F90DCDFULL, 0xAB0705FD0435882BULL, 
            0x4011744DC071796AULL, 0x93AD1EFE49B7FEDCULL, 0xD11D8E7EA320F3F4ULL, 0x94989BF118A797E5ULL, 
            0x97957C7CD1C2F0A8ULL, 0x5017FFFB568FF56EULL, 0xE9F27F36889A6F7CULL, 0x5271ED6EE0ED7BE1ULL, 
            0x09971C1E10457627ULL, 0x0273312C72F8843AULL, 0x51CF989A0F641B07ULL, 0x95E587F6A5FD72A6ULL, 
            0xC16E3032266E9D5DULL, 0xB3C48ED050A811A5ULL, 0x6E0D1CA0BE1A903AULL, 0x5FBF2B3443C4771AULL, 
            0x91A75B92812BA6ADULL, 0xA5A1D18107E55901ULL, 0x5D527F6B13001CA3ULL, 0x4A6CCC845F0155D9ULL, 
            0x82ECAA0A2F065DE3ULL, 0xC9DB09121C71CC88ULL, 0x7B8436A63729D0EEULL, 0xC211704A0785FF2AULL
        },
        {
            0x10A91E0EEED8DD47ULL, 0x97E95F3CE1E634C6ULL, 0x62810891402188B5ULL, 0x806485949672EC7DULL, 
            0x84CCEEADCD40AEE8ULL, 0x1448EEA6C49F8208ULL, 0x253143A84C5727C8ULL, 0xB1085349F99DD2FFULL, 
            0xA1CC53361A875FBAULL, 0x451DB0138E32FA29ULL, 0x1F1449A669A5A43DULL, 0xBAB6AD73CFE9820AULL, 
            0xD09098D82B200B98ULL, 0x1B0EC9A70A92C905ULL, 0x479AB57992313A45ULL, 0x67B5F7B9DF2391F9ULL, 
            0x156FFB94C1BED66EULL, 0xE3AEEE18034C1B41ULL, 0x3BFD8D56012DE39EULL, 0xF23844F34E2D575AULL, 
            0xF3E75F7F0A76EA1FULL, 0x95079B9D71335A11ULL, 0xE48DBA064E68A7BAULL, 0x7B3428693DD9023AULL, 
            0xB1590AC227392305ULL, 0x3E3B743C103BC4F8ULL, 0x9D85FC84FE0EED29ULL, 0x4ED0B4BCC3839372ULL, 
            0xC8CFDA1C977DA193ULL, 0x50F531FB934EA564ULL, 0x1574453D33246FBAULL, 0xE6A04D62BF3805FEULL
        },
        {
            0x72A63C981873336AULL, 0xB8CA8F5AED18A9C1ULL, 0xDAC886359522439CULL, 0xB29B3ABF71DC683FULL, 
            0x9685B85B3B9959C2ULL, 0xC9E1B46BBC6B41B5ULL, 0x3AE8BBB5366BD53AULL, 0xB9397BF3D8A58EA3ULL, 
            0x9B5E4B4BC39C6D23ULL, 0x116187BC135C5FDAULL, 0x5A7745CB7C2009F5ULL, 0x9FE032E69EA14692ULL, 
            0x9054403715B12924ULL, 0xB12DE0C4394F6924ULL, 0x6B4D72D1853FE1E6ULL, 0x3DAED855DA4BC873ULL, 
            0x4676D63EA3B579CCULL, 0xEA57F2D72E123DA5ULL, 0xD8440F69AF4FDA3EULL, 0x79DE7F94B72FF4EFULL, 
            0x4155F1CB9BFD94B0ULL, 0x2B66DCC0A499B30CULL, 0x7D9428EBB3AFDEBCULL, 0xE3AE1AD5EC8D7889ULL, 
            0x90BC27A008649F28ULL, 0x921A0FA5C30E4114ULL, 0x818CBACBDC7DA721ULL, 0xDAB4553A510AFC73ULL, 
            0x0BDC19F30547735EULL, 0x38196AC73F92F186ULL, 0xC2B25F6721A5F284ULL, 0xC076FF494114A37DULL
        },
        {
            0xA2D71660CD51102BULL, 0xC330C16B8F23DB75ULL, 0x14A85D1A878039B4ULL, 0x55BE58D0FB6B6E56ULL, 
            0xF776C396734F6AB6ULL, 0xBE67FB79E998D5B4ULL, 0x84362B79EB60B3E3ULL, 0xEED0BC4FF71784ECULL, 
            0xB7BB44AFE6A6983FULL, 0xAAD119B07B692F20ULL, 0x4FFC7BA5B2187D55ULL, 0xFADB4595E4DF750FULL, 
            0x3DB8FA0166059EB6ULL, 0x5BF60888D3ED4A86ULL, 0x89791242256DD185ULL, 0xCF6FFDC30721DDDBULL, 
            0x427AD46ACBABDF76ULL, 0x62B662D5AFB4A367ULL, 0xD485367F7431AFDFULL, 0xB80A1834922D429EULL, 
            0x60EA72CB5133936FULL, 0x7DA7F4CEBAF72481ULL, 0x1D3E20CAF3EE167CULL, 0xD058AA91966A56F1ULL, 
            0x32B96F64AE37FB7AULL, 0xFDD42E1F05681662ULL, 0x38071514024580BEULL, 0x90878C6F2BE336C2ULL, 
            0x47742241019BD020ULL, 0x4ABF9995E213B865ULL, 0x91AFA9C3780C45D0ULL, 0x8FC81F3BB71A8451ULL
        },
        {
            0xBB7C43544F1609AEULL, 0xA63B376F8D4DCBF2ULL, 0x62B9D72A585E534DULL, 0xA1FE39C6B40E7C88ULL, 
            0x479DB7E9AC8579E7ULL, 0x459F5A3AC0B5D7D2ULL, 0xD7B774D22DA4EB16ULL, 0x5253C24B94A6E245ULL, 
            0x250E7018EE615FCCULL, 0xE9A82D8C66E9DBA0ULL, 0xCF8D1E87AC13EDFEULL, 0xD2E6B0D54C8CF67EULL, 
            0x264F668FA7234E6DULL, 0xDD480BF27B9A28E4ULL, 0xB2753B1E51150967ULL, 0x263A811797DE9E73ULL, 
            0x086681C5EBC23130ULL, 0x8C3B792AAEBF8404ULL, 0x8EE051FFFAD50D59ULL, 0xBB97631BE22A7978ULL, 
            0x796E485A4E26151DULL, 0x167DBF9881006FACULL, 0x5EE7EFBFAFBC1D04ULL, 0xF225887F0E9014C0ULL, 
            0x6D86665CAA7B1AB4ULL, 0x28B8781281911826ULL, 0x8D20E0F2BEB9F78BULL, 0x947CE361736B3A5EULL, 
            0xEE90ACA3389A5A42ULL, 0xFEE2928115DB7B17ULL, 0x0211FE62A8EE0766ULL, 0x855D15C931D132D1ULL
        },
        {
            0xF47389839B868D42ULL, 0x2529AF6266229A9CULL, 0x5A9D4D7D9B683BCBULL, 0xBE8D8DE19A625189ULL, 
            0x118F245E82B57ACAULL, 0x5FECD44D8EB5EECFULL, 0x15840DC5BE3C73D3ULL, 0xAA70B58D6200FAECULL, 
            0x916FAD85F136E217ULL, 0x927740775B31C824ULL, 0x30CDE8E331779A97ULL, 0xC908781F5F5C1296ULL, 
            0x066B4FF4A42CD285ULL, 0x3BAE58B15B5014D1ULL, 0xBB616F216D11E2E9ULL, 0x0A349A0022B46487ULL, 
            0x6BC2427A24B639A6ULL, 0x16752A1B5611BD2AULL, 0x9482196A74D6A607ULL, 0x29A46A1D766FDED4ULL, 
            0x638CE53CC1C635C6ULL, 0xAF138F66E8E15778ULL, 0xF579E5D7D7BF904FULL, 0x69A62F93931C6619ULL, 
            0xE31C49EB5611A39CULL, 0xDF585129809BD08AULL, 0x60DDBD5C587A6136ULL, 0x1808554AAA69D26DULL, 
            0x11C695B68FC3274AULL, 0xB3EBA12008AC9E39ULL, 0x439CEA4FA2F56392ULL, 0x0F40F5FB5DFBB61FULL
        }
    },
    {
        {
            0xFCC30A67E76EF591ULL, 0x5CD8D6D62B3BA2B6ULL, 0x1471F7D34A2B2B60ULL, 0x016875B772A651ACULL, 
            0xC26E992AC99BA461ULL, 0xDBEF186D30A4A4F0ULL, 0x16A6675251F08731ULL, 0x946C90626332BFB3ULL, 
            0x1C26E5CD5B798EEAULL, 0x3601144E255ACDFEULL, 0x339A4F7E5E40E7CDULL, 0xB6D66A0C2AD2F622ULL, 
            0x37D6D320D7B67ADEULL, 0x431F852EAE68C570ULL, 0xBD078E62B619F0CEULL, 0x4B87A4C537DA360DULL, 
            0x7A570FAD08713F73ULL, 0x345FB46CE624F5CAULL, 0xBD7D6153B7352CDDULL, 0x2EB76431C5114A6DULL, 
            0x82AC9ACB1DD4AC82ULL, 0xDED9633B154BCC62ULL, 0x2E8DAB3C0E41918DULL, 0x72407947F619226DULL, 
            0x352BD183A7259245ULL, 0x7FA7C334682A059DULL, 0x6E9BF5815F187B62ULL, 0x5D9A038FA68ED13DULL, 
            0x1B0BD4FD5D7E8978ULL, 0x8E46C83310728F17ULL, 0x35A88846E77D267EULL, 0xDB5F6012D5F3AB48ULL
        },
        {
            0x5FF02DCCCAFE68A6ULL, 0x769722EE70CB807DULL, 0x2907E5D1BA5D9774ULL, 0xD6EE282BD48D53D5ULL, 
            0x6D6388BEF06F6A34ULL, 0x2AE165DED2E3B08EULL, 0x783945D52590482DULL, 0xF8AFC93F5865E42DULL, 
            0x5483467E1EA68281ULL, 0x3380C79D69D415B4ULL, 0x84FF56E379CF8D38ULL, 0x86DD287A47EB99EDULL, 
            0x6F566302E92D305CULL, 0xD28A00A48C1AA3C6ULL, 0x82A062006F64F02EULL, 0x59422461C5CD9425ULL, 
            0x2AA64AB49EEB7371ULL, 0x327166CB0D095C22ULL, 0xF5F7E60A485EB594ULL, 0xFDBB091652E0F049ULL, 
            0x1DB70E11D9456C47ULL, 0x59F986F1C4016D16ULL, 0xF71A4FFCB13EB60CULL, 0x2C03DE5637AA8F29ULL, 
            0x99C3A1D216E61E2FULL, 0x0BE20B9582A04A48ULL, 0x9407350D50CA6470ULL, 0x2ED45BD0E06E8D07ULL, 
            0x0BD33C7727A30C26ULL, 0x4F3956F1C70D11A0ULL, 0x4B0F3A30774E71C4ULL, 0x7F55B08740A620C2ULL
        },
        {
            0x43E8F33C02357007ULL, 0xAC58B83D9FB69BC7ULL, 0xDC11696B141E6A84ULL, 0x982706089D1A3286ULL, 
            0x8B7060DE06349225ULL, 0xFA629BEA4E32EED1ULL, 0xB5F0E263DAB94BC4ULL, 0x5D15B7CD4C1D8D69ULL, 
            0x91EDCF0D0E00AB55ULL, 0xD9750FFE995386DDULL, 0x6C9C0DD0F5A1CF81ULL, 0xDCD08DE536C0D9D4ULL, 
            0x59F7E7937D241AA5ULL, 0xB89D1C1236E68FACULL, 0x65211F973C4D2473ULL, 0x4A66AF081A2E5BBEULL, 
            0x09C16B602C431D2BULL, 0xF5D09385B508D5A2ULL, 0xA1E1C76C17E4344DULL, 0xB1B6341A343F7B6DULL, 
            0x56A20D40765DCCDCULL, 0xEBA581EBFF6B6961ULL, 0x3D2BDA65D70F1E1BULL, 0xCB070B5B2FA2C7F5ULL, 
            0xD99DA78DAF6A269CULL, 0xA4964732C67AB28EULL, 0x04EF4B7FAB54DA5BULL, 0x7218D09211D1F71BULL, 
            0xF8A444AAAC875C3BULL, 0xE18AC57228CF16E9ULL, 0x5985779EC02C0E88ULL, 0xF1271B6FF8A83531ULL
        },
        {
            0xC913C496804F6EA3ULL, 0x67537A8167BF770DULL, 0x2FF18726375E062DULL, 0x5F273AFE94FE73B7ULL, 
            0x4CA6F7A24B40E791ULL, 0x28DC25EB656EEBE5ULL, 0xA7070BF4BB69D09DULL, 0xB952D9F8A3473500ULL, 
            0x565411A29AC77750ULL, 0x6E5F85EB95D386B1ULL, 0x8C54A0292A0965D5ULL, 0x8212ED00F437875FULL, 
            0x7391DF2A95954063ULL, 0x5B5B08E58BBCAE5FULL, 0xC96F218DFD465378ULL, 0xCB4D2EC3906C59B8ULL, 
            0xAF0D5B1E64E3C63CULL, 0x20261608A83AC2D6ULL, 0x1CFAFCAE01B0E1F8ULL, 0x401675D5635E4B32ULL, 
            0x30202C5F33CE9D7AULL, 0x2EFA36546EF02D90ULL, 0xFCC1B0F54AE6A034ULL, 0x62B5484783254EFCULL, 
            0x8E30CCEA07269873ULL, 0x482FC3DAEAEDEF09ULL, 0x2ED8133FD03473ACULL, 0xA75C4CD72910324BULL, 
            0x59BEC28FB1BB1F78ULL, 0xD332C300B1323CD6ULL, 0x597F398C95C0AE73ULL, 0xF5B61072DF15C42EULL
        },
        {
            0x50DCC2B5DE4BF74AULL, 0x989D5EA9D7550D5CULL, 0x93720E6F0E7220CFULL, 0xBC5F948D621EFB9CULL, 
            0x87B46EE21F3B3866ULL, 0x00F3F5FAF57DE21EULL, 0x3A3945846A71B814ULL, 0x0DE75FA80EA64B78ULL, 
            0xC0C311CB7084A455ULL, 0xCFE6D94D65EF5398ULL, 0xD858101EA987B52AULL, 0x7411E868E4976613ULL, 
            0x727BC78DCDAC65ECULL, 0x8B2AFB78F4AB775DULL, 0x1C2BCFD1A12A6577ULL, 0xF669C12446BF6ED9ULL, 
            0x2E55F0380B63F3F4ULL, 0x87EE5BDA51422672ULL, 0xDFC407DDC4DFE987ULL, 0xE2B9348C189D6E2EULL, 
            0x355F9F0BDAD1AD1AULL, 0xAB4DC22A857AB824ULL, 0x64C512740BB1C502ULL, 0xBFB71846D045B84EULL, 
            0xCB224C1AA3BB46D9ULL, 0x8AA6013EAFB0F17AULL, 0x9686FD72AA5FDA0FULL, 0x44E892DBBCCCD7ADULL, 
            0xAB439939B6578A80ULL, 0x66D8F975BF0F1059ULL, 0xABE8668BB374ACDAULL, 0x576E82D5C70CD858ULL
        },
        {
            0x747F2834ACEB7390ULL, 0x903FFD617D22178EULL, 0x3E7BF2F17706E807ULL, 0x6090D7B6DA60F25AULL, 
            0x7342AB55016A6A02ULL, 0x679383E506DC4B97ULL, 0x0E21039B47D8E591ULL, 0xD3E3458ECC53E9DDULL, 
            0x2BB57BF7B9D24B17ULL, 0xFA8CE190022A9BEFULL, 0x65D2AB0154FA8CFAULL, 0x957746AE841E42E5ULL, 
            0xD6401BD8B36F5207ULL, 0x1DB5B63C6E19D0ABULL, 0xDBA7F48F08A2181CULL, 0x972A1B8643FB9B8AULL, 
            0xADB38C927EA92F18ULL, 0x1977E323830758AEULL, 0xA7C88EFE49BC45B1ULL, 0x7DC1BBFC60EFC328ULL, 
            0x0B9E81B5023D80E7ULL, 0x64322FCFE69CED6CULL, 0x6BCAAE332567913DULL, 0x65B809A02CD9B85AULL, 
            0x94E4ECC6C04310BEULL, 0xC8500B6AE9FE6FAEULL, 0x6651CD10B54D70CFULL, 0xE12CF380FF1926B8ULL, 
            0x186D46F1C59BD763ULL, 0x8C3E80101ECC351CULL, 0x8F73DAE242B3CACEULL, 0x07E0EBB06E9CCFA0ULL
        }
    }
};

const TwistDomainConstants Candidate_A::kPhaseAConstants = {
    0xAA04AC31BF160B3BULL,
    0xDF8717AFC3133CA6ULL,
    0x96DDBB6A946206C5ULL,
    0xAA04AC31BF160B3BULL,
    0xDF8717AFC3133CA6ULL,
    0x96DDBB6A946206C5ULL,
    0x8C84753F29A6F63DULL,
    0xF503353D18BF6631ULL,
    0x84,
    0x35,
    0x0B,
    0x5D,
    0x40,
    0x7A,
    0x6C,
    0x47
};

const TwistDomainSaltSet Candidate_A::kPhaseBSalts = {
    {
        {
            0xEF2200E50A9F8D66ULL, 0x9345E958978154B6ULL, 0xFB9D0787605850B1ULL, 0xF74FF4D1717582B9ULL, 
            0x529D7CE80BABAD77ULL, 0xBF62FEC473AADDA5ULL, 0x184E2A0CDA12FA32ULL, 0x4D66D209825B69DCULL, 
            0x9E07C164C6147CB4ULL, 0xA5B3E0563B37A5B7ULL, 0x9D733078A3FD071EULL, 0xEC38387684810BD4ULL, 
            0x3360D572E60D3896ULL, 0x68B8056C58F03B7AULL, 0x432221A2660452C7ULL, 0x2E99DF22E5330619ULL, 
            0x379444158CDBC53CULL, 0x63D478CED0E7583AULL, 0x73985625D24E86BBULL, 0xCFD3795DC1CA8D2FULL, 
            0xEEF859D01290951EULL, 0xDBA04AF3092BA072ULL, 0x9587D7D84A0FDAA0ULL, 0x3441ED92E8C2B476ULL, 
            0x7869C230FEA137B2ULL, 0x677CACFD3D36C01EULL, 0x24CB36739CB3DF4FULL, 0x06AAFB0B6ED38706ULL, 
            0x0A79B0480CBBAAC3ULL, 0xAC8CDA17F0DBA7E6ULL, 0x8477423D80F8CB1AULL, 0x6C4616FDEA4DF6FBULL
        },
        {
            0x5950AAA4D77FC3DEULL, 0xB6FE5DFE136833AAULL, 0x8F55CEFDE79278F6ULL, 0x4F897FC68AF9FDAEULL, 
            0xD565539C051D7954ULL, 0x88C3E2D0BB3C4349ULL, 0x1C4EECBD47D7A702ULL, 0xBDE772F7723F8C1AULL, 
            0x886FECA33E2ED3B3ULL, 0xE85B9774CDE7D58FULL, 0x9677E720267EE2EAULL, 0x5C41DF8D62D73BF1ULL, 
            0x98C98914ACF0F926ULL, 0x9759962E40728214ULL, 0x1CEC4FD68B2796BEULL, 0xB2D74349C148A7E1ULL, 
            0x7FF9F9B23DC213F6ULL, 0x041B4A6EDC02AD89ULL, 0x575C446AA549C4B9ULL, 0x463B6F660315A55BULL, 
            0x9C05F312B5D666D8ULL, 0x8B0D23170AB167A0ULL, 0x2841967A97A51EB7ULL, 0xF386CD3E8D3928A4ULL, 
            0x5338DA8D35A9BB46ULL, 0xD64F6BCF35A932B8ULL, 0x501E8FDFB4FAAEBDULL, 0xA484F5C56FF70958ULL, 
            0x6905FD790A004A31ULL, 0x100424ECCE24E950ULL, 0xDF2B05AA7FD119C4ULL, 0x22A4F64A1E172288ULL
        },
        {
            0x4C8213AC20E36BF9ULL, 0xEA8C30C54051C1A0ULL, 0x2775D542F16EC044ULL, 0x4585B6675B11455DULL, 
            0xE12E63970C5CB1A7ULL, 0xA2D8A7CAB9F41014ULL, 0x27BCB433FFBA04FCULL, 0xEE6E832EEDDF95A9ULL, 
            0xF6CDA4E551F7F9FDULL, 0x6C7AFA2AB27B7B85ULL, 0x80B6C50F5B72AC85ULL, 0xEBB499B70EDFD033ULL, 
            0xACE8664610EAA3F9ULL, 0x80D20080496EF24EULL, 0x76D51EBABCE53185ULL, 0x1805E1A36F95301AULL, 
            0x924CFF7A73CD1C7EULL, 0xC23DE41696BD00B7ULL, 0xCEFC939715599A7FULL, 0xA02EFBBDF94732A2ULL, 
            0x1BAA8323F8FF7BC4ULL, 0x6783E8DF46DB464CULL, 0xE0CF82B794B2F80EULL, 0x3BCE331DED0A3EC1ULL, 
            0xBF502B352319CF81ULL, 0x9E0598C41141CE1EULL, 0x4A2507ACD2FF2552ULL, 0x21FA34F9630DB21CULL, 
            0x4C73F09373415C5BULL, 0x3833835EACAC4BEBULL, 0x237EE8702099166EULL, 0x5B58BC6F17E028C5ULL
        },
        {
            0xF33768C2F32028F8ULL, 0xA22067F335331876ULL, 0x7D39770FA3636CA6ULL, 0x02B9F4C6970C4875ULL, 
            0xA72EE53B568A002FULL, 0xDC51C07C205DDA64ULL, 0x3FD08B8E150CDCC1ULL, 0x8473810D86CD6282ULL, 
            0x103B2A3217858F49ULL, 0x94818985E73B99A1ULL, 0xBE0224D409F854EFULL, 0xCA3CE98105038BA1ULL, 
            0x5483A312805343FAULL, 0xD75290A1C1D4441AULL, 0xC829C1A15E247D33ULL, 0x1C48D0A9F1189F9AULL, 
            0xE6934A7BB2CA8AB3ULL, 0x81B1776022C6F3EAULL, 0x59A8CC876D0C10E8ULL, 0xF530615431D972BDULL, 
            0x7CB391B778A20383ULL, 0x4EE68D82699176F0ULL, 0xB4E87BBABF2EF220ULL, 0xA4236D6B81008011ULL, 
            0x8046AA4844FE78B2ULL, 0x72CCB8C40E2B683BULL, 0xA67BEFD2B27F32E1ULL, 0xDCD6CC14063A5C72ULL, 
            0x13DD4CE4D9B5E4F7ULL, 0x9FBA4675DEFB9537ULL, 0xE85D66B4DC54E1BCULL, 0x584893F00DE18A7DULL
        },
        {
            0x01DBB372B84781B2ULL, 0x8F7BD11C47E07411ULL, 0x85079DAFA65BF7A1ULL, 0x23EB80CF2997B409ULL, 
            0xAA3001874BEEE16BULL, 0x27B36AD011772DD7ULL, 0x1574401F48766231ULL, 0x9EFDA08D1269E4FBULL, 
            0x836C12EF642BB17CULL, 0x449BCC1E5DA5F6E0ULL, 0x42D5A4888D71B450ULL, 0xCA3555DBE5FDD440ULL, 
            0xC905D9AE4A9B88C5ULL, 0xC8A7E1CE7138A207ULL, 0x7BF4614D42CBD496ULL, 0x665C4C74560298F4ULL, 
            0x5BD3F4A2E0141F0CULL, 0xB0FB32CAB2468F07ULL, 0xCCC6F3177999BA0CULL, 0xB9C9F965A463F273ULL, 
            0xF8456CD24F0B1737ULL, 0xA09E217BA7461252ULL, 0x7990B4C9CA929708ULL, 0x0E9056228F2EAF57ULL, 
            0xDAB9C53FFAF8E0F7ULL, 0x989035C09368206CULL, 0xE519637F23433C48ULL, 0x6716F6F6611792ACULL, 
            0x9CD47D0E4CC13913ULL, 0x9365CD64691A0B52ULL, 0x5D213460C1BC26D8ULL, 0xD4CD276286E6B7B7ULL
        },
        {
            0x8C69EDE50379E7DEULL, 0x1A0481E9AB53B247ULL, 0xDBF88F0535DAEBA0ULL, 0xBA74FF5804641639ULL, 
            0xA391BBB044A795AAULL, 0x8A116E3B6E9ECE99ULL, 0x3DD916289D078954ULL, 0x70A14A0B00AA3023ULL, 
            0xE4A3E3E2063A8EBBULL, 0xFED387198D971F91ULL, 0x5E7D5228D237667CULL, 0xBC4362213F57E387ULL, 
            0xCAA7164020029477ULL, 0x573CFAECA2DC2B0DULL, 0x6B1A405EE5DE7042ULL, 0x2104859B27C12B34ULL, 
            0x933212279DA83F82ULL, 0x362C456700BF05FAULL, 0x4782461D1D46F0EBULL, 0xC09E52C4EA1AF1A5ULL, 
            0xEC127BC318A0CD38ULL, 0x52D7515EBBF3BF95ULL, 0x10D760B3571B9C13ULL, 0x37D61DBE2E4F664DULL, 
            0x1E0C4A76D40032DCULL, 0xCAA1CCE7548B8F05ULL, 0xFC8012732685190EULL, 0xBE07C3258C86EB6DULL, 
            0x83AED0DE2AD42D66ULL, 0xBE27295A8343FAA1ULL, 0xAA910E645EE83499ULL, 0x366EA686D58E51B4ULL
        }
    },
    {
        {
            0x85CC5B3FE82DF6CFULL, 0x1042033D9258DDDEULL, 0xD3F5C26350E83185ULL, 0x3240AE5C6E918FE5ULL, 
            0xA9745B77757934A0ULL, 0xD0B409BDEDCF377BULL, 0x2757468DA6EE42DEULL, 0xCA327A28ED6C3520ULL, 
            0xA1470E700CCAD4FEULL, 0x79949386BE53785BULL, 0x066703E2785D21E6ULL, 0x0BAF2EF0FB624445ULL, 
            0xE57D70CEF8C4C6B6ULL, 0x1F1F26F62585B1C4ULL, 0xA08CDCABF0827DA4ULL, 0x731584E9544EC616ULL, 
            0x05E371EB9F6616A4ULL, 0xDE7A78583039D5B4ULL, 0x4CBFABAB0597B634ULL, 0x90DE71B50BAB0B27ULL, 
            0xFCEA7068398B89F3ULL, 0x0B7A18A81A7E72D2ULL, 0x8CA12D212F459FCBULL, 0xAB694423B7717C13ULL, 
            0x16DB6467EC7E5F5AULL, 0x7424FB56D1F1A08AULL, 0x30859A25B46539B6ULL, 0xF8175D56882CDB8CULL, 
            0xB6FBBCAB856C38A6ULL, 0xED5D4F1286A7A431ULL, 0x98ADD7E327523AAEULL, 0xE1CE053E8F43E742ULL
        },
        {
            0x241CDBE2B047F727ULL, 0x7B64B09D526E48E5ULL, 0x101C139AF9D76F4CULL, 0x20AB472F59CF77B8ULL, 
            0x4CB77DA3312DC63EULL, 0xE21FE9EFD74C7E94ULL, 0xE28AD4D6763DD872ULL, 0x91ABA8805ABDD8A5ULL, 
            0xCE98D94F21668486ULL, 0x7E03E8609D4B4A5EULL, 0x98D96D2E3D9E9771ULL, 0x73D603ADBA757476ULL, 
            0x008C9C07FA094150ULL, 0xC9F6A9832D269AC2ULL, 0x4D7997571A37870BULL, 0x3859F6B6F68F152DULL, 
            0xCBCAA2DB323A4015ULL, 0x33408CEAD197547BULL, 0x7A55F835AEBD1A3BULL, 0x17993884CE7287F5ULL, 
            0x97FB22928C9C0C73ULL, 0x258BB9AF83A81F5AULL, 0x68FEEA120C417410ULL, 0x201447083D36D66CULL, 
            0x81F600EC96F27BE8ULL, 0xFA5D590A161A2D0CULL, 0x5BE2E764B4073F8BULL, 0x0A559DDF7DCF49CCULL, 
            0xB01A7C9F6A0FF6E5ULL, 0x4AE66CE70498C52DULL, 0x2540BFE393DD2037ULL, 0xE894E3EF5DE4F45BULL
        },
        {
            0x99FF957981BA2983ULL, 0x46404C1C3CD63CF2ULL, 0xCFBB7EB780080AFFULL, 0x377D49810E909302ULL, 
            0x7CE1417B7726CC7AULL, 0x7F0AD97FBD95CE63ULL, 0x2BCD0DB7D39E7137ULL, 0x69E682EAFD02678EULL, 
            0x6DE033A17F59295CULL, 0xB58BA2AA765A2B51ULL, 0x1B37C461725AE0FCULL, 0xB6D2D38C0377F490ULL, 
            0xCCBC6958047066F0ULL, 0x0B3AE539BC26802DULL, 0x11EF9A02DFF4C50BULL, 0x03706FD28F19AC72ULL, 
            0x8755ED385898D795ULL, 0x9E445368A5D7DC71ULL, 0x41D53D399A2AF6EFULL, 0xAA60639DB7DBFC71ULL, 
            0x2D882F578C6E5FF8ULL, 0x5308FCC7C6AB78EFULL, 0x3FCCDC544175A7FDULL, 0xDF877F49FE38B1F2ULL, 
            0x6C4E4F85322D1EF0ULL, 0xE83AB7D82C1D866FULL, 0xBDEB2C42A8BAD659ULL, 0x202EED1084CCE3DCULL, 
            0x134643FA3DE6BA05ULL, 0xEE3160679FDBDC4BULL, 0x4FCF230ABFAC90D3ULL, 0xEB799ABFFF874E11ULL
        },
        {
            0xE54F08334806EAC3ULL, 0x526B3A9D75486C3FULL, 0xC77BEC333EDC44FEULL, 0x527B7D7530C6EA43ULL, 
            0x341464338AD66BE0ULL, 0x64BD45E69EB19553ULL, 0x84DE4FE3EEBFD23FULL, 0x72B418D0146B9049ULL, 
            0xFDE57A51CCD08138ULL, 0x7E730A9A66B3106AULL, 0x0EFEC2C2B2C78AB3ULL, 0xEB4449FD205868DBULL, 
            0xA394169214001E28ULL, 0xAD6E5607705AB659ULL, 0x4B2C46302AF9B2F0ULL, 0x61B69EE0F479EA77ULL, 
            0x54C2BE40DEE166F1ULL, 0x24C81C8CF53C8E0BULL, 0xE95E7E109C1EE5B0ULL, 0x1F00BB0121A3BABCULL, 
            0x830669889BC2CC92ULL, 0x1A9561BE775BACE2ULL, 0xC912BCAE11E9BB5EULL, 0xF1C2C9B6FE879004ULL, 
            0x630C32B5CDF06521ULL, 0x21BD389D9681409EULL, 0x7C2ABB5A7BF1FF8BULL, 0x0356A0180D20F549ULL, 
            0x1659193352025E27ULL, 0x3D3648BA8B9314A3ULL, 0xDD1C3485BBD8E4AFULL, 0x49A463D24E45155CULL
        },
        {
            0x03422C51F4BDA81FULL, 0xF0D161DB2D9DDAE4ULL, 0xCB5BB0B715E72C8BULL, 0x9F5B3DC529D19056ULL, 
            0x52E3541F41DC9D44ULL, 0x1FEFA3B1E41B2F29ULL, 0xA0AC9CDCEB69A112ULL, 0xD6467AFACA05C94DULL, 
            0x7A2BFEC46ABDCD34ULL, 0x7ABED93E0ABB3618ULL, 0x4136DD44777D380AULL, 0x5172E27004D3C550ULL, 
            0x2B663C52E27A10C9ULL, 0x759CF184C52E799CULL, 0xCA93FB4D2CCE3B4FULL, 0xEC1DB8FFF18FE6E6ULL, 
            0x1B515191A845EEF7ULL, 0x78A5CC20DBE37E81ULL, 0xFD715906E41D00FEULL, 0x89AFAF1127E2A03BULL, 
            0x66F416396F28F23DULL, 0x2AB1B97A87EE8702ULL, 0xA604990D155965A4ULL, 0x37910562C0F12364ULL, 
            0xD9CCCAF3678A12F3ULL, 0x4906C5709BC562E5ULL, 0xBED5F63BD3120C68ULL, 0xF549CA16065CD390ULL, 
            0x999F2E06D3DAEC44ULL, 0xDB9193DD7BC6CA75ULL, 0x92D50F06A2C0494FULL, 0xA58A551066CD0073ULL
        },
        {
            0xEB206EA997F5C1C8ULL, 0xDC2F3A96099F125EULL, 0x94B0A6B2CB609A4FULL, 0x2B3B3CDE667417A0ULL, 
            0x2820FD3D798D1254ULL, 0xDE3C10435E89F4B1ULL, 0xD355FC90F5F1B4ADULL, 0xB765F6F25697CB98ULL, 
            0x9EB8B0269383C189ULL, 0x6AD3A4D3B190FC08ULL, 0xD7FAFC5C714C9592ULL, 0xF75853E68A2252B9ULL, 
            0x44C1DF025D064A9DULL, 0xC88FDCB312FFD491ULL, 0x7842764393E91EC2ULL, 0x9754DE1A95E89DBEULL, 
            0x6E7DAA53EDEE747DULL, 0x6AF76B3D76E097F3ULL, 0x9CA667AE16B984E4ULL, 0xF78696B8E2B42865ULL, 
            0xF0D156B6507608CCULL, 0x93ADC46F6B52B1D8ULL, 0xFD1E608D8A65C75DULL, 0xFF5BD5BE42DA151CULL, 
            0xA44DAF3CE43C004DULL, 0x4EEBA0D2146C21CEULL, 0xC23BFBB9B5326769ULL, 0x468D0EEF3B76306CULL, 
            0x4C04DFB8387FD386ULL, 0xE79FC0065179C755ULL, 0xA8138E1EFD26F1BAULL, 0x7D31CF2BE0B498E0ULL
        }
    },
    {
        {
            0x078B93871F07CD51ULL, 0x2E98C6EAE0957167ULL, 0xB8AD9D70B0FF03C2ULL, 0x9B31FD6E8E5213B6ULL, 
            0xACEE498097D982FDULL, 0xE5073AE36BC4ED75ULL, 0x72DE94CB8763A111ULL, 0xCD7D5ACB695D9877ULL, 
            0xAE43533CBE6220E8ULL, 0xFCEFFA6E1CC5BB1BULL, 0x55FAF18AD32E2832ULL, 0x497EF8D560B12D8BULL, 
            0xB2D0EAD29256CD2AULL, 0x56EDD083BB3E86FFULL, 0x6366DDB4BAD076F3ULL, 0x30701DCDD2C58AE0ULL, 
            0x3B88D4B2CB97A249ULL, 0xAE8B180F7693614BULL, 0x5FC45486AD8BAFA3ULL, 0x286DB793FF4F743DULL, 
            0xBEA0AE95AC746534ULL, 0x1594FFB0EEDF5FE9ULL, 0x15AA17A7D713949FULL, 0xEC64A8A3343BFDBDULL, 
            0x151DDD10E75EE3F8ULL, 0xF87AF091B5FB51BCULL, 0x5A4FA87AED5A2986ULL, 0x65BCBBE6F36F450FULL, 
            0x9C1C0DF6D1144A4FULL, 0xBCB6F8E997534ABFULL, 0xE37EB8B463E1875DULL, 0xB8D8BA2C48CE6825ULL
        },
        {
            0x181FF384E6D5694FULL, 0x334E056BEC621F40ULL, 0x492631AAE955A1E7ULL, 0x7932822BA1CEBC50ULL, 
            0x20400E60CCB567CEULL, 0xC6F7FC76E1F7B11DULL, 0x70A67030F6A535C3ULL, 0x822B5CC74D5FF4B5ULL, 
            0x49922BC2258FBDC9ULL, 0x191C900F9206D1DFULL, 0x393E072D166A3879ULL, 0xB6E6BECC1F84868FULL, 
            0x45108CFF2D736641ULL, 0xBD0A4D627A4DA66FULL, 0xFE6A7C5CB416C598ULL, 0x4544E94B258FCDBFULL, 
            0xD7BECE973378B4B7ULL, 0x8BA17AB30AB47815ULL, 0x0F4E779019AF2D13ULL, 0xEEFB965B850E835AULL, 
            0xA2F488BBBF3D5307ULL, 0x5114C91A8E0460AEULL, 0x6205F09DC838C696ULL, 0xB2B42F58231CDD62ULL, 
            0x38D14E4D11B207D6ULL, 0xBFDD6F504E69B03AULL, 0x654FFFFF38FBBF66ULL, 0xD8A4D9CC63B4B757ULL, 
            0x52F9E1FCF6DEE4C4ULL, 0xCC5B34CC803BC5E0ULL, 0x07AAB6514BF4BC17ULL, 0x5C3E5C90519E9EE1ULL
        },
        {
            0x3F51D7362A27F002ULL, 0x6B90FE2FF65A53A5ULL, 0x564AC4DE0375DD1CULL, 0x4FF4A60785DEB27EULL, 
            0x2279BAD3B6BEB538ULL, 0xC58262DE840C2221ULL, 0xBD4DBF7AEAADC4F8ULL, 0x9B0FD20455FA6ECBULL, 
            0xFB422029B34089CCULL, 0x2878FC05A5B2BAFCULL, 0x3A74851FAC805DFFULL, 0x1437CB253B4F6DF6ULL, 
            0x7FD9E770166B47D2ULL, 0xF89DFC3F23725295ULL, 0x7B89A503E4563D37ULL, 0x4320B4694A35849AULL, 
            0xEE6D791D6A8283AFULL, 0x0AAA248C6906BF6BULL, 0x75E90DC9DCE50939ULL, 0x6253809E61778FA2ULL, 
            0xF9F4C16BF2F822DDULL, 0xC0E1418FFC9B3F5FULL, 0xD916BD9903ADEE39ULL, 0x4890645AF134E0F9ULL, 
            0x0B7EA18894817EA4ULL, 0x2B20028719D0C886ULL, 0xE8A9312882B93F0DULL, 0xC0E65D61BA831369ULL, 
            0x1BB025ABD3E9BEE3ULL, 0xFF8F694634872AE5ULL, 0xB36D2776A59F10F3ULL, 0x0C781E5B14B967AFULL
        },
        {
            0xCC7A72E17955D532ULL, 0xEABB02CB0CE101B2ULL, 0x693309F6A25E3910ULL, 0xEE57CE67B5871C75ULL, 
            0x2D0568882008A895ULL, 0xFC1AA28AA0124D3FULL, 0xC55297220CD8D3FAULL, 0x3F0D3B70D96767F8ULL, 
            0x748B5AD304642DDEULL, 0x54B9D688BE0964E7ULL, 0x40DD897B4E15AABFULL, 0x14FFF7777BF6246AULL, 
            0x2C7F969D01355AF2ULL, 0x4E8A7F5001D5982BULL, 0x719B8248A2068D44ULL, 0xA4DA9EB73B6D8E38ULL, 
            0x342038D95D2A6E65ULL, 0x7EC26D297A112222ULL, 0xA3C7372394E1AA4FULL, 0x9743BFAECA4836C8ULL, 
            0x7C444F8915B1BC3BULL, 0x0E672502FC95253AULL, 0xB01C72AF439F9B83ULL, 0xD987FA17FBA4D564ULL, 
            0x9A088F54E208BB6BULL, 0xA5DA1A7DDE488597ULL, 0x0F280728A956A867ULL, 0x4E4A9A0D4F3EBB26ULL, 
            0x0357CC424B9F5833ULL, 0x6C4D0A921CEA07DAULL, 0xBE63FEB8003E9672ULL, 0xC59C823E5570FC15ULL
        },
        {
            0x223AAB6F6BA9C911ULL, 0x149EB2632B15A5CAULL, 0x2C1A8414EB13D8DEULL, 0xA3BCDE534335D633ULL, 
            0xE7EFF67291FB1FE5ULL, 0xCE77F0E0F7B5041EULL, 0x69ED94EF5B47C8CAULL, 0xF80C58FFCB7EF363ULL, 
            0x9F9E39FC783DAF4FULL, 0x9AA95E58067146A3ULL, 0x663900BCEAD47920ULL, 0x75843B4AAD7F5025ULL, 
            0x30A7F02FC3E5203DULL, 0x6B9D48FEF6A6EF8BULL, 0x904E06C9B1D38324ULL, 0x56A4F036AD95B344ULL, 
            0x436D588E3BC8F425ULL, 0xA2E0DD23AB8FB17DULL, 0x1E5495F167C7FB10ULL, 0x1C43F6FA1DABAA6AULL, 
            0x758B1B10B0E8F65DULL, 0xAB0E753F13905900ULL, 0x8701D74FF7EF76DAULL, 0x787851C7A2EDB58AULL, 
            0x1DBD5269D47E597CULL, 0x445A1B77A41C0BF7ULL, 0x6FCF364A33DF1F9CULL, 0x8C9743595127634DULL, 
            0x2CC37F94AC285827ULL, 0x9D2990C72CDA006FULL, 0xF128765B1899010FULL, 0xFAF98A72C7537E08ULL
        },
        {
            0x172B4B7AD9456F2AULL, 0x701C9652D3EED4ADULL, 0x9F09CB3D622986E8ULL, 0x48811B3C9FF17B3FULL, 
            0xBFC75BE396FC2E10ULL, 0x691F8E6CC626A092ULL, 0xA1388FF32D14B783ULL, 0x2381F6E4E831B485ULL, 
            0x9BC2F501C801C54AULL, 0xC9C438D8C1CDDD6AULL, 0xC86CD2C1A7A13F08ULL, 0x073CCF30B595BD2BULL, 
            0x58C5CB41C477ABF7ULL, 0x146F7E66076C5DB7ULL, 0x8DD8EB40031F1ABCULL, 0xF3ABFB3605466A1EULL, 
            0x26B6BBDD026E920DULL, 0xE3B88C4953603846ULL, 0xF9CEB8B89B81AF10ULL, 0x61A62BC51F3AC119ULL, 
            0x5D28682A76D6813CULL, 0x202EF2A9A63727DCULL, 0x764B630F319104F9ULL, 0xB379D925EC5C56A1ULL, 
            0x9D44F90E35DACD85ULL, 0x83C83281D142D264ULL, 0x93457624929D0949ULL, 0xEA0FCED58E64373BULL, 
            0x126A8CE63AD02B00ULL, 0x6DE401FAD7885E30ULL, 0xE5D25FEC695F8376ULL, 0x581B3BCDED404DA5ULL
        }
    }
};

const TwistDomainConstants Candidate_A::kPhaseBConstants = {
    0xE05929EE3B6293DBULL,
    0x03080C95F07336D8ULL,
    0xBD9BB825CC2591ECULL,
    0xE05929EE3B6293DBULL,
    0x03080C95F07336D8ULL,
    0xBD9BB825CC2591ECULL,
    0x5E616A7742BDEFE7ULL,
    0x2739B4BDA9479584ULL,
    0x8B,
    0x9F,
    0x6D,
    0xE7,
    0x1C,
    0x25,
    0x9C,
    0x26
};

const TwistDomainSaltSet Candidate_A::kPhaseCSalts = {
    {
        {
            0x17DA6F62C5E8C115ULL, 0x847D4FE7E6CCD08DULL, 0xF61E1580E88B711EULL, 0x512E1A5925C70981ULL, 
            0x5570F753CA6B8804ULL, 0x9500495050F789BBULL, 0x4A7889B5CCCF02EAULL, 0xD7AB2B51163DB6E7ULL, 
            0x2071202165105B71ULL, 0x67081C69CD21CF5AULL, 0xB9A2831FC735D6C7ULL, 0x188551C9879060D1ULL, 
            0xB7BDAF1CC70CCCC2ULL, 0x826F07C9B888EC0BULL, 0xD42765F6F4E0A555ULL, 0x8BE87D780806FB04ULL, 
            0xDEB774BC4F10A4EBULL, 0x863D3909AE27907CULL, 0x01765E717DDFD97AULL, 0xA6F1B5196405F813ULL, 
            0x5244B7B2A9E5AA44ULL, 0xDDCB52F070FC5157ULL, 0x81887331E7CF5256ULL, 0x2CEDE202A45E81F2ULL, 
            0x3FC3BA0BE71748ADULL, 0x2F3F3882CF1A72CCULL, 0xF3F71E01E79320F8ULL, 0xD2470DD7A2E07D03ULL, 
            0x5A320090DF92545AULL, 0x1D2D5E3B45FE6062ULL, 0x06A4BFFC0AFCA5CBULL, 0xBBBB862352677719ULL
        },
        {
            0x8A2152B5D0268761ULL, 0x0352A0D31CC1B6F8ULL, 0x1F8C1CC5DCE07E41ULL, 0xE809B172A5258709ULL, 
            0x6D7C254E05FBBCD2ULL, 0x2E17A01B787D568BULL, 0x3BCA05897D3550AFULL, 0x75EE2C2F5A70C8B0ULL, 
            0x82E094826C6F6200ULL, 0xCC1B7379DFEBF85BULL, 0x9356CE2D81AF9B30ULL, 0xD69C2CCCCA921ADCULL, 
            0xEE49BF948427EDDAULL, 0x2BF80AD04842386FULL, 0xA252827B5519B0F2ULL, 0x3E2D119BB23C22F6ULL, 
            0xA3D498B0C3816D8FULL, 0xF16232EC9572181AULL, 0xC69B263F4E6B2007ULL, 0x6FE804DF3005428DULL, 
            0xADDE30EF03BC00FCULL, 0x73E5C60699BAF4B4ULL, 0x124188A5BB7D15FEULL, 0x505E488BCB0E2EE4ULL, 
            0x93653D91229961CAULL, 0xE32390CE7EC4E146ULL, 0x65A5CB1563C4D51BULL, 0x60A0B9F540CB9587ULL, 
            0x28E731323F9C4A1EULL, 0x1C62CA4ED29A8E1BULL, 0x1FC8678E625A6512ULL, 0x25AFAC74539F6096ULL
        },
        {
            0x12E8AEE779FC569DULL, 0x78C5F7A73B9CABDCULL, 0xD502CF64EA90968FULL, 0x0B55660D2A29C4A3ULL, 
            0x005E6AE8895698CDULL, 0xDDDA674E2D595101ULL, 0x8317B96CAC4207DCULL, 0x0424403C08CE7E5DULL, 
            0x7805794611E4811EULL, 0x0A4EDAE6A75D2EAAULL, 0x330D9E6F255E41ACULL, 0x96D8FA2126235DC6ULL, 
            0x0D8FD6A4C9110D1FULL, 0x6F4C2C3BE173F0C1ULL, 0xD1DCC738F12DEA4AULL, 0x045BB256B5CD2A07ULL, 
            0x018C537D0CB8F3DAULL, 0x07F7282D7BF69AB5ULL, 0x2249875ED32D90B1ULL, 0x17EA67164638DD8CULL, 
            0x7026B9582E4B6112ULL, 0x387F6D9CF5B551F3ULL, 0xBF61A4BC1CCACD11ULL, 0xD0B170E7C089EF22ULL, 
            0xF08BB170D4BBEE2AULL, 0x847E74361D00FE2CULL, 0x8DBC7684CB1210ADULL, 0x06DEA48BB282755CULL, 
            0xED08FEA14A819347ULL, 0x1D5FE5A7AD24588FULL, 0x9373603AD13B3E7BULL, 0x62A5E1C7ECB6E1CBULL
        },
        {
            0x4CE4F4DA2383C24BULL, 0x3517EDD375F16F24ULL, 0x5D511040B6482A9AULL, 0x9D2F3C6EFE61C1ADULL, 
            0x04AB8CFB107FBF68ULL, 0x7F13657E6E17A1C1ULL, 0x715A79507BEC6962ULL, 0x57F28C877068DF13ULL, 
            0x3F96CB6E86322995ULL, 0x29322B7D83CE0651ULL, 0xAF9680AF2C618646ULL, 0xFD44FF0177CFCCE0ULL, 
            0x2B0DB1FBDF628A09ULL, 0xDCC5B6C3258DCFD7ULL, 0x1150C6223E97FFD7ULL, 0xAFA604C62A28ED05ULL, 
            0x3AF1A7A8A32C9509ULL, 0x5F09E7EE0C63A2F9ULL, 0xFC7B263D7D2B07EFULL, 0xD9A45A4036ADFF66ULL, 
            0xDAEEB7F52473F6CAULL, 0x0397FC83321E75D2ULL, 0xDF42D53F2D51B213ULL, 0x912AE28034546FF0ULL, 
            0xBCAB92E02AC6BE74ULL, 0xF1801CEC148522D6ULL, 0x69A42E3AAD2B8F87ULL, 0x4F78B58E4A10E89AULL, 
            0x0FBB9C78986E79D5ULL, 0x0AA63C9C4E67A1E5ULL, 0x89CA536A7557A9D0ULL, 0x6AA0D6772F82BF42ULL
        },
        {
            0x46A8D2677EA2E608ULL, 0xD0F4D9B0B6D7F94CULL, 0x7461430F11F39B14ULL, 0xA59017279E98E516ULL, 
            0xEF7D8155C4EBC11FULL, 0xFF30E43F642057BAULL, 0x7319F1C2C867E607ULL, 0x4D99BDB955916496ULL, 
            0xFD941A93D2FCB978ULL, 0xA31BB0BD8A7D28E7ULL, 0x90D94F83F46E608AULL, 0xD8ABBB8649F9376EULL, 
            0xF37384C3A07C4DBAULL, 0x091EA64155BFB505ULL, 0x33C9235549D27E13ULL, 0x17311D1407E7C760ULL, 
            0xED080F9A0CCDBB47ULL, 0x1EA30AE884B79981ULL, 0x290EEA0C16AFC705ULL, 0x5D3FC58DB69BF948ULL, 
            0x77BAD0CE3497E13EULL, 0xDCB53544ADA72AD3ULL, 0x42B4F1CA5D7EABDBULL, 0x0C681035CC3DB386ULL, 
            0x8BE3B5DF049CC081ULL, 0x6A981B557431DBB8ULL, 0x24F7170F49D4DD1FULL, 0xC83B49F13543245BULL, 
            0x95B5830E678AF6DBULL, 0xFFCB3073C941ECB6ULL, 0xCDD278AC81857F33ULL, 0x423393C640144963ULL
        },
        {
            0xBF26B81DE0012ED1ULL, 0xB10C8C3B52EB7ECAULL, 0xBA74A98B46AB07E0ULL, 0xDE69E4542BF3B2C2ULL, 
            0x09BD320590B9F558ULL, 0x4210EB6FEDAC1754ULL, 0xCFA01A51B93552C7ULL, 0xAD905C72DC9641E9ULL, 
            0x3623B398E85C3FBDULL, 0x4044613D0005E183ULL, 0xFC8D32697A794957ULL, 0xC22059DC6FFAFE50ULL, 
            0x2170C9D5D964E7C1ULL, 0x07860F1D41EB731BULL, 0xB0777F0F9FF53553ULL, 0xE71C12470B9F96FFULL, 
            0x3921B414F1937ABBULL, 0xDB05D66C668580B4ULL, 0xFD700C9171D6A0CFULL, 0xC020B97A34B4FBEDULL, 
            0xFD89087EEF7292BFULL, 0x088B24265AE82BCEULL, 0xACCFECF34E898081ULL, 0x1680ACC91534B915ULL, 
            0xF950D9745CA1F7CDULL, 0x6C30C8D0EC178BC8ULL, 0x9F3DB0D236AF5C8AULL, 0xBB60B5A584A6DC25ULL, 
            0x3D2A59CDC98421A3ULL, 0x8E1E08CA3EDDD1EEULL, 0xE5631A0829A60FA8ULL, 0x292DA14016159AB5ULL
        }
    },
    {
        {
            0x7BB3EF7C9374FC42ULL, 0x29FFA8D979CBD51BULL, 0x5F43521994B2AA02ULL, 0x5B2089B873550701ULL, 
            0x57404B982AF4FF74ULL, 0xF441B888F3D9D88EULL, 0xD49BEDA58E47DD68ULL, 0xD05D2FEBC8578163ULL, 
            0x3F7DC98D8C81FA41ULL, 0x4243ED0D080F9CF2ULL, 0x18C5CD4F4335C5CBULL, 0x2B6107099C520AB7ULL, 
            0x87AEEC01ECD94A3DULL, 0x29616F177C028232ULL, 0x5A982E54EB72A51DULL, 0x17F3C00F870789CCULL, 
            0x787B71F601838EECULL, 0xEA7FC7922B4028BEULL, 0x79B08767831A1BC2ULL, 0x1852FCAB2DA6B755ULL, 
            0xCEE25764A652BEC4ULL, 0xA792307C2DD4AD41ULL, 0x517D59414A2DF99AULL, 0x31188B37AFCAE03CULL, 
            0xB91E3304B39237F1ULL, 0xAC4E110899C80E24ULL, 0x3D5422B2B6686661ULL, 0x52D005DC78E4457FULL, 
            0x8C41AFF2FE393790ULL, 0xE82F4C52CF21ACE6ULL, 0x85FB4273D1FDA2E6ULL, 0x9442D4DF2C48AE51ULL
        },
        {
            0x6C702BDEDFEE72FEULL, 0x53A858EC25460C0FULL, 0x5E1291ACC3AB4574ULL, 0x6DCEEB0176B0FDCFULL, 
            0x1712F49388C9D693ULL, 0xAA76CBD3F5198ECFULL, 0x5C06D45692296A0CULL, 0xC6D71423219035E6ULL, 
            0xF4A2907D6B234015ULL, 0xAB76F62D62EDA87EULL, 0x0DA30459351F899CULL, 0x19F0ED9E679F8184ULL, 
            0x4FAD4E213B0541EAULL, 0xBD497FB887CFB79AULL, 0xDF60BC3588FC5F7AULL, 0xF91DF05FF086A619ULL, 
            0xB79ECA338951E6F2ULL, 0x5EB82F4D62423DF8ULL, 0x73410307837B3BF8ULL, 0x903CD9B7721CC371ULL, 
            0x1FC3A9CA0C9DBB5DULL, 0x8D0CDA8424F5467BULL, 0xCDBEC40A83ECE0FEULL, 0x53390C1D3804E033ULL, 
            0x2CCBC47FBAFB6516ULL, 0x60BDC75872A66421ULL, 0xFDBCEC96AF9BA057ULL, 0x9C6E6AA1ED51A822ULL, 
            0x3F7BFEF4B45876C7ULL, 0x9B572B9F7FA517E3ULL, 0x4D3468CE9BC9AFBFULL, 0x966A3E097C25FF8DULL
        },
        {
            0x6A4FDB39D3985E76ULL, 0x46A12EB3BD3C45AAULL, 0xF9BC4A9FEEDC23C2ULL, 0x34A04A005888EE2BULL, 
            0xA894D52E83BF2E11ULL, 0x7BE2CD111EDCA00AULL, 0x1479B4F730D43833ULL, 0x8FE121944A2C7CF5ULL, 
            0x560681EB770FA9EFULL, 0xF400AB3A3B0867F2ULL, 0x96D4BE79943DE634ULL, 0xEAAA87B0BB8F733CULL, 
            0x381424D3AA0E9760ULL, 0xC54C4682906C8B06ULL, 0xBF22688208DBAC3EULL, 0x7860301F36A51F3AULL, 
            0xB02B8E8D7CABBA18ULL, 0x172ACEE35AA5C25FULL, 0x34DFDC7894AE67DFULL, 0x1F5FBA98D26621E0ULL, 
            0x0872AE3AFDA5D06AULL, 0xF2A3953C2771CA65ULL, 0x6F90918A8401BCA2ULL, 0xD9325EF12DFEC50AULL, 
            0x80D716DCEF9B5AD9ULL, 0x0A0528EB0623EF7DULL, 0x9703D1C2C7814E10ULL, 0x414A99DF3F5BBB67ULL, 
            0xFFE9CBF697835B6FULL, 0x677FD967B6668849ULL, 0xC31A2309B262E027ULL, 0xC46BC5A83358CD13ULL
        },
        {
            0x65C527E3D5C2235BULL, 0x207C3AB60F33A6D8ULL, 0x5EBDAA6449797932ULL, 0x3217BC3831B7D9D9ULL, 
            0xF93AF1807129BD08ULL, 0x08EFF278EDCDDDBDULL, 0xD0E30C108B930D32ULL, 0x1416FAEAD3A4CBDBULL, 
            0xAF62046BB7AAFC01ULL, 0x4A7F0639BE4C390BULL, 0xBC6193CD29CE7D5AULL, 0x20075878EAADC155ULL, 
            0x617FFEEE73F1F5E4ULL, 0x51D1663B12679E6AULL, 0x2CF07EF9898A80CEULL, 0x2BCA01796F621BE2ULL, 
            0x323FCB0903B218A7ULL, 0x94FE2F9834AC21C0ULL, 0xDD104B48E2B6B8DFULL, 0x55C4BC4DB9F12BE1ULL, 
            0xAE627570573B7E2DULL, 0x372ED45AA311B53EULL, 0xAFF908C07E98925FULL, 0x9EA8FA24B83BECE5ULL, 
            0x7085B70C07EF59D6ULL, 0xA106C77535107A08ULL, 0x97B3DAC0C1039501ULL, 0x8B058B975AEF6B44ULL, 
            0x80478AE7E429AA1DULL, 0x1CBF2D44268789D1ULL, 0x474A78C8DC443520ULL, 0x3DA7F9DB40C2490DULL
        },
        {
            0x360A653D3864BD62ULL, 0xD3008D18FD2F13B2ULL, 0x6D1B9C06DF8DCE5BULL, 0xC407711C09258ADDULL, 
            0xEC649C707EDE521DULL, 0x7EDAB1E07B95348FULL, 0xD04CA1C4D95CF2C6ULL, 0x10CB5ED3750C375DULL, 
            0xB6A6A3D3D05640CDULL, 0x1FE017FBA000DD3AULL, 0xFB200463647DA00EULL, 0x7E7378B6561AB76FULL, 
            0xBECA597D1284F03EULL, 0x37D0C00760BAA012ULL, 0xDA05E690526721EBULL, 0xF6AA699CA1CBC37EULL, 
            0x5E1825C860DE3D5FULL, 0x0EA0C09F38D50DDEULL, 0x649F65C356F66852ULL, 0xEB6636A330C906A3ULL, 
            0x7CC2C9A2D5E32806ULL, 0x339D852D4B5B2403ULL, 0x148865CB047001C9ULL, 0xD0490A9A8A20FD22ULL, 
            0x46557F3C770F332CULL, 0xC0CD42A9A4A5DF0AULL, 0xB877E7B45BAF21A1ULL, 0x672199C3407A7895ULL, 
            0x55586808B4BC33A9ULL, 0xC74270E94FDCB9C4ULL, 0x30C876B87259B404ULL, 0xAC8381F7FB24DF09ULL
        },
        {
            0xEE69D07F3E9A41F0ULL, 0x53791D82352A6C32ULL, 0x1C9D5FA4C3970DABULL, 0xA6B5AED875462F84ULL, 
            0x07C01E7E6B94CF6DULL, 0x2EAA08AA146F22B0ULL, 0xA7F9D2A290203ECDULL, 0xFD48019A88F7AE23ULL, 
            0x26E92FDD36637B6AULL, 0xB9B3B6B8C62F3483ULL, 0x49F9423D09B67C19ULL, 0x9A881C00F3BDCDCBULL, 
            0x9B1D08B8A99B8766ULL, 0xE213DACADEA32EDEULL, 0x6F4CD28C930DFB69ULL, 0x30841E290BC5EA75ULL, 
            0x704559323C4493BFULL, 0xBB92143EB6D3B6EAULL, 0x78D0708021840B41ULL, 0x205633A14424445AULL, 
            0x60A9B131E303B4C8ULL, 0x413110D63E02C9A7ULL, 0xECF7BA0715EACD43ULL, 0xF57417A4849D8899ULL, 
            0x6974E8DFC389E470ULL, 0xA65DE264DBBCD8FFULL, 0xAC684F10C4B7D599ULL, 0x98D4866421E2C5E2ULL, 
            0x34FAC6AA6656045BULL, 0x9B30B0B9BF410BA4ULL, 0x62820D2AB25C10CBULL, 0x2AF800AF122F6577ULL
        }
    },
    {
        {
            0xA12A2BD12005A499ULL, 0x0873BE9551FA4A52ULL, 0x5A768895A243256FULL, 0xC70A44AF4C4F9762ULL, 
            0xC5CC089751350108ULL, 0xFF7B3CF76324553CULL, 0x5D9FB8122DB2432BULL, 0x12E896E163E2F60AULL, 
            0xC26182A2F775E540ULL, 0x49C5F6C9AD50CB62ULL, 0x9DEBDD04ADD90F34ULL, 0x23C75DCDB1D02261ULL, 
            0xA2625289B42C1497ULL, 0xDCE2EF797EC2C97DULL, 0x4D5A02741BCA9887ULL, 0x2851CB8A93F40AECULL, 
            0x70FC3AEEC2EC9046ULL, 0xADA0485D1A4EAB15ULL, 0xCEB6ECBAA7F7E6C5ULL, 0x2FD9E9468D329EA0ULL, 
            0xC688AF8FF3E429DAULL, 0xEC4E9D75DF5FAE96ULL, 0x7AC478AFE751857DULL, 0x879F1DF01BEE7F3EULL, 
            0x51365EE7B3F8023EULL, 0xDD666F394386F6B9ULL, 0x738E5E544EC93B3CULL, 0x7145C1EA1D2624B3ULL, 
            0x64C0241B2E2112BAULL, 0xFCFCCA92B32C510AULL, 0xB5ED6670C63766EBULL, 0x36BF37B7CD9BA2C8ULL
        },
        {
            0x58698EE851A11511ULL, 0x271CE751426EF439ULL, 0xBC4D2D5F4FB7F906ULL, 0x350D43202DD1CCA8ULL, 
            0x3412886942482D2AULL, 0x338CF2FBF5ED9735ULL, 0x2E5E844C282C1606ULL, 0x28C45062A3D80483ULL, 
            0xA55B49E5FA913AAAULL, 0x2EDE6441E142D405ULL, 0x5A48BA471844683FULL, 0xDF56AF6E19A535FCULL, 
            0x98A69383BF702EECULL, 0x025B4C586BE05716ULL, 0xAA180656C28EC4BFULL, 0x4602DB5552D1FAB3ULL, 
            0xE4EC13C2864EE6A4ULL, 0x31A043E4CC14F28FULL, 0xEF8C6D6FA9A9A094ULL, 0x60F1412D45AEB813ULL, 
            0x62C4CBC2C7E801B1ULL, 0xBE23F6CFC5D5EFE6ULL, 0xEB098709052ED7A4ULL, 0x53DBBE6ABD761672ULL, 
            0xF17D3516584707E3ULL, 0x27D699B10EA4E446ULL, 0x4DB38DD265ECE3EFULL, 0x30A60E0E179A9CF9ULL, 
            0x5DA6946012D6399AULL, 0x14A553F283A92825ULL, 0x6209CC70FD9CE665ULL, 0x8C9A6C436C799F20ULL
        },
        {
            0x4E00D3ECA9D01D23ULL, 0x9B5CB51034D29639ULL, 0xB28A44301A0BB31FULL, 0xE2557D42E1D579FEULL, 
            0xC3F16C4F7104E01DULL, 0xF4F5254BEF2B1C74ULL, 0x198A717311EBB647ULL, 0x49762CFAB79EE5DDULL, 
            0x707F3AA8C216B05BULL, 0x4536E15942E07A93ULL, 0x105DEF6A9D931A3DULL, 0x9AB640545264A453ULL, 
            0xD820E9A25D83F9A6ULL, 0x97AC3401F8D71A64ULL, 0xB7813A1FF4115E0BULL, 0x0990E643FF9D89C3ULL, 
            0xCE1EA8A289E416DCULL, 0xA39C28FCA151A5C1ULL, 0x6EA7CDF96F4EDC13ULL, 0x8AFBD8567D28083AULL, 
            0x6A1AC9102CEA8EFDULL, 0x91A3A9FB8A763976ULL, 0xC4636DE6651CEDC2ULL, 0x6F2417BD867C3749ULL, 
            0x90A7493EDF1A9F57ULL, 0x653604F002CB1CEAULL, 0xF2C66F7BCB260CFFULL, 0x045C46194B09F79FULL, 
            0xC2029C7FAF46BC48ULL, 0x204687659AD92C3AULL, 0x936827B5C8D27B33ULL, 0xBBE47ABFF316C497ULL
        },
        {
            0x7E41BE43F8DCC09AULL, 0xE0A4B752CF364434ULL, 0xCE10764DBBE92FA3ULL, 0x1D7CC29EAB9E9773ULL, 
            0x951E2DCC32703F71ULL, 0x09507772CC483366ULL, 0x08DF0E178F1FB39FULL, 0xF2478B9C08E9895AULL, 
            0xA5D02D7C9338E965ULL, 0x431F4572986987E4ULL, 0x5E439FBF15625DC0ULL, 0x0720B909378FE60FULL, 
            0x68FA64D8C106DB70ULL, 0x2E8AD83FEE6374CAULL, 0xB9EF1C78D433F8D8ULL, 0x1024785AAE4A7E6FULL, 
            0x4769A8037AAA817FULL, 0xDB5E8F0196835A47ULL, 0xBFB70838C7618A8BULL, 0x4567D0B59554DF80ULL, 
            0xD1447F642C35D962ULL, 0xBCD8B3744F341B18ULL, 0xFC6D65E43E6E3081ULL, 0xEF1A9F6E99E0D673ULL, 
            0xF5353210641208EBULL, 0x0C4E26C3B7DE0BD2ULL, 0xF22901C3233C01CEULL, 0xB77604628DAFB306ULL, 
            0x4E1002D0ADEF42AAULL, 0x46A4058A4A3B3CD0ULL, 0x42B855D9032A2472ULL, 0x34E029F6A6F2F58CULL
        },
        {
            0x363F4F07A2CE1507ULL, 0xA856AAE007CACC29ULL, 0xDF3D5E4FEDD1BC10ULL, 0x33A59EA959B4D2A5ULL, 
            0xFC7A640F413AA600ULL, 0xBEC993B13BFB9A2BULL, 0x1B2F7033CE5A439DULL, 0xF9C50F69310379AAULL, 
            0xDF7D0E3A9713BDCCULL, 0x6A93331FEA325B74ULL, 0x5964449FD0946285ULL, 0x051014F143169485ULL, 
            0x085F70E86BF7BF23ULL, 0x94034EF974A74270ULL, 0x1E68884E62522392ULL, 0x0C4C2E0731C5F8E5ULL, 
            0xB44A3D75E3972C09ULL, 0x6C05C7A28BDC470AULL, 0x1107035E3593061EULL, 0xE52CF19D91BDB3AAULL, 
            0x7F9DCA6D13E6A79EULL, 0x5426CC076607C986ULL, 0x2C954857825BED2FULL, 0x2A8FAC23DB3C2F03ULL, 
            0xD38F64F5BA383AF4ULL, 0x6F0A293AD29F5089ULL, 0x205861A992BE689AULL, 0xD28A1B57BE654711ULL, 
            0x76299FB3C4C54198ULL, 0x43FB4A92CD00417DULL, 0x5892ED29A35AA533ULL, 0x60EC0606F8D36A86ULL
        },
        {
            0x57BD9C5892EF5240ULL, 0x01F209B0DE1C884DULL, 0x100D6E92911F73CCULL, 0x220AB3765BADB77BULL, 
            0xD8CF4ABED4B72BF7ULL, 0xF0894BF4F4D6F066ULL, 0x3681513A236957B3ULL, 0xDD16B8CF30241D69ULL, 
            0x010EAAC604B90714ULL, 0xE66471AC828EBACAULL, 0x58F3FC0A11DDE450ULL, 0x03EC8298824AECB4ULL, 
            0x466A10D978768F2BULL, 0x01611B131A45E5E0ULL, 0x5691C86D36182752ULL, 0xBDDCAA9507B9E591ULL, 
            0x98D2E022C572D8DFULL, 0x8FDD0A48ED61BA01ULL, 0xD811C189E29D7E70ULL, 0xC46331A8ABD74B82ULL, 
            0xEF94F698B3317CCCULL, 0x89974AD4A4FC139AULL, 0xF9A3CB9B3E478241ULL, 0xF6016B6876A3FC71ULL, 
            0x99DF1A355AEFAFC1ULL, 0x7D49234959D7C4DCULL, 0x8869126EF2558621ULL, 0xC58094DAED322ADFULL, 
            0x365B6FEC14938B77ULL, 0xC7BDA2B68B87A656ULL, 0x9FA2816EE6535F07ULL, 0x1A6A0BF3A5FC24FBULL
        }
    }
};

const TwistDomainConstants Candidate_A::kPhaseCConstants = {
    0x25A3845D2D0EEC13ULL,
    0xC79193121E77CA61ULL,
    0xF9BD93D2FDF7D2F8ULL,
    0x25A3845D2D0EEC13ULL,
    0xC79193121E77CA61ULL,
    0xF9BD93D2FDF7D2F8ULL,
    0x936410AC5A342797ULL,
    0xA7A93C57E36CB00AULL,
    0x0D,
    0xFF,
    0xBC,
    0xC7,
    0x03,
    0x47,
    0x87,
    0x23
};

const TwistDomainSaltSet Candidate_A::kPhaseDSalts = {
    {
        {
            0x3B5648F8CF9637D2ULL, 0xD05A698E7FEA3C05ULL, 0xC4E8687C6EE4FC4FULL, 0x6AB7CFEB5152034EULL, 
            0xA02D086997A1D94DULL, 0xAF3E98A07E8F85B5ULL, 0x0AC400D204A567ECULL, 0x7E0E5AC9402DE7AEULL, 
            0x1E327E0ABCA1F376ULL, 0x5321B2DC2C577A15ULL, 0x40B0C47DE984692AULL, 0x3A9FF912E80A1AA6ULL, 
            0x7CB4CC84C7E2B352ULL, 0x2131FB820236990AULL, 0x2F5346AAC8271F47ULL, 0x7E333AE160B58641ULL, 
            0x60275447BBF2F7E2ULL, 0x760E1FA3C1B4E509ULL, 0xCFB4C03F98B9A596ULL, 0xFA24D3AAC9B78E79ULL, 
            0xA7B790AB69A79692ULL, 0x8B66564A1C62013EULL, 0x4B99CA7DAAB1FC4CULL, 0xE1F0F3603FA831F2ULL, 
            0x3E7CC5F2ED54E808ULL, 0xEEE936A4BC004E1BULL, 0x678B64F70B363CB6ULL, 0xFFE2A5FE95E3BC2AULL, 
            0x1F40332051261181ULL, 0xE089F82F5E84CB0DULL, 0x60775867781BAB4CULL, 0x7774E3F3CF5B5433ULL
        },
        {
            0x54B44FD7AB209928ULL, 0x6A18E120B32020CEULL, 0x9EC1A31B2EF86F5AULL, 0x7636C3F242CEF0B3ULL, 
            0xC98C72AEBC70018FULL, 0x104054F89D85E5D6ULL, 0x6D81C3B8B7CD37B4ULL, 0x52E4AB263C62D780ULL, 
            0xD5F9001719492E40ULL, 0x6134F5C1C8D1910BULL, 0x7F26F75DE463B5E2ULL, 0x3410ED706BE21A19ULL, 
            0x369E8DF58429AEC9ULL, 0xB1075876B61BD708ULL, 0x582D09332B21F3AAULL, 0xEFACC4776A9BD54CULL, 
            0x85E91E37D8921E23ULL, 0x700C348824886552ULL, 0xCA113C74ADDF4E41ULL, 0x4479A1BFF630365DULL, 
            0x641E0BCD8114646CULL, 0x1C42C38E9E602EEDULL, 0x88753DEE36006D9FULL, 0xEB4EC5AD3BAB82E1ULL, 
            0x49B6F19B5D071627ULL, 0x6F3F7578D108866BULL, 0x1C5F4805C1B3B042ULL, 0x5D18C122AA421DB5ULL, 
            0x91A0A39EBD850898ULL, 0x76F5A62DCF0B7D26ULL, 0xE90A46C276106BCEULL, 0x6ABEAFE55DEFDFFDULL
        },
        {
            0x011947EAD2332666ULL, 0xA3CD1301D538604BULL, 0xB2E27E61DE2D9924ULL, 0x9120F0AC87C69A29ULL, 
            0x6B4B33C3C1173F17ULL, 0xD9241FE03F36BC43ULL, 0x754C101945F029F3ULL, 0x780B812ED6F7D7D5ULL, 
            0x7362D39E47F57870ULL, 0xFABCDEB5F3ED5EF3ULL, 0x207FA75F44595703ULL, 0x7B59EFB8F0D5678EULL, 
            0x1BD04D09A7967DDDULL, 0x946453E26D8E39D9ULL, 0xCDC5B01014597D51ULL, 0x3A5096E1F70D9B7CULL, 
            0x28856BCEDCAF7244ULL, 0xDEA0D10AB7F12985ULL, 0xB1A35C9D02407E67ULL, 0x1AF5F4613D83BDFDULL, 
            0x9D4B1EEEBBB668ACULL, 0x07E173CFE284DF21ULL, 0x094E106619DE60A6ULL, 0xF18CC10F263486E6ULL, 
            0x860DC2D8624D0306ULL, 0x7B8EB64025B3948BULL, 0xEBC9072302ED541DULL, 0x900959CDC6A63360ULL, 
            0x8092BEF8F1E6819FULL, 0x9D004B9E341FE6B4ULL, 0x878FA9C65C4A8AEFULL, 0x67C557FA5C49105AULL
        },
        {
            0x35EAA54DFEC7D4DBULL, 0xC99ADB97849C3590ULL, 0xB02B69969AA94259ULL, 0x634958493A6D82A2ULL, 
            0xB74F2507FFC83780ULL, 0x3A8F03BF4F461BD3ULL, 0xB5EC5BDA3537E143ULL, 0xAD7FE71542111D21ULL, 
            0x1C6F735399EF3CA4ULL, 0x1A80A2A95556EB8AULL, 0x06DBF7032084664CULL, 0xB610F227222BDDFCULL, 
            0x5532DC26DB41503CULL, 0x69C19E83521C5F9FULL, 0xF901B248AE4F2AABULL, 0xFED8F03A6550C68BULL, 
            0xDA422169FB57A024ULL, 0xB7F92FA15C34786AULL, 0x624B0C582544CB15ULL, 0xA3E8050F40B9ED71ULL, 
            0xB8CE4B82772EDB92ULL, 0x90E90207DBAD750FULL, 0x0D8F6B7645570EE3ULL, 0xBA568791995AFD1DULL, 
            0xB6BE93188C1DF253ULL, 0x5E238ACBB41BC3E0ULL, 0xF1887B130F5C5616ULL, 0x25C7E8F70FAA97B0ULL, 
            0xCF3E4B9CEA5275D0ULL, 0x8DA52C289A949801ULL, 0x8271906B2B6BC145ULL, 0x4FDCEA13DA847853ULL
        },
        {
            0xD14410C3C4835717ULL, 0x277F10F54B73F113ULL, 0xF8435201102E0750ULL, 0x15C00DD64B0BA8EFULL, 
            0xC2778ABC799A78CCULL, 0x34188914BA109895ULL, 0xB933137AE29B3ECBULL, 0x6ED4BE8DAB767255ULL, 
            0x99D69661D7B6D3BCULL, 0xB1D09869A14BFDBAULL, 0x661BFFB16B254E5AULL, 0x24A5082BF4F3609CULL, 
            0x8528576C8D47496BULL, 0xED492B7987BE7FBBULL, 0x2722327F18102C64ULL, 0x6A64B39A6506279FULL, 
            0xD9CE35B6622706B9ULL, 0x6F35AAED448302C6ULL, 0xE59DF9BCB26BC61AULL, 0xD184B29E2059AAE1ULL, 
            0xC52B8EB46CA27B97ULL, 0x554552D829D0B59BULL, 0x4EF7D9269DA8DA51ULL, 0x557660F831EF36D5ULL, 
            0x92BA951EF21E923CULL, 0xAE8E5E5977166C05ULL, 0xC23AC35DE0CC061BULL, 0x6391E4762C73985FULL, 
            0xC28B6C8C5C68B381ULL, 0xF3D24AB8AA516839ULL, 0x64673ACBF4CB9B40ULL, 0x894A80ADE3D3062DULL
        },
        {
            0xABA466593AC7E9D2ULL, 0x211BE24A616F63E5ULL, 0xE9651F4A62FF94D7ULL, 0xF2D81C1A6E681C73ULL, 
            0x02E97E40833B1F3EULL, 0xFD8AEAA1F8E59252ULL, 0x13093D5A32A43E14ULL, 0xCC2D0E7FEDF6BB95ULL, 
            0xCF983F669189E65FULL, 0x528311D931FB08FEULL, 0x84F277BB58B30B8DULL, 0x4F356EBFBE61C682ULL, 
            0xE57E0BBCCF6613C8ULL, 0x886E2665385A4883ULL, 0x498C2F8470A328EBULL, 0x7B7998384D15B8E9ULL, 
            0x1326E4A40A50F43DULL, 0x843FB385095BDA6CULL, 0x3EDB27E5EA3AB829ULL, 0xF8D7F1E68EB8DA8BULL, 
            0x667DC030738C2F09ULL, 0xB0579C0D7FA0EB75ULL, 0x5300251397B542DBULL, 0x96994C70270B7ABDULL, 
            0x60531F7972952ABAULL, 0x505CF47FD408EFFCULL, 0x6BE27786B75186F6ULL, 0x6B4A233330C3023BULL, 
            0x2120B8F7335F31FEULL, 0x5AB7D94E8E83A3DAULL, 0xC0E76E9D98A21CC7ULL, 0xCF50B8516DF25421ULL
        }
    },
    {
        {
            0x3A6E3C89F3E22000ULL, 0x3AD6850E14215A32ULL, 0xEBD4E474E4EEF774ULL, 0x2DDA04D95E1B5A2CULL, 
            0xC022F6335F4FCF1AULL, 0x979FEB0B0EF70325ULL, 0x1A7E176F402F5704ULL, 0x82530FD64DA9A37FULL, 
            0x867B8B30BFA2738BULL, 0x94FA33E0219E197AULL, 0x12FACC5BC1D14A53ULL, 0x7AFF40D26B3ADD1FULL, 
            0xC9B33520C43E2525ULL, 0x322B7F6C5099A81BULL, 0x8C857D41EC0DC914ULL, 0x275D109BE2D2308FULL, 
            0xDA129CC3A73D4701ULL, 0x56071D7E06FF5ED9ULL, 0x20CAB455E389C61DULL, 0x8BDC8E608917F21CULL, 
            0x21A0A07B651A0AACULL, 0x9D301A9FB5732FBEULL, 0x8F21C44CEC93DB3AULL, 0xF42EC037FFF9F902ULL, 
            0x8DD7BA9F8A656E8AULL, 0x79B42740A8499F64ULL, 0x7608FD52D31BD4A3ULL, 0x00246507963D1D16ULL, 
            0xCD94CE6315102ED1ULL, 0xE5A13B8EFB73CDBDULL, 0x228558D3A292C19AULL, 0x5ECDF849A76FD8E0ULL
        },
        {
            0x82C60F1BBC29DBA5ULL, 0x17E0BECD94D3492CULL, 0xC42A8E81C86E394FULL, 0x36E9679462B530D3ULL, 
            0xF46EBFC0D98EE864ULL, 0xA647C215FFF53D59ULL, 0xD0487D6BA79EE434ULL, 0x01E2A85944BE3B17ULL, 
            0x797411218C28D3A8ULL, 0x0E8EEE1C65FDBE6BULL, 0x771C19AB86EAEA47ULL, 0x4BA794C2B85E6D36ULL, 
            0xE994CC7AFAEFC3A2ULL, 0x08F3C564F3498A8AULL, 0xBA2F1A8BBFC5C6C8ULL, 0x81C89A89910B0D70ULL, 
            0xA4C30F6EE469D62BULL, 0x6919C3469A21DD68ULL, 0x2F54FA414C9A7BF6ULL, 0x7955D1EB2FBEB668ULL, 
            0x85DA27316214CB89ULL, 0x3A11F85BCAD79671ULL, 0xECB36CBD1096236AULL, 0x20E4B5ECEFEA64FBULL, 
            0x7107BEEE0FCA9B97ULL, 0x204936B9A2919DB6ULL, 0x19F1FE6E2E4B59B2ULL, 0x58E9107379E98162ULL, 
            0x148DDD2DEE36EF65ULL, 0xDAD63A574A4C6863ULL, 0x1852B85C6B63ED14ULL, 0xC41C1B1195FEAA37ULL
        },
        {
            0x7C1462B2E035E775ULL, 0x8E2744CFCD4B4181ULL, 0x3E5275D6315697E3ULL, 0x2159CC01B12CEE43ULL, 
            0x452671E168F3D73DULL, 0x0B5705231A71E256ULL, 0x4B4CDCF0118EB2CEULL, 0x8343BEAAFEA7F54DULL, 
            0x09983543DB620791ULL, 0x3EE3B5DAD2149449ULL, 0x929F980E837E7D24ULL, 0xE51BAEE9EDA21573ULL, 
            0xACCA3A35218A880DULL, 0xEBE6763507649BF0ULL, 0xE213486829A4B705ULL, 0xDCF2F8F63AE19159ULL, 
            0x691ECCE14CC9FB45ULL, 0x91E59DA21E4723DEULL, 0x2458E0B064D4A6F4ULL, 0xCE748EC1C818D5C2ULL, 
            0x8AB1C26FD7E311C8ULL, 0xB2588D1309C1AD59ULL, 0x36F294C183760857ULL, 0x2929D20BB3D5A520ULL, 
            0x320E24C597BAF57BULL, 0xABF3C38497A55F36ULL, 0x66ACC96469077A81ULL, 0xD8B95763EE92A90EULL, 
            0x4199F66709994D34ULL, 0xE817E17F4B698EB7ULL, 0x809A6051B2477957ULL, 0x6601FBB3303EA16AULL
        },
        {
            0xC9621D8C53A1A575ULL, 0x0083217BDF786F19ULL, 0x442E0407327D80EFULL, 0x9B93147DC02AC6DAULL, 
            0x2E338EA97C78210EULL, 0x63174C4E3FC71812ULL, 0xA2E9410DE345F3F8ULL, 0x3EA756E26F506FABULL, 
            0xEF7F5169A4D7EF57ULL, 0xFB09B35A4F76EFA0ULL, 0xF53C3BDB8D1F823DULL, 0x3B5AC7BB28DE0371ULL, 
            0xCC354500FDFF1E18ULL, 0x99EC2D4ADD92A250ULL, 0x997479EAB7E5E11AULL, 0x955D56563B94DDFAULL, 
            0x35EB2BC9A7563ADBULL, 0x59981101F4DEF2D5ULL, 0x31C039769C9B65BEULL, 0xAFA256042620AB06ULL, 
            0x95E058405C221603ULL, 0xF0B71B32E26FF1DAULL, 0xF970128A80EAB16FULL, 0x147017CAA7A8A750ULL, 
            0xD2B9FF441DCFC95FULL, 0xA4F7689F3CA6147DULL, 0xFCE658D3EBD2F6D1ULL, 0x3C38BC3C5CFA9C1AULL, 
            0x7B0A84783BB3F7A4ULL, 0x93A1C26E9022225CULL, 0x345461CFD1BBED76ULL, 0x9F9EC47317761D3BULL
        },
        {
            0x0ABFB762222E7500ULL, 0x2628A7A53CB7D024ULL, 0xB23FF10EFB2F5E5EULL, 0x0469A11E8D81EDF8ULL, 
            0x706437E214CC9F3EULL, 0x66CDEDFDE94E2E87ULL, 0x1BCB14951939120CULL, 0x488C4BE69AF399A8ULL, 
            0x77E5CD6E87A4B699ULL, 0x7A1D5DFAA98C6796ULL, 0x264E8521CEE244B5ULL, 0x9759F62502AA2315ULL, 
            0x8A66AA8E1D1B8F3EULL, 0x0225B7A98195BB6DULL, 0xA232A4395142BAA0ULL, 0x80C79F5F66594145ULL, 
            0x991B469713EFD4D2ULL, 0xB19C89F0118B42BBULL, 0x0EB0ABF479F2AB60ULL, 0xFB6B5B8064247B53ULL, 
            0x9716FB9475AFF760ULL, 0x7E30C5DF9F062D10ULL, 0x0F9CAA11608EC226ULL, 0xD2A069B85C3FD600ULL, 
            0x27BC6A3FD9F106B6ULL, 0x29EE163E39514EE9ULL, 0x5E79D849B44087A2ULL, 0x37324FE3A1B1AEAAULL, 
            0x7EFC15EB384B6CB3ULL, 0x38A9C9C84716D785ULL, 0x5619E2CCC70074EEULL, 0xD8F2EC74F133CEB8ULL
        },
        {
            0x7347DA17DAC19E95ULL, 0x4966696B6AA118D4ULL, 0xEAFC7BFDCC19B8A2ULL, 0x105DBF9AAEA4E169ULL, 
            0x791F79F8F7783036ULL, 0x7A39D2FC1481A1FBULL, 0x4567EFBD3210F179ULL, 0x1A4C520A9BD6BAA7ULL, 
            0x3C79AFC38A4AF90DULL, 0xB86552346A48978EULL, 0x585A053925B64003ULL, 0x1C195868BC8521CAULL, 
            0xEB57F172121525CBULL, 0xF7DE8E3002078B0AULL, 0xDEE88E9B61749C3FULL, 0xECED3C1F93B8E027ULL, 
            0x48BC61BBC2CFC8CCULL, 0x937C07BDB68C6631ULL, 0x7633F30C2897C9FBULL, 0x59643A3D822BF0FAULL, 
            0x6988F9F0DB44D955ULL, 0x0B664565E483DF8AULL, 0xEEAF417354163F7DULL, 0x284BD39342A71CB9ULL, 
            0x8EA89E847BBBAD14ULL, 0x6F5D9B745E5F4C63ULL, 0xA252CF32019B4299ULL, 0xBE1ACE1D8058E5C1ULL, 
            0xAF2B64473C736839ULL, 0x03D1EE33646176ABULL, 0x4D46A90855BF170EULL, 0xC694B67AC419EFD4ULL
        }
    },
    {
        {
            0xEA7EC1E2D98DD6D6ULL, 0xE2D3E522D2FE3DF3ULL, 0xAA62E8CE0DD70B25ULL, 0xFB55D7A4114912E3ULL, 
            0x1B28CBF2948D38F1ULL, 0x23D4EA0BC079E255ULL, 0x0B2702D78CB11F4AULL, 0x3E92C7C610C39F08ULL, 
            0xFA2D3B9D3BD704C7ULL, 0xCBEDA490F6B975C2ULL, 0xBD4D50595F3DA707ULL, 0xB64E303254212CA4ULL, 
            0x78576756B9C3AB34ULL, 0x4CB89C16B636EF79ULL, 0x8BB18227F1AD5DBAULL, 0x1B088514A685737BULL, 
            0xA1490B7D1FBB2BBFULL, 0xC13D7BD884DC1194ULL, 0x6085D27045DBE80CULL, 0x32FB8B82BA5A76C3ULL, 
            0xFB6DDDEE9332372EULL, 0x02B44DA2C9E3E9F2ULL, 0xCADFE14F52AC3409ULL, 0x875D5C8920285958ULL, 
            0x3001C758303C324FULL, 0x8AB218179B7B7E29ULL, 0xF4943F4F093E1585ULL, 0x958302D4F3C905DAULL, 
            0x96246D16E7CC6FC8ULL, 0x266F156156153742ULL, 0xE6E292205AB31A37ULL, 0x7E47F946DA70CB91ULL
        },
        {
            0xC467E3BA774F0DC7ULL, 0xFCD6A9BE9489929AULL, 0x97C302468A9A55B8ULL, 0x25C29BC307611B6CULL, 
            0x72A499F8FB067DB8ULL, 0x21213B8822EFCF70ULL, 0xBE1A625D4B6DCD46ULL, 0xB4861EFB7B76AE15ULL, 
            0x5341F9819297466CULL, 0xB56BF47DDD8F8B39ULL, 0xBBE79F26E62DFA89ULL, 0x05110B909281D20AULL, 
            0xE5CDE7DD81F068CBULL, 0x4F66D254BEEFC75EULL, 0x5CFAEADA84D90589ULL, 0x14B326371939F1BAULL, 
            0xC13075EEB486289AULL, 0x050BA07090273D47ULL, 0x4DA551FEC9C9CD6EULL, 0x78C96AC30004B639ULL, 
            0xBD745E49F8E302D6ULL, 0xEF249F8262EFFEB5ULL, 0x2B5298CAF1EF1159ULL, 0x4BEDB9F36F556604ULL, 
            0xB8F893F76D8C9160ULL, 0xDB23165F1EFB11BFULL, 0x6ECEA50938A45E93ULL, 0x48C8BEEC670C77A2ULL, 
            0xE0B6D88D063480C6ULL, 0xF83438E9EA298781ULL, 0xCCD5F33A07F2E739ULL, 0xFCEC689C5BB1A7DAULL
        },
        {
            0xE154273704AB1A63ULL, 0x580823C7FCEA437CULL, 0x10052F9603D63823ULL, 0xF3B5F545EBE0FA91ULL, 
            0xEF7172B56DD51DE4ULL, 0x033DDD5ABE094357ULL, 0x5794A1F248F14319ULL, 0x490FE43365537A3FULL, 
            0x17AE72987823E066ULL, 0xEB579141F97B7937ULL, 0xE141E74CB423D431ULL, 0xE66A07A2E42CC236ULL, 
            0xFF2A15500297AD3FULL, 0xA2283456549FA42CULL, 0x83B79EAFE9E039E4ULL, 0xC1E5E52CB3317199ULL, 
            0xA1FF18E07807F9D2ULL, 0xC7E68DC96C599D31ULL, 0xC91FA428D23BEFA8ULL, 0xDAE79016C5643062ULL, 
            0x20FA3F51EB52FF17ULL, 0xB6BC506E784E4C39ULL, 0x4CE2DAE3B11FAF3BULL, 0x3C5B8175BD63DE2AULL, 
            0x7B43DF63BCEB6C5AULL, 0x136ADC56116A8C17ULL, 0xBA48D87C5A6D0B26ULL, 0x5BEE5420C4E77435ULL, 
            0x67604917F6E364E5ULL, 0x0C3141F6F23EBC5FULL, 0x684D9C41553E0978ULL, 0x7A1D5C13B4E1C3A7ULL
        },
        {
            0x4CB78A3F5F8083BCULL, 0x073CD0964378E59AULL, 0x14630856AA2C000EULL, 0x8E5E81D0637F6476ULL, 
            0x43FCC28781EFECC1ULL, 0x5BECB208AAB40412ULL, 0x5D2853DF4A12FFF4ULL, 0x1B6670F968A41F29ULL, 
            0xE774F706BE2EC7BBULL, 0x5E7E363D139AB304ULL, 0xCFD1E224C592B41AULL, 0x23CF365643DDF9A9ULL, 
            0x3EF80E191EA2C13AULL, 0x052143AB5630AB4AULL, 0xC95958FABFB4B377ULL, 0x57F93667D6210CC6ULL, 
            0x7570CBB8A13773F5ULL, 0xC44D2BEB962877F1ULL, 0xF86680E03DB2006AULL, 0xDC1CF54A3D9A5CF4ULL, 
            0xEFFB3B747A396B8CULL, 0x21F98949400AF16DULL, 0xA7C833A79BA141B9ULL, 0x32B9B7D42B03102CULL, 
            0x932C113D1240E20FULL, 0x42C2C7F7FF3C4F56ULL, 0xECC2BAED82432182ULL, 0x9C903B691467AAA8ULL, 
            0xCCED9E08309D061EULL, 0x2033783F834A3209ULL, 0x09C74CF8E5C51778ULL, 0xB52E6E8F8DB3EC54ULL
        },
        {
            0x050A14A32C29DB02ULL, 0xD87020B8F0F7609BULL, 0xF6D9A6976022D772ULL, 0x4AF0215FB936EE91ULL, 
            0x6B196F3789153013ULL, 0xA2AC73672B469FC9ULL, 0x8C45FE7A8AA13A0AULL, 0x3A05B3F822BF5010ULL, 
            0x80C7F3A7D8E27D29ULL, 0x941FDCA9BF47635DULL, 0xADF66AAD47266D19ULL, 0x5BD287F0D68BECC9ULL, 
            0x5E200948A3A9F98CULL, 0x60ED679AA5136206ULL, 0x82CBDD6DA75AE38DULL, 0x2C3FF27A2AA833F7ULL, 
            0xE44E214E321B1AE7ULL, 0x2D476A30334B9E95ULL, 0x08460D5703246765ULL, 0x1ADDAFB6EABE46CBULL, 
            0x3903BA806E38426AULL, 0xA284AA46814E035AULL, 0x5DC5025ED89A40A1ULL, 0x19CF489DD4B5E594ULL, 
            0xAE9533B62753361FULL, 0x5F894BDF8AC236D1ULL, 0x21698D25223A1237ULL, 0x0C85A85F54CCEDE7ULL, 
            0xCE7E9863E9612E44ULL, 0xE99367C9ADFFCADDULL, 0x26F3994FE9F5A536ULL, 0xE8724C6F4E6EA9BEULL
        },
        {
            0x57828F6D6EE3C99DULL, 0x81FBF2D44C50AFF3ULL, 0xC4C01A549748BFA4ULL, 0x24230214FE266ECCULL, 
            0x744043538BE71A8FULL, 0xFA64C756770B65EBULL, 0xBDDCB3A3AA2D4907ULL, 0x935FA62EAA73580FULL, 
            0x63A218398ED16B7CULL, 0x2DFDEF3A6F8BB64AULL, 0x42FB055FEADE123DULL, 0xD7D79E83EC30533BULL, 
            0xCBC7C1D907A207CFULL, 0x15877978D0B2BBCCULL, 0x0BE0982F498C2DE3ULL, 0x00A0BE4831885F82ULL, 
            0xFEE25B3C70347ADDULL, 0x7BA55D32A5E85F0BULL, 0x444974F5587C12BCULL, 0x14287842FE5D722FULL, 
            0x9FAAF1D8CE098782ULL, 0xFF5AB488FE036423ULL, 0xC7A4B4A54FEF6687ULL, 0x9AB500B3B43CA108ULL, 
            0x9BFF88C04502FB2FULL, 0xC083476466649D2AULL, 0xD27FE5FE46C274CDULL, 0xD4CCF2759C6F51A7ULL, 
            0x0F60E84450029E10ULL, 0x59035A9569738988ULL, 0x97C31AB79D152BC2ULL, 0xD9C212634CA366E7ULL
        }
    }
};

const TwistDomainConstants Candidate_A::kPhaseDConstants = {
    0x95FBEED72722669CULL,
    0x959B1B7D72EC9DECULL,
    0xC88CA735E6360997ULL,
    0x95FBEED72722669CULL,
    0x959B1B7D72EC9DECULL,
    0xC88CA735E6360997ULL,
    0x80111A93C22BA627ULL,
    0x1D5708D4E427AF27ULL,
    0x2D,
    0xDC,
    0x3E,
    0xD2,
    0x85,
    0x7C,
    0xB0,
    0x6A
};
