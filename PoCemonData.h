#ifndef POCEMONDATA_H
#define POCEMONDATA_H

#include <string>
#include "Enums.h"

class PocemonData
{
	// In the future, all these member variables will be changed to "proteced".
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
};



#endif