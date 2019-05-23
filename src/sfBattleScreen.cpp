
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "GameState.h"
#include "GameStateBattle.h"
#include "sfAbilityListItem.h"
#include "sfLabel.h"
#include "sfBattleScreen.h"
#include "sfTeamListItem.h"
#include "sfVLayout.h"

BattleScreen::BattleScreen(GameState *gameState)
	: mGameState{ gameState }
{
	b = &dynamic_cast<GameStateBattle*>(mGameState)->b;

	unsigned int x = mGameState->game->mWindow.getView().getSize().x;
	unsigned int y = mGameState->game->mWindow.getView().getSize().y;
	unsigned int yTop = 0;
	unsigned int yBottom = (3 * y) / 5;
	mSizePadded = sf::IntRect(5, 5, x - 10, yBottom - 10);

	setPosition(sf::Vector2f(0, yTop));

	mP1PoceName.setFont(gameState->game->mAssetMgr.getFontRef(FontId::MainFont));
	mP1PoceName.setCharacterSize(24);
	mP1PoceName.setScale(.3f, .3f);
	mP1PoceName.setColor(sf::Color(255, 255, 255));
	mP1PoceName.setString("AHHHHHH");


	mP1Type1.setTexture(gameState->game->mAssetMgr.getTextureRef(TextureId::TypeLabels));
	mP1Type1.setPosition(5.f, 28.f);
	mP1Type1.setScale(.5f, .5f);

	mP1Type2.setTexture(gameState->game->mAssetMgr.getTextureRef(TextureId::TypeLabels));
	mP1Type2.setPosition(25.f, 28.f);
	mP1Type2.setScale(.5f, .5f);

	mP2Type1.setTexture(gameState->game->mAssetMgr.getTextureRef(TextureId::TypeLabels));
	mP2Type1.setPosition(mSizePadded.width - 15.f, 28.f);
	mP2Type1.setScale(.5f, .5f);

	mP2Type2.setTexture(gameState->game->mAssetMgr.getTextureRef(TextureId::TypeLabels));
	mP2Type2.setPosition(mSizePadded.width - 35.f, 28.f);
	mP2Type2.setScale(.5f, .5f);
	
	

	Pocemon *tempPoce = nullptr;

	if (b != nullptr)
	{
		mP1ActivePoce = b->p1->getActivePocemon();
		tempPoce = b->p1->getActivePocemon();
		mP1Index = static_cast<int>(tempPoce->getId());
		mP1PoceName.setString(tempPoce->getName());
		mP1ActualHealth = tempPoce->getCurHp();
		mP1DisplayHealth = mP1ActualHealth;
		mP1MaxHealth = tempPoce->getOriginalHp();

		int iType1 = static_cast<int>(tempPoce->getType1());
		mP1Type1.setTextureRect(sf::IntRect(TYPESIZE.x*iType1, 0, TYPESIZE.x, TYPESIZE.y));
		
		int iType2 = static_cast<int>(tempPoce->getType2());
		mP1Type2.setTextureRect(sf::IntRect(TYPESIZE.x*iType2, 0, TYPESIZE.x, TYPESIZE.y));
	}
	mP1PoceName.setPosition(mSizePadded.left, mSizePadded.top);

	mP2PoceName.setFont(gameState->game->mAssetMgr.getFontRef(FontId::MainFont));
	mP2PoceName.setCharacterSize(24);
	mP2PoceName.setScale(.3f, .3f);
	mP2PoceName.setColor(sf::Color(255, 255, 255));
	if (b != nullptr)
	{
		mP2ActivePoce = b->p2->getActivePocemon();
		tempPoce = b->p2->getActivePocemon();
		mP2Index = static_cast<int>(tempPoce->getId());
		mP2PoceName.setString(tempPoce->getName());
		mP2ActualHealth = tempPoce->getCurHp();
		mP2DisplayHealth = mP2ActualHealth;
		mP2MaxHealth = tempPoce->getOriginalHp();

		int iType1 = static_cast<int>(tempPoce->getType1());
		mP2Type1.setTextureRect(sf::IntRect(TYPESIZE.x*iType1, 0, TYPESIZE.x, TYPESIZE.y));

		int iType2 = static_cast<int>(tempPoce->getType2());
		mP2Type2.setTextureRect(sf::IntRect(TYPESIZE.x*iType2, 0, TYPESIZE.x, TYPESIZE.y));
	}
	// p2 poce name position set in setLayout.

	//msg.setOrigin(.5f, .5f);

	menuTx = &(mGameState->game->mAssetMgr.getTextureRef(TextureId::BattleMenuBorder));
	setLayout(mGameState->game->mWindow.getView());




	mP1PoceSprite.setTexture(gameState->game->mAssetMgr.getTextureRef(TextureId::PoceSprites));
	mP1PoceSprite.setTextureRect(sf::IntRect(sf::Vector2i(mP1Index * SPRITESIZE.x, mP1Frame * SPRITESIZE.y), SPRITESIZE));
	mP1PoceSprite.setOrigin(MID);
	mP1PoceSprite.setScale(-1 * SCALE, SCALE);
	mP1PoceSprite.setPosition(5.f + MID.x * SCALE, mSizePadded.top + 40.f + MID.y * SCALE);


	mP2PoceSprite.setTexture(gameState->game->mAssetMgr.getTextureRef(TextureId::PoceSprites));
	mP2PoceSprite.setTextureRect(sf::IntRect(sf::Vector2i(mP2Index * SPRITESIZE.x, mP2Frame * SPRITESIZE.y), SPRITESIZE));
	mP2PoceSprite.setOrigin(MID);
	mP2PoceSprite.setScale(SCALE, SCALE);
	mP2PoceSprite.setPosition(mSizePadded.width - MID.x * SCALE, mSizePadded.top + 40.f + MID.y * SCALE);


	mP1Healthbar.setFillColor(sf::Color(0, 200, 0));
	mP1Healthbar.setPosition(mP1PoceName.getGlobalBounds().left, mP1PoceName.getGlobalBounds().height + mP1PoceName.getGlobalBounds().top + 5.f);
	mP1Healthbar.setSize(sf::Vector2f(100.f, 5.f));

	mP1HealthbarMax.setFillColor(sf::Color(200, 0, 0));
	mP1HealthbarMax.setPosition(mP1Healthbar.getPosition());
	mP1HealthbarMax.setSize(mP1Healthbar.getSize());

	mP2Healthbar.setFillColor(sf::Color(0, 200, 0));
	mP2Healthbar.setPosition(mSizePadded.width - mP2Healthbar.getGlobalBounds().width, mP2PoceName.getGlobalBounds().height + mP2PoceName.getGlobalBounds().top + 5.f);
	mP2Healthbar.setSize(sf::Vector2f(100.f, 5.f));
	mP2Healthbar.setScale(-1.f, 1.f);

	mP2HealthbarMax.setFillColor(sf::Color(200, 0, 0));
	mP2HealthbarMax.setPosition(mP2Healthbar.getPosition());
	mP2HealthbarMax.setSize(mP2Healthbar.getSize());
	mP2HealthbarMax.setScale(-1.f, 1.f);

	mP2Healthbar.setSize(sf::Vector2f(mP2Healthbar.getSize().x / 2, mP2Healthbar.getSize().y));

	float healthPercentage = static_cast<float>(mP1DisplayHealth) / mP1MaxHealth;
	mP1Healthbar.setSize(sf::Vector2f(healthPercentage * mP1HealthbarMax.getSize().x, mP1Healthbar.getSize().y));

	healthPercentage = static_cast<float>(mP2DisplayHealth) / mP2MaxHealth;
	mP2Healthbar.setSize(sf::Vector2f(healthPercentage * mP2HealthbarMax.getSize().x, mP2Healthbar.getSize().y));


}


void BattleScreen::setLayout(const sf::View &view)
{
	mP2PoceName.setPosition(mSizePadded.width - mP2PoceName.getGlobalBounds().width, mSizePadded.top);

}


void BattleScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());

	target.draw(mP1PoceName);
	target.draw(mP1HealthbarMax);
	target.draw(mP1Healthbar);

	target.draw(mP2PoceName);
	target.draw(mP2HealthbarMax);
	target.draw(mP2Healthbar);

	target.draw(mP1PoceSprite);
	target.draw(mP2PoceSprite);

	target.draw(mP1Type1);
	target.draw(mP1Type2);

	target.draw(mP2Type1);
	target.draw(mP2Type2);

	//target.draw(mFtarget.draw(illColor, states);

//// draw children here.

//target.draw(mBorderTopLeft, states);
//target.draw(mBorderTopRight, states);
//target.draw(mBorderBottomLeft, states);
//target.draw(mBorderBottomRight, states);

//target.draw(mBorderTop, states);
//target.draw(mBorderRight, states);
//target.draw(mBorderBottom, states);
//target.draw(mBorderLeft, states);
//if ((b != nullptr && b->canContinue()))
//{
//	target.draw(mBorderMidTop, states);
//	target.draw(mBorderMidBottom, states);
//	target.draw(mBorderMidTop2Bottom, states);

//	//if (divisions > 1)
//	//{
//	//	target.draw(mBorderMidLeft, states);
//	//	target.draw(mBorderMidRight, states);
//	//	target.draw(mBorderMidLeft2Right, states);

//	//	target.draw(mBorderMidMid, states);
//	//}
//}


//if (b != nullptr && b->canContinue())
//{
//	sf::RenderStates statesCopy = states;
//	statesCopy.transform.translate(0.f, 5.f);
//	if (b->isP1PoceMenuOpen())
//		target.draw(mP1Pocemon, statesCopy);
//	else
//		target.draw(mP1Abilities, statesCopy);

//	statesCopy.transform.translate(target.getView().getSize().x / 2, 0.f);

//	if (b->isP2PoceMenuOpen())
//		target.draw(mP2Pocemon, statesCopy);
//	else
//		target.draw(mP2Abilities, statesCopy);

//}
//else
//{
//	target.draw(msg, states);
//}
}


sf::Vector2f BattleScreen::getSize() const
{
	sf::FloatRect rect = mFillColor.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}

void BattleScreen::setEventText(const std::string &text)
{
	msgString = text;
	mTimer = 0;

	unsigned int x = mGameState->game->mWindow.getView().getSize().x;
	unsigned int y = mGameState->game->mWindow.getView().getSize().y;
	unsigned int xMid = (x / 2) - 8;
	unsigned int yTop = (3 * y) / 5;
	unsigned int yMid = yTop + ((y - yTop) / 2) - 8;

	//msg.setPosition(xMid - msgSizer.getSize().x / 2, yMid / 4);
}


bool BattleScreen::updateSelf(const float &dt)
{

	mTimer += dt * mTimerInverter;
	mFrameTimer += dt;

	if (mTimer < 0)
	{
		mTimer = 0;
		mTimerInverter *= -1;
	}
	else if (mTimer > .5f)
	{
		mTimer = .5f;
		mTimerInverter *= -1;
	}

	bool updateFrame = false;
	if (mFrameTimer > .25f)
	{
		updateFrame = true;
		mFrameTimer = 0.f;
	}


	bool updateHealth = false;
	healthTimer += dt;
	if (healthTimer > .01f)
	{
		updateHealth = true;
		healthTimer = 0.f;
	}

	if (b == nullptr)
		return false;

	float healthPercentage = 0.f;

	if (updateHealth)
	{
		if (mP1DisplayHealth > mP1ActualHealth)
		{
			mP1DisplayHealth--;
			healthPercentage = static_cast<float>(mP1DisplayHealth) / mP1MaxHealth;
			mP1Healthbar.setSize(sf::Vector2f(healthPercentage * mP1HealthbarMax.getSize().x, mP1Healthbar.getSize().y));
		}
		else if (mP1DisplayHealth < mP1ActualHealth)
		{
			mP1DisplayHealth++;
			healthPercentage = static_cast<float>(mP1DisplayHealth) / mP1MaxHealth;
			mP1Healthbar.setSize(sf::Vector2f(healthPercentage * mP1HealthbarMax.getSize().x, mP1Healthbar.getSize().y));

		}

		if (mP2DisplayHealth > mP2ActualHealth)
		{
			mP2DisplayHealth--;
			healthPercentage = static_cast<float>(mP2DisplayHealth) / mP2MaxHealth;
			mP2Healthbar.setSize(sf::Vector2f(healthPercentage * mP2HealthbarMax.getSize().x, mP2Healthbar.getSize().y));

		}
		else if (mP2DisplayHealth < mP2ActualHealth)
		{
			mP2DisplayHealth++;
			healthPercentage = static_cast<float>(mP2DisplayHealth) / mP2MaxHealth;
			mP2Healthbar.setSize(sf::Vector2f(healthPercentage * mP2HealthbarMax.getSize().x, mP2Healthbar.getSize().y));

		}
	}


	Pocemon *tempPoce;

	if (updateFrame)
	{
		if (b->currentEvt.type == BEvtType::AbilityUsed)
		{
			if (b->currentEvt.source->getOwner() == b->p1)
			{
				if (mP1Frame == 0)
					mP1Frame = 1;
				else
					mP1Frame = 0;

				mP1PoceSprite.setTextureRect(sf::IntRect(sf::Vector2i(mP1Index * SPRITESIZE.x, mP1Frame * SPRITESIZE.y), SPRITESIZE));
			}
			else if (b->currentEvt.source->getOwner() == b->p2)
			{
				if (mP2Frame == 0)
					mP2Frame = 1;
				else
					mP2Frame = 0;

				mP2PoceSprite.setTextureRect(sf::IntRect(sf::Vector2i(mP2Index * SPRITESIZE.x, mP2Frame * SPRITESIZE.y), SPRITESIZE));
			}
		}
		else if (mP1Frame != 0 || mP2Frame != 0)
		{
			mP1Frame == 0;
			mP2Frame == 0;
		}
	}






	if ((b->currentEvt.type == BEvtType::AbilityDamageDealt
		|| b->currentEvt.type == BEvtType::AbilityHpHealed)
		&& b->currentEvt.target->getOwner() == b->p1)
	{
		mP1PoceSprite.setColor(sf::Color(255, 255 - 230 * mTimer, 255 - 230 * mTimer));
		mP1PoceSprite.setRotation(10 * (mTimer - .25));

		if (mP1ActualHealth != 0
			&& mP1ActualHealth != mP1ActivePoce->getCurHp())
		{
			mP1ActualHealth = mP1ActivePoce->getCurHp();
			if (mP1ActualHealth < 0)
				mP1ActualHealth = 0;

			//mTimer = 0.f;

		}
	}
	else
	{
		mP1PoceSprite.setColor(sf::Color(255, 255, 255));
		mP1PoceSprite.setRotation(0.f);
	}

	if ((b->currentEvt.type == BEvtType::AbilityDamageDealt
		|| b->currentEvt.type == BEvtType::AbilityHpHealed)
		&& b->currentEvt.target->getOwner() == b->p2)
	{
		mP2PoceSprite.setColor(sf::Color(255, 255 - 230 * mTimer, 255 - 230 * mTimer));
		mP2PoceSprite.setRotation(10 * (mTimer - .25));

		if (mP2ActualHealth != 0
			&& mP2ActualHealth != mP2ActivePoce->getCurHp())
		{
			mP2ActualHealth = mP2ActivePoce->getCurHp();
			if (mP2ActualHealth < 0)
				mP2ActualHealth = 0;

		}
	}
	else
	{
		mP2PoceSprite.setColor(sf::Color(255, 255, 255));
		mP2PoceSprite.setRotation(0.f);
	}


	if (b->currentEvt.type == BEvtType::PocemonDeployed
		&& b->currentEvt.playerSource == b->p1
		&& mP1Index != static_cast<int>(b->p1->getActivePocemon()->getId()))
	{
		mP1ActivePoce = b->p1->getActivePocemon();
		tempPoce = b->p1->getActivePocemon();
		mP1Index = static_cast<int>(tempPoce->getId());
		mP1PoceName.setString(tempPoce->getName());
		mP1ActualHealth = tempPoce->getCurHp();
		mP1DisplayHealth = mP1ActualHealth;
		mP1MaxHealth = tempPoce->getOriginalHp();

		float healthPercentage = static_cast<float>(mP1DisplayHealth) / mP1MaxHealth;
		mP1Healthbar.setSize(sf::Vector2f(healthPercentage * mP1HealthbarMax.getSize().x, mP1Healthbar.getSize().y));
		mP1PoceSprite.setTextureRect(sf::IntRect(sf::Vector2i(mP1Index * SPRITESIZE.x, mP1Frame * SPRITESIZE.y), SPRITESIZE));

		int iType1 = static_cast<int>(tempPoce->getType1());
		mP1Type1.setTextureRect(sf::IntRect(TYPESIZE.x*iType1, 0, TYPESIZE.x, TYPESIZE.y));

		int iType2 = static_cast<int>(tempPoce->getType2());
		mP1Type2.setTextureRect(sf::IntRect(TYPESIZE.x*iType2, 0, TYPESIZE.x, TYPESIZE.y));

	}

	if (b->currentEvt.type == BEvtType::PocemonDeployed
		&& b->currentEvt.playerSource == b->p2
		&& mP2Index != static_cast<int>(b->p2->getActivePocemon()->getId()))
	{
		mP2ActivePoce = b->p2->getActivePocemon();
		tempPoce = b->p2->getActivePocemon();
		mP2Index = static_cast<int>(tempPoce->getId());
		mP2PoceName.setString(tempPoce->getName());
		mP2ActualHealth = tempPoce->getCurHp();
		mP2DisplayHealth = mP2ActualHealth;
		mP2MaxHealth = tempPoce->getOriginalHp();

		float healthPercentage = static_cast<float>(mP2DisplayHealth) / mP2MaxHealth;
		mP2Healthbar.setSize(sf::Vector2f(healthPercentage * mP2HealthbarMax.getSize().x, mP2Healthbar.getSize().y));
		mP2PoceSprite.setTextureRect(sf::IntRect(sf::Vector2i(mP2Index * SPRITESIZE.x, mP2Frame * SPRITESIZE.y), SPRITESIZE));
		setLayout(mGameState->game->mWindow.getView());

		int iType1 = static_cast<int>(tempPoce->getType1());
		mP2Type1.setTextureRect(sf::IntRect(TYPESIZE.x*iType1, 0, TYPESIZE.x, TYPESIZE.y));

		int iType2 = static_cast<int>(tempPoce->getType2());
		mP2Type2.setTextureRect(sf::IntRect(TYPESIZE.x*iType2, 0, TYPESIZE.x, TYPESIZE.y));
	}


	return true;
}
