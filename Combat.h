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
    static const float dmgMultTbl[][19];
};

#endif
