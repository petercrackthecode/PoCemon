#ifndef GAME_H
#define GAME_H

#include "Player.h"

#include <SFML/Graphics.hpp>

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

#endif /* GAME_H */
