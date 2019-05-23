#ifndef BATTLE_H
#define BATTLE_H

#include <queue>
#include "Player.h"
#include "Structs.h"

class Battle
{
public:
    Battle();
    Battle(const std::string &p1Name, const std::string &p2Name);

	void set(Player *p1temp, Player *p2temp);

    bool next();
    static void addEvent(BattleEvent evt);
    BattleEvent peekNextEvent();
    BattleEvent extractNextEvent();
    bool eventPending() const;
	void handleEventCommand();

    bool canContinue() const { return canContinueFlag; };
	void setContinue() { canContinueFlag = true; currentEvt = BattleEvent(); };
    void setPause() { canContinueFlag = false; };

    int getAttackerAction() { return (p1 == attackingPlayer) ? p1Action : p2Action; };
    int getDefenderAction() { return (p1 == defendingPlayer) ? p1Action : p2Action; };
    void setP1Action(int i);
    void setP2Action(int i);
    bool playersReady() { return (pendingActions == 2) ? true : false; };
	void resetPlayerActions() { p1Action = -1; p2Action = -1; pendingActions = 0; p1Screen = 0; p2Screen = 0; };
    bool actionsPending() const { return (pendingActions > 0) ? true : false; }

	bool isP1ActionSelected() const { return !(p1Action == -1); };
	bool isP2ActionSelected() const { return !(p2Action == -1); };

	void toggleP1PoceMenu();
	void toggleP2PoceMenu();
	bool isP1PoceMenuOpen();
	bool isP2PoceMenuOpen();
	void forceP1PoceMenuOpen() { p1Screen = 2; };
	void forceP2PoceMenuOpen() { p2Screen = 2; };

	bool isP1Fainted() const { return p1Screen == 2; }
	bool isP2Fainted() const { return p2Screen == 2; }
	bool isAnyoneFainted() const { return (isP1Fainted() || isP2Fainted()); };

	bool isP1UsingAbility() const;
	bool isP2UsingAbility() const;
	bool isP1TakingDamage() const;
	bool isP2TakingDamage() const;
	bool isP1Invisible() const;
	bool isP2Invisible() const;

    void setAttackingPriority();
    void switchPlayerRoles();

    Player* getAttackingPlayer() { return attackingPlayer; };
    Player* getDefendingPlayer() { return defendingPlayer; };

	BattleEvent currentEvt;
	Player *p1;
	Player *p2;

private:
    bool canContinueFlag = true;
    Player *attackingPlayer = nullptr;
    Player *defendingPlayer = nullptr;
    static std::queue<BattleEvent> battleEvents;
    int pendingActions = 0;
    int p1Action = -1;
    int p2Action = -1;
	int p1Screen = 0;
	int p2Screen = 0;

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
