#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "Enums.h"
#include "PoCemon.h"

class Ability
{
public:
    virtual Ability(const std::string &tempName,
                    const std::string &tempDescription,
                    const std::string &tempDevDescription,
                    const Type &tempType,
                    const int &tempPower,
                    const int &tempAccuracy,
                    const int &tempMaxPP) = 0;

    virtual bool preCombat(Pocemon attacker, Pocemon defender) = 0;
    virtual bool mainEffect(Pocemon attacker, Pocemon defender) = 0;
    virtual bool postCombat(Pocemon attacker, Pocemon defender) = 0;

private:
    const std::string name;
    const std::string description;
    const std::string devDescription; // Just saving a description for us to reference.
    const Type type;

    const int power;
    const int accuracy;
    const int maxPP;


};

#endif