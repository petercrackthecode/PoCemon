#ifndef POCEMON_H
#define POCEMON_H

#include <string>
#include "Enums.h"
#include "PoCemonData.h"
#include "Combat.h"
#include "AttackStd.h"

class Pocemon
{
public: //private:
    // Creates a PoCemon at the requested level.
    Pocemon(const PkmnId &selectedId, const int &lvl);
	void doDamage(AttackStd *attack, Pocemon *pocemon1, Pocemon *pocemon2);

    template <class BasicAttributeReturn>
    BasicAttributeReturn getBasicAttribute(BasicAttribute type) const;

    int getStat(Stat type) const;


    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    // Calculates an individual stat value.
    // If calculating HP, set "isHp" to true.
    static int calculateStat(const int &lvl,
                             const int &baseStat,
                             const int &ivStat = 0,
                             const int &evStat = 0,
                             const bool &isHp = false);


    PkmnId id; // Need Getter
    int level; // Need Getter

    std::string name; // Need Getter
    Type type1; // Need Getter
    Type type2; // Need Getter

    // TODO: I'm considering creating a Struct that holds all
    //       six stats (hp, atk, def, speed, spAtk, and spDef).
    //       Each PoCemon would have 4 of those Structs.
    //       (i.e, one for current stats, one for base stats,
    //        one for iv stats, and one for ev stats.)

    int curHp;
    int curAtk;
    int curDef;
    int curSpeed;
    int curSpAtk;
    int curSpDef;

    // Treat these as const during a fight:
    int hp; // Need Getter
    int atk; // Need Getter
    int def; // Need Getter
    int speed; // Need Getter
    int spAtk; // Need Getter
    int spDef; // Need Getter

    int baseHp;
    int baseAtk;
    int baseDef;
    int baseSpeed;
    int baseSpAtk;
    int baseSpDef;

    // Varation between different Pikachu
    int ivHp;
    int ivAtk;
    int ivDef;
    int ivSpeed;
    int ivSpAtk;
    int ivSpDef;

    int evHp;
    int evAtk;
    int evDef;
    int evSpeed;
    int evSpAtk;
    int evSpDef;

	

};


#endif
