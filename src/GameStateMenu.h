#ifndef GAMESTATEMENU_H
#define GAMESTATEMENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Player.h"

class GameStateMenu : public GameState
{
public:
    GameStateMenu(Game* game);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();



private:
    void startBattle();

    sf::View mView;
    sf::Sprite mBackground;
	sf::Text mPlaceholderText;
	std::string mPlaceholderString = "This is the menu. Press spacebar to start a battle.\nThen enter the player names in the console window (cin/cout)";
    Player mP1;
    Player mP2;

};

#endif /* GAMESTATEMENU_H */
