#pragma once

#include "TwistExpander.hpp"

class Candidate_A : public TwistExpander {
public:
    Candidate_A();
    ~Candidate_A() override = default;

    void KDF_A(std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet) override;
    void KDF_B(std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet) override;
    void Seed(TwistWorkSpace *pWorkSpace,
              TwistFarmSalt *pFarmSalt,
              std::uint64_t pNonce,
              std::uint8_t *pSourceInput,
              std::uint8_t *pPassword,
              unsigned int pPasswordByteLength,
              std::uint8_t *pDestination) override;
    void TwistBlock(TwistWorkSpace *pWorkSpace,
                    std::uint64_t pNonce,
                    std::uint8_t *pSourceInput,
                    std::size_t pBlockIndex,
                    std::size_t pBlockCount,
                    std::uint8_t *pDestination) override;
    void GrowKeyA(TwistWorkSpace *pWorkSpace) override;
    void GrowKeyB(TwistWorkSpace *pWorkSpace) override;

private:
    static const TwistDomainSaltSet kPhaseASalts;
    static const TwistDomainConstants kPhaseAConstants;
    static const TwistDomainSaltSet kPhaseBSalts;
    static const TwistDomainConstants kPhaseBConstants;
    static const TwistDomainSaltSet kPhaseCSalts;
    static const TwistDomainConstants kPhaseCConstants;
    static const TwistDomainSaltSet kPhaseDSalts;
    static const TwistDomainConstants kPhaseDConstants;
};
