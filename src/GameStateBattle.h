#ifndef GAMESTATEBATTLE_H
#define GAMESTATEBATTLE_H

#include <SFML/Graphics.hpp>
#include "Battle.h"
#include "GameState.h"
#include "Player.h"
#include "sfBattleScreen.h"
#include "sfMenuContainer.h"
#include "sfWidget.h"

class GameStateBattle : public GameState
{
public:
    GameStateBattle(Game* gameTemp, Player p1Temp, Player p2Temp);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

	Battle b;

private:
    sf::View view;
    MenuContainer *mMenu;
	BattleScreen *mBattleScreen;
};

#endif /* GAMESTATEBATTLE_H */
