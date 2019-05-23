#include <ctime>
#include "AbilityFactory.h"
#include "Game.h"
#include "GameStateMenu.h"

using namespace std;

int main()
{
    // Seed for random number generation (this should only be done once throughout the entire program).
    srand(time(NULL));

    // Initialize the AbilityFactory
    AbilityFactory::init();

    Game game(sf::VideoMode(1280, 720), "PoCemon++");
    game.pushState(new GameStateMenu(&game));
    game.run();

    return 0;
}
