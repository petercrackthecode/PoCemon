#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "GameState.h"
#include "GameStateBattle.h"
#include "GameStateMenu.h"
#include "sfMenuContainer.h"

using namespace std;

GameStateMenu::GameStateMenu(Game* gameTemp)
    : GameState{ gameTemp }
{
    //this->game = gameTemp;
    sf::Vector2f pos = sf::Vector2f(this->game->mWindow.getSize());
    

	mPlaceholderText.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	mPlaceholderText.setCharacterSize(24);
	mPlaceholderText.setScale(.3, .3);
	mPlaceholderText.setColor(sf::Color::Black);
	mPlaceholderText.setString(mPlaceholderString);

    //this->mView.setSize(pos);
    pos *= 0.5f;
    //this->mView.setCenter(pos);
    //mBackground.setOrigin(pos);
    //mBackground.move(0.f, 0.f);
    //mBackground.setScale(.3f, .3f);
    //this->mBackground.setTexture(this->game->mAssetMgr.getTextureRef(TextureId::MenuBackground));
}


void GameStateMenu::draw(const float dt)
{
    //this->game->mWindow.setView(this->mView);

    this->game->mWindow.clear(sf::Color::White);
    this->game->mWindow.draw(this->mBackground);
	this->game->mWindow.draw(mPlaceholderText);

    return;
}

void GameStateMenu::update(const float dt)
{
}


void GameStateMenu::handleInput()
{
    sf::Event event;

    while (this->game->mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            game->mWindow.close();
            break;
        }
        /* Resize the window */
        case sf::Event::Resized:
        {
            //sf::Vector2f ratio(480.f / event.size.width, 270.f / event.size.height);

            //if (ratio.x - ratio.y > 0)
            //{
            //    //this->mView.setSize(event.size.width * ratio.y, event.size.height);
            //} else {
            //    //this->mView.setSize(event.size.width, event.size.height * ratio.x);
            //}

            //const sf::Vector2u designedsize(480, 270);

            //sf::Vector2u windowSize(event.size.width, event.size.height);
            //
            //sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);

            //float screenwidth = windowSize.x / static_cast<float>(designedsize.x);
            //float screenheight = windowSize.y / static_cast<float>(designedsize.y);

            //if (screenwidth > screenheight)
            //{ 
            //    viewport.width = screenheight / screenwidth;
            //    viewport.left = (1.f - viewport.width) / 2.f;
            //}
            //else if (screenwidth < screenheight)
            //{
            //    viewport.height = screenwidth / screenheight;
            //    viewport.top = (1.f - viewport.height) / 2.f;
            //}

            //sf::View view(sf::FloatRect(0, 0, designedsize.x, designedsize.y));
            //view.setViewport(viewport);

            //this->game->mWindow.setView(view);
            //
            //mBackground.setScale(designedsize.x / viewport.width, designedsize.y / viewport.height);













            //this->mView.setSize(event.size.width, event.size.height);
            //this->mBackground.setPosition(this->game->mWindow.mapPixelToCoords(sf::Vector2i(0, 0)));
            //this->mBackground.setScale(
            //    float(event.size.width) / float(this->mBackground.getTexture()->getSize().x),
            //    float(event.size.height) / float(this->mBackground.getTexture()->getSize().y));
            break;
        }
        case sf::Event::KeyPressed:
        {
            if (event.key.code == sf::Keyboard::Escape)
                this->game->mWindow.close();
            else if (event.key.code == sf::Keyboard::Space)
                this->startBattle();
            break;


        }
        default: break;
        }
    }

    return;
}


void GameStateMenu::startBattle()
{
    string p1Name;
    string p2Name;

    std::cout << "Enter each player's name." << endl;
    cout << "Player 1: ";
    cin >> p1Name;
    cout << "Player 2: ";
    cin >> p2Name;

    mP1 = Player(p1Name);
    mP2 = Player(p2Name);

    mP1.generateRandomTeam();
    mP2.generateRandomTeam();

    this->game->pushState(new GameStateBattle(this->game, mP1, mP2));

    return;
}