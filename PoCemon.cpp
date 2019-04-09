
#include "PoCemon.h"
#include "PoCemonData.h"
#include "Enums.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Combat.h"
#include "AttackStd.h"
#include "Enums.h"
#include "randomGenerator.h"
using namespace std; 
Pocemon::Pocemon(const PkmnId &selectedId, const int &lvl)
{
    int tempId = static_cast<int>(selectedId);

    id = selectedId;
    level = lvl;
    name = PocemonData::allData[tempId].name;
    type1 = PocemonData::allData[tempId].type1;
    type2 = PocemonData::allData[tempId].type2;

    baseHp = PocemonData::allData[tempId].baseHp;
    baseAtk = PocemonData::allData[tempId].baseAtk;
    baseDef = PocemonData::allData[tempId].baseDef;
    baseSpeed = PocemonData::allData[tempId].baseSpeed;
    baseSpAtk = PocemonData::allData[tempId].baseSpAtk;
    baseSpDef = PocemonData::allData[tempId].baseSpDef;

    // Normally, IV values are a random int from 0 to 15
    // TODO: Need to implement randomization.
    ivHp = 0;
    ivAtk = 0;
    ivDef = 0;
    ivSpeed = 0;
    ivSpAtk = 0;
    ivSpDef = 0;

    // EV values start at 0 and increase with each PoCemon defeated!
    evHp = 0;
    evAtk = 0;
    evDef = 0;
    evSpeed = 0;
    evSpAtk = 0;
    evSpDef = 0;

    hp = calculateStat(level, baseHp, ivHp, evHp, true);
    atk = calculateStat(level, baseAtk, ivAtk, evAtk);
    def = calculateStat(level, baseDef, ivDef, evDef);
    speed = calculateStat(level, baseSpeed, ivSpeed, evSpeed);
    spAtk = calculateStat(level, baseSpAtk, ivSpAtk, evSpAtk);
    spDef = calculateStat(level, baseSpDef, ivSpDef, evSpDef);

    resetCurStats();
}


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

// Used to reset a PoCemon's 'cur' stats after a battle.
void Pocemon::resetCurStats()
{
    curHp = hp;
    curAtk = atk;
    curDef = def;
    curSpeed = speed;
    curSpAtk = spAtk;
    curSpDef = spDef;
}


void Pocemon::doDamage(const AttackStd &attack, Pocemon &defendingPocemon)
{
    int tempAtk;
    int tempDef;

    if (attack.getAbilityCategory() == AbilityCategory::Physical)
    {
        tempAtk = this->curAtk;
        tempDef = defendingPocemon.curDef;
    }
    else // if (attack.getAbilityCategory() == AbilityCategory::Special)
    {
        tempAtk = this->curSpAtk;
        tempDef = defendingPocemon.curSpDef;
    }


	//calculating damage that will be done to defendingPocemon, using statistics of defendingPocemon
	double modifier = Combat::getDmgMultiplier(attack.getType(), defendingPocemon.type1, defendingPocemon.type2);
	//from double to int - some errors might occur
	int damage = ((((2 + (2 * this->level / 5)) * attack.getPower() * (tempAtk / tempDef) / 50) + 2 ) * modifier ); // TODO: double check proper order for "(2 * this->level / 5)"
	//doing damage to defendingPocemon

    // Random modifier
    // Description: Multiply 'damage' by a random percentage between 0.85 (217÷255) and 1.00 (255÷255).
    // In other words, multiply 'damage' by a random integer between 217 and 255 (inclusive), followed by an integer division by 255.
    damage = (damage * randomGenerator(217, 255)) / 255;

    cout << this->name << " did " << damage << " damage to " << defendingPocemon.name << endl;
    int newHp = defendingPocemon.curHp - damage;
    defendingPocemon.curHp = newHp;

    return;
	

	//ofstream battlestat;
	//battlestat.open("battlestat.txt");
	//battlestat << pocemon2->id << " caused damage to " << defendingPocemon->id << "." << endl;
	//defendingPocemon.savedata();
	//ofstream battlestatUser;
	//battlestatser.open("battlestatUser.txt");
	//battlestat << pocemon2->id << " caused damage to " << defendingPocemon->id << "." << endl;

}


void Pocemon::displayInfo(bool detailed /*= false*/)
{
    cout << endl;
    cout << this->name << ", lvl " << this->level << endl;
    
    cout << setw(9) << "**Stats**"
        << setw(6) << "hp"
        << setw(6) << "atk"
        << setw(6) << "def"
        << setw(6) << "spAtk"
        << setw(6) << "spDef"
        << setw(6) << "speed" << endl;

    cout << setw(9) << "Current:"
        << setw(6) << this->curHp
        << setw(6) << this->curAtk
        << setw(6) << this->curDef
        << setw(6) << this->curSpAtk
        << setw(6) << this->curSpDef
        << setw(6) << this->curSpeed << endl;

    cout << setw(9) << "Original:"
        << setw(6) << this->hp
        << setw(6) << this->atk
        << setw(6) << this->def
        << setw(6) << this->spAtk
        << setw(6) << this->spDef
        << setw(6) << this->speed << endl;

    if (detailed)
    {
        cout << setw(9) << "Base:"
            << setw(6) << this->baseHp
            << setw(6) << this->baseAtk
            << setw(6) << this->baseDef
            << setw(6) << this->baseSpAtk
            << setw(6) << this->baseSpDef
            << setw(6) << this->baseSpeed << endl;

        cout << setw(9) << "IV:"
            << setw(6) << this->ivHp
            << setw(6) << this->ivAtk
            << setw(6) << this->ivDef
            << setw(6) << this->ivSpAtk
            << setw(6) << this->ivSpDef
            << setw(6) << this->ivSpeed << endl;

        cout << setw(9) << "EV:"
            << setw(6) << this->evHp
            << setw(6) << this->evAtk
            << setw(6) << this->evDef
            << setw(6) << this->evSpAtk
            << setw(6) << this->evSpDef
            << setw(6) << this->evSpeed << endl;
    }

    cout << endl;
    return;
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

