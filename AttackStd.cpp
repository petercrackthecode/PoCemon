#include "AttackStd.h"


AttackStd::AttackStd(const std::string &tempName,
                     const std::string &tempDescription,
                     const std::string &tempDevDescription,
                     const Type &tempType,
                     const int &tempPower,
                     const int &tempAccuracy,
                     const int &tempMaxPP)
{
    name = tempName;
    description = tempDescription;
         tempDevDescription;
        tempType;
        tempPower;
        tempAccuracy;
        tempMaxPP;
}

bool AttackStd::preCombat(Pocemon attacker, Pocemon defender)
{

}

bool AttackStd::mainEffect(Pocemon attacker, Pocemon defender)
{

}

bool AttackStd::postCombat(Pocemon attacker, Pocemon defender)
{

}