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
	sf::Sprite mLogo;
	sf::Text mPlaceholderText;
	std::string mPlaceholderString = "Enter your name:";

	sf::Text mP1Prompt;
	std::string mP1Name = "";
	sf::Text mP1Text;
	bool mP1Done = false;

	sf::Text mP2Prompt;
	std::string mP2Name = "";
	sf::Text mP2Text;

		

};

#endif /* GAMESTATEMENU_H */