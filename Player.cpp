
#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"

Player::Player(const std::string &tempName) : name{tempName}
{

}


void Player::addToTeam(Pocemon &newPocemon)
{
    if (pocemonTeam.size() < 6)
    {
        pocemonTeam.push_back(newPocemon);
    }
    // TODO: Throw exception?
}

Pocemon Player::operator[](const int &i)
{
    // TODO: Make a class exception?
    if ((i < 0) || (i >= pocemonTeam.size()))
        throw "No PoCemon exists at this address";

    return pocemonTeam.at(i);
}

// Visiting a PoceCenter heals all your PoCemon and removes any status effects (poisoned, burned, etc).
void Player::visitPoceCenter()
{
    //for_each(pocemonTeam.begin(), pocemonTeam.end(), [](Pocemon &p) { p.resetCurStats(); });

    for (auto &pocemon : pocemonTeam)
    {
        pocemon.resetCurStats();
    }
}


// Displays info for all PoCemon in a team.
void Player::displayTeam()
{
    for (auto &pocemon : pocemonTeam)
    {
        pocemon.displayInfo();
    }
}
