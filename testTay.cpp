#include <iostream>
#include "PoCemon.h"
#include "AttackAbility.h"
#include "Player.h"
#include "randomGenerator.h"
#include "AbilityFactory.h"

using namespace std;

void tay()
{
    //Pocemon testAttacker(PkmnId::Aerodactyl, 99);
    //Pocemon testDefender(PkmnId::Abra, 99);

    // Player 1 & Player 2 Names
    string p1Name;
    string p2Name;

    cout << "Enter each player's name." << endl;
    cout << "Player 1: ";
    cin >> p1Name;
    cout << "Player 2: ";
    cin >> p2Name;
    
    
    AttackAbility attack(AbilityId::Acid, "Kate", "Hi there", Type::Normal, AbilityCategory::Physical, 3, 4, 5, 6, StatusEffect::None);

    

    AttackAbility megaPunch(AbilityId::MegaPunch, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0, StatusEffect::None);

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
    cout << "**********************************\n";
    cout << "Testing Stat Stages (-2 to Def):\n";
    cout << "**********************************";
    p2Active->modifyStatStage(Stat::Def, -2);
    p2Active->displayInfo();
    cin.get();

    cout << "...\n...\n";

    AbilityFactory::init();
    Ability *testAbility = AbilityFactory::getAbility(AbilityId::Slam);

    //for (int i = 0; i < 20; ++i)
    while (player1.activePocemonIndex < 6) {
        p1Active = player1.getActivePocemon();
        p2Active = player2.getActivePocemon();
        while (p2Active->getCurHp() > 0)
            testAbility->use(*p1Active, *p2Active);
        player1.activePocemonIndex++;
        player2.activePocemonIndex++;
    }

    //Person.displayInfo();
    //testAttacker.doDamage(attack, Person);

    cin.get();

    player1.displayTeam();


    cin.get();
}