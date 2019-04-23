#include <iostream>
#include "PoCemon.h"
#include "AttackAbility.h"
#include "Player.h"
#include "randomGenerator.h"

using namespace std;

void tay()
{


    AttackAbility attack(2, "Kate", "Hi there", Type::Normal, AbilityCategory::Physical, 3, 4, 5, 6);

    //Pocemon testAttacker(PkmnId::Aerodactyl, 99);
    //Pocemon testDefender(PkmnId::Abra, 99);

    AttackAbility megaPunch(5, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0);

    Player player1("tay");
    player1.generateRandomTeam();
    player1.displayTeam();
    cin.get();

    Player player2("other");
    player2.generateRandomTeam();
    
    player2.displayTeam();
    cin.get();

    cout << "...\n...\n";

    Pocemon *p1Active = player1.getActivePocemon();
    p1Active->displayInfo();

    Pocemon *p2Active = player2.getActivePocemon();
    p2Active->displayInfo();

    cout << "...\n...\n";


    //for (int i = 0; i < 20; ++i)
    while (player1.activePocemonIndex < 6) {
        p1Active = player1.getActivePocemon();
        p2Active = player2.getActivePocemon();
        while (p2Active->getCurHp() > 0)
            megaPunch.use(*p1Active, *p2Active);
        player1.activePocemonIndex++;
        player2.activePocemonIndex++;
    }

    //Person.displayInfo();
    //testAttacker.doDamage(attack, Person);

    cin.get();

    player1.displayTeam();


    cin.get();
}