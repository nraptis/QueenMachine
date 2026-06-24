#include "TwistExpander_Unholy_060_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Unholy_060_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint8_t *pSnow,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC1B775689192887DULL + 0xE8242EDAF38767B7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEE504FBE8B683DADULL + 0xB34269C1B441B6A4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8543D89BED9E1F0DULL + 0xB113C5920C960819ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8B7D63FB75B1AD2FULL + 0xFB27DFDAAC0D1C21ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF12649CCBD4905D1ULL + 0xAB53E70BA2518CD8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF63924FC5C2C4E71ULL + 0x8393DF87BE01BCCDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE2540BA79CD94189ULL + 0xD9A95273163ABF13ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xACE0BB08045BC5D5ULL + 0xA8F437E6F8B760ACULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    [[maybe_unused]] std::uint8_t *mSnow = pSnow;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_A kdf_a_loop_a (start)
    {
        // KDF_A_A kdf_a_loop_a lane group
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, mSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordH, 43U)) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2241U)) & S_BLOCK1], 22U) ^ RotL64(mSnow[((aIndex + 1004U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordF, 48U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1751U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 5227U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 51U)) + 12775735908960052604U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 11791373812080296887U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 11U)) + 5537362877706057303U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 6U)) + RotL64(aCarry, 11U)) + 2023912048504189380U) + RotL64(aNonceWordE, 50U);
            aOrbiterC = (aWandererI + RotL64(aCross, 13U)) + 17668828109963766893U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 558908629933941224U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 57U)) + 1479633119685446888U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 15460320397843364063U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 10059749397555469054U;
            aOrbiterA = (aWandererF + RotL64(aCross, 47U)) + 9987633811929693924U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 4U)) + 10087337844580228269U) + RotL64(aNonceWordG, 9U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4446204415503364254U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9430197906134676162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10611580584157624739U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9327201928815412810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12871947817782057116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11015991745792051390U;
            aOrbiterB = RotL64((aOrbiterB * 17152451500505815031U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6320437975845673731U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterF = RotL64((aOrbiterF * 17491257114676739589U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 16629064896250312921U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6054107387816339103U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6983767878966747219U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13274874838094190290U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12211422735294360321U;
            aOrbiterC = RotL64((aOrbiterC * 5113738196151089817U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15338616110718583619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1475787183754511373U;
            aOrbiterG = RotL64((aOrbiterG * 10904607643785840003U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15486810401396777742U) + RotL64(aNonceWordA, 21U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12775735908960052604U;
            aOrbiterA = RotL64((aOrbiterA * 7478156942468930207U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 6U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 18U)) + RotL64(aNonceWordF, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + RotL64(aNonceWordC, 51U));
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: mSource, mSnow, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 9264U)) & S_BLOCK1], 52U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 6214U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8165U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5931U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 43U)) + 5697928251815176134U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 337587740689259575U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 27U)) + 4927686903263973950U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 23U)) + 3742409032569801033U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 5U)) + 1608092659172197650U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 15848744267145717509U) + RotL64(aNonceWordE, 46U);
            aOrbiterJ = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 15300174177963339253U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 13U)) + 14162868453323648628U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 38U)) + 12020167069983729869U) + RotL64(aNonceWordF, 25U);
            aOrbiterA = (aWandererF + RotL64(aIngress, 11U)) + 16259538291658723956U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + 8516686212464112245U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3722184575520553132U) + RotL64(aNonceWordH, 17U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5663609293306386784U;
            aOrbiterH = RotL64((aOrbiterH * 14364218128780764749U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1093356813820599238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15167726103772238440U;
            aOrbiterF = RotL64((aOrbiterF * 5719466863561311069U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15170797965325981472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14710892030473425181U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 397194787697553904U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1273724124862533034U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4644812473262395329U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9638716186445643730U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7255587739807843785U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6055682981584011189U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9272350563697399628U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1040729335295009339U;
            aOrbiterI = RotL64((aOrbiterI * 17825687660830291443U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12128124729613601747U) + RotL64(aNonceWordD, 13U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2285238815562202219U;
            aOrbiterK = RotL64((aOrbiterK * 15398840993074390573U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6339113298619163493U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5911895708485037040U;
            aOrbiterA = RotL64((aOrbiterA * 3271006139923200439U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7601399508218901328U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5697928251815176134U;
            aOrbiterE = RotL64((aOrbiterE * 8184257916861355735U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 24U)) + aOrbiterD) + RotL64(aNonceWordG, 55U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 40U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aNonceWordC, 49U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterB, 56U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 11894U)) & S_BLOCK1], 60U) ^ RotL64(mSnow[((aIndex + 11619U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11392U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 12578U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 17264605017518259932U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + 15209184354580778643U) + RotL64(aNonceWordC, 61U);
            aOrbiterD = (((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 3299527965014731384U) + RotL64(aNonceWordB, 11U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 5U)) + 16293096431816127821U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 23U)) + 11031983436878828337U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 9188018632448236358U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 41U)) + 13420816400363406556U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 58U)) + 2485063384097917101U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 47U)) + 3089135816938128264U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 53U)) + 10730544971770435788U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 19U)) + 10431767565618874806U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14883796491656899074U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13322163435314643713U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4950101626975919939U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2596253994220103666U;
            aOrbiterG = RotL64((aOrbiterG * 7181706961838582889U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17961706029559914243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10321902557977495175U;
            aOrbiterH = RotL64((aOrbiterH * 16189559888625084711U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18146616411403012772U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterI = RotL64((aOrbiterI * 14879448948196182863U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11739172334166341121U) + RotL64(aNonceWordE, 31U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3160044627483874242U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16816384076887379704U;
            aOrbiterJ = RotL64((aOrbiterJ * 5052772186568301951U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8101560104988710226U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9941784290055185679U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14495651885701938495U;
            aOrbiterE = RotL64((aOrbiterE * 1540692851998143607U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10599676325220702167U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16092000942942971187U) ^ RotL64(aNonceWordH, 28U);
            aOrbiterF = RotL64((aOrbiterF * 2457268192247656817U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16168470945107928109U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17264605017518259932U;
            aOrbiterK = RotL64((aOrbiterK * 15038386057529909273U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 40U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterB) + RotL64(aNonceWordA, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + RotL64(aNonceWordD, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 52U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 23U) ^ RotL64(aNonceWordH, 10U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 21788U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17047U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19167U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21259U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 21U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 19U)) + 10336802574069791273U;
            aOrbiterI = (aWandererD + RotL64(aCross, 23U)) + 169025388197058936U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 27U)) + 6541354188379168846U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 40U)) + 16223920526599306104U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 51U)) + 12756613707692514808U) + RotL64(aNonceWordA, 41U);
            aOrbiterD = (aWandererK + RotL64(aScatter, 29U)) + 5082475548176484035U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 47U)) + 4907435526952698526U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 14236627073831834337U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 5U)) + 11502511046130497584U) + RotL64(aNonceWordC, 45U);
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 3679044835550219497U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 13U)) + 11254838916686736746U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10582608424233200966U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4628253464169957835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17664454668473204465U;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3798386391743884889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9816600392407327227U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4807797577690520554U) + RotL64(aNonceWordE, 17U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2492057261148595922U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7909676419643119585U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 256053568910383007U;
            aOrbiterF = RotL64((aOrbiterF * 11965085163352053161U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16179914439220412472U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3968867762761955845U;
            aOrbiterA = RotL64((aOrbiterA * 7473632378251893139U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7474832923901283742U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4736994731050735779U;
            aOrbiterG = RotL64((aOrbiterG * 9839654409121414047U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 596484364660389193U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13822222274464306169U;
            aOrbiterH = RotL64((aOrbiterH * 1723502278319885511U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16307920280681985443U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3505106171801702915U;
            aOrbiterI = RotL64((aOrbiterI * 8479675421552861243U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4987142580981135150U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10336802574069791273U;
            aOrbiterB = RotL64((aOrbiterB * 2670706512498539705U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterI, 37U)) + RotL64(aNonceWordG, 40U)) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 50U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 4U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26314U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26768U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24643U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 27232U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 40U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 37U)) + 11274974230580265396U;
            aOrbiterD = (aWandererB + RotL64(aCross, 14U)) + 16658438747342741547U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 23U)) + 16612986966106053844U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + 9329502236843231290U) + RotL64(aNonceWordD, 11U);
            aOrbiterA = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 14088261356708344656U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 51U)) + 13692608802007789581U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 6824473946645682398U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 43U)) + 2072915876348570040U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 47U)) + 7420507753044460759U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 4677557318688502593U) + RotL64(aNonceWordC, 9U);
            aOrbiterK = ((aWandererC + RotL64(aScatter, 26U)) + 15081678577055628459U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7026792817486507482U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14871665922943969918U;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6807734532159292872U) + RotL64(aNonceWordB, 14U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9233542707022629190U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1205501586581350876U) ^ RotL64(aNonceWordH, 61U);
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10878718669747466677U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8066049063548639241U;
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 861295180226875235U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7565008208670843555U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6726642007159809594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13541412083111962884U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8617442758729315637U;
            aOrbiterJ = RotL64((aOrbiterJ * 15471862889276160953U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16884403561131293362U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9490680911678221233U;
            aOrbiterC = RotL64((aOrbiterC * 15988763830018001033U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10486145044311386738U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10200001044821063684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16149790736141571017U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6997073594007878034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13585783612009989767U;
            aOrbiterD = RotL64((aOrbiterD * 11425303157774550449U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3847846040256340653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11274974230580265396U;
            aOrbiterA = RotL64((aOrbiterA * 13970270689108369205U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordA, 25U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 20U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterA, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 26U)) + aOrbiterB) + RotL64(aNonceWordE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordE, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 27929U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 32502U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32528U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 30219U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aCross, 53U)) + 3339283916456813609U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 50U)) + 11339086426180649584U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 16819191669329316585U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 5U)) + 8361916937762630725U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 18031328374429899857U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 18261756894092897276U) + RotL64(aNonceWordA, 49U);
            aOrbiterA = (aWandererG + RotL64(aScatter, 39U)) + 4250319792907645666U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 1492411503643460886U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 3U)) + 17369549067879344180U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 11U)) + 7301713524358676722U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 58U)) + 2985193736033012535U) + RotL64(aNonceWordF, 9U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14086975808140927408U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) ^ RotL64(aNonceWordD, 53U);
            aOrbiterK = RotL64((aOrbiterK * 11441293212275890819U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18205555540941493267U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9209505304067579944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3522631966146762306U;
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8811497120829041188U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14707301680850257294U;
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10080595991787801029U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1981637172055758689U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16463077485583119324U;
            aOrbiterC = RotL64((aOrbiterC * 2876782050665869121U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8383837717361569465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2788511294985017326U;
            aOrbiterJ = RotL64((aOrbiterJ * 2809163242875130677U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3529607472855930041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8850940802020173766U;
            aOrbiterE = RotL64((aOrbiterE * 7821450253655655943U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7469160295100147267U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16973986572163482061U;
            aOrbiterH = RotL64((aOrbiterH * 15660743778376905023U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12371372942863279718U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12098525148034303633U;
            aOrbiterG = RotL64((aOrbiterG * 11234127652230231751U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5138683482859889480U) + RotL64(aNonceWordH, 5U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3339283916456813609U;
            aOrbiterF = RotL64((aOrbiterF * 10975353228235695455U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 42U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterF, 12U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + RotL64(aNonceWordB, 23U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 14U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordE, 42U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_A kdf_a_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBA8D9026AFCDD051ULL + 0x97B9C7C14BAC2163ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB9F247DDDF996E15ULL + 0xEC7C30CEC1C0C176ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9233AFC5CEEC6601ULL + 0xF1256BCDFEA62A70ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8C8F7FF0E2BA4B2FULL + 0xA6D26D0E5AE44E20ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEA9789446018181FULL + 0xCB65F999C4EB9A1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD1E8BDC1814C4F29ULL + 0xC7C3F71B9A89A0B2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC9AD42F03F5DC547ULL + 0xDD921456D6B428E6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8C8A6CFD1639E071ULL + 0xC6889C78B7C6C304ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_B kdf_a_loop_b (start)
    {
        // KDF_A_B kdf_a_loop_b lane group
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordB, 52U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 96U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3501U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordC, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2586U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6776U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 6U)) + 12775735908960052604U) + RotL64(aNonceWordB, 51U);
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 21U)) + 11791373812080296887U) + RotL64(aNonceWordF, 61U);
            aOrbiterB = (aWandererK + RotL64(aCross, 57U)) + 5537362877706057303U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 43U)) + 2023912048504189380U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 17668828109963766893U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 558908629933941224U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 34U)) + 1479633119685446888U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 15460320397843364063U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 39U)) + 10059749397555469054U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9987633811929693924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4446204415503364254U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15106063243302192717U) ^ RotL64(aNonceWordH, 16U);
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10611580584157624739U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9327201928815412810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7890659377013147073U;
            aOrbiterF = RotL64((aOrbiterF * 13827717178378062047U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10675114832750356941U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12871947817782057116U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11015991745792051390U;
            aOrbiterD = RotL64((aOrbiterD * 17152451500505815031U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6320437975845673731U) + RotL64(aNonceWordD, 11U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 702457937087191287U;
            aOrbiterE = RotL64((aOrbiterE * 17491257114676739589U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16629064896250312921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6054107387816339103U;
            aOrbiterK = RotL64((aOrbiterK * 6983767878966747219U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 22U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordG, 59U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterH, 58U));
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aNonceWordE, 15U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordB, 40U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9734U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12898U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13796U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12367U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + 17264605017518259932U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 19U)) + 15209184354580778643U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 3299527965014731384U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 57U)) + 16293096431816127821U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 41U)) + 11031983436878828337U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 11U)) + 9188018632448236358U) + RotL64(aNonceWordE, 55U);
            aOrbiterE = (aWandererD + RotL64(aPrevious, 5U)) + 13420816400363406556U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 2485063384097917101U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 60U)) + 3089135816938128264U) + RotL64(aNonceWordF, 25U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10730544971770435788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14883796491656899074U) + RotL64(aNonceWordA, 9U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13322163435314643713U) + RotL64(aNonceWordH, 61U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4950101626975919939U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18146616411403012772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8414050129421955787U;
            aOrbiterG = RotL64((aOrbiterG * 14879448948196182863U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11739172334166341121U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7936637782633487291U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14940929920543800413U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3160044627483874242U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16816384076887379704U;
            aOrbiterB = RotL64((aOrbiterB * 5052772186568301951U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8101560104988710226U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8851416379738817624U;
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aNonceWordG, 19U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 34U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + RotL64(aNonceWordC, 52U));
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterA, 14U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordD, 12U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22134U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21493U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 56U) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24410U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 21671U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 51U)) + 11274974230580265396U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 11U)) + 16658438747342741547U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 16612986966106053844U;
            aOrbiterE = (aWandererC + RotL64(aCross, 60U)) + 9329502236843231290U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 23U)) + 14088261356708344656U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 13692608802007789581U) + RotL64(aNonceWordB, 35U);
            aOrbiterC = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 6824473946645682398U) + RotL64(aNonceWordG, 25U);
            aOrbiterK = ((aWandererG + RotL64(aCross, 46U)) + 2072915876348570040U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 35U)) + 7420507753044460759U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4677557318688502593U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7026792817486507482U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterI = RotL64((aOrbiterI * 694073180313083145U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6807734532159292872U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9233542707022629190U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1205501586581350876U) ^ RotL64(aNonceWordD, 15U);
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10878718669747466677U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8066049063548639241U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterA = RotL64((aOrbiterA * 3031382633089381605U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 861295180226875235U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterJ = RotL64((aOrbiterJ * 7565008208670843555U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6726642007159809594U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8061661744643240470U;
            aOrbiterC = RotL64((aOrbiterC * 6703498926835391813U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13541412083111962884U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8617442758729315637U;
            aOrbiterK = RotL64((aOrbiterK * 15471862889276160953U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16884403561131293362U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9490680911678221233U;
            aOrbiterH = RotL64((aOrbiterH * 15988763830018001033U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 12U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 20U)) + aOrbiterH) + RotL64(aNonceWordH, 40U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aNonceWordF, 49U));
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 27U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28533U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27388U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordD, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25240U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31979U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 20U)) + 3339283916456813609U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 43U)) + 11339086426180649584U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 29U)) + 16819191669329316585U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 51U)) + 8361916937762630725U) + RotL64(aNonceWordB, 51U);
            aOrbiterB = (aWandererH + RotL64(aIngress, 35U)) + 18031328374429899857U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 47U)) + 18261756894092897276U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 4250319792907645666U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 39U)) + 1492411503643460886U;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 17369549067879344180U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7301713524358676722U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2985193736033012535U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14086975808140927408U) + RotL64(aNonceWordH, 12U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18205555540941493267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9209505304067579944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3522631966146762306U;
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8811497120829041188U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14707301680850257294U;
            aOrbiterG = RotL64((aOrbiterG * 11383709499376464085U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 10080595991787801029U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordE, 59U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6822892187784299166U;
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1981637172055758689U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16463077485583119324U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2876782050665869121U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8383837717361569465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3529607472855930041U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8850940802020173766U;
            aOrbiterK = RotL64((aOrbiterK * 7821450253655655943U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 56U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + RotL64(aNonceWordA, 15U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 54U)) + RotL64(aNonceWordF, 49U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_B kdf_a_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC288D03CED255ACBULL + 0xBF6553DB0EECCB0CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x98B96FEBD8455D5FULL + 0xFE4076B231B91714ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xABC15A674D30C573ULL + 0xF8049D5539C242FBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8DC2560CBE08DC7BULL + 0xD115C21AADDBC82AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x85CC3CD55C93C983ULL + 0xC20BBA8C6103B874ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE475B9CF9E47AEEFULL + 0xBF810BF9899CACE9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD81B56BA7C77BB3DULL + 0xD009A990171087CEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEF5CCB0CC2C23763ULL + 0x98E5AA6C5CC67EAAULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_C kdf_a_loop_c (start)
    {
        // KDF_A_C kdf_a_loop_c lane group
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 50U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4324U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 177U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordC, 44U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3316U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 3021U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 5U)) + 12775735908960052604U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 48U)) + 11791373812080296887U) + RotL64(aNonceWordA, 27U);
            aOrbiterC = (aWandererH + RotL64(aScatter, 13U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 53U)) + 2023912048504189380U) + RotL64(aNonceWordB, 45U);
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 35U)) + 17668828109963766893U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 558908629933941224U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 1479633119685446888U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 23U)) + 15460320397843364063U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 28U)) + RotL64(aCarry, 11U)) + 10059749397555469054U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9987633811929693924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterC = RotL64((aOrbiterC * 13817142288940843815U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4446204415503364254U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10611580584157624739U) + RotL64(aNonceWordE, 40U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3137391249289641509U;
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9327201928815412810U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7890659377013147073U;
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10675114832750356941U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8804440385852327267U;
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12871947817782057116U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17152451500505815031U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6320437975845673731U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 702457937087191287U;
            aOrbiterA = RotL64((aOrbiterA * 17491257114676739589U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16629064896250312921U) + RotL64(aNonceWordH, 3U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6054107387816339103U;
            aOrbiterJ = RotL64((aOrbiterJ * 6983767878966747219U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 6U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aNonceWordG, 61U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aNonceWordD, 17U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 44U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordB, 26U)) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10166U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14660U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordF, 38U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8854U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13320U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 60U)) + 3339283916456813609U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 11339086426180649584U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + 16819191669329316585U) + RotL64(aNonceWordC, 25U);
            aOrbiterG = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 8361916937762630725U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 39U)) + 18031328374429899857U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 43U)) + 18261756894092897276U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 4250319792907645666U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 34U)) + 1492411503643460886U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aScatter, 3U)) + 17369549067879344180U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 7301713524358676722U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 3U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 18205555540941493267U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 9209505304067579944U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordE, 21U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8811497120829041188U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10080595991787801029U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6822892187784299166U;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1981637172055758689U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16463077485583119324U;
            aOrbiterG = RotL64((aOrbiterG * 2876782050665869121U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8383837717361569465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3529607472855930041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8850940802020173766U;
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordB, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 12U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + RotL64(aNonceWordD, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20158U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 16686U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordF, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23212U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23310U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 14U)) + 11274974230580265396U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 5U)) + 16658438747342741547U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 51U)) + 16612986966106053844U) + RotL64(aNonceWordB, 41U);
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 23U)) + 9329502236843231290U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 14088261356708344656U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 60U)) + 13692608802007789581U) + RotL64(aNonceWordD, 15U);
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 6824473946645682398U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 2072915876348570040U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 47U)) + 7420507753044460759U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4677557318688502593U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7026792817486507482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6807734532159292872U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9233542707022629190U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1205501586581350876U;
            aOrbiterD = RotL64((aOrbiterD * 2596053290311090589U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 10878718669747466677U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordF, 54U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 861295180226875235U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9134969787937288583U;
            aOrbiterC = RotL64((aOrbiterC * 7565008208670843555U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6726642007159809594U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8061661744643240470U;
            aOrbiterA = RotL64((aOrbiterA * 6703498926835391813U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13541412083111962884U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8617442758729315637U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15471862889276160953U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16884403561131293362U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9490680911678221233U) ^ RotL64(aNonceWordG, 45U);
            aOrbiterJ = RotL64((aOrbiterJ * 15988763830018001033U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 46U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordH, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 12U)) + aOrbiterB) + RotL64(aNonceWordC, 61U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordD, 29U)) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30595U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 32071U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30988U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((aIndex + 30172U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aScatter, 43U)) + 5697928251815176134U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterC = (aWandererJ + RotL64(aIngress, 60U)) + 337587740689259575U;
            aOrbiterD = (aWandererG + RotL64(aCross, 39U)) + 4927686903263973950U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 51U)) + 3742409032569801033U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 47U)) + 1608092659172197650U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 57U)) + 15848744267145717509U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 15300174177963339253U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14162868453323648628U) + RotL64(aNonceWordD, 4U);
            aOrbiterG = (aWandererE + RotL64(aScatter, 27U)) + 12020167069983729869U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16259538291658723956U) + RotL64(aNonceWordB, 27U);
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordG, 61U);
            aOrbiterD = RotL64((aOrbiterD * 4731296903548893627U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3722184575520553132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15265344442454471986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1093356813820599238U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15170797965325981472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterE = RotL64((aOrbiterE * 11186808881726573677U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14710892030473425181U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1273724124862533034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13018397560392545616U;
            aOrbiterB = RotL64((aOrbiterB * 4644812473262395329U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9638716186445643730U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7255587739807843785U;
            aOrbiterG = RotL64((aOrbiterG * 6055682981584011189U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9272350563697399628U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1040729335295009339U;
            aOrbiterC = RotL64((aOrbiterC * 17825687660830291443U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 22U) + aOrbiterK) + RotL64(aOrbiterD, 6U)) + RotL64(aNonceWordA, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordF, 17U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 52U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_C kdf_a_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC842F952D38BBB2DULL + 0x967566A1D2542FA9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD3FA4B745A171185ULL + 0xA6C16302D3DB70FEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD21695BCCE284AC3ULL + 0xB3E646814991FE2FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAEA410F0E0F7902DULL + 0x9A89E3B111AD13F4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x820889930819C8EDULL + 0x8485FE07BE49E27FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCE86645D67D15089ULL + 0x992DE71B7276B150ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFC661B34CFC2F28FULL + 0x861604540741E606ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA94D2EEE98961227ULL + 0xD51455AC1021DB06ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_D kdf_a_loop_d (start)
    {
        // KDF_A_D kdf_a_loop_d lane group
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordC, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5058U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7347U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5578U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3864U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 20U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 46U)) + RotL64(aCarry, 51U)) + 5697928251815176134U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 27U)) + 337587740689259575U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterA = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 4927686903263973950U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 3742409032569801033U) + RotL64(aNonceWordA, 3U);
            aOrbiterD = ((aWandererC + RotL64(aIngress, 13U)) + 1608092659172197650U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15848744267145717509U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 15300174177963339253U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ RotL64(aNonceWordH, 27U);
            aOrbiterA = RotL64((aOrbiterA * 5771922862677667319U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14162868453323648628U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12020167069983729869U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2071080217680099017U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 16259538291658723956U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 54U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterC = RotL64((aOrbiterC * 4731296903548893627U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3722184575520553132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15265344442454471986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 22U)) + aOrbiterC) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + RotL64(aCarry, 37U)) + RotL64(aNonceWordC, 5U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordA, 53U)) ^ RotL64(aNonceWordE, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10676U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15896U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordB, 26U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11471U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 14717U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 12U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 12775735908960052604U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 11791373812080296887U) + RotL64(aNonceWordH, 39U);
            aOrbiterG = (aWandererB + RotL64(aPrevious, 13U)) + 5537362877706057303U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 53U)) + 2023912048504189380U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 57U)) + 17668828109963766893U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 558908629933941224U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1479633119685446888U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4447153373540811385U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15460320397843364063U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10059749397555469054U;
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9987633811929693924U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterA = RotL64((aOrbiterA * 13817142288940843815U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4446204415503364254U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15106063243302192717U) ^ RotL64(aNonceWordF, 15U);
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 9430197906134676162U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 41U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 58U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + RotL64(aOrbiterH, 35U)) + aOrbiterD) + RotL64(aCarry, 57U)) + RotL64(aNonceWordE, 56U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 60U)) + aOrbiterG) + RotL64(aNonceWordC, 45U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 60U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20240U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23416U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24569U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 20333U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 56U)) + 3339283916456813609U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordD, 39U);
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 11339086426180649584U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 21U)) + 16819191669329316585U;
            aOrbiterE = ((((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 8361916937762630725U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 12U);
            aOrbiterG = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 18031328374429899857U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 18261756894092897276U) + RotL64(aNonceWordH, 59U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4250319792907645666U) ^ RotL64(aNonceWordF, 57U);
            aOrbiterI = RotL64((aOrbiterI * 7053489184750217963U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1492411503643460886U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17369549067879344180U;
            aOrbiterF = RotL64((aOrbiterF * 2947354306696216579U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7301713524358676722U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14086975808140927408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 18205555540941493267U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterE, 54U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 43U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aNonceWordC, 55U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26785U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 25033U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordF, 14U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32681U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 31997U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 10336802574069791273U) + RotL64(aNonceWordA, 14U);
            aOrbiterH = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 169025388197058936U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((((aWandererF + RotL64(aCross, 38U)) + RotL64(aCarry, 39U)) + 6541354188379168846U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 13U);
            aOrbiterI = (aWandererK + RotL64(aPrevious, 3U)) + 16223920526599306104U;
            aOrbiterB = (aWandererG + RotL64(aCross, 57U)) + 12756613707692514808U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5082475548176484035U) + RotL64(aNonceWordE, 35U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4907435526952698526U;
            aOrbiterG = RotL64((aOrbiterG * 1379692095754989215U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14236627073831834337U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11502511046130497584U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3679044835550219497U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordH, 31U);
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10582608424233200966U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4628253464169957835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17664454668473204465U;
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aNonceWordF, 11U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 11U)) + RotL64(aNonceWordG, 5U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 6U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_D kdf_a_loop_d (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF24E8E7A550FE7F7ULL + 0xDB738FDEEAF0C3ECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF489389345DE6051ULL + 0xEDB90345E649D11AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8C375983E621987DULL + 0x96A3CDA91EE0BCAEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB75603ECF6E2B7B7ULL + 0xB88ACD53B5741A83ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCD24761BAE69C9D1ULL + 0xF80D0593CFEA0318ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA2DE07C7108A20CDULL + 0xA961214207601BBAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAB768CA641D1736FULL + 0x8E4C3346B87CA88FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEC63B95E1FB25781ULL + 0xE2284FCF8CDEFBBEULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_A kdf_b_loop_a (start)
    {
        // KDF_B_A kdf_b_loop_a lane group
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 42U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4275U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 4574U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordG, 18U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6829U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 253U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 38U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aIngress, 5U)) + 12775735908960052604U;
            aOrbiterG = (aWandererG + RotL64(aCross, 35U)) + 11791373812080296887U;
            aOrbiterB = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 5537362877706057303U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterD = ((((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 5U)) + 2023912048504189380U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 17U);
            aOrbiterI = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 17668828109963766893U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 558908629933941224U) + RotL64(aNonceWordC, 11U);
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 1479633119685446888U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordH, 3U);
            aOrbiterB = RotL64((aOrbiterB * 4447153373540811385U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15460320397843364063U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10059749397555469054U;
            aOrbiterJ = RotL64((aOrbiterJ * 8671817118586065469U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9987633811929693924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4446204415503364254U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9430197906134676162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aNonceWordG, 59U));
            aWandererD = aWandererD + (((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 36U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 10U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererE, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 48U) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10736U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11391U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordE, 6U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14091U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11246U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + 17264605017518259932U) + RotL64(aNonceWordA, 51U);
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 15209184354580778643U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 39U)) + 3299527965014731384U) + RotL64(aNonceWordD, 41U);
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 16293096431816127821U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 11031983436878828337U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9188018632448236358U) + RotL64(aNonceWordH, 26U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13420816400363406556U;
            aOrbiterE = RotL64((aOrbiterE * 10958221259662190519U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2485063384097917101U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10730544971770435788U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14883796491656899074U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13465877783538483706U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13322163435314643713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 4U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + RotL64(aNonceWordE, 57U));
            aWandererG = aWandererG + (((((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordH, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24329U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 22390U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordG, 12U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22855U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 22696U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 4U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 11274974230580265396U) + RotL64(aNonceWordA, 16U);
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 16658438747342741547U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 19U);
            aOrbiterF = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 16612986966106053844U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 9329502236843231290U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 52U)) + 14088261356708344656U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13692608802007789581U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6824473946645682398U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13619437545775237601U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2072915876348570040U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7420507753044460759U;
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4677557318688502593U) + RotL64(aNonceWordH, 45U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15081678577055628459U;
            aOrbiterA = RotL64((aOrbiterA * 16659305295251177155U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7026792817486507482U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 6807734532159292872U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordC, 53U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17882797335141303280U;
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + RotL64(aNonceWordB, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aNonceWordE, 23U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 12U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27691U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28805U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordC, 4U)) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30123U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32557U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 38U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 3U)) + 3339283916456813609U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordC, 39U);
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 27U)) + 11339086426180649584U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 16819191669329316585U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + 8361916937762630725U) + RotL64(aNonceWordB, 57U);
            aOrbiterC = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 18031328374429899857U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18261756894092897276U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4250319792907645666U;
            aOrbiterF = RotL64((aOrbiterF * 7053489184750217963U), 41U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 1492411503643460886U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 56U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17369549067879344180U;
            aOrbiterJ = RotL64((aOrbiterJ * 2947354306696216579U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7301713524358676722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2985193736033012535U;
            aOrbiterD = RotL64((aOrbiterD * 7473297294949338265U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14086975808140927408U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18205555540941493267U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ RotL64(aNonceWordE, 43U);
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 36U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 13U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + RotL64(aNonceWordH, 11U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterC, 60U)) + RotL64(aNonceWordG, 59U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_B_A kdf_b_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDE92C297928349CDULL + 0xA18194DED395BD40ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF64CD024F6DE15BFULL + 0x80A3B9EECC46A7A1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDDCEDBD9A91537E3ULL + 0x9BF372AB7DB89696ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x83E402835A20153DULL + 0xB946013291D6A1FCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD25A65D6241C06AFULL + 0xB0D96CA4B4F3B2CCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x98523851DE529D8DULL + 0xFF254C2CFCBFA096ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEB299D22BFE4EF75ULL + 0xF99E5CB0749B5B44ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF5F7F9419954989ULL + 0xE05C9214A8AC5EBAULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_B kdf_b_loop_b (start)
    {
        // KDF_B_B kdf_b_loop_b lane group
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 53U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2460U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6927U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7947U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 2485U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 11274974230580265396U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 16658438747342741547U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 16612986966106053844U) + RotL64(aNonceWordA, 17U);
            aOrbiterH = ((aWandererI + RotL64(aIngress, 19U)) + 9329502236843231290U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 14088261356708344656U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 41U)) + 13692608802007789581U) + RotL64(aNonceWordB, 51U);
            aOrbiterB = ((aWandererA + RotL64(aIngress, 54U)) + 6824473946645682398U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2072915876348570040U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13239288539564571257U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4677557318688502593U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ RotL64(aNonceWordG, 42U);
            aOrbiterC = RotL64((aOrbiterC * 16659305295251177155U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7026792817486507482U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterF = RotL64((aOrbiterF * 694073180313083145U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6807734532159292872U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17882797335141303280U;
            aOrbiterB = RotL64((aOrbiterB * 15439872930381050291U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9233542707022629190U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1205501586581350876U;
            aOrbiterE = RotL64((aOrbiterE * 2596053290311090589U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10878718669747466677U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8066049063548639241U) ^ RotL64(aNonceWordF, 47U);
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 861295180226875235U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7565008208670843555U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 56U)) + aOrbiterB) + RotL64(aCarry, 27U)) + RotL64(aNonceWordE, 7U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordC, 49U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 51U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10566U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 10196U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 50U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8638U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10692U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 5697928251815176134U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + 337587740689259575U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 4927686903263973950U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 18U)) + 3742409032569801033U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 37U)) + 1608092659172197650U) + RotL64(aNonceWordA, 51U);
            aOrbiterI = ((((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 15848744267145717509U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 24U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 5U)) + 15300174177963339253U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14162868453323648628U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12020167069983729869U;
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16259538291658723956U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8516686212464112245U) ^ RotL64(aNonceWordG, 59U);
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3722184575520553132U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordD, 57U);
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15265344442454471986U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1093356813820599238U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15170797965325981472U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11186808881726573677U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14710892030473425181U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + RotL64(aNonceWordB, 55U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + RotL64(aNonceWordE, 49U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 14U) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19278U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16787U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 44U) ^ RotL64(aNonceWordE, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16654U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 17561U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 39U)) + 12775735908960052604U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 29U)) + 11791373812080296887U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 60U)) + 5537362877706057303U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 2023912048504189380U;
            aOrbiterB = ((((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 17668828109963766893U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordB, 43U);
            aOrbiterI = (aWandererI + RotL64(aCross, 51U)) + 558908629933941224U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 1479633119685446888U) + RotL64(aNonceWordE, 45U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15460320397843364063U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10059749397555469054U;
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9987633811929693924U) + RotL64(aNonceWordG, 61U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4446204415503364254U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15106063243302192717U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9430197906134676162U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10611580584157624739U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3137391249289641509U;
            aOrbiterB = RotL64((aOrbiterB * 5462682413239873181U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9327201928815412810U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordA, 55U);
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10675114832750356941U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aNonceWordF, 50U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterJ, 22U)) + RotL64(aNonceWordH, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 42U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31319U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 29738U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordE, 23U)) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26737U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 28354U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 51U)) + 17264605017518259932U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 43U)) + 15209184354580778643U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 57U)) + 3299527965014731384U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 16293096431816127821U) + RotL64(aNonceWordE, 31U);
            aOrbiterA = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 11031983436878828337U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 6U)) + 9188018632448236358U) + RotL64(aNonceWordD, 58U);
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 13420816400363406556U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2485063384097917101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3089135816938128264U;
            aOrbiterK = RotL64((aOrbiterK * 8813152992957361153U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10730544971770435788U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10431767565618874806U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14883796491656899074U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13322163435314643713U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4950101626975919939U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7181706961838582889U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17961706029559914243U) + RotL64(aNonceWordH, 29U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10321902557977495175U;
            aOrbiterF = RotL64((aOrbiterF * 16189559888625084711U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18146616411403012772U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8414050129421955787U) ^ RotL64(aNonceWordG, 49U);
            aOrbiterB = RotL64((aOrbiterB * 14879448948196182863U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 56U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + RotL64(aNonceWordB, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 61U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_B_B kdf_b_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF1F993E5C273C44FULL + 0x8F28538DACD01703ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE07A8F374C1F0CA3ULL + 0x90A60229DB52BDB2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCDD1304CF2A82993ULL + 0xAAC2F08EFE1DA7E3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9C97064EB46CC1F1ULL + 0xF52C6DBC86E93B7DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCB56FD176E188559ULL + 0xAF208E8AB2162EA1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x811D801F02D7684FULL + 0x99F47DEC34507A3DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A85ACD1270FAAAFULL + 0x8FDA0C360C49F211ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBE47AAEBDBC6B0DBULL + 0xECE625AAD891A041ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_C kdf_b_loop_c (start)
    {
        // KDF_B_C kdf_b_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3718U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1078U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5279U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4140U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 17264605017518259932U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 52U)) + 15209184354580778643U;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 3299527965014731384U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 19U)) + 16293096431816127821U) + RotL64(aNonceWordG, 41U);
            aOrbiterI = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 11031983436878828337U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 41U)) + 9188018632448236358U) + RotL64(aNonceWordC, 61U);
            aOrbiterA = (aWandererB + RotL64(aCross, 24U)) + 13420816400363406556U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 2485063384097917101U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 3089135816938128264U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10730544971770435788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14883796491656899074U) + RotL64(aNonceWordA, 55U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13322163435314643713U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4950101626975919939U) + RotL64(aNonceWordF, 7U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2596253994220103666U;
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18146616411403012772U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11739172334166341121U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3160044627483874242U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16816384076887379704U;
            aOrbiterD = RotL64((aOrbiterD * 5052772186568301951U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8101560104988710226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8851416379738817624U;
            aOrbiterI = RotL64((aOrbiterI * 16767420038937389027U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aNonceWordB, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + RotL64(aNonceWordH, 10U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 22U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 50U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8086U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6860U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordE, 60U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7368U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5925U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aScatter, 34U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 16658438747342741547U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + 16612986966106053844U) + RotL64(aNonceWordB, 54U);
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 13U)) + 9329502236843231290U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 39U)) + 14088261356708344656U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 57U)) + 13692608802007789581U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 4U)) + 6824473946645682398U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 2072915876348570040U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 7420507753044460759U) + RotL64(aNonceWordE, 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4677557318688502593U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7026792817486507482U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14871665922943969918U;
            aOrbiterA = RotL64((aOrbiterA * 694073180313083145U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6807734532159292872U) + RotL64(aNonceWordC, 61U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9233542707022629190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1205501586581350876U;
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10878718669747466677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8066049063548639241U;
            aOrbiterK = RotL64((aOrbiterK * 3031382633089381605U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 861295180226875235U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9134969787937288583U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterE = RotL64((aOrbiterE * 7565008208670843555U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6726642007159809594U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13541412083111962884U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8617442758729315637U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15471862889276160953U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16884403561131293362U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9490680911678221233U;
            aOrbiterF = RotL64((aOrbiterF * 15988763830018001033U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 28U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aNonceWordA, 9U));
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 14U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterH) + RotL64(aNonceWordH, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 36U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 48U) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15558U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15277U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11915U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 14867U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 51U)) + 12775735908960052604U) + RotL64(aNonceWordB, 41U);
            aOrbiterH = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 11791373812080296887U) + RotL64(aNonceWordD, 23U);
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 56U)) + RotL64(aCarry, 19U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 2023912048504189380U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 17668828109963766893U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 3U)) + 558908629933941224U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 11U)) + 1479633119685446888U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 15460320397843364063U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 24U)) + 10059749397555469054U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9987633811929693924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10087337844580228269U;
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9430197906134676162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1226048679997253363U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10611580584157624739U) + RotL64(aNonceWordA, 39U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9327201928815412810U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10675114832750356941U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8804440385852327267U;
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12871947817782057116U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17152451500505815031U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6320437975845673731U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 702457937087191287U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17491257114676739589U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16629064896250312921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6054107387816339103U;
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 10U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 24U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 40U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterI, 48U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aNonceWordH, 7U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 30U) ^ RotL64(aNonceWordC, 51U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20713U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21395U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordF, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16742U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 19010U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 5697928251815176134U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 337587740689259575U;
            aOrbiterF = (aWandererB + RotL64(aCross, 40U)) + 4927686903263973950U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 3742409032569801033U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 27U)) + 1608092659172197650U) + RotL64(aNonceWordB, 39U);
            aOrbiterB = ((aWandererA + RotL64(aCross, 13U)) + 15848744267145717509U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + 15300174177963339253U) + RotL64(aNonceWordF, 9U);
            aOrbiterC = (((aWandererI + RotL64(aIngress, 4U)) + RotL64(aCarry, 3U)) + 14162868453323648628U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 12020167069983729869U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16259538291658723956U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8516686212464112245U) ^ RotL64(aNonceWordH, 45U);
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3722184575520553132U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5663609293306386784U) ^ RotL64(aNonceWordA, 22U);
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15265344442454471986U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1093356813820599238U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15170797965325981472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterI = RotL64((aOrbiterI * 11186808881726573677U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14710892030473425181U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1273724124862533034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13018397560392545616U;
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9272350563697399628U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1040729335295009339U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 26U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterI, 24U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordG, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordE, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 10U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23468U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 23225U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 14U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24172U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 26634U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 23U)) + 3339283916456813609U) + RotL64(aNonceWordD, 45U);
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 11339086426180649584U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 16819191669329316585U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 10U)) + 8361916937762630725U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            aOrbiterA = (aWandererE + RotL64(aPrevious, 27U)) + 18031328374429899857U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 18261756894092897276U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 43U)) + 4250319792907645666U;
            aOrbiterH = (aWandererF + RotL64(aCross, 53U)) + 1492411503643460886U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 48U)) + 17369549067879344180U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7301713524358676722U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14086975808140927408U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18205555540941493267U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterH = RotL64((aOrbiterH * 3009081009044782443U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9209505304067579944U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3522631966146762306U) ^ RotL64(aNonceWordE, 49U);
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8811497120829041188U) + RotL64(aNonceWordA, 23U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10080595991787801029U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1981637172055758689U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16463077485583119324U;
            aOrbiterB = RotL64((aOrbiterB * 2876782050665869121U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8383837717361569465U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2788511294985017326U;
            aOrbiterG = RotL64((aOrbiterG * 2809163242875130677U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3529607472855930041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7821450253655655943U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 54U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 60U)) + aOrbiterB) + RotL64(aNonceWordH, 34U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aIngress, 26U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 26U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 18U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29415U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27820U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 26U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordH, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32252U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30543U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 30U)) + RotL64(aCarry, 41U)) + 10336802574069791273U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 11U)) + 169025388197058936U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 21U)) + 6541354188379168846U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 16223920526599306104U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 5U)) + 12756613707692514808U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 41U)) + 5082475548176484035U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordD, 11U);
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 4907435526952698526U) + RotL64(aNonceWordE, 6U);
            aOrbiterG = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 14236627073831834337U;
            aOrbiterC = (aWandererB + RotL64(aCross, 46U)) + 11502511046130497584U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3679044835550219497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 10582608424233200966U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordB, 57U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4628253464169957835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9816600392407327227U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16781971616348376878U;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4807797577690520554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2492057261148595922U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7909676419643119585U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 256053568910383007U;
            aOrbiterH = RotL64((aOrbiterH * 11965085163352053161U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16179914439220412472U) + RotL64(aNonceWordF, 47U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3968867762761955845U;
            aOrbiterD = RotL64((aOrbiterD * 7473632378251893139U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7474832923901283742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 60U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 31U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 22U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aNonceWordG, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
        }
    }
    // KDF_B_C kdf_b_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
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
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD64B06DDFD1B5923ULL + 0xE3CD144B6010C7D0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8D607B3D296361F9ULL + 0xB81097D92D159E5BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9180FE228F1470BDULL + 0xC50F9B6374BE25E0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBD01035B2AF38D3FULL + 0xFB38B852B9435E0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC65E95127543F65FULL + 0x95369A48C8BDFF5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB9A5576D8C801F33ULL + 0xC083AEAD6B376AABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x910769FC74DA5B6BULL + 0xE1E4C1754165EDDEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDDED81C4A244AD13ULL + 0xE22FBCB9B1C60628ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2312U)) & S_BLOCK1], 26U) ^ RotL64(aKeyBoxUnrolledA[((aIndex + 479U)) & (S_KEY_A - 1)], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 417U)) & (S_KEY_B - 1)], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6940U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 28U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 27U)) + 17264605017518259932U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 15209184354580778643U;
            aOrbiterD = (aWandererH + RotL64(aCross, 51U)) + 3299527965014731384U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 11U)) + 16293096431816127821U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + 11031983436878828337U) + RotL64(aNonceWordD, 9U);
            aOrbiterB = ((((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 9188018632448236358U) + aPhaseAOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordB, 35U);
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 13420816400363406556U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2485063384097917101U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3089135816938128264U;
            aOrbiterD = RotL64((aOrbiterD * 8813152992957361153U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10730544971770435788U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14883796491656899074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13465877783538483706U;
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 58U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3307316600284371955U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4950101626975919939U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2596253994220103666U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterI = RotL64((aOrbiterI * 7181706961838582889U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17961706029559914243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18146616411403012772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8414050129421955787U;
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aNonceWordF, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + (((((RotL64(aCross, 28U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 49U)) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 60U) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10200U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15603U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordC, 41U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 11231U)) & (S_KEY_A - 1)], 21U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 9902U)) & (S_KEY_B - 1)], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 12775735908960052604U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 11791373812080296887U) + aPhaseAOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 4U)) + 5537362877706057303U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 2023912048504189380U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 51U)) + 17668828109963766893U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 558908629933941224U) + RotL64(aNonceWordC, 5U);
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 21U)) + 1479633119685446888U) + RotL64(aNonceWordD, 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15460320397843364063U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10059749397555469054U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8671817118586065469U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9987633811929693924U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4446204415503364254U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15106063243302192717U;
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1226048679997253363U) ^ RotL64(aNonceWordE, 43U);
            aOrbiterD = RotL64((aOrbiterD * 14247538885252664127U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10611580584157624739U) + RotL64(aNonceWordH, 39U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3137391249289641509U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9327201928815412810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7890659377013147073U;
            aOrbiterA = RotL64((aOrbiterA * 13827717178378062047U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10675114832750356941U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8804440385852327267U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 34U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 17U)) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 22U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + RotL64(aNonceWordA, 50U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19139U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18324U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 60U) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 24356U)) & (S_KEY_A - 1)], 29U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 17099U)) & (S_KEY_B - 1)], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 28U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 3339283916456813609U) + RotL64(aNonceWordA, 27U);
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 50U)) + 11339086426180649584U) + aPhaseAOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 35U)) + 16819191669329316585U) + RotL64(aNonceWordE, 39U);
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + 8361916937762630725U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 13U)) + 18031328374429899857U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 18261756894092897276U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 4250319792907645666U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1492411503643460886U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17369549067879344180U;
            aOrbiterA = RotL64((aOrbiterA * 2947354306696216579U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7301713524358676722U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2985193736033012535U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14086975808140927408U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10390516547834639800U;
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18205555540941493267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9209505304067579944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8811497120829041188U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14707301680850257294U) ^ RotL64(aNonceWordC, 8U);
            aOrbiterG = RotL64((aOrbiterG * 11383709499376464085U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10080595991787801029U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6822892187784299166U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordB, 61U);
            aOrbiterK = RotL64((aOrbiterK * 7417016898027778287U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + RotL64(aNonceWordD, 59U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordF, 7U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 20U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 22U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28172U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29144U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30365U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26308U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 35U)) + 5697928251815176134U) + RotL64(aNonceWordC, 27U);
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 337587740689259575U) + RotL64(aNonceWordF, 17U);
            aOrbiterC = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 4927686903263973950U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 11U)) + 3742409032569801033U) + aPhaseAOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 1608092659172197650U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 15848744267145717509U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 21U)) + 15300174177963339253U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14162868453323648628U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12020167069983729869U;
            aOrbiterC = RotL64((aOrbiterC * 2071080217680099017U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16259538291658723956U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8516686212464112245U) ^ RotL64(aNonceWordB, 48U);
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3722184575520553132U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15265344442454471986U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 3050323350098829515U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ RotL64(aNonceWordH, 53U);
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1093356813820599238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15167726103772238440U;
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15170797965325981472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14710892030473425181U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 397194787697553904U;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + RotL64(aNonceWordA, 13U));
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aNonceWordE, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAAA1A04DE0C354CBULL + 0xAF15D412C9145F36ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDE2BD55A6DA7316DULL + 0x97B61972F2BD0288ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBDEBC3503D0D604DULL + 0x88A40485096AD08AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC81950A711984E3DULL + 0xC1AFB8D84011CE07ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE31D1AA5BE2390BFULL + 0xBFD8D2655E1E46C1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA008145D5DC40491ULL + 0xAA8A4F61DF291815ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE24E3A67C9A41389ULL + 0x86FD004EF95C060FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD4122CC3C8A4A165ULL + 0xF9D32410BCA470EBULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3311U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 5869U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1212U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2989U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 12775735908960052604U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 21U)) + 11791373812080296887U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 29U)) + 5537362877706057303U) + aPhaseBOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterH = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 2023912048504189380U) + RotL64(aNonceWordC, 5U);
            aOrbiterE = ((aWandererE + RotL64(aScatter, 42U)) + RotL64(aCarry, 37U)) + 17668828109963766893U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 558908629933941224U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1479633119685446888U) ^ RotL64(aNonceWordA, 9U);
            aOrbiterA = RotL64((aOrbiterA * 4447153373540811385U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15460320397843364063U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordH, 6U);
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9987633811929693924U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10087337844580228269U;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 29U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aPhaseBWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 13U)) + RotL64(aNonceWordG, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordG, 23U)) ^ RotL64(aNonceWordB, 44U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14126U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 15882U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9615U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9852U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 44U) + RotL64(aCross, 29U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 3339283916456813609U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + 11339086426180649584U) + RotL64(aNonceWordC, 35U);
            aOrbiterH = (((aWandererB + RotL64(aIngress, 37U)) + 16819191669329316585U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterA = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 8361916937762630725U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 18031328374429899857U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18261756894092897276U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4250319792907645666U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7053489184750217963U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1492411503643460886U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17369549067879344180U;
            aOrbiterB = RotL64((aOrbiterB * 2947354306696216579U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7301713524358676722U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2985193736033012535U;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14086975808140927408U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 18205555540941493267U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordD, 44U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16967799565443938873U) ^ RotL64(aNonceWordF, 39U);
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordA, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 52U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordH, 61U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24176U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 22726U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23479U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 21842U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 10336802574069791273U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 5U)) + 169025388197058936U) + RotL64(aNonceWordE, 35U);
            aOrbiterK = (((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 16223920526599306104U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 29U)) + 12756613707692514808U) + RotL64(aNonceWordA, 31U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5082475548176484035U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4907435526952698526U;
            aOrbiterK = RotL64((aOrbiterK * 1379692095754989215U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14236627073831834337U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11502511046130497584U;
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3679044835550219497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10582608424233200966U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10449735026385340313U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4628253464169957835U) + RotL64(aNonceWordG, 5U);
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 17664454668473204465U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordF, 40U);
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 13U)) + RotL64(aNonceWordD, 61U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + aPhaseBWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 22U)) + RotL64(aNonceWordH, 43U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32140U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 30291U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordC, 12U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26788U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 28399U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 41U)) + 5697928251815176134U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 337587740689259575U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 35U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 18U);
            aOrbiterE = ((((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 3742409032569801033U) + aPhaseBOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterB = (aWandererA + RotL64(aIngress, 3U)) + 1608092659172197650U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15848744267145717509U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15300174177963339253U;
            aOrbiterI = RotL64((aOrbiterI * 5771922862677667319U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14162868453323648628U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12020167069983729869U) ^ RotL64(aNonceWordB, 35U);
            aOrbiterG = RotL64((aOrbiterG * 2071080217680099017U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16259538291658723956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3722184575520553132U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5663609293306386784U;
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15265344442454471986U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 3050323350098829515U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordE, 61U);
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordA, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererA = aWandererA + (((((RotL64(aCross, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aCarry, 19U)) + RotL64(aNonceWordF, 13U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterJ, 10U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x85D897584C464BAFULL + 0xB841D0555FCBA883ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD1954A38C3BF5B35ULL + 0xFCE232BB33D2FCA7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE49E6855BD2B64E1ULL + 0x8000CF741D516B3FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA045A2560769740FULL + 0x974E5A8AA8BBE0BDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA87A3B9BA3D30983ULL + 0x8611484D04773543ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA0F1E88B29791D2DULL + 0xDE42B434B4FCA933ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8D431CAAB84E647BULL + 0xECB94D50ED237056ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xABBF34F6094D740DULL + 0xC6F55C7A9FBA65ACULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3032U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 4376U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 20U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7002U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7086U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 10336802574069791273U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 6U)) + 169025388197058936U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 6541354188379168846U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 16223920526599306104U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 12756613707692514808U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 24U)) + 5082475548176484035U) + RotL64(aNonceWordA, 23U);
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 43U)) + 4907435526952698526U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordG, 46U);
            aOrbiterG = (aWandererK + RotL64(aCross, 3U)) + 14236627073831834337U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 35U)) + 11502511046130497584U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 13U)) + 3679044835550219497U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 53U)) + 11254838916686736746U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10582608424233200966U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4628253464169957835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3798386391743884889U) + RotL64(aNonceWordE, 43U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1379331161819246587U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9816600392407327227U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16781971616348376878U;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4807797577690520554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7909676419643119585U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 256053568910383007U;
            aOrbiterB = RotL64((aOrbiterB * 11965085163352053161U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16179914439220412472U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3968867762761955845U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7473632378251893139U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7474832923901283742U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4736994731050735779U;
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 596484364660389193U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13822222274464306169U) ^ RotL64(aNonceWordD, 51U);
            aOrbiterC = RotL64((aOrbiterC * 1723502278319885511U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16307920280681985443U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3505106171801702915U;
            aOrbiterG = RotL64((aOrbiterG * 8479675421552861243U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4987142580981135150U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10336802574069791273U;
            aOrbiterK = RotL64((aOrbiterK * 2670706512498539705U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 10U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererK = aWandererK + (((((RotL64(aIngress, 44U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordB, 45U)) + aPhaseCWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 24U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + RotL64(aNonceWordH, 13U));
            aWandererH = aWandererH + (((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererA, 22U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordC, 24U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13514U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 10101U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14826U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15075U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 3U)) + 5697928251815176134U) + RotL64(aNonceWordE, 35U);
            aOrbiterG = (aWandererB + RotL64(aIngress, 46U)) + 337587740689259575U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 53U)) + 4927686903263973950U;
            aOrbiterC = (aWandererF + RotL64(aCross, 13U)) + 3742409032569801033U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 1608092659172197650U) + RotL64(aNonceWordH, 27U);
            aOrbiterD = (aWandererE + RotL64(aPrevious, 56U)) + 15848744267145717509U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 15300174177963339253U;
            aOrbiterF = (aWandererG + RotL64(aCross, 37U)) + 14162868453323648628U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 19U)) + 12020167069983729869U) + aPhaseCOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 51U)) + 16259538291658723956U) + aPhaseCOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 8516686212464112245U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3722184575520553132U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5663609293306386784U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15265344442454471986U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3050323350098829515U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1093356813820599238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15167726103772238440U;
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15170797965325981472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17826286701992981628U;
            aOrbiterK = RotL64((aOrbiterK * 11186808881726573677U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14710892030473425181U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1273724124862533034U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13018397560392545616U;
            aOrbiterA = RotL64((aOrbiterA * 4644812473262395329U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9638716186445643730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7255587739807843785U;
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9272350563697399628U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12128124729613601747U) + RotL64(aNonceWordA, 31U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2285238815562202219U;
            aOrbiterF = RotL64((aOrbiterF * 15398840993074390573U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6339113298619163493U) + RotL64(aNonceWordD, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5911895708485037040U;
            aOrbiterE = RotL64((aOrbiterE * 3271006139923200439U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7601399508218901328U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5697928251815176134U;
            aOrbiterJ = RotL64((aOrbiterJ * 8184257916861355735U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + RotL64(aNonceWordF, 41U)) + aPhaseCWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 56U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aNonceWordG, 20U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterA, 14U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18744U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19309U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 28U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22290U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22706U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 43U)) + 17264605017518259932U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 15209184354580778643U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 57U)) + 3299527965014731384U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 39U)) + 16293096431816127821U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 6U)) + 11031983436878828337U) + RotL64(aNonceWordH, 7U);
            aOrbiterG = (aWandererA + RotL64(aScatter, 51U)) + 9188018632448236358U;
            aOrbiterB = (aWandererH + RotL64(aCross, 53U)) + 13420816400363406556U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 13U)) + 2485063384097917101U) + aPhaseCOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 31U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 21U)) + 3089135816938128264U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 11U)) + 10730544971770435788U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 10431767565618874806U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14883796491656899074U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13465877783538483706U) ^ RotL64(aNonceWordE, 17U);
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13322163435314643713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4950101626975919939U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterE = RotL64((aOrbiterE * 7181706961838582889U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17961706029559914243U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10321902557977495175U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18146616411403012772U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11739172334166341121U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7936637782633487291U;
            aOrbiterI = RotL64((aOrbiterI * 14940929920543800413U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3160044627483874242U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16816384076887379704U;
            aOrbiterD = RotL64((aOrbiterD * 5052772186568301951U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8101560104988710226U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8851416379738817624U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16767420038937389027U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9941784290055185679U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14495651885701938495U;
            aOrbiterB = RotL64((aOrbiterB * 1540692851998143607U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10599676325220702167U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16092000942942971187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2457268192247656817U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16168470945107928109U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17264605017518259932U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15038386057529909273U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 37U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterI, 28U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aNonceWordA, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + RotL64(aNonceWordF, 42U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32074U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 26102U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28489U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27995U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 23U)) + 11274974230580265396U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 3U)) + 16658438747342741547U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 16612986966106053844U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 47U)) + 9329502236843231290U) + RotL64(aNonceWordF, 43U);
            aOrbiterC = (aWandererK + RotL64(aIngress, 10U)) + 14088261356708344656U;
            aOrbiterA = (aWandererG + RotL64(aCross, 13U)) + 13692608802007789581U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 41U)) + 6824473946645682398U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 2072915876348570040U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 7420507753044460759U) + RotL64(aNonceWordE, 17U);
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 4677557318688502593U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 37U)) + 15081678577055628459U) + aPhaseCOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7026792817486507482U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14871665922943969918U;
            aOrbiterF = RotL64((aOrbiterF * 694073180313083145U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6807734532159292872U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17882797335141303280U) ^ RotL64(aNonceWordH, 54U);
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10878718669747466677U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 861295180226875235U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterD = RotL64((aOrbiterD * 7565008208670843555U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6726642007159809594U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8061661744643240470U;
            aOrbiterH = RotL64((aOrbiterH * 6703498926835391813U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13541412083111962884U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8617442758729315637U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterB = RotL64((aOrbiterB * 15471862889276160953U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16884403561131293362U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9490680911678221233U;
            aOrbiterG = RotL64((aOrbiterG * 15988763830018001033U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10486145044311386738U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10200001044821063684U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16149790736141571017U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6997073594007878034U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13585783612009989767U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11425303157774550449U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3847846040256340653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11274974230580265396U;
            aOrbiterK = RotL64((aOrbiterK * 13970270689108369205U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 39U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + aPhaseCWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterK, 46U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aNonceWordC, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 48U));
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordB, 25U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
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
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA06716D8F40815F7ULL + 0x9AC51F5BB488A7C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB31A071626A28CA7ULL + 0x9E7C3C90A0784EE5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC8697CCE46F1E47DULL + 0x94C0F2238C64EF7BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAF15108E27199711ULL + 0x827CB0817B7E97BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFED6661051A133A5ULL + 0x9A792CEFDD8E8519ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9971F1729B2CC1E9ULL + 0xA57EC2BBDCAD6E81ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD0DBC1602BA5EB1BULL + 0x998F780564C27AC1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD0DFD9BA3E5873EBULL + 0xA5DF0AAB2DE754DBULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordC, 14U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1823U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5760U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordD, 52U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6811U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 64U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 22U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + 16658438747342741547U) + RotL64(aNonceWordF, 3U);
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 16612986966106053844U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 57U)) + 9329502236843231290U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 47U)) + 14088261356708344656U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 23U)) + 13692608802007789581U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 6824473946645682398U) + RotL64(aNonceWordG, 5U);
            aOrbiterJ = ((aWandererF + RotL64(aCross, 34U)) + 2072915876348570040U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 5U)) + 7420507753044460759U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4677557318688502593U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 15081678577055628459U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ RotL64(aNonceWordD, 25U);
            aOrbiterD = RotL64((aOrbiterD * 16659305295251177155U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7026792817486507482U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10878718669747466677U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8066049063548639241U;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 861295180226875235U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9134969787937288583U;
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6726642007159809594U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8061661744643240470U;
            aOrbiterE = RotL64((aOrbiterE * 6703498926835391813U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13541412083111962884U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8617442758729315637U;
            aOrbiterF = RotL64((aOrbiterF * 15471862889276160953U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16884403561131293362U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9490680911678221233U;
            aOrbiterK = RotL64((aOrbiterK * 15988763830018001033U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 40U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 56U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 18U)) + RotL64(aNonceWordB, 7U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aNonceWordH, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordE, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15720U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15000U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 6U) ^ RotL64(aNonceWordF, 37U)) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14891U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13000U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 3339283916456813609U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 3U)) + 11339086426180649584U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 53U)) + 16819191669329316585U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 8361916937762630725U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 48U)) + 18031328374429899857U) + aPhaseDOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + 18261756894092897276U) + RotL64(aNonceWordH, 46U);
            aOrbiterF = ((aWandererI + RotL64(aCross, 13U)) + 4250319792907645666U) + RotL64(aNonceWordA, 3U);
            aOrbiterH = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 1492411503643460886U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 24U)) + 17369549067879344180U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7301713524358676722U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2985193736033012535U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7473297294949338265U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14086975808140927408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18205555540941493267U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9209505304067579944U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3522631966146762306U;
            aOrbiterH = RotL64((aOrbiterH * 3441982898533162599U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8811497120829041188U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14707301680850257294U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10080595991787801029U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterK = RotL64((aOrbiterK * 7417016898027778287U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1981637172055758689U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16463077485583119324U;
            aOrbiterA = RotL64((aOrbiterA * 2876782050665869121U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8383837717361569465U) + RotL64(aNonceWordG, 31U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2788511294985017326U;
            aOrbiterB = RotL64((aOrbiterB * 2809163242875130677U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3529607472855930041U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8850940802020173766U) ^ RotL64(aNonceWordE, 29U);
            aOrbiterE = RotL64((aOrbiterE * 7821450253655655943U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererC = aWandererC + (((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + RotL64(aNonceWordC, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aNonceWordB, 61U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 22U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 6U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aPhaseDWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordH, 53U)) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22826U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 17347U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19368U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20201U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 29U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 43U)) + 17264605017518259932U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 14U)) + 15209184354580778643U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 39U)) + 3299527965014731384U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 57U)) + 16293096431816127821U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 11031983436878828337U) + RotL64(aNonceWordD, 23U);
            aOrbiterC = (aWandererA + RotL64(aPrevious, 3U)) + 9188018632448236358U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 27U)) + 13420816400363406556U) + RotL64(aNonceWordF, 7U);
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 2485063384097917101U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 50U)) + RotL64(aCarry, 3U)) + 3089135816938128264U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10730544971770435788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14883796491656899074U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13322163435314643713U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3307316600284371955U) ^ RotL64(aNonceWordA, 57U);
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4950101626975919939U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2596253994220103666U) ^ RotL64(aNonceWordG, 31U);
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17961706029559914243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18146616411403012772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11739172334166341121U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3160044627483874242U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16816384076887379704U;
            aOrbiterF = RotL64((aOrbiterF * 5052772186568301951U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8101560104988710226U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8851416379738817624U;
            aOrbiterE = RotL64((aOrbiterE * 16767420038937389027U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterI) + RotL64(aCarry, 13U)) + RotL64(aNonceWordE, 10U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 34U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 18U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordC, 25U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordF, 48U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28067U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29102U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24641U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 27096U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 5697928251815176134U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 337587740689259575U) + RotL64(aNonceWordA, 51U);
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 60U)) + 4927686903263973950U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 3742409032569801033U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 23U)) + 1608092659172197650U) + RotL64(aNonceWordH, 43U);
            aOrbiterG = (aWandererF + RotL64(aScatter, 35U)) + 15848744267145717509U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 18U)) + 15300174177963339253U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 43U)) + 14162868453323648628U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 12020167069983729869U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16259538291658723956U) + RotL64(aNonceWordB, 4U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8516686212464112245U;
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3722184575520553132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5663609293306386784U;
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15265344442454471986U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3050323350098829515U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1093356813820599238U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15167726103772238440U) ^ RotL64(aNonceWordG, 27U);
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15170797965325981472U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17826286701992981628U;
            aOrbiterB = RotL64((aOrbiterB * 11186808881726573677U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14710892030473425181U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 397194787697553904U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1273724124862533034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13018397560392545616U;
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9638716186445643730U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7255587739807843785U;
            aOrbiterI = RotL64((aOrbiterI * 6055682981584011189U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9272350563697399628U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1040729335295009339U;
            aOrbiterF = RotL64((aOrbiterF * 17825687660830291443U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 56U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + RotL64(aCarry, 3U)) + RotL64(aNonceWordF, 39U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + RotL64(aNonceWordD, 9U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 44U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_d (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [twist arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2398U)) & S_BLOCK1], 20U) ^ RotL64(aKeyBoxUnrolledA[((aIndex + 2330U)) & (S_KEY_A - 1)], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 8U)) & (S_KEY_B - 1)], 44U) ^ RotL64(mSource[((aIndex + 4527U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 12775735908960052604U) + aPhaseAOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 11791373812080296887U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 5537362877706057303U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + 2023912048504189380U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 13U)) + 17668828109963766893U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 558908629933941224U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1479633119685446888U;
            aOrbiterC = RotL64((aOrbiterC * 4447153373540811385U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15460320397843364063U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9987633811929693924U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10087337844580228269U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4446204415503364254U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + aPhaseAWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 36U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10439U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 13407U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 13661U)) & (S_KEY_A - 1)], 51U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 13905U)) & (S_KEY_B - 1)], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 58U)) + 10336802574069791273U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 21U)) + 169025388197058936U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 6541354188379168846U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 16223920526599306104U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 12756613707692514808U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5082475548176484035U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4907435526952698526U;
            aOrbiterG = RotL64((aOrbiterG * 1379692095754989215U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14236627073831834337U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11502511046130497584U;
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3679044835550219497U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4628253464169957835U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17664454668473204465U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4234720298731378527U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 46U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 42U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23359U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20721U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyBoxUnrolledA[(((14335U - aIndex) + 18495U)) & (S_KEY_A - 1)], 60U) ^ RotL64(aKeyBoxUnrolledB[(((18431U - aIndex) + 16495U)) & (S_KEY_B - 1)], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 3339283916456813609U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 60U)) + 11339086426180649584U) + aPhaseAOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 16819191669329316585U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 8361916937762630725U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + 18031328374429899857U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 18261756894092897276U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4250319792907645666U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7053489184750217963U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1492411503643460886U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17369549067879344180U;
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7301713524358676722U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2985193736033012535U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14086975808140927408U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10390516547834639800U;
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18205555540941493267U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 24U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterG, 56U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32763U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24741U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32497U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28899U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 5697928251815176134U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 14U)) + 337587740689259575U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 41U)) + 4927686903263973950U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 3742409032569801033U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 1608092659172197650U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15848744267145717509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15300174177963339253U;
            aOrbiterD = RotL64((aOrbiterD * 5771922862677667319U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14162868453323648628U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12020167069983729869U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16259538291658723956U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3722184575520553132U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15265344442454471986U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7696U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 2778U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5617U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 1119U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 24U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 17264605017518259932U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 44U)) + 15209184354580778643U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 3299527965014731384U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 16293096431816127821U) + aPhaseBOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 53U)) + 11031983436878828337U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9188018632448236358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13420816400363406556U;
            aOrbiterJ = RotL64((aOrbiterJ * 10958221259662190519U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2485063384097917101U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3089135816938128264U;
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10730544971770435788U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10431767565618874806U;
            aOrbiterH = RotL64((aOrbiterH * 4723078464590561545U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14883796491656899074U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13465877783538483706U;
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13322163435314643713U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3307316600284371955U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12337846092069506365U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 6U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15671U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14613U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13195U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12799U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 4U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 10336802574069791273U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 19U)) + 169025388197058936U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 11U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 16223920526599306104U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 12756613707692514808U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5082475548176484035U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4907435526952698526U;
            aOrbiterG = RotL64((aOrbiterG * 1379692095754989215U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14236627073831834337U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11502511046130497584U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3679044835550219497U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10582608424233200966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4628253464169957835U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17664454668473204465U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 30U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19928U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21996U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17388U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21894U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aIngress, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 12775735908960052604U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 11791373812080296887U;
            aOrbiterE = (aWandererF + RotL64(aCross, 21U)) + 5537362877706057303U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 4U)) + RotL64(aCarry, 35U)) + 2023912048504189380U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 53U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 558908629933941224U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1479633119685446888U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4447153373540811385U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15460320397843364063U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8671817118586065469U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9987633811929693924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4446204415503364254U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15106063243302192717U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9430197906134676162U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 48U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25450U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25973U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28779U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32725U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 5697928251815176134U) + aPhaseBOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 337587740689259575U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 56U)) + 4927686903263973950U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 23U)) + 3742409032569801033U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 1608092659172197650U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15848744267145717509U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15300174177963339253U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5771922862677667319U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14162868453323648628U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12020167069983729869U;
            aOrbiterA = RotL64((aOrbiterA * 2071080217680099017U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16259538291658723956U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8516686212464112245U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3722184575520553132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15265344442454471986U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3050323350098829515U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5890624677162388135U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 20U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Unholy_060_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4668U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 3033U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 741U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 1042U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 44U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 11U)) + 5697928251815176134U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 47U)) + 337587740689259575U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 4927686903263973950U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 20U)) + 3742409032569801033U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 1608092659172197650U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 15848744267145717509U) + aPhaseCOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 3U)) + 15300174177963339253U) + aPhaseCOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14162868453323648628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12020167069983729869U;
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16259538291658723956U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8516686212464112245U;
            aOrbiterD = RotL64((aOrbiterD * 4731296903548893627U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3722184575520553132U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5663609293306386784U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15265344442454471986U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1093356813820599238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15170797965325981472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14710892030473425181U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + aPhaseCWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9750U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15095U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8908U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 15471U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 39U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 44U)) + RotL64(aCarry, 5U)) + 10336802574069791273U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 5U)) + 169025388197058936U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 6541354188379168846U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 16223920526599306104U) + aPhaseCOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 27U)) + 12756613707692514808U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 19U)) + 5082475548176484035U;
            aOrbiterK = (aWandererK + RotL64(aCross, 37U)) + 4907435526952698526U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14236627073831834337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11502511046130497584U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3679044835550219497U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterC = RotL64((aOrbiterC * 8631695922983532915U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10582608424233200966U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4628253464169957835U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3798386391743884889U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9816600392407327227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16781971616348376878U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4807797577690520554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2492057261148595922U;
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 14U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19346U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18332U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22544U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 22892U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aIngress, 11U)) + 3339283916456813609U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 37U)) + 11339086426180649584U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16819191669329316585U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 8361916937762630725U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 5U)) + 18031328374429899857U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 18261756894092897276U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 43U)) + 4250319792907645666U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1492411503643460886U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17369549067879344180U;
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7301713524358676722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14086975808140927408U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10390516547834639800U;
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18205555540941493267U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9209505304067579944U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3522631966146762306U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8811497120829041188U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14707301680850257294U;
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10080595991787801029U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6822892187784299166U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 34U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 13U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26224U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27735U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26793U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27208U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + 11274974230580265396U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 39U)) + 16658438747342741547U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 23U)) + 16612986966106053844U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 9329502236843231290U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 13U)) + 14088261356708344656U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 13692608802007789581U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 6824473946645682398U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2072915876348570040U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7420507753044460759U;
            aOrbiterF = RotL64((aOrbiterF * 13239288539564571257U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4677557318688502593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7026792817486507482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14871665922943969918U;
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6807734532159292872U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17882797335141303280U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9233542707022629190U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10878718669747466677U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8066049063548639241U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3031382633089381605U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 861295180226875235U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterB = RotL64((aOrbiterB * 7565008208670843555U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 12U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterF, 44U));
            aWandererA = aWandererA + (((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + aPhaseCWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}
