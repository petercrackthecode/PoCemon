#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "GameStateBattle.h"
#include "sfContainer.h"
#include "sfLabel.h"
#include "sfWidget.h"

class BattleScreen : public Widget
{
public:
	BattleScreen(GameState *gameState);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setLayout(const sf::View &view);

	virtual sf::Vector2f getSize() const override;

	virtual bool updateSelf(const float &dt) override;

	void setEventText(const std::string &text);

	// *******************************************************
	// *** Everything below will be private in the future: ***
	// *******************************************************
private:
	sf::IntRect mSizePadded;

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

	const sf::Vector2i SPRITESIZE = sf::Vector2i(64, 64);
	const sf::Vector2f MID = sf::Vector2f(32.f, 32.f);
	const float SCALE = 1.5f;
	sf::Sprite mP1PoceSprite;
	sf::Sprite mP2PoceSprite;
	sf::Text mP1PoceName;
	sf::Text mP2PoceName;
	int mP1Index = 152;
	int mP2Index = 152;
	int mP1Frame = 0;
	int mP2Frame = 0;

	sf::RectangleShape mP1Healthbar;
	sf::RectangleShape mP1HealthbarMax;
	int mP1DisplayHealth = 0;
	int mP1ActualHealth = 0;
	int mP1MaxHealth = 0;

	sf::RectangleShape mP2Healthbar;
	sf::RectangleShape mP2HealthbarMax;
	int mP2DisplayHealth = 0;
	int mP2ActualHealth = 0;
	int mP2MaxHealth = 0;

	float healthTimer = 0.f;

	std::string msgString;
	float mTimer = 0.f;
	int mTimerInverter = -1;

	float mFrameTimer = 0.f;
	
	const sf::Vector2i TYPESIZE = sf::Vector2i(32, 14);
	sf::Sprite mP1Type1;
	sf::Sprite mP1Type2;
	sf::Sprite mP2Type1;
	sf::Sprite mP2Type2;


	Pocemon *mP1ActivePoce;
	Pocemon *mP2ActivePoce;

	Container mP1Pocemon;
	Container mP2Pocemon;
	Container mP1Abilities;
	Container mP2Abilities;

	GameState *mGameState;
	Battle *b = nullptr;


};






#endif
