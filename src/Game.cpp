//
//  Game.cpp
//  PoCemon
//
//  Created by Dung Nguyen on 4/23/19.
//  Copyright © 2019 Dung Nguyen. All rights reserved.
//

#include "Game.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>

void Game::run()    {
    sf::Clock clock;
    
    while (mWindow.isOpen())    {
        sf::Time deltaTime= clock.restart();
        // After get events from user, update game state, then render images
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents()  {
    sf::Event event;
    while (mWindow.pollEvent(event))    {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)  {
    
}

void Game::draw()   {
    
}

void Game::update(sf::Time deltaTime)   {
    sf::Vector2f movement(0.f, 0.f);
    
    // movement processing
    
    // movement result
}

void Game::render() {
    mWindow.clear();
    //mWindow.draw(mPlayer);
    mWindow.display();
}
