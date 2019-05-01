#ifndef POCEMON_H
#define POCEMON_H

#include <map>
#include <string>
#include <vector>
#include "Enums.h"
#include "PoCemonData.h"
#include "AttackAbility.h"

class Pocemon
{
public:
    // Creates a PoCemon at the requested level.
    Pocemon(const PkmnId &selectedId, const int &lvl);

	int doDamage(const AttackAbility &attack, Pocemon &pocemon1);

    void displayInfo(bool detailed = false) const;

    void resetCurStats();

    PkmnId getId() const { return id; };
    int getLevel() const { return level; };

    std::string getName() const { return name; };
    Type getType1() const { return type1; };
    Type getType2() const { return type2; };
    bool hasType(const Type &t) const;

    int getCurHp() const { return curHp; };
    int getCurAtk() const { return applyStatStage(atk, statStages.atk); };
    int getCurDef() const { return applyStatStage(def, statStages.def); };
    int getCurSpeed() const { return applyStatStage(speed, statStages.speed); };
    int getCurSpAtk() const { return applyStatStage(spAtk, statStages.spAtk); };
    int getCurSpDef() const { return applyStatStage(spDef, statStages.spDef); };

    int getOriginalHp() const { return hp; };
    int getOriginalAtk() const { return atk; };
    int getOriginalDef() const { return def; };
    int getOriginalSpeed() const { return speed; };
    int getOriginalSpAtk() const { return spAtk; };
    int getOriginalSpDef() const { return spDef; };

    int getAccuracyStage() const { return statStages.accuracy; };
    int getEvasionStage() const { return statStages.evasion; };
    int getCriticalHitRatioStage() const { return statStages.criticalHitRatio; };

    bool canGetStatus(const StatusEffect &effect) const;

    bool modifyStatStage(Stat statToModify, const int &numOfStages);

    void assignAbilitySet(const std::vector<Ability*> &set);
    void assignRandomAbilitySet();

    bool checkAbility(const int &i) const;
    Ability* getAbility(const int &i) const;

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

    int& revealStatStage(Stat statStage);

    int applyStatStage(const int &statVal, const int &stage) const;

    PkmnId id;
    int level;

    std::string name;
    Type type1;
    Type type2;

    // TODO: I'm considering creating a Struct that holds all
    //       six stats (hp, atk, def, speed, spAtk, and spDef).
    //       Each PoCemon would have 4 of those Structs.
    //       (i.e, one for current stats, one for base stats,
    //       one for iv stats, and one for ev stats.)

    int curHp;
    int curAtk;
    int curDef;
    int curSpeed;
    int curSpAtk;
    int curSpDef;

    // Treat these as const during a fight:
    int hp;
    int atk;
    int def;
    int speed;
    int spAtk;
    int spDef;

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

    std::vector<Ability*> abilitySet;

    std::pair<StatusEffect, int> exclusiveStatusEffect { StatusEffect::None, 0 };
    std::map<StatusEffect, int> activeStatusEffects;

    struct StatStages {
        int atk;
        int def;
        int speed;
        int spAtk;
        int spDef;
        int accuracy;
        int evasion;
        int criticalHitRatio;
    };

    StatStages statStages;
    
};


#endif
