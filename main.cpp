// main.cpp : Defines the entry point for the application.

#include "PoCemon.h"
#include "Combat.h"
#include "Enums.h"
#include "PoCemonData.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// The program just does 2 things right now.

	// 1. Lists the base stats for all PoCemon.
	cout << setw(3) << "ID" << setw(17) << "Name"
		<< setw(10) << "Type1" << setw(10) << "Type2"
		<< setw(4) << "HP" << setw(4) << "Atk" << setw(4) << "Def"
		<< setw(4) << "Spd" << setw(6) << "spAtk" << setw(6) << "spDef"
		<<endl;
	
	for (int i = 0; i < 152; ++i)
	{
		cout << setw(3) << i << setw(17) << PocemonData::allData[i].name
			<< setw(10) << PocemonData::getTypeName(PocemonData::allData[i].type1)
			<< setw(10) << PocemonData::getTypeName(PocemonData::allData[i].type2)
			<< setw(4) << PocemonData::allData[i].baseHp
			<< setw(4) << PocemonData::allData[i].baseAtk
			<< setw(4) << PocemonData::allData[i].baseDef
			<< setw(4) << PocemonData::allData[i].baseSpeed
			<< setw(6) << PocemonData::allData[i].baseSpAtk
			<< setw(6) << PocemonData::allData[i].baseSpDef
			<< endl;
		//cout << Pocemon::allData[i].name << endl;
	}

	cout << endl << endl;

	// 2. Shows some examples of damage multipliers.
	cout << "********************************" << endl;
	cout << "** Example Damage Multipliers **" << endl;
	cout << "********************************" << endl << endl;

	cout << "Super Effective:" << endl;
	cout << "A Water attack does "
		<< Combat::getDmgMultiplier(Type::Water, Type::Fire) * 100
		<< "% damage to a Fire PoCemon." << endl << endl;

	cout << "Not Very Effective...:" << endl;
	cout << "A Fire attack does "
		<< Combat::getDmgMultiplier(Type::Fire, Type::Water) * 100
		<< "% damage to a Water PoCemon." << endl << endl;

	cout << "Double Resistance (Not Very Effective... x2):" << endl;
	cout << "A Fire attack does "
		<< Combat::getDmgMultiplier(Type::Fire, Type::Water, Type::Rock) * 100
		<< "% damage to a PoCemon that is both Water & Rock." << endl << endl;

	cout << "Super Effective (again):" << endl;
	cout << "A Fire attack does "
		<< Combat::getDmgMultiplier(Type::Fire, Type::Grass) * 100
		<< "% damage to a Grass PoCemon." << endl << endl;

	cout << "DOUBLE Super Effective!:" << endl;
	cout << "A Fire attack does "
		<< Combat::getDmgMultiplier(Type::Fire, Type::Grass, Type::Bug) * 100
		<< "% damage to a PoCemon that is both Grass & Bug." << endl << endl;


	cin.get();
	return 0;
}
