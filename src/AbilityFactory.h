#ifndef ABILITYFACTORY_H
#define ABILITYFACTORY_H

#include <map>
#include "Ability.h"
#include "AttackAbility.h"
#include "Enums.h"

class AbilityFactory
{
public:
    static void init();
    static Ability* getAbility(const AbilityId &abilityId);

private:
    static std::map<AbilityId, Ability*> allAbilities;


};




#endif
