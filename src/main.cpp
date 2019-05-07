#include <iostream>
#include <iomanip>
#include <ctime>
#include "AbilityFactory.h"
#include "Enums.h"
#include "Game.h"
#include "GameStateMenu.h"
#include "PoCemon.h"
#include "PoCemonData.h"
#include "Structs.h"

using namespace std;

void aman();
void kate();
void peter();
void tay();

int main()
{
    // Seed for random number generation (this should only be done once throughout the entire program).
    srand(time(NULL));

    // Initialize the AbilityFactory
    AbilityFactory::init();

    int whoAreYou;
    cout << "Who are you?" << endl;
    cout << "1. Aman" << endl << "2. Kate" << endl << "3. Peter" << endl << "4. Tay" << endl << "5+ Main" << endl;
    cin >> whoAreYou;
    cin.clear();
    cin.ignore(1000, '\n');

    switch (whoAreYou){
    case 1: aman(); return 0; break;
    case 2: kate(); return 0; break;
    case 3: peter(); return 0; break;
    case 4: tay(); return 0; break;
    default: break;
    }

    //Game game(sf::VideoMode(1280, 720), "PoCemon++", sf::Style::Fullscreen);
    Game game(sf::VideoMode(1280, 720), "PoCemon++");
    game.pushState(new GameStateMenu(&game));
    game.run();



    return 0;
}
