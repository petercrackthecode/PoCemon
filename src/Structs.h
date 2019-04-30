#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <queue>
#include "Ability.h"
#include "Player.h"

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


struct BattleEvent
{
    Pocemon *source;
    Pocemon *target;
    Ability *abilitySource;
    Player *PlayerSource;
    bool isSucess;
    int amount;
    
    enum class BattleEventType
    {
        PocemonSwitched,
        AbilityUsed,
        AbilityMissed,
        AbilityDamageDealt, // Display how much damage was done.
        AbilityHpHealed,
        CriticalHit, // Display if the attack was a critical hit.
        Effective, // Display if the attack was 'super effective' or 'not very effective'
        StatusEffectApplied, // Display if the a new status effect was applied.
        StatusEffectRemoved, // Display if an existing status effect was removed.
        StatusEffectDamageDealt, // do poison/burn/leech seed damage.
        StatusEffectHpHealed, // do leech seed healing.
        PocemonFainted,
        PlayerDefeated,
    };
};


#endif
