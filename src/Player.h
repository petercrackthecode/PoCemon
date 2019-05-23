#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "PoCemon.h"

class Player
{
public:
    Player();
    Player(const std::string &tempName);
    void addToTeam(Pocemon &);
    Pocemon& operator[](const int &i);
    void visitPoceCenter();
    void generateRandomTeam(const int &minLvl = 75, const int &maxLvl = 95);
    void displayTeam();
    Pocemon* getActivePocemon();
    void setActivePocemon(const int &i);
	void setPreppedPocemon(const int &i);
	void deployPreppedPocemon();
	bool hasPreppedPocemon() const { return (activePocemonIndex != preppedPocemonIndex && preppedPocemonIndex >= 0); }

    std::string getName() const { return name; }

	std::vector<Pocemon> pocemonTeam;
	int activePocemonIndex = 0;

private:
    std::string name;
	int preppedPocemonIndex = -1;


};






#endif
