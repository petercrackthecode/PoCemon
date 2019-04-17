#include "Ability.h"
#include "PoCemon.h"


float Ability::getDmgMultiplier(Pocemon &defender) const
{
    int atkTypeInt = static_cast<int>(this->type);
    int defenderType1Int = static_cast<int>(defender.type1);
    int defenderType2Int = static_cast<int>(defender.type2);

    float dmgMultiplier = dmgMultTbl[atkTypeInt][defenderType1Int];
    dmgMultiplier = dmgMultiplier * dmgMultTbl[atkTypeInt][defenderType2Int];

    return dmgMultiplier;
}




// Damage Multiplier Table
// See 'main.cpp' for an example of how this table works.
// Also see this website: https://bulbapedia.bulbagarden.net/wiki/Type/Type_chart

const float Ability::dmgMultTbl[][19] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    { 1, 1, 1, 1, 1, 1, .5, 1, 0, .5, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 2, 1, .5, .5, 1, 2, .5, 0, 2, 1, 1, 1, 1, .5, 2, 1, 2, .5 },
    { 1, 1, 2, 1, 1, 1, .5, 2, 1, .5, 1, 1, 2, .5, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, .5, .5, .5, 1, .5, 0, 1, 1, 2, 1, 1, 1, 1, 1, 2 },
    { 1, 1, 1, 0, 2, 1, 2, .5, 1, 2, 2, 1, .5, 2, 1, 1, 1, 1, 1 },
    { 1, 1, .5, 2, 1, .5, 1, 2, 1, .5, 2, 1, 1, 1, 1, 2, 1, 1, 1 },
    { 1, 1, .5, .5, .5, 1, 1, 1, .5, .5, .5, 1, 2, 1, 2, 1, 1, 2, .5 },
    { 1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, .5, 1 },
    { 1, 1, 1, 1, 1, 1, 2, 1, 1, .5, .5, .5, 1, .5, 1, 2, 1, 1, 2 },
    { 1, 1, 1, 1, 1, 1, .5, 2, 1, 2, .5, .5, 2, 1, 1, 2, .5, 1, 1 },
    { 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 2, .5, .5, 1, 1, 1, .5, 1, 1 },
    { 1, 1, 1, .5, .5, 2, 2, .5, 1, .5, .5, 2, .5, 1, 1, 1, .5, 1, 1 },
    { 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 2, .5, .5, 1, 1, .5, 1, 1 },
    { 1, 1, 2, 1, 2, 1, 1, 1, 1, .5, 1, 1, 1, 1, .5, 1, 1, 0, 1 },
    { 1, 1, 1, 2, 1, 2, 1, 1, 1, .5, .5, .5, 2, 1, 1, .5, 2, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, .5, 1, 1, 1, 1, 1, 1, 2, 1, 0 },
    { 1, 1, .5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, .5, .5 },
    { 1, 1, 2, 1, .5, 1, 1, 1, 1, .5, .5, 1, 1, 1, 1, 1, 2, 2, 1 }
};

const struct Ability::AbilityData Ability::allAbilityData[] = {
{ AbilityId::Agility, "Acid Armor",  "Sharply raises user's Defense.",  Type::Poison,  AbilityCategory::Status, 0, 255, 20,  0 },
{ AbilityId::Amnesia, "Agility", "Sharply raises user's Speed.", Type::Psychic, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::Barrier, "Amnesia", "Sharply raises user's Special Defense.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::ConfuseRay, "Barrier", "Sharply raises user's Defense.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::Conversion, "Confuse Ray", "Confuses opponent.", Type::Ghost, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::DefenseCurl, "Conversion", "Changes user's type to that of its first move.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::Disable, "Defense Curl", "Raises user's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ AbilityId::DoubleTeam, "Disable", "Opponent can't use its last attack for a few turns.", Type::Normal, AbilityCategory::Status, 0, 140, 20, 0 },
{ AbilityId::Flash, "Double Team", "Raises user's Evasiveness.", Type::Normal, AbilityCategory::Status, 0, 255, 15, 0 },
{ AbilityId::FocusEnergy, "Flash", "Lowers opponent's Accuracy.", Type::Normal, AbilityCategory::Status, 0, 178, 20, 0 },
{ AbilityId::Glare, "Focus Energy", "Increases critical hit ratio.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::Growl, "Glare", "Paralyzes opponent.", Type::Normal, AbilityCategory::Status, 0, 191, 30, 0 },
{ AbilityId::Growth, "Growl", "Lowers opponent's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ AbilityId::Harden, "Growth", "Raises user's Attack and Special Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ AbilityId::Haze, "Harden", "Raises user's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::Hypnosis, "Haze", "Resets all stat changes.", Type::Ice, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::Kinesis, "Hypnosis", "Puts opponent to sleep.", Type::Psychic, AbilityCategory::Status, 0, 153, 20, 0 },
{ AbilityId::LeechSeed, "Kinesis", "Lowers opponent's Accuracy.", Type::Psychic, AbilityCategory::Status, 0, 204, 15, 0 },
{ AbilityId::Leer, "Leech Seed", "Drains HP from opponent each turn.", Type::Grass, AbilityCategory::Status, 0, 229, 10, 0 },
{ AbilityId::LightScreen, "Leer", "Lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 76 },
{ AbilityId::LovelyKiss, "Light Screen", "Halves damage from Special attacks for 5 turns.", Type::Psychic, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::Meditate, "Lovely Kiss", "Puts opponent to sleep.", Type::Normal, AbilityCategory::Status, 0, 191, 10, 0 },
{ AbilityId::Metronome, "Meditate", "Raises user's Attack.", Type::Psychic, AbilityCategory::Status, 0, 255, 40, 0 },
{ AbilityId::Mimic, "Metronome", "User performs almost any move in the game at random.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::Minimize, "Mimic", "Copies the opponent's last move.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::MirrorMove, "Minimize", "Sharply raises user's Evasiveness.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::Mist, "Mirror Move", "User performs the opponent's last move.", Type::Flying, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::PoisonGas, "Mist", "User's stats cannot be changed for a period of time.", Type::Ice, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::PoisonPowder, "Poison Gas", "Poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 140, 40, 0 },
{ AbilityId::Recover, "Poison Powder", "Poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 191, 35, 0 },
{ AbilityId::Reflect, "Recover", "User recovers half its max HP.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::Rest, "Reflect", "Halves damage from AbilityCategory::Physical attacks for 5 turns.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::Roar, "Rest", "User sleeps for 2 turns, but user is fully healed.", Type::Psychic, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::SandAttack, "Roar", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::Screech, "Sand Attack", "Lowers opponent's Accuracy.", Type::Ground, AbilityCategory::Status, 0, 255, 15, 0 },
{ AbilityId::Sharpen, "Screech", "Sharply lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 216, 40, 0 },
{ AbilityId::Sing, "Sharpen", "Raises user's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0 },
{ AbilityId::SleepPowder, "Sing", "Puts opponent to sleep.", Type::Normal, AbilityCategory::Status, 0, 140, 15, 0 },
{ AbilityId::Smokescreen, "Sleep Powder", "Puts opponent to sleep.", Type::Grass, AbilityCategory::Status, 0, 191, 15, 0 },
{ AbilityId::SoftBoiled, "Smokescreen", "Lowers opponent's Accuracy.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::Splash, "Soft-Boiled", "User recovers half its max HP.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::Spore, "Splash", "Doesn't do ANYTHING.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0 },
{ AbilityId::StringShot, "Spore", "Puts opponent to sleep.", Type::Grass, AbilityCategory::Status, 0, 255, 15, 0 },
{ AbilityId::StunSpore, "String Shot", "Sharply lowers opponent's Speed.", Type::Bug, AbilityCategory::Status, 0, 242, 40, 0 },
{ AbilityId::Substitute, "Stun Spore", "Paralyzes opponent.", Type::Grass, AbilityCategory::Status, 0, 191, 30, 0 },
{ AbilityId::Supersonic, "Substitute", "Uses HP to creates a decoy that takes hits.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::SwordsDance, "Supersonic", "Confuses opponent.", Type::Normal, AbilityCategory::Status, 0, 140, 20, 0 },
{ AbilityId::TailWhip, "Swords Dance", "Sharply raises user's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::Teleport, "Tail Whip", "Lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 76 },
{ AbilityId::ThunderWave, "Teleport", "Allows user to flee wild battles; also warps player to last PokeCenter.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0 },
{ AbilityId::Toxic, "Thunder Wave", "Paralyzes opponent.", Type::Electric, AbilityCategory::Status, 0, 255, 20, 25 },
{ AbilityId::Transform, "Toxic", "Badly poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 216, 10, 0 },
{ AbilityId::Whirlwind, "Transform", "User takes on the form and attacks of the opponent.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0 },
{ AbilityId::Withdraw, "Whirlwind", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, AbilityCategory::Status, 0, 216, 20, 0 },
{ AbilityId::Withdraw, "Withdraw", "Raises user's Defense.", Type::Water, AbilityCategory::Status, 0, 255, 40, 0 }
}

;
