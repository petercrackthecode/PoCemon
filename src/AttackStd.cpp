#include <iostream>
#include <string>
#include "AttackStd.h"
#include "Enums.h"
#include "PoCemon.h"

using namespace std;

AttackStd::AttackStd(const int &tempId,
                     const std::string &tempName,
                     const std::string &tempDescription,
                     //const std::string &tempDevDescription,
                     const Type &tempType,
                     const AbilityCategory &tempAbilityCategory,
                     const int &tempPower,
                     const int &tempAccuracy,
                     const int &tempMaxPP) : Ability{ tempId, tempName, tempDescription,  tempType, tempAbilityCategory, tempPower, tempAccuracy, tempMaxPP }
{
    std::cout << this->description << std::endl;
    //id = tempId;
    //name = tempName;
    //description = tempDescription;
    //devDescription = ""; // tempDevDescription;
    //type = tempType;
    //abilityCategory = tempAbilityCategory;
    //power = tempPower;
    //accuracy = tempAccuracy;
    //maxPP = tempMaxPP;
}

bool AttackStd::preCombat(Pocemon attacker, Pocemon defender)
{

    return false;
}

bool AttackStd::mainEffect(Pocemon attacker, Pocemon defender)
{

    return false;
}

bool AttackStd::postCombat(Pocemon attacker, Pocemon defender)
{

    return false;
}



// Attack data, to be used in the future @__@

/*
{ 71, "Absorb", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 20, 100, 25 },
{ 51, "Acid", "May lower opponent's Special Defense.", Type::Poison, AbilityCategory::Special, 40, 100, 30 },
{ 151, "Acid Armor", "Sharply raises user's Defense.", Type::Poison, status, 0, 0, 20 },
{ 97, "Agility", "Sharply raises user's Speed.", Type::Psychic, status, 0, 0, 30 },
{ 133, "Amnesia", "Sharply raises user's Special Defense.", Type::Psychic, status, 0, 0, 20 },
{ 62, "Aurora Beam", "May lower opponent's Attack.", Type::Ice, AbilityCategory::Special, 65, 100, 20 },
{ 140, "Barrage", "Hits 2-5 times in one turn.", Type::Normal, physical, 15, 85, 20 },
{ 112, "Barrier", "Sharply raises user's Defense.", Type::Psychic, status, 0, 0, 20 },
{ 117, "Bide", "User takes damage for two turns then strikes back double.", Type::Normal, physical, 0, 0, 10 },
{ 20, "Bind", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, physical, 15, 85, 20 },
{ 44, "Bite", "May cause flinching.", Type::Dark, physical, 60, 100, 25 },
{ 59, "Blizzard", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 110, 70, 5 },
{ 34, "Body Slam", "May paralyze opponent.", Type::Normal, physical, 85, 100, 15 },
{ 125, "Bone Club", "May cause flinching.", Type::Ground, physical, 65, 85, 20 },
{ 155, "Bonemerang", "Hits twice in one turn.", Type::Ground, physical, 50, 90, 10 },
{ 145, "Bubble", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 40, 100, 30 },
{ 61, "Bubble Beam", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 65, 100, 20 },
{ 128, "Clamp", "Traps opponent, damaging them for 4-5 turns.", Type::Water, physical, 35, 85, 10 },
{ 4, "Comet Punch", "Hits 2-5 times in one turn.", Type::Normal, physical, 18, 85, 15 },
{ 109, "Confuse Ray", "Confuses opponent.", Type::Ghost, status, 0, 100, 10 },
{ 93, "Confusion", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 50, 100, 25 },
{ 132, "Constrict", "May lower opponent's Speed by one stage.", Type::Normal, physical, 10, 100, 35 },
{ 160, "Conversion", "Changes user's type to that of its first move.", Type::Normal, status, 0, 0, 30 },
{ 68, "Counter", "When hit by a Physical Attack, user strikes back with 2x power.", Type::Fighting, physical, 0, 100, 20 },
{ 152, "Crabhammer", "High critical hit ratio.", Type::Water, physical, 100, 90, 10 },
{ 15, "Cut", "", Type::Normal, physical, 50, 95, 30 },
{ 111, "Defense Curl", "Raises user's Defense.", Type::Normal, status, 0, 0, 40 },
{ 91, "Dig", "Digs underground on first turn, attacks on second. Can also escape from caves.", Type::Ground, physical, 80, 100, 10 },
{ 50, "Disable", "Opponent can't use its last attack for a few turns.", Type::Normal, status, 0, 100, 20 },
{ 146, "Dizzy Punch", "May confuse opponent.", Type::Normal, physical, 70, 100, 10 },
{ 24, "Double Kick", "Hits twice in one turn.", Type::Fighting, physical, 30, 100, 30 },
{ 3, "Double Slap", "Hits 2-5 times in one turn.", Type::Normal, physical, 15, 85, 10 },
{ 104, "Double Team", "Raises user's Evasiveness.", Type::Normal, status, 0, 0, 15 },
{ 38, "Double-Edge", "User receives recoil damage.", Type::Normal, physical, 120, 100, 15 },
{ 82, "Dragon Rage", "Always inflicts 40 HP.", Type::Dragon, AbilityCategory::Special, 0, 100, 10 },
{ 138, "Dream Eater", "User recovers half the HP inflicted on a sleeping opponent.", Type::Psychic, AbilityCategory::Special, 100, 100, 15 },
{ 65, "Drill Peck", "", Type::Flying, physical, 80, 100, 20 },
{ 89, "Earthquake", "Power is doubled if opponent is underground from using Dig.", Type::Ground, physical, 100, 100, 10 },
{ 121, "Egg Bomb", "", Type::Normal, physical, 100, 75, 10 },
{ 52, "Ember", "May burn opponent.", Type::Fire, AbilityCategory::Special, 40, 100, 25 },
{ 153, "Explosion", "User faints.", Type::Normal, physical, 250, 100, 5 },
{ 126, "Fire Blast", "May burn opponent.", Type::Fire, AbilityCategory::Special, 110, 85, 5 },
{ 7, "Fire Punch", "May burn opponent.", Type::Fire, physical, 75, 100, 15 },
{ 83, "Fire Spin", "Traps opponent, damaging them for 4-5 turns.", Type::Fire, AbilityCategory::Special, 35, 85, 15 },
{ 90, "Fissure", "One-Hit-KO, if it hits.", Type::Ground, physical, 0, 0, 5 },
{ 53, "Flamethrower", "May burn opponent.", Type::Fire, AbilityCategory::Special, 90, 100, 15 },
{ 148, "Flash", "Lowers opponent's Accuracy.", Type::Normal, status, 0, 100, 20 },
{ 19, "Fly", "Flies up on first turn, attacks on second turn.", Type::Flying, physical, 90, 95, 15 },
{ 116, "Focus Energy", "Increases critical hit ratio.", Type::Normal, status, 0, 0, 30 },
{ 31, "Fury Attack", "Hits 2-5 times in one turn.", Type::Normal, physical, 15, 85, 20 },
{ 154, "Fury Swipes", "Hits 2-5 times in one turn.", Type::Normal, physical, 18, 80, 15 },
{ 137, "Glare", "Paralyzes opponent.", Type::Normal, status, 0, 100, 30 },
{ 45, "Growl", "Lowers opponent's Attack.", Type::Normal, status, 0, 100, 40 },
{ 74, "Growth", "Raises user's Attack and Special Attack.", Type::Normal, status, 0, 0, 40 },
{ 12, "Guillotine", "One-Hit-KO, if it hits.", Type::Normal, physical, 0, 0, 5 },
{ 16, "Gust", "Hits Pokemon using Fly/Bounce with double power.", Type::Flying, AbilityCategory::Special, 40, 100, 35 },
{ 106, "Harden", "Raises user's Defense.", Type::Normal, status, 0, 0, 30 },
{ 114, "Haze", "Resets all stat changes.", Type::Ice, status, 0, 0, 30 },
{ 29, "Headbutt", "May cause flinching.", Type::Normal, physical, 70, 100, 15 },
{ 136, "High Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, physical, 130, 90, 10 },
{ 30, "Horn Attack", "", Type::Normal, physical, 65, 100, 25 },
{ 32, "Horn Drill", "One-Hit-KO, if it hits.", Type::Normal, physical, 0, 0, 5 },
{ 56, "Hydro Pump", "", Type::Water, AbilityCategory::Special, 110, 80, 5 },
{ 63, "Hyper Beam", "User must recharge next turn.", Type::Normal, AbilityCategory::Special, 150, 90, 5 },
{ 158, "Hyper Fang", "May cause flinching.", Type::Normal, physical, 80, 90, 15 },
{ 95, "Hypnosis", "Puts opponent to sleep.", Type::Psychic, status, 0, 60, 20 },
{ 58, "Ice Beam", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 90, 100, 10 },
{ 8, "Ice Punch", "May freeze opponent.", Type::Ice, physical, 75, 100, 15 },
{ 26, "Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, physical, 100, 95, 10 },
{ 2, "Karate Chop", "High critical hit ratio.", Type::Fighting, physical, 50, 100, 25 },
{ 134, "Kinesis", "Lowers opponent's Accuracy.", Type::Psychic, status, 0, 80, 15 },
{ 141, "Leech Life", "User recovers half the HP inflicted on opponent.", Type::Bug, physical, 80, 100, 10 },
{ 73, "Leech Seed", "Drains HP from opponent each turn.", Type::Grass, status, 0, 90, 10 },
{ 43, "Leer", "Lowers opponent's Defense.", Type::Normal, status, 0, 100, 30 },
{ 122, "Lick", "May paralyze opponent.", Type::Ghost, physical, 30, 100, 30 },
{ 113, "Light Screen", "Halves damage from Special attacks for 5 turns.", Type::Psychic, status, 0, 0, 30 },
{ 142, "Lovely Kiss", "Puts opponent to sleep.", Type::Normal, status, 0, 75, 10 },
{ 67, "Low Kick", "The heavier the opponent, the stronger the attack.", Type::Fighting, physical, 0, 100, 20 },
{ 96, "Meditate", "Raises user's Attack.", Type::Psychic, status, 0, 0, 40 },
{ 72, "Mega Drain", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 40, 100, 15 },
{ 25, "Mega Kick", "", Type::Normal, physical, 120, 75, 5 },
{ 5, "Mega Punch", "", Type::Normal, physical, 80, 85, 20 },
{ 118, "Metronome", "User performs almost any move in the game at random.", Type::Normal, status, 0, 0, 10 },
{ 102, "Mimic", "Copies the opponent's last move.", Type::Normal, status, 0, 0, 10 },
{ 107, "Minimize", "Sharply raises user's Evasiveness.", Type::Normal, status, 0, 0, 10 },
{ 119, "Mirror Move", "User performs the opponent's last move.", Type::Flying, status, 0, 0, 20 },
{ 54, "Mist", "User's stats cannot be changed for a period of time.", Type::Ice, status, 0, 0, 30 },
{ 101, "Night Shade", "Inflicts damage equal to user's level.", Type::Ghost, AbilityCategory::Special, 0, 100, 15 },
{ 6, "Pay Day", "A small amount of money is gained after the battle resolves.", Type::Normal, physical, 40, 100, 20 },
{ 64, "Peck", "", Type::Flying, physical, 35, 100, 35 },
{ 80, "Petal Dance", "User attacks for 2-3 turns but then becomes confused.", Type::Grass, AbilityCategory::Special, 120, 100, 10 },
{ 42, "Pin Missile", "Hits 2-5 times in one turn.", Type::Bug, physical, 25, 95, 20 },
{ 139, "Poison Gas", "Poisons opponent.", Type::Poison, status, 0, 90, 40 },
{ 77, "Poison Powder", "Poisons opponent.", Type::Poison, status, 0, 75, 35 },
{ 40, "Poison Sting", "May poison the opponent.", Type::Poison, physical, 15, 100, 35 },
{ 1, "Pound", "", Type::Normal, physical, 40, 100, 35 },
{ 60, "Psybeam", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 65, 100, 20 },
{ 94, "Psychic", "May lower opponent's Special Defense.", Type::Psychic, AbilityCategory::Special, 90, 100, 10 },
{ 149, "Psywave", "Inflicts damage 50-150% of user's level.", Type::Psychic, AbilityCategory::Special, 0, 80, 15 },
{ 98, "Quick Attack", "User attacks first.", Type::Normal, physical, 40, 100, 30 },
{ 99, "Rage", "Raises user's Attack when hit.", Type::Normal, physical, 20, 100, 20 },
{ 75, "Razor Leaf", "High critical hit ratio.", Type::Grass, physical, 55, 95, 25 },
{ 13, "Razor Wind", "Charges on first turn, attacks on second. High critical hit ratio.", Type::Normal, AbilityCategory::Special, 80, 100, 10 },
{ 105, "Recover", "User recovers half its max HP.", Type::Normal, status, 0, 0, 10 },
{ 115, "Reflect", "Halves damage from Physical attacks for 5 turns.", Type::Psychic, status, 0, 0, 20 },
{ 156, "Rest", "User sleeps for 2 turns, but user is fully healed.", Type::Psychic, status, 0, 0, 10 },
{ 46, "Roar", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, status, 0, 0, 20 },
{ 157, "Rock Slide", "May cause flinching.", Type::Rock, physical, 75, 90, 10 },
{ 88, "Rock Throw", "", Type::Rock, physical, 50, 90, 15 },
{ 27, "Rolling Kick", "May cause flinching.", Type::Fighting, physical, 60, 85, 15 },
{ 28, "Sand Attack", "Lowers opponent's Accuracy.", Type::Ground, status, 0, 100, 15 },
{ 10, "Scratch", "", Type::Normal, physical, 40, 100, 35 },
{ 103, "Screech", "Sharply lowers opponent's Defense.", Type::Normal, status, 0, 85, 40 },
{ 69, "Seismic Toss", "Inflicts damage equal to user's level.", Type::Fighting, physical, 0, 100, 20 },
{ 120, "Self-Destruct", "User faints.", Type::Normal, physical, 200, 100, 5 },
{ 159, "Sharpen", "Raises user's Attack.", Type::Normal, status, 0, 0, 30 },
{ 47, "Sing", "Puts opponent to sleep.", Type::Normal, status, 0, 55, 15 },
{ 130, "Skull Bash", "Raises Defense on first turn, attacks on second.", Type::Normal, physical, 130, 100, 10 },
{ 143, "Sky Attack", "Charges on first turn, attacks on second. May cause flinching.", Type::Flying, physical, 140, 90, 5 },
{ 21, "Slam", "", Type::Normal, physical, 80, 75, 20 },
{ 163, "Slash", "High critical hit ratio.", Type::Normal, physical, 70, 100, 20 },
{ 79, "Sleep Powder", "Puts opponent to sleep.", Type::Grass, status, 0, 75, 15 },
{ 124, "Sludge", "May poison opponent.", Type::Poison, AbilityCategory::Special, 65, 100, 20 },
{ 123, "Smog", "May poison opponent.", Type::Poison, AbilityCategory::Special, 30, 70, 20 },
{ 108, "Smokescreen", "Lowers opponent's Accuracy.", Type::Normal, status, 0, 100, 20 },
{ 135, "Soft-Boiled", "User recovers half its max HP.", Type::Normal, status, 0, 0, 10 },
{ 76, "Solar Beam", "Charges on first turn, attacks on second.", Type::Grass, AbilityCategory::Special, 120, 100, 10 },
{ 49, "Sonic Boom", "Always inflicts 20 HP.", Type::Normal, AbilityCategory::Special, 0, 90, 20 },
{ 131, "Spike Cannon", "Hits 2-5 times in one turn.", Type::Normal, physical, 20, 100, 15 },
{ 150, "Splash", "Doesn't do ANYTHING.", Type::Normal, status, 0, 0, 40 },
{ 147, "Spore", "Puts opponent to sleep.", Type::Grass, status, 0, 100, 15 },
{ 23, "Stomp", "May cause flinching.", Type::Normal, physical, 65, 100, 20 },
{ 70, "Strength", "", Type::Normal, physical, 80, 100, 15 },
{ 81, "String Shot", "Sharply lowers opponent's Speed.", Type::Bug, status, 0, 95, 40 },
{ 165, "Struggle", "Only usable when all PP are gone. Hurts the user.", Type::Normal, physical, 50, 100, 0 },
{ 78, "Stun Spore", "Paralyzes opponent.", Type::Grass, status, 0, 75, 30 },
{ 66, "Submission", "User receives recoil damage.", Type::Fighting, physical, 80, 80, 20 },
{ 164, "Substitute", "Uses HP to creates a decoy that takes hits.", Type::Normal, status, 0, 0, 10 },
{ 162, "Super Fang", "Always takes off half of the opponent's HP.", Type::Normal, physical, 0, 90, 10 },
{ 48, "Supersonic", "Confuses opponent.", Type::Normal, status, 0, 55, 20 },
{ 57, "Surf", "Hits all adjacent Pokemon.", Type::Water, AbilityCategory::Special, 90, 100, 15 },
{ 129, "Swift", "Ignores Accuracy and Evasiveness.", Type::Normal, AbilityCategory::Special, 60, 100, 20 },
{ 14, "Swords Dance", "Sharply raises user's Attack.", Type::Normal, status, 0, 0, 20 },
{ 33, "Tackle", "", Type::Normal, physical, 40, 100, 35 },
{ 39, "Tail Whip", "Lowers opponent's Defense.", Type::Normal, status, 0, 100, 30 },
{ 36, "Take Down", "User receives recoil damage.", Type::Normal, physical, 90, 85, 20 },
{ 100, "Teleport", "Allows user to flee wild battles; also warps player to last PokeCenter.", Type::Psychic, status, 0, 0, 20 },
{ 37, "Thrash", "User attacks for 2-3 turns but then becomes confused.", Type::Normal, physical, 120, 100, 10 },
{ 87, "Thunder", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 110, 70, 10 },
{ 9, "Thunder Punch", "May paralyze opponent.", Type::Electric, physical, 75, 100, 15 },
{ 84, "Thunder Shock", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 40, 100, 30 },
{ 86, "Thunder Wave", "Paralyzes opponent.", Type::Electric, status, 0, 90, 20 },
{ 85, "Thunderbolt", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 90, 100, 15 },
{ 92, "Toxic", "Badly poisons opponent.", Type::Poison, status, 0, 90, 10 },
{ 144, "Transform", "User takes on the form and attacks of the opponent.", Type::Normal, status, 0, 0, 10 },
{ 161, "Tri Attack", "May paralyze, burn or freeze opponent.", Type::Normal, AbilityCategory::Special, 80, 100, 10 },
{ 41, "Twineedle", "Hits twice in one turn. May poison opponent.", Type::Bug, physical, 25, 100, 20 },
{ 11, "Vice Grip", "", Type::Normal, physical, 55, 100, 30 },
{ 22, "Vine Whip", "", Type::Grass, physical, 45, 100, 25 },
{ 55, "Water Gun", "", Type::Water, AbilityCategory::Special, 40, 100, 25 },
{ 127, "Waterfall", "May cause flinching.", Type::Water, physical, 80, 100, 15 },
{ 18, "Whirlwind", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, status, 0, 0, 20 },
{ 17, "Wing Attack", "", Type::Flying, physical, 60, 100, 35 },
{ 110, "Withdraw", "Raises user's Defense.", Type::Water, status, 0, 0, 40 },
{ 35, "Wrap", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, physical, 15, 90, 20 },

*/
