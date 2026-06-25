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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF7C22DFCDBD0A0B1ULL + 0xA43C947F575A979CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF34F52F14709AA6FULL + 0xD04E15689DC6663DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x80142D056DD216C5ULL + 0x9A9D27F9CE8AFB92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE72078DCDA985377ULL + 0x9FE9A6A583175A2AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBF9C2A85EE1BF825ULL + 0xE1324BBB5073746DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8D4EFA89FBDCBD97ULL + 0x9EF770A971E675EFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA0510C25CC67B50DULL + 0xC21B9168062D5A22ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE6659E1E293C8497ULL + 0xD8A682048E953F71ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1159U)) & S_BLOCK1], 39U) ^ RotL64(mSnow[((aIndex + 810U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 20U) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1626U)) & S_BLOCK1], 35U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 1753U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 38U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 10336802574069791273U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 41U)) + 169025388197058936U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 29U)) + 6541354188379168846U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 5U)) + 16223920526599306104U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 19U)) + 12756613707692514808U) + RotL64(aNonceWordC, 57U);
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 5082475548176484035U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 43U)) + 4907435526952698526U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 14236627073831834337U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 37U)) + 11502511046130497584U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 11U)) + 3679044835550219497U) + RotL64(aNonceWordH, 19U);
            aOrbiterC = (((aWandererG + RotL64(aIngress, 24U)) + RotL64(aCarry, 43U)) + 11254838916686736746U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10582608424233200966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4628253464169957835U) + RotL64(aNonceWordF, 34U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17664454668473204465U) ^ RotL64(aNonceWordA, 5U);
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3798386391743884889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1379331161819246587U;
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9816600392407327227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16781971616348376878U;
            aOrbiterK = RotL64((aOrbiterK * 12503867584828289879U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4807797577690520554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7909676419643119585U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 256053568910383007U;
            aOrbiterH = RotL64((aOrbiterH * 11965085163352053161U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16179914439220412472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3968867762761955845U;
            aOrbiterC = RotL64((aOrbiterC * 7473632378251893139U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7474832923901283742U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4736994731050735779U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 596484364660389193U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13822222274464306169U;
            aOrbiterF = RotL64((aOrbiterF * 1723502278319885511U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16307920280681985443U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3505106171801702915U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8479675421552861243U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4987142580981135150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10336802574069791273U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2670706512498539705U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aNonceWordG, 59U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 34U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6983U)) & S_BLOCK1], 26U) ^ RotL64(mSnow[((aIndex + 7168U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordF, 28U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6383U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 6018U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 48U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 27U)) + 5697928251815176134U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 43U)) + 337587740689259575U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + 4927686903263973950U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 3742409032569801033U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 51U)) + 1608092659172197650U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 15848744267145717509U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 15300174177963339253U) + RotL64(aNonceWordB, 41U);
            aOrbiterB = ((aWandererB + RotL64(aCross, 37U)) + 14162868453323648628U) + RotL64(aNonceWordC, 10U);
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + 12020167069983729869U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 53U)) + 16259538291658723956U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 18U)) + 8516686212464112245U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3722184575520553132U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15265344442454471986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3050323350098829515U;
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1093356813820599238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15167726103772238440U;
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15170797965325981472U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14710892030473425181U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1273724124862533034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13018397560392545616U) ^ RotL64(aNonceWordF, 25U);
            aOrbiterD = RotL64((aOrbiterD * 4644812473262395329U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9638716186445643730U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7255587739807843785U;
            aOrbiterF = RotL64((aOrbiterF * 6055682981584011189U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9272350563697399628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1040729335295009339U;
            aOrbiterK = RotL64((aOrbiterK * 17825687660830291443U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12128124729613601747U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2285238815562202219U) ^ RotL64(aNonceWordA, 11U);
            aOrbiterB = RotL64((aOrbiterB * 15398840993074390573U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6339113298619163493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5911895708485037040U;
            aOrbiterE = RotL64((aOrbiterE * 3271006139923200439U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7601399508218901328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5697928251815176134U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8184257916861355735U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterH, 38U)) + RotL64(aNonceWordG, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 4U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 40U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 14439U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 11913U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13501U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 11738U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 41U)) + 3339283916456813609U;
            aOrbiterI = (aWandererB + RotL64(aCross, 3U)) + 11339086426180649584U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 60U)) + 16819191669329316585U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 8361916937762630725U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 18031328374429899857U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 51U)) + 18261756894092897276U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordC, 18U);
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 4250319792907645666U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 21U)) + 1492411503643460886U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 28U)) + RotL64(aCarry, 35U)) + 17369549067879344180U) + RotL64(aNonceWordF, 39U);
            aOrbiterC = (aWandererE + RotL64(aCross, 57U)) + 7301713524358676722U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 47U)) + 2985193736033012535U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18205555540941493267U) + RotL64(aNonceWordB, 45U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9209505304067579944U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3441982898533162599U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8811497120829041188U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10080595991787801029U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1981637172055758689U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16463077485583119324U;
            aOrbiterC = RotL64((aOrbiterC * 2876782050665869121U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8383837717361569465U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2788511294985017326U;
            aOrbiterH = RotL64((aOrbiterH * 2809163242875130677U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3529607472855930041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8850940802020173766U;
            aOrbiterF = RotL64((aOrbiterF * 7821450253655655943U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7469160295100147267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16973986572163482061U;
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12371372942863279718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12098525148034303633U;
            aOrbiterD = RotL64((aOrbiterD * 11234127652230231751U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5138683482859889480U) + RotL64(aNonceWordE, 41U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3339283916456813609U;
            aOrbiterB = RotL64((aOrbiterB * 10975353228235695455U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterA, 24U));
            aWandererF = aWandererF + (((RotL64(aCross, 26U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aNonceWordG, 57U));
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 22U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + RotL64(aNonceWordH, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordA, 54U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 17462U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 21169U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21443U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 20296U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 11274974230580265396U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 29U)) + 16658438747342741547U) + RotL64(aNonceWordD, 50U);
            aOrbiterE = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 16612986966106053844U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 39U)) + 9329502236843231290U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 20U)) + 14088261356708344656U) + RotL64(aNonceWordH, 57U);
            aOrbiterF = (aWandererD + RotL64(aPrevious, 13U)) + 13692608802007789581U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 57U)) + 6824473946645682398U;
            aOrbiterK = (aWandererG + RotL64(aCross, 41U)) + 2072915876348570040U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 51U)) + 7420507753044460759U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 4677557318688502593U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 22U)) + 15081678577055628459U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7026792817486507482U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6807734532159292872U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9233542707022629190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1205501586581350876U;
            aOrbiterF = RotL64((aOrbiterF * 2596053290311090589U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10878718669747466677U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8066049063548639241U;
            aOrbiterG = RotL64((aOrbiterG * 3031382633089381605U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 861295180226875235U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9134969787937288583U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterK = RotL64((aOrbiterK * 7565008208670843555U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6726642007159809594U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8061661744643240470U;
            aOrbiterH = RotL64((aOrbiterH * 6703498926835391813U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13541412083111962884U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8617442758729315637U;
            aOrbiterD = RotL64((aOrbiterD * 15471862889276160953U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16884403561131293362U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9490680911678221233U;
            aOrbiterB = RotL64((aOrbiterB * 15988763830018001033U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10486145044311386738U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10200001044821063684U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16149790736141571017U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6997073594007878034U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13585783612009989767U;
            aOrbiterI = RotL64((aOrbiterI * 11425303157774550449U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3847846040256340653U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11274974230580265396U) ^ RotL64(aNonceWordB, 9U);
            aOrbiterA = RotL64((aOrbiterA * 13970270689108369205U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 36U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aNonceWordE, 17U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 26U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aNonceWordG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26357U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24779U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 26U) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26820U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 23083U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 19U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 53U)) + 17264605017518259932U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 56U)) + 15209184354580778643U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 13U)) + 3299527965014731384U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 47U)) + 16293096431816127821U;
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 9188018632448236358U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 43U)) + 13420816400363406556U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 2485063384097917101U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 3089135816938128264U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 10730544971770435788U) + RotL64(aNonceWordB, 41U);
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + 10431767565618874806U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14883796491656899074U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13322163435314643713U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12337846092069506365U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4950101626975919939U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17961706029559914243U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10321902557977495175U;
            aOrbiterB = RotL64((aOrbiterB * 16189559888625084711U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18146616411403012772U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11739172334166341121U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7936637782633487291U) ^ RotL64(aNonceWordE, 37U);
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3160044627483874242U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16816384076887379704U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5052772186568301951U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8101560104988710226U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8851416379738817624U;
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9941784290055185679U) + RotL64(aNonceWordD, 31U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14495651885701938495U;
            aOrbiterE = RotL64((aOrbiterE * 1540692851998143607U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10599676325220702167U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16092000942942971187U;
            aOrbiterI = RotL64((aOrbiterI * 2457268192247656817U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16168470945107928109U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17264605017518259932U;
            aOrbiterH = RotL64((aOrbiterH * 15038386057529909273U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + RotL64(aNonceWordF, 56U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 56U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 37U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aNonceWordH, 59U));
            aWandererE = aWandererE + ((((RotL64(aCross, 56U) + RotL64(aOrbiterH, 10U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordA, 4U)) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 29877U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32091U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30262U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31920U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aCross, 14U)) + 12775735908960052604U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 19U)) + 11791373812080296887U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 5537362877706057303U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + 2023912048504189380U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 56U)) + 17668828109963766893U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 558908629933941224U) + RotL64(aNonceWordC, 5U);
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 1479633119685446888U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 15460320397843364063U) + RotL64(aNonceWordB, 49U);
            aOrbiterF = (aWandererB + RotL64(aPrevious, 29U)) + 10059749397555469054U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 53U)) + 9987633811929693924U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 27U)) + 10087337844580228269U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4446204415503364254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9430197906134676162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10611580584157624739U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 9327201928815412810U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordE, 15U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7890659377013147073U;
            aOrbiterG = RotL64((aOrbiterG * 13827717178378062047U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12871947817782057116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11015991745792051390U;
            aOrbiterF = RotL64((aOrbiterF * 17152451500505815031U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6320437975845673731U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 702457937087191287U;
            aOrbiterJ = RotL64((aOrbiterJ * 17491257114676739589U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16629064896250312921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6054107387816339103U;
            aOrbiterE = RotL64((aOrbiterE * 6983767878966747219U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13274874838094190290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12211422735294360321U) ^ RotL64(aNonceWordD, 9U);
            aOrbiterA = RotL64((aOrbiterA * 5113738196151089817U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15338616110718583619U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1475787183754511373U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10904607643785840003U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15486810401396777742U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12775735908960052604U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7478156942468930207U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 46U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + RotL64(aNonceWordH, 48U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 44U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + RotL64(aNonceWordF, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCECF2867A136664DULL + 0x997A2FA8A166A4A8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9B011AEF9FA3E219ULL + 0xC5388EE8CDA55591ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x81B6DB25903FD77FULL + 0xBCA143E6CB5D0A70ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC040D2EA14F987B5ULL + 0x97E5DDB7B19F88D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD520248AA3485369ULL + 0x810B7E0453E13523ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA5DD1A625F2C09DDULL + 0xE530C9F1084CC7BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDB5101A5C285B589ULL + 0x8CF228F25966A664ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDDE73B1E6D827ED7ULL + 0x85D9B24B330D0298ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1490U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3593U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3616U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4812U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 5697928251815176134U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 42U)) + RotL64(aCarry, 43U)) + 337587740689259575U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 4927686903263973950U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 23U)) + 3742409032569801033U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 57U)) + 1608092659172197650U;
            aOrbiterA = (aWandererG + RotL64(aCross, 29U)) + 15848744267145717509U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 15300174177963339253U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 4U)) + 14162868453323648628U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + 12020167069983729869U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16259538291658723956U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3722184575520553132U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1093356813820599238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15167726103772238440U;
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15170797965325981472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17826286701992981628U;
            aOrbiterB = RotL64((aOrbiterB * 11186808881726573677U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14710892030473425181U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 397194787697553904U;
            aOrbiterD = RotL64((aOrbiterD * 14368930300818752833U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1273724124862533034U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13018397560392545616U;
            aOrbiterE = RotL64((aOrbiterE * 4644812473262395329U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9638716186445643730U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7255587739807843785U;
            aOrbiterH = RotL64((aOrbiterH * 6055682981584011189U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9272350563697399628U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1040729335295009339U;
            aOrbiterF = RotL64((aOrbiterF * 17825687660830291443U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 52U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 40U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12850U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 9735U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12518U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 15219U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 18U)) + 3339283916456813609U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 29U)) + 11339086426180649584U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 16819191669329316585U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 57U)) + 8361916937762630725U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 18031328374429899857U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 22U)) + 18261756894092897276U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 53U)) + 4250319792907645666U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 1492411503643460886U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 43U)) + 17369549067879344180U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7301713524358676722U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2985193736033012535U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18205555540941493267U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9209505304067579944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8811497120829041188U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14707301680850257294U;
            aOrbiterH = RotL64((aOrbiterH * 11383709499376464085U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10080595991787801029U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1981637172055758689U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16463077485583119324U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2876782050665869121U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8383837717361569465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2788511294985017326U;
            aOrbiterJ = RotL64((aOrbiterJ * 2809163242875130677U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3529607472855930041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8850940802020173766U;
            aOrbiterG = RotL64((aOrbiterG * 7821450253655655943U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 10U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterD, 58U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20641U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 23089U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20601U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 22806U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 29U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 24U)) + 11274974230580265396U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 29U)) + 16658438747342741547U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 16612986966106053844U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 9329502236843231290U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 14088261356708344656U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 19U)) + 13692608802007789581U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 6824473946645682398U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 36U)) + 2072915876348570040U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 7420507753044460759U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4677557318688502593U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7026792817486507482U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6807734532159292872U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9233542707022629190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10878718669747466677U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterA = RotL64((aOrbiterA * 3031382633089381605U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6726642007159809594U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8061661744643240470U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6703498926835391813U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13541412083111962884U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8617442758729315637U;
            aOrbiterD = RotL64((aOrbiterD * 15471862889276160953U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16884403561131293362U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9490680911678221233U;
            aOrbiterJ = RotL64((aOrbiterJ * 15988763830018001033U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 18U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 6U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26567U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25722U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25356U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 31342U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 47U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 21U)) + 17264605017518259932U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 15209184354580778643U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 51U)) + 3299527965014731384U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 27U)) + 16293096431816127821U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 23U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 9188018632448236358U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 35U)) + 13420816400363406556U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + 2485063384097917101U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 47U)) + 3089135816938128264U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10730544971770435788U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10431767565618874806U;
            aOrbiterF = RotL64((aOrbiterF * 4723078464590561545U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14883796491656899074U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4950101626975919939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17961706029559914243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10321902557977495175U;
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18146616411403012772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11739172334166341121U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7936637782633487291U;
            aOrbiterI = RotL64((aOrbiterI * 14940929920543800413U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3160044627483874242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16816384076887379704U;
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8101560104988710226U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 20U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 46U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE069FE6FC246B7ADULL + 0xC9B76F21134F4D61ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x847B0810A9F77B73ULL + 0x8F18541CA9DB5446ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF8003FE158500E61ULL + 0x83FF9EB4BAD25EB8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA9838597F1220585ULL + 0xC823C07EEFD07C32ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9B05868B892A3AC3ULL + 0xBE02AAD49DB28C70ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF5FE501C3FB1EE9BULL + 0xFB690EB120A2540CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDC353F0B5D9FAEC9ULL + 0xA97D9A9F4BB7BFA4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBD8AE918EFB66335ULL + 0xC5C3D8B29A265FBBULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5683U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 6781U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1230U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6658U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 13U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererH + RotL64(aScatter, 6U)) + RotL64(aCarry, 27U)) + 17264605017518259932U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 27U)) + 15209184354580778643U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 23U)) + 3299527965014731384U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 39U)) + 16293096431816127821U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 47U)) + 11031983436878828337U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 13U)) + 9188018632448236358U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 13420816400363406556U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 57U)) + 2485063384097917101U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 41U)) + 3089135816938128264U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10730544971770435788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterH = RotL64((aOrbiterH * 4723078464590561545U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14883796491656899074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13322163435314643713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4950101626975919939U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7181706961838582889U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18146616411403012772U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8414050129421955787U;
            aOrbiterA = RotL64((aOrbiterA * 14879448948196182863U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11739172334166341121U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7936637782633487291U;
            aOrbiterD = RotL64((aOrbiterD * 14940929920543800413U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3160044627483874242U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16816384076887379704U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5052772186568301951U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8101560104988710226U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8851416379738817624U;
            aOrbiterK = RotL64((aOrbiterK * 16767420038937389027U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 60U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 40U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12613U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 10687U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12593U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 14137U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 53U)) + 10336802574069791273U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 35U)) + 169025388197058936U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 60U)) + 6541354188379168846U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 39U)) + 16223920526599306104U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 12756613707692514808U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 5082475548176484035U;
            aOrbiterH = (aWandererF + RotL64(aCross, 14U)) + 4907435526952698526U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 14236627073831834337U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 11502511046130497584U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3679044835550219497U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4628253464169957835U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3798386391743884889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1379331161819246587U;
            aOrbiterC = RotL64((aOrbiterC * 13086160171095077295U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4807797577690520554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7909676419643119585U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 256053568910383007U;
            aOrbiterA = RotL64((aOrbiterA * 11965085163352053161U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16179914439220412472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3968867762761955845U;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7474832923901283742U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4736994731050735779U;
            aOrbiterE = RotL64((aOrbiterE * 9839654409121414047U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 30U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 52U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20889U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22365U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17496U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 20005U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 5697928251815176134U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 35U)) + 337587740689259575U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 4927686903263973950U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 3742409032569801033U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 47U)) + 1608092659172197650U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 27U)) + 15848744267145717509U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 22U)) + 15300174177963339253U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 3U)) + 14162868453323648628U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 13U)) + 12020167069983729869U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16259538291658723956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4731296903548893627U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3722184575520553132U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15265344442454471986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1093356813820599238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15167726103772238440U;
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15170797965325981472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17826286701992981628U;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14710892030473425181U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1273724124862533034U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13018397560392545616U;
            aOrbiterF = RotL64((aOrbiterF * 4644812473262395329U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9638716186445643730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9272350563697399628U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1040729335295009339U;
            aOrbiterJ = RotL64((aOrbiterJ * 17825687660830291443U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterG, 18U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 28U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30505U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26722U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25755U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 29345U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 12775735908960052604U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 19U)) + 11791373812080296887U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 53U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 2023912048504189380U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 41U)) + 17668828109963766893U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 35U)) + 558908629933941224U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 14U)) + 1479633119685446888U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 57U)) + 15460320397843364063U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 10059749397555469054U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9987633811929693924U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4446204415503364254U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10611580584157624739U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9327201928815412810U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10675114832750356941U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8804440385852327267U;
            aOrbiterJ = RotL64((aOrbiterJ * 8520671775587260601U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12871947817782057116U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17152451500505815031U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6320437975845673731U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterA = RotL64((aOrbiterA * 17491257114676739589U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16629064896250312921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6054107387816339103U;
            aOrbiterD = RotL64((aOrbiterD * 6983767878966747219U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterI, 24U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 14U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBD350ED5CF496337ULL + 0x96EFB63C9042BF8AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAA01620FC00959BBULL + 0x9168994B0D3800F9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFD6CCD745CF2BE41ULL + 0xACACC61135988605ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC01E2A965E9E2E99ULL + 0x8F6A1A6A8C9C4DECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF78E3EDE7FF24223ULL + 0xF08E0AA724DF4122ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE63F0D1A205F0271ULL + 0x99BCBC84961F6DFDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD64AABC20962F64FULL + 0xF18FC54833C82B1BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8A083245693FD629ULL + 0xFEE8EC3A08BFBF98ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6158U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5631U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3491U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 775U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 18U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 47U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 22U)) + 337587740689259575U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 4927686903263973950U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3742409032569801033U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 13U)) + 1608092659172197650U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 29U)) + 15848744267145717509U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 15300174177963339253U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14162868453323648628U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12020167069983729869U;
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16259538291658723956U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8516686212464112245U;
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15265344442454471986U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1093356813820599238U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15170797965325981472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14710892030473425181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterI = RotL64((aOrbiterI * 14368930300818752833U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 30U));
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10941U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12309U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10000U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14709U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 11274974230580265396U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 13U)) + 16658438747342741547U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 57U)) + 16612986966106053844U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 9329502236843231290U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 14088261356708344656U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 4U)) + 13692608802007789581U;
            aOrbiterA = (aWandererK + RotL64(aCross, 29U)) + 6824473946645682398U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2072915876348570040U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7420507753044460759U;
            aOrbiterI = RotL64((aOrbiterI * 13239288539564571257U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4677557318688502593U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterD = RotL64((aOrbiterD * 16659305295251177155U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7026792817486507482U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6807734532159292872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9233542707022629190U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1205501586581350876U;
            aOrbiterJ = RotL64((aOrbiterJ * 2596053290311090589U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10878718669747466677U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8066049063548639241U;
            aOrbiterB = RotL64((aOrbiterB * 3031382633089381605U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 861295180226875235U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 12U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17884U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23251U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21511U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 19108U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 24U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 53U)) + 12775735908960052604U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 47U)) + 11791373812080296887U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 5537362877706057303U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 2023912048504189380U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 30U)) + 17668828109963766893U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 558908629933941224U;
            aOrbiterH = (aWandererI + RotL64(aCross, 11U)) + 1479633119685446888U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15460320397843364063U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10059749397555469054U;
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9987633811929693924U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13817142288940843815U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4446204415503364254U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9430197906134676162U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10611580584157624739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9327201928815412810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 22U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29551U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 30889U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28931U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 32035U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + 10336802574069791273U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 169025388197058936U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 6541354188379168846U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 16223920526599306104U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 10U)) + 12756613707692514808U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 57U)) + 5082475548176484035U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 4907435526952698526U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14236627073831834337U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterJ = RotL64((aOrbiterJ * 3460330807286625917U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3679044835550219497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11254838916686736746U;
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10582608424233200966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4628253464169957835U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9816600392407327227U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererI = aWandererI + (((RotL64(aScatter, 10U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 28U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x88A7556A488235C5ULL + 0xBCD4E453F52B4941ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C068F331D8DD783ULL + 0xB49E423F09A4282AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEBB5C786D0817ADFULL + 0xE4E0FECCB668D09DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x95E571CC14AF004DULL + 0xFE0E168A825BA8B5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE48437E6B4974A9ULL + 0x890D47696F1A2FD5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDDBCFFCFCE9432C3ULL + 0xE0B2194DA174CDCEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCDE79CEA980D5B2BULL + 0xB9A98A520583F247ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9E358C3864DF44B7ULL + 0xC79E118CB3671BE0ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 26U) ^ RotL64(aNonceWordB, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1611U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5392U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6696U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 734U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 34U)) + 10336802574069791273U) + RotL64(aNonceWordE, 21U);
            aOrbiterH = (aWandererB + RotL64(aPrevious, 13U)) + 169025388197058936U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 47U)) + 6541354188379168846U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 16223920526599306104U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 12756613707692514808U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 5082475548176484035U) + RotL64(aNonceWordD, 31U);
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 4907435526952698526U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 14236627073831834337U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordA, 13U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11502511046130497584U;
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3679044835550219497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10582608424233200966U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7363770199734997411U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4628253464169957835U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17664454668473204465U) ^ RotL64(aNonceWordC, 36U);
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3798386391743884889U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1379331161819246587U;
            aOrbiterC = RotL64((aOrbiterC * 13086160171095077295U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9816600392407327227U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 20U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + RotL64(aNonceWordG, 55U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aNonceWordF, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordD, 58U)) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8567U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11304U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordH, 48U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9005U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 10388U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 54U)) + 3339283916456813609U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 13U);
            aOrbiterG = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 29U)) + 16819191669329316585U) + RotL64(aNonceWordG, 37U);
            aOrbiterD = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 8361916937762630725U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 3U)) + 18031328374429899857U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 47U)) + 18261756894092897276U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 4250319792907645666U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1492411503643460886U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17369549067879344180U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7301713524358676722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2985193736033012535U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14086975808140927408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18205555540941493267U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9209505304067579944U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3522631966146762306U) ^ RotL64(aNonceWordF, 61U);
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 8811497120829041188U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordB, 34U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14707301680850257294U;
            aOrbiterH = RotL64((aOrbiterH * 11383709499376464085U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10080595991787801029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterB = RotL64((aOrbiterB * 7417016898027778287U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererK = aWandererK + (((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 25U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + RotL64(aNonceWordC, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordA, 34U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17147U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23352U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 50U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19568U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 17545U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 5697928251815176134U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 337587740689259575U;
            aOrbiterI = (aWandererG + RotL64(aCross, 60U)) + 4927686903263973950U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 3742409032569801033U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 1608092659172197650U) + RotL64(aNonceWordG, 10U);
            aOrbiterE = (aWandererI + RotL64(aPrevious, 53U)) + 15848744267145717509U;
            aOrbiterC = ((((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 15300174177963339253U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14162868453323648628U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12020167069983729869U;
            aOrbiterI = RotL64((aOrbiterI * 2071080217680099017U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16259538291658723956U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3722184575520553132U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15265344442454471986U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3050323350098829515U) ^ RotL64(aNonceWordB, 27U);
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 1093356813820599238U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordF, 55U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15167726103772238440U;
            aOrbiterG = RotL64((aOrbiterG * 5719466863561311069U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15170797965325981472U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11186808881726573677U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14710892030473425181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterB) + RotL64(aNonceWordH, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordE, 56U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25879U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31366U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordA, 34U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27031U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 30473U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 36U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 17264605017518259932U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 15209184354580778643U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 3299527965014731384U;
            aOrbiterE = (aWandererF + RotL64(aCross, 21U)) + 16293096431816127821U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 41U)) + 11031983436878828337U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterJ = (((aWandererH + RotL64(aCross, 60U)) + 9188018632448236358U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 7U);
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 47U)) + 13420816400363406556U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2485063384097917101U) + RotL64(aNonceWordB, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3089135816938128264U;
            aOrbiterI = RotL64((aOrbiterI * 8813152992957361153U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10730544971770435788U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10431767565618874806U;
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14883796491656899074U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13465877783538483706U) ^ RotL64(aNonceWordF, 26U);
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13322163435314643713U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3307316600284371955U;
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4950101626975919939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterD = RotL64((aOrbiterD * 7181706961838582889U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17961706029559914243U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18146616411403012772U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8414050129421955787U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aNonceWordE, 9U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 60U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xACF6B733D1156CB5ULL + 0xC9A1E953985881FDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD32654B4EB4530EFULL + 0xCB8C44EF02DC5B0AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB0296C1E1E680493ULL + 0xBE417B55071A64D7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE487C5F970E9CDD3ULL + 0xE4C49931E5120F36ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8520DB97BC692F31ULL + 0xDD04C9D7D3DBDA4EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA56CC3EECB20A4BULL + 0x810708B34178CDCFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC4ABB939A155B095ULL + 0xBCD122D3930808D4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBB8DEF64CBE071C7ULL + 0xC96D5B8BB19EFFBDULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordD, 22U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4131U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 1559U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1307U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1322U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 51U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 16658438747342741547U) + RotL64(aNonceWordC, 53U);
            aOrbiterC = (aWandererG + RotL64(aCross, 21U)) + 16612986966106053844U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 47U)) + 9329502236843231290U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 29U)) + 14088261356708344656U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 23U)) + 13692608802007789581U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 6824473946645682398U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 13U)) + 2072915876348570040U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordE, 15U);
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 34U)) + RotL64(aCarry, 35U)) + 7420507753044460759U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 41U)) + 4677557318688502593U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 53U)) + 15081678577055628459U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7026792817486507482U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6807734532159292872U) + RotL64(aNonceWordA, 12U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9233542707022629190U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1205501586581350876U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10878718669747466677U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8066049063548639241U;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 861295180226875235U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6726642007159809594U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8061661744643240470U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13541412083111962884U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8617442758729315637U;
            aOrbiterD = RotL64((aOrbiterD * 15471862889276160953U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16884403561131293362U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9490680911678221233U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15988763830018001033U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10486145044311386738U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10200001044821063684U;
            aOrbiterE = RotL64((aOrbiterE * 16149790736141571017U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6997073594007878034U) + RotL64(aNonceWordH, 37U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13585783612009989767U;
            aOrbiterB = RotL64((aOrbiterB * 11425303157774550449U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3847846040256340653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11274974230580265396U;
            aOrbiterJ = RotL64((aOrbiterJ * 13970270689108369205U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordB, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 46U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aNonceWordG, 7U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 6U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 50U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 18U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14576U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13189U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 26U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8976U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 15146U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 12775735908960052604U) + RotL64(aNonceWordC, 10U);
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 11791373812080296887U;
            aOrbiterE = (aWandererC + RotL64(aCross, 46U)) + 5537362877706057303U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 2023912048504189380U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + 17668828109963766893U) + RotL64(aNonceWordE, 35U);
            aOrbiterH = ((aWandererK + RotL64(aCross, 5U)) + 558908629933941224U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 38U)) + 1479633119685446888U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 11U)) + 15460320397843364063U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 10059749397555469054U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 9987633811929693924U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 53U)) + 10087337844580228269U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4446204415503364254U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15106063243302192717U;
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9430197906134676162U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10611580584157624739U) + RotL64(aNonceWordH, 47U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9327201928815412810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterD = RotL64((aOrbiterD * 13827717178378062047U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12871947817782057116U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17152451500505815031U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6320437975845673731U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 702457937087191287U;
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16629064896250312921U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6054107387816339103U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6983767878966747219U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13274874838094190290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12211422735294360321U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterA = RotL64((aOrbiterA * 5113738196151089817U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15338616110718583619U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1475787183754511373U;
            aOrbiterI = RotL64((aOrbiterI * 10904607643785840003U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15486810401396777742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12775735908960052604U;
            aOrbiterC = RotL64((aOrbiterC * 7478156942468930207U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordB, 53U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 14U) + RotL64(aOrbiterB, 4U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + RotL64(aNonceWordD, 45U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 36U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21765U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22753U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22340U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 21080U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 50U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 18U)) + 10336802574069791273U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 169025388197058936U;
            aOrbiterG = (aWandererE + RotL64(aCross, 51U)) + 6541354188379168846U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 43U)) + 16223920526599306104U;
            aOrbiterD = (aWandererA + RotL64(aCross, 35U)) + 12756613707692514808U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 21U)) + 5082475548176484035U) + RotL64(aNonceWordG, 49U);
            aOrbiterC = (aWandererH + RotL64(aScatter, 41U)) + 4907435526952698526U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 14236627073831834337U) + RotL64(aNonceWordD, 39U);
            aOrbiterE = ((aWandererF + RotL64(aScatter, 10U)) + 11502511046130497584U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 29U)) + 3679044835550219497U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 11254838916686736746U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10582608424233200966U) + RotL64(aNonceWordC, 11U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4628253464169957835U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3798386391743884889U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9816600392407327227U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterD = RotL64((aOrbiterD * 12503867584828289879U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4807797577690520554U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7909676419643119585U) + RotL64(aNonceWordE, 55U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 256053568910383007U;
            aOrbiterF = RotL64((aOrbiterF * 11965085163352053161U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16179914439220412472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3968867762761955845U;
            aOrbiterK = RotL64((aOrbiterK * 7473632378251893139U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7474832923901283742U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4736994731050735779U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9839654409121414047U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 596484364660389193U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13822222274464306169U;
            aOrbiterC = RotL64((aOrbiterC * 1723502278319885511U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16307920280681985443U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3505106171801702915U;
            aOrbiterE = RotL64((aOrbiterE * 8479675421552861243U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4987142580981135150U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10336802574069791273U;
            aOrbiterJ = RotL64((aOrbiterJ * 2670706512498539705U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 26U) + aOrbiterH) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 52U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordH, 38U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aNonceWordB, 61U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 12U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordD, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28196U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 27583U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordF, 58U)) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27413U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 29890U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 60U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 10U)) + 17264605017518259932U) + RotL64(aNonceWordE, 47U);
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 15209184354580778643U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 41U)) + 3299527965014731384U) + RotL64(aNonceWordD, 31U);
            aOrbiterI = (aWandererG + RotL64(aCross, 47U)) + 16293096431816127821U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 35U)) + 11031983436878828337U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 53U)) + 9188018632448236358U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 26U)) + RotL64(aCarry, 39U)) + 13420816400363406556U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 19U)) + 2485063384097917101U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 3089135816938128264U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + 10730544971770435788U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 10431767565618874806U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 14883796491656899074U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordA, 7U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4950101626975919939U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7181706961838582889U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17961706029559914243U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16189559888625084711U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18146616411403012772U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11739172334166341121U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7936637782633487291U;
            aOrbiterC = RotL64((aOrbiterC * 14940929920543800413U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3160044627483874242U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16816384076887379704U;
            aOrbiterE = RotL64((aOrbiterE * 5052772186568301951U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8101560104988710226U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8851416379738817624U;
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9941784290055185679U) + RotL64(aNonceWordH, 35U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14495651885701938495U;
            aOrbiterF = RotL64((aOrbiterF * 1540692851998143607U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10599676325220702167U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16092000942942971187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2457268192247656817U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16168470945107928109U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17264605017518259932U;
            aOrbiterI = RotL64((aOrbiterI * 15038386057529909273U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 46U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 6U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + RotL64(aNonceWordG, 27U));
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 26U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 60U)) + RotL64(aNonceWordB, 58U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF7211662C00F9D01ULL + 0xD769F6DBA9EEE5E9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE1F62C87AA68E16BULL + 0x9709A879DE016DBBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x96F959AEDD572A1DULL + 0xBAC9E304A762F569ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFEB1729F4589CD27ULL + 0xEACDD9CE73EDB8F6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE850646FDE7E8761ULL + 0xF4E01A9FF407F6E0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB48D7807A4AB2E2DULL + 0xBA8C06D1A8DA3E39ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF94AC880204A4D3BULL + 0xDEA410DD987C346FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC065AE0B1F592E5BULL + 0xEBFB8398A11727C0ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordH, 28U)) ^ RotL64(aNonceWordA, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2206U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 790U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 895U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 937U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 18U)) + 12775735908960052604U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 47U)) + 11791373812080296887U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 13U)) + 5537362877706057303U) + RotL64(aNonceWordH, 36U);
            aOrbiterD = (aWandererI + RotL64(aCross, 27U)) + 2023912048504189380U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 13U)) + 17668828109963766893U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 558908629933941224U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 57U)) + 1479633119685446888U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 35U)) + 15460320397843364063U;
            aOrbiterH = ((((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 10059749397555469054U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 25U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9987633811929693924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4446204415503364254U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15106063243302192717U;
            aOrbiterI = RotL64((aOrbiterI * 13273756657334709803U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9430197906134676162U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14247538885252664127U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10611580584157624739U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9327201928815412810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7890659377013147073U;
            aOrbiterF = RotL64((aOrbiterF * 13827717178378062047U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10675114832750356941U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 12871947817782057116U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordE, 11U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11015991745792051390U) ^ RotL64(aNonceWordG, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 17152451500505815031U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6320437975845673731U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterA = RotL64((aOrbiterA * 17491257114676739589U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16629064896250312921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6054107387816339103U;
            aOrbiterG = RotL64((aOrbiterG * 6983767878966747219U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + RotL64(aCarry, 37U)) + RotL64(aNonceWordA, 61U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterH, 22U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + RotL64(aNonceWordD, 55U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordB, 28U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6250U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6848U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordA, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6994U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6823U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 35U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 43U)) + 10336802574069791273U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 6U)) + 169025388197058936U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 47U)) + 6541354188379168846U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordC, 19U);
            aOrbiterI = ((aWandererJ + RotL64(aCross, 27U)) + 16223920526599306104U) + RotL64(aNonceWordD, 31U);
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 12756613707692514808U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 5082475548176484035U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 23U)) + 4907435526952698526U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 14236627073831834337U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 11502511046130497584U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3679044835550219497U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterF = RotL64((aOrbiterF * 8631695922983532915U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10582608424233200966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4628253464169957835U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17664454668473204465U;
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3798386391743884889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9816600392407327227U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordF, 11U);
            aOrbiterE = RotL64((aOrbiterE * 12503867584828289879U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4807797577690520554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2492057261148595922U;
            aOrbiterD = RotL64((aOrbiterD * 9453302540675483005U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7909676419643119585U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 256053568910383007U;
            aOrbiterI = RotL64((aOrbiterI * 11965085163352053161U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 16179914439220412472U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 57U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7473632378251893139U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7474832923901283742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4736994731050735779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9839654409121414047U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterJ, 48U));
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aNonceWordA, 49U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 14U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11373U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 13727U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordA, 39U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11309U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11458U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 11U)) + 17264605017518259932U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 43U)) + 15209184354580778643U) + RotL64(aNonceWordC, 27U);
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + 3299527965014731384U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 51U)) + 16293096431816127821U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 9188018632448236358U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 3U)) + 13420816400363406556U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordH, 19U);
            aOrbiterG = (aWandererH + RotL64(aIngress, 28U)) + 2485063384097917101U;
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 3089135816938128264U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10730544971770435788U) + RotL64(aNonceWordD, 13U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10431767565618874806U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14883796491656899074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13322163435314643713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4950101626975919939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2596253994220103666U;
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17961706029559914243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterH = RotL64((aOrbiterH * 16189559888625084711U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18146616411403012772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11739172334166341121U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7936637782633487291U) ^ RotL64(aNonceWordE, 43U);
            aOrbiterE = RotL64((aOrbiterE * 14940929920543800413U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3160044627483874242U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16816384076887379704U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5052772186568301951U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8101560104988710226U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8851416379738817624U;
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterA, 28U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aNonceWordA, 52U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 60U)) + aOrbiterH) + RotL64(aNonceWordB, 49U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17055U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 17543U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordB, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21653U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21463U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 28U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 11274974230580265396U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 6U)) + 16658438747342741547U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 16612986966106053844U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 9329502236843231290U) + RotL64(aNonceWordB, 23U);
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + 14088261356708344656U) + RotL64(aNonceWordC, 51U);
            aOrbiterK = (aWandererF + RotL64(aCross, 30U)) + 13692608802007789581U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 6824473946645682398U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 11U)) + 2072915876348570040U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 47U)) + 7420507753044460759U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4677557318688502593U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16659305295251177155U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7026792817486507482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14871665922943969918U;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6807734532159292872U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17882797335141303280U;
            aOrbiterF = RotL64((aOrbiterF * 15439872930381050291U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10878718669747466677U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8066049063548639241U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 861295180226875235U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterK = RotL64((aOrbiterK * 7565008208670843555U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6726642007159809594U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 8061661744643240470U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordE, 48U);
            aOrbiterD = RotL64((aOrbiterD * 6703498926835391813U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13541412083111962884U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8617442758729315637U;
            aOrbiterC = RotL64((aOrbiterC * 15471862889276160953U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16884403561131293362U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9490680911678221233U;
            aOrbiterJ = RotL64((aOrbiterJ * 15988763830018001033U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterD, 48U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + RotL64(aNonceWordF, 61U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordH, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 4U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25003U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 25166U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordG, 57U)) ^ RotL64(aNonceWordH, 40U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23098U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25650U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 35U)) + 5697928251815176134U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 337587740689259575U;
            aOrbiterJ = ((((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 4927686903263973950U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterC = (aWandererF + RotL64(aPrevious, 60U)) + 3742409032569801033U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 13U)) + 1608092659172197650U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 15848744267145717509U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 43U)) + 15300174177963339253U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 14162868453323648628U) + RotL64(aNonceWordC, 37U);
            aOrbiterG = (aWandererA + RotL64(aIngress, 50U)) + 12020167069983729869U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16259538291658723956U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8516686212464112245U) ^ RotL64(aNonceWordD, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3722184575520553132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterH = RotL64((aOrbiterH * 14364218128780764749U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15265344442454471986U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1093356813820599238U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15167726103772238440U) ^ RotL64(aNonceWordA, 9U);
            aOrbiterG = RotL64((aOrbiterG * 5719466863561311069U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15170797965325981472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterE = RotL64((aOrbiterE * 11186808881726573677U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14710892030473425181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1273724124862533034U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9638716186445643730U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7255587739807843785U;
            aOrbiterB = RotL64((aOrbiterB * 6055682981584011189U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9272350563697399628U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1040729335295009339U;
            aOrbiterA = RotL64((aOrbiterA * 17825687660830291443U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 22U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aNonceWordB, 15U));
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordG, 20U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordF, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27912U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 27318U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28628U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28514U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 29U)) + 3339283916456813609U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 60U)) + 11339086426180649584U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 16819191669329316585U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 8361916937762630725U;
            aOrbiterB = (aWandererG + RotL64(aCross, 37U)) + 18031328374429899857U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 18261756894092897276U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 51U)) + 4250319792907645666U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 56U)) + 1492411503643460886U) + RotL64(aNonceWordG, 17U);
            aOrbiterK = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 17369549067879344180U) + RotL64(aNonceWordF, 25U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7301713524358676722U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 2985193736033012535U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordE, 51U);
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14086975808140927408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18205555540941493267U) + RotL64(aNonceWordC, 31U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9209505304067579944U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8811497120829041188U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10080595991787801029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1981637172055758689U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16463077485583119324U;
            aOrbiterE = RotL64((aOrbiterE * 2876782050665869121U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8383837717361569465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2788511294985017326U;
            aOrbiterC = RotL64((aOrbiterC * 2809163242875130677U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3529607472855930041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7821450253655655943U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 30U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + RotL64(aNonceWordA, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterA, 40U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordH, 12U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE286871F26E45A85ULL + 0xAEF2D4B10C1BA3B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD763E04AA3488DFBULL + 0xD7395292602168A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF1CF562D6D6F3449ULL + 0xFE1A519762FB156EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBF38EDDF15708D15ULL + 0x88BFAB844E3D98DCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE19EE3004AA78F3DULL + 0xA491D2C277CAC843ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA19AB95C53FBE63ULL + 0xF7163298DEB4FFD4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9F669682138DBEABULL + 0xB5E21D72EF63DC13ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFB4F0F8181CDAB25ULL + 0x89357763837955C5ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: mSource, aKeyRowReadA, aKeyRowReadB, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // read from: mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1938U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 792U)) & W_KEY1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((1023U - aIndex) + 3184U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 870U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 51U)) + 10336802574069791273U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 169025388197058936U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 29U)) + 6541354188379168846U) + aPhaseAOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 15U);
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 16223920526599306104U;
            aOrbiterJ = ((((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12756613707692514808U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordC, 13U);
            aOrbiterH = ((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 5082475548176484035U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 11U)) + 4907435526952698526U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14236627073831834337U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11502511046130497584U;
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3679044835550219497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11254838916686736746U;
            aOrbiterJ = RotL64((aOrbiterJ * 8631695922983532915U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10582608424233200966U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 10449735026385340313U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4628253464169957835U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterF = RotL64((aOrbiterF * 4234720298731378527U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3798386391743884889U) + RotL64(aNonceWordG, 7U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1379331161819246587U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9816600392407327227U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16781971616348376878U;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4807797577690520554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + RotL64(aNonceWordF, 19U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 34U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordD, 22U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // read from: aWorkLaneA, mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 30U)) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6950U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 6133U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((1023U - aIndex) + 6091U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((1023U - aIndex) + 9281U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 17264605017518259932U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 5U)) + 15209184354580778643U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 19U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 16293096431816127821U) + aPhaseAOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordC, 59U);
            aOrbiterC = (aWandererD + RotL64(aIngress, 42U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 9188018632448236358U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + 13420816400363406556U) + RotL64(aNonceWordB, 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2485063384097917101U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3089135816938128264U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10730544971770435788U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10431767565618874806U) ^ RotL64(aNonceWordE, 55U);
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14883796491656899074U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterK = RotL64((aOrbiterK * 14311686051108108503U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4950101626975919939U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterC = RotL64((aOrbiterC * 7181706961838582889U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17961706029559914243U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10321902557977495175U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189559888625084711U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18146616411403012772U) + RotL64(aNonceWordD, 16U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8414050129421955787U;
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordF, 25U));
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // read from: aWorkLaneB, aWorkLaneA, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 20U) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12216U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 14938U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((1023U - aIndex) + 13793U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((1023U - aIndex) + 15647U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 26U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererK + RotL64(aIngress, 44U)) + RotL64(aCarry, 3U)) + 11274974230580265396U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 16658438747342741547U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordA, 9U);
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 16612986966106053844U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 9329502236843231290U) + RotL64(aNonceWordC, 51U);
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 14088261356708344656U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 57U)) + 13692608802007789581U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 6824473946645682398U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2072915876348570040U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7420507753044460759U;
            aOrbiterD = RotL64((aOrbiterD * 13239288539564571257U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4677557318688502593U) + RotL64(aNonceWordE, 28U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterC = RotL64((aOrbiterC * 16659305295251177155U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7026792817486507482U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14871665922943969918U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6807734532159292872U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9233542707022629190U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1205501586581350876U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10878718669747466677U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8066049063548639241U;
            aOrbiterB = RotL64((aOrbiterB * 3031382633089381605U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 861295180226875235U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterK = RotL64((aOrbiterK * 7565008208670843555U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aNonceWordH, 29U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 24U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + aPhaseAWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordD, 11U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, mSource
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 20U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19397U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 18820U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17637U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18692U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 50U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 57U)) + 3339283916456813609U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 29U)) + 11339086426180649584U;
            aOrbiterI = (aWandererE + RotL64(aCross, 39U)) + 16819191669329316585U;
            aOrbiterJ = ((((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 8361916937762630725U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterB = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 18031328374429899857U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 50U)) + 18261756894092897276U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 4250319792907645666U) + RotL64(aNonceWordA, 16U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1492411503643460886U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17369549067879344180U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7301713524358676722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2985193736033012535U) ^ RotL64(aNonceWordG, 11U);
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14086975808140927408U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 18205555540941493267U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordC, 29U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9209505304067579944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8811497120829041188U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14707301680850257294U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10080595991787801029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterA, 28U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterK) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 31U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordD, 45U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordF, 24U)) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26081U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 25607U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26081U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 22213U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 12775735908960052604U) + RotL64(aNonceWordE, 40U);
            aOrbiterH = ((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 11791373812080296887U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 43U)) + 5537362877706057303U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 19U)) + 2023912048504189380U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 17668828109963766893U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 5U)) + 558908629933941224U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordF, 41U);
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 37U)) + 1479633119685446888U) + aPhaseAOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15460320397843364063U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10059749397555469054U;
            aOrbiterI = RotL64((aOrbiterI * 8671817118586065469U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9987633811929693924U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10087337844580228269U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4446204415503364254U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15106063243302192717U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10611580584157624739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3137391249289641509U;
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9327201928815412810U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7890659377013147073U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10675114832750356941U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8804440385852327267U) ^ RotL64(aNonceWordA, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 8520671775587260601U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 48U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 29U)) + RotL64(aNonceWordD, 19U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 50U)) + RotL64(aNonceWordG, 17U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordE, 46U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31741U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28771U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordB, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30673U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 27656U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 14U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 47U)) + 5697928251815176134U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 11U)) + 337587740689259575U) + RotL64(aNonceWordE, 20U);
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 4927686903263973950U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 3742409032569801033U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 1608092659172197650U) + aPhaseAOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 40U)) + 15848744267145717509U) + RotL64(aNonceWordF, 31U);
            aOrbiterF = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 15300174177963339253U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14162868453323648628U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12020167069983729869U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 16259538291658723956U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 39U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8516686212464112245U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15265344442454471986U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1093356813820599238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15170797965325981472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14710892030473425181U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 397194787697553904U) ^ RotL64(aNonceWordH, 45U);
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aNonceWordA, 5U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aNonceWordD, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterB, 11U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB62E2DA1BFEF4CAFULL + 0xD356A61FF521DCCDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEDCE43FA160B8639ULL + 0xD1CEFC868BE946F0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xECCFEB4E88C77A51ULL + 0xECF1CFEB0DBEC2CEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x94FCEF050761960DULL + 0x8096C5B54E8F996DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9498A57FD20E2355ULL + 0x8E4DF83AA20E166DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB09B473A49F3332BULL + 0x86AB1895FCF97913ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA6A2EA9148DF4C2FULL + 0xC7212604728917EDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDBFC4EFB169E4F3DULL + 0xEBA6A02C91A3DC4CULL);
    // GSeedRunSeed_B seed_loop_b (start)
    {
        // GSeedRunSeed_B seed_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2895U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 845U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordH, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 816U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4874U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCarry, 29U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 53U)) + 11274974230580265396U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 3U)) + 16658438747342741547U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 43U)) + 16612986966106053844U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 9329502236843231290U) + RotL64(aNonceWordC, 11U);
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 14088261356708344656U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13692608802007789581U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6824473946645682398U;
            aOrbiterB = RotL64((aOrbiterB * 13619437545775237601U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2072915876348570040U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7420507753044460759U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4677557318688502593U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordF, 35U);
            aOrbiterG = RotL64((aOrbiterG * 16659305295251177155U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7026792817486507482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14871665922943969918U;
            aOrbiterK = RotL64((aOrbiterK * 694073180313083145U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6807734532159292872U) + RotL64(aNonceWordD, 19U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + RotL64(aNonceWordB, 9U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 14U)) + aOrbiterK) + RotL64(aNonceWordA, 54U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9577U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 10837U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10267U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 7618U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 5697928251815176134U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 337587740689259575U) + RotL64(aNonceWordH, 42U);
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 3742409032569801033U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 44U)) + 1608092659172197650U) + aPhaseBOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15848744267145717509U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15300174177963339253U;
            aOrbiterD = RotL64((aOrbiterD * 5771922862677667319U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14162868453323648628U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12020167069983729869U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2071080217680099017U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16259538291658723956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3722184575520553132U) + RotL64(aNonceWordA, 35U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15265344442454471986U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 3050323350098829515U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordF, 11U);
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterD, 10U)) + aPhaseBWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceWordB, 7U));
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 12U) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12381U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 15226U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordF, 44U)) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11729U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12419U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 11U)) + 3339283916456813609U) + RotL64(aNonceWordA, 53U);
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 20U)) + RotL64(aCarry, 37U)) + 11339086426180649584U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 16819191669329316585U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 8361916937762630725U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 41U)) + 18031328374429899857U) + aPhaseBOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordB, 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18261756894092897276U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4250319792907645666U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1492411503643460886U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17369549067879344180U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2947354306696216579U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7301713524358676722U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14086975808140927408U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10390516547834639800U) ^ RotL64(aNonceWordD, 42U);
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18205555540941493267U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16967799565443938873U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterI, 4U)) + RotL64(aNonceWordF, 25U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordG, 57U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // read from: aOperationLaneA, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16778U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17277U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordF, 52U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21479U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 20703U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 12775735908960052604U) + RotL64(aNonceWordG, 11U);
            aOrbiterF = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 11791373812080296887U) + aPhaseBOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 37U)) + 5537362877706057303U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 2023912048504189380U) + RotL64(aNonceWordD, 6U);
            aOrbiterD = (aWandererF + RotL64(aIngress, 19U)) + 17668828109963766893U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 558908629933941224U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordA, 29U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1479633119685446888U;
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15460320397843364063U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9987633811929693924U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterA = RotL64((aOrbiterA * 13817142288940843815U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4446204415503364254U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 15106063243302192717U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordH, 47U);
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9430197906134676162U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1226048679997253363U;
            aOrbiterD = RotL64((aOrbiterD * 14247538885252664127U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 36U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + RotL64(aNonceWordC, 31U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 52U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // read from: aOperationLaneB, aOperationLaneA, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25476U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 25889U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22095U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25776U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 10336802574069791273U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 169025388197058936U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 3U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 41U)) + 16223920526599306104U) + RotL64(aNonceWordG, 14U);
            aOrbiterB = (((aWandererD + RotL64(aIngress, 19U)) + 12756613707692514808U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordH, 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5082475548176484035U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4907435526952698526U;
            aOrbiterD = RotL64((aOrbiterD * 1379692095754989215U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14236627073831834337U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3679044835550219497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterJ = RotL64((aOrbiterJ * 8631695922983532915U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10582608424233200966U) + RotL64(aNonceWordD, 55U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10449735026385340313U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4628253464169957835U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17664454668473204465U) ^ RotL64(aNonceWordA, 41U);
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + RotL64(aNonceWordE, 21U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 21U)) + RotL64(aNonceWordB, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 30U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneB
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28809U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30454U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordF, 34U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30988U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 31333U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 22U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 17264605017518259932U) + RotL64(aNonceWordF, 9U);
            aOrbiterF = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 15209184354580778643U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 4U)) + 3299527965014731384U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 16293096431816127821U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 13U)) + 11031983436878828337U) + RotL64(aNonceWordC, 36U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9188018632448236358U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13420816400363406556U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10958221259662190519U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2485063384097917101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3089135816938128264U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10730544971770435788U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10431767565618874806U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14883796491656899074U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13465877783538483706U) ^ RotL64(aNonceWordB, 51U);
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13322163435314643713U) + RotL64(aNonceWordE, 61U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 47U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 41U)) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterI, 4U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[aIndex] = aIngress;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8AFAEFF33CEF257BULL + 0xE4A95D0A33EE2D88ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCCF32D343E2B61DDULL + 0xC6495A903F6CA762ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9C0E171132BB0B5DULL + 0xC3AF0039872E108BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD3307BFC087E54FFULL + 0xC254CBBD781C3FBAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF9DD04FDFD673D17ULL + 0x859D655FBF863825ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE3D034212E3E567FULL + 0xDB8003DFF207ABC7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC2ACA86EEC4E6A79ULL + 0xBD77C4793DE108ECULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD6184007C6214789ULL + 0xEF17B164A4B30966ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordG, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7534U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2851U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordH, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4114U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6145U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 35U)) + 10336802574069791273U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 18U)) + 169025388197058936U) + RotL64(aNonceWordF, 9U);
            aOrbiterI = (aWandererE + RotL64(aCross, 23U)) + 6541354188379168846U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 51U)) + 16223920526599306104U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 57U)) + 12756613707692514808U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 5082475548176484035U) + aPhaseCOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 40U)) + 4907435526952698526U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 11U);
            aOrbiterD = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 14236627073831834337U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 11502511046130497584U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3679044835550219497U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10582608424233200966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3798386391743884889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1379331161819246587U;
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9816600392407327227U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16781971616348376878U;
            aOrbiterG = RotL64((aOrbiterG * 12503867584828289879U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7909676419643119585U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 256053568910383007U;
            aOrbiterE = RotL64((aOrbiterE * 11965085163352053161U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16179914439220412472U) + RotL64(aNonceWordE, 37U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3968867762761955845U) ^ RotL64(aNonceWordH, 14U);
            aOrbiterC = RotL64((aOrbiterC * 7473632378251893139U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7474832923901283742U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4736994731050735779U;
            aOrbiterH = RotL64((aOrbiterH * 9839654409121414047U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aPhaseCWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 18U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aNonceWordB, 41U)) + aPhaseCWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + RotL64(aNonceWordA, 49U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterI, 38U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererG = aWandererG + ((RotL64(aIngress, 10U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 20U) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12048U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 10549U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordE, 10U)) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15248U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10515U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 11274974230580265396U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 16658438747342741547U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 57U)) + 16612986966106053844U) + aPhaseCOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 6U)) + 9329502236843231290U) + RotL64(aNonceWordC, 13U);
            aOrbiterB = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 14088261356708344656U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 53U)) + 13692608802007789581U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 35U)) + 6824473946645682398U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 24U)) + 2072915876348570040U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 29U)) + 7420507753044460759U) + RotL64(aNonceWordA, 45U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4677557318688502593U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15081678577055628459U;
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7026792817486507482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6807734532159292872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9233542707022629190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10878718669747466677U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8066049063548639241U;
            aOrbiterG = RotL64((aOrbiterG * 3031382633089381605U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 861295180226875235U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9134969787937288583U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7565008208670843555U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6726642007159809594U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8061661744643240470U;
            aOrbiterF = RotL64((aOrbiterF * 6703498926835391813U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 13541412083111962884U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 7U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8617442758729315637U) ^ RotL64(aNonceWordF, 9U);
            aOrbiterC = RotL64((aOrbiterC * 15471862889276160953U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16884403561131293362U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9490680911678221233U;
            aOrbiterA = RotL64((aOrbiterA * 15988763830018001033U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 42U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + RotL64(aNonceWordG, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 26U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordB, 18U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24302U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 17864U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22568U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17945U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 39U)) + 17264605017518259932U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 15209184354580778643U) + RotL64(aNonceWordA, 7U);
            aOrbiterF = (aWandererK + RotL64(aIngress, 57U)) + 3299527965014731384U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 16293096431816127821U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 13U)) + 11031983436878828337U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 4U)) + 9188018632448236358U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 27U)) + 13420816400363406556U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 47U)) + 2485063384097917101U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 19U)) + 3089135816938128264U) + RotL64(aNonceWordC, 8U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10730544971770435788U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterF = RotL64((aOrbiterF * 4723078464590561545U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14883796491656899074U) + RotL64(aNonceWordF, 49U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13465877783538483706U;
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13322163435314643713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3307316600284371955U;
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4950101626975919939U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2596253994220103666U;
            aOrbiterI = RotL64((aOrbiterI * 7181706961838582889U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17961706029559914243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18146616411403012772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 11739172334166341121U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7936637782633487291U;
            aOrbiterJ = RotL64((aOrbiterJ * 14940929920543800413U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3160044627483874242U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16816384076887379704U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5052772186568301951U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8101560104988710226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8851416379738817624U;
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + RotL64(aNonceWordH, 21U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aNonceWordB, 15U));
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterE, 56U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordC, 40U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28066U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 27260U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordA, 6U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28874U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 26330U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 28U)) + RotL64(aCarry, 41U)) + 5697928251815176134U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 47U)) + 337587740689259575U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 43U)) + 4927686903263973950U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 3742409032569801033U) + RotL64(aNonceWordD, 27U);
            aOrbiterB = ((aWandererK + RotL64(aIngress, 21U)) + 1608092659172197650U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 37U)) + 15848744267145717509U) + RotL64(aNonceWordG, 19U);
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 57U)) + 15300174177963339253U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 53U)) + 14162868453323648628U;
            aOrbiterH = (aWandererI + RotL64(aCross, 11U)) + 12020167069983729869U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16259538291658723956U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8516686212464112245U) ^ RotL64(aNonceWordH, 26U);
            aOrbiterD = RotL64((aOrbiterD * 4731296903548893627U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3722184575520553132U) + RotL64(aNonceWordF, 5U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5663609293306386784U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15265344442454471986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1093356813820599238U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15167726103772238440U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15170797965325981472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17826286701992981628U;
            aOrbiterI = RotL64((aOrbiterI * 11186808881726573677U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14710892030473425181U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 397194787697553904U;
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1273724124862533034U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13018397560392545616U;
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9638716186445643730U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7255587739807843785U;
            aOrbiterH = RotL64((aOrbiterH * 6055682981584011189U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9272350563697399628U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1040729335295009339U;
            aOrbiterJ = RotL64((aOrbiterJ * 17825687660830291443U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aNonceWordE, 29U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + RotL64(aNonceWordB, 21U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 36U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE338A8386B955F15ULL + 0xF3AADD538F737435ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8FA290F9BDD90061ULL + 0xDC9F3E720B7332CEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF4669A2F7479D78BULL + 0x932F44F71ECB24A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9C914CC02CB8BA59ULL + 0x873D40E514A5465EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD38213A45CDAF789ULL + 0x817703CCB8B2F38DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBA143BB78A27FFEBULL + 0xBA0D3499171E0DE8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8C6D3FECC3DB8DD3ULL + 0xD0B4A96B14292B59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEC47D93AB6752643ULL + 0x98BF066D56B8AEACULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aOperationLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1483U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 464U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordG, 28U)) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4977U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 326U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 27U)) + 5697928251815176134U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 3U)) + 337587740689259575U) + RotL64(aNonceWordC, 57U);
            aOrbiterB = (aWandererH + RotL64(aScatter, 42U)) + 4927686903263973950U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 39U)) + 3742409032569801033U;
            aOrbiterI = (aWandererB + RotL64(aCross, 37U)) + 1608092659172197650U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 13U)) + 15848744267145717509U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 15300174177963339253U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 14162868453323648628U;
            aOrbiterG = (aWandererI + RotL64(aCross, 47U)) + 12020167069983729869U;
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 16259538291658723956U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordA, 35U);
            aOrbiterE = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 8516686212464112245U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3722184575520553132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15265344442454471986U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3050323350098829515U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1093356813820599238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15167726103772238440U) ^ RotL64(aNonceWordB, 20U);
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15170797965325981472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14710892030473425181U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1273724124862533034U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13018397560392545616U;
            aOrbiterG = RotL64((aOrbiterG * 4644812473262395329U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9638716186445643730U) + RotL64(aNonceWordD, 7U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7255587739807843785U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9272350563697399628U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12128124729613601747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2285238815562202219U;
            aOrbiterI = RotL64((aOrbiterI * 15398840993074390573U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6339113298619163493U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5911895708485037040U;
            aOrbiterK = RotL64((aOrbiterK * 3271006139923200439U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7601399508218901328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5697928251815176134U;
            aOrbiterA = RotL64((aOrbiterA * 8184257916861355735U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 56U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordG, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aPhaseDWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 10U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + RotL64(aNonceWordE, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 44U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5715U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5652U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordA, 57U)) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10456U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 8779U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 19U)) + 3339283916456813609U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 11339086426180649584U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 16819191669329316585U) + RotL64(aNonceWordE, 15U);
            aOrbiterE = ((aWandererD + RotL64(aIngress, 11U)) + 8361916937762630725U) + RotL64(aNonceWordD, 35U);
            aOrbiterH = (aWandererI + RotL64(aCross, 58U)) + 18031328374429899857U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 18261756894092897276U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 5U)) + 4250319792907645666U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 29U)) + 1492411503643460886U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 41U)) + 17369549067879344180U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 51U)) + 7301713524358676722U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 34U)) + 2985193736033012535U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18205555540941493267U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9209505304067579944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterH = RotL64((aOrbiterH * 3441982898533162599U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 8811497120829041188U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordC, 3U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14707301680850257294U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10080595991787801029U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterG = RotL64((aOrbiterG * 7417016898027778287U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1981637172055758689U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16463077485583119324U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterI = RotL64((aOrbiterI * 2876782050665869121U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8383837717361569465U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2788511294985017326U;
            aOrbiterE = RotL64((aOrbiterE * 2809163242875130677U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3529607472855930041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8850940802020173766U;
            aOrbiterK = RotL64((aOrbiterK * 7821450253655655943U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7469160295100147267U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16973986572163482061U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15660743778376905023U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12371372942863279718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12098525148034303633U;
            aOrbiterD = RotL64((aOrbiterD * 11234127652230231751U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5138683482859889480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3339283916456813609U;
            aOrbiterJ = RotL64((aOrbiterJ * 10975353228235695455U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 26U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 26U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterB, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + RotL64(aNonceWordH, 29U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 58U)) + aOrbiterB) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 6U)) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 10U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15077U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 15147U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13505U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11135U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 22U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 11U)) + 12775735908960052604U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 11791373812080296887U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 22U)) + 5537362877706057303U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 41U)) + 2023912048504189380U) + RotL64(aNonceWordF, 37U);
            aOrbiterC = (aWandererB + RotL64(aIngress, 35U)) + 17668828109963766893U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 27U)) + 558908629933941224U;
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 1479633119685446888U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 29U)) + 15460320397843364063U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 10059749397555469054U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 48U)) + RotL64(aCarry, 23U)) + 9987633811929693924U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 51U)) + 10087337844580228269U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4446204415503364254U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15106063243302192717U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10611580584157624739U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3137391249289641509U;
            aOrbiterD = RotL64((aOrbiterD * 5462682413239873181U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9327201928815412810U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10675114832750356941U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 8804440385852327267U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordA, 55U);
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12871947817782057116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11015991745792051390U;
            aOrbiterI = RotL64((aOrbiterI * 17152451500505815031U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6320437975845673731U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 702457937087191287U;
            aOrbiterE = RotL64((aOrbiterE * 17491257114676739589U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16629064896250312921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6054107387816339103U;
            aOrbiterK = RotL64((aOrbiterK * 6983767878966747219U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13274874838094190290U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12211422735294360321U;
            aOrbiterB = RotL64((aOrbiterB * 5113738196151089817U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15338616110718583619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1475787183754511373U;
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15486810401396777742U) + RotL64(aNonceWordC, 29U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12775735908960052604U;
            aOrbiterH = RotL64((aOrbiterH * 7478156942468930207U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 6U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordD, 22U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aNonceWordB, 7U)) + aPhaseDWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 54U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // read from: aWorkLaneA, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 30U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19647U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20999U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21255U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 21018U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 39U)) + 17264605017518259932U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 27U)) + 15209184354580778643U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 48U);
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 3299527965014731384U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 37U)) + 16293096431816127821U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 23U)) + 11031983436878828337U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 5U)) + 9188018632448236358U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 58U)) + 13420816400363406556U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 2485063384097917101U) + RotL64(aNonceWordB, 51U);
            aOrbiterC = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 3089135816938128264U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 19U)) + 10730544971770435788U;
            aOrbiterH = (aWandererB + RotL64(aCross, 56U)) + 10431767565618874806U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14883796491656899074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13322163435314643713U) + RotL64(aNonceWordA, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4950101626975919939U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterF = RotL64((aOrbiterF * 7181706961838582889U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17961706029559914243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterK = RotL64((aOrbiterK * 16189559888625084711U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18146616411403012772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8414050129421955787U;
            aOrbiterG = RotL64((aOrbiterG * 14879448948196182863U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11739172334166341121U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7936637782633487291U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14940929920543800413U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3160044627483874242U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16816384076887379704U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5052772186568301951U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8101560104988710226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8851416379738817624U;
            aOrbiterH = RotL64((aOrbiterH * 16767420038937389027U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9941784290055185679U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14495651885701938495U;
            aOrbiterB = RotL64((aOrbiterB * 1540692851998143607U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10599676325220702167U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16092000942942971187U;
            aOrbiterD = RotL64((aOrbiterD * 2457268192247656817U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16168470945107928109U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 17264605017518259932U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordF, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 15038386057529909273U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterE, 22U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aNonceWordC, 25U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aNonceWordG, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 6U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererE, 4U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordA, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25401U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 24033U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 4U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23107U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 25009U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 13U)) + 10336802574069791273U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 169025388197058936U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 5U)) + 6541354188379168846U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 37U)) + 16223920526599306104U) + RotL64(aNonceWordB, 60U);
            aOrbiterA = ((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 29U)) + 12756613707692514808U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 19U)) + 5082475548176484035U) + aPhaseDOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 4907435526952698526U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 14236627073831834337U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 27U)) + 11502511046130497584U) + RotL64(aNonceWordG, 57U);
            aOrbiterH = (aWandererI + RotL64(aScatter, 44U)) + 3679044835550219497U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 11254838916686736746U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10582608424233200966U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10449735026385340313U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7363770199734997411U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4628253464169957835U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3798386391743884889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9816600392407327227U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16781971616348376878U;
            aOrbiterH = RotL64((aOrbiterH * 12503867584828289879U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7909676419643119585U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterJ = RotL64((aOrbiterJ * 11965085163352053161U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16179914439220412472U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3968867762761955845U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7473632378251893139U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7474832923901283742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4736994731050735779U;
            aOrbiterC = RotL64((aOrbiterC * 9839654409121414047U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 596484364660389193U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13822222274464306169U;
            aOrbiterG = RotL64((aOrbiterG * 1723502278319885511U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16307920280681985443U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3505106171801702915U) ^ RotL64(aNonceWordC, 13U);
            aOrbiterB = RotL64((aOrbiterB * 8479675421552861243U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4987142580981135150U) + RotL64(aNonceWordE, 11U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10336802574069791273U;
            aOrbiterA = RotL64((aOrbiterA * 2670706512498539705U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 44U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aNonceWordH, 43U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 42U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aNonceWordF, 37U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneB
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 20U) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30372U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28836U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 36U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31733U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29384U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 11274974230580265396U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 16658438747342741547U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 51U)) + 16612986966106053844U) + RotL64(aNonceWordE, 26U);
            aOrbiterK = (aWandererF + RotL64(aIngress, 41U)) + 9329502236843231290U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 14088261356708344656U;
            aOrbiterC = (aWandererK + RotL64(aCross, 47U)) + 13692608802007789581U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 39U)) + 6824473946645682398U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 11U)) + 2072915876348570040U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 4U)) + 7420507753044460759U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 29U)) + 4677557318688502593U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 21U)) + 15081678577055628459U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7026792817486507482U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14871665922943969918U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6807734532159292872U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9233542707022629190U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterC = RotL64((aOrbiterC * 2596053290311090589U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10878718669747466677U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8066049063548639241U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 861295180226875235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6726642007159809594U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8061661744643240470U;
            aOrbiterD = RotL64((aOrbiterD * 6703498926835391813U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13541412083111962884U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8617442758729315637U;
            aOrbiterE = RotL64((aOrbiterE * 15471862889276160953U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16884403561131293362U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9490680911678221233U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15988763830018001033U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10486145044311386738U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 10200001044821063684U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordF, 49U);
            aOrbiterF = RotL64((aOrbiterF * 16149790736141571017U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6997073594007878034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13585783612009989767U;
            aOrbiterB = RotL64((aOrbiterB * 11425303157774550449U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3847846040256340653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11274974230580265396U;
            aOrbiterK = RotL64((aOrbiterK * 13970270689108369205U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterD, 42U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + RotL64(aNonceWordH, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 38U)) + aOrbiterB) + RotL64(aNonceWordA, 29U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
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
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
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
    // GTwistRunTwist_A twist_loop_a (start)
    {
        // GTwistRunTwist_A twist_loop_a lane group
        // read from: mSource, aKeyRowReadA, aKeyRowReadB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // read from: mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3045U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((1023U - aIndex) + 1588U)) & W_KEY1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((1023U - aIndex) + 4730U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 798U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 14U)) + 3339283916456813609U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 11339086426180649584U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + 16819191669329316585U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 8361916937762630725U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 18031328374429899857U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 41U)) + 18261756894092897276U;
            aOrbiterI = (aWandererE + RotL64(aCross, 10U)) + 4250319792907645666U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + 1492411503643460886U) + aPhaseAOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 17369549067879344180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7301713524358676722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterD = RotL64((aOrbiterD * 7473297294949338265U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9209505304067579944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8811497120829041188U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10080595991787801029U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1981637172055758689U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16463077485583119324U;
            aOrbiterI = RotL64((aOrbiterI * 2876782050665869121U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8383837717361569465U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2788511294985017326U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2809163242875130677U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3529607472855930041U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8850940802020173766U;
            aOrbiterF = RotL64((aOrbiterF * 7821450253655655943U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 30U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 6U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 48U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11774U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 9639U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((1023U - aIndex) + 12344U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((1023U - aIndex) + 12749U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 30U)) + 17264605017518259932U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 15209184354580778643U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 43U)) + 3299527965014731384U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 16293096431816127821U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 12U)) + 11031983436878828337U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 9188018632448236358U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 47U)) + 13420816400363406556U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 2485063384097917101U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 35U)) + 3089135816938128264U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10730544971770435788U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10431767565618874806U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4723078464590561545U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14883796491656899074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13465877783538483706U;
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13322163435314643713U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3307316600284371955U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4950101626975919939U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterG = RotL64((aOrbiterG * 7181706961838582889U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17961706029559914243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterF = RotL64((aOrbiterF * 16189559888625084711U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18146616411403012772U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8414050129421955787U;
            aOrbiterI = RotL64((aOrbiterI * 14879448948196182863U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11739172334166341121U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7936637782633487291U;
            aOrbiterD = RotL64((aOrbiterD * 14940929920543800413U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3160044627483874242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16816384076887379704U;
            aOrbiterH = RotL64((aOrbiterH * 5052772186568301951U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8101560104988710226U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8851416379738817624U;
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterI, 36U));
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 14U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22751U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16463U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((1023U - aIndex) + 20837U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((1023U - aIndex) + 19792U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 48U)) + 11274974230580265396U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 16658438747342741547U;
            aOrbiterD = (aWandererK + RotL64(aCross, 3U)) + 16612986966106053844U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 27U)) + 9329502236843231290U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 39U)) + 14088261356708344656U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 43U)) + 13692608802007789581U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 37U)) + 6824473946645682398U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 2072915876348570040U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 7420507753044460759U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4677557318688502593U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15081678577055628459U;
            aOrbiterD = RotL64((aOrbiterD * 16659305295251177155U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7026792817486507482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6807734532159292872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17882797335141303280U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9233542707022629190U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterC = RotL64((aOrbiterC * 2596053290311090589U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10878718669747466677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8066049063548639241U;
            aOrbiterK = RotL64((aOrbiterK * 3031382633089381605U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 861295180226875235U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9134969787937288583U;
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6726642007159809594U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8061661744643240470U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6703498926835391813U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13541412083111962884U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8617442758729315637U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15471862889276160953U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16884403561131293362U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9490680911678221233U;
            aOrbiterF = RotL64((aOrbiterF * 15988763830018001033U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 46U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterA, 12U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 42U)) + aOrbiterC) + aPhaseAWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30702U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 25238U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25381U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 30564U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 5697928251815176134U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 10U)) + 337587740689259575U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 39U)) + 4927686903263973950U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 47U)) + 3742409032569801033U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 1608092659172197650U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + 15848744267145717509U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 15300174177963339253U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 43U)) + 14162868453323648628U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 20U)) + RotL64(aCarry, 47U)) + 12020167069983729869U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16259538291658723956U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8516686212464112245U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4731296903548893627U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3722184575520553132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15265344442454471986U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1093356813820599238U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15167726103772238440U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15170797965325981472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14710892030473425181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1273724124862533034U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13018397560392545616U;
            aOrbiterA = RotL64((aOrbiterA * 4644812473262395329U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9638716186445643730U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7255587739807843785U;
            aOrbiterJ = RotL64((aOrbiterJ * 6055682981584011189U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9272350563697399628U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1040729335295009339U;
            aOrbiterF = RotL64((aOrbiterF * 17825687660830291443U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 58U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterA, 36U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7294U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4865U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1858U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6892U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 26U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 20U)) + RotL64(aCarry, 3U)) + 5697928251815176134U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 29U)) + 337587740689259575U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 3742409032569801033U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 11U)) + 1608092659172197650U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15848744267145717509U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15300174177963339253U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5771922862677667319U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14162868453323648628U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12020167069983729869U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16259538291658723956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3722184575520553132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 40U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 50U)) + aPhaseBWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11405U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9981U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14160U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 8888U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 17264605017518259932U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 15209184354580778643U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 11U)) + 3299527965014731384U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 16293096431816127821U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 51U)) + 11031983436878828337U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9188018632448236358U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13420816400363406556U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10958221259662190519U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2485063384097917101U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3089135816938128264U;
            aOrbiterJ = RotL64((aOrbiterJ * 8813152992957361153U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10730544971770435788U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterG = RotL64((aOrbiterG * 4723078464590561545U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14883796491656899074U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13465877783538483706U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13322163435314643713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 46U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21978U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16971U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16975U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 17639U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 60U)) + 10336802574069791273U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 169025388197058936U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 16223920526599306104U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 12756613707692514808U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5082475548176484035U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4907435526952698526U;
            aOrbiterB = RotL64((aOrbiterB * 1379692095754989215U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14236627073831834337U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11502511046130497584U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3679044835550219497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10582608424233200966U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4628253464169957835U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 50U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30791U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27362U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28916U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31963U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 48U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 12775735908960052604U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 11791373812080296887U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 5537362877706057303U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 2023912048504189380U) + aPhaseBOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 558908629933941224U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1479633119685446888U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4447153373540811385U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15460320397843364063U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8671817118586065469U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9987633811929693924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10087337844580228269U;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4446204415503364254U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9430197906134676162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 36U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterA, 28U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2612U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4898U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1574U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4795U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 40U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 21U)) + 17264605017518259932U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 29U)) + 15209184354580778643U) + aPhaseCOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 53U)) + 3299527965014731384U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 16293096431816127821U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 11031983436878828337U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 9188018632448236358U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 13420816400363406556U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2485063384097917101U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3089135816938128264U;
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10730544971770435788U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14883796491656899074U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13465877783538483706U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13322163435314643713U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3307316600284371955U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12337846092069506365U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4950101626975919939U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterC = RotL64((aOrbiterC * 7181706961838582889U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18146616411403012772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 4U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14373U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 9944U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13067U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12145U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 11274974230580265396U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 13U)) + 16658438747342741547U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 16612986966106053844U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 5U)) + 9329502236843231290U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 14088261356708344656U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 13692608802007789581U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 58U)) + 6824473946645682398U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2072915876348570040U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7420507753044460759U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13239288539564571257U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4677557318688502593U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15081678577055628459U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16659305295251177155U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7026792817486507482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14871665922943969918U;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6807734532159292872U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9233542707022629190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1205501586581350876U;
            aOrbiterB = RotL64((aOrbiterB * 2596053290311090589U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10878718669747466677U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterG = RotL64((aOrbiterG * 3031382633089381605U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 6U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 60U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22071U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 24298U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20416U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 17800U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 11U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 3U)) + 10336802574069791273U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 11U)) + 169025388197058936U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 36U)) + RotL64(aCarry, 5U)) + 6541354188379168846U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 27U)) + 16223920526599306104U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 53U)) + 12756613707692514808U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 5082475548176484035U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 4907435526952698526U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14236627073831834337U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11502511046130497584U;
            aOrbiterE = RotL64((aOrbiterE * 3460330807286625917U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3679044835550219497U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11254838916686736746U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10582608424233200966U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4628253464169957835U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3798386391743884889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1379331161819246587U;
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9816600392407327227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4807797577690520554U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2492057261148595922U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 12U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aPhaseCWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aPhaseCWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28098U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 26814U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30614U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 25637U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 12U)) + 12775735908960052604U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 11791373812080296887U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 2023912048504189380U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 29U)) + 17668828109963766893U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 19U)) + 558908629933941224U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 35U)) + 1479633119685446888U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15460320397843364063U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10059749397555469054U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9987633811929693924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10087337844580228269U;
            aOrbiterJ = RotL64((aOrbiterJ * 13817142288940843815U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4446204415503364254U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10611580584157624739U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3137391249289641509U;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9327201928815412810U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10675114832750356941U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + aPhaseCWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
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

void TwistExpander_Unholy_060_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    // GTwistRunTwist_D twist_loop_d (start)
    {
        // GTwistRunTwist_D twist_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5511U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 4556U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2746U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 7310U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 11274974230580265396U) + aPhaseDOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 43U)) + 16658438747342741547U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 16612986966106053844U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 9329502236843231290U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 19U)) + 14088261356708344656U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13692608802007789581U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6824473946645682398U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13619437545775237601U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2072915876348570040U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7420507753044460759U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13239288539564571257U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4677557318688502593U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15081678577055628459U;
            aOrbiterG = RotL64((aOrbiterG * 16659305295251177155U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7026792817486507482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterI = RotL64((aOrbiterI * 694073180313083145U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17882797335141303280U;
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 24U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11058U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15519U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15030U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8515U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 12775735908960052604U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 11791373812080296887U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 26U)) + 5537362877706057303U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 2023912048504189380U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 3U)) + 17668828109963766893U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 558908629933941224U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1479633119685446888U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15460320397843364063U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterI = RotL64((aOrbiterI * 8671817118586065469U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9987633811929693924U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4446204415503364254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9430197906134676162U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1226048679997253363U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 14U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererG, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16460U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 18208U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21670U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21200U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 35U)) + 5697928251815176134U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 20U)) + RotL64(aCarry, 51U)) + 337587740689259575U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + 4927686903263973950U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 3742409032569801033U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 1608092659172197650U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15848744267145717509U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15300174177963339253U;
            aOrbiterD = RotL64((aOrbiterD * 5771922862677667319U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14162868453323648628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12020167069983729869U;
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16259538291658723956U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8516686212464112245U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3722184575520553132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15265344442454471986U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3050323350098829515U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 10U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30926U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 24585U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30672U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 27684U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererC + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 17264605017518259932U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 29U)) + 15209184354580778643U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 11U)) + 3299527965014731384U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 16293096431816127821U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 11031983436878828337U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9188018632448236358U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13420816400363406556U;
            aOrbiterD = RotL64((aOrbiterD * 10958221259662190519U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2485063384097917101U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3089135816938128264U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8813152992957361153U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10730544971770435788U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14883796491656899074U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13465877783538483706U;
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13322163435314643713U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3307316600284371955U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 52U) + aOrbiterK) + RotL64(aOrbiterD, 58U));
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)
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
