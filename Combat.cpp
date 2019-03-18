#include "Combat.h"
#include "Enums.h"

// This class is totally incomplete right now.

float Combat::getDmgMultiplier(const Type &atkType,
                               const Type &defenderType1,
                               const Type &defenderType2 /* = Type::None */)
{
    int atkTypeInt = static_cast<int>(atkType);
    int defenderType1Int = static_cast<int>(defenderType1);
    int defenderType2Int = static_cast<int>(defenderType2);

    float dmgMultiplier = dmgMultTbl[atkTypeInt][defenderType1Int];
    dmgMultiplier = dmgMultiplier * dmgMultTbl[atkTypeInt][defenderType2Int];

    return dmgMultiplier;
}

// Damage Multiplier Table
// See 'main.cpp' for an example of how this table works.
// Also see this website: https://bulbapedia.bulbagarden.net/wiki/Type/Type_chart

