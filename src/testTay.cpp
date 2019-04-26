#include <iostream>
#include "PoCemon.h"
#include "AttackAbility.h"
#include "Player.h"
#include "randomGenerator.h"
#include "AbilityFactory.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

using namespace std;

void tayGraphicsTest();

void tay()
{
    int testMode;
    cout << "Enter '1' for Battle test\nEnter '2' for Graphics test " << endl;
    cin >> testMode;
    cin.clear();
    cin.ignore(1000, '\n');

    if (testMode != 1)
    {
        tayGraphicsTest();
        return;
    }

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




void tayGraphicsTest()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "PoCemon");

    sf::Texture texture;


    if (!texture.loadFromFile("graphics/gen1-sprites.png"))
    {
        // error...
    }

    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(8.f, 8.f));
    sprite.setPosition(sf::Vector2f(10.f, 50.f));
    const int SPRITESIZE = 64;
    
    // used to switch between animation frames
    int frame = 0;

    // The index of that determines which PoCemon sprite is being displayed.
    int iPoce = 1;

    

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (iPoce <= 1) {
                    iPoce = 151;
                }
                else {
                    --iPoce;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (iPoce >= 151) {
                    iPoce = 1;
                } else {
                    ++iPoce;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (frame == 0) {
                    frame = 1;
                } else {
                    frame = 0;
                }
            }

            
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE+1) * frame), SPRITESIZE, SPRITESIZE));

        // inside the main loop, between window.clear() and window.display()
        window.draw(sprite);

        // end the current frame
        window.display();

    }


}