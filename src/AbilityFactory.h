#ifndef ABILITYFACTORY_H
#define ABILITYFACTORY_H

#include <map>
#include <vector>
#include "Ability.h"
#include "AttackAbility.h"
#include "Enums.h"

class AbilityFactory
{
public:
    static void init();
    static Ability* getAbility(const AbilityId &abilityId);
    static Ability* getRandomAbility(const PkmnId &id);
    static std::vector<Ability*> getRandomAbilitySet(const Pocemon &pocemon);

    static Type getAbilityType(const AbilityId &id) { return getAbility(id)->getType(); };
    static AbilityCategory getAbilityCategory(const AbilityId &id) { return getAbility(id)->getAbilityCategory(); };

private:
    static std::map<AbilityId, Ability*> allAbilities;
    static std::map<PkmnId, std::vector<AbilityId>> abilityPools;

};




#endif
