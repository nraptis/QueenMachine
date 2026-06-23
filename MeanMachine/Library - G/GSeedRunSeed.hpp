//
//  GSeedRunSeed.hpp
//  MeanMachine
//

#ifndef GSeedRunSeed_hpp
#define GSeedRunSeed_hpp

#include "GSeedRunStage.hpp"
#include <string>

class GSeedRunSeed_A {
public:
    explicit GSeedRunSeed_A(bool pUseNonces = true);
    ~GSeedRunSeed_A();

    bool                                    Plan(std::string *pErrorMessage);
    bool                                    Build(TwistProgramBranch &pBranch, std::string *pErrorMessage);

private:
    void                                    Reset();

    GSeedRunStage                           mStage;
    bool                                    mUseNonces;
};

class GSeedRunSeed_B {
public:
    explicit GSeedRunSeed_B(bool pUseNonces = false);
    ~GSeedRunSeed_B();

    bool                                    Plan(std::string *pErrorMessage);
    bool                                    Build(TwistProgramBranch &pBranch, std::string *pErrorMessage);

private:
    void                                    Reset();

    GSeedRunStage                           mStage;
    bool                                    mUseNonces;
};

class GSeedRunSeed_C {
public:
    explicit GSeedRunSeed_C(bool pUseNonces = false);
    ~GSeedRunSeed_C();

    bool                                    Plan(std::string *pErrorMessage);
    bool                                    Build(TwistProgramBranch &pBranch, std::string *pErrorMessage);

private:
    void                                    Reset();

    GSeedRunStage                           mStage;
    bool                                    mUseNonces;
};

class GSeedRunSeed_D {
public:
    explicit GSeedRunSeed_D(bool pUseNonces = false);
    ~GSeedRunSeed_D();

    bool                                    Plan(std::string *pErrorMessage);
    bool                                    Build(TwistProgramBranch &pBranch, std::string *pErrorMessage);

private:
    void                                    Reset();

    GSeedRunStage                           mStage;
    bool                                    mUseNonces;
};

#endif /* GSeedRunSeed_hpp */
