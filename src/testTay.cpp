#include <iostream>
#include "PoCemon.h"
#include "AttackStd.h"
#include "Player.h"

using namespace std;

void tay()
{


    AttackStd attack(2, "Kate", "Hi there", Type::Normal, AbilityCategory::Physical, 3, 4, 5);

    Pocemon testAttacker(PkmnId::Aerodactyl, 99);
    Pocemon testDefender(PkmnId::Abra, 99);

    AttackStd megaPunch(5, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20);

    Player t("tay");
    t.addToTeam(testAttacker);
    t.addToTeam(testDefender);

    t.displayTeam();
    cin.get();



    //for (int i = 0; i < 20; ++i)
    megaPunch.mainEffect(testAttacker, testDefender);

    //Person.displayInfo();
    //testAttacker.doDamage(attack, Person);

    cin.get();

    testDefender.displayInfo();

    cin.get();
}