#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "PoCemon.h"

class Player
{
public:
    Player(const std::string &tempName);
    void addToTeam(Pocemon &);
    Pocemon& operator[](const int &i);
    void visitPoceCenter();
    void generateRandomTeam(const int &minLvl = 75, const int &maxLvl = 95);
    void displayTeam();
    Pocemon* getActivePocemon();

    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    std::string name;
    std::vector<Pocemon> pocemonTeam;
    int activePocemonIndex;



};






#endif
