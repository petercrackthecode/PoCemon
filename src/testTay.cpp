#include <iostream>
#include "PoCemon.h"
#include "AttackAbility.h"
#include "Player.h"
#include "randomGenerator.h"
#include "AbilityFactory.h"
#include "Battle.h"
#include "sfTeamListItem.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

using namespace std;

void tayGraphicsTest();
void tayGraphicsAndBattleTest();

void tay()
{
    int testMode;
    cout << "Enter '1' for Battle test\nEnter '2' for Graphics test\nEnter '3' for Graphics & test" << endl;
    cin >> testMode;
    cin.clear();
    cin.ignore(1000, '\n');

    if (testMode == 2)
    {
        tayGraphicsTest();
        return;
    }
    else if (testMode >= 3)
    {
        tayGraphicsAndBattleTest();
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

    Player p1(p1Name);
    Player p2(p2Name);

    Battle b(p1, p1);


    p1.generateRandomTeam();
    p1.displayTeam();
    cin.get();

    p2.generateRandomTeam();
    
    p2.displayTeam();
    cin.get();

    cout << "...\n...\n";

    Pocemon *p1Active = p1.getActivePocemon();
    p1Active->displayInfo();

    Pocemon *p2Active = p2.getActivePocemon();
    cout << "**********************************\n";
    cout << "Testing Stat Stages (-2 to Def):\n";
    cout << "**********************************";
    p2Active->modifyStatStage(Stat::Def, -2);
    p2Active->displayInfo();
    cin.get();

    cout << "...\n...\n";

    
    Ability *testAbility = AbilityFactory::getAbility(AbilityId::Slam);

    //for (int i = 0; i < 20; ++i)
    while (p1.activePocemonIndex < 6) {
        p1Active = p1.getActivePocemon();
        p2Active = p2.getActivePocemon();
        while (p2Active->getCurHp() > 0)
            testAbility->use(*p1Active, *p2Active);
        p1.activePocemonIndex++;
        p2.activePocemonIndex++;
    }

    //Person.displayInfo();
    //testAttacker.doDamage(attack, Person);

    cin.get();

    p1.displayTeam();


    cin.get();
}




void tayGraphicsTest()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "PoCemon");
    window.setKeyRepeatEnabled(false);

    // Setup the font
    sf::Font font;
    if (!font.loadFromFile("graphics/gbFont.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Arrow Keys: Move ---- Space: Animate ---- CTRL/ALT: Switch PoCemon");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);


    sf::Texture texture;
    if (!texture.loadFromFile("graphics/gen1-sprites.png"))
    {
        // error...
    }

    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(8.f, 8.f));
    float x = 10.f;
    float y = 50.f;
    sprite.setPosition(sf::Vector2f(x, y));
    sprite.setTexture(texture);
    const int SPRITESIZE = 64;
    
    // used to switch between animation frames
    int frame = 0;

    // The index of that determines which PoCemon sprite is being displayed.
    int iPoce = 1;
    
    sf::Clock clock;

    while (window.isOpen())
    {
        // Time it took to render the previous frame.
        sf::Time deltaTime = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (frame == 0) {
                        frame = 1;
                    } else {
                        frame = 0;
                    }
                }

                if (event.key.code == sf::Keyboard::LControl)
                {
                    if (iPoce <= 1) {
                        iPoce = 151;
                    } else {
                        --iPoce;
                    }
                }

                if (event.key.code == sf::Keyboard::LAlt)
                {
                    if (iPoce >= 151) {
                        iPoce = 1;
                    } else {
                        ++iPoce;
                    }
                }
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x -= 1.f * deltaTime.asMilliseconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x += 1.f * deltaTime.asMilliseconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            y += 1.f * deltaTime.asMilliseconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            y -= 1.f * deltaTime.asMilliseconds();
        }

        
        sprite.setPosition(sf::Vector2f(x, y));

        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // Display the correct PoCemon in the correct location.
        sprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE) * frame), SPRITESIZE, SPRITESIZE));

        // inside the main loop, between window.clear() and window.display()
        window.draw(sprite);
        window.draw(text);


        // end the current frame
        window.display();

    }


}



void tayGraphicsAndBattleTest()
{
    // Player 1 & Player 2 Names
    string p1Name;
    string p2Name;

    cout << "Enter each player's name." << endl;
    cout << "Player 1: ";
    cin >> p1Name;
    cout << "Player 2: ";
    cin >> p2Name;

    Player p1(p1Name);
    Player p2(p2Name);

    Battle b(p1, p1);

    p1.generateRandomTeam();
    p2.generateRandomTeam();




    const int SPRITESIZE = 64;
    sf::RenderWindow window(sf::VideoMode(), "PoCemon", sf::Style::Fullscreen);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
    int screenW = window.getSize().x;
    int screenH = window.getSize().y;
    float fScale = screenH / 150.f;
    sf::Vector2f scale(fScale, fScale);
    sf::Vector2f scaleLeft(-fScale, fScale);
    sf::Vector2f scaleRight(fScale, fScale);
    sf::Vector2f spriteOrigin(0, 0);
    sf::Vector2f spriteOriginLeft(0, 0);
    sf::Vector2f spriteOriginRight(SPRITESIZE, 0);
    sf::Vector2f spriteOriginMid((SPRITESIZE) / 2.f, (SPRITESIZE) / 2.f);

    // Setup the font
    sf::Font font;
    if (!font.loadFromFile("graphics/gbFont.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    //text.setString("Arrow Keys: Move ---- Space: Animate ---- CTRL/ALT: Switch PoCemon");
    text.setCharacterSize(3*fScale);
    text.setFillColor(sf::Color::White);

    sf::Text p1PoceNameText;
    p1PoceNameText.setFont(font);
    p1PoceNameText.setString(p1.getActivePocemon()->getName());
    p1PoceNameText.setCharacterSize(3*fScale);
    p1PoceNameText.setFillColor(sf::Color::White);
    p1PoceNameText.setPosition(sf::Vector2f(6.f*fScale, 6.f*fScale));

    sf::Text p2PoceNameText;
    p2PoceNameText.setFont(font);
    p2PoceNameText.setString(p2.getActivePocemon()->getName());
    p2PoceNameText.setCharacterSize(3*fScale);
    p2PoceNameText.setFillColor(sf::Color::White);
    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));


    sf::Texture texture;
    if (!texture.loadFromFile("graphics/gen1-sprites.png"))
    {
        // error...
    }

    sf::Texture miniSprites;
    if (!miniSprites.loadFromFile("graphics/gen1-mini-sprites.png"))
    {
        // error...
    }

    vector<sfTeamListItem> p1TeamList;
    for (int i = 0; i < 6; i++)
    {
        sfTeamListItem a(p1[i], sf::Vector2f(6.f*fScale + (i % 2) * screenW*.25f, screenH*.65f + 8.f * fScale * i - (8.f * fScale * (i%2))), fScale, font, miniSprites);
        p1TeamList.push_back(a);
    }

    vector<sfTeamListItem> p2TeamList;
    for (int i = 0; i < 6; i++)
    {
        sfTeamListItem a(p2[i], sf::Vector2f(screenW*.5f + 6.f*fScale + (i % 2) * screenW*.25f, screenH*.65f + 8.f * fScale * i - (8.f * fScale * (i % 2))), fScale, font, miniSprites);
        p2TeamList.push_back(a);
    }


    sf::Sprite p1PoceSprite;
    sf::Sprite p2PoceSprite;
    p1PoceSprite.setOrigin(spriteOriginRight);
    p2PoceSprite.setOrigin(spriteOriginRight);
    p1PoceSprite.setScale(scaleLeft);
    p2PoceSprite.setScale(scaleRight);
    float x = 11.f * fScale;
    float y = 11.f * fScale;
    p1PoceSprite.setPosition(sf::Vector2f(x, y));
    p2PoceSprite.setPosition(sf::Vector2f(screenW - x, y));
    p1PoceSprite.setTexture(texture);
    p2PoceSprite.setTexture(texture);

    // used to switch between animation frames
    int iFrameP1 = 0;
    int iFrameP2 = 0;
    int iFrameMini = 0;

    // The index that determines which PoCemon sprite is being displayed.
    int iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
    int iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());

    sf::Clock clock;
    sf::Time elapsedTime;
    while (window.isOpen())
    {
        // Time it took to render the previous frame.
        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        if (elapsedTime.asMilliseconds() > 500)
        {
            if (iFrameMini == 0)
                iFrameMini = 1;
            else
                iFrameMini = 0;
            elapsedTime = deltaTime;
        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                screenW = event.size.width;
                screenH = event.size.height;
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }

                else if (event.key.code == sf::Keyboard::Space) {
                    if (iFrameP1 == 0) {
                        iFrameP1 = 1;
                    } else {
                        iFrameP1 = 0;
                    }
                }

                else if (event.key.code == sf::Keyboard::Numpad0) {
                    if (iFrameP2 == 0) {
                        iFrameP2 = 1;
                    } else {
                        iFrameP2 = 0;
                    }
                }

                else if (event.key.code == sf::Keyboard::LControl) {
                    if (iPoceP1 <= 1) {
                        iPoceP1 = 151;
                    } else {
                        --iPoceP1;
                    }
                }

                else if (event.key.code == sf::Keyboard::LAlt)
                {
                    if (iPoceP1 >= 151) {
                        iPoceP1 = 1;
                    } else {
                        ++iPoceP1;
                    }
                }

                else if (event.key.code == sf::Keyboard::Subtract) {
                    if (iPoceP2 <= 1) {
                        iPoceP2 = 151;
                    } else {
                        --iPoceP2;
                    }
                }

                else if (event.key.code == sf::Keyboard::Add)
                {
                    if (iPoceP2 >= 151) {
                        iPoceP2 = 1;
                    } else {
                        ++iPoceP2;
                    }
                }


                else if (event.key.code == sf::Keyboard::Num1) {
                    p1.setActivePocemon(0);
                    iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
                    p1PoceNameText.setString(p1.getActivePocemon()->getName());
                }

                else if (event.key.code == sf::Keyboard::Num2) {
                    p1.setActivePocemon(1);
                    iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
                    p1PoceNameText.setString(p1.getActivePocemon()->getName());
                }

                else if (event.key.code == sf::Keyboard::Num3) {
                    p1.setActivePocemon(2);
                    iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
                    p1PoceNameText.setString(p1.getActivePocemon()->getName());
                }

                else if (event.key.code == sf::Keyboard::Num4) {
                    p1.setActivePocemon(3);
                    iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
                    p1PoceNameText.setString(p1.getActivePocemon()->getName());
                }

                else if (event.key.code == sf::Keyboard::Num5) {
                    p1.setActivePocemon(4);
                    iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
                    p1PoceNameText.setString(p1.getActivePocemon()->getName());
                }

                else if (event.key.code == sf::Keyboard::Num6) {
                    p1.setActivePocemon(5);
                    iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
                    p1PoceNameText.setString(p1.getActivePocemon()->getName());
                }



                else if (event.key.code == sf::Keyboard::Numpad1) {
                    p2.setActivePocemon(0);
                    iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
                    p2PoceNameText.setString(p2.getActivePocemon()->getName());
                    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));
                }

                else if (event.key.code == sf::Keyboard::Numpad2) {
                    p2.setActivePocemon(1);
                    iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
                    p2PoceNameText.setString(p2.getActivePocemon()->getName());
                    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));
                }

                else if (event.key.code == sf::Keyboard::Numpad3) {
                    p2.setActivePocemon(2);
                    iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
                    p2PoceNameText.setString(p2.getActivePocemon()->getName());
                    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));
                }

                else if (event.key.code == sf::Keyboard::Numpad4) {
                    p2.setActivePocemon(3);
                    iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
                    p2PoceNameText.setString(p2.getActivePocemon()->getName());
                    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));
                }

                else if (event.key.code == sf::Keyboard::Numpad5) {
                    p2.setActivePocemon(4);
                    iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
                    p2PoceNameText.setString(p2.getActivePocemon()->getName());
                    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));
                }
                
                else if (event.key.code == sf::Keyboard::Numpad6) {
                    p2.setActivePocemon(5);
                    iPoceP2 = static_cast<int>(p2.getActivePocemon()->getId());
                    p2PoceNameText.setString(p2.getActivePocemon()->getName());
                    p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f*fScale - p2PoceNameText.getLocalBounds().width, 6.f*fScale));
                }
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x -= 1.f * deltaTime.asMilliseconds();
        }

        p1PoceSprite.setPosition(sf::Vector2f(x, y));

        // clear the window with black color
        window.clear(sf::Color::Transparent);

        // Display the correct PoCemon.
        p1PoceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoceP1), ((SPRITESIZE)* iFrameP1), SPRITESIZE, SPRITESIZE));
        p2PoceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoceP2), ((SPRITESIZE)* iFrameP2), SPRITESIZE, SPRITESIZE));

        // inside the main loop, between window.clear() and window.display()
        window.draw(p1PoceSprite);
        window.draw(p2PoceSprite);
        //window.draw(text);
        window.draw(p1PoceNameText);
        window.draw(p2PoceNameText);
        std::for_each(p1TeamList.begin(), p1TeamList.end(), [&window, &iFrameMini](sfTeamListItem a) { a.Render(window, iFrameMini); });
        std::for_each(p2TeamList.begin(), p2TeamList.end(), [&window, &iFrameMini](sfTeamListItem a) { a.Render(window, iFrameMini); });
        

        // end the current frame
        window.display();

    }
}