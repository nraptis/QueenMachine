//
//  GTwistRunGrowKeyA.hpp
//  MeanMachine
//

#ifndef GTwistRunGrowKeyA_hpp
#define GTwistRunGrowKeyA_hpp

#include "GSeedRunStage.hpp"

#include <string>

class GTwistRunGrowKeyA {
public:
    GTwistRunGrowKeyA();
    ~GTwistRunGrowKeyA();

    bool                                    Plan(std::string *pErrorMessage);
    bool                                    Build(TwistProgramBranch &pBranch,
                                                  std::string *pErrorMessage);

private:
    void                                    Reset();

    GSeedRunStage                           mExpandAStage;
    GSeedRunStage                           mExpandBStage;
    GSeedRunStage                           mKeyRowStage;
};

class GTwistRunGrowKeyB {
public:
    GTwistRunGrowKeyB();
    ~GTwistRunGrowKeyB();

    bool                                    Plan(std::string *pErrorMessage);
    bool                                    Build(TwistProgramBranch &pBranch,
                                                  std::string *pErrorMessage);

private:
    void                                    Reset();

    GSeedRunStage                           mExpandAStage;
    GSeedRunStage                           mExpandBStage;
    GSeedRunStage                           mKeyRowStage;
};

#endif /* GTwistRunGrowKeyA_hpp */
