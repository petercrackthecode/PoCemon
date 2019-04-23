#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "PoCemon.h"

using namespace std;

class Player
{
public:
    Player(const string &tempName);
    void addToTeam(Pocemon &);
    Pocemon& operator[](const int &i);
    void visitPoceCenter();
    void generateRandomTeam(const int &minLvl = 75, const int &maxLvl = 95);
    void displayTeam();
    Pocemon* getActivePocemon();

    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    string name;
    vector<Pocemon> pocemonTeam;
    int activePocemonIndex;



};






#endif
