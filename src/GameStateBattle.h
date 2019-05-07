#ifndef GAMESTATEBATTLE_H
#define GAMESTATEBATTLE_H

#include <SFML/Graphics.hpp>
#include "Battle.h"
#include "GameState.h"
#include "Player.h"
#include "sfWidget.h"

class GameStateBattle : public GameState
{
public:
    GameStateBattle(Game* gameTemp, Player p1Temp, Player p2Temp);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();



private:

    sf::View view;
    Widget *mWidget;
    Player mP1;
    Player mP2;
    Battle b;
};

#endif /* GAMESTATEBATTLE_H */
