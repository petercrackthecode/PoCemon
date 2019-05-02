#include <iostream>
#include <string>
#include "Battle.h"
#include "Structs.h"

using namespace std;

std::queue<BattleEvent> Battle::battleEvents;

Battle::Battle(Player &p1temp, Player &p2temp) : p1(p1temp), p2(p2temp)
{
    while (battleEvents.size() > 0)
        battleEvents.pop();
}


void Battle::addEvent(BattleEvent evt)
{
    battleEvents.push(evt);
};


BattleEvent Battle::peekNextEvent()
{
    if (battleEvents.empty())
        throw "No events pending"; // TODO: Class exception.

    BattleEvent evt = battleEvents.front();
    return evt;
}


BattleEvent Battle::extractNextEvent()
{
    if (battleEvents.empty())
        throw "No events pending"; // TODO: Class exception.

    BattleEvent evt = battleEvents.front();
    battleEvents.pop();
    return evt;
}


bool Battle::eventPending() const
{
    if (battleEvents.empty())
        return false;
    else
        return true;
}


void Battle::setP1Action(int i)
{
    if (p1Action == -1)
    {
        p1Action = i;
        ++pendingActions;
    }
};

void Battle::setP2Action(int i)
{
    if (p2Action == -1)
    {
        p2Action = i;
        ++pendingActions;
    }
};


void Battle::setAttackingPriority()
{
    int p1Speed = p1.getActivePocemon()->getCurSpeed();
    int p2Speed = p2.getActivePocemon()->getCurSpeed();

    if (p2Speed > p1Speed)
    {
        attackingPlayer = &p2;
        defendingPlayer = &p1;
    }
    else
    {
        attackingPlayer = &p1;
        defendingPlayer = &p2;
    }
}


void Battle::switchPlayerRoles()
{
    if (&p1 == attackingPlayer)
    {
        cout << "switching p1 to defend\n";
        attackingPlayer = &p2;
        defendingPlayer = &p1;
    } else
    {
        cout << "switching p1 to attack\n";
        attackingPlayer = &p1;
        defendingPlayer = &p2;
    }
    --pendingActions;
}
