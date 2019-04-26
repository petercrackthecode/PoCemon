#ifndef POCEMON_H
#define POCEMON_H

#include "Enums.h"
#include "PoCemonData.h"
#include "Combat.h"
#include "AttackStd.h"
#include "GameSprite.hpp"

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class Pocemon : public GameSprite
{
public: //private:
    // Creates a PoCemon at the requested level.
    Pocemon() : GameSprite("")   {
        
    }
    
    Pocemon(const PkmnId &selectedId, const int &lvl, std::string imagePath) : GameSprite(imagePath)
    {
        int tempId = static_cast<int>(selectedId);
        
        id = selectedId;
        level = lvl;
        name = PocemonData::allData[tempId].name;
        type1 = PocemonData::allData[tempId].type1;
        type2 = PocemonData::allData[tempId].type2;
        
        baseHp = PocemonData::allData[tempId].baseHp;
        baseAtk = PocemonData::allData[tempId].baseAtk;
        baseDef = PocemonData::allData[tempId].baseDef;
        baseSpeed = PocemonData::allData[tempId].baseSpeed;
        baseSpAtk = PocemonData::allData[tempId].baseSpAtk;
        baseSpDef = PocemonData::allData[tempId].baseSpDef;
        
        // Normally, IV values are a random int from 0 to 15
        // TODO: Need to implement randomization.
        ivHp = 0;
        ivAtk = 0;
        ivDef = 0;
        ivSpeed = 0;
        ivSpAtk = 0;
        ivSpDef = 0;
        
        // EV values start at 0 and increase with each PoCemon defeated!
        evHp = 0;
        evAtk = 0;
        evDef = 0;
        evSpeed = 0;
        evSpAtk = 0;
        evSpDef = 0;
        
        hp = calculateStat(level, baseHp, ivHp, evHp, true);
        atk = calculateStat(level, baseAtk, ivAtk, evAtk);
        def = calculateStat(level, baseDef, ivDef, evDef);
        speed = calculateStat(level, baseSpeed, ivSpeed, evSpeed);
        spAtk = calculateStat(level, baseSpAtk, ivSpAtk, evSpAtk);
        spDef = calculateStat(level, baseSpDef, ivSpDef, evSpDef);
        
        curHp = hp;
        curAtk = atk;
        curDef = def;
        curSpeed = speed;
        curSpAtk = spAtk;
        curSpDef = spDef;
    }
    
	void doDamage(AttackStd *attack, Pocemon *pocemon1, Pocemon *pocemon2);

    template <class BasicAttributeReturn>
    BasicAttributeReturn getBasicAttribute(BasicAttribute type) const;

    int getStat(Stat type) const;


    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************

    // Calculates an individual stat value.
    // If calculating HP, set "isHp" to true.
    static int calculateStat(const int &lvl,
                             const int &baseStat,
                             const int &ivStat = 0,
                             const int &evStat = 0,
                             const bool &isHp = false);


    PkmnId id; // Need Getter
    int level; // Need Getter

    std::string name; // Need Getter
    Type type1; // Need Getter
    Type type2; // Need Getter

    // TODO: I'm considering creating a Struct that holds all
    //       six stats (hp, atk, def, speed, spAtk, and spDef).
    //       Each PoCemon would have 4 of those Structs.
    //       (i.e, one for current stats, one for base stats,
    //        one for iv stats, and one for ev stats.)

    int curHp;
    int curAtk;
    int curDef;
    int curSpeed;
    int curSpAtk;
    int curSpDef;

    // Treat these as const during a fight:
    int hp; // Need Getter
    int atk; // Need Getter
    int def; // Need Getter
    int speed; // Need Getter
    int spAtk; // Need Getter
    int spDef; // Need Getter

    int baseHp;
    int baseAtk;
    int baseDef;
    int baseSpeed;
    int baseSpAtk;
    int baseSpDef;

    // Varation between different Pikachu
    int ivHp;
    int ivAtk;
    int ivDef;
    int ivSpeed;
    int ivSpAtk;
    int ivSpDef;

    int evHp;
    int evAtk;
    int evDef;
    int evSpeed;
    int evSpAtk;
    int evSpDef;


    
};


#endif
