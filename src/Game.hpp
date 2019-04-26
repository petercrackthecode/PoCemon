//
//  Game.hpp
//  PoCemon
//
//  Created by Dung Nguyen on 4/23/19.
//  Copyright © 2019 Dung Nguyen. All rights reserved.
//
#include "Player.hpp"

#include <SFML/Graphics.hpp>

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
class Game  {
private:
    // private member funcs
    void update(sf::Time deltaTime); // update game through a constant time frame
    void render(); // renders game
    void processEvents(); // for player input
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    
    // private member vars
    sf::RenderWindow mWindow;
    Player mPlayer;
    constexpr static double PlayerSpeed= 100.f;
public:
    Game() : mWindow(sf::VideoMode(2000, 1200), "PoCemon"), mPlayer() {
        
    }
    
    void run();
    void draw();
};

#endif /* Game_hpp */
