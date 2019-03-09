#ifndef POCEMON_H
#define POCEMON_H

#include <string>
#include "Enums.h"

class Pocemon
{
public: //private:
    PkmnId id;
    int level;

    std::string name;
    Type type1;
    Type type2;

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

    static int calculateStat(const int &lvl, const int &baseStat,
                             const int &ivStat = 0, const int &evStat = 0,
                             const bool &sHp = false);

public:
    Pocemon(const PkmnId &selectedId, const int &lvl);


};







#endif