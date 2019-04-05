#ifndef COMBAT_H
#define COMBAT_H

#include "Enums.h"

// This class is totally incomplete right now.
class Combat
{
public:
    static float getDmgMultiplier(const Type &atkType,
                                  const Type &defenderType1,
                                  const Type &defenderType2 = Type::undefined);


    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    // Damage Multiplier Table
    static const float dmgMultTbl[][19];
};

#endif
