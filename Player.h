#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include "PoCemon.h"

using namespace std;

class Player
{
public:
    Player(const string &tempName);
    void addToTeam(Pocemon &);
    Pocemon operator[](const int &i);
    void visitPoceCenter();
    void displayTeam();


    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    string name;
    list<Pocemon> pocemonTeam;




};






#endif
