<<<<<<< HEAD
/*
 * Combat.h
 *
 *  Created on: Mar 18, 2019
 *      Author: dungnguyen
 */

=======
>>>>>>> 715ca8e7d67d3f02e313e4636252527cc330a23c
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

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 715ca8e7d67d3f02e313e4636252527cc330a23c
