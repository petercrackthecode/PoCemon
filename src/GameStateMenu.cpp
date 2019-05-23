#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "GameState.h"
#include "GameStateBattle.h"
#include "GameStateMenu.h"
#include "sfMenuContainer.h"

using namespace std;

GameStateMenu::GameStateMenu(Game* gameTemp)
	: GameState{ gameTemp }
{
	//this->game = gameTemp;
	sf::Vector2f pos = sf::Vector2f(this->game->mWindow.getSize());


	mPlaceholderText.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	mPlaceholderText.setCharacterSize(24);
	mPlaceholderText.setScale(.3f, .3f);
	mPlaceholderText.setColor(sf::Color::White);
	mPlaceholderText.setString(mPlaceholderString);
	//mPlaceholderText.setPosition(2.f, 2.f);
	//mPlaceholderText.setOrigin(mPlaceholderText.getGlobalBounds().width / 2, mPlaceholderText.getGlobalBounds().height / 2);
	mPlaceholderText.setPosition(185.f, 150.f);

	float curY = 170.f;//10.f + mPlaceholderText.getGlobalBounds().height;

	mP1Prompt.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	mP1Prompt.setCharacterSize(24);
	mP1Prompt.setScale(.3, .3);
	mP1Prompt.setColor(sf::Color::White);
	mP1Prompt.setString("Player 1: ");
	//mP1Prompt.setPosition(2.f, curY);
	mP1Prompt.setPosition(170.f, curY);

	mP1Text.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	mP1Text.setCharacterSize(24);
	mP1Text.setScale(.3, .3);
	mP1Text.setColor(sf::Color::White);
	mP1Text.setString(mP1Name);
	//mP1Text.setPosition(2.f + mP1Prompt.getGlobalBounds().width, curY);
	mP1Text.setPosition(2.f + mP1Prompt.getGlobalBounds().width + 170.f, curY);

	curY += 10.f + mP1Prompt.getGlobalBounds().height;

	mP2Prompt.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	mP2Prompt.setCharacterSize(24);
	mP2Prompt.setScale(.3, .3);
	mP2Prompt.setColor(sf::Color::White);
	mP2Prompt.setString("Player 2: ");
	mP2Prompt.setPosition(170.f, curY);

	mP2Text.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	mP2Text.setCharacterSize(24);
	mP2Text.setScale(.3, .3);
	mP2Text.setColor(sf::Color::White);
	mP2Text.setString(mP2Name);
	mP2Text.setPosition(2.f + mP1Prompt.getGlobalBounds().width + 170.f, curY);

	mLogo.setTexture(game->mAssetMgr.getTextureRef(TextureId::MenuLogo));
	mLogo.setOrigin(mLogo.getGlobalBounds().width / 2,
		mLogo.getGlobalBounds().height / 2);
	mLogo.setScale(.15f, .15f);
	mLogo.setPosition(240, 90);


	//this->mView.setSize(pos);
	pos *= 0.5f;
	//this->mView.setCenter(pos);
	//mBackground.setOrigin(pos);
	//mBackground.move(0.f, 0.f);
	//mBackground.setScale(.3f, .3f);
	//this->mBackground.setTexture(this->game->mAssetMgr.getTextureRef(TextureId::MenuBackground));
}


void GameStateMenu::draw(const float dt)
{
	//this->game->mWindow.setView(this->mView);
	sf::RenderWindow &win = game->mWindow;
	win.clear(sf::Color::Black);
	win.draw(this->mBackground);
	win.draw(mPlaceholderText);
	win.draw(mP1Prompt);
	win.draw(mP1Text);
	win.draw(mLogo);
	if (mP1Done)
	{
		win.draw(mP2Prompt);
		win.draw(mP2Text);
	}

	return;
}

void GameStateMenu::update(const float dt)
{
}


void GameStateMenu::handleInput()
{
	sf::Event event;

	while (this->game->mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->mWindow.close();
			break;
		}

		case sf::Event::Resized:
		{
			game->setLetterboxView(event.size.width, event.size.height);
			break;
		}

		case sf::Event::TextEntered:
		{
			if (event.key.code >= 32 && event.key.code <= 126)
			{
				if (!mP1Done)
				{
					mP1Name += event.text.unicode;
					mP1Text.setString(mP1Name);
				}
				else
				{
					mP2Name += event.text.unicode;
					mP2Text.setString(mP2Name);
				}
			}
		}

		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
				this->game->mWindow.close();
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (!mP1Done)
					mP1Done = true;
				else
					this->startBattle();
			}
			else if (event.key.code == sf::Keyboard::BackSpace)
			{
				if (!mP1Done && mP1Name.length() > 0)
				{
					mP1Name.pop_back();
					mP1Text.setString(mP1Name);
				}
				else if (mP2Name.length() > 0)
				{
					mP2Name.pop_back();
					mP2Text.setString(mP2Name);
				}
			}
			else if (event.key.code == sf::Keyboard::F11)
			{
				game->toggleFullscreen();
			}
			break;


		}
		default: break;
		}
	}

	return;
}


void GameStateMenu::startBattle()
{
	mP1 = Player(mP1Name);
	mP2 = Player(mP2Name);

	mP1.generateRandomTeam();
	mP2.generateRandomTeam();

	this->game->pushState(new GameStateBattle(this->game, mP1, mP2));

	return;
}