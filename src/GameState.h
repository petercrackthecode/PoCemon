// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState
{
public:
    GameState(Game* gameTemp) : game{ gameTemp } {};
    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};

#endif /* GAMESTATE_H */