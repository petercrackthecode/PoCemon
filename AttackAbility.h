#ifndef ATTACKABILITY_H
#define ATTACKABILITY_H

#include <string>
#include "Enums.h"
#include "Ability.h"
class Pocemon;

// TODO: Rename to AttackAbility
class AttackAbility : public Ability
{
public:

    AttackAbility(const int &tempId,
              const std::string &tempName,
              const std::string &tempDescription,
              //const std::string &tempDevDescription,
              const Type &tempType,
              const AbilityCategory &tempAbilityCategory,
              const int &tempPower,
              const int &tempAccuracy,
              const int &tempMaxPP,
              const int &tempStatusEffectChance);

    virtual ~AttackAbility() {};

    bool use(Pocemon &attacker, Pocemon &defender) override;

private:

};

#endif
