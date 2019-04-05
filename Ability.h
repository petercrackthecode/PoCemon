#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "Enums.h"
#include "PoCemon.h"

class Ability
{
public:
    Ability(const int &tempId,
            const std::string &tempName,
            const std::string &tempDescription,
            //const std::string &tempDevDescription,
            const Type &tempType,
            const AbilityCategory &tempAbilityCategory,
            const int &tempPower,
            const int &tempAccuracy,
            const int &tempMaxPP)
        : id{ tempId }, name{ tempName }, description{ tempDescription }, type{ tempType },
        abilityCategory{ tempAbilityCategory }, power{ tempPower }, accuracy{ tempAccuracy }, maxPP{ tempMaxPP }
    {};

    virtual bool preCombat(Pocemon attacker, Pocemon defender) = 0;
    virtual bool mainEffect(Pocemon attacker, Pocemon defender) = 0;
    virtual bool postCombat(Pocemon attacker, Pocemon defender) = 0;


protected:
    const int id;
    const std::string name;
    const std::string description;
    const std::string devDescription; // Just saving a description for us to reference.
    const Type type;
    const AbilityCategory abilityCategory;

    const int power;
    const int accuracy;
    const int maxPP;


};

#endif
