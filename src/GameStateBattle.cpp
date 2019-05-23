#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GameStateBattle.h"
#include "GameStateMenu.h"
#include "sfMenuContainer.h"


GameStateBattle::GameStateBattle(Game* gameTemp, Player p1Temp, Player p2Temp)
	: GameState{ gameTemp }
{
	//this->game = game;
	mP1 = p1Temp;
	mP2 = p2Temp;

	b.set(&mP1, &mP2);
	//sf::Vector2f pos = sf::Vector2f(this->game->mWindow.getSize());

	//MenuContainer *mMenu = new MenuContainer(this->game, 0);
	mMenu = new MenuContainer(this, 0);
	mBattleScreen = new BattleScreen(this);

}

void GameStateBattle::draw(const float dt)
{
	this->game->mWindow.clear(sf::Color::Black);
	this->game->mWindow.draw(*mBattleScreen);
	this->game->mWindow.draw(*mMenu);

	return;
}

void GameStateBattle::update(const float dt)
{
	mBattleScreen->update(dt);
	mMenu->update(dt);


	if (b.canContinue() && b.playersReady())
	{
		BattleEvent evtTemp;
		b.setAttackingPriority();
		int action = -1;
		while (b.actionsPending() && b.p1->activePocemonIndex < 6 && b.p2->activePocemonIndex < 6) {
			action = b.getAttackerAction();
			if (b.getAttackingPlayer()->hasPreppedPocemon()) {
				evtTemp = BattleEvent(BEvtType::PocemonWithdrawn, b.getAttackingPlayer()->getActivePocemon(), *b.getAttackingPlayer());
				Battle::addEvent(evtTemp);
				b.getAttackingPlayer()->deployPreppedPocemon();
				evtTemp = BattleEvent(BEvtType::PocemonDeployed, b.getAttackingPlayer()->getActivePocemon(), *b.getAttackingPlayer());
				Battle::addEvent(evtTemp);
			}
			else if (b.getAttackingPlayer()->getActivePocemon()->checkAbility(action))
				b.getAttackingPlayer()->getActivePocemon()->getAbility(b.getAttackerAction())->use(*b.getAttackingPlayer()->getActivePocemon(), *b.getDefendingPlayer()->getActivePocemon());

			if (b.getAttackingPlayer()->getActivePocemon()->getCurHp() <= 0) {
				//b.getAttackingPlayer()->setPreppedPocemon(b.getAttackingPlayer()->activePocemonIndex + 1);
				//b.getAttackingPlayer()->activePocemonIndex++;
				//evtTemp = BattleEvent(BEvtType::PocemonDeployed, b.getAttackingPlayer()->getActivePocemon(), *b.getAttackingPlayer());
				//Battle::addEvent(evtTemp);
				break;
			}
			else if (b.getDefendingPlayer()->getActivePocemon()->getCurHp() <= 0) {
				//b.getDefendingPlayer()->setPreppedPocemon(b.getDefendingPlayer()->activePocemonIndex + 1);
				//b.getDefendingPlayer()->activePocemonIndex++;
				//evtTemp = BattleEvent(BEvtType::PocemonDeployed, b.getDefendingPlayer()->getActivePocemon(), *b.getDefendingPlayer());
				//Battle::addEvent(evtTemp);
				break;
			}

			b.switchPlayerRoles();
		}

		b.resetPlayerActions();
		b.setPause();
		if (b.eventPending())
		{
			b.handleEventCommand();
			mMenu->setEventText(b.currentEvt.toString());
		}
	}


	return;
}

void GameStateBattle::handleInput()
{
	sf::Event event;

	while (this->game->mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
		{
			this->game->mWindow.close();
			break;
		}
		/* Resize the window */
		case sf::Event::Resized:
		{
			//view.setSize(event.size.width, event.size.height);
			game->setLetterboxView(event.size.width, event.size.height);
			//this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
			//this->game->background.setScale(
			//    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
			//    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
			break;
		}
		case sf::Event::KeyPressed:
		{
			Battle *b = &this->b;
			BattleEvent evt;

			if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space)
			{
				if (!b->canContinue() && !b->isAnyoneFainted())
				{
					if (b->currentEvt.type == BEvtType::PocemonFainted && !b->isP1ActionSelected() && !b->isP2ActionSelected())
					{
						if (b->currentEvt.target->owner == &mP1)
						{
							b->forceP1PoceMenuOpen();
						}
						else if (b->currentEvt.target->owner == &mP2)
						{
							b->forceP2PoceMenuOpen();
						}
					}
					else if (b->eventPending())
					{
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					else
					{
						b->resetPlayerActions();
						b->setContinue();
					}
				}
				//else
				//{
				//	if (b->eventPending())
				//	{
				//		b->handleEventCommand();
				//		mMenu->setEventText(b->currentEvt.toString());
				//	}
				//	else
				//	{
				//		b->setContinue();
				//	}
				//}
			}
			else if (event.key.code == sf::Keyboard::Num1)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP1PoceMenuOpen() && b->p1->getActivePocemon()->checkAbility(0))
					{
						b->setP1Action(0);
					}
					else if (b->isP1PoceMenuOpen() && b->p1->activePocemonIndex != 0 && b->p1->operator[](0).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(0);
						b->setP1Action(7);
					}
				}
				else if (b->isP1Fainted())
				{
					if (b->p1->activePocemonIndex != 0 && b->p1->operator[](0).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(0);
						b->p1->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP1.getActivePocemon(), mP1);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}

					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP1PoceMenuOpen() && b->p1->getActivePocemon()->checkAbility(1))
					{
						b->setP1Action(1);
					}
					else if (b->isP1PoceMenuOpen() && b->p1->activePocemonIndex != 1 && b->p1->operator[](1).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(1);
						b->setP1Action(8);
					}
				}
				else if (b->isP1Fainted())
				{
					if (b->p1->activePocemonIndex != 1 && b->p1->operator[](1).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(1);
						b->p1->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP1.getActivePocemon(), mP1);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num3)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP1PoceMenuOpen() && b->p1->getActivePocemon()->checkAbility(2))
					{
						b->setP1Action(2);
					}
					else if (b->isP1PoceMenuOpen() && b->p1->activePocemonIndex != 2 && b->p1->operator[](2).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(2);
						b->setP1Action(9);
					}
				}
				else if (b->isP1Fainted())
				{
					if (b->p1->activePocemonIndex != 2 && b->p1->operator[](2).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(2);
						b->p1->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP1.getActivePocemon(), mP1);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num4)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP1PoceMenuOpen() && b->p1->getActivePocemon()->checkAbility(3))
					{
						b->setP1Action(3);
					}
					else if (b->isP1PoceMenuOpen() && b->p1->activePocemonIndex != 3 && b->p1->operator[](3).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(3);
						b->setP1Action(10);
					}
				}
				else if (b->isP1Fainted())
				{
					if (b->p1->activePocemonIndex != 3 && b->p1->operator[](3).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(3);
						b->p1->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP1.getActivePocemon(), mP1);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num5)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (b->isP1PoceMenuOpen() && b->p1->activePocemonIndex != 4 && b->p1->operator[](4).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(4);
						b->setP1Action(11);
					}
				}
				else if (b->isP1Fainted())
				{
					if (b->p1->activePocemonIndex != 4 && b->p1->operator[](4).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(4);
						b->p1->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP1.getActivePocemon(), mP1);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num6)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (b->isP1PoceMenuOpen() && b->p1->activePocemonIndex != 5 && b->p1->operator[](5).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(5);
						b->setP1Action(11);
					}
				}
				else if (b->isP1Fainted())
				{
					if (b->p1->activePocemonIndex != 5 && b->p1->operator[](5).getCurHp() > 0)
					{
						b->p1->setPreppedPocemon(5);
						b->p1->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP1.getActivePocemon(), mP1);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num7 || event.key.code == sf::Keyboard::Numpad1)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP2PoceMenuOpen() && b->p2->getActivePocemon()->checkAbility(0))
					{
						b->setP2Action(0);
					}
					else if (b->isP2PoceMenuOpen() && b->p2->activePocemonIndex != 0 && b->p2->operator[](0).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(0);
						b->setP2Action(7);
					}
				}
				else if (b->isP2Fainted())
				{
					if (b->p2->activePocemonIndex != 0 && b->p2->operator[](0).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(0);
						b->p2->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP2.getActivePocemon(), mP2);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num8 || event.key.code == sf::Keyboard::Numpad2)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP2PoceMenuOpen() && b->p2->getActivePocemon()->checkAbility(1))
					{
						b->setP2Action(1);
					}
					else if (b->isP2PoceMenuOpen() && b->p2->activePocemonIndex != 1 && b->p2->operator[](1).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(1);
						b->setP2Action(8);
					}
				}
				else if (b->isP2Fainted())
				{
					if (b->p2->activePocemonIndex != 1 && b->p2->operator[](1).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(1);
						b->p2->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP2.getActivePocemon(), mP2);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num9 || event.key.code == sf::Keyboard::Numpad3)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP2PoceMenuOpen() && b->p2->getActivePocemon()->checkAbility(2))
					{
						b->setP2Action(2);
					}
					else if (b->isP2PoceMenuOpen() && b->p2->activePocemonIndex != 2 && b->p2->operator[](2).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(2);
						b->setP2Action(9);
					}
				}
				else if (b->isP2Fainted())
				{
					if (b->p2->activePocemonIndex != 2 && b->p2->operator[](2).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(2);
						b->p2->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP2.getActivePocemon(), mP2);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Num0 || event.key.code == sf::Keyboard::Numpad4)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (!b->isP2PoceMenuOpen() && b->p2->getActivePocemon()->checkAbility(3))
					{
						b->setP2Action(3);
					}
					else if (b->isP2PoceMenuOpen() && b->p2->activePocemonIndex != 3 && b->p2->operator[](3).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(3);
						b->setP2Action(10);
					}
				}
				else if (b->isP2Fainted())
				{
					if (b->p2->activePocemonIndex != 3 && b->p2->operator[](3).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(3);
						b->p2->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP2.getActivePocemon(), mP2);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Dash || event.key.code == sf::Keyboard::Numpad5)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (b->isP2PoceMenuOpen() && b->p2->activePocemonIndex != 4 && b->p2->operator[](4).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(4);
						b->setP2Action(11);
					}
				}
				else if (b->isP2Fainted())
				{
					if (b->p2->activePocemonIndex != 4 && b->p2->operator[](4).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(4);
						b->p2->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP2.getActivePocemon(), mP2);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Equal || event.key.code == sf::Keyboard::Numpad6)
			{
				if (b->canContinue() && !b->playersReady() && !b->isAnyoneFainted())
				{
					if (b->isP2PoceMenuOpen() && b->p2->activePocemonIndex != 5 && b->p2->operator[](5).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(5);
						b->setP2Action(12);
					}
				}
				else if (b->isP2Fainted())
				{
					if (b->p2->activePocemonIndex != 5 && b->p2->operator[](5).getCurHp() > 0)
					{
						b->p2->setPreppedPocemon(5);
						b->p2->deployPreppedPocemon();
						BattleEvent beTemp = BattleEvent(BEvtType::PocemonDeployed, mP2.getActivePocemon(), mP2);
						Battle::addEvent(beTemp);
						b->setPause();
						b->resetPlayerActions();
						b->handleEventCommand();
						mMenu->setEventText(b->currentEvt.toString());
					}
					//iPoceP1 = static_cast<int>(p1.getActivePocemon()->getId());
					//p1PoceNameText.setString(p1.getActivePocemon()->getName());
				}
			}
			else if (event.key.code == sf::Keyboard::Tab)
			{
				if (!b->isAnyoneFainted())
					b->toggleP1PoceMenu();
			}
			else if (event.key.code == sf::Keyboard::Backspace || event.key.code == sf::Keyboard::Numpad0)
			{
				if (!b->isAnyoneFainted())
					b->toggleP2PoceMenu();
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