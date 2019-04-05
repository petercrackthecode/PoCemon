#include "PoCemon.h"
#include "Combat.h"
#include "Enums.h"
#include "PoCemonData.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// ***********************************
// *** What happens before main()? ***
// ***********************************
//
// 1. In Enums.h, all enums ('enumerations') are defined. Enums are 'special' variables
//    that represent numbers. It lets us use 'English' words in our code, instead of
//    having to remember that (for example) the number '10' represents the 'Fire' type. We
//    can just say "Type::Fire", which is much easier to remember AND easier to
//    comprehend when reading code. We can also cast "Type::Fire" to an int at any time and
//    use it as an array index or for anything else that requires an actual number.
//    The example below would look up the 11th item of the array:
//       array[ static_cast<int>(Type::Fire) ];
//
// 2. In PoCemonData.cpp, the 'defineAllPocemonData()' function runs. It returns
//    an array of PocemonData objects, which is saved in the 'allData' member
//    variable. The PocemonData objects in the 'allData' array hold the base
//    stats & info for all PoCemon.
//
// 3. In Combat.cpp, the 'dmgMultTbl' 2D array is defined. 'dmgMultTbl' stands
//    for 'damage multiplier table'. This 2-dimensional array is used by the 
//    getDmgMultiplier() function. When you pass the function 2 or 3 'Type' arguments,
//    it will do a look up in the array to find out what the correct damage multiplier is.

void aman();
void kate();
void peter();
void tay();

int main()
{
    // Seed for random number generation (this should only be done once throughout the entire program).
    srand(time(NULL));

    int whoAreYou;
    cout << "Who are you?" << endl;
    cout << "1. Aman" << endl << "2. Kate" << endl
        << "3. Peter" << endl << "4. Tay" << endl;
    cin >> whoAreYou;
    cin.clear();
    cin.ignore(1000, '\0');

    switch (whoAreYou)
    {
    case 1:
        aman();
        break;
    case 2:
        kate();
        break;
    case 3:
        peter();
        break;
    case 4:
        tay();
        break;
    default:




        // The program just does 3 things right now.

        // 1. Lists the base stats for all PoCemon.

        // First, print Column Headers.
        cout << setw(3) << "ID"
            << setw(17) << "Name"
            << setw(10) << "Type1"
            << setw(10) << "Type2"
            << setw(4) << "HP"
            << setw(4) << "Atk"
            << setw(4) << "Def"
            << setw(4) << "Spd"
            << setw(6) << "spAtk"
            << setw(6) << "spDef" << endl;

        // Then, print the actual PoCemon data.
        for (int i = 0; i < 152; ++i)
        {
            cout << setw(3) << i
                << setw(17) << PocemonData::allData[i].name
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

        cout << "Super Effective:" << endl
            << "A Water attack does "
            << Combat::getDmgMultiplier(Type::Water, Type::Fire) * 100
            << "% damage to a Fire PoCemon." << endl << endl;

        cout << "Not Very Effective...:" << endl
            << "A Fire attack does "
            << Combat::getDmgMultiplier(Type::Fire, Type::Water) * 100
            << "% damage to a Water PoCemon." << endl << endl;

        cout << "Double Resistance (Not Very Effective... x2):" << endl
            << "A Fire attack does "
            << Combat::getDmgMultiplier(Type::Fire, Type::Water, Type::Rock) * 100
            << "% damage to a PoCemon that is both Water & Rock." << endl << endl;

        cout << "Super Effective (again):" << endl
            << "A Fire attack does "
            << Combat::getDmgMultiplier(Type::Fire, Type::Grass) * 100
            << "% damage to a Grass PoCemon." << endl << endl;

        cout << "DOUBLE Super Effective!:" << endl
            << "A Fire attack does "
            << Combat::getDmgMultiplier(Type::Fire, Type::Grass, Type::Bug) * 100
            << "% damage to a PoCemon that is both Grass & Bug." << endl << endl << endl;



        // 3. Lets you select an example PoCemon and displays its stats.
        cout << "*********************************" << endl
            << "** Example PoCemon Constructor **" << endl
            << "*********************************" << endl << endl;

        int exampleId = 0;
        int exampleLevel;

        cout << "Choose a PoCemon! (enter a number from 1 to 151) -> ";
        cin >> exampleId;

        while (exampleId >= 0)
        {
            cout << "What level? (enter a number from 1 to 99) -> ";
            cin >> exampleLevel;

            Pocemon pikablue(static_cast<PkmnId>(exampleId), exampleLevel);

            cout << endl << endl
                << "*** Here are your PoCemon's stats: ***" << endl
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

        break;
    }

    return 0;
}
