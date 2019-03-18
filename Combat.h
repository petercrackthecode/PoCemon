/*
 * Combat.h
 *
 *  Created on: Mar 18, 2019
 *      Author: dungnguyen
 */

#ifndef COMBAT_H
#define COMBAT_H

#include "Enums.h"

// This class is totally incomplete right now.
class Combat
{
public:
    static float getDmgMultiplier(const Type &atkType,
                                  const Type &defenderType1,
                                  const Type &defenderType2 = Type::None);

private:
    // Damage Multiplier Table
    const static float dmgMultTbl[][19];
};

#endif
