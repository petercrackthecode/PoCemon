#ifndef COMBAT_H
#define COMBAT_H

#include "Enums.h"

// This class is totally incomplete right now.
class Combat
{
	// This will probably become private/protected.
private:
	// Damage Multiplier Table
	const static float dmgMultTbl[][19]; 
public:
	static float getDmgMultiplier(const Type &atkType,
								  const Type &defenderType1,
								  const Type &defenderType2 = Type::None);
};

#endif