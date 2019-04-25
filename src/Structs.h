#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <queue>
#include "Ability.h"

struct AbilityOutcome
{
    Ability *ability;
    bool hit; // false = ability missed.
    bool criticalHit; // true = critical hit.

    int damageDealt;
    int hpHealed;

    bool statusEffectTriggered;
    
    
    std::queue<std::string> messages;
};


#endif
