
#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "randomGenerator.h"

Player::Player(const std::string &tempName) : name{tempName}, activePocemonIndex{0}
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

Pocemon& Player::operator[](const int &i)
{
    // TODO: Make a class exception?
    if ((i < 0) || (i >= pocemonTeam.size()))
        throw "No PoCemon exists at this index";

    return pocemonTeam.at(i);
}

Pocemon* Player::getActivePocemon()
{
    if (pocemonTeam.size() < activePocemonIndex + 1) {
        throw "Acitve index is higher than team size";
    }
    return &pocemonTeam.at(activePocemonIndex);


    //if (activePocemon == nullptr) {
    //    if (pocemonTeam.size() < 1) {
    //        // TODO: Make a class exception?
    //        throw "No PoCemon is active";
    //    }
    //    else
    //    {
    //        activePocemon = &pocemonTeam.at(0);
    //    }
    //}

    //return activePocemon;
}


void Player::setActivePocemon(const int &i)
{
    if (i >= pocemonTeam.size() || i < 0) {
        throw "Selected index is higher than team size";
    }

    activePocemonIndex = i;
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


void Player::generateRandomTeam(const int &minLvl /* = 75 */, const int &maxLvl /* = 95 */)
{
    // Remove any existing PoCemon
    while (pocemonTeam.size() > 0)
    {
        pocemonTeam.pop_back();
    }

    for (int i = 0; i < 6; ++i)
    {
        PkmnId randId = static_cast<PkmnId>(randomGenerator(1, 151));
        int randLvl = randomGenerator(minLvl, maxLvl);
        
        Pocemon newPocemon(randId, randLvl);
        newPocemon.assignRandomAbilitySet();
        this->addToTeam(newPocemon);
    }

    this->activePocemonIndex = 0;
}

// Displays info for all PoCemon in a team.
void Player::displayTeam()
{
    for (auto &pocemon : pocemonTeam)
    {
        pocemon.displayInfo();
    }
}
