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
    BattleEvent evt = battleEvents.front();
    return evt;
}


BattleEvent Battle::extractNextEvent()
{
    BattleEvent evt = battleEvents.front();
    battleEvents.pop();
    return evt;
}