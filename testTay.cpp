#include <iostream>
#include "PoCemon.h"
#include "AttackAbility.h"
#include "Player.h"

using namespace std;

void tay()
{


    AttackAbility attack(2, "Kate", "Hi there", Type::Normal, AbilityCategory::Physical, 3, 4, 5, 6);

    Pocemon testAttacker(PkmnId::Aerodactyl, 99);
    Pocemon testDefender(PkmnId::Abra, 99);

    AttackAbility megaPunch(5, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0);

    Player t("tay");
    t.addToTeam(testAttacker);
    t.addToTeam(testDefender);

    t.displayTeam();
    cin.get();



    //for (int i = 0; i < 20; ++i)
    megaPunch.use(testAttacker, testDefender);

    //Person.displayInfo();
    //testAttacker.doDamage(attack, Person);

    cin.get();

    testDefender.displayInfo();

    cin.get();
}