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

    AttackAbility(const AbilityId &tempId,
                  const std::string &tempName,
                  const std::string &tempDescription,
                  //const std::string &tempDevDescription,
                  const Type &tempType,
                  const AbilityCategory &tempAbilityCategory,
                  const int &tempPower,
                  const int &tempAccuracy,
                  const int &tempMaxPP,
                  const int &tempStatusEffectChance,
                  const StatusEffect &tempStatusEffectType);

    virtual ~AttackAbility() {};

    bool use(Pocemon &attacker, Pocemon &defender) override;

    int calculateHitThreshold(Pocemon &attacker, Pocemon &defender) const;
    bool doesAttackHit(Pocemon &attacker, Pocemon &defender) const;

private:

};

#endif
