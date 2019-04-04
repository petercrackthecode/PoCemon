#ifndef POCEMONDATA_H
#define POCEMONDATA_H

#include <string>
#include "Enums.h"
using namespace std;

class PocemonData
{
public:
    // Constructor for creating PoCemon base data/stats.
    PocemonData(std::string tempName,
                Type tempType1,
                Type tempType2,
                int tempBaseHp,
                int tempBaseAtk,
                int tempBaseDef,
                int tempBaseSpeed,
                int tempBaseSpAtk,
                int tempBaseSpDef);

    // Takes a Type enum and returns its name (as a string).
    static std::string getTypeName(Type type);

    // Defines all base PoCemon data/stats. 
    static PocemonData *defineAllPocemonData();

    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    // The array that holds base data/stats for all PoCemon.
    const static PocemonData *allData;

    std::string name;
    Type type1;
    Type type2;

    int baseHp;
    int baseAtk;
    int baseDef;
    int baseSpeed;
    int baseSpAtk;
    int baseSpDef;



};



#endif