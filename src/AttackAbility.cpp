#include <iostream>
#include <string>
#include "AttackAbility.h"
#include "Enums.h"
#include "PoCemon.h"
#include "randomGenerator.h"

using namespace std;

// TODO: Rename to AttackAbility
AttackAbility::AttackAbility(const AbilityId &tempId,
                             const std::string &tempName,
                             const std::string &tempDescription,
                             //const std::string &tempDevDescription,
                             const Type &tempType,
                             const AbilityCategory &tempAbilityCategory,
                             const int &tempPower,
                             const int &tempAccuracy,
                             const int &tempMaxPP,
                             const int &tempStatusEffectChance,
                             const StatusEffect &tempStatusEffectType)
                    : Ability{ tempId, tempName, tempDescription, tempType,
                               tempAbilityCategory, tempPower, tempAccuracy,
                               tempMaxPP, tempStatusEffectChance, tempStatusEffectType }
{}

// Calculates the Hit Threshold (likelyhood of hitting with an attack) based on
// the Attack's accuracy and the accuracy/evasion stat stages of the attacker/defender.
int AttackAbility::calculateHitThreshold(Pocemon &attacker, Pocemon &defender) const
{
    int combinedStatStage = attacker.getAccuracyStage() - defender.getEvasionStage();

    // Positive Combined Stat Stages increase the numerator.
    // Negative Combined Stat Stages increase the denominator.
    int numerator = 3;
    int denominator = 3;

    if (combinedStatStage > 0)
        numerator += combinedStatStage;
    else if (combinedStatStage < 0)
        denominator += -1 * combinedStatStage;

    int threshold = (this->accuracy * numerator) / denominator;

    if (threshold < 1)
        threshold = 1;
    else if (threshold > 255)
        threshold = 255;

    return threshold;

}

// Determines whether an attack hits (true) or misses (false)
bool AttackAbility::doesAttackHit(Pocemon &attacker, Pocemon &defender) const
{
    // Threshold is the likelyhood of hitting with an attack. The higher the number, the better.
    int threshold = calculateHitThreshold(attacker, defender);

    int outcome = threshold - randomGenerator();
    
    // if (threshold - RandomNumber) is a negative value, the attack missed.
    if (outcome < 0)
        return false;
    else
        return true;
}


bool AttackAbility::use(Pocemon &attacker, Pocemon &defender)
{
    cout << attacker.name << " used " << this->name << "!" << endl;
    if (doesAttackHit(attacker, defender))
    {
        cout << "Attack missed." << endl;
        return false; // Attack misses.
    }

    cout << "Attack hit!" << endl;
    attacker.doDamage(*this, defender);
    defender.displayInfo();

    return true;
}



// Ability data, to be used in the future @__@

/*

// Status Abilities:

{ 151, "Acid Armor", "Sharply raises user's Defense.", Type::Poison, AbilityCategory::Status, 0, 255, 20, 0 },
{ 97, "Agility", "Sharply raises user's Speed.", Type::Psychic, AbilityCategory::Status, 0, 255, 30, 0 },
{ 133, "Amnesia", "Sharply raises user's Special Defense.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ 112, "Barrier", "Sharply raises user's Defense.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ 109, "Confuse Ray", "Confuses opponent.", Type::Ghost, AbilityCategory::Status, 0, 255, 10, 0 },
{ 160, "Conversion", "Changes user's type to that of its first move.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ 111, "Defense Curl", "Raises user's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ 50, "Disable", "Opponent can't use its last attack for a few turns.", Type::Normal, AbilityCategory::Status, 0, 140, 20, 0 },
{ 104, "Double Team", "Raises user's Evasiveness.", Type::Normal, AbilityCategory::Status, 0, 255, 15, 0 },
{ 148, "Flash", "Lowers opponent's Accuracy.", Type::Normal, AbilityCategory::Status, 0, 178, 20, 0 },
{ 116, "Focus Energy", "Increases critical hit ratio.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ 137, "Glare", "Paralyzes opponent.", Type::Normal, AbilityCategory::Status, 0, 191, 30, 0 },
{ 45, "Growl", "Lowers opponent's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ 74, "Growth", "Raises user's Attack and Special Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ 106, "Harden", "Raises user's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ 114, "Haze", "Resets all stat changes.", Type::Ice, AbilityCategory::Status, 0, 255, 30, 0 },
{ 95, "Hypnosis", "Puts opponent to sleep.", Type::Psychic, AbilityCategory::Status, 0, 153, 20, 0 },
{ 134, "Kinesis", "Lowers opponent's Accuracy.", Type::Psychic, AbilityCategory::Status, 0, 204, 15, 0 },
{ 73, "Leech Seed", "Drains HP from opponent each turn.", Type::Grass, AbilityCategory::Status, 0, 229, 10, 0 },
{ 43, "Leer", "Lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 76 },
{ 113, "Light Screen", "Halves damage from Special attacks for 5 turns.", Type::Psychic, AbilityCategory::Status, 0, 255, 30, 0 },
{ 142, "Lovely Kiss", "Puts opponent to sleep.", Type::Normal, AbilityCategory::Status, 0, 191, 10, 0 },
{ 96, "Meditate", "Raises user's Attack.", Type::Psychic, AbilityCategory::Status, 0, 255, 40, 0 },
{ 118, "Metronome", "User performs almost any move in the game at random.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 102, "Mimic", "Copies the opponent's last move.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 107, "Minimize", "Sharply raises user's Evasiveness.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 119, "Mirror Move", "User performs the opponent's last move.", Type::Flying, AbilityCategory::Status, 0, 255, 20, 0 },
{ 54, "Mist", "User's stats cannot be changed for a period of time.", Type::Ice, AbilityCategory::Status, 0, 255, 30, 0 },
{ 139, "Poison Gas", "Poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 140, 40, 0 },
{ 77, "Poison Powder", "Poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 191, 35, 0 },
{ 105, "Recover", "User recovers half its max HP.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 115, "Reflect", "Halves damage from AbilityCategory::Physical attacks for 5 turns.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ 156, "Rest", "User sleeps for 2 turns, but user is fully healed.", Type::Psychic, AbilityCategory::Status, 0, 255, 10, 0 },
{ 46, "Roar", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0 },
{ 28, "Sand Attack", "Lowers opponent's Accuracy.", Type::Ground, AbilityCategory::Status, 0, 255, 15, 0 },
{ 103, "Screech", "Sharply lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 216, 40, 0 },
{ 159, "Sharpen", "Raises user's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ 47, "Sing", "Puts opponent to sleep.", Type::Normal, AbilityCategory::Status, 0, 140, 15, 0 },
{ 79, "Sleep Powder", "Puts opponent to sleep.", Type::Grass, AbilityCategory::Status, 0, 191, 15, 0 },
{ 108, "Smokescreen", "Lowers opponent's Accuracy.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0 },
{ 135, "Soft-Boiled", "User recovers half its max HP.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 150, "Splash", "Doesn't do ANYTHING.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ 147, "Spore", "Puts opponent to sleep.", Type::Grass, AbilityCategory::Status, 0, 255, 15, 0 },
{ 81, "String Shot", "Sharply lowers opponent's Speed.", Type::Bug, AbilityCategory::Status, 0, 242, 40, 0 },
{ 78, "Stun Spore", "Paralyzes opponent.", Type::Grass, AbilityCategory::Status, 0, 191, 30, 0 },
{ 164, "Substitute", "Uses HP to creates a decoy that takes hits.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 48, "Supersonic", "Confuses opponent.", Type::Normal, AbilityCategory::Status, 0, 140, 20, 0 },
{ 14, "Swords Dance", "Sharply raises user's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0 },
{ 39, "Tail Whip", "Lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 76 },
{ 100, "Teleport", "Allows user to flee wild battles; also warps player to last PokeCenter.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ 86, "Thunder Wave", "Paralyzes opponent.", Type::Electric, AbilityCategory::Status, 0, 255, 20, 25 },
{ 92, "Toxic", "Badly poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 216, 10, 0 },
{ 144, "Transform", "User takes on the form and attacks of the opponent.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ 18, "Whirlwind", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, AbilityCategory::Status, 0, 216, 20, 0 },
{ 110, "Withdraw", "Raises user's Defense.", Type::Water, AbilityCategory::Status, 0, 255, 40, 0 },






// Physical/Special Abilities:

{ 71, "Absorb", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 20, 255, 25, 0 },
{ 51, "Acid", "May lower opponent's Special Defense.", Type::Poison, AbilityCategory::Special, 40, 255, 30, 25 },
{ 62, "Aurora Beam", "May lower opponent's Attack.", Type::Ice, AbilityCategory::Special, 65, 255, 20, 25 },
{ 140, "Barrage", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0 },
{ 117, "Bide", "User takes damage for two turns then strikes back double.", Type::Normal, AbilityCategory::Physical, 0, 255, 10, 0 },
{ 20, "Bind", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, AbilityCategory::Physical, 15, 191, 20, 0 },
{ 44, "Bite", "May cause flinching.", Type::Dark, AbilityCategory::Physical, 60, 255, 25, 0 },
{ 59, "Blizzard", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 110, 229, 5, 25 },
{ 34, "Body Slam", "May paralyze opponent.", Type::Normal, AbilityCategory::Physical, 85, 255, 15, 76 },
{ 125, "Bone Club", "May cause flinching.", Type::Ground, AbilityCategory::Physical, 65, 216, 20, 25 },
{ 155, "Bonemerang", "Hits twice in one turn.", Type::Ground, AbilityCategory::Physical, 50, 229, 10, 0 },
{ 145, "Bubble", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 40, 255, 30, 25 },
{ 61, "Bubble Beam", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 65, 255, 20, 25 },
{ 128, "Clamp", "Traps opponent, damaging them for 4-5 turns.", Type::Water, AbilityCategory::Physical, 35, 191, 10, 0 },
{ 4, "Comet Punch", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 18, 216, 15, 0 },
{ 93, "Confusion", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 50, 255, 25, 25 },
{ 132, "Constrict", "May lower opponent's Speed by one stage.", Type::Normal, AbilityCategory::Physical, 10, 255, 35, 25 },
{ 68, "Counter", "When hit by a AbilityCategory::Physical Attack, user strikes back with 2x power.", Type::Fighting, AbilityCategory::Physical, 0, 255, 20, 0 },
{ 152, "Crabhammer", "High critical hit ratio.", Type::Water, AbilityCategory::Physical, 100, 216, 10, 0 },
{ 15, "Cut", "", Type::Normal, AbilityCategory::Physical, 50, 242, 30, 0 },
{ 91, "Dig", "Digs underground on first turn, attacks on second. Can also escape from caves.", Type::Ground, AbilityCategory::Physical, 80, 255, 10, 0 },
{ 146, "Dizzy Punch", "May confuse opponent.", Type::Normal, AbilityCategory::Physical, 70, 255, 10, 51 },
{ 24, "Double Kick", "Hits twice in one turn.", Type::Fighting, AbilityCategory::Physical, 30, 255, 30, 0 },
{ 3, "Double Slap", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 10, 0 },
{ 38, "Double-Edge", "User receives recoil damage.", Type::Normal, AbilityCategory::Physical, 120, 255, 15, 0 },
{ 82, "Dragon Rage", "Always inflicts 40 HP.", Type::Dragon, AbilityCategory::Special, 0, 255, 10, 0 },
{ 138, "Dream Eater", "User recovers half the HP inflicted on a sleeping opponent.", Type::Psychic, AbilityCategory::Special, 100, 255, 15, 0 },
{ 65, "Drill Peck", "", Type::Flying, AbilityCategory::Physical, 80, 255, 20, 0 },
{ 89, "Earthquake", "Power is doubled if opponent is underground from using Dig.", Type::Ground, AbilityCategory::Physical, 100, 255, 10, 0 },
{ 121, "Egg Bomb", "", Type::Normal, AbilityCategory::Physical, 100, 191, 10, 0 },
{ 52, "Ember", "May burn opponent.", Type::Fire, AbilityCategory::Special, 40, 255, 25, 25 },
{ 153, "Explosion", "User faints.", Type::Normal, AbilityCategory::Physical, 250, 255, 5, 0 },
{ 126, "Fire Blast", "May burn opponent.", Type::Fire, AbilityCategory::Special, 110, 216, 5, 25 },
{ 7, "Fire Punch", "May burn opponent.", Type::Fire, AbilityCategory::Physical, 75, 255, 15, 25 },
{ 83, "Fire Spin", "Traps opponent, damaging them for 4-5 turns.", Type::Fire, AbilityCategory::Special, 35, 178, 15, 0 },
{ 90, "Fissure", "One-Hit-KO, if it hits.", Type::Ground, AbilityCategory::Physical, 0, 76, 5, 0 },
{ 53, "Flamethrower", "May burn opponent.", Type::Fire, AbilityCategory::Special, 90, 255, 15, 25 },
{ 19, "Fly", "Flies up on first turn, attacks on second turn.", Type::Flying, AbilityCategory::Physical, 90, 242, 15, 0 },
{ 31, "Fury Attack", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0 },
{ 154, "Fury Swipes", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 18, 204, 15, 0 },
{ 12, "Guillotine", "One-Hit-KO, if it hits.", Type::Normal, AbilityCategory::Physical, 0, 76, 5, 0 },
{ 16, "Gust", "Hits Pokemon using Fly/Bounce with double power.", Type::Flying, AbilityCategory::Special, 40, 255, 35, 0 },
{ 29, "Headbutt", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 70, 255, 15, 76 },
{ 136, "High Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, AbilityCategory::Physical, 130, 229, 10, 0 },
{ 30, "Horn Attack", "", Type::Normal, AbilityCategory::Physical, 65, 255, 25, 0 },
{ 32, "Horn Drill", "One-Hit-KO, if it hits.", Type::Normal, AbilityCategory::Physical, 0, 76, 5, 0 },
{ 56, "Hydro Pump", "", Type::Water, AbilityCategory::Special, 110, 204, 5, 0 },
{ 63, "Hyper Beam", "User must recharge next turn.", Type::Normal, AbilityCategory::Special, 150, 229, 5, 0 },
{ 158, "Hyper Fang", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 80, 229, 15, 25 },
{ 58, "Ice Beam", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 90, 255, 10, 25 },
{ 8, "Ice Punch", "May freeze opponent.", Type::Ice, AbilityCategory::Physical, 75, 255, 15, 25 },
{ 26, "Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, AbilityCategory::Physical, 100, 242, 10, 0 },
{ 2, "Karate Chop", "High critical hit ratio.", Type::Fighting, AbilityCategory::Physical, 50, 255, 25, 0 },
{ 141, "Leech Life", "User recovers half the HP inflicted on opponent.", Type::Bug, AbilityCategory::Physical, 80, 255, 10, 0 },
{ 122, "Lick", "May paralyze opponent.", Type::Ghost, AbilityCategory::Physical, 30, 255, 30, 76 },
{ 67, "Low Kick", "The heavier the opponent, the stronger the attack.", Type::Fighting, AbilityCategory::Physical, 0, 229, 20, 76 },
{ 72, "Mega Drain", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 40, 255, 15, 0 },
{ 25, "Mega Kick", "", Type::Normal, AbilityCategory::Physical, 120, 191, 5, 0 },
{ 5, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0 },
{ 101, "Night Shade", "Inflicts damage equal to user's level.", Type::Ghost, AbilityCategory::Special, 0, 255, 15, 0 },
{ 6, "Pay Day", "A small amount of money is gained after the battle resolves.", Type::Normal, AbilityCategory::Physical, 40, 255, 20, 0 },
{ 64, "Peck", "", Type::Flying, AbilityCategory::Physical, 35, 255, 35, 0 },
{ 80, "Petal Dance", "User attacks for 2-3 turns but then becomes confused.", Type::Grass, AbilityCategory::Special, 120, 255, 10, 0 },
{ 42, "Pin Missile", "Hits 2-5 times in one turn.", Type::Bug, AbilityCategory::Physical, 25, 216, 20, 0 },
{ 40, "Poison Sting", "May poison the opponent.", Type::Poison, AbilityCategory::Physical, 15, 255, 35, 51 },
{ 1, "Pound", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0 },
{ 60, "Psybeam", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 65, 255, 20, 25 },
{ 94, "Psychic", "May lower opponent's Special Defense.", Type::Psychic, AbilityCategory::Special, 90, 255, 10, 25 },
{ 149, "Psywave", "Inflicts damage 50-150% of user's level.", Type::Psychic, AbilityCategory::Special, 0, 204, 15, 0 },
{ 98, "Quick Attack", "User attacks first.", Type::Normal, AbilityCategory::Physical, 40, 255, 30, 0 },
{ 99, "Rage", "Raises user's Attack when hit.", Type::Normal, AbilityCategory::Physical, 20, 255, 20, 0 },
{ 75, "Razor Leaf", "High critical hit ratio.", Type::Grass, AbilityCategory::Physical, 55, 242, 25, 0 },
{ 13, "Razor Wind", "Charges on first turn, attacks on second. High critical hit ratio.", Type::Normal, AbilityCategory::Special, 80, 191, 10, 0 },
{ 157, "Rock Slide", "May cause flinching.", Type::Rock, AbilityCategory::Physical, 75, 229, 10, 76 },
{ 88, "Rock Throw", "", Type::Rock, AbilityCategory::Physical, 50, 64.7, 15, 0 },
{ 27, "Rolling Kick", "May cause flinching.", Type::Fighting, AbilityCategory::Physical, 60, 216, 15, 76 },
{ 10, "Scratch", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0 },
{ 69, "Seismic Toss", "Inflicts damage equal to user's level.", Type::Fighting, AbilityCategory::Physical, 0, 255, 20, 0 },
{ 120, "Self-Destruct", "User faints.", Type::Normal, AbilityCategory::Physical, 200, 255, 5, 0 },
{ 130, "Skull Bash", "Raises Defense on first turn, attacks on second.", Type::Normal, AbilityCategory::Physical, 130, 255, 10, 0 },
{ 143, "Sky Attack", "Charges on first turn, attacks on second. May cause flinching.", Type::Flying, AbilityCategory::Physical, 140, 229, 5, 0 },
{ 21, "Slam", "", Type::Normal, AbilityCategory::Physical, 80, 191, 20, 0 },
{ 163, "Slash", "High critical hit ratio.", Type::Normal, AbilityCategory::Physical, 70, 255, 20, 0 },
{ 124, "Sludge", "May poison opponent.", Type::Poison, AbilityCategory::Special, 65, 255, 20, 76 },
{ 123, "Smog", "May poison opponent.", Type::Poison, AbilityCategory::Special, 30, 178, 20, 102 },
{ 76, "Solar Beam", "Charges on first turn, attacks on second.", Type::Grass, AbilityCategory::Special, 120, 255, 10, 0 },
{ 49, "Sonic Boom", "Always inflicts 20 HP.", Type::Normal, AbilityCategory::Special, 0, 229, 20, 0 },
{ 131, "Spike Cannon", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 20, 255, 15, 0 },
{ 23, "Stomp", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 65, 255, 20, 76 },
{ 70, "Strength", "", Type::Normal, AbilityCategory::Physical, 80, 255, 15, 0 },
{ 165, "Struggle", "Only usable when all PP are gone. Hurts the user.", Type::Normal, AbilityCategory::Physical, 50, 255, 0, 0 },
{ 66, "Submission", "User receives recoil damage.", Type::Fighting, AbilityCategory::Physical, 80, 204, 20, 0 },
{ 162, "Super Fang", "Always takes off half of the opponent's HP.", Type::Normal, AbilityCategory::Physical, 0, 229, 10, 0 },
{ 57, "Surf", "Hits all adjacent Pokemon.", Type::Water, AbilityCategory::Special, 90, 255, 15, 0 },
{ 129, "Swift", "Ignores Accuracy and Evasiveness.", Type::Normal, AbilityCategory::Special, 60, 255, 20, 0 },
{ 33, "Tackle", "", Type::Normal, AbilityCategory::Physical, 40, 242, 35, 0 },
{ 36, "Take Down", "User receives recoil damage.", Type::Normal, AbilityCategory::Physical, 90, 216, 20, 0 },
{ 37, "Thrash", "User attacks for 2-3 turns but then becomes confused.", Type::Normal, AbilityCategory::Physical, 120, 255, 10, 0 },
{ 87, "Thunder", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 110, 178, 10, 25 },
{ 9, "Thunder Punch", "May paralyze opponent.", Type::Electric, AbilityCategory::Physical, 75, 255, 15, 25 },
{ 84, "Thunder Shock", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 40, 255, 30, 0 },
{ 85, "Thunderbolt", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 90, 255, 15, 25 },
{ 161, "Tri Attack", "May paralyze, burn or freeze opponent.", Type::Normal, AbilityCategory::Special, 80, 255, 10, 0 },
{ 41, "Twineedle", "Hits twice in one turn. May poison opponent.", Type::Bug, AbilityCategory::Physical, 25, 255, 20, 0 },
{ 11, "Vice Grip", "", Type::Normal, AbilityCategory::Physical, 55, 255, 30, 0 },
{ 22, "Vine Whip", "", Type::Grass, AbilityCategory::Physical, 45, 255, 25, 0 },
{ 55, "Water Gun", "", Type::Water, AbilityCategory::Special, 40, 255, 25, 0 },
{ 127, "Waterfall", "May cause flinching.", Type::Water, AbilityCategory::Physical, 80, 255, 15, 0 },
{ 17, "Wing Attack", "", Type::Flying, AbilityCategory::Physical, 60, 255, 35, 0 },
{ 35, "Wrap", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0 },













{ AbilityId::Absorb, "Absorb", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 20, 255, 25, 0 },
{ AbilityId::Acid, "Acid", "May lower opponent's Special Defense.", Type::Poison, AbilityCategory::Special, 40, 255, 30, 25 },
{ AbilityId::AuroraBeam, "Aurora Beam", "May lower opponent's Attack.", Type::Ice, AbilityCategory::Special, 65, 255, 20, 25 },
{ AbilityId::Barrage, "Barrage", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0 },
{ AbilityId::Bide, "Bide", "User takes damage for two turns then strikes back double.", Type::Normal, AbilityCategory::Physical, 0, 255, 10, 0 },
{ AbilityId::Bind, "Bind", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, AbilityCategory::Physical, 15, 191, 20, 0 },
{ AbilityId::Bite, "Bite", "May cause flinching.", Type::Dark, AbilityCategory::Physical, 60, 255, 25, 0 },
{ AbilityId::Blizzard, "Blizzard", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 110, 229, 5, 25 },
{ AbilityId::BodySlam, "Body Slam", "May paralyze opponent.", Type::Normal, AbilityCategory::Physical, 85, 255, 15, 76 },
{ AbilityId::BoneClub, "Bone Club", "May cause flinching.", Type::Ground, AbilityCategory::Physical, 65, 216, 20, 25 },
{ AbilityId::Bonemerang, "Bonemerang", "Hits twice in one turn.", Type::Ground, AbilityCategory::Physical, 50, 229, 10, 0 },
{ AbilityId::Bubble, "Bubble", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 40, 255, 30, 25 },
{ AbilityId::BubbleBeam, "Bubble Beam", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 65, 255, 20, 25 },
{ AbilityId::Clamp, "Clamp", "Traps opponent, damaging them for 4-5 turns.", Type::Water, AbilityCategory::Physical, 35, 191, 10, 0 },
{ AbilityId::CometPunch, "Comet Punch", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 18, 216, 15, 0 },
{ AbilityId::Confusion, "Confusion", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 50, 255, 25, 25 },
{ AbilityId::Constrict, "Constrict", "May lower opponent's Speed by one stage.", Type::Normal, AbilityCategory::Physical, 10, 255, 35, 25 },
{ AbilityId::Counter, "Counter", "When hit by a AbilityCategory::Physical Attack, user strikes back with 2x power.", Type::Fighting, AbilityCategory::Physical, 0, 255, 20, 0 },
{ AbilityId::Crabhammer, "Crabhammer", "High critical hit ratio.", Type::Water, AbilityCategory::Physical, 100, 216, 10, 0 },
{ AbilityId::Cut, "Cut", "", Type::Normal, AbilityCategory::Physical, 50, 242, 30, 0 },
{ AbilityId::Dig, "Dig", "Digs underground on first turn, attacks on second. Can also escape from caves.", Type::Ground, AbilityCategory::Physical, 80, 255, 10, 0 },
{ AbilityId::DizzyPunch, "Dizzy Punch", "May confuse opponent.", Type::Normal, AbilityCategory::Physical, 70, 255, 10, 51 },
{ AbilityId::DoubleKick, "Double Kick", "Hits twice in one turn.", Type::Fighting, AbilityCategory::Physical, 30, 255, 30, 0 },
{ AbilityId::DoubleSlap, "Double Slap", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 10, 0 },
{ AbilityId::DoubleEdge, "Double-Edge", "User receives recoil damage.", Type::Normal, AbilityCategory::Physical, 120, 255, 15, 0 },
{ AbilityId::DragonRage, "Dragon Rage", "Always inflicts 40 HP.", Type::Dragon, AbilityCategory::Special, 0, 255, 10, 0 },
{ AbilityId::DreamEater, "Dream Eater", "User recovers half the HP inflicted on a sleeping opponent.", Type::Psychic, AbilityCategory::Special, 100, 255, 15, 0 },
{ AbilityId::DrillPeck, "Drill Peck", "", Type::Flying, AbilityCategory::Physical, 80, 255, 20, 0 },
{ AbilityId::Earthquake, "Earthquake", "Power is doubled if opponent is underground from using Dig.", Type::Ground, AbilityCategory::Physical, 100, 255, 10, 0 },
{ AbilityId::EggBomb, "Egg Bomb", "", Type::Normal, AbilityCategory::Physical, 100, 191, 10, 0 },
{ AbilityId::Ember, "Ember", "May burn opponent.", Type::Fire, AbilityCategory::Special, 40, 255, 25, 25 },
{ AbilityId::Explosion, "Explosion", "User faints.", Type::Normal, AbilityCategory::Physical, 250, 255, 5, 0 },
{ AbilityId::FireBlast, "Fire Blast", "May burn opponent.", Type::Fire, AbilityCategory::Special, 110, 216, 5, 25 },
{ AbilityId::FirePunch, "Fire Punch", "May burn opponent.", Type::Fire, AbilityCategory::Physical, 75, 255, 15, 25 },
{ AbilityId::FireSpin, "Fire Spin", "Traps opponent, damaging them for 4-5 turns.", Type::Fire, AbilityCategory::Special, 35, 178, 15, 0 },
{ AbilityId::Fissure, "Fissure", "One-Hit-KO, if it hits.", Type::Ground, AbilityCategory::Physical, 0, 76, 5, 0 },
{ AbilityId::Flamethrower, "Flamethrower", "May burn opponent.", Type::Fire, AbilityCategory::Special, 90, 255, 15, 25 },
{ AbilityId::Fly, "Fly", "Flies up on first turn, attacks on second turn.", Type::Flying, AbilityCategory::Physical, 90, 242, 15, 0 },
{ AbilityId::FuryAttack, "Fury Attack", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0 },
{ AbilityId::FurySwipes, "Fury Swipes", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 18, 204, 15, 0 },
{ AbilityId::Guillotine, "Guillotine", "One-Hit-KO, if it hits.", Type::Normal, AbilityCategory::Physical, 0, 76, 5, 0 },
{ AbilityId::Gust, "Gust", "Hits Pokemon using Fly/Bounce with double power.", Type::Flying, AbilityCategory::Special, 40, 255, 35, 0 },
{ AbilityId::Headbutt, "Headbutt", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 70, 255, 15, 76 },
{ AbilityId::HighJumpKick, "High Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, AbilityCategory::Physical, 130, 229, 10, 0 },
{ AbilityId::HornAttack, "Horn Attack", "", Type::Normal, AbilityCategory::Physical, 65, 255, 25, 0 },
{ AbilityId::HornDrill, "Horn Drill", "One-Hit-KO, if it hits.", Type::Normal, AbilityCategory::Physical, 0, 76, 5, 0 },
{ AbilityId::HydroPump, "Hydro Pump", "", Type::Water, AbilityCategory::Special, 110, 204, 5, 0 },
{ AbilityId::HyperBeam, "Hyper Beam", "User must recharge next turn.", Type::Normal, AbilityCategory::Special, 150, 229, 5, 0 },
{ AbilityId::HyperFang, "Hyper Fang", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 80, 229, 15, 25 },
{ AbilityId::IceBeam, "Ice Beam", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 90, 255, 10, 25 },
{ AbilityId::IcePunch, "Ice Punch", "May freeze opponent.", Type::Ice, AbilityCategory::Physical, 75, 255, 15, 25 },
{ AbilityId::JumpKick, "Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, AbilityCategory::Physical, 100, 242, 10, 0 },
{ AbilityId::KarateChop, "Karate Chop", "High critical hit ratio.", Type::Fighting, AbilityCategory::Physical, 50, 255, 25, 0 },
{ AbilityId::LeechLife, "Leech Life", "User recovers half the HP inflicted on opponent.", Type::Bug, AbilityCategory::Physical, 80, 255, 10, 0 },
{ AbilityId::Lick, "Lick", "May paralyze opponent.", Type::Ghost, AbilityCategory::Physical, 30, 255, 30, 76 },
{ AbilityId::LowKick, "Low Kick", "The heavier the opponent, the stronger the attack.", Type::Fighting, AbilityCategory::Physical, 0, 229, 20, 76 },
{ AbilityId::MegaDrain, "Mega Drain", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 40, 255, 15, 0 },
{ AbilityId::MegaKick, "Mega Kick", "", Type::Normal, AbilityCategory::Physical, 120, 191, 5, 0 },
{ AbilityId::MegaPunch, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0 },
{ AbilityId::NightShade, "Night Shade", "Inflicts damage equal to user's level.", Type::Ghost, AbilityCategory::Special, 0, 255, 15, 0 },
{ AbilityId::PayDay, "Pay Day", "A small amount of money is gained after the battle resolves.", Type::Normal, AbilityCategory::Physical, 40, 255, 20, 0 },
{ AbilityId::Peck, "Peck", "", Type::Flying, AbilityCategory::Physical, 35, 255, 35, 0 },
{ AbilityId::PetalDance, "Petal Dance", "User attacks for 2-3 turns but then becomes confused.", Type::Grass, AbilityCategory::Special, 120, 255, 10, 0 },
{ AbilityId::PinMissile, "Pin Missile", "Hits 2-5 times in one turn.", Type::Bug, AbilityCategory::Physical, 25, 216, 20, 0 },
{ AbilityId::PoisonSting, "Poison Sting", "May poison the opponent.", Type::Poison, AbilityCategory::Physical, 15, 255, 35, 51 },
{ AbilityId::Pound, "Pound", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0 },
{ AbilityId::Psybeam, "Psybeam", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 65, 255, 20, 25 },
{ AbilityId::Psychic, "Psychic", "May lower opponent's Special Defense.", Type::Psychic, AbilityCategory::Special, 90, 255, 10, 25 },
{ AbilityId::Psywave, "Psywave", "Inflicts damage 50-150% of user's level.", Type::Psychic, AbilityCategory::Special, 0, 204, 15, 0 },
{ AbilityId::QuickAttack, "Quick Attack", "User attacks first.", Type::Normal, AbilityCategory::Physical, 40, 255, 30, 0 },
{ AbilityId::Rage, "Rage", "Raises user's Attack when hit.", Type::Normal, AbilityCategory::Physical, 20, 255, 20, 0 },
{ AbilityId::RazorLeaf, "Razor Leaf", "High critical hit ratio.", Type::Grass, AbilityCategory::Physical, 55, 242, 25, 0 },
{ AbilityId::RazorWind, "Razor Wind", "Charges on first turn, attacks on second. High critical hit ratio.", Type::Normal, AbilityCategory::Special, 80, 191, 10, 0 },
{ AbilityId::RockSlide, "Rock Slide", "May cause flinching.", Type::Rock, AbilityCategory::Physical, 75, 229, 10, 76 },
{ AbilityId::RockThrow, "Rock Throw", "", Type::Rock, AbilityCategory::Physical, 50, 64.7, 15, 0 },
{ AbilityId::RollingKick, "Rolling Kick", "May cause flinching.", Type::Fighting, AbilityCategory::Physical, 60, 216, 15, 76 },
{ AbilityId::Scratch, "Scratch", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0 },
{ AbilityId::SeismicToss, "Seismic Toss", "Inflicts damage equal to user's level.", Type::Fighting, AbilityCategory::Physical, 0, 255, 20, 0 },
{ AbilityId::SelfDestruct, "Self-Destruct", "User faints.", Type::Normal, AbilityCategory::Physical, 200, 255, 5, 0 },
{ AbilityId::SkullBash, "Skull Bash", "Raises Defense on first turn, attacks on second.", Type::Normal, AbilityCategory::Physical, 130, 255, 10, 0 },
{ AbilityId::SkyAttack, "Sky Attack", "Charges on first turn, attacks on second. May cause flinching.", Type::Flying, AbilityCategory::Physical, 140, 229, 5, 0 },
{ AbilityId::Slam, "Slam", "", Type::Normal, AbilityCategory::Physical, 80, 191, 20, 0 },
{ AbilityId::Slash, "Slash", "High critical hit ratio.", Type::Normal, AbilityCategory::Physical, 70, 255, 20, 0 },
{ AbilityId::Sludge, "Sludge", "May poison opponent.", Type::Poison, AbilityCategory::Special, 65, 255, 20, 76 },
{ AbilityId::Smog, "Smog", "May poison opponent.", Type::Poison, AbilityCategory::Special, 30, 178, 20, 102 },
{ AbilityId::SolarBeam, "Solar Beam", "Charges on first turn, attacks on second.", Type::Grass, AbilityCategory::Special, 120, 255, 10, 0 },
{ AbilityId::SonicBoom, "Sonic Boom", "Always inflicts 20 HP.", Type::Normal, AbilityCategory::Special, 0, 229, 20, 0 },
{ AbilityId::SpikeCannon, "Spike Cannon", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 20, 255, 15, 0 },
{ AbilityId::Stomp, "Stomp", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 65, 255, 20, 76 },
{ AbilityId::Strength, "Strength", "", Type::Normal, AbilityCategory::Physical, 80, 255, 15, 0 },
{ AbilityId::Struggle, "Struggle", "Only usable when all PP are gone. Hurts the user.", Type::Normal, AbilityCategory::Physical, 50, 255, 0, 0 },
{ AbilityId::Submission, "Submission", "User receives recoil damage.", Type::Fighting, AbilityCategory::Physical, 80, 204, 20, 0 },
{ AbilityId::SuperFang, "Super Fang", "Always takes off half of the opponent's HP.", Type::Normal, AbilityCategory::Physical, 0, 229, 10, 0 },
{ AbilityId::Surf, "Surf", "Hits all adjacent Pokemon.", Type::Water, AbilityCategory::Special, 90, 255, 15, 0 },
{ AbilityId::Swift, "Swift", "Ignores Accuracy and Evasiveness.", Type::Normal, AbilityCategory::Special, 60, 255, 20, 0 },
{ AbilityId::Tackle, "Tackle", "", Type::Normal, AbilityCategory::Physical, 40, 242, 35, 0 },
{ AbilityId::TakeDown, "Take Down", "User receives recoil damage.", Type::Normal, AbilityCategory::Physical, 90, 216, 20, 0 },
{ AbilityId::Thrash, "Thrash", "User attacks for 2-3 turns but then becomes confused.", Type::Normal, AbilityCategory::Physical, 120, 255, 10, 0 },
{ AbilityId::Thunder, "Thunder", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 110, 178, 10, 25 },
{ AbilityId::ThunderPunch, "Thunder Punch", "May paralyze opponent.", Type::Electric, AbilityCategory::Physical, 75, 255, 15, 25 },
{ AbilityId::ThunderShock, "Thunder Shock", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 40, 255, 30, 0 },
{ AbilityId::Thunderbolt, "Thunderbolt", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 90, 255, 15, 25 },
{ AbilityId::TriAttack, "Tri Attack", "May paralyze, burn or freeze opponent.", Type::Normal, AbilityCategory::Special, 80, 255, 10, 0 },
{ AbilityId::Twineedle, "Twineedle", "Hits twice in one turn. May poison opponent.", Type::Bug, AbilityCategory::Physical, 25, 255, 20, 0 },
{ AbilityId::ViceGrip, "Vice Grip", "", Type::Normal, AbilityCategory::Physical, 55, 255, 30, 0 },
{ AbilityId::VineWhip, "Vine Whip", "", Type::Grass, AbilityCategory::Physical, 45, 255, 25, 0 },
{ AbilityId::WaterGun, "Water Gun", "", Type::Water, AbilityCategory::Special, 40, 255, 25, 0 },
{ AbilityId::Waterfall, "Waterfall", "May cause flinching.", Type::Water, AbilityCategory::Physical, 80, 255, 15, 0 },
{ AbilityId::WingAttack, "Wing Attack", "", Type::Flying, AbilityCategory::Physical, 60, 255, 35, 0 },
{ AbilityId::Wrap, "Wrap", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0 },




*/
