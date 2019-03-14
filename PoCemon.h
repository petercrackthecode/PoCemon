#ifndef POCEMON_H
#define POCEMON_H

#include <string>
#include "Enums.h"

class Pocemon
{
public: //private:
    // Creates a PoCemon at the requested level.
    Pocemon(const PkmnId &selectedId, const int &lvl);



    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    // Calcualates an individual stat value. 
    // If calculating HP, set "isHp" to true.
    static int calculateStat(const int &lvl,
                             const int &baseStat,
                             const int &ivStat = 0,
                             const int &evStat = 0,
                             const bool &isHp = false);

    PkmnId id;
    int level;

    std::string name;
    Type type1;
    Type type2;

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

    int hp;
    int atk;
    int def;
    int speed;
    int spAtk;
    int spDef;

    int baseHp;
    int baseAtk;
    int baseDef;
    int baseSpeed;
    int baseSpAtk;
    int baseSpDef;

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