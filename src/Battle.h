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
    BattleEvent peekNextEvent();
    BattleEvent extractNextEvent();
    bool eventPending() const;

    bool canContinue() const { return canContinueFlag; };
    void setContinue() { canContinueFlag = true; };
    void setPause() { canContinueFlag = false; };

    int getAttackerAction() { return (&p1 == attackingPlayer) ? p1Action : p2Action; };
    int getDefenderAction() { return (&p1 == defendingPlayer) ? p1Action : p2Action; };
    void setP1Action(int i);
    void setP2Action(int i);
    bool playersReady() { return (pendingActions == 2) ? true : false; };
    void resetPlayerActions() { p1Action = -1; p2Action = -1; };
    bool actionsPending() const { return (pendingActions > 0) ? true : false; }

    void setAttackingPriority();
    void switchPlayerRoles();

    Player* getAttackingPlayer() { return attackingPlayer; };
    Player* getDefendingPlayer() { return defendingPlayer; };

private:
    bool canContinueFlag = true;
    Player &p1;
    Player &p2;
    Player *attackingPlayer = nullptr;
    Player *defendingPlayer = nullptr;
    static std::queue<BattleEvent> battleEvents;
    int pendingActions = 0;
    int p1Action = -1;
    int p2Action = -1;

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
