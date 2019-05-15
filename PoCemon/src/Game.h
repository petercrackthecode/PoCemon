#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
    sf::SoundBuffer sBuffer;
public:
    Game() : mWindow(sf::VideoMode(1800, 1000), "PoCemon", sf::Style::Default), mPlayer(std::string("Player 1")) {
        
    }
    
    void run();
};

#endif /* GAME_H */
