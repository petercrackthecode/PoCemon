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
    // The program just does 3 things right now.

    // 1. Lists the base stats for all PoCemon.
    cout << setw(3) << "ID" << setw(17) << "Name"
        << setw(10) << "Type1" << setw(10) << "Type2"
        << setw(4) << "HP" << setw(4) << "Atk" << setw(4) << "Def"
        << setw(4) << "Spd" << setw(6) << "spAtk" << setw(6) << "spDef"
        << endl;
    
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
        << "% damage to a PoCemon that is both Grass & Bug." << endl << endl << endl;



    // 3. Lets you select an example PoCemon and displays its stats.
    cout << "*********************************" << endl;
    cout << "** Example PoCemon Constructor **" << endl;
    cout << "*********************************" << endl << endl;

    int exampleId = 0;
    int exampleLevel;

    cout << "Choose a PoCemon! (enter a number from 1 to 151) -> ";
    cin >> exampleId;

    while (exampleId >= 0)
    {
        cout << "What level? (enter a number from 1 to 99) -> ";
        cin >> exampleLevel;

        Pocemon pikablue(static_cast<PkmnId>(exampleId), exampleLevel);

        cout << endl << endl << "*** Here are your PoCemon's stats: ***" << endl
            << setw(10) << "Name: " << pikablue.name << endl
            << setw(10) << "Level: " << pikablue.level << endl
            << setw(10) << "Type1: " << PocemonData::getTypeName(pikablue.type1) << endl
            << setw(10) << "Type2: " << PocemonData::getTypeName(pikablue.type2) << endl
            << setw(10) << "HP: " << pikablue.hp << endl
            << setw(10) << "Attack: " << pikablue.atk << endl
            << setw(10) << "Defense: " << pikablue.def << endl
            << setw(10) << "Speed: " << pikablue.speed << endl
            << setw(10) << "spAtk: " << pikablue.spAtk << endl
            << setw(10) << "spDef: " << pikablue.spDef << endl << endl;

        cout << "Press 'enter' to continue.";
        cin.ignore(1000, '\n');
        cin.clear();
        cin.get();
        
        cout << endl << endl << "(Enter '-1' to quit)" << endl;
        cout << "Choose a PoCemon! (enter a number from 1 to 151) -> ";
        cin >> exampleId;
    }

    return 0;
}
