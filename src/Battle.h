#ifndef BATTLE_H
#define BATTLE_H

#include <queue>
#include "Player.h"
#include "Structs.h"

class Battle
{
public:
    Battle(Player &p1temp, Player &p2temp);
    Battle(const std::string &p1Name, const std::string &p2Name);

    bool next();
    static void addEvent(BattleEvent evt);
    BattleEvent extractNextEvent();

private:
    Player &p1;
    Player &p2;
    Player *attackingPlayer = nullptr;
    Player *defendingPlayer = nullptr;
    static std::queue<BattleEvent> battleEvents;

    // Probably getting rid of this:
    //enum class State
    //{
    //    AbilitySelection, // Waiting for players to select attacks.
    //    AttackMsg, // Display what attack is being used.
    //    DamageMsg, // Display how much damage was done (or miss).
    //    CriticalHitMsg, // Display if the attack was a critical hit.
    //    EffectiveMsg, // Display if the attack was 'super effective' or 'not very effective'
    //    NewStatusMsg, // Display if the defender received a new status effect.
    //    StatusDamageMsg, // do poison/burn/leech seed damage
    //    PocemonFainted,
    //    PlayerDefeated,
    //};
    //State state;
};

#endif
