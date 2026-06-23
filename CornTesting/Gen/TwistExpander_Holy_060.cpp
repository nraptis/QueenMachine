#include "TwistExpander_Holy_060.hpp"
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

TwistExpander_Holy_060::TwistExpander_Holy_060()
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

void TwistExpander_Holy_060::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 13194946069812220172U;
        aCarry = 11060306122282105823U;
        aWandererA = 13436866756544171564U;
        aWandererB = 11899380193834133833U;
        aWandererC = 15980435220198670276U;
        aWandererD = 14912032128334385423U;
        aWandererE = 14058471821288443815U;
        aWandererF = 15998020490342946955U;
        aWandererG = 11272791938316332454U;
        aWandererH = 14617810150772258149U;
        aWandererI = 14875432395988072294U;
        aWandererJ = 10446806449589932355U;
        aWandererK = 12777663572918816528U;
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
            aIngress = aIngress ^ (RotL64(aNonceByteF, 3U) ^ RotL64(aNonceByteB, 46U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4810U)) & S_BLOCK1], 27U) ^ RotL64(mSnow[((aIndex + 3163U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteG, 21U) ^ RotL64(aNonceByteD, 29U)) ^ RotL64(aNonceByteC, 37U));
            aCross = aCross ^ (RotL64(mSnow[((S_BLOCK1 - aIndex + 2619U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4205U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 34U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 57U)) + 12775735908960052604U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 46U)) + 11791373812080296887U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 13U)) + 5537362877706057303U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6511U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 2023912048504189380U) + RotL64(aNonceByteA, 5U);
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 17668828109963766893U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 558908629933941224U;
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 1479633119685446888U) + aOrbiterAssignSaltC[((aIndex + 6982U)) & S_SALT1]) + RotL64(aNonceByteE, 60U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15460320397843364063U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9987633811929693924U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 2705U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10087337844580228269U) ^ RotL64(aNonceByteG, 41U);
            aOrbiterC = RotL64((aOrbiterC * 13817142288940843815U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4446204415503364254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9430197906134676162U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5435U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10611580584157624739U) + RotL64(aNonceByteB, 23U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9327201928815412810U) + aOrbiterUpdateSaltF[((aIndex + 6632U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltD[((aIndex + 7831U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13827717178378062047U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10675114832750356941U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8804440385852327267U;
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6008U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 36U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aNonceByteC, 27U));
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 6277U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 14U)) + aOrbiterD) + RotL64(aCarry, 19U)) + RotL64(aNonceByteH, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteF, 57U) ^ RotL64(aNonceByteE, 35U)) ^ RotL64(aNonceByteB, 46U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13743U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 11204U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteD, 19U) ^ RotL64(aNonceByteA, 11U));
            aCross = aCross ^ (RotL64(mSnow[((S_BLOCK1 - aIndex + 14808U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13236U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 54U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 11274974230580265396U;
            aOrbiterC = ((((aWandererI + RotL64(aCross, 12U)) + RotL64(aCarry, 21U)) + 16658438747342741547U) + aOrbiterAssignSaltA[((aIndex + 3669U)) & S_SALT1]) + RotL64(aNonceByteC, 15U);
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 16612986966106053844U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 5U)) + 9329502236843231290U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 43U)) + 14088261356708344656U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 13692608802007789581U) + aOrbiterAssignSaltB[((aIndex + 8049U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + 6824473946645682398U) + RotL64(aNonceByteF, 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2072915876348570040U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7420507753044460759U;
            aOrbiterH = RotL64((aOrbiterH * 13239288539564571257U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4677557318688502593U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15081678577055628459U;
            aOrbiterG = RotL64((aOrbiterG * 16659305295251177155U), 39U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 7026792817486507482U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4380U)) & S_SALT1]) + RotL64(aNonceByteE, 17U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7460U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6807734532159292872U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 1847U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9233542707022629190U) + RotL64(aNonceByteA, 54U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10878718669747466677U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8066049063548639241U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4803U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 861295180226875235U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9134969787937288583U;
            aOrbiterI = RotL64((aOrbiterI * 7565008208670843555U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 19U)) + RotL64(aNonceByteH, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 775U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltE[((aIndex + 2075U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterF, 46U));
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aNonceByteG, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteG, 5U) ^ RotL64(aNonceByteA, 18U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22770U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24436U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteH, 35U) ^ RotL64(aNonceByteD, 3U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 24501U)) & S_BLOCK1], 51U) ^ RotL64(mSnow[((aIndex + 22373U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 3339283916456813609U) + RotL64(aNonceByteB, 56U);
            aOrbiterK = (aWandererC + RotL64(aIngress, 29U)) + 11339086426180649584U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 21U)) + 16819191669329316585U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 8361916937762630725U) + aOrbiterAssignSaltD[((aIndex + 3255U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 18031328374429899857U) + aOrbiterAssignSaltF[((aIndex + 4686U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 18261756894092897276U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 60U)) + 4250319792907645666U) + RotL64(aNonceByteD, 9U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1492411503643460886U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17369549067879344180U;
            aOrbiterA = RotL64((aOrbiterA * 2947354306696216579U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7301713524358676722U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2985193736033012535U) ^ RotL64(aNonceByteF, 27U);
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14086975808140927408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18205555540941493267U) + aOrbiterUpdateSaltB[((aIndex + 4155U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterJ = RotL64((aOrbiterJ * 3009081009044782443U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9209505304067579944U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5699U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltF[((aIndex + 6219U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8811497120829041188U) + RotL64(pNonce, 55U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltA[((aIndex + 1292U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10080595991787801029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 44U)) + aOrbiterF) + RotL64(aCarry, 21U)) + RotL64(aNonceByteC, 41U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aNonceByteE, 43U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3188U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 1873U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 19U) ^ RotL64(aNonceByteC, 3U)) ^ RotL64(aNonceByteF, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25329U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 27685U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 27U) ^ RotL64(aNonceByteG, 35U)) ^ RotL64(aNonceByteH, 10U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28162U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 25684U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 54U)) + 10336802574069791273U) + RotL64(aNonceByteB, 25U);
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + 169025388197058936U) + aOrbiterAssignSaltC[((aIndex + 2421U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 37U)) + 6541354188379168846U) + aOrbiterAssignSaltE[((aIndex + 4745U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 16223920526599306104U;
            aOrbiterH = (aWandererC + RotL64(aCross, 47U)) + 12756613707692514808U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 5082475548176484035U) + RotL64(aNonceByteA, 55U);
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 4907435526952698526U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14236627073831834337U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11502511046130497584U) ^ RotL64(aNonceByteH, 41U);
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3679044835550219497U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltB[((aIndex + 4260U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4628253464169957835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltC[((aIndex + 2939U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3798386391743884889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterC = RotL64((aOrbiterC * 13086160171095077295U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9816600392407327227U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 235U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltD[((aIndex + 1620U)) & S_SALT1]) ^ RotL64(aNonceByteE, 21U);
            aOrbiterE = RotL64((aOrbiterE * 12503867584828289879U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4807797577690520554U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2492057261148595922U;
            aOrbiterB = RotL64((aOrbiterB * 9453302540675483005U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 5U)) + RotL64(aNonceByteD, 28U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5048U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5655U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterF, 60U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + RotL64(aNonceByteC, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteE, 3U) ^ RotL64(aNonceByteG, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2034U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6028U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteA, 3U) ^ RotL64(aNonceByteH, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4247U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 4274U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 29U)) + 17264605017518259932U) + aOrbiterAssignSaltB[((aIndex + 5464U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 53U)) + 15209184354580778643U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 21U)) + 3299527965014731384U) + RotL64(aNonceByteE, 23U);
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 16293096431816127821U;
            aOrbiterA = (aWandererB + RotL64(aCross, 11U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 41U)) + 9188018632448236358U) + aOrbiterAssignSaltF[(((31U - aIndex) + 2294U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 24U)) + RotL64(aCarry, 11U)) + 13420816400363406556U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 37U)) + 2485063384097917101U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 3089135816938128264U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 39U)) + 10730544971770435788U) + RotL64(aNonceByteC, 43U);
            aOrbiterI = (aWandererG + RotL64(aIngress, 13U)) + 10431767565618874806U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14883796491656899074U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13465877783538483706U;
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13322163435314643713U) + RotL64(aNonceByteF, 35U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltA[((aIndex + 302U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12337846092069506365U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4950101626975919939U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2596253994220103666U;
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18146616411403012772U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 39U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8414050129421955787U;
            aOrbiterG = RotL64((aOrbiterG * 14879448948196182863U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11739172334166341121U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7829U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7936637782633487291U;
            aOrbiterE = RotL64((aOrbiterE * 14940929920543800413U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3160044627483874242U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16816384076887379704U;
            aOrbiterI = RotL64((aOrbiterI * 5052772186568301951U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8101560104988710226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8851416379738817624U;
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9941784290055185679U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14495651885701938495U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7827U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1540692851998143607U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10599676325220702167U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16092000942942971187U;
            aOrbiterD = RotL64((aOrbiterD * 2457268192247656817U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16168470945107928109U) + RotL64(aNonceByteD, 21U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17264605017518259932U;
            aOrbiterK = RotL64((aOrbiterK * 15038386057529909273U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterK, 60U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5585U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 3195U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceByteB, 20U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterD, 48U)) + RotL64(aNonceByteG, 49U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteE, 51U) ^ RotL64(aNonceByteH, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9839U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10549U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 3U) ^ RotL64(aNonceByteB, 11U)) ^ RotL64(aNonceByteA, 54U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8322U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 10064U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 51U)) + 3339283916456813609U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 35U)) + 11339086426180649584U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 21U)) + 16819191669329316585U;
            aOrbiterK = (aWandererB + RotL64(aCross, 47U)) + 8361916937762630725U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 56U)) + 18031328374429899857U) + RotL64(aNonceByteC, 47U);
            aOrbiterB = ((aWandererK + RotL64(aCross, 43U)) + 18261756894092897276U) + aOrbiterAssignSaltE[((aIndex + 6509U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 23U)) + 4250319792907645666U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + 1492411503643460886U) + aOrbiterAssignSaltA[((aIndex + 4837U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 17369549067879344180U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 27U)) + 7301713524358676722U) + RotL64(aNonceByteF, 39U);
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 2985193736033012535U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14086975808140927408U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3831U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18205555540941493267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9209505304067579944U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3444U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8811497120829041188U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10080595991787801029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1981637172055758689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16463077485583119324U;
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8383837717361569465U) + RotL64(aNonceByteH, 27U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2788511294985017326U;
            aOrbiterK = RotL64((aOrbiterK * 2809163242875130677U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3529607472855930041U) + aOrbiterUpdateSaltC[((aIndex + 3446U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8850940802020173766U;
            aOrbiterB = RotL64((aOrbiterB * 7821450253655655943U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7469160295100147267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16973986572163482061U;
            aOrbiterA = RotL64((aOrbiterA * 15660743778376905023U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12371372942863279718U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12098525148034303633U) ^ RotL64(aNonceByteB, 60U);
            aOrbiterC = RotL64((aOrbiterC * 11234127652230231751U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5138683482859889480U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3339283916456813609U) ^ aOrbiterUpdateSaltD[((aIndex + 5611U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10975353228235695455U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 5139U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 44U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aCarry, 41U)) + RotL64(aNonceByteD, 55U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 3058U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aNonceByteG, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 38U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 14U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 19U) ^ RotL64(aNonceByteH, 29U)) ^ RotL64(aNonceByteA, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24462U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21282U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteG, 29U) ^ RotL64(aNonceByteC, 21U)) ^ RotL64(aNonceByteE, 48U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21364U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 20932U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 19U)) + 11274974230580265396U) + aOrbiterAssignSaltD[(((31U - aIndex) + 1078U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 35U)) + 16658438747342741547U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 54U)) + 16612986966106053844U) + RotL64(aNonceByteB, 61U);
            aOrbiterA = (aWandererC + RotL64(aCross, 5U)) + 9329502236843231290U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 41U)) + 14088261356708344656U) + aOrbiterAssignSaltC[((aIndex + 4327U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 13U)) + 13692608802007789581U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 51U)) + 6824473946645682398U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 2072915876348570040U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 7420507753044460759U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 24U)) + RotL64(aCarry, 39U)) + 4677557318688502593U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + 15081678577055628459U) + RotL64(aNonceByteA, 30U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7026792817486507482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14871665922943969918U;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6807734532159292872U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17882797335141303280U;
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9233542707022629190U) + aOrbiterUpdateSaltA[((aIndex + 453U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1205501586581350876U;
            aOrbiterB = RotL64((aOrbiterB * 2596053290311090589U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10878718669747466677U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6169U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8066049063548639241U;
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 861295180226875235U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltC[((aIndex + 4659U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 6726642007159809594U) + aOrbiterUpdateSaltE[((aIndex + 1405U)) & S_SALT1]) + RotL64(pNonce, 39U);
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8061661744643240470U;
            aOrbiterE = RotL64((aOrbiterE * 6703498926835391813U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13541412083111962884U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8617442758729315637U;
            aOrbiterC = RotL64((aOrbiterC * 15471862889276160953U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16884403561131293362U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9490680911678221233U) ^ RotL64(aNonceByteF, 49U);
            aOrbiterA = RotL64((aOrbiterA * 15988763830018001033U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10486145044311386738U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10200001044821063684U;
            aOrbiterD = RotL64((aOrbiterD * 16149790736141571017U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6997073594007878034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13585783612009989767U;
            aOrbiterI = RotL64((aOrbiterI * 11425303157774550449U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3847846040256340653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11274974230580265396U;
            aOrbiterJ = RotL64((aOrbiterJ * 13970270689108369205U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterH, 22U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 39U)) + RotL64(aNonceByteE, 17U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 4803U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterC, 40U)) + RotL64(aCarry, 19U)) + RotL64(aNonceByteG, 15U)) + aWandererUpdateSaltC[(((31U - aIndex) + 378U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 3U) ^ RotL64(aNonceByteA, 47U)) ^ RotL64(aNonceByteF, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32036U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 31320U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteG, 37U) ^ RotL64(aNonceByteH, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25755U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26251U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 5697928251815176134U) + RotL64(aNonceByteA, 21U);
            aOrbiterJ = ((aWandererD + RotL64(aCross, 54U)) + RotL64(aCarry, 5U)) + 337587740689259575U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 47U)) + 4927686903263973950U) + aOrbiterAssignSaltB[(((31U - aIndex) + 2867U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 57U)) + 3742409032569801033U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + 1608092659172197650U) + RotL64(aNonceByteG, 7U);
            aOrbiterF = (aWandererK + RotL64(aCross, 11U)) + 15848744267145717509U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 18U)) + 15300174177963339253U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 14162868453323648628U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 29U)) + 12020167069983729869U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 51U)) + 16259538291658723956U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 37U)) + 8516686212464112245U) + aOrbiterAssignSaltF[((aIndex + 3726U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15265344442454471986U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3050323350098829515U) ^ RotL64(aNonceByteE, 41U);
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1093356813820599238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15167726103772238440U;
            aOrbiterF = RotL64((aOrbiterF * 5719466863561311069U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15170797965325981472U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6701U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11186808881726573677U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14710892030473425181U) + aOrbiterUpdateSaltD[((aIndex + 7043U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 397194787697553904U) ^ aOrbiterUpdateSaltF[((aIndex + 679U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1273724124862533034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13018397560392545616U;
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9638716186445643730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7255587739807843785U;
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9272350563697399628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1040729335295009339U) ^ RotL64(aNonceByteB, 39U);
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12128124729613601747U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2285238815562202219U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4026U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15398840993074390573U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6339113298619163493U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5911895708485037040U;
            aOrbiterJ = RotL64((aOrbiterJ * 3271006139923200439U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7601399508218901328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5697928251815176134U;
            aOrbiterK = RotL64((aOrbiterK * 8184257916861355735U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 44U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aNonceByteC, 20U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 34U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceByteD, 25U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 6225U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 26U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[((aIndex + 3115U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceByteA, 13U) ^ RotL64(aNonceByteC, 34U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7919U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5804U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteH, 29U) ^ RotL64(aNonceByteF, 48U)) ^ RotL64(aNonceByteG, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6578U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1759U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 41U)) + 17264605017518259932U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 15209184354580778643U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + 3299527965014731384U) + RotL64(aNonceByteF, 35U);
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 16293096431816127821U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7787U)) & S_SALT1]) + RotL64(aNonceByteE, 49U);
            aOrbiterE = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 11031983436878828337U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 29U)) + 9188018632448236358U;
            aOrbiterA = (aWandererG + RotL64(aCross, 37U)) + 13420816400363406556U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 23U)) + 2485063384097917101U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 39U)) + 3089135816938128264U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5340U)) & S_SALT1];
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 10730544971770435788U) + aOrbiterUpdateSaltE[((aIndex + 6672U)) & S_SALT1]) + RotL64(aNonceByteD, 19U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10431767565618874806U) ^ aOrbiterUpdateSaltA[((aIndex + 7960U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4723078464590561545U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14883796491656899074U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 490U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13465877783538483706U;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13322163435314643713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3307316600284371955U;
            aOrbiterB = RotL64((aOrbiterB * 12337846092069506365U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4950101626975919939U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2596253994220103666U;
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17961706029559914243U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10321902557977495175U) ^ RotL64(aNonceByteA, 59U);
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18146616411403012772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11739172334166341121U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3160044627483874242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16816384076887379704U;
            aOrbiterH = RotL64((aOrbiterH * 5052772186568301951U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8101560104988710226U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltB[((aIndex + 7318U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16767420038937389027U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 4431U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterE, 22U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceByteB, 60U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 18U)) + aOrbiterI) + RotL64(aNonceByteH, 31U)) + aWandererUpdateSaltD[(((31U - aIndex) + 1911U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteH, 27U) ^ RotL64(aNonceByteB, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14265U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14566U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteC, 11U) ^ RotL64(aNonceByteE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13211U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 11741U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 58U)) + 10336802574069791273U;
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 169025388197058936U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 6541354188379168846U) + RotL64(aNonceByteG, 3U);
            aOrbiterF = ((((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 16223920526599306104U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5838U)) & S_SALT1]) + RotL64(aNonceByteD, 45U);
            aOrbiterI = ((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 12756613707692514808U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 43U)) + 5082475548176484035U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 13U)) + 4907435526952698526U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 35U)) + 14236627073831834337U) + aOrbiterAssignSaltA[((aIndex + 2959U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 21U)) + 11502511046130497584U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3679044835550219497U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4035U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10582608424233200966U) + RotL64(aNonceByteC, 59U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10449735026385340313U) ^ RotL64(aNonceByteF, 11U);
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4628253464169957835U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 1030U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9816600392407327227U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5392U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4807797577690520554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7909676419643119585U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 256053568910383007U;
            aOrbiterF = RotL64((aOrbiterF * 11965085163352053161U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16179914439220412472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3968867762761955845U;
            aOrbiterC = RotL64((aOrbiterC * 7473632378251893139U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7474832923901283742U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7979U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4736994731050735779U;
            aOrbiterA = RotL64((aOrbiterA * 9839654409121414047U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 58U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 5937U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aNonceByteA, 49U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 307U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 5U)) + RotL64(aNonceByteH, 60U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterJ, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteA, 3U) ^ RotL64(aNonceByteH, 42U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21161U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21042U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteD, 35U) ^ RotL64(aNonceByteG, 3U)) ^ RotL64(aNonceByteF, 44U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18824U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 22604U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 20U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 47U)) + 12775735908960052604U;
            aOrbiterF = (aWandererE + RotL64(aCross, 3U)) + 11791373812080296887U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 5537362877706057303U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 43U)) + 2023912048504189380U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + 17668828109963766893U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5510U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 29U)) + 558908629933941224U) + aOrbiterAssignSaltD[((aIndex + 6961U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 13U)) + 1479633119685446888U) + RotL64(aNonceByteA, 45U);
            aOrbiterC = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 15460320397843364063U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 13U)) + 10059749397555469054U) + RotL64(aNonceByteC, 9U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9987633811929693924U) + aOrbiterUpdateSaltB[((aIndex + 5961U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4446204415503364254U) + RotL64(aNonceByteE, 51U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5419U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9430197906134676162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10611580584157624739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9327201928815412810U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7890659377013147073U;
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10675114832750356941U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3469U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltA[((aIndex + 4760U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12871947817782057116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11015991745792051390U;
            aOrbiterD = RotL64((aOrbiterD * 17152451500505815031U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6320437975845673731U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 702457937087191287U) ^ RotL64(aNonceByteH, 40U);
            aOrbiterC = RotL64((aOrbiterC * 17491257114676739589U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16629064896250312921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterI, 56U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aNonceByteD, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 22U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 1821U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltA[((aIndex + 7751U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aNonceByteB, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 52U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteC, 46U) ^ RotL64(aNonceByteF, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32146U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 25059U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteB, 3U) ^ RotL64(aNonceByteD, 27U)) ^ RotL64(aNonceByteE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30854U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 27037U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aIngress, 5U)) + 11274974230580265396U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 18U)) + 16658438747342741547U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 43U)) + 16612986966106053844U) + RotL64(pNonce, 44U);
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 9329502236843231290U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7547U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 14088261356708344656U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 34U)) + 13692608802007789581U) + aOrbiterAssignSaltE[((aIndex + 3205U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 6824473946645682398U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 47U)) + 2072915876348570040U) + RotL64(aNonceByteH, 11U);
            aOrbiterG = (aWandererK + RotL64(aPrevious, 27U)) + 7420507753044460759U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4677557318688502593U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltB[((aIndex + 7939U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16659305295251177155U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7026792817486507482U) + RotL64(aNonceByteE, 61U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 1321U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 694073180313083145U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6807734532159292872U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltE[((aIndex + 455U)) & S_SALT1]) ^ RotL64(aNonceByteG, 9U);
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9233542707022629190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10878718669747466677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8066049063548639241U;
            aOrbiterK = RotL64((aOrbiterK * 3031382633089381605U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6726642007159809594U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8061661744643240470U;
            aOrbiterJ = RotL64((aOrbiterJ * 6703498926835391813U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13541412083111962884U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8617442758729315637U;
            aOrbiterG = RotL64((aOrbiterG * 15471862889276160953U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16884403561131293362U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9490680911678221233U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 1047U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15988763830018001033U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 18U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceByteB, 39U));
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 56U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 37U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceByteA, 7U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7854U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteA, 53U) ^ RotL64(aNonceByteE, 11U)) ^ RotL64(aNonceByteG, 24U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6589U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2584U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteB, 47U) ^ RotL64(aNonceByteC, 29U)) ^ RotL64(aNonceByteF, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4322U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4200U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererG + RotL64(aCross, 38U)) + RotL64(aCarry, 3U)) + 3339283916456813609U) + aOrbiterAssignSaltE[((aIndex + 7208U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 51U)) + 11339086426180649584U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 16819191669329316585U;
            aOrbiterB = ((((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 8361916937762630725U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7740U)) & S_SALT1]) + RotL64(aNonceByteD, 21U);
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 5U)) + 18031328374429899857U) + RotL64(pNonce, 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 18261756894092897276U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 2342U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4250319792907645666U;
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1492411503643460886U) + aOrbiterUpdateSaltA[((aIndex + 2265U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17369549067879344180U;
            aOrbiterE = RotL64((aOrbiterE * 2947354306696216579U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7301713524358676722U) + aOrbiterUpdateSaltC[((aIndex + 5041U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2985193736033012535U) ^ RotL64(aNonceByteB, 58U);
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14086975808140927408U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7497U)) & S_SALT1]) ^ RotL64(aNonceByteA, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18205555540941493267U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 52U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 5831U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 30U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 5U)) + RotL64(aNonceByteH, 23U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + RotL64(aNonceByteC, 61U)) + aWandererUpdateSaltF[((aIndex + 1947U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceByteH, 60U) ^ RotL64(aNonceByteA, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12670U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 13498U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteD, 37U) ^ RotL64(aNonceByteG, 29U)) ^ RotL64(aNonceByteB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13004U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15102U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 40U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 5697928251815176134U) + aOrbiterAssignSaltA[((aIndex + 5464U)) & S_SALT1];
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 337587740689259575U) + aOrbiterAssignSaltD[((aIndex + 5834U)) & S_SALT1]) + RotL64(aNonceByteB, 29U);
            aOrbiterF = (aWandererF + RotL64(aPrevious, 13U)) + 4927686903263973950U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 3742409032569801033U) + RotL64(aNonceByteF, 11U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 1608092659172197650U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15848744267145717509U) + aOrbiterUpdateSaltF[((aIndex + 4939U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15300174177963339253U;
            aOrbiterF = RotL64((aOrbiterF * 5771922862677667319U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14162868453323648628U) + RotL64(aNonceByteH, 8U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12020167069983729869U;
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16259538291658723956U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3177U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterC = RotL64((aOrbiterC * 4731296903548893627U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3722184575520553132U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4108U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5663609293306386784U) ^ RotL64(aNonceByteE, 53U);
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15265344442454471986U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltB[((aIndex + 7481U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceByteG, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 200U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aNonceByteC, 55U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 1807U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteF, 5U) ^ RotL64(aNonceByteH, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21012U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20309U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteD, 43U) ^ RotL64(aNonceByteB, 52U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19076U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 18681U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 54U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 35U)) + 11274974230580265396U) + aOrbiterAssignSaltB[(((31U - aIndex) + 2737U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 16658438747342741547U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4022U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 43U)) + 16612986966106053844U) + RotL64(aNonceByteH, 59U);
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 9329502236843231290U) + RotL64(aNonceByteG, 41U);
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 14088261356708344656U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13692608802007789581U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6824473946645682398U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5191U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13619437545775237601U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2072915876348570040U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7420507753044460759U) ^ RotL64(aNonceByteA, 11U);
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4677557318688502593U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 2216U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15081678577055628459U;
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7026792817486507482U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltC[((aIndex + 5589U)) & S_SALT1]) ^ RotL64(aNonceByteE, 36U);
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6807734532159292872U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6563U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15439872930381050291U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aNonceByteB, 39U)) + aWandererUpdateSaltC[((aIndex + 3142U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 14U)) + aOrbiterE) + RotL64(aCarry, 57U)) + RotL64(aNonceByteC, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 2547U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteF, 47U) ^ RotL64(aNonceByteG, 60U)) ^ RotL64(aNonceByteH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27936U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 31489U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 37U) ^ RotL64(aNonceByteB, 13U)) ^ RotL64(aNonceByteD, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28595U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 25551U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 60U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 17264605017518259932U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 22U)) + RotL64(aCarry, 23U)) + 15209184354580778643U) + RotL64(aNonceByteA, 17U);
            aOrbiterB = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 3299527965014731384U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 3U)) + 16293096431816127821U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5552U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aScatter, 53U)) + 11031983436878828337U) + aOrbiterAssignSaltE[((aIndex + 2185U)) & S_SALT1]) + RotL64(aNonceByteC, 55U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 9188018632448236358U) + aOrbiterUpdateSaltC[((aIndex + 7164U)) & S_SALT1]) + RotL64(aNonceByteH, 36U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13420816400363406556U;
            aOrbiterB = RotL64((aOrbiterB * 10958221259662190519U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2485063384097917101U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 871U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3089135816938128264U;
            aOrbiterI = RotL64((aOrbiterI * 8813152992957361153U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10730544971770435788U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10431767565618874806U;
            aOrbiterF = RotL64((aOrbiterF * 4723078464590561545U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 14883796491656899074U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 677U)) & S_SALT1]) + RotL64(aNonceByteD, 57U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterK = RotL64((aOrbiterK * 14311686051108108503U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13322163435314643713U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltE[((aIndex + 279U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 52U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 4505U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5011U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 57U)) + RotL64(aNonceByteB, 61U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aNonceByteE, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)
}

void TwistExpander_Holy_060::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 11229165716677456057U;
        aCarry = 13386974850747535323U;
        aWandererA = 13551699153221812451U;
        aWandererB = 9853114581165481798U;
        aWandererC = 13743437363753158927U;
        aWandererD = 12706662720622809832U;
        aWandererE = 17394155006307673995U;
        aWandererF = 11140153128125076184U;
        aWandererG = 13842304148549098300U;
        aWandererH = 11776332951314989228U;
        aWandererI = 12092334092208734061U;
        aWandererJ = 12035919014932488772U;
        aWandererK = 10293102541763231415U;
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
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 46U) ^ RotL64(aNonceByteE, 5U)) ^ RotL64(aNonceByteD, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2943U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4485U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteF, 50U) ^ RotL64(aNonceByteA, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2462U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3308U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 3339283916456813609U) + aOrbiterAssignSaltA[((aIndex + 3195U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 27U)) + 11339086426180649584U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 11U)) + 16819191669329316585U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6511U)) & S_SALT1]) + RotL64(aNonceByteB, 53U);
            aOrbiterG = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 8361916937762630725U) + RotL64(aNonceByteF, 7U);
            aOrbiterH = (aWandererK + RotL64(aScatter, 51U)) + 18031328374429899857U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18261756894092897276U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4250319792907645666U) ^ aOrbiterUpdateSaltF[((aIndex + 7206U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7053489184750217963U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1492411503643460886U) + RotL64(aNonceByteG, 5U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17369549067879344180U;
            aOrbiterE = RotL64((aOrbiterE * 2947354306696216579U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7301713524358676722U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 2710U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14086975808140927408U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltC[((aIndex + 5917U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18205555540941493267U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3957U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16967799565443938873U) ^ RotL64(aNonceByteH, 22U);
            aOrbiterH = RotL64((aOrbiterH * 3009081009044782443U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aNonceByteD, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 47U)) + RotL64(aNonceByteC, 49U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltA[((aIndex + 5795U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 54U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7895U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteB, 43U) ^ RotL64(aNonceByteD, 11U)) ^ RotL64(aNonceByteG, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14201U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 13499U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteE, 10U) ^ RotL64(aNonceByteH, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13670U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13737U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 5697928251815176134U) + RotL64(aNonceByteC, 27U);
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 337587740689259575U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + 4927686903263973950U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6807U)) & S_SALT1];
            aOrbiterK = ((((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 3742409032569801033U) + aOrbiterAssignSaltF[(((31U - aIndex) + 2683U)) & S_SALT1]) + RotL64(aNonceByteE, 35U);
            aOrbiterC = (aWandererD + RotL64(aIngress, 13U)) + 1608092659172197650U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 15848744267145717509U) + aOrbiterUpdateSaltA[((aIndex + 885U)) & S_SALT1]) + RotL64(aNonceByteA, 29U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15300174177963339253U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4619U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5771922862677667319U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14162868453323648628U) + aOrbiterUpdateSaltE[((aIndex + 2042U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12020167069983729869U;
            aOrbiterC = RotL64((aOrbiterC * 2071080217680099017U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16259538291658723956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8516686212464112245U;
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15265344442454471986U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltF[((aIndex + 2960U)) & S_SALT1]) ^ RotL64(aNonceByteG, 19U);
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 38U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererC = aWandererC + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aCarry, 3U)) + RotL64(aNonceByteH, 14U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5959U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + RotL64(aNonceByteF, 37U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 44U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 1710U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 21U) ^ RotL64(aNonceByteC, 39U)) ^ RotL64(aNonceByteH, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19770U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 20776U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 39U) ^ RotL64(aNonceByteB, 27U)) ^ RotL64(aNonceByteG, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20791U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16770U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 10336802574069791273U) + RotL64(aNonceByteD, 29U);
            aOrbiterH = ((aWandererG + RotL64(aCross, 40U)) + RotL64(aCarry, 51U)) + 169025388197058936U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 53U)) + 6541354188379168846U) + aOrbiterAssignSaltB[((aIndex + 6085U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 16223920526599306104U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 13U)) + 12756613707692514808U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5583U)) & S_SALT1]) + RotL64(aNonceByteA, 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5082475548176484035U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4907435526952698526U;
            aOrbiterD = RotL64((aOrbiterD * 1379692095754989215U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14236627073831834337U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11502511046130497584U) ^ RotL64(aNonceByteG, 16U);
            aOrbiterH = RotL64((aOrbiterH * 3460330807286625917U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3679044835550219497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltB[((aIndex + 1971U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10582608424233200966U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3479U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4628253464169957835U) + aOrbiterUpdateSaltA[((aIndex + 763U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5390U)) & S_SALT1]) ^ RotL64(aNonceByteH, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterF) + RotL64(aCarry, 57U)) + RotL64(aNonceByteC, 61U)) + aWandererUpdateSaltF[((aIndex + 2480U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 5941U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 60U)) + aOrbiterF) + RotL64(aNonceByteF, 25U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteF, 21U) ^ RotL64(aNonceByteE, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31559U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 28047U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 3U) ^ RotL64(aNonceByteB, 21U)) ^ RotL64(aNonceByteG, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30175U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((aIndex + 30559U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 53U)) + 11274974230580265396U) + aOrbiterAssignSaltE[((aIndex + 7483U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 16658438747342741547U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 5U)) + 16612986966106053844U) + RotL64(pNonce, 37U);
            aOrbiterF = ((((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 9329502236843231290U) + aOrbiterAssignSaltA[(((31U - aIndex) + 2833U)) & S_SALT1]) + RotL64(aNonceByteA, 28U);
            aOrbiterA = (aWandererC + RotL64(aIngress, 27U)) + 14088261356708344656U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13692608802007789581U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6824473946645682398U;
            aOrbiterH = RotL64((aOrbiterH * 13619437545775237601U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2072915876348570040U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7420507753044460759U;
            aOrbiterI = RotL64((aOrbiterI * 13239288539564571257U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4677557318688502593U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 2611U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16659305295251177155U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7026792817486507482U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7549U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltF[((aIndex + 5818U)) & S_SALT1]) ^ RotL64(aNonceByteF, 59U);
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 6807734532159292872U) + aOrbiterUpdateSaltA[((aIndex + 5552U)) & S_SALT1]) + RotL64(aNonceByteH, 35U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17882797335141303280U;
            aOrbiterA = RotL64((aOrbiterA * 15439872930381050291U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5927U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 41U)) + RotL64(aNonceByteD, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 2883U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + RotL64(aNonceByteB, 25U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 3U) ^ RotL64(aNonceByteH, 12U)) ^ RotL64(aNonceByteB, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2685U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5231U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteF, 13U) ^ RotL64(aNonceByteD, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5476U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1062U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aPrevious, 43U)) + 5697928251815176134U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 21U)) + 337587740689259575U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 27U)) + 4927686903263973950U) + RotL64(aNonceByteG, 31U);
            aOrbiterG = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 3742409032569801033U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 1608092659172197650U) + aOrbiterAssignSaltE[((aIndex + 3076U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 15848744267145717509U) + RotL64(aNonceByteC, 61U);
            aOrbiterE = ((aWandererI + RotL64(aCross, 34U)) + 15300174177963339253U) + aOrbiterAssignSaltC[((aIndex + 3451U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14162868453323648628U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12020167069983729869U;
            aOrbiterH = RotL64((aOrbiterH * 2071080217680099017U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16259538291658723956U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8516686212464112245U;
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3722184575520553132U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltF[((aIndex + 6229U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15265344442454471986U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4406U)) & S_SALT1]) ^ RotL64(aNonceByteH, 29U);
            aOrbiterE = RotL64((aOrbiterE * 5890624677162388135U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1093356813820599238U) + RotL64(aNonceByteE, 5U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15167726103772238440U;
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15170797965325981472U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3335U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14710892030473425181U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 397194787697553904U) ^ aOrbiterUpdateSaltD[((aIndex + 4855U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14368930300818752833U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 12U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 47U)) + RotL64(aNonceByteA, 25U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + RotL64(aNonceByteB, 12U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltC[((aIndex + 3251U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterE, 20U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltD[((aIndex + 4344U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteB, 10U) ^ RotL64(aNonceByteD, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10593U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15511U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteG, 3U) ^ RotL64(aNonceByteH, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11149U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10336U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 10336802574069791273U) + aOrbiterAssignSaltB[(((31U - aIndex) + 2054U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 169025388197058936U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 12U)) + 6541354188379168846U) + RotL64(aNonceByteF, 49U);
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 16223920526599306104U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 39U)) + 12756613707692514808U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 23U)) + 5082475548176484035U) + RotL64(aNonceByteG, 59U);
            aOrbiterK = ((aWandererI + RotL64(aCross, 29U)) + 4907435526952698526U) + aOrbiterAssignSaltF[(((31U - aIndex) + 2019U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14236627073831834337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11502511046130497584U;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3679044835550219497U) + RotL64(pNonce, 4U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10582608424233200966U) + RotL64(aNonceByteE, 5U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4628253464169957835U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6295U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4234720298731378527U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3798386391743884889U) + aOrbiterUpdateSaltB[((aIndex + 4427U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltA[((aIndex + 6707U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9816600392407327227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16781971616348376878U;
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4807797577690520554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2492057261148595922U) ^ aOrbiterUpdateSaltC[((aIndex + 6460U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 36U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 6U)) + aOrbiterB) + RotL64(aCarry, 37U)) + RotL64(aNonceByteA, 21U)) + aWandererUpdateSaltE[((aIndex + 2505U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + RotL64(aNonceByteC, 45U)) + aWandererUpdateSaltB[((aIndex + 1936U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteD, 51U) ^ RotL64(aNonceByteA, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23139U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 23911U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteG, 19U) ^ RotL64(aNonceByteH, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20452U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21063U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 3339283916456813609U) + aOrbiterAssignSaltD[((aIndex + 7467U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 11339086426180649584U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 43U)) + 16819191669329316585U) + aOrbiterAssignSaltA[((aIndex + 6311U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 8361916937762630725U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 3U)) + 18031328374429899857U) + RotL64(aNonceByteH, 12U);
            aOrbiterI = (((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 18261756894092897276U) + RotL64(aNonceByteC, 49U);
            aOrbiterA = (aWandererE + RotL64(aCross, 51U)) + 4250319792907645666U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1492411503643460886U) + aOrbiterUpdateSaltB[((aIndex + 2650U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17369549067879344180U;
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7301713524358676722U) + RotL64(aNonceByteB, 3U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2985193736033012535U) ^ RotL64(aNonceByteD, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14086975808140927408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 18205555540941493267U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 1136U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9209505304067579944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8811497120829041188U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltF[((aIndex + 1745U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10080595991787801029U) + aOrbiterUpdateSaltE[((aIndex + 1071U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6822892187784299166U;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 40U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aNonceByteE, 41U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5385U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 46U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceByteF, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 3698U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteF, 24U) ^ RotL64(aNonceByteB, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28485U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30305U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteC, 57U) ^ RotL64(aNonceByteH, 39U)) ^ RotL64(aNonceByteA, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27848U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27778U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 11274974230580265396U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 41U)) + 16658438747342741547U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + 16612986966106053844U) + aOrbiterAssignSaltE[(((31U - aIndex) + 1844U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 23U)) + 9329502236843231290U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 14088261356708344656U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 3U)) + 13692608802007789581U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6459U)) & S_SALT1]) + RotL64(aNonceByteA, 43U);
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + 6824473946645682398U) + RotL64(aNonceByteG, 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2072915876348570040U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltC[((aIndex + 8024U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13239288539564571257U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4677557318688502593U) + RotL64(aNonceByteD, 35U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterG = RotL64((aOrbiterG * 16659305295251177155U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7026792817486507482U) + aOrbiterUpdateSaltD[((aIndex + 7577U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6128U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 694073180313083145U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6807734532159292872U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 1509U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17882797335141303280U;
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9233542707022629190U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1205501586581350876U) ^ RotL64(aNonceByteH, 9U);
            aOrbiterC = RotL64((aOrbiterC * 2596053290311090589U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10878718669747466677U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 861295180226875235U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterH = RotL64((aOrbiterH * 7565008208670843555U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aNonceByteB, 55U)) + aWandererUpdateSaltC[((aIndex + 2344U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 1165U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + RotL64(aNonceByteE, 46U));
            aWandererE = aWandererE + ((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 4U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceByteC, 20U) ^ RotL64(aNonceByteF, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1616U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5368U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteD, 53U) ^ RotL64(aNonceByteG, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3132U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 230U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 53U)) + 12775735908960052604U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7539U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 22U)) + 11791373812080296887U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 57U)) + 5537362877706057303U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 37U)) + 2023912048504189380U) + RotL64(aNonceByteE, 55U);
            aOrbiterC = (aWandererD + RotL64(aIngress, 27U)) + 17668828109963766893U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 558908629933941224U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 1479633119685446888U) + aOrbiterAssignSaltC[(((31U - aIndex) + 1908U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 15460320397843364063U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 4U)) + 10059749397555469054U) + RotL64(aNonceByteG, 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9987633811929693924U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltA[((aIndex + 2330U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4446204415503364254U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9430197906134676162U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3897U)) & S_SALT1]) ^ RotL64(aNonceByteA, 59U);
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10611580584157624739U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5173U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 9327201928815412810U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5030U)) & S_SALT1]) + RotL64(aNonceByteB, 13U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterA = RotL64((aOrbiterA * 13827717178378062047U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12871947817782057116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11015991745792051390U;
            aOrbiterE = RotL64((aOrbiterE * 17152451500505815031U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6320437975845673731U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 702457937087191287U;
            aOrbiterD = RotL64((aOrbiterD * 17491257114676739589U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16629064896250312921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6054107387816339103U;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceByteC, 9U));
            aWandererF = aWandererF + ((((RotL64(aCross, 44U) + RotL64(aOrbiterG, 60U)) + aOrbiterD) + RotL64(aCarry, 39U)) + RotL64(aNonceByteH, 24U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 2488U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 1871U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 39U) ^ RotL64(aNonceByteF, 30U)) ^ RotL64(aNonceByteA, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13788U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11142U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteB, 51U) ^ RotL64(aNonceByteD, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8777U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12694U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 3339283916456813609U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 37U)) + 11339086426180649584U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 16819191669329316585U) + RotL64(aNonceByteF, 45U);
            aOrbiterH = (aWandererI + RotL64(aIngress, 60U)) + 8361916937762630725U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 11U)) + 18031328374429899857U;
            aOrbiterI = (aWandererG + RotL64(aCross, 27U)) + 18261756894092897276U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + 4250319792907645666U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3654U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 11U)) + 1492411503643460886U) + RotL64(aNonceByteE, 11U);
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + 17369549067879344180U) + aOrbiterAssignSaltE[((aIndex + 2844U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7301713524358676722U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14086975808140927408U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6448U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18205555540941493267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9209505304067579944U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5998U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8811497120829041188U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14707301680850257294U) ^ RotL64(aNonceByteH, 55U);
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10080595991787801029U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6822892187784299166U;
            aOrbiterD = RotL64((aOrbiterD * 7417016898027778287U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1981637172055758689U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16463077485583119324U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6185U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8383837717361569465U) + RotL64(aNonceByteG, 31U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3529607472855930041U) + aOrbiterUpdateSaltE[((aIndex + 2395U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8850940802020173766U;
            aOrbiterK = RotL64((aOrbiterK * 7821450253655655943U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 52U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 56U)) + aOrbiterH) + RotL64(aNonceByteB, 18U)) + aWandererUpdateSaltC[(((31U - aIndex) + 2676U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + RotL64(aNonceByteC, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltA[((aIndex + 6995U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 60U));
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + ((RotL64(aCross, 42U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceByteH, 39U) ^ RotL64(aNonceByteE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22563U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23861U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteB, 39U) ^ RotL64(aNonceByteC, 50U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20042U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 17844U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 57U)) + 17264605017518259932U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 29U)) + 15209184354580778643U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 24U)) + RotL64(aCarry, 47U)) + 3299527965014731384U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 16293096431816127821U;
            aOrbiterD = (aWandererE + RotL64(aCross, 11U)) + 11031983436878828337U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 19U)) + 9188018632448236358U) + aOrbiterAssignSaltD[((aIndex + 3261U)) & S_SALT1]) + RotL64(aNonceByteA, 35U);
            aOrbiterJ = (aWandererG + RotL64(aScatter, 5U)) + 13420816400363406556U;
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 2485063384097917101U) + aOrbiterAssignSaltB[(((31U - aIndex) + 48U)) & S_SALT1]) + RotL64(aNonceByteG, 59U);
            aOrbiterE = (aWandererA + RotL64(aPrevious, 42U)) + 3089135816938128264U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10730544971770435788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14883796491656899074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13322163435314643713U) + aOrbiterUpdateSaltB[((aIndex + 197U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4950101626975919939U) + RotL64(aNonceByteE, 21U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltD[((aIndex + 7331U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17961706029559914243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10321902557977495175U;
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18146616411403012772U) + RotL64(aNonceByteH, 4U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8414050129421955787U;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11739172334166341121U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7936637782633487291U;
            aOrbiterJ = RotL64((aOrbiterJ * 14940929920543800413U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3160044627483874242U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4335U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16816384076887379704U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 661U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5052772186568301951U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8101560104988710226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8851416379738817624U;
            aOrbiterE = RotL64((aOrbiterE * 16767420038937389027U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 2126U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceByteF, 49U));
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 24U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + RotL64(aNonceByteD, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 6U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 8136U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteD, 51U) ^ RotL64(aNonceByteC, 23U)) ^ RotL64(aNonceByteE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25298U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 26525U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteH, 51U) ^ RotL64(aNonceByteG, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28536U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 27736U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 47U)) + (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 5697928251815176134U) + RotL64(aNonceByteA, 34U);
            aOrbiterG = (aWandererE + RotL64(aIngress, 39U)) + 337587740689259575U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 21U)) + 4927686903263973950U) + RotL64(pNonce, 45U);
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + 3742409032569801033U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 57U)) + 1608092659172197650U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 15848744267145717509U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6930U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 15300174177963339253U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 14162868453323648628U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 14U)) + 12020167069983729869U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16259538291658723956U) + aOrbiterUpdateSaltD[((aIndex + 687U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterH = RotL64((aOrbiterH * 4731296903548893627U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3722184575520553132U) + RotL64(aNonceByteF, 3U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5765U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15265344442454471986U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1093356813820599238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14710892030473425181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 397194787697553904U;
            aOrbiterD = RotL64((aOrbiterD * 14368930300818752833U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1273724124862533034U) + aOrbiterUpdateSaltE[((aIndex + 2711U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 346U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4644812473262395329U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9272350563697399628U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1040729335295009339U) ^ RotL64(aNonceByteE, 15U);
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 3177U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 34U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + RotL64(aNonceByteB, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 525U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 4U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceByteG, 37U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)
}

void TwistExpander_Holy_060::Seed(TwistWorkSpace *pWorkSpace,
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
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseA invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseB invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseC invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseD invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    }
    // KDF_B PhaseE invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    }
    // KDF_B PhaseF invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    }
    // KDF_B PhaseG invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseH invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceByteH, 19U) ^ RotL64(aNonceByteD, 27U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 741U)) & S_BLOCK1], 10U) ^ RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 7093U)) & (S_KEY_A - 1)], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteG, 23U) ^ RotL64(aNonceByteC, 10U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 635U)) & (S_KEY_B - 1)], 43U) ^ RotL64(aKeyBoxUnrolledA[((aIndex + 4590U)) & (S_KEY_A - 1)], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aScatter, 27U)) + 10336802574069791273U) + aPhaseAOrbiterAssignSaltA[((aIndex + 2989U)) & S_SALT1]) + RotL64(aNonceByteE, 27U);
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 53U)) + 169025388197058936U;
            aOrbiterB = (aWandererK + RotL64(aCross, 11U)) + 6541354188379168846U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 60U)) + 16223920526599306104U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 12756613707692514808U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5911U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 5082475548176484035U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 4907435526952698526U) + RotL64(aNonceByteH, 20U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14236627073831834337U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11502511046130497584U;
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3679044835550219497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4628253464169957835U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3920U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17664454668473204465U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 2663U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3798386391743884889U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 1379331161819246587U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3411U)) & S_SALT1]) ^ RotL64(aNonceByteC, 43U);
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9816600392407327227U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 16781971616348376878U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 1205U)) & S_SALT1]) ^ RotL64(aNonceByteB, 29U);
            aOrbiterG = RotL64((aOrbiterG * 12503867584828289879U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4807797577690520554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2492057261148595922U;
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterK, 42U)) + RotL64(aCarry, 23U)) + RotL64(aNonceByteF, 61U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK + ((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 51U)) + RotL64(aNonceByteA, 59U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + aPhaseAWandererUpdateSaltF[((aIndex + 5020U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aPhaseAWandererUpdateSaltA[((aIndex + 4921U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteC, 21U) ^ RotL64(aNonceByteF, 51U)) ^ RotL64(aNonceByteB, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11892U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14723U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceByteE, 11U) ^ RotL64(aNonceByteD, 57U)) ^ RotL64(aNonceByteA, 3U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 12259U)) & (S_KEY_A - 1)], 22U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 8728U)) & (S_KEY_B - 1)], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 41U)) + 3339283916456813609U) + aPhaseAOrbiterAssignSaltF[((aIndex + 949U)) & S_SALT1]) + RotL64(aNonceByteG, 49U);
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 11339086426180649584U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 47U)) + 16819191669329316585U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 8361916937762630725U) + RotL64(aNonceByteH, 59U);
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 18031328374429899857U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 19U)) + 18261756894092897276U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 56U)) + 4250319792907645666U) + aPhaseAOrbiterAssignSaltC[((aIndex + 1034U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1492411503643460886U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 2748U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17369549067879344180U) ^ RotL64(aNonceByteC, 29U);
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7301713524358676722U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 2414U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18205555540941493267U) + RotL64(pNonce, 38U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16967799565443938873U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 2469U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9209505304067579944U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterE = RotL64((aOrbiterE * 3441982898533162599U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8811497120829041188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10080595991787801029U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6391U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterB = RotL64((aOrbiterB * 7417016898027778287U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 10U)) + aOrbiterI);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 5U)) + RotL64(aNonceByteE, 5U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 6189U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 2968U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceByteF, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceByteE, 27U) ^ RotL64(aNonceByteF, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16738U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 19790U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteB, 57U) ^ RotL64(aNonceByteH, 5U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 21999U)) & (S_KEY_A - 1)], 23U) ^ RotL64(aKeyBoxUnrolledB[((aIndex + 19843U)) & (S_KEY_B - 1)], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 12775735908960052604U) + RotL64(aNonceByteG, 45U);
            aOrbiterD = (aWandererB + RotL64(aIngress, 3U)) + 11791373812080296887U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 5537362877706057303U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5197U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 27U)) + 2023912048504189380U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 17668828109963766893U) + RotL64(aNonceByteA, 50U);
            aOrbiterI = (aWandererE + RotL64(aCross, 20U)) + 558908629933941224U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 47U)) + 1479633119685446888U) + aPhaseAOrbiterAssignSaltB[((aIndex + 1907U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15460320397843364063U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10059749397555469054U;
            aOrbiterC = RotL64((aOrbiterC * 8671817118586065469U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9987633811929693924U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3852U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10087337844580228269U) ^ RotL64(aNonceByteC, 7U);
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4446204415503364254U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15106063243302192717U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 1413U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 2261U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10611580584157624739U) + RotL64(aNonceByteH, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9327201928815412810U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4599U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10675114832750356941U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8804440385852327267U;
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5033U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceByteD, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 231U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 39U)) + RotL64(aNonceByteB, 25U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 22U)) + aOrbiterH) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceByteG, 35U) ^ RotL64(aNonceByteA, 13U)) ^ RotL64(aNonceByteD, 52U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25368U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27797U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceByteC, 47U) ^ RotL64(aNonceByteB, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26853U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29669U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 29U)) + 11274974230580265396U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3798U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 23U)) + 16658438747342741547U) + RotL64(aNonceByteE, 26U);
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 51U)) + 16612986966106053844U) + RotL64(aNonceByteB, 7U);
            aOrbiterE = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 9329502236843231290U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 14088261356708344656U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + 13692608802007789581U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 3900U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 6824473946645682398U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2072915876348570040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7420507753044460759U;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4677557318688502593U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 2475U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7026792817486507482U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 2129U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6807734532159292872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17882797335141303280U) ^ RotL64(aNonceByteF, 45U);
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9233542707022629190U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1205501586581350876U) ^ RotL64(aNonceByteH, 37U);
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10878718669747466677U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5959U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 861295180226875235U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9134969787937288583U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 4717U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + RotL64(aNonceByteA, 17U)) + aPhaseAWandererUpdateSaltA[((aIndex + 5177U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterE, 36U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceByteG, 35U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 3983U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2207U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 806U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2883U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 3076U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 56U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 12775735908960052604U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 46U)) + 11791373812080296887U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3485U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 5537362877706057303U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 2023912048504189380U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 1607U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 57U)) + 17668828109963766893U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 558908629933941224U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1479633119685446888U;
            aOrbiterB = RotL64((aOrbiterB * 4447153373540811385U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15460320397843364063U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8137U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10059749397555469054U;
            aOrbiterE = RotL64((aOrbiterE * 8671817118586065469U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9987633811929693924U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 69U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10087337844580228269U;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4446204415503364254U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5364U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9430197906134676162U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 2636U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 58U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltF[((aIndex + 6898U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aPhaseBWandererUpdateSaltD[((aIndex + 2500U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13347U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 8956U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8385U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 13901U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 35U)) + 17264605017518259932U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 15209184354580778643U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 6517U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 3299527965014731384U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 51U)) + 16293096431816127821U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 43U)) + 11031983436878828337U) + aPhaseBOrbiterAssignSaltF[((aIndex + 1821U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9188018632448236358U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3627U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13420816400363406556U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 463U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10958221259662190519U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2485063384097917101U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3089135816938128264U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6574U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8813152992957361153U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10730544971770435788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14883796491656899074U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13465877783538483706U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3724U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13322163435314643713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4298U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 52U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 483U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17651U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21506U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23056U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 23622U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 42U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 11274974230580265396U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5339U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 16658438747342741547U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 4149U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 16612986966106053844U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 47U)) + 9329502236843231290U;
            aOrbiterI = (aWandererG + RotL64(aCross, 12U)) + 14088261356708344656U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13692608802007789581U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 2200U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6824473946645682398U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 925U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13619437545775237601U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2072915876348570040U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 2637U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7420507753044460759U;
            aOrbiterK = RotL64((aOrbiterK * 13239288539564571257U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4677557318688502593U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7026792817486507482U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14871665922943969918U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 2160U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6807734532159292872U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17882797335141303280U;
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 4U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 42U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 313U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3723U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26425U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24643U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29700U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24580U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 10336802574069791273U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 169025388197058936U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 2577U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 12U)) + RotL64(aCarry, 11U)) + 6541354188379168846U;
            aOrbiterE = (aWandererF + RotL64(aCross, 23U)) + 16223920526599306104U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 35U)) + 12756613707692514808U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5078U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5082475548176484035U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5977U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4907435526952698526U;
            aOrbiterD = RotL64((aOrbiterD * 1379692095754989215U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14236627073831834337U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5395U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11502511046130497584U;
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3679044835550219497U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 5554U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11254838916686736746U;
            aOrbiterE = RotL64((aOrbiterE * 8631695922983532915U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4628253464169957835U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17664454668473204465U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 924U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 34U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterF, 42U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltF[((aIndex + 1944U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltD[((aIndex + 7023U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1630U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((aIndex + 6220U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5768U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1502U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 3339283916456813609U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 1832U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 11339086426180649584U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 13U)) + 16819191669329316585U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 4871U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 41U)) + 8361916937762630725U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 19U)) + 18031328374429899857U;
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 18261756894092897276U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 57U)) + 4250319792907645666U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 4U)) + 1492411503643460886U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 53U)) + 17369549067879344180U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 39U)) + 7301713524358676722U;
            aOrbiterI = (aWandererG + RotL64(aCross, 41U)) + 2985193736033012535U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14086975808140927408U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18205555540941493267U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterH = RotL64((aOrbiterH * 3009081009044782443U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9209505304067579944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8811497120829041188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10080595991787801029U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1981637172055758689U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 5006U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16463077485583119324U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 7340U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2876782050665869121U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8383837717361569465U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 1865U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3529607472855930041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8850940802020173766U;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7469160295100147267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16973986572163482061U;
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12371372942863279718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12098525148034303633U;
            aOrbiterC = RotL64((aOrbiterC * 11234127652230231751U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5138683482859889480U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3339283916456813609U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3675U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10975353228235695455U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 40U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((RotL64(aCross, 52U) + RotL64(aOrbiterI, 12U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[((aIndex + 5707U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 14U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC + ((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 1965U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10728U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 14280U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15605U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 10747U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 22U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 52U)) + 17264605017518259932U;
            aOrbiterG = (aWandererG + RotL64(aCross, 21U)) + 15209184354580778643U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 39U)) + 3299527965014731384U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 3U)) + 16293096431816127821U;
            aOrbiterE = (aWandererE + RotL64(aCross, 47U)) + 11031983436878828337U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 9188018632448236358U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 13420816400363406556U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 6936U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 6U)) + RotL64(aCarry, 57U)) + 2485063384097917101U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 27U)) + 3089135816938128264U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 5581U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 41U)) + 10730544971770435788U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 23U)) + 10431767565618874806U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14883796491656899074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13322163435314643713U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7206U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4950101626975919939U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2596253994220103666U;
            aOrbiterE = RotL64((aOrbiterE * 7181706961838582889U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17961706029559914243U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5323U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10321902557977495175U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4788U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18146616411403012772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8414050129421955787U;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11739172334166341121U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7936637782633487291U;
            aOrbiterH = RotL64((aOrbiterH * 14940929920543800413U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3160044627483874242U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16816384076887379704U;
            aOrbiterI = RotL64((aOrbiterI * 5052772186568301951U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8101560104988710226U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 839U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8851416379738817624U;
            aOrbiterC = RotL64((aOrbiterC * 16767420038937389027U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9941784290055185679U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14495651885701938495U;
            aOrbiterK = RotL64((aOrbiterK * 1540692851998143607U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10599676325220702167U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16092000942942971187U;
            aOrbiterB = RotL64((aOrbiterB * 2457268192247656817U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16168470945107928109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17264605017518259932U;
            aOrbiterJ = RotL64((aOrbiterJ * 15038386057529909273U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 20U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 44U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 4375U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 612U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 12U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18811U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24562U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23815U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 22613U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 44U)) + RotL64(aCarry, 23U)) + 5697928251815176134U;
            aOrbiterI = (aWandererK + RotL64(aCross, 47U)) + 337587740689259575U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 19U)) + 4927686903263973950U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 37U)) + 3742409032569801033U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 60U)) + 1608092659172197650U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 15848744267145717509U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 6964U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 23U)) + 15300174177963339253U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7543U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 14162868453323648628U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 39U)) + 12020167069983729869U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 53U)) + 16259538291658723956U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 8516686212464112245U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3722184575520553132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1093356813820599238U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 521U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15167726103772238440U;
            aOrbiterI = RotL64((aOrbiterI * 5719466863561311069U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15170797965325981472U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 3985U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17826286701992981628U;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14710892030473425181U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 397194787697553904U;
            aOrbiterJ = RotL64((aOrbiterJ * 14368930300818752833U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1273724124862533034U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13018397560392545616U;
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9638716186445643730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7255587739807843785U;
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9272350563697399628U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1040729335295009339U;
            aOrbiterB = RotL64((aOrbiterB * 17825687660830291443U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12128124729613601747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2285238815562202219U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6127U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15398840993074390573U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6339113298619163493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5911895708485037040U;
            aOrbiterE = RotL64((aOrbiterE * 3271006139923200439U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7601399508218901328U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7801U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5697928251815176134U;
            aOrbiterK = RotL64((aOrbiterK * 8184257916861355735U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 6U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[((aIndex + 7468U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + ((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 54U) + aOrbiterA) + RotL64(aOrbiterD, 40U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 2421U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28104U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32204U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27589U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27510U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 51U)) + 11274974230580265396U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 16658438747342741547U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 27U)) + 16612986966106053844U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5783U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + 9329502236843231290U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 5395U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 14088261356708344656U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 13692608802007789581U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 37U)) + 6824473946645682398U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 2072915876348570040U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 35U)) + 7420507753044460759U;
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 4677557318688502593U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 20U)) + 15081678577055628459U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7026792817486507482U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14871665922943969918U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 5172U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6807734532159292872U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17882797335141303280U;
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9233542707022629190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10878718669747466677U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8066049063548639241U;
            aOrbiterC = RotL64((aOrbiterC * 3031382633089381605U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 861295180226875235U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 37U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9134969787937288583U;
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6726642007159809594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13541412083111962884U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8617442758729315637U;
            aOrbiterK = RotL64((aOrbiterK * 15471862889276160953U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16884403561131293362U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 1415U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9490680911678221233U;
            aOrbiterE = RotL64((aOrbiterE * 15988763830018001033U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10486145044311386738U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10200001044821063684U;
            aOrbiterA = RotL64((aOrbiterA * 16149790736141571017U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6997073594007878034U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 1212U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13585783612009989767U;
            aOrbiterF = RotL64((aOrbiterF * 11425303157774550449U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3847846040256340653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11274974230580265396U;
            aOrbiterB = RotL64((aOrbiterB * 13970270689108369205U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterE, 56U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 5807U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + aPhaseCWandererUpdateSaltC[((aIndex + 7747U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 10U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3658U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 2115U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4678U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 4779U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 53U)) + 3339283916456813609U;
            aOrbiterD = (aWandererB + RotL64(aCross, 60U)) + 11339086426180649584U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 16819191669329316585U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 8361916937762630725U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 1065U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 18031328374429899857U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 11U)) + 18261756894092897276U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 47U)) + 4250319792907645666U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 43U)) + 1492411503643460886U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 26U)) + 17369549067879344180U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 238U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7301713524358676722U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2985193736033012535U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 1350U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18205555540941493267U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9209505304067579944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8811497120829041188U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14707301680850257294U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5869U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11383709499376464085U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10080595991787801029U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6822892187784299166U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4347U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1981637172055758689U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6213U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8383837717361569465U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2788511294985017326U;
            aOrbiterD = RotL64((aOrbiterD * 2809163242875130677U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3529607472855930041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8850940802020173766U;
            aOrbiterG = RotL64((aOrbiterG * 7821450253655655943U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 46U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterD, 18U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[((aIndex + 1719U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 22U)) + aPhaseDWandererUpdateSaltB[((aIndex + 5489U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12574U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 9111U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8619U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 13844U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 18U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 17264605017518259932U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 41U)) + 15209184354580778643U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 4093U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 23U)) + 3299527965014731384U) + aPhaseDOrbiterAssignSaltC[((aIndex + 4539U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 16293096431816127821U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 11031983436878828337U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 9188018632448236358U;
            aOrbiterB = (aWandererC + RotL64(aCross, 57U)) + 13420816400363406556U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 4U)) + 2485063384097917101U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 29U)) + 3089135816938128264U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10730544971770435788U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 2069U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10431767565618874806U;
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14883796491656899074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13322163435314643713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterB = RotL64((aOrbiterB * 12337846092069506365U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4950101626975919939U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2596253994220103666U;
            aOrbiterJ = RotL64((aOrbiterJ * 7181706961838582889U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17961706029559914243U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 4467U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18146616411403012772U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8414050129421955787U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 601U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11739172334166341121U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 6508U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7936637782633487291U;
            aOrbiterI = RotL64((aOrbiterI * 14940929920543800413U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3160044627483874242U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16816384076887379704U;
            aOrbiterD = RotL64((aOrbiterD * 5052772186568301951U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8101560104988710226U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8851416379738817624U;
            aOrbiterC = RotL64((aOrbiterC * 16767420038937389027U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 22U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterB, 57U));
            aWandererH = aWandererH + ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aPhaseDWandererUpdateSaltD[((aIndex + 1990U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 54U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 7320U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22351U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 16528U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17438U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23707U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 11U)) + 11274974230580265396U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 16658438747342741547U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 20U)) + RotL64(aCarry, 37U)) + 16612986966106053844U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 29U)) + 9329502236843231290U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 47U)) + 14088261356708344656U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 37U)) + 13692608802007789581U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7759U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 6824473946645682398U) + aPhaseDOrbiterAssignSaltB[((aIndex + 945U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 6U)) + RotL64(aCarry, 47U)) + 2072915876348570040U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 53U)) + 7420507753044460759U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4677557318688502593U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5995U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7026792817486507482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4662U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9233542707022629190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1205501586581350876U;
            aOrbiterI = RotL64((aOrbiterI * 2596053290311090589U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10878718669747466677U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8066049063548639241U;
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 861295180226875235U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 2612U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9134969787937288583U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 1036U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6726642007159809594U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8061661744643240470U;
            aOrbiterA = RotL64((aOrbiterA * 6703498926835391813U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13541412083111962884U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8617442758729315637U;
            aOrbiterC = RotL64((aOrbiterC * 15471862889276160953U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16884403561131293362U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9490680911678221233U;
            aOrbiterD = RotL64((aOrbiterD * 15988763830018001033U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 44U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[((aIndex + 2743U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 28U) + aOrbiterC) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 42U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 307U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26764U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26558U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32190U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27612U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aScatter, 58U)) + 10336802574069791273U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 169025388197058936U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 6541354188379168846U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + 16223920526599306104U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6067U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 12U)) + 12756613707692514808U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 5082475548176484035U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 35U)) + 4907435526952698526U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 14236627073831834337U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 7854U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 3U)) + 11502511046130497584U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3679044835550219497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11254838916686736746U;
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4628253464169957835U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17664454668473204465U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3247U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3798386391743884889U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4647U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9816600392407327227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16781971616348376878U;
            aOrbiterI = RotL64((aOrbiterI * 12503867584828289879U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4807797577690520554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7909676419643119585U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16179914439220412472U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 2107U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3968867762761955845U;
            aOrbiterC = RotL64((aOrbiterC * 7473632378251893139U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7474832923901283742U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4736994731050735779U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3013U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9839654409121414047U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 54U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 8070U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterI, 30U));
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 2520U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
}

void TwistExpander_Holy_060::TwistBlock(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3459U)) & S_BLOCK1], 19U) ^ RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 1807U)) & (S_KEY_A - 1)], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 160U)) & (S_KEY_B - 1)], 29U) ^ RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 6990U)) & (S_KEY_A - 1)], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 54U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 3339283916456813609U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3701U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 53U)) + 11339086426180649584U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 16819191669329316585U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8361916937762630725U) + aPhaseAOrbiterAssignSaltD[((aIndex + 6247U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 14U)) + 18031328374429899857U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18261756894092897276U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4250319792907645666U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7053489184750217963U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1492411503643460886U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17369549067879344180U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7735U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2947354306696216579U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7301713524358676722U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 3580U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14086975808140927408U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10390516547834639800U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4643U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18205555540941493267U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 56U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 747U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5469U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15828U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8459U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 9537U)) & (S_KEY_A - 1)], 47U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 14297U)) & (S_KEY_B - 1)], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 5U)) + 17264605017518259932U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3413U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 15209184354580778643U;
            aOrbiterA = (aWandererD + RotL64(aCross, 23U)) + 3299527965014731384U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 16293096431816127821U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3943U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 11031983436878828337U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9188018632448236358U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5092U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13420816400363406556U;
            aOrbiterA = RotL64((aOrbiterA * 10958221259662190519U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2485063384097917101U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3089135816938128264U;
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10730544971770435788U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10431767565618874806U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 1001U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14883796491656899074U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5928U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13465877783538483706U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 2307U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13322163435314643713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 2246U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltC[((aIndex + 5756U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20865U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18372U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 17673U)) & (S_KEY_A - 1)], 26U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 18641U)) & (S_KEY_B - 1)], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 53U)) + 10336802574069791273U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 27U)) + 169025388197058936U) + aPhaseAOrbiterAssignSaltE[((aIndex + 6581U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 6541354188379168846U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 16223920526599306104U) + aPhaseAOrbiterAssignSaltF[((aIndex + 1097U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 53U)) + 12756613707692514808U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5082475548176484035U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 6289U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4907435526952698526U;
            aOrbiterK = RotL64((aOrbiterK * 1379692095754989215U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14236627073831834337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11502511046130497584U;
            aOrbiterJ = RotL64((aOrbiterJ * 3460330807286625917U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3679044835550219497U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 1582U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11254838916686736746U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 4765U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10582608424233200966U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10449735026385340313U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7863U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4628253464169957835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5776U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 30U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 21U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[((aIndex + 7748U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31479U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 28987U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29197U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 30616U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 54U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 5697928251815176134U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + 337587740689259575U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3131U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 4927686903263973950U) + aPhaseAOrbiterAssignSaltD[((aIndex + 2745U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 51U)) + 3742409032569801033U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 47U)) + 1608092659172197650U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15848744267145717509U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3475U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15300174177963339253U;
            aOrbiterD = RotL64((aOrbiterD * 5771922862677667319U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14162868453323648628U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12020167069983729869U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4207U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2071080217680099017U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16259538291658723956U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 602U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8516686212464112245U;
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3722184575520553132U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5663609293306386784U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6603U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15265344442454471986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 22U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 4874U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5968U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2201U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4654U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5140U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 4270U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 13U)) + 3339283916456813609U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 52U)) + 11339086426180649584U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 16819191669329316585U) + aPhaseBOrbiterAssignSaltE[((aIndex + 2148U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 8361916937762630725U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 18031328374429899857U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 6767U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18261756894092897276U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6290U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4250319792907645666U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 1969U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7053489184750217963U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1492411503643460886U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 3527U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17369549067879344180U;
            aOrbiterB = RotL64((aOrbiterB * 2947354306696216579U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7301713524358676722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18205555540941493267U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 1411U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16967799565443938873U;
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 18U));
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + aPhaseBWandererUpdateSaltA[((aIndex + 40U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 3418U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15615U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 8471U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9587U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14949U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 10336802574069791273U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 169025388197058936U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 6541354188379168846U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 22U)) + 16223920526599306104U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 6179U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 43U)) + 12756613707692514808U) + aPhaseBOrbiterAssignSaltA[((aIndex + 51U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5082475548176484035U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3675U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4907435526952698526U;
            aOrbiterI = RotL64((aOrbiterI * 1379692095754989215U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14236627073831834337U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11502511046130497584U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 2038U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3679044835550219497U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3673U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10582608424233200966U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7849U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 6U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + aPhaseBWandererUpdateSaltC[((aIndex + 5045U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aPhaseBWandererUpdateSaltD[((aIndex + 5082U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19928U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 18960U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20451U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22617U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 20U)) + RotL64(aCarry, 51U)) + 11274974230580265396U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 16658438747342741547U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5771U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 16612986966106053844U) + aPhaseBOrbiterAssignSaltC[((aIndex + 2290U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 43U)) + 9329502236843231290U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 29U)) + 14088261356708344656U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13692608802007789581U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6824473946645682398U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5094U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13619437545775237601U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2072915876348570040U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 6999U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7420507753044460759U;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4677557318688502593U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3372U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7026792817486507482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14871665922943969918U;
            aOrbiterK = RotL64((aOrbiterK * 694073180313083145U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6807734532159292872U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3215U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 4U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 6217U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 34U)) + aPhaseBWandererUpdateSaltE[((aIndex + 5828U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27663U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 28183U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31819U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 31787U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 12775735908960052604U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 1941U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 11791373812080296887U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 5537362877706057303U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 39U)) + 2023912048504189380U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 56U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltE[((aIndex + 6666U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 558908629933941224U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1479633119685446888U;
            aOrbiterE = RotL64((aOrbiterE * 4447153373540811385U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15460320397843364063U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 1579U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10059749397555469054U;
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9987633811929693924U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3717U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10087337844580228269U;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4446204415503364254U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15106063243302192717U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3982U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9430197906134676162U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1226048679997253363U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4936U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[((aIndex + 7343U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 1874U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 24U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4872U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 1112U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2399U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 1590U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 43U)) + 11274974230580265396U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 16658438747342741547U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 21U)) + 16612986966106053844U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 9329502236843231290U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 14088261356708344656U) + aPhaseCOrbiterAssignSaltA[((aIndex + 3225U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 13692608802007789581U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 398U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 13U)) + 6824473946645682398U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2072915876348570040U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7420507753044460759U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5655U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4677557318688502593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15081678577055628459U;
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7026792817486507482U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14871665922943969918U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 2390U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 694073180313083145U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6807734532159292872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9233542707022629190U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5373U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1205501586581350876U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4101U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10878718669747466677U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8066049063548639241U;
            aOrbiterD = RotL64((aOrbiterD * 3031382633089381605U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aPhaseCWandererUpdateSaltF[((aIndex + 7853U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 38U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 12U)) + aOrbiterD) + aPhaseCWandererUpdateSaltC[((aIndex + 6924U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9986U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((aIndex + 11991U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10007U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9604U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 35U)) + 12775735908960052604U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 11791373812080296887U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 23U)) + 5537362877706057303U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 2023912048504189380U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 13U)) + 17668828109963766893U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 1001U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 558908629933941224U) + aPhaseCOrbiterAssignSaltE[((aIndex + 7185U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 1479633119685446888U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15460320397843364063U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 2989U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10059749397555469054U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4818U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9987633811929693924U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5851U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4446204415503364254U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9430197906134676162U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3752U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10611580584157624739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3137391249289641509U;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9327201928815412810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7890659377013147073U;
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10675114832750356941U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8804440385852327267U;
            aOrbiterJ = RotL64((aOrbiterJ * 8520671775587260601U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aPhaseCWandererUpdateSaltE[((aIndex + 6342U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aPhaseCWandererUpdateSaltD[((aIndex + 1359U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterE, 12U));
            aWandererA = aWandererA + (((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16559U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 23667U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18819U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19817U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 17264605017518259932U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 41U)) + 15209184354580778643U;
            aOrbiterC = (aWandererC + RotL64(aCross, 3U)) + 3299527965014731384U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 16293096431816127821U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 50U)) + RotL64(aCarry, 3U)) + 11031983436878828337U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 2979U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 9188018632448236358U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 13U)) + 13420816400363406556U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 4977U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2485063384097917101U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3089135816938128264U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 1358U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8813152992957361153U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10730544971770435788U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 829U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10431767565618874806U;
            aOrbiterA = RotL64((aOrbiterA * 4723078464590561545U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14883796491656899074U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13465877783538483706U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 4423U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13322163435314643713U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 268U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4950101626975919939U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18146616411403012772U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8414050129421955787U;
            aOrbiterB = RotL64((aOrbiterB * 14879448948196182863U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 50U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterJ, 20U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 4232U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 6820U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25036U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 32449U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32274U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31957U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 28U)) + RotL64(aCarry, 5U)) + 3339283916456813609U;
            aOrbiterI = (aWandererG + RotL64(aCross, 3U)) + 11339086426180649584U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 16819191669329316585U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 4601U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 8361916937762630725U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 57U)) + 18031328374429899857U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 11U)) + 18261756894092897276U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 2001U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 35U)) + 4250319792907645666U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1492411503643460886U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17369549067879344180U;
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7301713524358676722U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5394U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2985193736033012535U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5852U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14086975808140927408U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18205555540941493267U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3883U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16967799565443938873U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7525U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9209505304067579944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8811497120829041188U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14707301680850257294U;
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10080595991787801029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6822892187784299166U;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 14U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + aPhaseCWandererUpdateSaltC[((aIndex + 6799U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4086U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3932U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 165U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6084U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 6358U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 47U)) + 10336802574069791273U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 56U)) + 169025388197058936U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5028U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 4492U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 16223920526599306104U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 41U)) + 12756613707692514808U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 5082475548176484035U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 5U)) + 4907435526952698526U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14236627073831834337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11502511046130497584U;
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3679044835550219497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11254838916686736746U;
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10582608424233200966U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 1693U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10449735026385340313U;
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4628253464169957835U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 1450U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterF = RotL64((aOrbiterF * 4234720298731378527U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3798386391743884889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9816600392407327227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16781971616348376878U;
            aOrbiterI = RotL64((aOrbiterI * 12503867584828289879U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4807797577690520554U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 1176U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2492057261148595922U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5326U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7309U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 60U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 2649U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 50U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8759U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12140U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14245U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16267U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 53U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 337587740689259575U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 4927686903263973950U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 35U)) + 3742409032569801033U) + aPhaseBOrbiterAssignSaltE[((aIndex + 2767U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 60U)) + 1608092659172197650U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 15848744267145717509U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 29U)) + 15300174177963339253U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6699U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14162868453323648628U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12020167069983729869U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7145U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2071080217680099017U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16259538291658723956U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8516686212464112245U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6874U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3722184575520553132U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 369U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15265344442454471986U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1093356813820599238U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5942U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15170797965325981472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterE = RotL64((aOrbiterE * 11186808881726573677U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14710892030473425181U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 397194787697553904U;
            aOrbiterK = RotL64((aOrbiterK * 14368930300818752833U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 34U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + aPhaseBWandererUpdateSaltC[((aIndex + 6523U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 5098U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16934U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 24480U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18361U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17506U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 13U)) + 3339283916456813609U) + aPhaseBOrbiterAssignSaltB[((aIndex + 1231U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 35U)) + 11339086426180649584U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 16819191669329316585U;
            aOrbiterH = (aWandererG + RotL64(aCross, 43U)) + 8361916937762630725U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 41U)) + 18031328374429899857U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 18261756894092897276U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 3963U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 4250319792907645666U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1492411503643460886U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17369549067879344180U;
            aOrbiterC = RotL64((aOrbiterC * 2947354306696216579U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7301713524358676722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14086975808140927408U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6040U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18205555540941493267U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16967799565443938873U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6220U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3009081009044782443U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9209505304067579944U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3366U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterI = RotL64((aOrbiterI * 3441982898533162599U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8811497120829041188U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14707301680850257294U;
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10080595991787801029U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 71U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6822892187784299166U;
            aOrbiterK = RotL64((aOrbiterK * 7417016898027778287U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseBWandererUpdateSaltA[((aIndex + 5594U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 58U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3292U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25275U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32729U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26288U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25075U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 12775735908960052604U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 20U)) + 11791373812080296887U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 5U)) + 5537362877706057303U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 6897U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 13U)) + 2023912048504189380U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 17668828109963766893U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 57U)) + 558908629933941224U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 1479633119685446888U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 4636U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15460320397843364063U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6573U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8671817118586065469U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9987633811929693924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10087337844580228269U;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4446204415503364254U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15106063243302192717U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5290U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9430197906134676162U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1226048679997253363U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5900U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10611580584157624739U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9327201928815412810U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3317U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7890659377013147073U;
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10675114832750356941U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterJ = RotL64((aOrbiterJ * 8520671775587260601U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 44U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererK = aWandererK + ((((RotL64(aCross, 38U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 4297U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 34U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aPhaseBWandererUpdateSaltE[((aIndex + 5021U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Holy_060::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererH = 0; std::uint64_t aWandererJ = 0;
    std::uint64_t aWandererK = 0;

    // [grow key a]
    // GTwistRunGrowKeyA grow_key_a_expand_a (start)
    {
        // grow_key_a_expand_a loop 1
        // read from: aWorkLaneA, aWorkLaneC, aWorkLaneB, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[aIndex], 21U) ^ RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 30U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[S_BLOCK1 - aIndex], 39U) ^ RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 37U)) + 10336802574069791273U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 169025388197058936U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4938U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 52U)) + 6541354188379168846U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 16223920526599306104U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 12756613707692514808U) + aPhaseDOrbiterAssignSaltE[((aIndex + 2716U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5715U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4907435526952698526U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3268U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1379692095754989215U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14236627073831834337U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11502511046130497584U;
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3679044835550219497U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterE = RotL64((aOrbiterE * 8631695922983532915U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10582608424233200966U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10449735026385340313U;
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4628253464169957835U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4178U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17664454668473204465U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 621U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltF[((aIndex + 1413U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 14U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 465U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
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
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>((S_BLOCK >> 1)); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[aIndex], 27U) ^ RotL64(aWorkLaneC[S_BLOCK1 - aIndex], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[S_BLOCK1 - aIndex], 35U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 58U)) + 11274974230580265396U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 35U)) + 16658438747342741547U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4291U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 16612986966106053844U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 9329502236843231290U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 14088261356708344656U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 106U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13692608802007789581U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4015U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6824473946645682398U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 2797U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13619437545775237601U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2072915876348570040U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 398U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7420507753044460759U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5766U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13239288539564571257U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4677557318688502593U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15081678577055628459U;
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7026792817486507482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6807734532159292872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3817U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 52U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 1879U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 4U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[aIndex], 37U) ^ RotL64(aExpandLaneA[aIndex], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 19U) ^ RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 23U)) + 12775735908960052604U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + 11791373812080296887U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7931U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 42U)) + RotL64(aCarry, 5U)) + 5537362877706057303U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 2023912048504189380U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 17668828109963766893U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 6424U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 558908629933941224U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1479633119685446888U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 244U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4447153373540811385U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15460320397843364063U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10059749397555469054U;
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9987633811929693924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10087337844580228269U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 2109U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4446204415503364254U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3942U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9430197906134676162U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3719U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[((aIndex + 6787U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 12U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6321U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 56U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aKeyRowWriteA[(aIndex) & W_KEY_A1] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyA twist_key_box_loop_a (end)
}

void TwistExpander_Holy_060::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0; std::uint64_t aCross = 0;
    std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [grow key b]
    // GTwistRunGrowKeyB grow_key_b_expand_a (start)
    {
        // grow_key_b_expand_a loop 1
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = static_cast<std::size_t>((S_BLOCK >> 1)); aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[aIndex], 41U) ^ RotL64(aWorkLaneB[S_BLOCK1 - aIndex], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[S_BLOCK1 - aIndex], 44U) ^ RotL64(aWorkLaneD[aIndex], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 54U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 11274974230580265396U) + aPhaseDOrbiterAssignSaltF[((aIndex + 1000U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 16658438747342741547U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 16612986966106053844U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 46U)) + 9329502236843231290U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 13U)) + 14088261356708344656U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4379U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13692608802007789581U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 2870U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6824473946645682398U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 2635U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13619437545775237601U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2072915876348570040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7420507753044460759U;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4677557318688502593U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15081678577055628459U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6384U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7026792817486507482U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4909U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14871665922943969918U;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6807734532159292872U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterA = RotL64((aOrbiterA * 15439872930381050291U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 4367U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5636U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 56U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[aIndex], 56U) ^ RotL64(aWorkLaneD[S_BLOCK1 - aIndex], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 26U) ^ RotL64(aWorkLaneC[aIndex], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 19U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 10336802574069791273U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 2215U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 169025388197058936U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 3U)) + 6541354188379168846U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 16223920526599306104U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + 12756613707692514808U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 1321U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 2428U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4907435526952698526U;
            aOrbiterB = RotL64((aOrbiterB * 1379692095754989215U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14236627073831834337U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 424U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11502511046130497584U;
            aOrbiterK = RotL64((aOrbiterK * 3460330807286625917U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3679044835550219497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10582608424233200966U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3971U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10449735026385340313U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3182U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4628253464169957835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltB[((aIndex + 237U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterK, 38U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[((aIndex + 6060U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[aIndex], 5U) ^ RotL64(aExpandLaneB[aIndex], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[S_BLOCK1 - aIndex], 51U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 5697928251815176134U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5463U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 337587740689259575U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 1707U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 4927686903263973950U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 19U)) + 3742409032569801033U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 11U)) + 1608092659172197650U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15848744267145717509U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15300174177963339253U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 645U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5771922862677667319U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14162868453323648628U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 2234U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12020167069983729869U;
            aOrbiterH = RotL64((aOrbiterH * 2071080217680099017U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16259538291658723956U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8516686212464112245U;
            aOrbiterK = RotL64((aOrbiterK * 4731296903548893627U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3722184575520553132U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3124U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5663609293306386784U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 266U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7832U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 6243U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 4U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aKeyRowWriteB[(aIndex) & (W_KEY_B - 1)] ^= aIngress;
        }
    }
    // GTwistRunGrowKeyB twist_key_box_loop_b (end)
}

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseASalts = {
    {
        {
            0xFF2CD3940C6D64E0ULL, 0x9D7B68C85F626C37ULL, 0x6C2526F2FC85A00DULL, 0xD25F8B1A0466AC3DULL, 
            0x710CB91625E3D3DAULL, 0xA01650B206D4C9E3ULL, 0xCB333A4506BB39C9ULL, 0x0D1E05B0ED1CC35EULL, 
            0xFD99798E104644E7ULL, 0x495E2C319E8FBABEULL, 0xB982249A417C9495ULL, 0x21A40F7BD7F33D0FULL, 
            0xE2F291AF85CEDD98ULL, 0x06FDB29B77C05485ULL, 0xB3C472FFED7C9A8EULL, 0xA44DCA6A4A661FBDULL, 
            0x1CB3ECDBFCB16978ULL, 0xDE8D0678568EC0E0ULL, 0x98DF4A043AA07E7AULL, 0x1087252053B17280ULL, 
            0x896F8713B9ACA591ULL, 0x9E29E2FBDD7474FAULL, 0x8051DECBAF38F36DULL, 0xD670A6946CE4FCABULL, 
            0xC0C925D7050D4E45ULL, 0x64E6770F81FFACA2ULL, 0x49C21E8425F3C7C6ULL, 0x81438AE376F19A6CULL, 
            0x3F2F2C3FCB3D84DBULL, 0x21DBD1114FF34ECEULL, 0xE3C9CF2F6D9600C2ULL, 0x42CC1D939DB3E9D0ULL
        },
        {
            0x49CD53623BF54D13ULL, 0x99A48A41CA813812ULL, 0x6E30D9378D35EB75ULL, 0x63784CB9C51FED49ULL, 
            0x8FF7F941A774D2F3ULL, 0x697D056BA4D01DA2ULL, 0x82EAF8DB56607DB5ULL, 0x57D9F98FDDAA4FCFULL, 
            0x0FA5E1C79D0BC19CULL, 0x4AA7BF2C7131F629ULL, 0x4210A3CA07D22237ULL, 0xDD2D007145485BE1ULL, 
            0x8FB3DE76A99352A5ULL, 0x41AD8CAD0A15DB49ULL, 0x20A159C597B412A5ULL, 0xDDE64922E91E0A74ULL, 
            0x79CB9F66682D133CULL, 0x667B3A47259251B1ULL, 0x12859AE2ACA3E36EULL, 0x71CDE3BAC78FACF4ULL, 
            0xC2FB2FA660163D62ULL, 0x9DD7621F72203A1EULL, 0x4886355EBB6772BCULL, 0x51F3D6AC32931A5EULL, 
            0x59D684F7C3DAE39DULL, 0xC0FDC78DC2B18FC4ULL, 0xDA0FEE31A84487B2ULL, 0x3686B7F60C511F87ULL, 
            0x517B5896F796EF5DULL, 0x6B251693C131ECFFULL, 0x7E0704BA617EC3A7ULL, 0xEB2D6A274FA883A3ULL
        },
        {
            0xC165A9AFA14A5D86ULL, 0x946B8964328C7C87ULL, 0xF84D488A2ABB702FULL, 0xF7EE53A8C8A7149AULL, 
            0x15D112E21BC46610ULL, 0x53BF87C12360323EULL, 0xD6A0E5EA5A3DECFAULL, 0x85C4417CFF6E6BA2ULL, 
            0x05664399B35F4F6FULL, 0x100A43FEDF031B65ULL, 0xD3E2556CFCE6126BULL, 0x4BD249BE0260B188ULL, 
            0xC28FE1E606F256A3ULL, 0xF9A65AD74C0C6DD4ULL, 0x1316DF04A6970864ULL, 0xA577DA55308C3208ULL, 
            0x29526BBA70AB92A2ULL, 0x88E6EB083F47BD65ULL, 0x75B4C74089A52D38ULL, 0x36666B51B8BF1EA2ULL, 
            0x8A83BB932B92DA15ULL, 0x4C0A2768AFAC7E63ULL, 0x8CFA3FAF7F0E3792ULL, 0xDE054B871D10E177ULL, 
            0xA1F404117A854F23ULL, 0x3DEC9FF486CFD61DULL, 0x04388151F71607C1ULL, 0xFF4DFA19891C7C5CULL, 
            0xA735B362512706DBULL, 0xE2C786657836F9F9ULL, 0x35406BDBA16F1065ULL, 0x9473A3AE2ACF649EULL
        },
        {
            0x180629393EBCEE80ULL, 0x38924E9194A78556ULL, 0xC6E2B46FEA35E5B5ULL, 0xE04D12FE9B32D4F3ULL, 
            0xCA76AF2D064102CAULL, 0x7F31B3D11D34DCDEULL, 0xA70223A4DC41974CULL, 0xA3CD0FC326B646A6ULL, 
            0x3B16CE51AAB1C74FULL, 0x00D9AB4AF606EF1AULL, 0x9D3922AB34EF79D9ULL, 0xEA44739B5500AC9DULL, 
            0x908DCD9445872756ULL, 0x835D5E0E9E882435ULL, 0x159F98778EC28542ULL, 0x0C0A1AA1E3CC7EE1ULL, 
            0x969A91151630BFE3ULL, 0x9858A92565F71EDEULL, 0xB78784ECA2E88537ULL, 0xA1B29A9C175A4CB4ULL, 
            0xCE37B284184CC90AULL, 0x7C3E633F0EAF2D0DULL, 0xD3868D676C0761B8ULL, 0xCB05F55BCA622C97ULL, 
            0xDEFB26D5B83B4374ULL, 0xFEA31168584B46BDULL, 0x111FFBEBEA8AA910ULL, 0x69257504F5D9C226ULL, 
            0x6C71A69DF294425DULL, 0xEDEA6DD130F5EFC8ULL, 0x8AF2F6DCFBE6BD78ULL, 0xDA6D4C085C170573ULL
        },
        {
            0x29D4B5C4911FC2B1ULL, 0x98F7A14D931789A8ULL, 0x7A892A6AAB5864BBULL, 0x34C7D0F368F2C1EAULL, 
            0xE3B568A5731E90E6ULL, 0x43453204B16FDBEEULL, 0xB874B45D46184B3BULL, 0x914179C693E71ED4ULL, 
            0xCB192ADB509081FEULL, 0x397E4007820A57AFULL, 0x2B7BAAAD38B5C623ULL, 0xB22979D36369E19DULL, 
            0x39615E4983D131C4ULL, 0x07D58A38FCED5AADULL, 0x093495E9B9349B80ULL, 0x27D9234871DEACB4ULL, 
            0xA394055333041271ULL, 0x0E246BD99E5EC789ULL, 0x29554C1F97E87F09ULL, 0x3E02A84AD609C050ULL, 
            0x5EC83D0C95AC4C37ULL, 0xBCAD62FEBA9308EEULL, 0xF874E0A9737C7192ULL, 0x259E03A2180FA8CDULL, 
            0x21D4A0AAC417CCFCULL, 0x4E15B2E34F068421ULL, 0xF3D4140446517174ULL, 0x94786347440C948BULL, 
            0x3FD6F22B4555A181ULL, 0x48F0B353131EF190ULL, 0x11E9EF53EBFAEB5BULL, 0x366DE19AA55094B7ULL
        },
        {
            0xA83435D70E54300DULL, 0xC4A8C5959EED154FULL, 0x83BB45E52C14CD56ULL, 0x1F929A53ADBD5997ULL, 
            0x923398176B33D0BCULL, 0xBCDD656B385FF2A4ULL, 0x074C64A52E6A1B5CULL, 0x8E7FC7770CE94B9CULL, 
            0x1AE0960AE7A93DFFULL, 0x61D7DC8CE582A74FULL, 0x2743CEAA13BDE66DULL, 0x35C294546579496BULL, 
            0x0FE54FCE99DEAF30ULL, 0x7D693D5864E04C72ULL, 0x7FF4353A07724F75ULL, 0x7EC6C6C564268CB0ULL, 
            0x6FF9B1A1AD40E1F2ULL, 0x224FB0A2944F4A08ULL, 0xB88A6B58C6FBD004ULL, 0x08D6C63086024C7FULL, 
            0xB38F136724557F6BULL, 0xA31701411DCFE579ULL, 0xDFC1153751F61702ULL, 0xE2C0F98A5410A08BULL, 
            0xE587F6D2A46C9443ULL, 0x53FC7C95F53BF592ULL, 0x684BE66E7090E2BAULL, 0x710C85110115886BULL, 
            0x677C8977D8D4F303ULL, 0x21BED6E0B6BD3B59ULL, 0xA9DA95547971F120ULL, 0xD779B6075A519D15ULL
        }
    },
    {
        {
            0x012DD7585D7EE04EULL, 0xB3706A7FCCDB4617ULL, 0xE6C49AAB355E447BULL, 0xE71EF7E0F8600ED4ULL, 
            0xC0EAD0C97C519276ULL, 0x65D5A9C0BCAE1310ULL, 0x565F4CD118D30D41ULL, 0x058A370105F6971AULL, 
            0xF0E8C16A77FC77F8ULL, 0x3F7A4E40A306648BULL, 0xA797E7581EDA7BEFULL, 0x4ED406E0222617CEULL, 
            0xE838FF1F7F3CE0D0ULL, 0x401BA570F26A42BAULL, 0x3DF92A7FA57CEE1CULL, 0x7FBE96A159492F5EULL, 
            0x4ECAFE8A30707F1CULL, 0x5B3BF2EE4F0CA0B6ULL, 0x840C71BD6FD84F15ULL, 0x8A1A7DAB9C096980ULL, 
            0xB9FE29BE397BD36EULL, 0x4B7F72E15FDB6ADBULL, 0xC0B235883B4D0A2EULL, 0x4302BE5435E168DFULL, 
            0x5E014F78CD522C6AULL, 0x4FBE87E2559AC28AULL, 0x469F3ABE2F66BEC2ULL, 0x99AC2DC528E7C800ULL, 
            0x24406EEDB39A1AEBULL, 0x57E9D9C0AD3590F0ULL, 0xB5376A55CCCD0576ULL, 0x879C19E0D7EAC5B9ULL
        },
        {
            0x063BE68AA801D7F6ULL, 0xCD29D9E2AFB9CE38ULL, 0x2FF9DB442150BDBDULL, 0x3174936A3365E963ULL, 
            0x29564FFC82E0853AULL, 0xF2F6800F9B8BF751ULL, 0x65C1E274CFB844F6ULL, 0x9154F475E084CC4DULL, 
            0xAA1B090F55F4FB23ULL, 0x393F7ECD4651CCBDULL, 0x2311872CC9D8F548ULL, 0x9A2B30BFAD8BA5FBULL, 
            0x3D9C09103BF45856ULL, 0x934F98C6582ADEC1ULL, 0x7FF42B49C78562BEULL, 0x80474E483D1FBD37ULL, 
            0xD585CA9B0E21525FULL, 0x06A0631E37B9F420ULL, 0x8D7618D312875DD1ULL, 0xAB1453FF70AA4D84ULL, 
            0x6B9A1E9407C86998ULL, 0x106EC675D440CC9BULL, 0xE8CCFCD02CEE035AULL, 0xE87BEF83E36991BCULL, 
            0x881F08C43172A018ULL, 0x362C42490119E311ULL, 0x47836CECC78A0B8BULL, 0xB91C864B8F67316CULL, 
            0xE7A975018482A35AULL, 0xC5283F765BAB3953ULL, 0x5F50DC36762C76B3ULL, 0x023CD0586C2DC801ULL
        },
        {
            0x2FEE804D96B3674DULL, 0x771E28910C3E510AULL, 0x2C45B7CDB732AFF2ULL, 0xEC179414464C9D4AULL, 
            0x80834A953BBC548CULL, 0x4DA7F895244A8983ULL, 0x72326A7C91E2E116ULL, 0xB560E29E13B687BEULL, 
            0xE2DACF8E56D6DDE2ULL, 0x7DC5BE683BF1F8B0ULL, 0xF8BC3206F3C864C2ULL, 0x202FF2FF49EC3FCCULL, 
            0xD39A6DB341FA381BULL, 0x3045282636DCB1BCULL, 0x36AB18A91E7C3127ULL, 0xB121231B08961E36ULL, 
            0xEDF9303550FA960FULL, 0xBD9F81A598B1775CULL, 0x3F28AF7F13C8CF63ULL, 0x0B267CC594082D9BULL, 
            0xF7E38DCA4443CE12ULL, 0x37F590B8B9301B58ULL, 0x672D91C43F7B8DD7ULL, 0xDAA814268C393DD7ULL, 
            0xB40306EF9B7F0A93ULL, 0x167F10D804ACD348ULL, 0xF8FC834759734B71ULL, 0x3C5CD097D7E04E29ULL, 
            0x8F851A77EA856C45ULL, 0x4CC6FC5F997A7612ULL, 0x943C2C13590B63F5ULL, 0x48921FFA003BE90BULL
        },
        {
            0x73F77CB8A8936AEEULL, 0x2C166C7BEB9B2FEDULL, 0x2C9E18551B094BDBULL, 0x6C9249AC2A869DE3ULL, 
            0x7B01DA1B51724E99ULL, 0x86B3568D7DCA6607ULL, 0xEDA9AE766C5BB638ULL, 0x805DEDB20FFEF99BULL, 
            0x820926A2342504D2ULL, 0x5AB9AAC65A3C2254ULL, 0xDFD4CEE5B4A29D97ULL, 0x7CD4C6B1B43BF79CULL, 
            0x419A34759A62E798ULL, 0x71C6EC97267B6C2EULL, 0x7C78375BBBCDD2C0ULL, 0x51E112E5D0D07AE7ULL, 
            0xDBBD399CC916B385ULL, 0x2E5962C5D29046F6ULL, 0x07C5E12081096D02ULL, 0xFDB1E0FFE7B2CA5CULL, 
            0x5D3FB5F374E31173ULL, 0x8158491ADE6FDFB5ULL, 0xF847465C90DD1A0DULL, 0x454D6C962DF21F1DULL, 
            0xEC89DF520DA185ADULL, 0xECB9FE4362F9BDD0ULL, 0x8A6422774548889EULL, 0x4DF26A27F3A52EB0ULL, 
            0x2076E6D4E3C980ECULL, 0x5F376C6055110592ULL, 0x2E607B64813F26FEULL, 0x5636FB723F04C04BULL
        },
        {
            0xC698CD4E89E7740CULL, 0xCDB20D218EA12207ULL, 0xACD4C18869D2C1D8ULL, 0x5E33CBAA82CFB54FULL, 
            0x6B0E56C1F2737988ULL, 0xE8D1E1D45F67BE9DULL, 0x443C601860DB8BB0ULL, 0x2E973ABE2E4F84ABULL, 
            0xD18D9D0AC6BB19E7ULL, 0x3F190F9E53A896ECULL, 0xB5433E0DF00FBD50ULL, 0xEECE50C635D92147ULL, 
            0x83D4354D254C9CF6ULL, 0xEB6486CCD8F3F8F0ULL, 0x242895EB1A8F48E0ULL, 0x15979F95E5BF6774ULL, 
            0x452D7309DD9FA567ULL, 0xB91E7D5C226AD395ULL, 0x36F90931E79DDE0BULL, 0x1B2D5FBDBAC1652EULL, 
            0xB1782FE01C7DCB7AULL, 0x6180ED548639B25EULL, 0xB99C58B4FD8D391DULL, 0x03E9F66069E83BC6ULL, 
            0x882AD969EE9DF68FULL, 0x4214F73E6119EDDBULL, 0xEE57C83D60EBA042ULL, 0xD2453D46467055D3ULL, 
            0x5B16F7C04D18F1AAULL, 0xF6EE055C3D14CD8CULL, 0x98A38A1A21D7E641ULL, 0xCB9025C2AEC084BFULL
        },
        {
            0x9CB47B7460DDF14AULL, 0x52F05B6F02AF3830ULL, 0xEA721A6FD4FE067DULL, 0xF77E4206B0F08745ULL, 
            0xA9BB3B6D7E1B6C26ULL, 0xA8C688DF83CDF225ULL, 0x5F2C601FAA32193EULL, 0xD45D9F341945A920ULL, 
            0xD0E480C9BD538910ULL, 0x84EFBB9DE5B5041FULL, 0xED22F39A2FD5FCACULL, 0x5479493C6BE9C6CFULL, 
            0x6E2CCC522406015EULL, 0xDB31681CF8CA23C0ULL, 0x261AA3BD1D4638B7ULL, 0x7852B0A931146E62ULL, 
            0xDE674A12338AFE69ULL, 0xD804B0C539329613ULL, 0x83182DB055774A8AULL, 0xD3F5308C7FB6887CULL, 
            0x1F8DA6553D639AB9ULL, 0x9BD92AB158F1E310ULL, 0x4A3CE0419AF7D894ULL, 0xEABB48C9B68A385CULL, 
            0xBAD5B4DD3A5E589FULL, 0xA810CEB930961F5DULL, 0x19B71CB822651385ULL, 0x029B8024E118735CULL, 
            0xC4D3E6DA48B5CB29ULL, 0xFE243F11DF3C1B8EULL, 0x2BD6243A647DC9A7ULL, 0x70F88E7284A5D3E0ULL
        }
    },
    {
        {
            0x86531B71C31A772DULL, 0x7F9DC7B1D004066BULL, 0x086BEFCA798D92E3ULL, 0xC599A1F41FCF66A1ULL, 
            0x25E83A6902FE2286ULL, 0xC0F0A30E47009D85ULL, 0x9179B9AC5B05B202ULL, 0x20CF43D6D8F39E2DULL, 
            0xEBD3F0099B95D66AULL, 0x1982269841AB9111ULL, 0xC1B0CD0906F7A1D4ULL, 0x185F651EB85861A3ULL, 
            0xEAAC68F3E70B590AULL, 0x3C64F5DB6D70C0C2ULL, 0x882525E89A973445ULL, 0xC31CBCC4274D9B72ULL, 
            0xBB2DB1E6C75F4143ULL, 0x85BBD0780F1B05F4ULL, 0x6D9D5CD5E486D7F7ULL, 0xC60F49AEA4F4CF8CULL, 
            0xCDA7F93B8C81AD07ULL, 0x82645F049E284276ULL, 0x1DC6192649649D03ULL, 0x7D766A607239D0AEULL, 
            0xF52863B3E3AD736DULL, 0x7E0CCAF94242AA39ULL, 0xA827DCEF2FA286B9ULL, 0x169958D483A6FAB4ULL, 
            0x4147C2D6A4F2F424ULL, 0xD806323948DD804BULL, 0x27C468659F3FC6ACULL, 0xF80A70D39D96DBC4ULL
        },
        {
            0xBCD0CEF50B9396A3ULL, 0x02D14F2FACE40743ULL, 0xC9EDD9F942666E51ULL, 0xC5AB4FF6867ECF02ULL, 
            0xA4FD0A41E6220220ULL, 0x1454218A87116374ULL, 0xAC243661BF93CD93ULL, 0x30205EF8500B488FULL, 
            0xA7C4226441C1833AULL, 0xEE0B5EAC45CB4DFDULL, 0x73373E6204E2DE52ULL, 0xB7A545965559C3FEULL, 
            0xCD2331612A17D35FULL, 0x5A3542C22BF085D9ULL, 0x5EE93E57647C7E7EULL, 0x927F2B49F22CAD13ULL, 
            0xBA989E1770DC03ADULL, 0x06452DA6C1D89C9DULL, 0x77BCD9E0081919ECULL, 0x7AE05F412B91B63FULL, 
            0x2B45B60CD8EF0F3BULL, 0x701CC6EB1FC22B62ULL, 0x7700309BFF300875ULL, 0xC79DE2CB690F33E6ULL, 
            0x06363D47CA6B7C6DULL, 0x764B103E7331B5D2ULL, 0x4BB80D54ED8BCFE5ULL, 0x230D188FD21C6B29ULL, 
            0x7A7BBA3089D70810ULL, 0xEEB7FC6134455415ULL, 0xE6FB55584CBCC1A3ULL, 0x8647FA556471DD07ULL
        },
        {
            0x864B1EC70C40C7C4ULL, 0x2A4D69C9CFA2CE34ULL, 0x778048ED2BF42C78ULL, 0x7C03D80004AC6C77ULL, 
            0x2B4DB8EDA7E87B34ULL, 0xA34362C1B8EF91F8ULL, 0x936FA91E62ECD2B0ULL, 0x00F0E691274CFF95ULL, 
            0xC1E288D4C263B870ULL, 0x7820F635EF521161ULL, 0xC0F5BA4C01912314ULL, 0xBBE27FF877A64897ULL, 
            0x04E579D5D0988065ULL, 0xE41AAC7F4818ABDFULL, 0x2802F8443935796CULL, 0x54BFD3AA19A74AF1ULL, 
            0x1A6F4DC34F222437ULL, 0x3D5956F176E1DFA2ULL, 0xE11FFB2208046DB4ULL, 0xC33DFA4036F8C64BULL, 
            0xB4CA9C6D4EDE4D90ULL, 0x59EE07E61488A936ULL, 0x187F4C1436857A99ULL, 0x66A42157DDBDEE51ULL, 
            0x733F7CFC9BE99B37ULL, 0x17A854EB24188023ULL, 0x5DBC67B75550A03BULL, 0x79CB5172BAF13DA7ULL, 
            0x71F12029727B1B49ULL, 0x31A55BF1C710FA88ULL, 0x061F29D448EB9AF2ULL, 0xD73FA74EF7EC0334ULL
        },
        {
            0xBF457FB1C57FE3E6ULL, 0x5AAD450BA446737AULL, 0x21E26A49540ED08CULL, 0x76877AA727EE009AULL, 
            0x797796579ACD31B6ULL, 0x99B2D24548BC2385ULL, 0xB29E56B596ADB136ULL, 0x2EDAE77F97D5CB00ULL, 
            0x6E1A05DB510426D5ULL, 0xDF027F008504E668ULL, 0x7E11FC571F97518AULL, 0x6B9C2E41C3A4FD36ULL, 
            0x86059518D7D798F3ULL, 0x283810F045963B2EULL, 0x7E8A055BACA518D5ULL, 0xE60E26ABA4AC80FCULL, 
            0xD19FB557BD3EF41CULL, 0xA2DA48326505D7C0ULL, 0x83B115B2B632D3BEULL, 0x945368C2D2627D9CULL, 
            0x778A6590E493B11AULL, 0x119CB70E32AD9A98ULL, 0x7D259F5F55B1899BULL, 0x41B23EB6FFDAE5AEULL, 
            0x532EC745863E66D4ULL, 0x390D0AFE6B1CA107ULL, 0xA46F7F149286C86DULL, 0x1CD7F80EA26AF62DULL, 
            0x3BAD1452A23CFBEDULL, 0x7838DABEF862EE24ULL, 0x8E4056449D3DDBC4ULL, 0x35C6BCB68FDB45AAULL
        },
        {
            0x07D8C6E81CD88732ULL, 0xF672903B54B49FF3ULL, 0x7D5286CF512F777FULL, 0x2C013890B27A24A8ULL, 
            0xC8E1BEF5CE69B5B7ULL, 0x33E131F4DCCA4B9AULL, 0xC79B6BC3ABDBA9FEULL, 0x9D6C00ACC99E2157ULL, 
            0x22F73BC0E7A2257AULL, 0xBCB2DED61A6A64C0ULL, 0xAEE19E64E52BA5BCULL, 0x63CF790D224A7DC0ULL, 
            0xAB3C9EF91E56F320ULL, 0xF1C4E47381468B7FULL, 0x03EF95210860E346ULL, 0x8825CB5DE56B400BULL, 
            0x457793762BB7D80BULL, 0x00099C1940C7AC06ULL, 0x5A4F3494216A40B2ULL, 0x144C60A77D8ED744ULL, 
            0x381C8A44F323D099ULL, 0xBC9F0A8AFB7EE803ULL, 0x32BA9A64E52DD1EEULL, 0x5BCA4FF8F61C9A2DULL, 
            0xBE06AF138E0EAA59ULL, 0x5C13852371E0A2BCULL, 0xF15B0BF86A0CEC9DULL, 0x868D8C52F8F946BFULL, 
            0xCA4F286469EE8060ULL, 0xCD6A1766E84DE0ACULL, 0xBD72A61CA66352E2ULL, 0x9F7EB619B5022810ULL
        },
        {
            0x238720C6BC178188ULL, 0x5F77A80016D65166ULL, 0x678E9244425BAE0AULL, 0x262B970ABA7E03B5ULL, 
            0xCA1763DBD26CEF7AULL, 0x94E37DE159D853C8ULL, 0x0B53412861BAE7C4ULL, 0xAC4D2177DF8BB8F3ULL, 
            0x16CDBA66684BC265ULL, 0xAC827F066B85110DULL, 0xF537ECA72F9B50F5ULL, 0x17C26EF73C7E2F1BULL, 
            0xF931431D1FEFCCA2ULL, 0xF0294A76E04CB3C5ULL, 0xA737938C9B69A5BCULL, 0x7BF0AA4401ECE87DULL, 
            0x48B9DD5F2AC5D396ULL, 0x04A2240C63571F17ULL, 0x56DEFCE6FDB87548ULL, 0xAA467DDA554EB704ULL, 
            0x8E5D160B95AA5D7DULL, 0xF5D4CF659EF79DBCULL, 0xE38C6BE6D580C279ULL, 0x564EE0265E159E4FULL, 
            0xC4CD04CD35E46D87ULL, 0xB086D89AC4B2D162ULL, 0xAD03FEABED3B29FBULL, 0x7FCBB1EF4A7A8B07ULL, 
            0x0B9E8F8CC016E42BULL, 0x4D03D187CF98B3B9ULL, 0x14FDF8259E907621ULL, 0x57FD860E07A8D5CAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseAConstants = {
    0x1EE1A1853C30E4CDULL,
    0x2F9BAB4C414F2AEDULL,
    0xAB6A1BFC3CE303BAULL,
    0x1EE1A1853C30E4CDULL,
    0x2F9BAB4C414F2AEDULL,
    0xAB6A1BFC3CE303BAULL,
    0x7F96CB738CD70FE0ULL,
    0xA2D265189BEC4EFDULL,
    0x2C,
    0x98,
    0x48,
    0x44,
    0xB1,
    0xE3,
    0xAD,
    0x37
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseBSalts = {
    {
        {
            0xA7EE40751C3AD5BAULL, 0xCF0346B4129CE170ULL, 0x4934AB65F9CEF29EULL, 0xCA6A11DF9C091BE9ULL, 
            0xB1C285DC7F9B35F8ULL, 0xC926B7107599CD09ULL, 0xE226C929519FCA3FULL, 0x6FF1A4B75BC2B829ULL, 
            0xFED691C678853610ULL, 0xA19C40D5B0B32712ULL, 0xA4970657D37543E2ULL, 0xB12AAFFE1FB785A1ULL, 
            0x55CE84DD0F9C6C78ULL, 0xBF96B65B91B9D315ULL, 0x9669F9B09BD5D107ULL, 0xE1874575859E9D03ULL, 
            0xA49EE36B38C9F849ULL, 0x2FE3201FA69FEC06ULL, 0x6E652557B76A07C8ULL, 0xBD3AB55E3CF9FE04ULL, 
            0xFC1AE721460FB17FULL, 0xD85C5F54FE4894D5ULL, 0x011240FDA1C2EF95ULL, 0xB22816E41B1550BAULL, 
            0x6DAAEFCA090D0E80ULL, 0x99CEDD830A5B8460ULL, 0x55C5C9A6D0145950ULL, 0x0147C4B61A6CC59DULL, 
            0x7AF080D1D94E97BEULL, 0x4D8235A731C5D7DEULL, 0x12464740BF6C7557ULL, 0xDFD49C57F6B40C13ULL
        },
        {
            0xF8727F3DDAA05A8EULL, 0xF2B26FE692C3A7A1ULL, 0x8F9A4A8CFAEFE9D9ULL, 0x5353459F420D2A21ULL, 
            0xA9B6E007B2C34631ULL, 0x071122E25D11736EULL, 0xE1C5AC1D9D0545F5ULL, 0xB2A3B70548CDB143ULL, 
            0xB6B4467009C69BF8ULL, 0x558809A620058B07ULL, 0x78908BE7ED31BC0CULL, 0x6B2AB9AF462659A0ULL, 
            0xE6B66A0641A70ECFULL, 0x5E44BFF4F215F173ULL, 0x31E9803F83EF46F8ULL, 0x2A019937B25A8F2DULL, 
            0x89C490FB59CC38BAULL, 0xDC0CAB582B99F69CULL, 0xD99C3B36EC4EF0FCULL, 0xD683DFFA46F28F25ULL, 
            0x5D3486E65331D32BULL, 0x02755658D78E4842ULL, 0xF505D0A8E9C37142ULL, 0x303344C7B0A4992EULL, 
            0x4886284B17CC8F00ULL, 0xE51272B0ED798F0EULL, 0x3F9439845169A057ULL, 0x3D58E206259A31B0ULL, 
            0xF36291EA369BA6F7ULL, 0x5043140D3BE29E16ULL, 0x09022210D953D918ULL, 0x6F6A4B1708B7D568ULL
        },
        {
            0x1ADBE916CF4B1CD5ULL, 0x1871B752DE259FD9ULL, 0x41E669C77332D95FULL, 0x8F1A7C53964DAB94ULL, 
            0x0DF6275B55D4169FULL, 0xD181161216890D53ULL, 0xF1C8C743934C85A1ULL, 0xDB164271D391128AULL, 
            0xEE2D7C758274F947ULL, 0x52772750FC836B81ULL, 0x9F4F2FDB8FCC9295ULL, 0x3E143B7657C4C5BCULL, 
            0xD3FDC966C8CAE6E3ULL, 0xA83E9E0FCD2EE7ABULL, 0x1D92F56C726B667BULL, 0x48B808A3D40C0E7EULL, 
            0xF53DADA81A28F0F2ULL, 0xAD95718EB0A52FC7ULL, 0xF45A95FCF5E7C464ULL, 0x0AB88D5CCD49FCADULL, 
            0xC1C32F9EAF4A6AB4ULL, 0xC8A5691EBCC6107DULL, 0xBA080D958E10F940ULL, 0xCB29E40DA8D6CC84ULL, 
            0xB7F52125125F8B11ULL, 0xB6DEC3BE0A35564FULL, 0x347E6A3A7881BE1BULL, 0xD340595C8B5F31A3ULL, 
            0x5C0937FD0D47D41AULL, 0xD9BE5021C07EACDAULL, 0xD5FF4ECBAD3EB1A4ULL, 0xAB63B03BCA149AC8ULL
        },
        {
            0xD7B25495BF9D60D6ULL, 0x299A17D7EC3865A2ULL, 0x1DA88D558FAFFBA1ULL, 0xBC32A2B4B1A96962ULL, 
            0xA0BB3A33AA610545ULL, 0x17645AF25DDF6E19ULL, 0xFB66129231AECCDDULL, 0x43C579C789955F55ULL, 
            0xAD067431B20FEA4EULL, 0xCAA8B476CA99D698ULL, 0xCBDB9831DE019D5FULL, 0x33EC713D03F31064ULL, 
            0x993EB9BC61D0ECD7ULL, 0x03742F2B574C3611ULL, 0x8BB232358C24CB93ULL, 0xF1E1689C564DBF19ULL, 
            0x5380244814FDA6F1ULL, 0x5A70AFA27F7DB71CULL, 0x880588D89139F5A5ULL, 0x2DA8A70D5FC86A3CULL, 
            0xC6D75CD86622DD9CULL, 0x0B63FB1C48C5C302ULL, 0xFD814B5ADE9358B1ULL, 0x7A44CCEC521D4CDDULL, 
            0x9768E09E809B89CFULL, 0xC29936DC9031F260ULL, 0x3793F1A639F41F88ULL, 0x45A5391756344EB1ULL, 
            0xEAB0FFF247E88B3CULL, 0x43CBF31C9876C8C5ULL, 0xD19669AC68AD4669ULL, 0x0A104966CD1A4167ULL
        },
        {
            0x3A0E3DBF70EC1B87ULL, 0x53E02BD1A97EAF23ULL, 0x87935ECCC4637086ULL, 0x2824FA37D77E9385ULL, 
            0x1427521096023629ULL, 0xFBF5D5EB6F0A417EULL, 0xAA379800D39068E8ULL, 0x2362C3FAD7BB09A8ULL, 
            0x0412B2FD2E0B6E09ULL, 0xD88F94A8A0E4F655ULL, 0x323596EB45486691ULL, 0xC71E1E11B2323153ULL, 
            0xE26AC32CDC9B00FEULL, 0x85274F2E44EB1052ULL, 0x39D0B4538575D3E3ULL, 0x6E634E9CD23AACB3ULL, 
            0xAE019C54649F06D2ULL, 0xC14B2B9AA96164B6ULL, 0xCB41FBA2AB9EF8D9ULL, 0xFC594CCA3B2C0D13ULL, 
            0xFDDBAAF159581166ULL, 0xD26EC625B57E50AEULL, 0x85EB6E854186878BULL, 0x109240498F964C80ULL, 
            0x828113163F374336ULL, 0x60C59D72FC56E0C6ULL, 0x67F5ABA493F81A5BULL, 0x10486363F24CB4E4ULL, 
            0x1D250F1A8A3766DBULL, 0xBBE72F261F17B26BULL, 0xB9B4F01A2FCF8671ULL, 0xE48BC51FA0DE4E43ULL
        },
        {
            0x7B4FB8D7FD82B194ULL, 0x70DA58C1A4E0189BULL, 0x105488DB285C523FULL, 0x97B4E248D2CFCFCEULL, 
            0xC8EBAD21D2B1C42AULL, 0xB7DE30A62D256BD9ULL, 0x09BD863565AFEBCCULL, 0xC9A3F619AA07618CULL, 
            0xDE0B13DF75D9403EULL, 0x7EE150EBE9D608BCULL, 0xD09524B81DCBFDECULL, 0xC47F258B7BB56241ULL, 
            0x2E70FBC692A796BCULL, 0xEA27E7D4C6967069ULL, 0x0B391394DBE7FEB6ULL, 0x6461D156443EED60ULL, 
            0xEEED6516ED3E8175ULL, 0xA95645072779D975ULL, 0xB965A5249A2CA2B0ULL, 0xE534471BA36951B3ULL, 
            0x030EC35551276C10ULL, 0xD61361D399F21391ULL, 0x3415F60FFE82689BULL, 0x65F0DD478A82C7F6ULL, 
            0xCEE190021FA1D5CAULL, 0x18CC2E439AC9C737ULL, 0x6E882A6F342295EFULL, 0xFBEF52A325D7AD76ULL, 
            0x09EF70AA6F73C03CULL, 0x0F2C3A02B0A20E0BULL, 0x20F863502F7F293DULL, 0x37D4DEEAEB0DED4FULL
        }
    },
    {
        {
            0xD9A70E84000CDA10ULL, 0xC0C2ECB58EF68E5AULL, 0xDAF4B05BFD4AC2B7ULL, 0x255E417E4C49832CULL, 
            0xC6E76990C45820E9ULL, 0xBA1AABEE1F0273E8ULL, 0x31C0067DF300E738ULL, 0xDA2D603805C36E38ULL, 
            0x66C6227C44ED0833ULL, 0xCB7842F3464F7654ULL, 0x16438CDF07547DB4ULL, 0x412047B3E2C84FCDULL, 
            0xDFB4299EEA543995ULL, 0x34CB556D17DD8947ULL, 0x79407830C3D29288ULL, 0xBF931049F1C96B06ULL, 
            0xA1157355658DE6D7ULL, 0x06247266EE8C03EEULL, 0x7024885D8C2FC0A4ULL, 0xDE8AC74711080845ULL, 
            0x437950351F8C0B7BULL, 0x69913B2A1629EE8BULL, 0x003A40F72582B2E0ULL, 0x383482A01CEA4AA5ULL, 
            0x8B4717BC8BC362BBULL, 0xAB1CCE6A42378E6CULL, 0x6C73E151D271A80EULL, 0xE9DF6303BEA553E4ULL, 
            0x84E090CC5F8FBC02ULL, 0x82FCC1454BA7346CULL, 0x0A9A978A07AF169DULL, 0xED0E5E9C9BC0C2C4ULL
        },
        {
            0x6E7B982ECBA1772AULL, 0xE99D7675AAEB6083ULL, 0xDE73AB03D5299F0DULL, 0x5E3A38CAD8251A19ULL, 
            0xD39C5BE3DEED0CA4ULL, 0xDBB4E6809C8BAC28ULL, 0xB027F6A9A6BBEB15ULL, 0xB3D4F84CAB4FC727ULL, 
            0xA45203D3A8A81E1AULL, 0xDE7775BF977AC896ULL, 0xF8700CC002E12278ULL, 0xC8B14A5AAB2323FBULL, 
            0xE6FFED493C66E8ACULL, 0x7BF34F9D1F8E3238ULL, 0xF7E89EACFC04A656ULL, 0xF90AD3642E415C17ULL, 
            0xD92B65C201DC27AEULL, 0x51EAFEC2153F4C2CULL, 0x1C0D918410A078E0ULL, 0x4AEE22D1E0656B3EULL, 
            0x92C80FE5886BBC56ULL, 0x7CC425507C78D0ABULL, 0x41BF80B309EC5888ULL, 0xDBD342542E8951C7ULL, 
            0x7E8F1FB470EB2CF1ULL, 0x54D28ED5D3AE42E1ULL, 0xF9B31FD59BEA30FCULL, 0xB832B491EB81DE19ULL, 
            0x70504D12CB632823ULL, 0x59FC589DDC5BF420ULL, 0x07A6042A0E066BB1ULL, 0x2F0A238DD544DDCBULL
        },
        {
            0x14C831448174F3C7ULL, 0x1F3A0DEBEFBBB48BULL, 0xA9BE893B36EEACBFULL, 0x11B21C0EB8581D76ULL, 
            0xBF4A06849A445A4EULL, 0xC98A484F06526C1DULL, 0x28B50FBDE7B0A01BULL, 0x4D65B12FBBC8411FULL, 
            0x38E2646F06BCC3AFULL, 0xB754F33E8E7A2DB7ULL, 0x5F916CCE7D0869E2ULL, 0x320D0187F63FED9FULL, 
            0x2E374CD3A5B31936ULL, 0x997EE04E103B3C28ULL, 0x6EC475A540531210ULL, 0x493F45C54E26D25AULL, 
            0x06F60984B16CBFA5ULL, 0xD59C4E39D2867AEFULL, 0xD16E6FB280603EFDULL, 0x51F8CFBCD2519CD4ULL, 
            0xE64630F32A9E10C9ULL, 0xE26978F1D29A7CECULL, 0xF63F23A7127EA2C4ULL, 0x52FE9FC25B4C9B12ULL, 
            0x6BFF5E3256A0196CULL, 0x37F3D3C78A065CD6ULL, 0xD5D4E2413B3918A1ULL, 0xB6DF8DE8A20CEF99ULL, 
            0xBE0A09362C788822ULL, 0x821BF013B00095BAULL, 0x33D3EDA656EC6901ULL, 0x315B266602A24ABCULL
        },
        {
            0x85F95B792B70CE4AULL, 0x6715934309594BDDULL, 0xDFFAB7FE9F9366E6ULL, 0x05C245EF789F2E5DULL, 
            0x07471551DFE5BF53ULL, 0x642985CC6AC5FE22ULL, 0x8524FF491D54ADC7ULL, 0x1B91A2C9C435C33FULL, 
            0x7F7DABC080FB3C77ULL, 0xE524D3D0F5D2176BULL, 0x18FD40B06EDFFE90ULL, 0xA18124438E2733C7ULL, 
            0x45DDC1D213E3955BULL, 0x641AB47331F80D09ULL, 0x86A3DCDFDCD87F53ULL, 0x0DF6E73677895B07ULL, 
            0x0A4DDBBCC8FC222FULL, 0x06A862EC21F85493ULL, 0xD9D18BF710D7FA83ULL, 0x163612E99D8F52E6ULL, 
            0xBC5231723D8CECDFULL, 0xBD9363593B639CDEULL, 0x79958AC7894D3AC2ULL, 0xAF6EE40DFCB92C41ULL, 
            0xE868922A78379A0CULL, 0x3AC824658AB419BFULL, 0x5895465FC5213282ULL, 0x950E892D1F2071B9ULL, 
            0x25DEA2DE0D7750D2ULL, 0x45C85A7193ECAAC9ULL, 0x70EDCAA2FBFFFEE2ULL, 0x645B5E15F7397682ULL
        },
        {
            0x463093F96285D40DULL, 0x9E87F22604F109BAULL, 0xE891AE58EEFE1241ULL, 0xA8A5F1E502AEF16CULL, 
            0xC8E5E458906515FEULL, 0xEF25E086F31C067FULL, 0x89CBD69492FE06B6ULL, 0xD62882E8F5A05459ULL, 
            0xCC2380B47B73F852ULL, 0xDF356B2C60C8BBF8ULL, 0x2321E4C649969201ULL, 0x22AC56DFF9966B9EULL, 
            0xA502AE0FB11CEABBULL, 0x750DEBCF6174A73AULL, 0x586385AEB2370F01ULL, 0x9EB279D48EE454AAULL, 
            0x833A8E1176255F74ULL, 0xC3B0E1B2A9FB33A3ULL, 0xD4E27950DE5A5A59ULL, 0xD8262662C8096281ULL, 
            0xFD443BADAAEEEB4DULL, 0xBC364805E75BF57AULL, 0x5845C56390017699ULL, 0x094EB953F35644C8ULL, 
            0x41D7A948F38708CFULL, 0xFE3F81C8298F0ABCULL, 0xBDFE36C79399F365ULL, 0x744D4609E2967EA0ULL, 
            0x1AE16D5AA7E1CD9DULL, 0x12B81DE7E3757166ULL, 0x16971A34D0DDA319ULL, 0x8FDD32CD484BA389ULL
        },
        {
            0x329E372BF9DC5C86ULL, 0x2CA7562EE2834E12ULL, 0x1CA1BE0241085ADCULL, 0x2414214D8BB2AEF8ULL, 
            0x8FCBC591F9136B7DULL, 0x72403AB411A7E7BDULL, 0x96B71D4572F1D58EULL, 0x84FF6CE3E5339DC2ULL, 
            0xA10946E87788DCF1ULL, 0x9C476DA12BBAF69EULL, 0xBA4C80FBEB10B77BULL, 0xAFA24734C0BB06C7ULL, 
            0x65A79C1AD80E9E21ULL, 0x8012574AEE459F20ULL, 0xD5A69DEE45B61B10ULL, 0x0FC75CA8A81FD927ULL, 
            0x25FB0D1FBDEBA735ULL, 0xB9ECED288FDD7EA5ULL, 0x65B426B0D6AB9B4DULL, 0x59D229854D7B52B2ULL, 
            0x4AEB917570E0B205ULL, 0x1034049F6842D8FEULL, 0x6A05155DFD3AAF69ULL, 0x90ED1A18E857A2BAULL, 
            0xE9DB1D5AC77163ACULL, 0x95E7A314568B7150ULL, 0x17B7FEF0D09657DBULL, 0x08C70B566BC7D805ULL, 
            0x7550B523ACB5A217ULL, 0x06BF359B120226D9ULL, 0x9DB16A023C02E34CULL, 0x2A02F30C19FB3129ULL
        }
    },
    {
        {
            0x83505A91E8DC76CBULL, 0x1C27C44E51242A8BULL, 0x8F1769492B3481E5ULL, 0x3EDF52F777DC8DF4ULL, 
            0x09C35253876136E8ULL, 0x2818880C4CF25ED5ULL, 0x6166E857E0B4F0A9ULL, 0x2D024B455DCF6689ULL, 
            0x0367ED762C4906DCULL, 0xB7F644CC5C9E3BB4ULL, 0x8E3ECD8EE4027D25ULL, 0xEAFC625891229DE8ULL, 
            0xC6289004561ED722ULL, 0xA38928BA3D4C6D1EULL, 0x6CE625365109D44EULL, 0x7301246FAA6A9447ULL, 
            0xD1624EFF86A9A2C3ULL, 0x804F87FF39968805ULL, 0xA72D4169BA181891ULL, 0x6B498EFD229280C2ULL, 
            0xA7EC3D2FC83C4C2DULL, 0x7380C5A766D8842CULL, 0xB955F0720B83EDF4ULL, 0xA11C9D87821A5F8FULL, 
            0x7081E1735CAE6AC3ULL, 0x52E702BD56F861C5ULL, 0x91F3E6D84D87DAE9ULL, 0xF75FA517E1E72234ULL, 
            0xEFB98BEA7ADD997CULL, 0x6826FFCE5BF0D2C6ULL, 0xE50576F511035370ULL, 0x9835291E3BB69B17ULL
        },
        {
            0x9F942AA9355D666FULL, 0x86BD4AD4730CF8C0ULL, 0xD10255E584B59589ULL, 0xD9BFCE012A3656ACULL, 
            0x9A562A868802AAD2ULL, 0x07764ED98F6B304AULL, 0x8D391A324E074D76ULL, 0x041AF0E9C414ACF2ULL, 
            0xB634052D7FB66694ULL, 0x7BA8EBDE97D6FE20ULL, 0x2FDA4FB26880E669ULL, 0x19B71AEC56BB7377ULL, 
            0x66EC3C0260F669C1ULL, 0x3423011D2CE9346AULL, 0x782D394CE76CABFBULL, 0x030BEFF7E98FB585ULL, 
            0x0E15AFECC54370DEULL, 0x7BAF1DE0672E4F0DULL, 0xB1525CD913E0443BULL, 0xB0EEFC2C624D8108ULL, 
            0x1765B92F9867F642ULL, 0x446C5324AC08C0FFULL, 0x5EBAC5983DB88536ULL, 0xC24BC2EF64FF934CULL, 
            0x449B6971EA39C1CFULL, 0x6579628CF9AD7BF4ULL, 0xFCBA16A23CC3D205ULL, 0x0ADCE17CB7FB3947ULL, 
            0x73E0C6B108A79494ULL, 0x920A07825FE3771FULL, 0xC0A67970F1116FCCULL, 0xEFC51C57237EC546ULL
        },
        {
            0xA98D0DEE85B8F9A7ULL, 0xBAB138322FB4752BULL, 0x0B222E9173333E3AULL, 0x485353DEFBDCE9B6ULL, 
            0xFE1160B04892E7D2ULL, 0x31FA8F17E13A89D8ULL, 0x5D97976BC506397BULL, 0x239E725EC75A258EULL, 
            0xA9CC9AC14082E3D2ULL, 0xA4DA804790FA959BULL, 0xA544D61432FBE4F2ULL, 0x4E02755C3814608AULL, 
            0x0DC04D67553BAF0AULL, 0xAE9DD40C925F85E6ULL, 0x640FB58502AAF931ULL, 0x398525E1FF7EBB15ULL, 
            0x8DF641CD644E36F5ULL, 0x8ED986F776583422ULL, 0x858B8EF9FD46D9A8ULL, 0xF6E0EF5D77656440ULL, 
            0xD466E65C29B36B6AULL, 0x5B90579880870DBEULL, 0x1FE466DC161A6AD9ULL, 0x5B4F982C1943AA4FULL, 
            0x07A4A0E04FAAFE8DULL, 0xE35063E0B0B291B3ULL, 0x362735B497CB3F95ULL, 0x4302BC9D83C7F511ULL, 
            0x1999215E73AB8433ULL, 0x5E569460C7A62B7EULL, 0x7DFE397BA178D2A8ULL, 0xBDD651F8A62C045EULL
        },
        {
            0xEDB4E752C2C2D6FFULL, 0xF3371DFDECFF4C33ULL, 0x50887C81C69854ABULL, 0x988B8B9A7890AD92ULL, 
            0xE0F195EC2E8F7D12ULL, 0x23A30C26673C03C8ULL, 0x643BF06C58BE3B10ULL, 0x1362BC13E358E2DDULL, 
            0xAFFCB03AAB877DEDULL, 0x3C113117A8551E8BULL, 0x8CA5FA14DE9EC266ULL, 0x71D9BC4B0A96D512ULL, 
            0xFAA5957BA547FF89ULL, 0xE841569EF55A9FE1ULL, 0x0049314CA6813002ULL, 0xBC322CCD0E75C8A6ULL, 
            0x8CBC61F13DACAA56ULL, 0xE4D54FC5D700932FULL, 0xF50B5E5DC0516D3FULL, 0x0E80E13AD3EEF0A2ULL, 
            0xBF8C0F3AC2946C9FULL, 0xE05B31BDEF3235FBULL, 0x5D3C04503BF6D3B0ULL, 0xC7A964C03AA9A6CFULL, 
            0x63E027A2C29EA050ULL, 0x4F7819C7A759832FULL, 0xFF5BD8FB88C83B97ULL, 0xF8A698AAAD847216ULL, 
            0x13F1DC833CBAF8AFULL, 0x4F3C28DD372AE95AULL, 0xEE0B7AC6FF3FCB27ULL, 0xCD5456350483BE91ULL
        },
        {
            0x65CF7B83690C08B7ULL, 0x7F3767E5FFE6B858ULL, 0x2E5BF374AB0CCDD4ULL, 0x4F2F71B48F1C2018ULL, 
            0x2B4F8EC3C3B896DEULL, 0x5DD2481EB47E695BULL, 0x3CEE3D7B7712F83FULL, 0x32C7B6E7D6275FD7ULL, 
            0x72A8BD8E3BD2C65CULL, 0x36C1D2AF28C44035ULL, 0x6500A6D2C99E2F7BULL, 0x8BE919F79EE182EAULL, 
            0x82C21FF8135DD5C8ULL, 0x44CC528D2CAB526CULL, 0x97DC961F2C5FACF8ULL, 0x459EE1364BDE9246ULL, 
            0x32DDAEC30F2BDFBCULL, 0x21F3D2B448532897ULL, 0x1656D69491F085D0ULL, 0x2714BEB5D6D5BE47ULL, 
            0x2EE28E39CB6F5B1BULL, 0xF636805438613581ULL, 0x464A15EE87DD745CULL, 0x1AFA004FA7A3F994ULL, 
            0x6A81E17267C1D249ULL, 0x6C27D3A3D13F49CDULL, 0xDECF87F81F830D89ULL, 0xCC1977021C0958F5ULL, 
            0x2E76F5EBE62B3E48ULL, 0xDFB2BBA79C36F608ULL, 0xF5554AFD88F542A5ULL, 0x352E187780E85376ULL
        },
        {
            0x506CA34896032BE1ULL, 0x6B413168D2D8A08FULL, 0x4296E2258FFDCA2AULL, 0x50A78A670290FD3CULL, 
            0xACF062C2D4F5893BULL, 0xB228623425977D8CULL, 0x48108CDE6DED256DULL, 0xBBFACFFCAD57D213ULL, 
            0x6994EC67496E4D6BULL, 0x48924DE4A37166B9ULL, 0x638BCEE373E20EE0ULL, 0x2E878F51CA85315BULL, 
            0x168054651D5BBFBCULL, 0xAD73C5C710621D75ULL, 0xD331DD6EAF9FA990ULL, 0xC4A79C8A53636D59ULL, 
            0x163EFFC2FF3DEE9EULL, 0xE041EE80088C3290ULL, 0x005FA102E4AAB05EULL, 0xE7A96000005884A1ULL, 
            0xF5D6AC22032BB080ULL, 0x42215E002929DE1FULL, 0xB5DE504151E8E7D7ULL, 0xE88BAB0B65BF2C47ULL, 
            0x680CC29E4500355BULL, 0xB8D4C21B1A4B47B6ULL, 0x4F71BE36BBEBD2B3ULL, 0xAEE7B867AC8FAF6BULL, 
            0xA8CE27FAD9E1630BULL, 0x9E3930EC0F602DD2ULL, 0x347CAF56B55F8335ULL, 0x33F1E245B833B43BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseBConstants = {
    0x61D5CCCFB72893BCULL,
    0x4B40146899A7701EULL,
    0xE44F3E47643DA5D4ULL,
    0x61D5CCCFB72893BCULL,
    0x4B40146899A7701EULL,
    0xE44F3E47643DA5D4ULL,
    0xFA5963F42846C5A9ULL,
    0x6B30F115F6FE9296ULL,
    0x3B,
    0xCC,
    0x9C,
    0x75,
    0x47,
    0xA9,
    0xB5,
    0x27
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseCSalts = {
    {
        {
            0xDA72BD1C38BB44B5ULL, 0x7C16A0A8E4E6750EULL, 0xB217FC4F077B2405ULL, 0xBBEFB5A7C1BFA157ULL, 
            0xF5C291B5655B564EULL, 0x338C1573F6D071AAULL, 0xEC48202275B985E8ULL, 0x3C8953B28EC54AD7ULL, 
            0xC6EC82C4725C5D68ULL, 0xD5879BD523776EF9ULL, 0x2CA3AB4D17015D1AULL, 0x3D7B1E474B62FC2EULL, 
            0x6A1485600A86DDEAULL, 0x7249ED1F178290B4ULL, 0x74A1F819236D423EULL, 0xEFAA29E2A53BBC18ULL, 
            0x5D21B58F835AD9F4ULL, 0x14AB395F564431BFULL, 0xFA03682E9B452532ULL, 0x6DD8ADB356E1A468ULL, 
            0x461A3F005A866089ULL, 0xED7429410DB82B29ULL, 0x7DF4F93D3DB75E67ULL, 0xCE174B8339D83AEDULL, 
            0x4EB17052D0E53127ULL, 0x7DEED7DD84DD0B83ULL, 0x7C718F53A23770BAULL, 0x735E9973800CD7F8ULL, 
            0xAAEFDAAF817884CCULL, 0xA15A7F37FCD6F2CCULL, 0xD5F04FD8CFF85D4BULL, 0x427D5055C63BE69BULL
        },
        {
            0xF6B429ACC22B4B0EULL, 0xBDB5F56258822406ULL, 0x297DC949E2F1ED87ULL, 0xB99F3C5D17C18795ULL, 
            0xF52E15FCA1CBA8A7ULL, 0x1ED058B37013E83BULL, 0x5676A0D8E989B438ULL, 0x0E336A452B49DC00ULL, 
            0x240BC84C3FD0B6DAULL, 0x497260D60FA3BBC6ULL, 0xD1E5C20B9951BB19ULL, 0xB0E633BBA87E6011ULL, 
            0x3B38785B097F33F0ULL, 0x432F2999DF78BBBEULL, 0x28DF7FEF3DB7364DULL, 0xF306CF27A3091973ULL, 
            0x77647B854206A7FCULL, 0xBC6CA32E1B997AF7ULL, 0xC591DD2A95BA3FDEULL, 0x0AC93F06E2BD15DDULL, 
            0x7D5CF3FC9AFDD5D0ULL, 0xBFE1936231DC0A2BULL, 0x03040C4C7B275586ULL, 0x906C778B18DBD6EAULL, 
            0x2D382B28A39873FAULL, 0x110FEACD91B9682BULL, 0xCDE64EC1D5F52CB3ULL, 0x1C4DFDB06016752FULL, 
            0xD2C7E9387E9603A4ULL, 0x2AE80703D10A03EBULL, 0xD29B15997A9E415AULL, 0x51D830C918BFCA2EULL
        },
        {
            0x0E7902AFC9E7A7B7ULL, 0x9BF69AF6AA89F05EULL, 0x2DC0F31BC322B96FULL, 0x8252A9194FEFB2C3ULL, 
            0xE2814240C350EDC6ULL, 0x1F3B5F0A024ECDA0ULL, 0x8999763A11917BDFULL, 0x5B774958F3EF6304ULL, 
            0x76B02B7D4C31B6BBULL, 0x7F88FA6C2EA00C18ULL, 0xF17148B178B3AFC4ULL, 0xC92EC7823C1A80F9ULL, 
            0x94B4BBDAC5B91CE0ULL, 0xE1FC4028D6ACC079ULL, 0x83A32B66EA9939ECULL, 0x48D420148971B432ULL, 
            0x746BD42CFF73ED5BULL, 0x9E27EDA9548EEA80ULL, 0x5DC4D4550BBD07EDULL, 0x6A10D657A6C0D620ULL, 
            0xFFCB1F7B758F7C2BULL, 0xA60E64788AA3E114ULL, 0x6700C9B8C14F9E0CULL, 0x886617657F459822ULL, 
            0xA1A48C4F491FDBA1ULL, 0x9B96E2330CCCECB4ULL, 0x403E1D43032F0EB6ULL, 0xA26AD889A117806DULL, 
            0xF020FDE8395EFE38ULL, 0xC8CACC995F9C0E49ULL, 0x33B804338C761EF6ULL, 0xE555A74738FC3183ULL
        },
        {
            0x54E9553F017194D1ULL, 0x15E4A2D1C5BC82B5ULL, 0x5F9D2864F3E00103ULL, 0xF22A3B2DCCC63C06ULL, 
            0x649E61CCD3AD2B12ULL, 0x21A3948BB53308B8ULL, 0xB5366825444558D7ULL, 0xE20CE2FAC371A985ULL, 
            0x0B69D0CB4282A77DULL, 0xBAD4F1266DFDFABEULL, 0xF7307971EF15A9E2ULL, 0x8791517BEA8028A2ULL, 
            0xABCE5216A60D1FCFULL, 0x7F3C8B9FF5A559D5ULL, 0x8B0BD40F60821A26ULL, 0x9748C40A80796E34ULL, 
            0x090712599BC71FA8ULL, 0x5EFD0D30222A9F7EULL, 0xCCBB2EE23D3D0EA1ULL, 0x367091BFC895C36FULL, 
            0xAB9B0CDF156910C9ULL, 0xA7F29E1D8F3541FBULL, 0xCF3E467B8A1877B3ULL, 0xB58D5690D3BF2A70ULL, 
            0xC82B7E1B122080AFULL, 0xD96D4E512DA860D4ULL, 0x9C04E98E1668CEE3ULL, 0xBC450EE687ACA3E2ULL, 
            0x3AECCFA6883FA7C2ULL, 0xD05AD9E56C044E00ULL, 0x87353240D8F649B3ULL, 0x936A5297571CF79CULL
        },
        {
            0x02EE8D594D521103ULL, 0x44C1C67BFE3CFB4BULL, 0x4B78D3B949228E46ULL, 0xA30C92617934EFB1ULL, 
            0xFFB3FCAF6EE01F94ULL, 0xF50876508625AA64ULL, 0x112FDB9DC24A9B99ULL, 0x644946BF88A41D47ULL, 
            0x10DCFC87ECDFA3B9ULL, 0x64E34CD2F9CD58B5ULL, 0xCB41E443284B9709ULL, 0xEFBAF8EDDF7A59CBULL, 
            0xE901043FD58C6E1BULL, 0x955A48CBFDCD66C5ULL, 0xE345687A8C3D0891ULL, 0x84E160A72CC5DC39ULL, 
            0x4623DEE6364E59CFULL, 0x7931577FEC6EB96DULL, 0xB1A86419A61AE6F9ULL, 0xA3F1DBFE01AC286EULL, 
            0x326735AD8DDB6A7EULL, 0x64470AB228A4068AULL, 0x8686A66B03F11C2EULL, 0x4162691675BEC1B6ULL, 
            0x714CF0008AE3D97CULL, 0x05CA06D090845DCCULL, 0x077FDFDBF95BFA11ULL, 0xD47E3E708A634877ULL, 
            0xE80B5FF6E7DD8966ULL, 0xDBBC4D8F79EBDBCBULL, 0xD1B50C2EDD3ABF51ULL, 0x81CA691B0CA6A3BBULL
        },
        {
            0xFC13E3D0FBA3B054ULL, 0x2D315EFDAFB28441ULL, 0x93EEF4D65F31215AULL, 0xEE307943D6EC1219ULL, 
            0xA942392312CFE024ULL, 0x25601357BE06E751ULL, 0xF6F9CC82A9B044FAULL, 0x98CF300CEA217214ULL, 
            0x9F07384EBB14706BULL, 0x50E29BA0F86C262DULL, 0x3DE535548CE47658ULL, 0xA17A8D9874CD5A0BULL, 
            0xAA704656378F8AC3ULL, 0xB52F262F4E99C010ULL, 0xD79A33FA56FFFEFFULL, 0xD1F9ECE4A549E620ULL, 
            0x1F132C25D3D2A040ULL, 0xE3F24B1A3CDE341CULL, 0x699EA35366D32831ULL, 0xA2105570BE928C6EULL, 
            0x8EBE0BCADD6E356CULL, 0xC2D5509601409C4FULL, 0xB563BFBA0346BEE5ULL, 0x4A8A2FC064D07DD8ULL, 
            0xCFEC911E62E662FCULL, 0x64BE5DD82747690FULL, 0x81886528B37C0708ULL, 0x19BDE5B96C82F3C8ULL, 
            0x0C9BC6C65F2B5B40ULL, 0xBB2CABFB2CB547C8ULL, 0xD19D7C662CDD10A7ULL, 0x59901EF4A396590CULL
        }
    },
    {
        {
            0x001C4A167A6F8FEFULL, 0x52FB998A94117446ULL, 0x26EED168FD54C200ULL, 0x51E11376638C5146ULL, 
            0xF7F48836EED4C72BULL, 0xDC2E0CB4F926E377ULL, 0x2971F6697875ED7DULL, 0x668E83E43C80FC3AULL, 
            0x848DA5AAB49BFA7CULL, 0x47884845C43DBB06ULL, 0xCA3C13C4DF2E5A51ULL, 0x821E796E4F63F8DCULL, 
            0xF56B9413C4C2948DULL, 0x52D87FE46A56F7E3ULL, 0x481CCECBFBE845C8ULL, 0x00019E79BFCB0BB0ULL, 
            0xB4A0F1E7CFE847C9ULL, 0x41460B96B946A1D8ULL, 0x95910CC9D0EEA326ULL, 0x5994C04EAB306729ULL, 
            0xEA6EB2D44154D418ULL, 0x6CCD279770052588ULL, 0xD17D2CA508031A7EULL, 0x6D91BEB3D209EDDDULL, 
            0x4198D05F5CF1C4CAULL, 0x1AC32C028605CE16ULL, 0xABF9DD64A2C3C50CULL, 0x1EAB3A57BD9BCD7FULL, 
            0x11CCD9EF30EEA282ULL, 0x0D038378EEF7BAB0ULL, 0x9FD2BB72BADCCC8DULL, 0x6FC98A832DC25A1AULL
        },
        {
            0x96017EF1B66CFE60ULL, 0x8B892DEA73AE0015ULL, 0xA369E5B9A9BAA416ULL, 0x3040C2B754F16936ULL, 
            0xB263B7999AA828F0ULL, 0xF707F90BE1DCFC81ULL, 0x50E18AB49D0ABA17ULL, 0x9DCA4FF9D84EDC82ULL, 
            0xEACA9A18665868B5ULL, 0xD6816C21A56E0E3CULL, 0x8AF4B2CCBDB06831ULL, 0x7AA7A9D0D954B12FULL, 
            0x6ACFA89608D2224CULL, 0x9061DF0024AA0D89ULL, 0x4C2FAB704C818E99ULL, 0x13C3070555C96F89ULL, 
            0xB380C195213028C9ULL, 0x743B8768DE3CA168ULL, 0x267B5957F6C33950ULL, 0xB588BE0D2719A13EULL, 
            0xB8FADE8F480B8CB4ULL, 0x94A33A8633E523C7ULL, 0x86CA10C7C2D05405ULL, 0x0FE327309ACCD32CULL, 
            0x3874BBD3FFCC56F2ULL, 0xA357EA720B75E919ULL, 0xC9602716B73D0666ULL, 0x08FEFC805DA8AB46ULL, 
            0xEE39F4B083CF6AA2ULL, 0x6B0C33C1B13501DFULL, 0x06A41E9DD0FCE52BULL, 0x63CBC72A247DE859ULL
        },
        {
            0x74E45C3BCB56079AULL, 0x1DCB9F10113522ECULL, 0xD6AE094C2DE4A32CULL, 0x5C990DFDB7F6CF5FULL, 
            0x0E1B94B48F7F8B3BULL, 0x145CCA92825866FAULL, 0x9FE33A1F73DB7A8EULL, 0xDB9FEF796600FBB7ULL, 
            0xF917CC7D2FA8064DULL, 0xF6115F8E0841FD9EULL, 0x1C4418C8E6AA76F3ULL, 0x5351ED4E9CF8A31EULL, 
            0x4681DB8BD547A3C5ULL, 0xB8B4D6240CDD2621ULL, 0x2AF31AD600F977FEULL, 0xC016B9A4EE3258B2ULL, 
            0x78FF00A2FE76FAB2ULL, 0x433F52A7999AAB37ULL, 0xB3F137583E9776CCULL, 0x4EFFF5D36CE5D2FCULL, 
            0x4AC87113C5FA9784ULL, 0xB34940C29B1A37F2ULL, 0x7E0887B6F022EDDBULL, 0xE9844F1636D55595ULL, 
            0x7B71E90FBC450676ULL, 0x4ACB1A18460AC3A8ULL, 0xF45FA17ED452E461ULL, 0x47F5A2403B051F45ULL, 
            0xA552FF6BB4E11E34ULL, 0x5ECC1847944E8E99ULL, 0x8E96BACCE6BF6B9FULL, 0x066A311852EA79B5ULL
        },
        {
            0x44F0DE33B3D3437CULL, 0x899DCD3526A57D7DULL, 0xDB50AA9CFEF71C82ULL, 0x0A44AE43278B2D9CULL, 
            0x52D410E67601EC15ULL, 0x996F50238A5476D6ULL, 0x44CDAF16F4B01E11ULL, 0x647AD4067B0C2A1EULL, 
            0x1F09D39C33BE9B8AULL, 0xCB253FD6A89D1DA1ULL, 0x1E3BBF9A2D578FD5ULL, 0x91D1D9CE0A4F9379ULL, 
            0xA7FB938EBF5DDC25ULL, 0x863F4A115C886799ULL, 0xC7C55DF15F2B9B45ULL, 0xE8BCF9311008FA95ULL, 
            0x7AB58E5A3508FA60ULL, 0x2A581A4188091414ULL, 0x4EA086EFBC1F51C3ULL, 0x259BEF1DA210DAB1ULL, 
            0x9B853FEC6C69590BULL, 0x779C0588DFB6F31DULL, 0x9FD7CDE7E0B05592ULL, 0x70B84168D79B89D8ULL, 
            0x839A9A3291FED7DEULL, 0x3F36C0FFB81A9C75ULL, 0xA411C2BACF6C2A95ULL, 0x92A2F18CEAC27AA4ULL, 
            0x8D9621ED3DC74087ULL, 0x454A5B68985B2EB0ULL, 0xC1674F2832B17972ULL, 0xFC21C737A45F0334ULL
        },
        {
            0x09E5B40299DB1D6EULL, 0xD762ABBC234FF585ULL, 0xA41BEFC268324316ULL, 0xA6607925953FDCC7ULL, 
            0x54F3D0F338223F01ULL, 0x8DF68E2FBD3861B5ULL, 0xACCB7AAC4F3885F9ULL, 0xC513C9088C31C2F8ULL, 
            0x999733BAA3320E7DULL, 0xD6495BACACD19AFFULL, 0xBA5EFF835B892883ULL, 0x9A306FB744A41365ULL, 
            0x62B5DA1795A9E06EULL, 0xD62F0CC69C23010EULL, 0xC976593E2B8F5E26ULL, 0x5473F5BC7BCB097FULL, 
            0xA19425D871707490ULL, 0x85DD2754392940B7ULL, 0xE87161ADCF72F160ULL, 0x4AC0F0662678D21FULL, 
            0xD423E7162531D2B2ULL, 0xC39835DCC067D81BULL, 0x8EA547BFE0191563ULL, 0x8E70BDF81CB2229DULL, 
            0xB989B10C76F62BF0ULL, 0x5E2104071471B7A0ULL, 0xC02575769FE60958ULL, 0x70E16F1557CAC66AULL, 
            0xC70DCA5FF1733B92ULL, 0x44FFE4A5B7726968ULL, 0x41AA2C5FD87BF924ULL, 0x4E6B81713A84B24AULL
        },
        {
            0xB4BD92B231418724ULL, 0xA5D23DDF7F5DF676ULL, 0x6D80FCF1CC97EEDDULL, 0xB1A755F47E2484E6ULL, 
            0x100638FD8C231F50ULL, 0x14C9D035AE492DF0ULL, 0x2D3578343E1FF8BDULL, 0x2068B2B45C4F157CULL, 
            0x36BE6AAA28EDEBEBULL, 0x0DF8848C799FEA4EULL, 0xE3306B02AC860693ULL, 0x294289A4355576FAULL, 
            0xEA6181C49CE930C3ULL, 0x5BBC47DEA00572A8ULL, 0xDD9BFCD9895BF02CULL, 0x84407787024EBA0FULL, 
            0x250A394BC4D7FC41ULL, 0x1E96B781F3C8A844ULL, 0x9B04FE5D0ABAE4BEULL, 0xDBD957F0A80362A8ULL, 
            0xE7059A0D3F5BE88DULL, 0x3E1623BFAEB0DCE7ULL, 0x6C3E13A5164AD51CULL, 0x2D33CE33A80A259DULL, 
            0x712AC2364125D525ULL, 0x9A8D06984D8F9CCFULL, 0x4C83A59541FF3F72ULL, 0x5018CF76FCCBCD7CULL, 
            0x47EDE20B2620797EULL, 0xCD0E17951A6202CDULL, 0x7C9D2AABF942C8FCULL, 0xFDC2839CF27C7C4DULL
        }
    },
    {
        {
            0xDD034062233546D6ULL, 0x2A8BF66392A286F7ULL, 0x5FE96E6EEC212762ULL, 0x4ABC7FFD9231878BULL, 
            0xB35DBF9E4C0B8D09ULL, 0xB2106FD6C4BD8CB3ULL, 0xFF32D6F82B52DF7CULL, 0x3E9F26DD773EF0FEULL, 
            0x4477B7F736F57A69ULL, 0xD03788C3A4CE546DULL, 0x6C65DCC65D74F0EAULL, 0xBD359BD1778BE0F1ULL, 
            0xB6C28F801248FD03ULL, 0xD4892B495DA13A2BULL, 0xAC394EA39A5FE20EULL, 0x28D8E713CF3DF6EAULL, 
            0x694EA8A48E01EBD1ULL, 0xDE96D14E302CC3B7ULL, 0x6CD5E27A6179E411ULL, 0xFBF655E6B8A24203ULL, 
            0x6B8E47E8EFF8E962ULL, 0x1759687AB96E50C6ULL, 0x83BE251639C266CDULL, 0x46D6A910074FC45EULL, 
            0x4934697F25C61FE1ULL, 0x1C970F7E13620885ULL, 0x1CABA792A6A659DDULL, 0x788F40654C808BF9ULL, 
            0x4C5508EC72786B9FULL, 0xD317CC74C6D46740ULL, 0x19E0AA5F4E0EDE1CULL, 0x4CB1B7F8E6509217ULL
        },
        {
            0xE7831F9377C6510BULL, 0xFAA445F73EF3FFCCULL, 0x4CD7AE90ED0736C8ULL, 0x84A907C984254F9FULL, 
            0xF69075DFD2E38FE3ULL, 0x9182D1AEA32598C3ULL, 0xBE5D5AC5E80F7D80ULL, 0x3E905D2EE4DDBF60ULL, 
            0x4BED59BD386E8ED7ULL, 0x3E056DA7ED7AF351ULL, 0x3A1ECFFA8F97FB31ULL, 0xB274138B0C8AC11CULL, 
            0xD30077F5DD9D81DFULL, 0x38862F1C09640571ULL, 0xC9F571DA37744C0BULL, 0x248CBCF95E137E77ULL, 
            0xC15BE35F82E46561ULL, 0x8AE5D40C434504C9ULL, 0xC1662F43C004EFB2ULL, 0xAFFBF55F2AE15DFEULL, 
            0x73CAEC30E7D0171DULL, 0x63AE5FE7AF8DBDE3ULL, 0x864849E7BAF40AA5ULL, 0xAA2EF967A0696781ULL, 
            0x48D896D12D48103EULL, 0xAF3DBF2218ED2570ULL, 0x759F405B169D90CCULL, 0xD579C1A5C40A0732ULL, 
            0x4E8CBEBDECEBEB34ULL, 0xAE0596AFCA3B4678ULL, 0xE776FDDCCA4F0F09ULL, 0x291099CDEE8BBD89ULL
        },
        {
            0x5BBF5F78C891397DULL, 0xF3742CD8EFA9D0B8ULL, 0x0A0FA4E16659BC13ULL, 0x0AFDE6C60E8CE08DULL, 
            0xEB287A07E730C49DULL, 0xA0C0AC9404EE3147ULL, 0x243032F2A7F33716ULL, 0xA8B83E65DDF48DB1ULL, 
            0xF0ECFC9FCACB2771ULL, 0x54A08CBB4A55E5EBULL, 0x271274E68F678E24ULL, 0xD93D2F95C1B771AEULL, 
            0x79055BF138589610ULL, 0x8ADE40F46EF4CAFEULL, 0x6E1D2B2315755150ULL, 0x10FD46DDB5E92627ULL, 
            0xF2338E54286C4A39ULL, 0xFB33966A08301256ULL, 0xBA0FB0C3C2399AFEULL, 0x4BBB28EB7547B6B5ULL, 
            0xFABFF03B91AD72D7ULL, 0xBB71E18CECA75B38ULL, 0x019B8FC0F1A11F48ULL, 0x5631A2F94E4362EBULL, 
            0xD7C12B278E73B5FCULL, 0x910764D5A18E6CC2ULL, 0xE21112194DF08A75ULL, 0x59C4D792D9B76F61ULL, 
            0xCB9087DAF8E660C2ULL, 0x61681DB9CC4043D8ULL, 0x5965F77FF60DCC58ULL, 0x2E330F51585DE962ULL
        },
        {
            0xF8D76A9D5998AB01ULL, 0xB4DC607738109853ULL, 0xC0FE7017D45E321BULL, 0xD7F7868F1BB7DD93ULL, 
            0x1C637DF8EB1113D6ULL, 0xF4534375B2C391CCULL, 0x6FF0892DFB03D042ULL, 0x375CE9D828AB357BULL, 
            0x7585955F0655802DULL, 0x1D51AC75D2023973ULL, 0xFB3B993DC8062C6CULL, 0x5C6ACDE69324D6B2ULL, 
            0x2E94ED34BCCAD5A9ULL, 0xB360A28721BD53E9ULL, 0xE036E68F89331B31ULL, 0x7802E37293774EF1ULL, 
            0xF45CB52ADD050FCEULL, 0x5F07CCFD83497280ULL, 0x394DED8D391EC384ULL, 0x8C90CB97CFD2390DULL, 
            0x05F48D20CC23F748ULL, 0xA3E6F1A14579F55CULL, 0x37A4D3E88EDB6735ULL, 0xCBEA2AE32021AEE0ULL, 
            0xE7BBC4AAADDA80FBULL, 0x41A6180E393CA565ULL, 0x9AFD2AEE16E17661ULL, 0xCB64D4D70CAA1530ULL, 
            0x74D40AE8C5940832ULL, 0x07E5977A8862EAABULL, 0xFFDD485C111CD25AULL, 0x97E5BB6BF4B3A40AULL
        },
        {
            0xBFEC4E75EFCC9ED9ULL, 0xD3BA7104F254C5DBULL, 0x9E395F81156D7C7EULL, 0xE05B4993D553D8DBULL, 
            0x53AC83651676266EULL, 0x51B05B3A87BB8131ULL, 0x6A4F38A921962339ULL, 0x71A5A8576EBC0FC3ULL, 
            0xB1A1F341F05F02E0ULL, 0x770BCB6349BFC50CULL, 0x54FC8FBFC41E2616ULL, 0xB6CF29B5BABF1F93ULL, 
            0x8C2CCEA7A9733116ULL, 0x48A48DD64CC10216ULL, 0x2549C3C797D83E16ULL, 0x56F305350C2FF734ULL, 
            0x9FB65F421ADE30E3ULL, 0x6CF845E8BB24BDA7ULL, 0x8F6235E35000C816ULL, 0x48EC9ADD09C4AB2BULL, 
            0x214DDE6FC9C11148ULL, 0x7A9060E24A42363AULL, 0xF242248DEAEF52E1ULL, 0x3E9D4DEB194D472FULL, 
            0xE4AA0FE06778707DULL, 0x713DE9C6B157532FULL, 0x0114C08A1EC7D4A0ULL, 0xCDEEDC84C2BA0E25ULL, 
            0x3A02DAD5E794A2ABULL, 0xB31829FA5BF9E0D8ULL, 0x0451A3A8F6FE45ECULL, 0x2796C636F561AFB9ULL
        },
        {
            0xC9FB3590A440F6AEULL, 0x4A4198CA0A794F7CULL, 0xBF8EA0B410CC2CBEULL, 0x8896BB6AEB5BB742ULL, 
            0x028226AB791D543CULL, 0xABDC7764AD27E087ULL, 0x58E13AA319F0562FULL, 0x2491E8A5ABA36380ULL, 
            0xF65650601DCA4EB4ULL, 0xAF2516C56E04EE9DULL, 0x7E597D68C1981CDAULL, 0x73D0A3F04D6A92C7ULL, 
            0xE44A202A2850BCABULL, 0x9011B755612B11A2ULL, 0x37C01F22A189AFF5ULL, 0xC48C1C8594C1714BULL, 
            0xD45A9DAEE33185A6ULL, 0x4994D52C94ADF638ULL, 0xFEC640987FF57272ULL, 0x726416202CA75A50ULL, 
            0x676C2F18B307789AULL, 0x4AB3E281DD3BE0A1ULL, 0x04CDCF62CC7AC084ULL, 0x366EDBC9851A308DULL, 
            0x16A4440F8EEB6B3DULL, 0xCB0BF44069861621ULL, 0x008544CF57A86044ULL, 0x3CE6BFB178C76647ULL, 
            0xBBDA13ABE6160654ULL, 0xF003B5D72A97CE81ULL, 0x7086909C443809D0ULL, 0x7491AE4DB2BB3950ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseCConstants = {
    0x2654938E404D3757ULL,
    0x4E2AA49B2C5AC89FULL,
    0xA6EA85C931E8E1CCULL,
    0x2654938E404D3757ULL,
    0x4E2AA49B2C5AC89FULL,
    0xA6EA85C931E8E1CCULL,
    0x31791832EB6D870EULL,
    0x8C5A7858AF7DB2B6ULL,
    0x90,
    0x16,
    0x21,
    0x36,
    0xE8,
    0x83,
    0x0E,
    0x65
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseDSalts = {
    {
        {
            0xA070B05367B4DF8DULL, 0x5F3042AAF46D425CULL, 0xA6BE88A3B71F1BD3ULL, 0x37F63194F1C7C486ULL, 
            0x5A8D606EBF6E0200ULL, 0x74C463ABC6C24C7FULL, 0x7F8E4EA43229032CULL, 0x6707FA66DAB4F6DFULL, 
            0xA6124351A3ED797FULL, 0x43F5747D97C5A70BULL, 0x3A91410E760B4A71ULL, 0x8CA1EFFDBD1C5F86ULL, 
            0x1F739A8F2E2152D7ULL, 0x91E662C401C367FDULL, 0xCF67CF422B1A1BEDULL, 0xA7BD7BFF522DC486ULL, 
            0x558BF06CC9ACB257ULL, 0xF182E278FFAC21C4ULL, 0x12A709F48D87039EULL, 0xB6ED7DE44606B434ULL, 
            0x6EA4B54C6965E1CEULL, 0x06597F619E93FFEAULL, 0xDE5FE0AA2FB439A1ULL, 0x23FF66A3D7347938ULL, 
            0xF13CACCC37BEC657ULL, 0x2B2D91E9A9A3CF4AULL, 0xABAB1C6147602030ULL, 0xCDDDB69074A6A70DULL, 
            0x7A4016C4CC6705F8ULL, 0x342D85313CDD9C55ULL, 0x632FF24F1C28534FULL, 0x79D152058BE8D7B1ULL
        },
        {
            0x61BCD1EC239544D2ULL, 0xABAC1786E723DA35ULL, 0x7FBC3AC7DA1FB8DCULL, 0x43BAE6B802FB8A29ULL, 
            0xBAAE897D0E9B82FBULL, 0x922759FAB43FF136ULL, 0xE4C36197DF2DE5ADULL, 0xFC4BF707E4E1F9E2ULL, 
            0x39B5CBFBD4200CEAULL, 0x8F2CF07EA3DB1182ULL, 0x617B3C1A94EFEEF3ULL, 0xF366C778DAE7EA7BULL, 
            0xA7F305D4660E3217ULL, 0x8BA13BADC76FDD2AULL, 0xBB0EBB09453ECFF3ULL, 0x2BCA668755A37772ULL, 
            0xC0B92907622D233CULL, 0x7C95C5479FE924D6ULL, 0x1186C0AFE44EA25FULL, 0xF2D31595D9E3AA3DULL, 
            0xB1719CC674DB7BD2ULL, 0x18641E508750A6F1ULL, 0xB942E1C21551B586ULL, 0x02333119EA4144FEULL, 
            0x10AB7B6308915E86ULL, 0x86BDAAAE06685353ULL, 0xF70F22C29D37F5D6ULL, 0x7943EA1A984E2377ULL, 
            0x0AE3BA388B0FE4C1ULL, 0x902FA710298CA9A0ULL, 0x5E553C8251D92A65ULL, 0x6140825885401F1AULL
        },
        {
            0xD76021C98618AEF7ULL, 0x91536C69EFE16436ULL, 0xF602BD460C88043CULL, 0x940AF3D97F1D71AFULL, 
            0x6F5389143225E28AULL, 0xC43CDB95C884C241ULL, 0x3FFE0ADACAF7FA0CULL, 0xA2372EE402434EAEULL, 
            0x34B5BFE19B67FFD0ULL, 0xC5489521A2BC5767ULL, 0x87FF0FF573D875D3ULL, 0x88AE963EF3FC4217ULL, 
            0x4BB83A6F4E6F35D7ULL, 0x05D8B74204FADF02ULL, 0xCEB0306436A0FF50ULL, 0x2923EF40746D2F1DULL, 
            0x035AF0A01963B6E5ULL, 0xE40B0EC8A058DEF6ULL, 0x52A2812993C16788ULL, 0x85094CEB4B7F85DBULL, 
            0xD31CCD99A75935D7ULL, 0xB2119DCF132013D0ULL, 0x7883DBC9A9EF7534ULL, 0x47F40021DBC5AC42ULL, 
            0x87A00220BE7D81A1ULL, 0xCCC8A2A5497A0CA3ULL, 0x5160CF651FFA03FBULL, 0x799D21B76E965282ULL, 
            0x812C0912112A20EDULL, 0xEC9C1E9B8B7D634DULL, 0xFFE03B9D79096F29ULL, 0x0EBF894A546ADCFAULL
        },
        {
            0x4FCA5ECB5159070EULL, 0x294E45AC673F2686ULL, 0x8F7FF0D0BF8428BEULL, 0x35F5FB1D6B1142C9ULL, 
            0x471D28CFC011E702ULL, 0x3B427D47FC7826E9ULL, 0x7F8ABBD981DCD7E7ULL, 0xD79C018C7C138233ULL, 
            0xB7CED50D460331B7ULL, 0x17026771855F1585ULL, 0x378020BE727D6FD3ULL, 0x71251D529EA8191AULL, 
            0x7F6E93A3378F17F6ULL, 0x03B031D1479600A3ULL, 0xB55C34D0A3F2C3CEULL, 0x3A69D1E630057A0EULL, 
            0x3B1D5FD1E0D44B45ULL, 0xA637A4609429FAACULL, 0xAA02BEE7EE8AAC93ULL, 0x1FC51EB5EBCAB8F7ULL, 
            0x3C1FF49B495114B4ULL, 0x5486243B37D7E1ACULL, 0x8E3AECA69783ECE7ULL, 0x69318D7D021DDD66ULL, 
            0xFF5375DA8D388BBBULL, 0xA044D4932A0922E8ULL, 0x032F85654E26F0C6ULL, 0x588AE1D9C4407F1DULL, 
            0xB1298C5BE02693E8ULL, 0x56FF759FA3D9B05BULL, 0x52AA03D01D8FA8FEULL, 0x2E1BB99E34C63F15ULL
        },
        {
            0x17C6600375D9811CULL, 0x9E03494BF47D4BE8ULL, 0x11F9A0309CD0127EULL, 0x6DFE269015DCDB12ULL, 
            0x83D7C616821C5B86ULL, 0x83DA9EC2AE67E6E4ULL, 0xFFE594E0DAB6078DULL, 0x1C559BF0B9FE20AAULL, 
            0x3D9BA40C4D9630E0ULL, 0x14DD3F8BDCF3DF96ULL, 0x4B9D31173824CFBBULL, 0x5649AC0CA5BB2FC5ULL, 
            0x6BB5AF28F9024888ULL, 0xACC546F696508C50ULL, 0xFC83BD50413034BBULL, 0xD5FA2E2BA6B13D52ULL, 
            0x015AAEBA342E34E7ULL, 0x31C70E027C760F24ULL, 0x0719A6FC10B45C57ULL, 0x5F378F4DC600EEDCULL, 
            0xA5F331CAB7373FA0ULL, 0x535BE6E13D779962ULL, 0x661A4A52346676F9ULL, 0x9800EFE05A1E94F8ULL, 
            0x7E2611EEBF881B10ULL, 0x887CA2E289DD5A18ULL, 0xF81F2309A8A9A6EAULL, 0xBBA2DF2EDDCEF629ULL, 
            0x2A6AF332CC2AFBB3ULL, 0x4DE0ED65841D8F78ULL, 0x135A745042FEC5C1ULL, 0xC9ECB33FDB64322CULL
        },
        {
            0x30A8E1B1B0307A1FULL, 0x60F7BA38B0E217F8ULL, 0x17938B50D2334159ULL, 0x4B2C9BE4085DE542ULL, 
            0x68106069198F557AULL, 0x27DA9E8BDC4D6CEDULL, 0x726C83DAD19BA117ULL, 0x0A795DD3791793C7ULL, 
            0xC7926E8B0F0FCCF0ULL, 0x3F2463F2E82C8D70ULL, 0xE519E8F859AD7D03ULL, 0x487ACFEDB4EC9747ULL, 
            0x71CFF762A25187C4ULL, 0xBC1FCA1798F83306ULL, 0x9348BC8BE75D250CULL, 0xDE08B04C5E75F120ULL, 
            0xF325D40DDC2ABC22ULL, 0xE07EDA2BDE0FD66DULL, 0xC7E50B9AFA814899ULL, 0xD39D6CFD051971C7ULL, 
            0xA8B251B0857E49FAULL, 0xFF274D8A1A012E84ULL, 0x04A76721CDD401ABULL, 0x0B66D438D4268EC4ULL, 
            0x0367BAD2D7D5297EULL, 0xA12A3B6869FA5983ULL, 0x568533B81BFC650AULL, 0x504CFA7CC75DDB3BULL, 
            0x3DD3DE7F0DFF9BA9ULL, 0xFFD8CC339D51FCA2ULL, 0x00DE72F22BFF6092ULL, 0xE9B8BA780A0B8E51ULL
        }
    },
    {
        {
            0x8777FA5A13E087F6ULL, 0xA5C3FAAE4FDEEA44ULL, 0xA428623A578A5492ULL, 0x0F3AE4E31CA297B3ULL, 
            0x94F854503930CC78ULL, 0xA5AB92713DFC04B1ULL, 0xC13662899C88D162ULL, 0x88B4804E1AF36283ULL, 
            0xEA13987CD557BB9DULL, 0x2F76C1EF3F6D1D8AULL, 0xB49490232C6D203FULL, 0x991378EC67277BC4ULL, 
            0xA51D1D7CBCD571B1ULL, 0x611F237455317472ULL, 0xD1A840A56AB2C141ULL, 0x844A43C804A466C2ULL, 
            0xE272187AC06584A6ULL, 0x6318B603E255C1F6ULL, 0x77455079043E0CFBULL, 0x3615AA35B1F0416AULL, 
            0x638B85345170603DULL, 0x481EEF92EECC6F3EULL, 0x367A5CCABF03AC62ULL, 0x8F92C15DFCCA9C3AULL, 
            0xD3857C93436236ADULL, 0xB9EC2FFDD7A8DD32ULL, 0xA4772A26BDBF39DCULL, 0x062157DAD6145CD8ULL, 
            0x8CE169139CA0F3CAULL, 0xE36FC0C18DA30FC1ULL, 0x5FB50C04959FBC8BULL, 0x7CE8CC16F88843A1ULL
        },
        {
            0xAD75E0A5D5D3EA75ULL, 0x651D5E3CF419182EULL, 0x3EC38CC3E0F796E4ULL, 0xB7C2BE248D898220ULL, 
            0x6D0504FED56177C4ULL, 0x733F0DC5F8FC4FEBULL, 0x133A4860BA168295ULL, 0x6A75C53AB159A334ULL, 
            0xA4ACDDAF2CD56C41ULL, 0xF6DD50D0B43B1EE5ULL, 0xB199F1E1A7558D92ULL, 0x3E459EF0F326CBC7ULL, 
            0x508EF8B10664D845ULL, 0xBDE5B7A5466D2B43ULL, 0x3F6FB49C98F491D9ULL, 0xCD5047F0AAD8FA95ULL, 
            0x25133FB42DA3B504ULL, 0xB541AE2A911A2478ULL, 0xF316AA94ACDB1B8AULL, 0x06DE020EEC77EA30ULL, 
            0xFB4EA110C1CAD64EULL, 0xFC94D15B9AE5F2C1ULL, 0x5FA98C093F85AC36ULL, 0x833969D68D8C2A81ULL, 
            0xE629DF24DEADF58AULL, 0xE74A4D43706816F5ULL, 0x6413F4403986D65AULL, 0x310F932441B58529ULL, 
            0xAB4DF5304E92DF6AULL, 0xD4EF9E7952C91649ULL, 0xE99FB27BA85692ACULL, 0x3CC6B5FBECAB996BULL
        },
        {
            0xE6E34249CCD2D073ULL, 0xEAFC9874D4304E9EULL, 0x72AD17A9ADF80DA8ULL, 0xE18133273F21956DULL, 
            0xDD11BDCABD99BEACULL, 0xE8417008C4EE6C20ULL, 0x7B1F387631BACBE8ULL, 0x379FDFA2816F0B35ULL, 
            0x78E7BD5A69B1D0DBULL, 0x0A782415BECDB2DEULL, 0xDEFDDB74F17753D1ULL, 0x03A0F41734135889ULL, 
            0xCD2C045D6530F997ULL, 0x24A60E29B45612B0ULL, 0xCECD2A830F8EDDA7ULL, 0x85A1E38A338BA20AULL, 
            0x3CB72A90731AFB0AULL, 0x7BCD446E817BE765ULL, 0x9F8599D7F1CCE68BULL, 0xFE8B5A53909188AFULL, 
            0xC1534CC9CD1547F6ULL, 0x99A04B4E15C99C81ULL, 0x558DF629B5EAE81DULL, 0xA9C94CBD3AB90124ULL, 
            0xEA12C5241FDE891AULL, 0x02E556852F9D61C5ULL, 0x1E790C3AB3BD0A65ULL, 0x42A4E8EEEDFF1711ULL, 
            0x5B9F3F64902EE606ULL, 0xB9D703522968D61BULL, 0x9774B946FBF14145ULL, 0x4559EFF47196065EULL
        },
        {
            0x3D0C82DA1768274FULL, 0x0F6A8E3DE05C97C3ULL, 0x24D937E0E66198EBULL, 0x69AC343888EDC465ULL, 
            0x49A3BC3A384569D6ULL, 0x89BDF87ECC9C6BBFULL, 0x6308E1FF6170272FULL, 0xD0437EA08C2F5E99ULL, 
            0x67B28E5B2014644AULL, 0x04044DD547E3745CULL, 0xD5C1348797A29ADFULL, 0x9AC6C8851D1329A5ULL, 
            0x7AA93359FFAAFAF0ULL, 0x6ED51D0E75BC2069ULL, 0xCF68229C7D273E63ULL, 0x4E9641D0805D4577ULL, 
            0xCB6B5006EE7969DDULL, 0xA189BB9E9325E68FULL, 0x0655AFDEB7BF5D2CULL, 0x80CB831A4A8B82A8ULL, 
            0xEBD1B78E3EB5C3B3ULL, 0x2789115F897ED0A5ULL, 0x05D2706B55FB2C91ULL, 0xC0D8C464F9FA024FULL, 
            0x78BB2C8AA4B59443ULL, 0xE9EE1BAB055CB26BULL, 0x1F21EBCD4CAA5E40ULL, 0xA816CFB01E993F92ULL, 
            0x099AA4628DF0F8F6ULL, 0xCCFDCCFC54566E30ULL, 0x1696545B2761F068ULL, 0x28D2E5DEFD2BCACAULL
        },
        {
            0x18D4EA6DE4DC5AA6ULL, 0x8AA5A028DE217D97ULL, 0xF6529AF008A1E10BULL, 0xBBF7BBF69BADEE48ULL, 
            0x35D1131565936AD9ULL, 0x65E25C8638A5B93BULL, 0xAC1503350B0DA29EULL, 0x710BB0A57F3ED85CULL, 
            0xFAF1EFE065016B39ULL, 0x1A0D200F98E539BBULL, 0xF4F4CB88F149AF08ULL, 0x78547B42C448432AULL, 
            0xBCD5A1C13E43CAB7ULL, 0xA7DC690A247B780CULL, 0x4D117C2A80D5105FULL, 0x29286CAB1084038EULL, 
            0x1DD744E007A845D6ULL, 0xAF7FA46003C026D6ULL, 0x09FE472D02D3D0C0ULL, 0x441DD07E233420BEULL, 
            0xD26A25040716F558ULL, 0x42CDEF313FECA9CCULL, 0x13D10FDFEFEC0EE0ULL, 0xDBBCE0D6294FACC5ULL, 
            0x53CD3BC13AC3C744ULL, 0x8DF2ABC7FFB18069ULL, 0xB6EE36401CF27E0FULL, 0x759700F65C4AE178ULL, 
            0x70DCF30E99051616ULL, 0x2AFD9630775CFD87ULL, 0x9D3D23379AA18F98ULL, 0x2EBE872BF7E0A8DAULL
        },
        {
            0xB82436E9DEB119D8ULL, 0x7042B20E8CF9065BULL, 0xCFA7676B6CD20A07ULL, 0x4889F7A26C45943AULL, 
            0x347D6A11EC7549D6ULL, 0xF5348935A6F89CA9ULL, 0x21DF77032544F72EULL, 0x4CCA9B525E4A78B2ULL, 
            0xC4BFD8EF5C4BE533ULL, 0x31EC4B0F33EB253EULL, 0xD7EDE42DE7B26425ULL, 0xDDD2D61BEAEEDBB2ULL, 
            0xB72E5110CBCC4B8AULL, 0xEB4F7AE290D42BDFULL, 0x3D4C36D87E18CD0BULL, 0xD303C871A8C3FFADULL, 
            0x001BF4B45BBA2C6BULL, 0x487D09813784F03CULL, 0xBAFC50DF311C6087ULL, 0x0609968DC13E0265ULL, 
            0xBDAF14D3B21CA5EBULL, 0x9203E3DE1E6973D4ULL, 0x4CEE2B85E1012B18ULL, 0x8857181414D86082ULL, 
            0xA976CB1F608BD19CULL, 0x09B2674DCF9D3150ULL, 0xDC9E2E3C91FD4613ULL, 0x9011C6C99DCC544DULL, 
            0xE2AAA2D3D6C03629ULL, 0x0BF67F20438A4764ULL, 0x9293A42BD612F71CULL, 0x19E9205EFFBAD71CULL
        }
    },
    {
        {
            0xEF2BEF425CFCD6E2ULL, 0xC3F2B4681968E996ULL, 0x4BDA5E7A967742ABULL, 0xB4E8E8676DE7F6A9ULL, 
            0x56C85FB8815196C7ULL, 0xB624431AA80EF49CULL, 0xDF9ED3A67A5A5D9CULL, 0x81C0F5D23731F0E6ULL, 
            0x5F5945F07B9EDF14ULL, 0x6913CAF4B0C194C2ULL, 0xB5851E492A5743D3ULL, 0x9042E71A54ECA200ULL, 
            0x7A84212F73BE22B9ULL, 0x1BFBE0CF4372DF0DULL, 0x10B485D0135577DDULL, 0xFFE9414E86B2CB20ULL, 
            0x6EB948654EE3DE60ULL, 0xD3A307475FDF5CF4ULL, 0xBBFCAF496731A6C7ULL, 0xD8822323C9EC5249ULL, 
            0x11E7A748D21550DCULL, 0x3CBB7CAA0A57F367ULL, 0x193C7E95D2E1729CULL, 0xB7348D407E5EBF9CULL, 
            0x46F951F71BBD1E83ULL, 0x7CD01A67B00EF353ULL, 0x4357035FCC9F1305ULL, 0xAFA9615AC9443E64ULL, 
            0x8543F2F1103F99AAULL, 0x70B10D0F8546E547ULL, 0x3CCC8C7E1E34B17BULL, 0x3A604843A4A62B48ULL
        },
        {
            0xE22AC5D138D68ED7ULL, 0x8F83D4446045EE07ULL, 0x7A0F2034F8F7C89FULL, 0x1F13C282ED11B312ULL, 
            0x45CDE6A2C8ABF047ULL, 0xCB5A24906F6C1789ULL, 0x0DDA7FE7D220E592ULL, 0x9284C293405995A4ULL, 
            0xB12B70A970F7BFC0ULL, 0xCB87437844CDCB6EULL, 0xD493AAFA13E6DD3DULL, 0x1685D65C42362597ULL, 
            0x25F0D74AF4001933ULL, 0x0456DB1CE95A6984ULL, 0xF6B24B23131C8C08ULL, 0x644BAD231E2AECC2ULL, 
            0x7C0A8F9B83B277E6ULL, 0x0A7CE8D6D51E3172ULL, 0x6031DE825D447BBAULL, 0x3583A5882A49E313ULL, 
            0x9DE4E36762885B89ULL, 0xA868E78254C1817EULL, 0x5129C22E651DDBDAULL, 0xB5337DD9ADC5CF54ULL, 
            0x41466E6BFFAC7FA4ULL, 0x44FE8183849DA37BULL, 0xA40E664A0F74874DULL, 0x769927EF28B42323ULL, 
            0x67414295699B0766ULL, 0x98461C5B05B7C2B7ULL, 0xE779F75B545F4EF4ULL, 0x1F96C98782899311ULL
        },
        {
            0x49925140C4BB04C0ULL, 0x54AA257817A60701ULL, 0xAD259909A41A8C48ULL, 0x18770E5803BD3623ULL, 
            0x960B4C7EDB364689ULL, 0x4D5E05B6CE7F0C40ULL, 0x5A1C73F357BF6F10ULL, 0x90C7B1148D810AB3ULL, 
            0xF8AFA6DE6637D1E9ULL, 0x411B94CCCF1F5BF3ULL, 0x509EAF33AB5653F0ULL, 0x2B27868D8C1BCD8BULL, 
            0x2CEB43CCE08B1894ULL, 0x4E26BA1A1A408FE0ULL, 0x1306A2BA6EE31C81ULL, 0x0143AD347F21EEC0ULL, 
            0xC8E38C647485F924ULL, 0x3639CA66629CF7A1ULL, 0x07A6E506B6C2ADC8ULL, 0x353D9AEABF5148B3ULL, 
            0x6668182434A2EAB7ULL, 0xC76B5DB4370E9987ULL, 0x38AE1CBDCBE80366ULL, 0x80967CD38EF421F9ULL, 
            0xA1F9160215E02968ULL, 0xEA2661985A2C9213ULL, 0x9224559B80E5871AULL, 0x6C0C693ECDB15F48ULL, 
            0x9D4154FD0ACBC5CBULL, 0x39E51ADD2553BBE1ULL, 0x939D1F36E8C088F7ULL, 0xF32655D5E41185D5ULL
        },
        {
            0x5496AB0D93091E79ULL, 0x2D908E9FFA7DC83CULL, 0xF097A40D15D79A54ULL, 0x2CF19354CAA059EFULL, 
            0xA7083A5D0450F64DULL, 0xCDEDE18D54190B51ULL, 0x10C04A3097850924ULL, 0x8EBDB4F5D961C157ULL, 
            0xE5DF1596CA8B4755ULL, 0x8674E60C714AFD24ULL, 0x12C0D02795491EA4ULL, 0x2898D38C19285F21ULL, 
            0x4C7DF86B69C4EFA0ULL, 0xB66451350EC0A447ULL, 0x0DDF796DE5097A88ULL, 0x61B4999EBF923220ULL, 
            0xB6B4C29B30153C65ULL, 0x49251541320B82C2ULL, 0xF15B878721B6BAC6ULL, 0x0475938D5F28CDF2ULL, 
            0x5960F8D8CBC21773ULL, 0x163BBFFB6A6B90D6ULL, 0x9DFECC15258AEDCCULL, 0x03071410EDC6426CULL, 
            0x12E4A05396011B4CULL, 0x319954F20FAEE764ULL, 0x835385C0452F7BDCULL, 0x3BE0F92179343E23ULL, 
            0x1516432BFE73BA6AULL, 0x636F629FB117A82BULL, 0xF11DD7CDBD282E0CULL, 0xCD7FF64B690C18F6ULL
        },
        {
            0xE831BBC156D03090ULL, 0xA0F34DE048751E90ULL, 0xD8700577EF77B272ULL, 0x44AAC1B2818F527DULL, 
            0xA52930BD2DC15A13ULL, 0x01E448BEC0951630ULL, 0x2BB894B91324789FULL, 0xB2E2B84D0154702AULL, 
            0x32EEBBACD2AABFEFULL, 0xEFE60BF862E81DCBULL, 0x35AAD686DD4F6B5DULL, 0x1A4B41C33DFC8E28ULL, 
            0x5127342500C7FD22ULL, 0x0857A3351C49787CULL, 0x17B3DAC585DCFD53ULL, 0x36F42A3A69D90454ULL, 
            0x87EA81D00A8EA7A1ULL, 0x4420CB7DB84379FBULL, 0xA8B182EB5BF3D5D0ULL, 0xD4ADB5C222F040BAULL, 
            0xE9B117DAD7E8A4F6ULL, 0xF0D9A71C7F67B59AULL, 0xB4C32153F57C85A3ULL, 0x25F5012A848AF0CBULL, 
            0x74D408A91EBC799FULL, 0xE117E9C134855413ULL, 0x4FC644677C4829BAULL, 0xD1D91E0E723C1B94ULL, 
            0x261CD267C7B95AC8ULL, 0xFDC6B647FB96929EULL, 0x9E3C3313ADE3A210ULL, 0xF83525A40BB2F182ULL
        },
        {
            0xD4DFFDAD3815B005ULL, 0xAE4E2508904D204CULL, 0x46824A44320DEE78ULL, 0xF89E7A8071DAD76EULL, 
            0x7EFDFCA171D181FCULL, 0x3AC517F0735CB67DULL, 0x0DD51F635A0FD2ACULL, 0xEC8E7DC26165A143ULL, 
            0x067BBF235C7690CEULL, 0xA09A1C632B4A38C4ULL, 0x8ECB7830D3AEE298ULL, 0xE627DE17EE280779ULL, 
            0x371A05746E162EC0ULL, 0xE0896C469E1B5833ULL, 0xB79F5460C51C02A9ULL, 0x52D6122586FA009AULL, 
            0x73E28B366BCDE008ULL, 0x30EE2DAB5FBD6FBFULL, 0x1302ABB45EA16A58ULL, 0x6AA89EC3C1A56030ULL, 
            0xBC67A28FE94BDE3EULL, 0x58122B36A07E0A35ULL, 0x1940B4ACF3AD63DEULL, 0xE320299E00A156A4ULL, 
            0xB344129E848873C3ULL, 0xA13DD573E170C314ULL, 0xE5FD0552D10FCB23ULL, 0x358289290168E834ULL, 
            0xD80CC13D9102C0E3ULL, 0x65EDF5F835D703E0ULL, 0xDC05F834495D33DFULL, 0x6FC35238FFBB6106ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseDConstants = {
    0x7D9D9F4F8290F2FFULL,
    0xD42E0623D8377B90ULL,
    0x08E1B3E80F3A3E45ULL,
    0x7D9D9F4F8290F2FFULL,
    0xD42E0623D8377B90ULL,
    0x08E1B3E80F3A3E45ULL,
    0x57412B9DE2031F38ULL,
    0xA033AF8DC949C8C5ULL,
    0x3A,
    0x0F,
    0xF9,
    0xAF,
    0x3F,
    0x77,
    0x6A,
    0x4E
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseESalts = {
    {
        {
            0x7B255F0B1FBA565FULL, 0x8A72AC85431B158FULL, 0x05AEE05E281E2F32ULL, 0x7081D27F08005760ULL, 
            0xBD7241D840BCA28BULL, 0x362C037F6EB00DF6ULL, 0x91E31B2B90824A59ULL, 0xCAEFF8D41404B15BULL, 
            0x0870DF59F964B28DULL, 0x037EB159DCBCE4D2ULL, 0xD08F619C521C6E00ULL, 0x067367646B23C754ULL, 
            0x3BDE1A77DCEF4861ULL, 0xBED2F04C77435759ULL, 0x4CA7CCB3531722A8ULL, 0xC8B0F3293A768FE9ULL, 
            0x90C17DF70D8FA2ADULL, 0x07C292814CFB03E4ULL, 0x7F01E992073E67D5ULL, 0xA556CCB47AF6FEBCULL, 
            0xFB775E0F6C6E0475ULL, 0x2BB285C184A47ED3ULL, 0x6A8A124BE4AED055ULL, 0xD1E01CC25C7873A3ULL, 
            0x8B3E2465DC196906ULL, 0xBC88C4611F9609D0ULL, 0x6079C14CE4F341C1ULL, 0xAE5F42C844DD3DE8ULL, 
            0x7005E205BA9B298DULL, 0xFA08180F2F33B608ULL, 0xFD9ED1110380CADDULL, 0x064F9BE0AE2BD51AULL
        },
        {
            0x4435E64203D8360EULL, 0x7A61BA4ABB9F080DULL, 0x78B1A149C6722FB3ULL, 0x6B3C7F460F884017ULL, 
            0xB881D624250248E1ULL, 0x3BC228B74A45C30FULL, 0x689EB0611E2C20FBULL, 0xC59D518A7B80DF6AULL, 
            0x46A7378519A97DA4ULL, 0x72DEEEB8B117A052ULL, 0xA81FD56CD17B33EBULL, 0x6C45AAAF43C7CB0AULL, 
            0xEA82BFBB35BAF667ULL, 0xE506D6CAB8F985EAULL, 0x39B0614086938FC6ULL, 0xD20103D7CB84D3F8ULL, 
            0xEA381DC123B9E3BBULL, 0x7F55F7C0F0FE8BCDULL, 0x209B5033563BEF9FULL, 0x46C51E8FE2FE57D3ULL, 
            0x218DA43F6C62412BULL, 0x813466A867E3E92AULL, 0x566FF6F37CA672BFULL, 0x16AF2957EA66F045ULL, 
            0x3CE759F17BEA7784ULL, 0xA3EA51491721C194ULL, 0xB06A7B85E16B11EEULL, 0x660794197063A356ULL, 
            0x1FDE1DBF6D4CFC1AULL, 0x4C8EF9AC382AA68CULL, 0x8D938F96C5C85EC2ULL, 0x8E81CBF55E035197ULL
        },
        {
            0x8756FA71F2A600A8ULL, 0xF27F2DECF82DFCAEULL, 0x6EC3B3D5FCC42AB2ULL, 0x8FB636EF7D8CF79FULL, 
            0x4EDB3A2879F0F48AULL, 0xDECD5D3C35E9B472ULL, 0x70B2908D2C572638ULL, 0x7A8AE9B70BCED78FULL, 
            0xB9997119D26EA20AULL, 0x18DC16A914B93FF9ULL, 0x15099A5593B65E1CULL, 0x8248E8B255B8856EULL, 
            0x9F80484BBB14EA9DULL, 0x775599F209E3BF43ULL, 0xBF7046D9A3A7AB85ULL, 0x4A9659EECF89F360ULL, 
            0x91881A1D5C980BEFULL, 0x5951E96F75F8281BULL, 0x91E491FC29FFEA03ULL, 0x9CD3C78FCDE0BA8CULL, 
            0x18D90770444EFA33ULL, 0x9248C390FC953DA8ULL, 0x9FEDEF942CD64901ULL, 0xAB7929B40673E2D7ULL, 
            0x6818B7CC6B8F4813ULL, 0xE0DA9A8BAD24164FULL, 0x3BB04584AF2F1009ULL, 0x09D801B9F3917A78ULL, 
            0x261E8FAF1688D47DULL, 0xAEA1128ED5CB74B9ULL, 0x171F843BBB1BBFC5ULL, 0x12D5619FE27B8924ULL
        },
        {
            0x3B47BD7D6B19321DULL, 0x02025B7CD4797A62ULL, 0xCB4CF80793E38232ULL, 0x273770C4BEFCD133ULL, 
            0x564495CE800CF304ULL, 0x4A6C55508D578E70ULL, 0x7CFDA106F9FDC3B8ULL, 0x6DF58740A8A644B0ULL, 
            0x5D8DCCAA5F0A949AULL, 0x8028CC8CE3ABB87FULL, 0x41468FC341F39902ULL, 0xB4457601205AEB16ULL, 
            0xA62887BAE0B676CFULL, 0x0AD5811B85AE20F0ULL, 0xC4DB75730E2CB945ULL, 0xC8CA4841B3BAA502ULL, 
            0xC0F71F652B3A7725ULL, 0x75FADF1C1819472FULL, 0xA4616EA143776E21ULL, 0x8970C3C890ED7E0BULL, 
            0x317390B417080BD3ULL, 0x909C0C73B2CC0935ULL, 0x3227B81FE74F85D2ULL, 0xFDE4FDBAAD640899ULL, 
            0x9A46F9F677CF5E8CULL, 0xD4856C92490291CCULL, 0xD64D4A3B25590A65ULL, 0xB7AEB4E2E4B17280ULL, 
            0x977C0D74626F1C39ULL, 0xB03EE8929FE1E867ULL, 0xE395F1C64FA2A2FCULL, 0x61E7D3EEF504ABDBULL
        },
        {
            0x04265C6D8372C06BULL, 0x09C6172C0997FF11ULL, 0x24FCA89F73AE5F29ULL, 0x40061E2030B9AF08ULL, 
            0xDA352FBF14AE75B7ULL, 0xB70618FB644F928CULL, 0x032051A0ED0E0980ULL, 0x4DF2A865679E38F0ULL, 
            0x1B5039B61B354762ULL, 0x6A59D13E32354398ULL, 0xA56F0E516DE463B9ULL, 0xEC3847CBCDD57E7EULL, 
            0x672107DDC11F4FC9ULL, 0x07EBBDFAB36EAA53ULL, 0xBD7140DB6568246DULL, 0xFB80EAC47F011294ULL, 
            0xEDAB1B6CAB3003BCULL, 0x9D09D38788E3F0F3ULL, 0x379339E0C9E75D3AULL, 0xF458EE451DD77A80ULL, 
            0x44723D200EC8B27EULL, 0xE7B7528D95F29FFCULL, 0xDC1662842010D404ULL, 0x5ED03DCD2AF7F005ULL, 
            0x13C4556C924A32ABULL, 0x6918B81EA8415202ULL, 0x16A22D9D7D483FABULL, 0xE595F34388CCC58CULL, 
            0xA7E1253C06865216ULL, 0x58244203FD3E1791ULL, 0xE48B8D6A89575234ULL, 0xECEBF75F71691BECULL
        },
        {
            0xF6A8F93F22CB72CCULL, 0x23AC7A95DA9FDB75ULL, 0x3A4AE157C38931C9ULL, 0xAF889D52832CFB07ULL, 
            0xBB956D3E63813E82ULL, 0x2CD4B97C53F4D704ULL, 0xF30343D4BCDD0B0CULL, 0xE8A60F382FC4853AULL, 
            0x46B1968308516A58ULL, 0x9CAE9D6A6C3E0425ULL, 0xA6279BCF65E11136ULL, 0xBAFFD874FDE6AC71ULL, 
            0xF57340F34B8AEC8DULL, 0x483FF0D56CF2C9A1ULL, 0x6B65C6EC35BF7426ULL, 0xDD17685611C97A6FULL, 
            0x4C9839B2DF4D8C72ULL, 0x82D8F3ED6BB0A5A0ULL, 0x435AC7F1129A4175ULL, 0x1791C3FAB602BDFCULL, 
            0x5E4BC0FF197CBC24ULL, 0xBB8BE096614FBB20ULL, 0xA38A1D0C31335643ULL, 0xE15CF4FD2D3064DAULL, 
            0xD49D5F0921385CC8ULL, 0xF76A6ACD8F2E7605ULL, 0xF778DC298AE0ED7EULL, 0x8E5581B318965799ULL, 
            0xB4CBB53C80AC0062ULL, 0xB4616D32185A6535ULL, 0x2A16C293754D6552ULL, 0xBA6AB4071421E2BBULL
        }
    },
    {
        {
            0x63898C38C34D256FULL, 0x9B659E9339AF47CDULL, 0xDF083A55DF9C5A7BULL, 0x1D64A0945126B4FEULL, 
            0xEDB6FD2B3D3E3B13ULL, 0xBFEB1644C5FBF0AAULL, 0xD91C9184A8C3B8C3ULL, 0xCEB4C27BC4918537ULL, 
            0xECABCCD096214C15ULL, 0x13B64DA1316D8525ULL, 0x33496F72642E084EULL, 0xCC4CB9D64FF4F845ULL, 
            0x26CBD9DE2F4AEDC3ULL, 0x1F8B579B6C4778D6ULL, 0x5F2663B744B68D07ULL, 0x17F5804249BDB8C9ULL, 
            0xA82918FBD457DE10ULL, 0xDE4A21D64CBA3A68ULL, 0xFB96015BCA5F68C3ULL, 0x5E69846222A5F633ULL, 
            0x318826AD25C8DB7AULL, 0x3DD2D394A6E33258ULL, 0x8A04DDE413C4BD64ULL, 0xD3745B1E7683A1F8ULL, 
            0x02604D45961508F7ULL, 0x761EBF06C076A58AULL, 0x38261C5C4FE0132CULL, 0xC9C4D64D44FE5160ULL, 
            0x366BFE97B623334AULL, 0x46234DFD1B0141BAULL, 0x084F368C92C79F7BULL, 0xBF243D0B0739D4A4ULL
        },
        {
            0xBA61831FBE85A1D9ULL, 0x24EF6452E6630EC8ULL, 0xE30AAD9D3E761E80ULL, 0x0615F5524249A759ULL, 
            0xBFCEB27572E0E986ULL, 0xC916E290F95BA7F6ULL, 0xE14222FAB125494BULL, 0x055DCA9AE4910CF8ULL, 
            0xFA52DC954D9B4571ULL, 0x21AD3A364ECCB4D4ULL, 0xAC8DD37C70188CA2ULL, 0xE9C146F0C9CD51A0ULL, 
            0x30B8548BF26FB2C2ULL, 0x9093B7716B68B766ULL, 0x6345272592006699ULL, 0x38D6EBB1A7F838B0ULL, 
            0x154E96AEF3C83A94ULL, 0xA6586B1370619E42ULL, 0x84E55CBC81868399ULL, 0xB2D402846D1A7E89ULL, 
            0xE0D7EA653928CAB3ULL, 0x8F1C336B8D1E4483ULL, 0x02091A24AEF5293EULL, 0xC0A41040D03BCE14ULL, 
            0xADDABB1F403AF406ULL, 0xA1D5BB1C821F4DC5ULL, 0x93ECA353E861FEFEULL, 0x52B9FB75B1943EBFULL, 
            0xE9CC62A97AEC8367ULL, 0x61B4764FF00B1D86ULL, 0xEDDBC0AF58D94EFDULL, 0x98F45B20F9C6EF4CULL
        },
        {
            0x5B22E7D126CE2588ULL, 0x6180D44C74801DF8ULL, 0x93B57FE7430F230EULL, 0xD0B97EF0FA01D4FAULL, 
            0x57F6C90D7E4F4205ULL, 0x894F33623CBA9644ULL, 0x56914CB638EB67BFULL, 0x0A0B104658BC9C7DULL, 
            0x7C142B856645F23AULL, 0x0FFA531CD2D48F8FULL, 0xF838C99125E37147ULL, 0xA9E2D70EF24930A8ULL, 
            0x2653A150A4DF3C79ULL, 0x9BDD6DC887A48518ULL, 0x9A38B0F16ADFEF73ULL, 0x96E65D3333D8C2ABULL, 
            0x0F9A8D1F7E6A9315ULL, 0x6DADCEFD8F8CE08EULL, 0xB59B85B5CD8B5E7FULL, 0x7E47C487951158D0ULL, 
            0x17CA58534E54067FULL, 0x611177710393C39FULL, 0x5FFA935E4ECCA742ULL, 0xBBB356DF936FB314ULL, 
            0x8FB762BD81489843ULL, 0xEB7B6C32D785B070ULL, 0x14757CDCC249FCFAULL, 0x659FB81D829D27ACULL, 
            0xECFE2230073E1DEDULL, 0x8EF1C39210D561CAULL, 0xE150D9A7F45141F8ULL, 0x13996D0FE64BB181ULL
        },
        {
            0xCC536E3AED636F57ULL, 0xF10FC82D117C4656ULL, 0x807354DA04FE407CULL, 0x75BC1E703735D002ULL, 
            0xF5C77EE3911946FFULL, 0x4A41815ACD380761ULL, 0x21F1BB95D3E8AE60ULL, 0xA24131751A21DB36ULL, 
            0xBC7EDBC837D1C2F1ULL, 0xA20190A835733B13ULL, 0x19C21F86D94E6818ULL, 0xEEAE6239731A7B35ULL, 
            0x233E4A1470F31DB1ULL, 0x7AFB84DD565BEDEAULL, 0x2152EB39E362393BULL, 0x86A4A9F37DDD494BULL, 
            0x5DE4F873CCC16A09ULL, 0x2ABD364C8339D494ULL, 0xDC52F910F9B8C13DULL, 0x4BE21AA139C47D44ULL, 
            0xE2CAABC2379A1E67ULL, 0x553E82B8499AEACEULL, 0xD0CDD547EE7A5609ULL, 0x11DED9EFBC512643ULL, 
            0x621D51A4CF420A56ULL, 0x3BCE5662FBFBF36CULL, 0xBD95F96BB4DD5009ULL, 0x70E9D94F7B00BA53ULL, 
            0xFB22BD567F0D3C19ULL, 0x4DAF140121963586ULL, 0x763DBB639B0E4AC8ULL, 0xF2BD499A0DF7EB3AULL
        },
        {
            0xEC54173A90C78F43ULL, 0x3B8E2A43933E804CULL, 0x680AFB089009CE88ULL, 0xA8E4DB4573FC851AULL, 
            0xFE9D4548703ED870ULL, 0x8B23CCE07E0A48DBULL, 0x1959D710438AAEDBULL, 0xEFC1D3459578FF7AULL, 
            0xEED8EA4AD3E5DF0DULL, 0x3A71FF99021ED6FFULL, 0xD3F6D1FA69E04AB5ULL, 0x4BC169E5642AFD86ULL, 
            0xD62D9206D1DDAE09ULL, 0x97EF9B7CF88978C5ULL, 0x127951ED02D1F8E1ULL, 0x14B31DAD60A6479DULL, 
            0x3AC5C090925B2040ULL, 0x6931FED52D3AAA21ULL, 0xA07FD96685FA82DDULL, 0x61D702291DD5C266ULL, 
            0x68E95E103152EAB9ULL, 0x9AC35344B4FD9EF7ULL, 0xB1A2A003097E1517ULL, 0x91FA93324F5C4F67ULL, 
            0x632204A900D3B515ULL, 0x130F61533404DB4FULL, 0x51432777D0DAC550ULL, 0x6F52C7C5FD5DE820ULL, 
            0x9223A93B39BB61AEULL, 0xB61448D220BE260AULL, 0x6431AE9EE9BA418FULL, 0x3098A85554B0ECFEULL
        },
        {
            0xF1BC7338E285FF46ULL, 0x6BC315A76FB3212AULL, 0xBC2601EAF90AF174ULL, 0xB5954429EFCC5131ULL, 
            0xBCA0FD5D31C06478ULL, 0x9D19520CC558865BULL, 0xE864288437CB3DAEULL, 0xD404A90F234B24D4ULL, 
            0x047DC98DFAB9E93DULL, 0x2DA5CCEF75FD66C4ULL, 0x325627C00989A427ULL, 0xD8E4CFCE78A2DB8BULL, 
            0x441FE58713C79906ULL, 0xA8CA3C4341024DD6ULL, 0x1FDCA3AE9F921FD9ULL, 0xEBDCA7FB5E38D973ULL, 
            0xE1549F356EC8029FULL, 0x1022A1B53EEE763DULL, 0xDA57AAA4E1705774ULL, 0xAA579C2EA9163D1BULL, 
            0xBE9F25BA708910A2ULL, 0x3B105D5D2491BF7CULL, 0x2FD9FD58BD66B71FULL, 0x401D1AEFF91D3D08ULL, 
            0xE131935A4FD9991DULL, 0xA31BB46771868B05ULL, 0x9A80EC7921DD4865ULL, 0xE1FF9AAD714D57AAULL, 
            0xB872068B17971C3EULL, 0xD0BFE73D2E6762B2ULL, 0xA4981A7C12762EF0ULL, 0xD5882514D8E171A7ULL
        }
    },
    {
        {
            0x71F21A9BFEF6301BULL, 0x40373443F5FEF249ULL, 0xCF7C1E229115098AULL, 0xB158C6B8935470DDULL, 
            0xDB2F2DFD7578A9F5ULL, 0xEB5424DF6D0E2E07ULL, 0x3ACBC1382BB9F679ULL, 0xB4E957AC559B699FULL, 
            0xA7FFA9874F9021CFULL, 0x6750D2A8044B3FF1ULL, 0xEB73828EE50A3B6CULL, 0x9E89422F186E537EULL, 
            0xC46599FC47275194ULL, 0xF2CF8A8CEE0347EBULL, 0x8931D091EA2EC7FAULL, 0xCF5187020E03C228ULL, 
            0x55AAC1A607AB31B8ULL, 0x503A23E8B0206ADBULL, 0xDBA8DAB5F1641F44ULL, 0x86F72F112E047BBEULL, 
            0x9D445D830B7AA141ULL, 0x7A5ADD84AA39D16DULL, 0x5396F1CFCE147EEAULL, 0x351D67BCA704CAF7ULL, 
            0xCE967108EF98BA85ULL, 0x9F1EDAE17F406ADEULL, 0x460208251AD4CD3DULL, 0x6CB78931692FE7C1ULL, 
            0x7359271F4700D095ULL, 0x68138F8CD8734134ULL, 0xD59DBE3D6877C9B2ULL, 0xA8465051752DB681ULL
        },
        {
            0x5482BC1AB5B05366ULL, 0x6EC66598BA2098C3ULL, 0x3E62BF405538471DULL, 0xCAC257BFB0962AA2ULL, 
            0xE5177D83536C0530ULL, 0x426260AA50C5FA8FULL, 0x37E12C4516B82A40ULL, 0x93BB850C014EEDA2ULL, 
            0x480ECC68A85E4AC7ULL, 0x857C78027B610FADULL, 0x725FA4C76165F86AULL, 0x0DE33F16E9F80755ULL, 
            0x7091A29139891F04ULL, 0x042709570F34B95BULL, 0x988BCA14F0A6C4D5ULL, 0x88A57A86C6F54264ULL, 
            0x616FC89DA42D6813ULL, 0xE9DA158546C1C88EULL, 0x042FF038817D24A1ULL, 0xF4F0836F0A78C6D0ULL, 
            0xD5113801894155D4ULL, 0x4C93E0BBBB52B902ULL, 0xAFFC901678176B96ULL, 0xA9BFCB2C801F3185ULL, 
            0xE2B659140A8735D7ULL, 0xDE34A6007E7FA60FULL, 0x4CF721964264FC51ULL, 0xEA884E52B5EB7484ULL, 
            0x61B03F59467E772DULL, 0x16D70FB76A80159DULL, 0xBE6E0D7780ECBCB9ULL, 0x3B13C2DB3462B715ULL
        },
        {
            0xB8FBD12D23688DEDULL, 0xE894FFC49AEC3041ULL, 0x43C157AEEB7F1358ULL, 0x6F86A2BFDF66DEF9ULL, 
            0x8DBE5A12F4561CEEULL, 0xAE31E08E58B92E92ULL, 0x20592C723587C762ULL, 0x7F08F8F1A949CBCBULL, 
            0xA7A56457B6EB1EE9ULL, 0x668DE9BFF09535AEULL, 0x82837CD6EF02EF55ULL, 0x72641C98456E40B8ULL, 
            0x37E492C9B3C9FFFFULL, 0x78E5199051439A92ULL, 0x23068D3E579CB474ULL, 0x32060262D9570C1BULL, 
            0xA94943D471CEB984ULL, 0x1C82343127DD6576ULL, 0xBFBBD70C7151B431ULL, 0x144941A5EE110A93ULL, 
            0xCB19D98B2E4369ADULL, 0xF03772B6641E12DCULL, 0x519F9E0FBE73708BULL, 0xD14FE7661160673EULL, 
            0x997E2C923F6A2C88ULL, 0xDA6CB40B42264891ULL, 0x0D5D6C0CB5570F88ULL, 0x507276A9BA79EB51ULL, 
            0xD17D2CB0BCD34135ULL, 0x7B266A0A8C0AF94BULL, 0x373F7FA6B989355CULL, 0x5478006F48309232ULL
        },
        {
            0x74DFC5D1EC0F07C4ULL, 0x7EC5A82FB8A95DD4ULL, 0xB5332DB81076A878ULL, 0xDF9EA9DD3A8F32B2ULL, 
            0x7FBD6AA729D0E566ULL, 0xB920BEAC4A11A4ADULL, 0x9EF01F758E98EB56ULL, 0xEF768FF161CD832DULL, 
            0xBEEC056BD6490F8FULL, 0x6ABBBBE330EC0D50ULL, 0x32EEBCF0087B0ADAULL, 0x56DA1A7D2B3C6B39ULL, 
            0x89404301D3976637ULL, 0x3ABD85E04FBDB16EULL, 0x72335DBEF020DE7DULL, 0xAB9256F9E855C1DCULL, 
            0xD8FAF8C75EAE9142ULL, 0x0C57B4A445260A74ULL, 0x9519DA3D2AF0DAAFULL, 0xC93B7751D5D0CC57ULL, 
            0x1E99516BDDA3EDF7ULL, 0xF5864DC7D617FB5EULL, 0x38F5B8DDB3992AACULL, 0xCE1625861A741A26ULL, 
            0xA5142FD069827864ULL, 0xB013C854B8562535ULL, 0x2EDFEAE55B0353BDULL, 0x4763AF3B950C2BF6ULL, 
            0x3EFB1700CC739369ULL, 0x9BEEFB5037563ED6ULL, 0x83FCC45062F55C9CULL, 0x7EE2819B9606BBA2ULL
        },
        {
            0x31F784A80B6675D7ULL, 0xF1DCCA988134BB78ULL, 0x19D213F91F473635ULL, 0x33566A0581137881ULL, 
            0x470F2639395F82CEULL, 0x38A95803E1668E2EULL, 0x8262D80F46807A33ULL, 0xA757BBC4349E5588ULL, 
            0x2EEFD61057C2277DULL, 0x6A002DB703DB88B1ULL, 0x30E6A6B1CE6A3204ULL, 0xF4FEE67F72E1246EULL, 
            0x307C60C75F365E57ULL, 0x9AB7BDE0456C28DBULL, 0xD8A007694E350C98ULL, 0x92E61DC092B37C89ULL, 
            0x2F6E6B5FFDEB1CC7ULL, 0x7D2928196E5977F3ULL, 0x7491F45C1D2E2684ULL, 0xB0B70A269A24DD3BULL, 
            0x900BDB8492EBDCB5ULL, 0x3FBEC6B138A4B91DULL, 0x1DBC0680B0E33B12ULL, 0x4FA9BD94FA9DB3D2ULL, 
            0x5DA72543855B00EEULL, 0xA38EA7C2F9D8801AULL, 0x7990543520DCB897ULL, 0x7C050AD7BACEE72BULL, 
            0x659E7F1F5B6770DCULL, 0xED4DA7FE70955C3CULL, 0xF2320A9E79114052ULL, 0x9C1F83CC1CB80901ULL
        },
        {
            0x20397CA67DFB72B4ULL, 0xB83FC661E8962E4BULL, 0xB070A84074689C95ULL, 0xC17DC04558372283ULL, 
            0xA44E2353B789102EULL, 0x5A1274089E6002D3ULL, 0x9448BA0275222BF7ULL, 0x8FA7D9A5C067E6B0ULL, 
            0xC2FC58B55AE3F088ULL, 0xC6F4AB093A9D7CA5ULL, 0xF86A0CF7620539AFULL, 0x99CBE4B5480155CFULL, 
            0x3A9BA13D8732C7A4ULL, 0x67D8EEDA8EB43CB3ULL, 0x537E9CC6EB534EC4ULL, 0x2750D417E91BB3C9ULL, 
            0xA4DD306639FF4E96ULL, 0xC03EC2681177724CULL, 0x1B9144C8079C3064ULL, 0x1208EF08623CEBFDULL, 
            0x250D07A4B3FAE57DULL, 0xCE1A2FDAEA856C23ULL, 0xAA3BB0F073D475C2ULL, 0x5D72B0CBC00BD758ULL, 
            0x8BE19DEDCACF557FULL, 0xD57C153B936FDFE1ULL, 0x3266F232F2B197B9ULL, 0x76322807F01EDB3FULL, 
            0xE2764B30A47EDD03ULL, 0xA5072C66367A2D88ULL, 0x5601B7CF143041E2ULL, 0xFDF0F094D43A2FBAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseEConstants = {
    0x5C6B0886B834CE8DULL,
    0x9B7771A45201C23BULL,
    0xCA057F8F379AB564ULL,
    0x5C6B0886B834CE8DULL,
    0x9B7771A45201C23BULL,
    0xCA057F8F379AB564ULL,
    0x71C04F863CC89F9BULL,
    0xC9849DA2D9971D31ULL,
    0x9E,
    0x38,
    0x6D,
    0x62,
    0x47,
    0x8C,
    0x27,
    0x37
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseFSalts = {
    {
        {
            0xFC4FA16654CB674EULL, 0x762459C1EAC6B8DCULL, 0x14D1408BDD2FC91BULL, 0x7FBC1769CB051860ULL, 
            0xE2826E41574684A0ULL, 0xE71F875675FCAC87ULL, 0x0B7337845FFFEFA6ULL, 0x20BC30E951F47E58ULL, 
            0xBFEBEAFDD561C951ULL, 0x2CE7099A117F101DULL, 0xF9E5908295BEBF1CULL, 0x146F7C1EBD74F4B3ULL, 
            0x103C0FBFD81BF649ULL, 0x5D51355BD4B84F54ULL, 0x56DAF2137F13F4CCULL, 0x2061E45D45DBE589ULL, 
            0x8E8328701E45EC37ULL, 0x859521DE83A6C6F2ULL, 0x0BDFC860654908F9ULL, 0xA59CFFA0C6438B23ULL, 
            0x7E0DEBE9EFF6C85DULL, 0x5AEC2EDB71E50295ULL, 0xD1F00DDC824A2D8DULL, 0xED9852544E1A7E93ULL, 
            0x8BCFAAAC673B6D20ULL, 0xD80E1F32DAA9C817ULL, 0x3743390E804D3940ULL, 0x333C47F03708D831ULL, 
            0xB36FD1641BEEA687ULL, 0xE8955548F82400E8ULL, 0x192FA92B0A17C4A2ULL, 0xFBAB4B45CAA6F2ACULL
        },
        {
            0x70CCB7414FFFB4B0ULL, 0xB397B2105D9F1678ULL, 0xD9BC56C4060C1C03ULL, 0xE603576D5A56FCE0ULL, 
            0xC36980423A88B1B8ULL, 0x718619DAE2A0FDCCULL, 0xD2362EDB625E8BCEULL, 0x17943A54B4A7AAF7ULL, 
            0x9B8FA08927CCE117ULL, 0x2955D8CF8C15255AULL, 0x35635A31F2D9333DULL, 0x30CDCE11F7D91438ULL, 
            0xA8C5DFC38D590171ULL, 0x0BA37C8F3E313B47ULL, 0x13F319D0F586FD83ULL, 0x27B8E622C4970ACDULL, 
            0xAAB3E6A0D15C99FCULL, 0x70C0234CC8E1319CULL, 0x03F88C49AAC0AD04ULL, 0x7F404B488F07B29DULL, 
            0x2BDD1743FAFD24F2ULL, 0x5245D378FF8AECB7ULL, 0x8DC180B9E1D53003ULL, 0xD16866C27B0E1D6DULL, 
            0x89996EB53C6F9FD0ULL, 0x5F222D32855A7DE6ULL, 0x9EFAEFCAF36BCE15ULL, 0xE36377D8C9AE48F3ULL, 
            0x6B8003A87ACE4A41ULL, 0x2C3ADBABAAFEC9A3ULL, 0xA13833279DB873D1ULL, 0x87855721C9556CD5ULL
        },
        {
            0xA3AFA9AC5E11F50CULL, 0xB7FF7C7C25B2AAC9ULL, 0x444C0BAFD6B263B1ULL, 0xD4701D28F937F156ULL, 
            0x2A9B72B24D925614ULL, 0xA11BCED7A63C91F0ULL, 0x00AA397DB3FB81DAULL, 0xDD53BF8F64C51B99ULL, 
            0xB827F7047807866AULL, 0x4BBC6B78E99C0402ULL, 0xB12CCCDB8B0A6E4CULL, 0xBAA04FB6AC861F41ULL, 
            0xCA8D0D36D8C2DDA1ULL, 0xA669EECB33ED8811ULL, 0xCC9732E3521AAD66ULL, 0x193E33F81B687479ULL, 
            0xC40404138EEEDAECULL, 0xEAF4317CADEF495DULL, 0xA00A997909DAAA0BULL, 0xDEC68C8C4A6BF004ULL, 
            0xEA047AF917A9D4ACULL, 0x525ED3A8BED8BB15ULL, 0xD3B467B445C7CC2EULL, 0x0E31179D838400DBULL, 
            0x85797F93D270CC93ULL, 0x33D4E42D6D38DE92ULL, 0xCF489A6D5E2CD2ADULL, 0x234B4410EE206F4DULL, 
            0x8AD1775F85EC3175ULL, 0xE55CD49C506EA752ULL, 0x7259DBA93C3CEB46ULL, 0xA52844B559BF11D0ULL
        },
        {
            0x894537BCC5EB4E28ULL, 0xC24209A11213BA65ULL, 0x295FD7436375B7FEULL, 0xF9A4505EF7E03616ULL, 
            0x5D05D2BF1654D043ULL, 0x885C734B4E257431ULL, 0xC4CD7FD503826D0FULL, 0x9DEAA7457B5CF93CULL, 
            0x02B6B2B9FB3676A9ULL, 0x0A9D512DEB00F5E2ULL, 0xBF8A927914BE6367ULL, 0xC7891E69979DD528ULL, 
            0xB025A0160D95FEDFULL, 0x87831FDB22622BE1ULL, 0x254B9ED97E06CC9CULL, 0xD7CD046D2B5DE73BULL, 
            0xA071A00D5205EC52ULL, 0xD64D512A26500064ULL, 0x63B530538307DD3EULL, 0xDB04BD772A55120EULL, 
            0x6EF1184115FBF280ULL, 0x50E562090FEC9682ULL, 0xF6F05EF9DA2762B7ULL, 0x67EC9FB42A4021F6ULL, 
            0xB1F70BBB067CA109ULL, 0xAA6CA78AE04CEB6EULL, 0x5C0C50DF44243751ULL, 0x4CF9DF3912B489EFULL, 
            0xE9909642BFD21D05ULL, 0x0C39EF5C4CCA39FAULL, 0xE79D052276D5F0AEULL, 0xF6CCEACD0878C234ULL
        },
        {
            0xD2DA7FC6CDE35101ULL, 0xEA23CEF3C6394339ULL, 0x85C292687C561249ULL, 0x93C57EF0B00AA748ULL, 
            0x1765884C9FB93F9FULL, 0x3F48F90B7DACF9E7ULL, 0x5C56472C22E6F8F1ULL, 0xC5B2EEFEC434BDF2ULL, 
            0x1494DE4F953855ABULL, 0xE39E563C62DAD01AULL, 0x52926B45E09FC12AULL, 0x869870223B223AC9ULL, 
            0x201A573CFBD791F4ULL, 0x3CCA8607858EEA1CULL, 0x80D5069E2E4DE8CBULL, 0x673B5A4BA915A11DULL, 
            0x01C9C4CC2DED69F8ULL, 0x8CCCD2D86D5DB4E6ULL, 0xD2A5BE20325A840FULL, 0x6088C5088501B242ULL, 
            0xC3799E174B356D38ULL, 0x7D6C396F07754E0FULL, 0xC2477A1E55AB51F2ULL, 0x32C3FD71D55EE2D8ULL, 
            0xF31B8CF221DA1328ULL, 0x41A8A245A4B926B8ULL, 0xFAD487406E425245ULL, 0xA2A35D98C9A0F578ULL, 
            0xB3517DD9243C084AULL, 0xA9CA847426DC9C9AULL, 0x44FEB3631B0AE4C4ULL, 0xCCDFF4560721B3CDULL
        },
        {
            0x2656B15ACD571101ULL, 0x3DC1B265F8D70603ULL, 0x9E6BA5F457BBC97CULL, 0x9B23D70F0B246E8BULL, 
            0x1714A0ABAD26BAC9ULL, 0x59F1296C5C9112DAULL, 0xB3A547ED3A07D0ABULL, 0xAA7C0E0B9C9181CCULL, 
            0x5D1B7AED485DA721ULL, 0x642B53E48C51A6FAULL, 0x358CFFA4ED9C1B47ULL, 0x19EB693EB129B58AULL, 
            0x5D2F71A3B0EDCDBFULL, 0xB4DFA8FEEC208867ULL, 0x4F7E44E2F3CC9F63ULL, 0x9EE0E66DBD92403FULL, 
            0xCF0CB2B8AB6A65B4ULL, 0xAC5BD3CC818DE8C7ULL, 0x074DADCA932B4369ULL, 0x968BC6D590D60BDFULL, 
            0x7C9A10C38D4E285EULL, 0x2D14A9E8C07B25D7ULL, 0x4EDA8FE84F9483B9ULL, 0xF49AF5AF4856E8D2ULL, 
            0x4F1ED25D407DCD70ULL, 0x27F4B4A5BE35205FULL, 0x91D6849D007B50C4ULL, 0x60C4B74DE2325E1EULL, 
            0x2811D5EC90058B70ULL, 0x9BD1EA72E211C3DAULL, 0xE0894C7EEFB3AAB6ULL, 0x5403B65862A34CE0ULL
        }
    },
    {
        {
            0xF4AD01E2E196A253ULL, 0x4DCD727E52694388ULL, 0x5E605C6DCDA9D01EULL, 0x1A9013B39FAEAC2BULL, 
            0xD18312E8913C4C88ULL, 0xDA152452D3527BFCULL, 0x88C0C303107A106AULL, 0xF7B018C552EC44DDULL, 
            0x4F9C9E425F7946DAULL, 0x1F22D49836AD0E1BULL, 0x606F728DE6F3F5C1ULL, 0xAEECB205BF47DE45ULL, 
            0x54A3D63B3D1D1A98ULL, 0xD5E345033845A178ULL, 0x0F00960106B86E08ULL, 0x97600C157221BBB5ULL, 
            0xBCD14B05E5EE959CULL, 0x78437C5EAEA9ABFCULL, 0x6E299CB0365F197BULL, 0x24A21375C3F78477ULL, 
            0x42E2437DFB7E1D8EULL, 0x651DBCE40B9C5A2CULL, 0x441EAB025D533922ULL, 0xCB416904B21579C9ULL, 
            0xC922DEFBCBF09662ULL, 0x6DB6C2F019A3DBF9ULL, 0x75013D16B70E42B7ULL, 0xEC3526B9DCED7D81ULL, 
            0xB1A2CCD893837108ULL, 0x5E27BDE17BEAB43CULL, 0x509B28D1A219CEFDULL, 0x5CDC0ACAB147D0BCULL
        },
        {
            0x870D388D8A137E98ULL, 0x7C163ED4911A240FULL, 0x06DA662E9B2898E5ULL, 0x2C200CF0963A0228ULL, 
            0x65F1D3513C3F1055ULL, 0xB200BE4785236C16ULL, 0x17FD3D1319286E86ULL, 0x27BA9A96B90DD238ULL, 
            0xBEBC7CE6F388267BULL, 0x7254C600DFD07857ULL, 0x8127193D48222025ULL, 0xA28C1BD45C614A71ULL, 
            0x6CBCC0214FD842D9ULL, 0xA06B89263C9A0ACDULL, 0x7368FD00AB129E90ULL, 0x6ED3BD13BE2DDEDFULL, 
            0xE82527DDA9ED2C19ULL, 0x3A73AF8325093043ULL, 0x90D32F63718957A1ULL, 0xCFC3D756B3B49B21ULL, 
            0xEC8BA7C2FB1312A9ULL, 0xE62FEA5D8ADCC8BBULL, 0x336A435383DF6D72ULL, 0x4A4A6DD9C0E07FB9ULL, 
            0x6BA8FDD1E872F471ULL, 0x079E4C7C47547731ULL, 0x3917FD28C02164D5ULL, 0x20E8BC3D39092C2FULL, 
            0x14A3AC501C911A67ULL, 0x99911819FF90D0F3ULL, 0x6C18174F3EC9DB30ULL, 0xBFE7F10B59609147ULL
        },
        {
            0xAA70BB0E557110A0ULL, 0xE4A94E7DD61A780CULL, 0x5739B4BECBDE7F2DULL, 0xDE4ACB713FACC98EULL, 
            0x74A17398AF26F597ULL, 0xCEA65CE5499D29E9ULL, 0xE20D6146835B1C3DULL, 0x418C64E81769F3F8ULL, 
            0x4C9204E42F5D3430ULL, 0x8625EA3E8E3CB33FULL, 0xE347524E22679A0DULL, 0xD2362DDE01752706ULL, 
            0x151364E99BED1837ULL, 0x8636F42972B70012ULL, 0xD8B1661C2BE14484ULL, 0x1371FE4CCBCD159DULL, 
            0xD00BE48009A5A352ULL, 0x2FB7BDBE0BF16EBBULL, 0x59758346C196039DULL, 0x55B87014865FC3B7ULL, 
            0xC75A64EF682C9B9DULL, 0x3B9EDEFE593A0EDDULL, 0x6BD8521389E4CEECULL, 0x70E777DE033B0444ULL, 
            0x15A2B98C2CDC92FAULL, 0x84BC674F2B4CEA4BULL, 0xDF38A2786914FE55ULL, 0x8F9406FE1BCD0C28ULL, 
            0xDBD565F97E723059ULL, 0xE56F7ABF2D08FE61ULL, 0x3A77D29BBA81C52EULL, 0xCCC3D4B68A7C68F3ULL
        },
        {
            0x3EFD342323DB6496ULL, 0xC754F05FDF09A78CULL, 0x2CCCE30F329EF82BULL, 0xF5A467E0B56F02E2ULL, 
            0x0400ECCE97464C44ULL, 0x10EA8270EDBF32BBULL, 0x0ADF55CBEE2FEEFEULL, 0xF2116B047700B54AULL, 
            0xA43927F22CC9F675ULL, 0xF280D9B35BC1418EULL, 0xDD07B8892F2A5CB3ULL, 0x61B91F62E9940A28ULL, 
            0x52DF473173D9B190ULL, 0x58CCA5A662009405ULL, 0xDBD01A6F220BA306ULL, 0xDB4EB02D618825A2ULL, 
            0xB832D6E1F5D70DC8ULL, 0x2C8E71641EAD8CEEULL, 0x7F102440B1A7AA9DULL, 0x2FD23FD76B65EB63ULL, 
            0xBE09E95FC7174F9DULL, 0x64A1C7AE1016C144ULL, 0xFD30B432955D6147ULL, 0xC0E1353FBFB1677DULL, 
            0xE8D2F575EE375B58ULL, 0x6C7BE55BC7FBA07CULL, 0x8C1D46CC49D39B93ULL, 0xDD0D4F5BEB423C67ULL, 
            0xBD6873EC9DFEE543ULL, 0x73BF2B896D73B606ULL, 0xBCBBF1ADB14509B3ULL, 0x9E3CBD26CF539F9EULL
        },
        {
            0x2154AB82489A07F1ULL, 0xB34F08B46C2009F9ULL, 0xCA2E30B9CAA80FCBULL, 0x41DA9EFAEB073D8AULL, 
            0xFD72388547CD7EA7ULL, 0x0FA3557688173FB8ULL, 0x481FB0FB1A299E98ULL, 0x98AC6213D128693AULL, 
            0xF592C47CD2798410ULL, 0xA70EF7DF7100A745ULL, 0xAE63DC66CABAFA8DULL, 0xB837F1BB3B5CC70FULL, 
            0xC3D9189D756BFF20ULL, 0xBAF4F9AB0C8B8FB6ULL, 0x0999660CEE94EE88ULL, 0x87DD8C666E135F8FULL, 
            0x87451E839F72D226ULL, 0x3C1B567902ADA482ULL, 0xCF9811EDD006C96EULL, 0x136CEA0067A3F7C9ULL, 
            0xD1C6FF015BEF1AF8ULL, 0xCBC9EC29410BDFA8ULL, 0x68E2DAA8E01918DAULL, 0xF3FAA6BA9524A442ULL, 
            0xA22B2FB05CF704C5ULL, 0x53673961D9911AB8ULL, 0x600541BB92E42A5AULL, 0xE7C6DBB5F249E02FULL, 
            0x3DA7D7296731DE23ULL, 0x31DD09AC5567D2AFULL, 0x3C5CB1853292BD9BULL, 0x36634B31A0D379B7ULL
        },
        {
            0xBE366E81939F6EC2ULL, 0x7F9EC9C7470D8F61ULL, 0xEF9C1AD419E3B528ULL, 0x831BBC26A3CDFC25ULL, 
            0x759C67F6FD713B40ULL, 0x1A9C768C55BFD998ULL, 0x3DA15EEC77B8F29AULL, 0x8BA5DADD7EB4FC45ULL, 
            0x87D576CE0E3D5A82ULL, 0x286AFE015AC64E41ULL, 0x5D600F8FBDC93C72ULL, 0xBF293713CD9E1EC3ULL, 
            0xE85C4D8B4FD40481ULL, 0x6CD01FA84B5FD728ULL, 0xDFFA2F9A8C01423FULL, 0x6971D35E0D054082ULL, 
            0x5950F402E9557D96ULL, 0xD3650294D792B163ULL, 0xC6DE30183DF45246ULL, 0x2EE0AC8C6B88232DULL, 
            0x6996717CBB16EA65ULL, 0x798EB079F2398F0CULL, 0x0D9CC833F13D1C8CULL, 0xBCD104284BF52418ULL, 
            0x89AB9C05E18AE31EULL, 0x2137BFE155970774ULL, 0x33BAF873871FBEB9ULL, 0x1272FF043B09A40CULL, 
            0x9E7C8420F494B490ULL, 0x0916D07903F4D26EULL, 0x4B8C66FEA8EBB810ULL, 0xEC74E6C58F080EDBULL
        }
    },
    {
        {
            0xA59596823985AD73ULL, 0x976BEDDB739E6208ULL, 0x4FBCE8804C6B6BC8ULL, 0x64DD6CD63C3B4380ULL, 
            0x5A568FAA566A6A93ULL, 0x9657F94979A6EBD0ULL, 0x4338EC1E692E79EAULL, 0xAA774D891BEB9382ULL, 
            0x321568AE572FEDC3ULL, 0x2C6B23B8F3A61F8AULL, 0x08D1EE996F0749F2ULL, 0xCDF820EB4D040814ULL, 
            0x0EA471033FA9CA2FULL, 0x604EEE5523DAD423ULL, 0x025F5084FDF82423ULL, 0x320EBAF2EFCC4E8AULL, 
            0xC23FACD89368FD89ULL, 0xC05C77E750764C7CULL, 0x69D35BD5BD1A745BULL, 0x3585DE3933D6D424ULL, 
            0xB22B06B8D68B331AULL, 0x8A7E3EC1C07BC4BAULL, 0xBF23E6911319941EULL, 0xA25E6AABEF7D6EF2ULL, 
            0xB9818C4D6A48AAF7ULL, 0xA3F4DDAE49E3FB7AULL, 0xD0188BCE1F4B7612ULL, 0xCDDAF727AA09C07FULL, 
            0xB4494BAF4AA3112AULL, 0x2180CDAA40B268A5ULL, 0xC0629147D260F772ULL, 0x98A323CC7BFCFA44ULL
        },
        {
            0xBC66DB87F6A1CDD7ULL, 0xD7D386C44DC71506ULL, 0xBE19DBDEE6749EF2ULL, 0x0E6920C503BB04B0ULL, 
            0x98DA2F71464D83B6ULL, 0x3C275F5BEF2A8E51ULL, 0xA955C9BBA38E64C7ULL, 0x99CBCA7F0AE24297ULL, 
            0xF378FA2E4E6A1C8DULL, 0xFF3AB569326E6A1CULL, 0xEA8BBE6D519B2813ULL, 0x5874CB6DB4F1E5FEULL, 
            0x87FCC392FF75EAFFULL, 0x60DA3AC04283F039ULL, 0x5C7C4FE7A7E522F5ULL, 0x6A900429BE93AA3CULL, 
            0xC50E81649195A5F8ULL, 0x99350A14926FECB1ULL, 0x749BD36317F7EB54ULL, 0xC6810C5A45148262ULL, 
            0x9093FC18AD9095FFULL, 0x82D7EECD2623CA0FULL, 0xC17AA41FB607B58BULL, 0x07525ADF41F2EEC1ULL, 
            0x59059F2B2E5EDD21ULL, 0xA66055923A7222BDULL, 0x50176CC0653B5060ULL, 0x931185AE237709FDULL, 
            0x8E453676E32D7347ULL, 0xBEBA0228F06966B4ULL, 0xE521D2BD117DE665ULL, 0x7F474234FF6D2A4DULL
        },
        {
            0xF235CC0E2CA95868ULL, 0x6C00FB9645980000ULL, 0xFACA93768E82DB5CULL, 0xBE3713A639637123ULL, 
            0xC2545D7CF9DA2706ULL, 0x35D7D7C96BD45601ULL, 0xCF6E0F6DFC71B2D3ULL, 0x54D57C46568244C7ULL, 
            0x50D922C6090943D9ULL, 0x4986A13197551BE9ULL, 0x8584986F5B7CCE09ULL, 0x49D9886A1145911CULL, 
            0x92C45944D7E7C634ULL, 0x15BB606C4D83CF92ULL, 0x9187F8370EA3FDEDULL, 0x30E83960EBD1FBA4ULL, 
            0xE763D197F7667FADULL, 0x5B64F478527CBB48ULL, 0xE4BCE877228EFC05ULL, 0xF5CADC80829A3D93ULL, 
            0x8C80DFCCABD55A94ULL, 0xFACD3966AF92D1B9ULL, 0x9AF8F9012FF6BE29ULL, 0x7F9B378AC003849FULL, 
            0x435D11BD1C4D268BULL, 0xE7EAFBDD2D46E106ULL, 0x1F30F4FD480FA797ULL, 0x280FF6538C4A8B23ULL, 
            0x85C01CA4B60A9678ULL, 0xF8E3D3C82BA84824ULL, 0x6189A0FA68EC96BEULL, 0x947F9DFCC88D95E2ULL
        },
        {
            0xAE163BF9DA046AD4ULL, 0x80B472B6DA2A4187ULL, 0xE9FF6FF91B495CF1ULL, 0x306863A06210B536ULL, 
            0xB5C0F947D5A48B10ULL, 0x9055473C33538D8EULL, 0x562F64C1BF4DD6C2ULL, 0x1828F3B2E76DF008ULL, 
            0x31D432C9D798A761ULL, 0xD80A1FE2ECF500B2ULL, 0x3028AA7A3DEA9C82ULL, 0x19E5BE4467E60B3AULL, 
            0x25E942288B136490ULL, 0x96614056F5FE4E28ULL, 0x97B0DF42A4B73DA6ULL, 0x50B786BF82547CF4ULL, 
            0xEAF56AAF748DD668ULL, 0xFD66681C30783840ULL, 0x508DC05E5D23F4EBULL, 0x462D7D9B393CB1B6ULL, 
            0x2D79F95D462852BEULL, 0x0E454041C25A30EEULL, 0xE187F93D9FAF6DEEULL, 0x36C31E8432938263ULL, 
            0x31252CA718E37F01ULL, 0x8FCAAF7F0EC79639ULL, 0xC87235FB480F3B00ULL, 0xA1AF0C0AC579EDCDULL, 
            0xEFA2EC46C3174C41ULL, 0x2AA949BD7E73B648ULL, 0xB06CDD9D98E1D8C9ULL, 0x0B77B3ADD2939CE4ULL
        },
        {
            0xE86341BC11DF84A7ULL, 0x7102E8872ADFCC69ULL, 0x37F41EA5AF04B39DULL, 0x6EE1C403856D85E7ULL, 
            0x295690C3814077F1ULL, 0x1A35CB4B1B7C1054ULL, 0x0B335C1A93BFD0C8ULL, 0x944B7C6D0375CA8AULL, 
            0xACD6BCE2D4AF680EULL, 0xEAB6758418EEAD77ULL, 0x7D06EF163FDF7376ULL, 0x7F9BBBBBDA234633ULL, 
            0xED04478F10756759ULL, 0x2D8BC08F7CA773E4ULL, 0xAF1DDFA87E6E740AULL, 0xC48A56EBA3529D4AULL, 
            0xAF160ACBA32A5385ULL, 0xBA25EEC1DED91E98ULL, 0x2917E4F23552F417ULL, 0xF82C5FA5A772500CULL, 
            0x20DF341F8095B704ULL, 0xC4FFCCD6F9C554C0ULL, 0xF63CA1C13114C31CULL, 0x79C357031C2717DCULL, 
            0x614516C99617E05AULL, 0x884B00CD787A0539ULL, 0x3D5C503A82A7F5F8ULL, 0x564F0A7CDAFCADBEULL, 
            0xC577C21084F8CE12ULL, 0xAE89B3D99FC87F42ULL, 0x21AF92D977694CB0ULL, 0x6BE9278777D714E5ULL
        },
        {
            0x40EB897997180CBDULL, 0xBB25FF8DA31EF4E7ULL, 0x5094E25DB4CBB4B3ULL, 0xB105FA116F65BC2AULL, 
            0x828728BB7E573DAEULL, 0x3334B980447125EEULL, 0x7602CAADF72D1CD4ULL, 0xD7F3AD59CF10E068ULL, 
            0xA10E0C2EB3437E72ULL, 0x57D063E43EA139B9ULL, 0xC24375F05C000785ULL, 0xF03DD76B3C325937ULL, 
            0x94FF3BDC1D4DE785ULL, 0x549228B707249970ULL, 0x79AD7469F4F9A42BULL, 0xF1A6EF53C26F0E18ULL, 
            0x5F01899D8E2B5706ULL, 0x94CE26D22D583D10ULL, 0x8FDE297524E61B09ULL, 0x55E105166A2FBA26ULL, 
            0xEF1E42C2C579E5A6ULL, 0xF032E37A3D9E9E43ULL, 0x31AADD94B10E7F5DULL, 0x235783F74934C694ULL, 
            0xB8AACC54427B5093ULL, 0x49CEE0593143379EULL, 0xC22028938DAF1B0AULL, 0x9312924A47B80E69ULL, 
            0xFB8A8834F9D00250ULL, 0x9BF5CFF56206F7D3ULL, 0x66F2ADD0FC1C0C24ULL, 0x9AD8D449AD147D67ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseFConstants = {
    0xBA687223F9C1B4B4ULL,
    0xF5C3CDB5878CFCD6ULL,
    0x3E58CA6DA2A9D2EEULL,
    0xBA687223F9C1B4B4ULL,
    0xF5C3CDB5878CFCD6ULL,
    0x3E58CA6DA2A9D2EEULL,
    0xD881FA73037F49ABULL,
    0xE854B2B378858ABAULL,
    0x43,
    0x8E,
    0x80,
    0x8B,
    0x64,
    0x3F,
    0x98,
    0x4E
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseGSalts = {
    {
        {
            0x39171E4A94D90E7AULL, 0xF77A36ED222F4C16ULL, 0x4027AE0FBDF0D0F1ULL, 0x8786E78F5F9ED4A7ULL, 
            0xEAECBB749DD237E7ULL, 0x60CD0BEDFBE77B51ULL, 0x77C229114C163762ULL, 0x85A4776A707BEA6BULL, 
            0x866BB56699BE5D26ULL, 0xE50448703F4828F3ULL, 0xC1983BE6315A8F52ULL, 0x71AF4ED2C204C066ULL, 
            0xAA0BD9E383CF00DDULL, 0x4C12029CD433A246ULL, 0xFB24DB2850FA3C2CULL, 0x8EB16D899932FF6BULL, 
            0xF86541C10C1232F6ULL, 0xC36D6C94BAE38929ULL, 0x5BAA840E75CB717DULL, 0x17E60529454E77E4ULL, 
            0x79CD3BA3F5B395CCULL, 0xB2E9944D857EB5B2ULL, 0x8BB999BBA9389F22ULL, 0x25BA314C82B4E901ULL, 
            0x688C6474FD342521ULL, 0x2E364403C2A591EAULL, 0x51D1D8538313BF9AULL, 0xD0BC1317A01CF642ULL, 
            0x924D1264B065EC74ULL, 0x6BE8C6A86CCB146AULL, 0x82D6F220DA94E146ULL, 0x417ED148D0BE1BF3ULL
        },
        {
            0xBCB98A0061860B75ULL, 0x4FA80AD77A5A243AULL, 0x1D4B334C3337FE9AULL, 0x82F5FF582306B27DULL, 
            0x889C61978CD734D8ULL, 0xA78D377DC324743AULL, 0xBE875CE271F4DB76ULL, 0x8CCAD61C5D8EBB8DULL, 
            0x21D281FA426A5051ULL, 0xDCD71700DF399061ULL, 0x9581AB63DE366F63ULL, 0x21F45562C984432AULL, 
            0xE62E93C9850F2032ULL, 0xCB085914380030F3ULL, 0x35FC5475A56E09CAULL, 0x811A6D7B80F166FCULL, 
            0x1C62593A171E2167ULL, 0x8D73CFCF05F3A56DULL, 0x6C7A9E4A7DDF468BULL, 0xFCB5846BD23D1837ULL, 
            0x293A422CC3412636ULL, 0x6B2013BA3C639F8EULL, 0x052B6BE11B02DB01ULL, 0xB092B5C1E16CC5EAULL, 
            0x2A48F9E6E7920A3AULL, 0xACA61FC8058F4F96ULL, 0x814D59A7BBCB51DCULL, 0xEE23E36AE6489A26ULL, 
            0x9E9DA97AD5EAF0FEULL, 0xC8880A2014C4E14EULL, 0xE7ED731DEC557AACULL, 0xFA2F82B21BE81873ULL
        },
        {
            0xB9ADE265CF189122ULL, 0x4350EA10BFC3D27EULL, 0x84D6C0D4FAFE8C66ULL, 0xFC0BF0B32748EDC4ULL, 
            0xEA9DA4932A4DB576ULL, 0x0CC9FBB0A3C15E30ULL, 0x4E608308F767251FULL, 0xA0C13E4A5456FE01ULL, 
            0xE8847E28AFDC0E7EULL, 0x4B8E439A19A6F483ULL, 0x4E2C272DBFDF9A9AULL, 0x800BEC84577F70B0ULL, 
            0x660F0F861E96882DULL, 0x63449C3501727A82ULL, 0xCBCF40A9E2BDACCBULL, 0x09ACC40A4852BA50ULL, 
            0xBBC6B404F53CAA1EULL, 0x069F3EFBFCE725A0ULL, 0x8E39820F6FC75C3EULL, 0x1C21C843BB24B4D5ULL, 
            0xC5CB5642B6828BCAULL, 0x7D1627AF8034510DULL, 0xB02E1FA376FA8C10ULL, 0x7B5C072BF0BEFEA2ULL, 
            0x1CE479711168CB8AULL, 0x8086904B3F03D1F2ULL, 0x06B04439D87C2393ULL, 0xE7F9F48FE6BFC3C5ULL, 
            0x514DC89EEBB7524CULL, 0x5C50B5418AEE5157ULL, 0xE4E8FFB6CE7B3499ULL, 0x06C5168260C35C9DULL
        },
        {
            0x5EAE1A97A8C314D0ULL, 0xF508E4530AC94CC2ULL, 0x98F12DADA6FCB751ULL, 0xE0F0AE403D7919B7ULL, 
            0x157D58C2736B553CULL, 0x37F8FA807360F6C4ULL, 0x430E6A41363C32CDULL, 0x40A548941490903EULL, 
            0xB29B57AB887296FAULL, 0xC473CAD84483540BULL, 0x2C744555FF46A0FDULL, 0x128FF15BA20C9788ULL, 
            0xDC34DBDD8E94402DULL, 0x180C684629FED99AULL, 0xB9720F7E6E2A4C6FULL, 0x5D836889EEC7C45CULL, 
            0x1F3BD6D0D5A835A4ULL, 0x050499C957E55213ULL, 0x94EF6BBAACB98687ULL, 0x320404C8E19AB604ULL, 
            0x72C169A4DA049E03ULL, 0x3F2F3008F0A0F926ULL, 0xBDCDBC4C4BE81A26ULL, 0x87351B0BB638C098ULL, 
            0xA80F5524D3CDB7C9ULL, 0x5E466E8804F6BE15ULL, 0xD3774AC9D1F304D2ULL, 0x26AC76977998C017ULL, 
            0xC4FF4D1FB5DF1134ULL, 0xCBB3276A4CCB7259ULL, 0x38D266403736827EULL, 0x632546B2D0CA2DC6ULL
        },
        {
            0x533D2B4CC8276341ULL, 0x8817CEDEE2891A6FULL, 0x0A3069357B1854D0ULL, 0xB621BD595F793B39ULL, 
            0x0F3DC71F1F411CB7ULL, 0xD23D7DF927FE51D7ULL, 0x4231CC1413F4AFACULL, 0x5354177F51A6AF59ULL, 
            0x135791AFC70656A5ULL, 0x23C4EE74F287DC7DULL, 0x1E6F428635E5919EULL, 0x426BE2953C808601ULL, 
            0x382F769F22B980BDULL, 0x9E89C9962AF2D03BULL, 0x1A013E4D0F4F8F20ULL, 0x6451A3CAF558731EULL, 
            0xE8741EED8A5A13B9ULL, 0xC4E6E315C76DC4A1ULL, 0xBC7ABCB7F2E5274AULL, 0xE73811BB9C8A7996ULL, 
            0x7D0C05236AA776BBULL, 0x62A13A0326618CF2ULL, 0x92D60184421C941DULL, 0x1FDE3E6FF3028DBFULL, 
            0x628F55193AC4A741ULL, 0x40CE2FE8184B774FULL, 0xE1946A329EFF8E9CULL, 0x93962C786025112FULL, 
            0x434B9FF2FA5DBC11ULL, 0xBA4C156AD601B644ULL, 0xEE19F594ED9D1539ULL, 0xCFD7509C1614B677ULL
        },
        {
            0xEDCA678D79A9DF0FULL, 0x772453D92954F282ULL, 0x9796A413F2517FE6ULL, 0x3F6A664B5B28DFF9ULL, 
            0xC5FECF7BB81AE798ULL, 0xC41BFF861EFBD907ULL, 0x92BE9B9FF28F0BE5ULL, 0x235520A6D2CFCA4FULL, 
            0xD6AF9A8FF35D45BCULL, 0x4B9650EA8F70C86AULL, 0x5926768FF93EBFECULL, 0x3B9B672E40EFCBD0ULL, 
            0xBEA301B3C6E7324CULL, 0xFA2BA67ECBFC1A70ULL, 0xE8B0F7996EE4B0E1ULL, 0x4452BD325446F229ULL, 
            0x21C4D5B0CA12F24EULL, 0xE6B08B90E8989FDEULL, 0xFC1A79C64EF9888DULL, 0x715BB1473AE52549ULL, 
            0x332EE5AD3C2405DBULL, 0x3BE8D7A121514F7AULL, 0xFC47B06B9336813CULL, 0xA07AD75B40EF5896ULL, 
            0x3C81C1FB647B84A9ULL, 0x480DA6C06ACD83B3ULL, 0xF736CB6134FAC993ULL, 0x247376183F401032ULL, 
            0x02630935A31205AEULL, 0x55535F90E6D63779ULL, 0xDB1CC6FBB9B3A86AULL, 0x1CE70F6B37681A60ULL
        }
    },
    {
        {
            0xA6CEFA94FCDD83D2ULL, 0x5E70F4A3FE1D77A3ULL, 0x441DD06B81C847D3ULL, 0x8FE9B42850D77AA1ULL, 
            0xD386DE677CD78409ULL, 0x0473A4A62D9A03BDULL, 0x3D8D378373EA9E78ULL, 0xA5D1CE83C0255DB3ULL, 
            0x5AA8E32C33B235F7ULL, 0xC328811FDA7D2C25ULL, 0xBE9B226707FC60C9ULL, 0x9711413A43C4F697ULL, 
            0x4C48432D441CA0ADULL, 0xFA1BC88641263B00ULL, 0x431BE95D500533E1ULL, 0x32E94C60FEF4393BULL, 
            0x8A0C1C50D5375A08ULL, 0x06CC94D44F462FBDULL, 0x50FBCAE419934678ULL, 0xE73AE1C0F844F7D1ULL, 
            0x5209FA48C76BA067ULL, 0xCB51A3368D88FA9EULL, 0xDE1AD78E530DBB20ULL, 0xA2268587487BDD24ULL, 
            0x64934BAC3D3A3864ULL, 0xD31C18B72C2D0097ULL, 0x6A70D0441AF3289CULL, 0xB56415F8214DDFA1ULL, 
            0xCE528411F0070B57ULL, 0x9AFEBC8E4A9DB85AULL, 0x61538EF22C852FFAULL, 0x92B04ABFE32E093AULL
        },
        {
            0x43C9666374089895ULL, 0xB838B82053121CF6ULL, 0x9B6F7CB5B7F05DF3ULL, 0xAC832FD49C53E286ULL, 
            0xF78D16DA8DF97E34ULL, 0x84979F081065F70CULL, 0xF8C5499A57B4D298ULL, 0x42BF37FDDDE1CAFAULL, 
            0x5B837967628A3BD0ULL, 0x00C12C4C03F190FEULL, 0xDBBDC1FA7564665EULL, 0x99895622C64BEB06ULL, 
            0xE256E4A3D3403471ULL, 0x327AFE2CEA195658ULL, 0xF4CCEB741DD963C3ULL, 0xCA4F4F0E56599D60ULL, 
            0xB6356AA251C2D971ULL, 0x192A170882375D0BULL, 0x89A6E26CBB9D542DULL, 0x0B391FB447808626ULL, 
            0x4031BD5443D6774EULL, 0x243CE44A80533828ULL, 0x2EBFB442E78019D6ULL, 0x75C3DC86277ED63CULL, 
            0x0860953E245FB1ABULL, 0x4FF6C324DBEDFAEFULL, 0xBDF16B0B83400D87ULL, 0xECFDBB0A52DD54B2ULL, 
            0x859886B39E997FCEULL, 0x2FB35A04228D2B68ULL, 0x6D2AFB0C49AC0FEBULL, 0x85E002FA88592517ULL
        },
        {
            0x42172297CB3CDCF2ULL, 0x691843D3B96C3370ULL, 0x139D55812DF9A071ULL, 0xA28FDFFDD8C418BBULL, 
            0x1EEFF2ECA5435BBDULL, 0x8994D6FC0D1708CCULL, 0xFE1388D347D046BDULL, 0x52B6BB7BCD09929FULL, 
            0xBD84A1B744AC0EF7ULL, 0x9B69C6A816503898ULL, 0x736BC1B65C217137ULL, 0xE67024D65F203C9AULL, 
            0xFD82D1359360DD7AULL, 0x80E2AC86EC33C787ULL, 0x13490F3EA4F2F392ULL, 0xDCB00A865ECEFCEFULL, 
            0x731E5B098C278FB7ULL, 0x5DF599185D9F7FEBULL, 0x6770BD53F7AD1819ULL, 0x7888A8362868406CULL, 
            0x28FB59BB3C4FE0D6ULL, 0x3E0523D00A24EF9EULL, 0x13C97149FAE935B4ULL, 0x0C67CE2CF03F52D1ULL, 
            0x4B0DC9A95A42DA5CULL, 0x9A7EC89451A6A60AULL, 0xCF7BC78013B9C389ULL, 0xFA28007AF51FB2D0ULL, 
            0x8F8FE55B8C206D0EULL, 0x9D017EDB47299DCBULL, 0x1F2E20255211239FULL, 0x0ACDF43122F78B77ULL
        },
        {
            0xB0A6B6A66615F5E7ULL, 0xD5ACA192EEF4E726ULL, 0x10C97822E68BBD02ULL, 0xD548A4C5F0F96324ULL, 
            0xBF7C60AA2905A898ULL, 0x5B53BE70946F9CD5ULL, 0x8603F987CDA22C9AULL, 0xDD1E8478FCB0B65EULL, 
            0xCE28AA5390B5AD25ULL, 0xAFFCDA8AF11DB3BAULL, 0x7032C801C93C68DEULL, 0xB8938162BA29BE63ULL, 
            0x9A283510F02ACD13ULL, 0x7052B3516EECE9DAULL, 0x490F3A95F17B1334ULL, 0xA03C81D4D8DB6E77ULL, 
            0xB67909E98D3EE2C1ULL, 0x201B2DD19634D5A4ULL, 0x3BFD3009263A4DC3ULL, 0xD949583038EA1BF6ULL, 
            0x4D64321738FD787DULL, 0xC44F9A8354F42216ULL, 0x4CC77B50C4B986ACULL, 0x383D8A56E3B9AD79ULL, 
            0x15E7394A4B3F05A6ULL, 0x1876EBF8FA3D2174ULL, 0xD6DFDDF95DB9EAE8ULL, 0xE21ED1700C244F3CULL, 
            0xCE5B0B71E418BD41ULL, 0xFDB7C33398A9388FULL, 0x618BE5E25F58BB61ULL, 0x8F7B298850059DD4ULL
        },
        {
            0x14E150EC42C534C4ULL, 0x069832A65F4F1AB9ULL, 0x19C605A4D418CE07ULL, 0x0C5899C5913964E8ULL, 
            0xE3B6981F5D3201FCULL, 0x1234DAA9F40E853CULL, 0x6CA03038359BD123ULL, 0xC279D7ED91EDAA13ULL, 
            0x5E742EBC8AB7CFADULL, 0xA5FE5F316E163B06ULL, 0x930DB4C90E6A5189ULL, 0x1AFF361D77E47D27ULL, 
            0x9518C97F09571135ULL, 0x689A7099805FDD6CULL, 0xC256501EBE65E41CULL, 0x70F031ACF2B0719EULL, 
            0x42BE64939BA86925ULL, 0x3E351477DCB9369EULL, 0xB93D6D65E94F50B6ULL, 0x0BAC30350D83540EULL, 
            0x60C9CB1538D2E201ULL, 0xAF2CA8E13F806E92ULL, 0xD8C57E3B7BEF9BF7ULL, 0x6225CE3AA9EF5F86ULL, 
            0x6A378EADF667CBB0ULL, 0x6B0003340352A1F3ULL, 0xD5FEF4352164DD94ULL, 0xBCF9FAA92C6D4E0AULL, 
            0xEE8010602680F31CULL, 0x4620DF76F0F1B974ULL, 0x4F6D7EC4473D3844ULL, 0xAB5772D5A956B7A6ULL
        },
        {
            0x094BCCFA2AD8CBFBULL, 0x24550CACBF8B32CFULL, 0xE93D0E918DF7F442ULL, 0x1FAE69EE50DD4FD8ULL, 
            0xD6E242704C1EFDEDULL, 0x51530427B013242CULL, 0x88B32E7FA0517102ULL, 0xC11BDC89D5AE1980ULL, 
            0x0143FC37D7AC7FA8ULL, 0x6A69C4E79F890898ULL, 0x06070936FCA39CBBULL, 0x0376C00013B70835ULL, 
            0x022DAD604FA43640ULL, 0x854E8C68B24C602BULL, 0xACD231598D726A69ULL, 0xCDE3A095EE241C7FULL, 
            0x2DF73D2538979B77ULL, 0x5487D3236B8A5C67ULL, 0xC539AAB6FCBF081BULL, 0x1B1A983FEA6B0384ULL, 
            0x4548F117F81F5ACAULL, 0x4C4E71C332BB2667ULL, 0xD1507F69B5057758ULL, 0xB5F83F24B4A40E5FULL, 
            0xF66766D74BC24845ULL, 0xCD0A2FE283723E7AULL, 0x113568058A484327ULL, 0x1460BEDD305B7286ULL, 
            0xD3D4490D6EE92620ULL, 0x6C2BE6E08006AEBBULL, 0xDAF7BBD9518E6DE4ULL, 0x2816C02B7A0E9B8CULL
        }
    },
    {
        {
            0x986C6FB4587361BCULL, 0x1A6EE63005222012ULL, 0x71E2D9D7F70244CFULL, 0x8E6ABAFD796BE04EULL, 
            0x6E01C6077BF0CE24ULL, 0x22DFC85B932536F6ULL, 0x823CC4C24E70E3B7ULL, 0x29F1B63522173011ULL, 
            0xEC8EF23FF54BD60FULL, 0x8886F1A55E3CE1E6ULL, 0xE0A0EBCF8C9C133CULL, 0xE3F75D661083B9DAULL, 
            0xADDD6D473B0D326FULL, 0xD8C77A5AEB983861ULL, 0x74F893E2A9077191ULL, 0xDA1446AA814A22C8ULL, 
            0x7FADFC37F729CB18ULL, 0x9AE4FA5CA70997A9ULL, 0x5079E776F29190F0ULL, 0xD92278D5F2EC97C9ULL, 
            0xD499DD2D0DF84D1AULL, 0x80EA44F3CF511780ULL, 0xD8882AC866DD481DULL, 0xF074634CE73B05E1ULL, 
            0xF5CE501919C51A36ULL, 0x8CA4BF03C8CC6532ULL, 0x21EF70C12CE83865ULL, 0x21A0D9CCAE6097DBULL, 
            0x7BB13CDB55F15CDCULL, 0x007966151FA5AD96ULL, 0x6EA2EDC14C26944EULL, 0xF77D50C827608F86ULL
        },
        {
            0xEC12044B1A38532FULL, 0x7C8E97888024AEECULL, 0xFF1B177DA76BE381ULL, 0x00989396D6DC7B65ULL, 
            0x6AFFE7B3CD03D630ULL, 0x3C972BEBC74694DEULL, 0xDEF9B521147AC0C1ULL, 0x17D2EA7AFF6E7F7FULL, 
            0xBC4BAC6A71EFC7C0ULL, 0x60F55CF7568A0250ULL, 0x4B6CFBC283EBFBA4ULL, 0x44126A4F755FA516ULL, 
            0xF7189424EE654C23ULL, 0x546B43BE71E10973ULL, 0x5EF5B7ACD0D65200ULL, 0xF0087C94866C8B4DULL, 
            0x15A5E121B59551E5ULL, 0xD565297506BF900EULL, 0x7CAB136193E6990FULL, 0x628459AD95DE9F45ULL, 
            0x99D2D6F4A9CDCD66ULL, 0xBA2D9B8E8B0CB888ULL, 0x38AAFC07B82BF1FEULL, 0x498E2BF856D208C3ULL, 
            0xED3BF033EFECB437ULL, 0xAC31EADE9AA9AA1EULL, 0x8869BB4178694C03ULL, 0x022A578B1D2E9B1BULL, 
            0xDF494B5F3876EA5FULL, 0x6E97766935A72F07ULL, 0xD4A86A3E7F1A7752ULL, 0x5A0AA5CB1D53FE83ULL
        },
        {
            0xD1CF81A3E960F11BULL, 0x73E52C9F21FD20D5ULL, 0xFC2B8731422AC099ULL, 0xF3B84E19A078FD64ULL, 
            0x2053E3FCC7ECA6DFULL, 0x02B94B18F47EB082ULL, 0xA8AEC46F99E6D0DFULL, 0x007BCB662EE3125FULL, 
            0x7A0347552E4CD9D4ULL, 0x08A97E51462B47D7ULL, 0xC247833D326D1565ULL, 0x2AC69E2AA151DA13ULL, 
            0xC9478319052ED0E9ULL, 0x270A34243C88DF89ULL, 0x0B07A7C762C0D6B3ULL, 0xB484034553057CEBULL, 
            0xCD20E60C3C0AB762ULL, 0xFCABBDDDBE8C3583ULL, 0x1E3E094240ED8625ULL, 0x9B9E0CE5BA846120ULL, 
            0x1BF6DADBFDAC3E0EULL, 0x01CC46396233FEAAULL, 0xA99C42F150AC433CULL, 0x2B13017164D1E2AFULL, 
            0xD024584356562D60ULL, 0x771FD5D492510AC8ULL, 0x1D405B13E4289C88ULL, 0x9FA59D85EA273D8BULL, 
            0xD1F80B989347414BULL, 0xE34FA613DCC85817ULL, 0xF70511755AED88FEULL, 0xA249DDA62F042554ULL
        },
        {
            0x663875CD9E818B5EULL, 0x327F2DAAC5FBDFF5ULL, 0xD60D40B9AB863016ULL, 0xEAB290F9BDB119A3ULL, 
            0xD21A7271EBF368A1ULL, 0x782D0E4E3AB6F1D5ULL, 0x9A61B6171D540DC0ULL, 0x72F256F3F5C3EC7BULL, 
            0x3435684E5CFA768DULL, 0x3782CBAD4264BAEDULL, 0x9350BFBD00EA9331ULL, 0x2797A019A0218B83ULL, 
            0x437EE2022E301B38ULL, 0x574466D30F38DB63ULL, 0x37E62BF291BC8360ULL, 0x4ED908B3D25F830BULL, 
            0x5FF6BFB42A30B5F4ULL, 0xD9530E82BCD287BDULL, 0x5973DB8ED0B1ED70ULL, 0x5435A40994165C69ULL, 
            0x72ECE9C414C1B7C8ULL, 0x1E82B8DD67BA2017ULL, 0x493E910CEBC49B1CULL, 0x01662277FFBCB480ULL, 
            0xC9A487DBF748D690ULL, 0x502674BA0DA60F1AULL, 0x2E5E2CF98B103131ULL, 0x1496837F7576DD49ULL, 
            0x4603AB2ED2C43A81ULL, 0x15A25DFF2A47C8F5ULL, 0xFEB72D07B2C5393FULL, 0xAB6F851D3AF07DEEULL
        },
        {
            0xF68D92A4C7E44E1FULL, 0x6AC48231C5D1B645ULL, 0x3B887570332CA3C3ULL, 0x55BB85F4FCEBBAC5ULL, 
            0x9ED06C9FD980D443ULL, 0xE2BBBFB48DCA8505ULL, 0x6E6147F1D622C739ULL, 0xD964A66395BB966FULL, 
            0x9B3FDD9D6A200A05ULL, 0x472BB3F2D75D277EULL, 0x32CAF3E30C046264ULL, 0x1E5D679454528A4EULL, 
            0xB6B04696D24A7E71ULL, 0xE6535656A5BEB156ULL, 0x38BA59EA5C5F9876ULL, 0xDEE597E8D3662C25ULL, 
            0x30B29AC88F4ACF7FULL, 0xE33EA3036E12E840ULL, 0x3211EDC8A4715762ULL, 0x73A5A1021CA31AE5ULL, 
            0xF569014B32B6FA54ULL, 0x6D0D838A0B30AB71ULL, 0x0AAC6E1FFF90BEBCULL, 0xB2D0F3107011830AULL, 
            0xF9E2BFF99338A64AULL, 0x9779DEA410566F61ULL, 0x4843873BB7B52D11ULL, 0x550E44F53F9E12F8ULL, 
            0x6EF28970743E1E59ULL, 0xE131AD6F1C85DC24ULL, 0x8B5A7ADBF117C7AAULL, 0xEE6B88FE7B35EF50ULL
        },
        {
            0x88FA4F3EDB838984ULL, 0x5846F20975D7C810ULL, 0x53298B15FF1EC00FULL, 0xD6B9AF0D27ABAAE8ULL, 
            0xFA3D7E1D46EC3A16ULL, 0x3715EEF2FE37D71AULL, 0x7E14CF9864EA3A2EULL, 0xBFB48F0F25DD7E59ULL, 
            0x3A4E2C2AF6260975ULL, 0x6CF9DB703F561E78ULL, 0x2798DFB343531A19ULL, 0xECA4E60C1138A254ULL, 
            0x0A4045D44F1719B0ULL, 0x82052DEE11CDE8A1ULL, 0x0573CEB3517D75CAULL, 0x535BA5F699F346C7ULL, 
            0x1FBE3EE6D3AA1325ULL, 0x66009E861C7A3912ULL, 0xD58847B2A74F359FULL, 0x200816E5E48047ABULL, 
            0x8209FF5E7949132FULL, 0x02E06559C5CE8E9DULL, 0x1CB7A4387877FC55ULL, 0xE53AA2B2F71FDD7BULL, 
            0xD35D32A3D1A0EB9FULL, 0x088D7AB450057D76ULL, 0xC835F81A8CF9E685ULL, 0x8D01F749E19D8CE5ULL, 
            0xA0335244576EF067ULL, 0xF52A6E82DEB39C4CULL, 0x882EC202E3FB81C5ULL, 0xFD768AD1B98C6967ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseGConstants = {
    0xD75CCE2121B8C4D5ULL,
    0x02EC68DA5448AD78ULL,
    0x6328C50C51F39D61ULL,
    0xD75CCE2121B8C4D5ULL,
    0x02EC68DA5448AD78ULL,
    0x6328C50C51F39D61ULL,
    0x44A0093293C8FFAFULL,
    0x941EBF2A8F42A758ULL,
    0x66,
    0x0F,
    0xAD,
    0xE8,
    0x0F,
    0x63,
    0x46,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Holy_060::kPhaseHSalts = {
    {
        {
            0x75FFA4FEE1BB8D02ULL, 0x64D02E246AAE8F26ULL, 0xA242A94C9517B78CULL, 0x29012A06925A48A9ULL, 
            0x7504F6455C748535ULL, 0xEB9A37FFBC60A579ULL, 0x1BA004563A2C6FDDULL, 0xA20A421E0D9F5F79ULL, 
            0x57E3E1B49CEFB955ULL, 0xA8387910252371B6ULL, 0x55FEE872E983CB34ULL, 0xF51B57B168D83302ULL, 
            0x3D14F4DFF5F43500ULL, 0x9ED4F44DFAD5F0F6ULL, 0x2137EE7319A8723BULL, 0xA5DF002838E3ACF3ULL, 
            0x3E3AC43E920039BDULL, 0x84FF8ED801F24AA2ULL, 0x2A6AF649CDD8DD41ULL, 0xEB56BC3B59A7AA50ULL, 
            0x0DAD4F972BA69BC7ULL, 0x3A34FA64B25C1C97ULL, 0xC3DCFF37AA9C1F28ULL, 0x0EC7DC2258070938ULL, 
            0x09A1C1F1FF996B31ULL, 0x2AEE1AEDB984A1ABULL, 0x82B6DB95C5FD0172ULL, 0x89BCD352FD641F43ULL, 
            0xCF757DF1E5897435ULL, 0x6459D7C7102383F4ULL, 0x0E2051ADE2F85761ULL, 0xD5FBAE27BDF71DC7ULL
        },
        {
            0x793DDB2132751F42ULL, 0x61E9EF3EAD1C4E42ULL, 0x339D607BF4F17767ULL, 0xC42BAAFF851C4D73ULL, 
            0x2D26ED3199E26607ULL, 0x602A937A48C3C36FULL, 0x5F3625F74C2D77E3ULL, 0x0E15A11E652B7CCBULL, 
            0x5451105E31B2DA47ULL, 0x206AAA9EF573DE74ULL, 0x1FBE1429022E9D33ULL, 0xDD419D96A0A52979ULL, 
            0x040F41C07DDEAECFULL, 0xDBED7A9DA90A190AULL, 0x32AD7DEE404D3A6BULL, 0xB6A03E63C3E2C9F2ULL, 
            0xD2C730C744222FB6ULL, 0x2EAFB88441511DEFULL, 0xB7069B25C4E259CCULL, 0x5CEECF90E551121DULL, 
            0xF600C42FFCDF7CD6ULL, 0xCBCF4CDEAC873840ULL, 0x397DA73E109433E9ULL, 0x4667D469BC38F7CDULL, 
            0xD6191B631E087668ULL, 0x71621CF9158E1FEFULL, 0x601FA21AAA6B53A4ULL, 0xADD2094EED4C74FBULL, 
            0x7C9EDC480349CB2EULL, 0x0C27954D36284ADDULL, 0x42E5BF4824F952A6ULL, 0xC34C9034A7D845B8ULL
        },
        {
            0x528BFA42ADA44773ULL, 0x3608ED5660B77BBCULL, 0x4AFB26C6E75651F9ULL, 0x08705C084B7CE478ULL, 
            0x6A269866E7B81ECBULL, 0x1490CACCE3D54384ULL, 0xB01B2A9851BDF4A8ULL, 0xE13C098D4A5D3941ULL, 
            0xACBA0E6B29ED854AULL, 0x8AA4D0E90AB58CD0ULL, 0x9C605CD51CFCDE91ULL, 0x5BB6067008407FDFULL, 
            0x7648123DEC0CF655ULL, 0xBDE6E883CC600DFAULL, 0x72CF6AD09F2EBA48ULL, 0x14CD9B9175CC7EEAULL, 
            0x8977A32FD34C5A15ULL, 0x73F64B0F39DFFE78ULL, 0x506879067111B6BAULL, 0xF4F0F0B98FB7F631ULL, 
            0x7E8BD19B3568A14CULL, 0x3B0EB2F2851034D6ULL, 0x6F2FED887AD1D5D0ULL, 0xC44B795DFAA5ABFBULL, 
            0x51D1A82A8A5E5740ULL, 0x756F2E7922B1F197ULL, 0xDF633CDBA0DB13C2ULL, 0x8A28258C81450A5DULL, 
            0xB929E47B2062F5B1ULL, 0x401E9078AFEC0F17ULL, 0xFD5726A6D7DE9268ULL, 0x0D0E82984225B929ULL
        },
        {
            0x7C38614B91A9F4A9ULL, 0xCC889633B0DE01E7ULL, 0xD4E508A27ED4C6B8ULL, 0x885205EF83C3EE84ULL, 
            0xFBD5809F30B4D5F9ULL, 0x5CC3C4A5742869F0ULL, 0x82A3D77F70A5C212ULL, 0xAFCEE77D10445648ULL, 
            0xED9E6E0F7858661DULL, 0x8A68D5C33EFE7C78ULL, 0x06CC45F2DF3C93EDULL, 0x282907C85EBC3D8CULL, 
            0x7B5AC34FEBABE7CBULL, 0x92D622BE9026823DULL, 0xACD3D460B975611DULL, 0x4E9EEDD5BA4E07C5ULL, 
            0x758FEEDC9F48354AULL, 0xC02AD840C7654FB6ULL, 0xFE1A89614C7265C2ULL, 0x0629FE4C7EEDC52FULL, 
            0xD1989F749584F087ULL, 0x5F1E429F5A06EFFCULL, 0x1DE95E9EC71866EAULL, 0xCFD79CA1B65D5C72ULL, 
            0x496D26BA7CA15C22ULL, 0x5ED4783B0C72AD8BULL, 0x96A64299D0A706CCULL, 0x1F37EC07BC3EC92CULL, 
            0x72F990C626970A63ULL, 0x8F355E67016AF3F8ULL, 0x4E40847534ABB3FFULL, 0x75EE00D6DFF12C3EULL
        },
        {
            0xB94BC7C13C586E67ULL, 0x00C30E1695EC34B1ULL, 0x48CE5288FB739F03ULL, 0x0BC74C1D0D069EE6ULL, 
            0x50379CC7101EB654ULL, 0x43CBCCC20C51C47DULL, 0xDB098D48258C37ACULL, 0xB063D544C0EF184FULL, 
            0x5EC06DDC5F8E0108ULL, 0xE8E6490F87FCFD49ULL, 0x1B3150C7229CF31EULL, 0xCDEC90D8FEBFDFF7ULL, 
            0x3334A9F7219B3BE7ULL, 0x8C1798B381523285ULL, 0x897580BC65E4B7F2ULL, 0x6EEF0C2E2711755FULL, 
            0xC9160DDB83425929ULL, 0x04AB4DB29319E731ULL, 0x021D58889ED08C18ULL, 0x51D971FDD3BB07F8ULL, 
            0xDC2DAD91E1EE8951ULL, 0xD2019E876C034645ULL, 0xE35CA9CE4A66EFBAULL, 0x428D71273F7D8F80ULL, 
            0xB993836C250A63A6ULL, 0x17CC52608BB3EE54ULL, 0xAD22528AA1FD29E4ULL, 0x348F74D7E82AD17FULL, 
            0xF0306A36DF6196CBULL, 0x2910C5591A87C6B8ULL, 0x1BDBC6F8AB4C56BBULL, 0x807C7863CD26CA94ULL
        },
        {
            0x33AD00BAC36828FFULL, 0xBA9AFEFEFD6C50E1ULL, 0x9059CC9C3592FFA8ULL, 0x6A7AB5CEEFB0AEBCULL, 
            0x8628EF2C761267DDULL, 0x685686CD6F5031D4ULL, 0x939809944814F159ULL, 0x2D70CD96464ADEC1ULL, 
            0xD67E5F0D8EE00B81ULL, 0xFC13A1CF68F620E9ULL, 0x7A0E6E55E1275F82ULL, 0xF65EAA53E576137BULL, 
            0x1A9997FDB40A3E9AULL, 0x565660A532D2FE93ULL, 0x026398EC0AED5438ULL, 0xCB040133A4191878ULL, 
            0x66A57C726CE77E1AULL, 0x4AA3E98AAD05D9F2ULL, 0x8B9ABEC85D2F486CULL, 0x6FFB96EB25770FBEULL, 
            0x5AB686288CC1B57AULL, 0x6B6534C0D444B3CCULL, 0xC7FFC33D5D5E7093ULL, 0xE64179035C4E2458ULL, 
            0x13DF549D28BFF6AEULL, 0x37387429B0154088ULL, 0xBEF8ABB444ED8DE1ULL, 0x9EF0205AC6F73715ULL, 
            0x50C1DB4A63C84AC4ULL, 0xC235D40DC4780F46ULL, 0xE4CFBAEDF81DCB23ULL, 0x16996AF3E2467E62ULL
        }
    },
    {
        {
            0x7413C50FD35CB4CCULL, 0xCA0835357C14C6D7ULL, 0x7D1AF1F05A4C7457ULL, 0x39B79A17C25980E2ULL, 
            0x6D84B91909C8EBBFULL, 0x2708036EB04EA62AULL, 0x75CC32A38552B16AULL, 0x2D1A631873716D64ULL, 
            0xC55F900D085EAED3ULL, 0x50B5EFB534ACD0E1ULL, 0xEC91DC03EF4A8148ULL, 0x0FFAF1F6BA5796B1ULL, 
            0xDAFDA0821C2206A0ULL, 0xC1F2C9280E3DDC83ULL, 0x1A9CC39D6B84B20DULL, 0x6191D5C45BF004BFULL, 
            0x8ECA7B21B1EA0472ULL, 0xE816AE5B39BD5472ULL, 0xBD2CEDD9BE59E7EAULL, 0x47A482907A664A04ULL, 
            0x4B568D124D67815EULL, 0xBFCD5D6CEB6D474DULL, 0x91DEF1BEEBAB12F9ULL, 0xE28FE59242E44B65ULL, 
            0xF44B7DA4B0C6DADBULL, 0x20FC87664193BD75ULL, 0xE09062F7BA77F499ULL, 0x5B8A538B6B4721A9ULL, 
            0xDBA681E5D6105F42ULL, 0xD2BD3D72C69E62C3ULL, 0x2DE232375CD8AE4DULL, 0xADA6D3761A441D2FULL
        },
        {
            0x2DA895F7FFB1C1DDULL, 0x5CCE57399D9041C0ULL, 0xE1FFAE39F2AD49F7ULL, 0xB6543773192C187CULL, 
            0x458E6AFFCA582B20ULL, 0x340AAE35E51BF370ULL, 0xF71DF49EC160E6C6ULL, 0x516080B22E881AECULL, 
            0xEC55ED5586F1CE80ULL, 0x13B0D8FA7A9AD699ULL, 0x0FA1FA1EBDC4FE75ULL, 0xBA3370B02AD4599FULL, 
            0xBC50700E431CB520ULL, 0xC77118B3E89EB0D9ULL, 0x19350B75AC4CBE89ULL, 0x707F5F0F57F97F1CULL, 
            0xAE28FC5C830F6114ULL, 0x3FA499C2D6192DC8ULL, 0x17A91A6720F7582BULL, 0x4EDEA9EFF6C54A2CULL, 
            0xBD589A71BA67E794ULL, 0x741BB1EB86A4FC99ULL, 0x20753BC132144EDFULL, 0x6150029DB63F1196ULL, 
            0x222197B69F8EFFCAULL, 0xFEBEB88E81E85B76ULL, 0x5225DCE5E9514ACCULL, 0x8FFF90965426F446ULL, 
            0x10BF5A86B33320AEULL, 0xB96EE4CCFD74695BULL, 0xD52C0D6C78597E95ULL, 0xA8B87269771BA5D2ULL
        },
        {
            0x60F4F2439AE14127ULL, 0x2C707EC2F46638F8ULL, 0x19CA150EF74C43C2ULL, 0x92D71A49F2358648ULL, 
            0x7BE8FCE5C00A41BEULL, 0xA082D848D231A43DULL, 0x53BF4C8C301A6488ULL, 0x4DF0F808F651B53AULL, 
            0x443BB436A9C19AECULL, 0x7AE2C86A4B41CF21ULL, 0x23C5BF103ECF6842ULL, 0x8A8B01B932F29373ULL, 
            0xD0E407B80E6EF22AULL, 0x4FCA162E9DAC4526ULL, 0x2C00751878D17663ULL, 0x318AC1BEEF771946ULL, 
            0xA2E8C0D248AF3E54ULL, 0x140977588F16A97AULL, 0x23DD016B99B6C082ULL, 0x225AD0120B6DC2F9ULL, 
            0x7CC2814D09FFCE61ULL, 0x944A50D167EC4569ULL, 0xB682C0B7FA8A42A6ULL, 0xB3D4225344F1B063ULL, 
            0xD68D5F801699ED2FULL, 0xED039B90E2C0C7C4ULL, 0x1284F078064C7D09ULL, 0xEE676D37E9BCF3E7ULL, 
            0x95DEEFAEE34286CAULL, 0x5CA355F0231F6EADULL, 0x2D7F36D78C361E78ULL, 0x11360944F5A060C2ULL
        },
        {
            0xFCC0BFE7D5A533D5ULL, 0x04ED7D86F383D4A2ULL, 0x015A5E9B51DCA392ULL, 0x939EF256E39B7C12ULL, 
            0xC5EBB9FE2C7FB98EULL, 0xEA7940D8E9FFE968ULL, 0x21C5B1C762909B44ULL, 0xAE4976C0B9BABFD5ULL, 
            0xCFFC0277DFB69E23ULL, 0xC52A64C45EAEE6B0ULL, 0xDD2714191B7A0E50ULL, 0xF2245828E906ED9AULL, 
            0x8C38A44AA0BE80F3ULL, 0xDFE8E1B8D17764ECULL, 0xEB594B55F9C8A8C1ULL, 0xA3C77AA51A9276E5ULL, 
            0xFE30EB34051337BDULL, 0x21DC0B6E5EA5F823ULL, 0x91DF1720AE2609DEULL, 0x11A1F1AC19A28A9FULL, 
            0x67D554E2D9D5DDA6ULL, 0xAA6A880AD04EEA5FULL, 0x7E9E60040D9C30CBULL, 0x920B7BDCA95380DAULL, 
            0x5FBCAEA77DB0DA4FULL, 0x81B5CAD9C8C3D862ULL, 0x35800378341B69B5ULL, 0x5986D972F047D50BULL, 
            0x741DEFB3993F99F0ULL, 0x9082F1DAA222DC8EULL, 0x785649F849EFBC74ULL, 0x271DF45FB59054EBULL
        },
        {
            0xC6BCFC2338EA09D5ULL, 0x570C02287AA5DFADULL, 0xE1EF194281F1F962ULL, 0xB88CB573CECB752AULL, 
            0xE1868E1B9EB29B2AULL, 0x599EE3F9D02F2DE6ULL, 0xBB8ED6C6A04C6BACULL, 0x84F243EB43DC4EA2ULL, 
            0x8B8673C0AEAE35D2ULL, 0x27918CD15CE64925ULL, 0x9FED2C0783E6E653ULL, 0x0282AFB5C1DD223EULL, 
            0xB3E95431C89B9C64ULL, 0x4D2A4BF2BA505352ULL, 0xB094FD0F45F189C2ULL, 0x9A94F8AE59823BE3ULL, 
            0xFF4D6AB20BE1C0B5ULL, 0x025F717D7A0DF990ULL, 0xDD5DC19AD921BA25ULL, 0x7E1AB9E256B278EBULL, 
            0x132554D11CA8BFE7ULL, 0x6C09444BB2FF95B2ULL, 0xB077FD24C94F93A2ULL, 0xF0F913C7901DEEDAULL, 
            0x720010EB70C78472ULL, 0x72B63F3AAC619B97ULL, 0x5DCD4B105591E76CULL, 0x1FC824AEB798B787ULL, 
            0xDF70C58C7F9C2F77ULL, 0xBEAFC69F0C0164AFULL, 0x8395EC546F4F17A6ULL, 0x5D9D8BD567046DE1ULL
        },
        {
            0xC2BCCB6404923848ULL, 0x08B6831A444E5056ULL, 0x9F445301555B4210ULL, 0x919DAC61B10EDE75ULL, 
            0x5EEFF93B384FD42DULL, 0x787ECA6E704ABAD7ULL, 0xE0942AAE4C562FFDULL, 0x8BA52A2FC33E260CULL, 
            0xED4E491988656198ULL, 0xD23F9B2186C6209CULL, 0x52E6DF32EB413A54ULL, 0x64EC5BA14B92DFE2ULL, 
            0x5AD70D125E011156ULL, 0xA132CDF351FB6CDCULL, 0xE4C0337AD3F3F1C9ULL, 0xB0311A03DC115C1BULL, 
            0xE512543A1433979AULL, 0x36973DABB4B58D0CULL, 0x46DE968F62694C84ULL, 0x5CB33D6DC46971D5ULL, 
            0xF66BB5E0C495E7C1ULL, 0x4CCEC33FA8067C98ULL, 0x33B2D7DBEF65020FULL, 0xB55E98D167614AD9ULL, 
            0x8E57DAA41AC73361ULL, 0xFBB60C714B9A917AULL, 0x59A24BD815FB61B8ULL, 0x852851F56C70C793ULL, 
            0x6455E2F8C4CCB95AULL, 0xCDB39E7D9AE48FBEULL, 0xDB7FA1B19FD7AD4FULL, 0x56011756D65C0A0DULL
        }
    },
    {
        {
            0x5D5FCC11222F8B9CULL, 0x6692A60D15B701A4ULL, 0x7EE1539A2D7EE01DULL, 0x86A95C89A56CFEB2ULL, 
            0x79BEDBE6A3DF98F1ULL, 0x7069943A5D612A03ULL, 0x000FE289DE9EBEEAULL, 0x8CBB5A3092785283ULL, 
            0xBF811BEA70EDA86AULL, 0x89341BE0AC475B50ULL, 0xC6DBD4429ED18F9AULL, 0x157BBE16947B6B95ULL, 
            0xA9007669B549DF3AULL, 0x98656EE1C7491061ULL, 0x23788C577A1AE39FULL, 0x036801AFA02A15A1ULL, 
            0x86EF2F9EA2A7C3D0ULL, 0xD5CA024CC49AB419ULL, 0x1A0DFC6A0B162E5AULL, 0x1A50002CD669F8DEULL, 
            0x8F367DF144DC2A02ULL, 0xC2A0F6D898A48F19ULL, 0xC2D085758D4AEFAEULL, 0xB753B4BD07CE2410ULL, 
            0xABBF7DB525F56BE1ULL, 0xC7516E86E4F2B989ULL, 0x2DB0A4AE83BACD5CULL, 0x035CDAF4B54DAAA0ULL, 
            0xAF67DD2C2302716CULL, 0x04C1AC1BA8457C79ULL, 0x4F9A9EE56666FA80ULL, 0x9D530D3B9CEB31EBULL
        },
        {
            0xAD6DC7790E49C896ULL, 0x22CF415A10F3A8E1ULL, 0x5EFBC9F5607D4D25ULL, 0x1BA4C1640D20A559ULL, 
            0x460F7831A8BE8490ULL, 0xEC3AA900A6EE604BULL, 0xF23DD03E7DC699B5ULL, 0x27B7F4D61AD53253ULL, 
            0x9B7B970C02244172ULL, 0x81DB394557415FF5ULL, 0x954B48A293122FCFULL, 0x729CB6AA80D8DAA4ULL, 
            0x29C696FB1F2C708BULL, 0xDC2EA149BE8DA064ULL, 0x29EBB5AB7B129F08ULL, 0x72716DAD427CFA3CULL, 
            0xF26648ED90A21B30ULL, 0xFBAD602EEF1103F5ULL, 0x17BD6D9902FC17FCULL, 0xA8E6CCD4A3737D96ULL, 
            0x36447EB90F39E563ULL, 0x9D54F81A93D42BF4ULL, 0x4A1231245F1437D1ULL, 0x474EEBF732FCE5F1ULL, 
            0x0FB4F61D3EF16816ULL, 0xB173A7C800E0A98DULL, 0x8AF745828D6BE680ULL, 0xE5B8A639EFA303FAULL, 
            0x37AB96737D47DA8EULL, 0x94A6374939CB4D26ULL, 0x319A583210376A1CULL, 0x62C04D9CC660B276ULL
        },
        {
            0xE3998E9C81E24B26ULL, 0x2E944AF91FB1B966ULL, 0x8FFFFAA4AA68E00DULL, 0xCF7AF4EBC6C00D07ULL, 
            0xC8CDA3B1270DC81BULL, 0x9217698848B68D8BULL, 0x9FA26938B5085CF6ULL, 0xE6F688FC1F6F24A4ULL, 
            0xA2A425C8CF9697E5ULL, 0xBB4E5EA21D541481ULL, 0xF1FFF733D61305F5ULL, 0x7359B20D7005EC98ULL, 
            0x136BC3397FFCC9C4ULL, 0x5BEB36CFF122B4FCULL, 0x30B942128C536DB7ULL, 0x4950C4BD76C19CE8ULL, 
            0x22F760E87F31E937ULL, 0xD8CA73E8FCA8A412ULL, 0xD9B20CF65FB07B04ULL, 0x2AFF3215BB1F7145ULL, 
            0x51C6195E32EFA8F4ULL, 0x1DD3F049014F0F1CULL, 0x804C2D2FCA3E8D36ULL, 0x427078E293AD4BB0ULL, 
            0xFC5DF55E8BB03595ULL, 0xAAA1F24FC46F9E94ULL, 0x9A7616087C33A365ULL, 0xAE50D6AC2A6C2C0AULL, 
            0x5100F33F7EF9200EULL, 0x43D2F1CABDEF3625ULL, 0xA647F9D29FCD0E7DULL, 0xF3F8FBD3B9975CEEULL
        },
        {
            0x80FD84124DC2EAF6ULL, 0x183B9C5AFC895CBFULL, 0x6DFEED85F441311BULL, 0x20FC3D7781F50C2BULL, 
            0x80DF7FC48769237CULL, 0x6DB7FF4244FC3978ULL, 0x91E2B4CE8C60AAB3ULL, 0xA584CFA384985219ULL, 
            0x832974BA1BF57AFEULL, 0x2ECAC67D91B36B40ULL, 0xE5DAD4649E30F9EAULL, 0x48E5B91A119258B5ULL, 
            0x3565C6EF7B5771E5ULL, 0xE85A306D70A1BD07ULL, 0xAF97DD7267EBAB33ULL, 0x8317293B5AF16831ULL, 
            0xFF4BF0EDBA47787BULL, 0x108A8ECB00CD7307ULL, 0xCF448CB218AD37FCULL, 0x194ED1E8DCC6D9F5ULL, 
            0x00426CC5A8AD2FC0ULL, 0x93F1307FDC384561ULL, 0x5F519351A7BB54D8ULL, 0x657D71F325994DA2ULL, 
            0x0B09A2D9AA7284CFULL, 0xDE2E791B43275A37ULL, 0xF5423A314A8FB1A1ULL, 0xF0F3F8B7F77223CDULL, 
            0xE5001C7020799D4FULL, 0x2C0E21115661CBF1ULL, 0x17DB19140B064F30ULL, 0x3DC14C83D289892AULL
        },
        {
            0xFECDE792C15E6F8CULL, 0x3B3F14D98B27B06AULL, 0x2B7E11FFBE1AE6EBULL, 0x2D9EC73789A92984ULL, 
            0x8ED387D4C88093D5ULL, 0x9DEC12C6DEC2F381ULL, 0xCBAA37E00EF5859EULL, 0x7F18311D741A133AULL, 
            0x7A4F709E8995A069ULL, 0x1F989A0291294BFDULL, 0x0EA0B9C797A7C9E8ULL, 0x7F31E19418CE6D0AULL, 
            0xDF1B967C0A14A62DULL, 0x35A45A7BE7917610ULL, 0xE378A2F258C9E5B7ULL, 0x1F3EABB5D1207E2DULL, 
            0x503E0EDD353928F3ULL, 0x9225ACAF8A465093ULL, 0xBA187AEE507E728AULL, 0xBEFC4B5C3B011C74ULL, 
            0x997F007460E03131ULL, 0x08B8AA80C3213F41ULL, 0x564553DB117FD423ULL, 0x4CAD713A27503205ULL, 
            0xDA37E09CBA2D67F2ULL, 0x732C83697462F058ULL, 0x40E14EB829368B99ULL, 0x05EC3AA55759EBD9ULL, 
            0xFC6D23B9FB7806E9ULL, 0x0A12A6CA5819BDC7ULL, 0x22653125CDA902A2ULL, 0x535DD3087C10EACFULL
        },
        {
            0x7B6C75AD9ECCB55AULL, 0x8FFD37A722660BB2ULL, 0x9DA9DA08302B4921ULL, 0x5A80B8E5A7EF9517ULL, 
            0x46922BECBF0A6E1AULL, 0x9F1F185198E7AFB5ULL, 0xD0ECE410806E7750ULL, 0x64B3F3D1543284A7ULL, 
            0xDF6C27967CF394DCULL, 0x38F36A7F7F63163FULL, 0xA8F33213B42237A8ULL, 0x0BA0E94BF8A55506ULL, 
            0xC0C084EE566FF58BULL, 0xDAAEF9F27B0CCEBFULL, 0x26C0423154E56B45ULL, 0xB51DFF5C7ECFA497ULL, 
            0xEA40FCAADC94CED0ULL, 0x86A732875DA90507ULL, 0xECCCEAAC830FE7BAULL, 0x29392CB0581D3040ULL, 
            0xA5C8D46DBC79F981ULL, 0x94FD0A6596C94801ULL, 0x8DB4BBA639BDDD26ULL, 0xB0E50A03F2FCCD76ULL, 
            0x648D9688D5B4E35BULL, 0xD8625F99CCA03D64ULL, 0x109B9729C8C9B17FULL, 0x666A468549A7C8BBULL, 
            0x545EFF6663FB3762ULL, 0x5B799A91E8012DDCULL, 0x61DEE9E932D9F13FULL, 0x6480C3E3F66EC6D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Holy_060::kPhaseHConstants = {
    0xF4AE5183A2A42952ULL,
    0xF95AB961B497E074ULL,
    0x5525706E54B74302ULL,
    0xF4AE5183A2A42952ULL,
    0xF95AB961B497E074ULL,
    0x5525706E54B74302ULL,
    0xA08FAAFE27164E6BULL,
    0xC9ABF5A25BD2D049ULL,
    0xE5,
    0xC5,
    0xD5,
    0xBF,
    0xED,
    0x0B,
    0x41,
    0xD4
};

