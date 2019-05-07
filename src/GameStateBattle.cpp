#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GameStateBattle.h"
#include "GameStateMenu.h"
#include "sfMenuContainer.h"


GameStateBattle::GameStateBattle(Game* gameTemp, Player p1Temp, Player p2Temp)
    : mP1{ p1Temp }, mP2{ p2Temp }, b(p1Temp, p2Temp), GameState{ gameTemp }
{
    //this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->mWindow.getSize());

    //MenuContainer *mMenu = new MenuContainer(this->game, 0);
	mWidget = new MenuContainer(this->game, 0);
    
}

void GameStateBattle::draw(const float dt)
{
    this->game->mWindow.clear(sf::Color::Black);
    this->game->mWindow.draw(*mWidget);

    return;
}

void GameStateBattle::update(const float dt)
{
    return;
}

void GameStateBattle::handleInput()
{
    sf::Event event;

    while (this->game->mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
        case sf::Event::Closed:
        {
            this->game->mWindow.close();
            break;
        }
        /* Resize the window */
        case sf::Event::Resized:
        {
            view.setSize(event.size.width, event.size.height);
            //this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
            //this->game->background.setScale(
            //    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
            //    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
            break;
        }
        default: break;
        }
    }

    return;
}