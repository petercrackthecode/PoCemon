#ifndef MENUCONTAINER_H
#define MENUCONTAINER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "GameStateBattle.h"
#include "sfContainer.h"
#include "sfLabel.h"
#include "sfWidget.h"

class MenuContainer : public Widget
{
public:
    MenuContainer(GameState *gameState, const int &numOfDivisions);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setLayout(const sf::View &view);

	virtual sf::Vector2f getSize() const override;

	virtual bool updateSelf(const float &dt) override;

	void setEventText(const std::string &text);

    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************
private:

    int divisions;

    sf::Texture *menuTx;

    sf::Sprite mBorderTopLeft;
    sf::Sprite mBorderTopRight;
    sf::Sprite mBorderBottomLeft;
    sf::Sprite mBorderBottomRight;

    sf::Sprite mBorderTop;
    sf::Sprite mBorderRight;
    sf::Sprite mBorderBottom;
    sf::Sprite mBorderLeft;

    sf::Sprite mBorderMidTop;
    sf::Sprite mBorderMidBottom;
    sf::Sprite mBorderMidTop2Bottom;

    sf::Sprite mBorderMidLeft;
    sf::Sprite mBorderMidRight;
    sf::Sprite mBorderMidLeft2Right;

    sf::Sprite mBorderMidMid;

    sf::RectangleShape mFillColor;

	Label msg;
	Label msgSizer;
	std::string msgString;
	int msgStringLen = 0;
	float msgElapsedTime = 0;

	Container mP1Pocemon;
	Container mP2Pocemon;
	Container mP1Abilities;
	Container mP2Abilities;
	GameState *mGameState;
	Battle *b = nullptr;


};






#endif
