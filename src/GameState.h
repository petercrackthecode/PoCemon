// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include "sfAction.h"
#include "sfActionTarget.h"

class GameState : public ActionTarget
{
public:
	GameState(Game* gameTemp) : game{ gameTemp }, ActionTarget{ mActionMap } {};
    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;

	ActionMap mActionMap;

	Player* getP1() { return &mP1; };
	Player* getP2() { return &mP2; };

protected:
	Player mP1;
	Player mP2;
	
};

#endif /* GAMESTATE_H */