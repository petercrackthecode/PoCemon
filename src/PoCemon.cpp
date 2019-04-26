
#include "PoCemon.h"
#include "PoCemonData.h"
#include "Enums.h"
#include <cmath>
#include <iostream>
#include "Combat.h"
#include "AttackStd.h"
#include "Enums.h"
using namespace std;

int Pocemon::calculateStat(const int &lvl,
                           const int &baseStat,
                           const int &ivStat /* = 0 */,
                           const int &evStat /* = 0 */,
                           const bool &isHp /* = false*/)
{
    int stat;

    if (isHp)
        stat = lvl + 10;
    else
        stat = 5;

    // Note: Decimal is intentionally truncated.
    // Simplified version of the formula:
    // stat += (lvl * (2 * baseStat)) / 100;
    stat += (lvl * (2 * (baseStat + ivStat) + (sqrt(evStat) / 4))) / 100;
    return stat;
}

void Pocemon::doDamage(AttackStd *attack, Pocemon *pocemon1, Pocemon *pocemon2)
{

	//calculating damage that will be done to pocemon1, using statistics of pocemon2
	double modifier = Combat::getDmgMultiplier((attack->getType()), (pocemon2->type1), (pocemon2->type2));
	//from double to int - some errors might occur
	int damage = ((((2 + (2 * (pocemon2->level) / 5))* (attack->getPower()) * ((pocemon2->curAtk) / (pocemon2->curDef)) / 50) + 2)*modifier );
	//doing damage to pocemon1

	cout << pocemon1->curDef << endl;
	cout << pocemon1->curAtk << endl;
	cout << pocemon1->curSpDef << endl;
	cout << pocemon1->curSpAtk << endl;
	cout << pocemon1->curSpeed << endl;
	cout << pocemon1->curHp << endl;

	if (attack->getAbilityCategory() == AbilityCategory::Physical) {
		int newAtk = pocemon1->curAtk - damage;
		pocemon1->curAtk = newAtk;
		int newDef = pocemon1->curDef - damage;
		pocemon1->curDef = newDef;

		cout << pocemon1->curDef << endl;
		cout << pocemon1->curAtk << endl;
	}
	else if (attack->getAbilityCategory() == AbilityCategory::Special) {
		int newSpAtk = pocemon1->curSpAtk - damage;
		pocemon1->curSpAtk = newSpAtk;
		int newSpDef = pocemon1->curSpDef - damage;
		pocemon1->curSpDef = newSpDef;


		cout << pocemon1->curSpDef << endl;
		cout << pocemon1->curSpAtk << endl;
	}
	else if (attack->getAbilityCategory() == AbilityCategory::Status) {
		int newHp = pocemon1->curHp - damage;
		pocemon1->curHp = newHp;
		int newSpeed = pocemon1->curSpeed - damage;
		pocemon1->curSpeed = newSpeed;


		cout << pocemon1->curSpeed << endl;
		cout << pocemon1->curHp << endl;
	}

	//else {
		//	throw "No attack type found";
	//}

	//ofstream battlestat;
	//battlestat.open("battlestat.txt");
	//battlestat << pocemon2->id << " caused damage to " << pocemon1->id << "." << endl;
	//pocemon1.savedata();
	//ofstream battlestatUser;
	//battlestatser.open("battlestatUser.txt");
	//battlestat << pocemon2->id << " caused damage to " << pocemon1->id << "." << endl;

}




template <class BasicAttributeReturn>
BasicAttributeReturn Pocemon::getBasicAttribute(BasicAttribute type) const {
    if (type == BasicAttribute::id) return id;
    if (type == BasicAttribute::level) return level;
    if (type == BasicAttribute::name) return name;
    if (type == BasicAttribute::type1) return type1;

    return type2;
}


int Pocemon::getStat(Stat type) const {
    if (type == Stat::hp) return hp;
    if (type == Stat::attack) return atk;
    if (type == Stat::speed) return speed;
    if (type == Stat::spAttack) return spAtk;

    return spDef;
}
