#include <iostream>
#include <string>
#include "Battle.h"
#include "Structs.h"

using namespace std;

std::queue<BattleEvent> Battle::battleEvents;

Battle::Battle()
{
	while (battleEvents.size() > 0)
		battleEvents.pop();
}

void Battle::set(Player *p1temp, Player *p2temp)
{
	p1 = p1temp;
	p2 = p2temp;
	p1->generateRandomTeam();
	p2->generateRandomTeam();
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


void Battle::handleEventCommand()
{
	if (eventPending()) {
		currentEvt = extractNextEvent();
		//bEvtMsg.setString(bEvtCurrent.toString());
		if (currentEvt.type == BEvtType::PocemonFainted) {
			//if (iPoceP1 != static_cast<int>(p1.getActivePocemon()->getId()))
			//	iPoceP1 = 152;
			//if (iPoceP2 != static_cast<int>(p2.getActivePocemon()->getId()))
			//	iPoceP2 = 152;
		}
		else if (currentEvt.type == BEvtType::PocemonDeployed)
		{
			//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
			//iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
		}
	}
	else {
		//bEvtMsg.setString("");
		setContinue();
	}
}


void Battle::setP1Action(int i)
{
	if (p1Action == -1)
	{
		p1Action = i;
		p1Screen = -1;
		++pendingActions;
	}
};

void Battle::setP2Action(int i)
{
	if (p2Action == -1)
	{
		p2Action = i;
		p2Screen = -1;
		++pendingActions;
	}
};


void Battle::setAttackingPriority()
{
	int p1Speed = p1->getActivePocemon()->getCurSpeed();
	int p2Speed = p2->getActivePocemon()->getCurSpeed();

	if (p2Speed > p1Speed)
	{
		attackingPlayer = p2;
		defendingPlayer = p1;
	}
	else
	{
		attackingPlayer = p1;
		defendingPlayer = p2;
	}
}


void Battle::switchPlayerRoles()
{
	if (p1 == attackingPlayer)
	{
		cout << "switching p1 to defend\n";
		attackingPlayer = p2;
		defendingPlayer = p1;
	}
	else
	{
		cout << "switching p1 to attack\n";
		attackingPlayer = p1;
		defendingPlayer = p2;
	}
	--pendingActions;
}

void Battle::toggleP1PoceMenu()
{
	if (p1Action == -1)
	{
		if (p1Screen == 0)
			p1Screen = 1;
		else if (p1Screen > 0)
			p1Screen = 0;
	}
}


void Battle::toggleP2PoceMenu()
{
	if (p2Action == -1)
	{
		if (p2Screen == 0)
			p2Screen = 1;
		else if (p2Screen > 0)
			p2Screen = 0;
	}
}


bool Battle::isP1PoceMenuOpen()
{
	if (p1Screen > 0)
		return true;
	else
		return false;
};


bool Battle::isP2PoceMenuOpen()
{
	if (p2Screen > 0)
		return true;
	else
		return false;
};


bool Battle::isP1UsingAbility() const
{
	if (currentEvt.source->getOwner() == p1 && currentEvt.type == BEvtType::AbilityUsed)
		return true;
	else
		return false;
}


bool Battle::isP2UsingAbility() const
{
	if (currentEvt.source->getOwner() == p2 && currentEvt.type == BEvtType::AbilityUsed)
		return true;
	else
		return false;
}


bool Battle::isP1TakingDamage() const
{
	if (currentEvt.target->getOwner() == p1 && currentEvt.type == BEvtType::AbilityDamageDealt)
		return true;
	else
		return false;
}


bool Battle::isP2TakingDamage() const
{
	if (currentEvt.target->getOwner() == p2 && currentEvt.type == BEvtType::AbilityDamageDealt)
		return true;
	else
		return false;
}


bool Battle::isP1Invisible() const
{
	if (currentEvt.playerSource == p1 && currentEvt.type == BEvtType::PocemonWithdrawn)
		return true;
	else if (currentEvt.target->getOwner() == p1 && currentEvt.type == BEvtType::PocemonFainted )
		return true;
	else
		return false;
}


bool Battle::isP2Invisible() const
{
	if (currentEvt.playerSource == p2 && currentEvt.type == BEvtType::PocemonWithdrawn)
		return true;
	else if (currentEvt.target->getOwner() == p2 && currentEvt.type == BEvtType::PocemonFainted)
		return true;
	else
		return false;
}
