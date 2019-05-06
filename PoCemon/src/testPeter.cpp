#include "testTay.cpp"
#include "PoCemon.h"
#include "AttackAbility.h"
#include "Player.h"
#include "randomGenerator.h"
#include "AbilityFactory.h"
#include "Battle.h"
#include "sfTeamListItem.h"
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <chrono>
#include <thread>

void tayGraphicsTest();
void tayGraphicsAndBattleTest();
void tay();

void peter()
{
    Game game;
    game.run();
}
