#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "Enums.h"
class Pocemon;

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
            const int &tempMaxPP,
            const int &tempStatusEffectChance)
        : id{ tempId }, name{ tempName }, description{ tempDescription }, type{ tempType },
        abilityCategory{ tempAbilityCategory }, power{ tempPower }, accuracy{ tempAccuracy },
        maxPP{ tempMaxPP }, statusEffectChance{ tempStatusEffectChance }
    {};

    virtual bool use(Pocemon &attacker, Pocemon &defender) = 0;
	AbilityCategory getAbilityCategory() const { return abilityCategory; }
	Type getType() const { return type; }
	int getPower() const { return power; }

    virtual float getDmgMultiplier(Pocemon &defender) const;
    // Change to protected/private:
    static const float dmgMultTbl[][19];

protected:
    const int id; // TODO: Change to AbilityId
    const std::string name;
    const std::string description;
    const std::string devDescription; // Just saving a description for us to reference.
    const Type type;
    const AbilityCategory abilityCategory;

    const int power;
    const int accuracy;
    const int maxPP;
    const int statusEffectChance;

    struct AbilityData
    {
        const AbilityId id;
        const std::string name;
        const std::string description;
        //const std::string devDescription; // Just saving a description for us to reference.
        const Type type;
        const AbilityCategory abilityCategory;

        const int power;
        const int accuracy;
        const int maxPP;
        const int statusEffectChance;
    };

    const static AbilityData allAbilityData[55];

};

#endif
