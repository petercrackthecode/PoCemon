
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "GameState.h"
#include "GameStateBattle.h"
#include "sfAbilityListItem.h"
#include "sfLabel.h"
#include "sfMenuContainer.h"
#include "sfTeamListItem.h"
#include "sfVLayout.h"

MenuContainer::MenuContainer(GameState *gameState, const int &numOfDivisions)
	: mGameState{ gameState }, divisions{ numOfDivisions }, msg{ gameState->game, "" }, msgSizer{ gameState->game, "" }
{
	b = &dynamic_cast<GameStateBattle*>(mGameState)->b;

	unsigned int y = mGameState->game->mWindow.getView().getSize().y;
	unsigned int yTop = (3 * y) / 5;
	sf::IntRect a = sf::IntRect();

	setPosition(sf::Vector2f(0, yTop));

	msg.setCharacterSize(24);
	msg.setScale(.3f, .3f);
	msg.setText("LOL HIIIIIIIIIIIII");
	msgSizer.setCharacterSize(24);
	msgSizer.setScale(.3f, .3f);
	msgSizer.setText("LOL HIIIIIIIIIIIII");
	//msg.setOrigin(.5f, .5f);

	menuTx = &(mGameState->game->mAssetMgr.getTextureRef(TextureId::BattleMenuBorder));
	setLayout(mGameState->game->mWindow.getView());


	VLayout *v1 = new VLayout(this, false, 3);
	//v1->setPosition(5.f, 5.f);
	mP1Pocemon.setLayout(v1);
	v1->setSpace(0.f);

	Player *p1Temp = mGameState->getP1();
	for (int i = 0; i < 2; ++i)
	{

		//lbl->setCharacterSize(24);
		//lbl->setScale(.3, .3);

		v1->attachChild(new TeamListItem(p1Temp->pocemonTeam[i], mGameState->game, this));
		v1->attachChild(new TeamListItem(p1Temp->pocemonTeam[i + 2], mGameState->game, this));
		v1->attachChild(new TeamListItem(p1Temp->pocemonTeam[i + 4], mGameState->game, this));
	}

	attachChild(&mP1Pocemon);


	VLayout *v2 = new VLayout(this, false, 3);
	//v2->setPosition(5.f, 5.f);
	mP2Pocemon.setLayout(v2);
	v2->setSpace(0.f);

	Player *p2Temp = mGameState->getP2();
	for (int i = 0; i < 2; ++i)
	{

		//lbl->setCharacterSize(24);
		//lbl->setScale(.3, .3);

		v2->attachChild(new TeamListItem(p2Temp->pocemonTeam[i], mGameState->game, this));
		v2->attachChild(new TeamListItem(p2Temp->pocemonTeam[i + 2], mGameState->game, this));
		v2->attachChild(new TeamListItem(p2Temp->pocemonTeam[i + 4], mGameState->game, this));
	}

	attachChild(&mP2Pocemon);





	///////////////// Abilities

	VLayout *v3 = new VLayout(this, false, 2);
	v3->setPosition(5.f, 5.f);
	mP1Abilities.setLayout(v3);
	v3->setSpace(25.f);

	Pocemon *poceTemp = mGameState->getP1()->getActivePocemon();

	for (int i = 0; i < 2; ++i)
	{
		if (poceTemp->checkAbility(i))
		{
			v3->attachChild(new AbilityListItem(poceTemp->getAbility(i), mGameState->game, this));
		}

		if (poceTemp->checkAbility(i + 2))
		{
			v3->attachChild(new AbilityListItem(poceTemp->getAbility(i + 2), mGameState->game, this));
		}
	}

	//attachChild(&mP1Abilities);


	VLayout *v4 = new VLayout(this, false, 2);
	v4->setPosition(5.f, 5.f);
	mP2Abilities.setLayout(v4);
	v4->setSpace(25.f);

	poceTemp = mGameState->getP2()->getActivePocemon();

	for (int i = 0; i < 2; ++i)
	{
		if (poceTemp->checkAbility(i))
		{
			v4->attachChild(new AbilityListItem(poceTemp->getAbility(i), mGameState->game, this));
		}

		if (poceTemp->checkAbility(i + 2))
		{
			v4->attachChild(new AbilityListItem(poceTemp->getAbility(i + 2), mGameState->game, this));
		}
	}

	//attachChild(&mP2Abilities);
















}

void MenuContainer::setLayout(const sf::View &view)
{
	unsigned int x = view.getSize().x;
	unsigned int y = view.getSize().y;
	unsigned int xSize = x - 16;
	unsigned int ySize = y - 16 - (3 * y) / 5;

	mBorderTopLeft = sf::Sprite(*menuTx, sf::IntRect(0, 0, 8, 8));
	mBorderTopRight = sf::Sprite(*menuTx, sf::IntRect(16, 0, 8, 8));
	mBorderBottomRight = sf::Sprite(*menuTx, sf::IntRect(16, 16, 8, 8));
	mBorderBottomLeft = sf::Sprite(*menuTx, sf::IntRect(0, 16, 8, 8));

	mBorderTop = sf::Sprite(*menuTx, sf::IntRect(8, 0, 8, 8));
	mBorderRight = sf::Sprite(*menuTx, sf::IntRect(16, 8, 8, 8));
	mBorderBottom = sf::Sprite(*menuTx, sf::IntRect(8, 16, 8, 8));
	mBorderLeft = sf::Sprite(*menuTx, sf::IntRect(0, 8, 8, 8));

	mBorderMidTop = sf::Sprite(*menuTx, sf::IntRect(24, 0, 8, 8));
	mBorderMidBottom = sf::Sprite(*menuTx, sf::IntRect(24, 16, 8, 8));
	mBorderMidTop2Bottom = sf::Sprite(*menuTx, sf::IntRect(24, 8, 8, 8));

	mBorderMidLeft = sf::Sprite(*menuTx, sf::IntRect(0, 24, 8, 8));
	mBorderMidRight = sf::Sprite(*menuTx, sf::IntRect(16, 24, 8, 8));
	mBorderMidLeft2Right = sf::Sprite(*menuTx, sf::IntRect(8, 24, 8, 8));

	mBorderMidMid = sf::Sprite(*menuTx, sf::IntRect(24, 24, 8, 8));

	unsigned int xLeft = 0;
	unsigned int xRight = x - 8;
	unsigned int xMid = (x / 2) - 8;

	unsigned int yTop = (3 * y) / 5;
	unsigned int yBottom = y - 8;
	unsigned int yMid = yTop + ((y - yTop) / 2) - 8;

	yBottom = y - yTop - 8;
	yTop = 0;

	mFillColor = sf::RectangleShape(sf::Vector2f(xSize + 16, ySize + 16));
	mFillColor.setFillColor(sf::Color(240, 232, 240, 255));
	mFillColor.setOutlineColor(sf::Color(0, 0, 0, 255));
	mFillColor.setOutlineThickness(-2.f);
	mFillColor.setPosition(xLeft, yTop);

	mBorderTopLeft.setPosition(xLeft, yTop);
	mBorderTopRight.setPosition(xRight, yTop);
	mBorderBottomLeft.setPosition(xLeft, yBottom);
	mBorderBottomRight.setPosition(xRight, yBottom);

	mBorderTop.setPosition(xLeft + 8, yTop);
	mBorderRight.setPosition(xRight, yTop + 8);
	mBorderBottom.setPosition(xLeft + 8, yBottom);
	mBorderLeft.setPosition(xLeft, yTop + 8);

	mBorderTop.setScale(xSize / 8.f, 1.f);
	mBorderRight.setScale(1.f, ySize / 8.f);
	mBorderBottom.setScale(xSize / 8.f, 1.f);
	mBorderLeft.setScale(1.f, ySize / 8.f);


	mBorderMidTop.setPosition(xMid, yTop);
	mBorderMidBottom.setPosition(xMid, yBottom);
	mBorderMidTop2Bottom.setPosition(xMid, yTop + 8);

	mBorderMidTop2Bottom.setScale(1.f, ySize / 8.f);


	mBorderMidLeft.setPosition(xLeft, yMid);
	mBorderMidRight.setPosition(xRight, yMid);
	mBorderMidLeft2Right.setPosition(xLeft + 8, yMid);

	mBorderMidMid.setPosition(xMid, yMid);

	mBorderMidLeft2Right.setScale(xSize / 8.f, 1.f);

	msg.setPosition(xMid - msg.getSize().x / 2, yMid / 4);
	msgSizer.setPosition(xMid - msgSizer.getSize().x / 2, yMid / 4);
}


void MenuContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());

	target.draw(mFillColor, states);

	// draw children here.

	target.draw(mBorderTopLeft, states);
	target.draw(mBorderTopRight, states);
	target.draw(mBorderBottomLeft, states);
	target.draw(mBorderBottomRight, states);

	target.draw(mBorderTop, states);
	target.draw(mBorderRight, states);
	target.draw(mBorderBottom, states);
	target.draw(mBorderLeft, states);
	if (divisions > 0 || (b != nullptr && b->canContinue()))
	{
		target.draw(mBorderMidTop, states);
		target.draw(mBorderMidBottom, states);
		target.draw(mBorderMidTop2Bottom, states);

		if (divisions > 1)
		{
			target.draw(mBorderMidLeft, states);
			target.draw(mBorderMidRight, states);
			target.draw(mBorderMidLeft2Right, states);

			target.draw(mBorderMidMid, states);
		}
	}


	if (b != nullptr && b->canContinue())
	{
		sf::RenderStates statesCopy = states;
		statesCopy.transform.translate(0.f, 5.f);
		if (b->isP1PoceMenuOpen())
			target.draw(mP1Pocemon, statesCopy);
		else if (!b->isP1ActionSelected())
			target.draw(mP1Abilities, statesCopy);

		statesCopy.transform.translate(target.getView().getSize().x / 2, 0.f);

		if (b->isP2PoceMenuOpen())
			target.draw(mP2Pocemon, statesCopy);
		else if (!b->isP2ActionSelected())
			target.draw(mP2Abilities, statesCopy);

	}
	else if (b->isP1Fainted() || b->isP2Fainted())
	{
		sf::RenderStates statesCopy = states;
		statesCopy.transform.translate(0.f, 5.f);

		if (b->isP1Fainted())
		{
			target.draw(mP1Pocemon, statesCopy);
		}
		else if (b->isP2Fainted())
		{
			statesCopy.transform.translate(target.getView().getSize().x / 2, 0.f);
			target.draw(mP2Pocemon, statesCopy);
		}
	}
	else
	{
		target.draw(msg, states);
	}
}


sf::Vector2f MenuContainer::getSize() const
{
	sf::FloatRect rect = mFillColor.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}

void MenuContainer::setEventText(const std::string &text)
{
	msgString = text;
	msgSizer.setText(msgString);
	msgStringLen = msgString.length();
	msgElapsedTime = 0;

	unsigned int x = mGameState->game->mWindow.getView().getSize().x;
	unsigned int y = mGameState->game->mWindow.getView().getSize().y;
	unsigned int xMid = (x / 2) - 8;
	unsigned int yTop = (3 * y) / 5;
	unsigned int yMid = yTop + ((y - yTop) / 2) - 8;

	msg.setPosition(xMid - msgSizer.getSize().x / 2, yMid / 4);
}


bool MenuContainer::updateSelf(const float &dt)
{
	Pocemon *poceTemp;

	if (b->currentEvt.type == BEvtType::PocemonDeployed
		&& b->currentEvt.playerSource == b->p1)
	{
		delete mP1Abilities.getLayout();
		VLayout *v = new VLayout(this, false, 2);
		v->setPosition(5.f, 5.f);
		mP1Abilities.setLayout(v);
		v->setSpace(25.f);

		poceTemp = mGameState->getP1()->getActivePocemon();

		for (int i = 0; i < 2; ++i)
		{
			if (poceTemp->checkAbility(i))
			{
				v->attachChild(new AbilityListItem(poceTemp->getAbility(i), mGameState->game, this));
			}

			if (poceTemp->checkAbility(i + 2))
			{
				v->attachChild(new AbilityListItem(poceTemp->getAbility(i + 2), mGameState->game, this));
			}
		}


	}

	if (b->currentEvt.type == BEvtType::PocemonDeployed
		&& b->currentEvt.playerSource == b->p2)
	{
		//for (int i = 0; i < mP2Abilities.getLayout()->mChildren.size(); ++i)
		//{
		//	mP1Abilities.getLayout()->detachChild(mP2Abilities.getLayout()->mChildren.at(i));
		//	//delete mP2Abilities.getLayout()->mChildren.at(i);
		//	//mP2Abilities.getLayout()->mChildren.erase(mP2Abilities.mChildren.begin() + i);
		//}

		delete mP2Abilities.getLayout();
		VLayout *v = new VLayout(this, false, 2);
		v->setPosition(5.f, 5.f);
		mP2Abilities.setLayout(v);
		v->setSpace(25.f);

		poceTemp = mGameState->getP2()->getActivePocemon();

		for (int i = 0; i < 2; ++i)
		{
			if (poceTemp->checkAbility(i))
			{
				v->attachChild(new AbilityListItem(poceTemp->getAbility(i), mGameState->game, this));
			}

			if (poceTemp->checkAbility(i + 2))
			{
				v->attachChild(new AbilityListItem(poceTemp->getAbility(i + 2), mGameState->game, this));
			}
		}
	}


	int tempElapsedTime = 40 * msgElapsedTime;
	if (tempElapsedTime < msgStringLen + 2)
	{


		msg.setText(msgString.substr(0, tempElapsedTime));
		msgElapsedTime += dt;
		return true;
	}
	else
	{
		return false;
	}
}
