#ifndef POCEMON_H
#define POCEMON_H

#include <string>
#include "PoCemonData.h"
#include "Enums.h"
#include "Combat.h"

class Pocemon : protected PocemonData
{
private:
    PkmnId id;
    std::string name;
    int level;

    Type type1;
    Type type2;

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

public:
    Pocemon(const PkmnId selectedId, const int lvl);


};







#endif