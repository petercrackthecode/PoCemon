#ifndef GAME_H
#define GAME_H

#include <stack>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Player.h"

class GameState;

class Game  {
public:
    Game(const sf::VideoMode &videoMode, const std::string &appName, const int &setting = sf::Style::Default);

    void run();
    void draw();

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

	void setLetterboxView(int windowWidth, int windowHeight);
    
    AssetManager mAssetMgr;
    sf::RenderWindow mWindow;

	void toggleFullscreen();

private:
    // private member funcs
    void update(sf::Time deltaTime); // update game through a constant time frame
    void render(); // renders game
    void processEvents(); // for player input
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    
    // private member vars
    std::stack<GameState*> states;
	bool isFullscreen = false;

};

#endif /* GAME_H */
