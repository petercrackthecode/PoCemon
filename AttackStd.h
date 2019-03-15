#ifndef ATTACKSTD_H
#define ATTACKSTD_H

#include <string>
#include "Enums.h"
#include "Ability.h"

class AttackStd : public Ability
{
public:
    AttackStd(const int &tempId,
              const std::string &tempName,
              const std::string &tempDescription,
              //const std::string &tempDevDescription,
              const Type &tempType,
              const AbilityCategory &tempAbilityCategory,
              const int &tempPower,
              const int &tempAccuracy,
              const int &tempMaxPP);

    bool preCombat(Pocemon attacker, Pocemon defender);
    bool mainEffect(Pocemon attacker, Pocemon defender);
    bool postCombat(Pocemon attacker, Pocemon defender);



private:

};

#endif