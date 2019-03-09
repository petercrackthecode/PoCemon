#ifndef POCEMONDATA_H
#define POCEMONDATA_H

#include <string>
#include "Enums.h"

class PocemonData
{
public:
    std::string name;
    Type type1;
    Type type2;

    int baseHp;
    int baseAtk;
    int baseDef;
    int baseSpeed;
    int baseSpAtk;
    int baseSpDef;

    // These will probably remain public:
    const static PocemonData *allData;
    static std::string getTypeName(Type type);
    static PocemonData* defineAllPocemonData();

    PocemonData(std::string tempName, 
                Type tempType1,
                Type tempType2,
                int tempBaseHp,
                int tempBaseAtk,
                int tempBaseDef,
                int tempBaseSpeed,
                int tempBaseSpAtk,
                int tempBaseSpDef);
};



#endif