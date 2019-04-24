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
{ AbilityId::Agility, "Acid Armor",  "Sharply raises user's Defense.",  Type::Poison,  AbilityCategory::Status, 0, 255, 20,  0, StatusEffect::None },
{ AbilityId::Amnesia, "Agility", "Sharply raises user's Speed.", Type::Psychic, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::Barrier, "Amnesia", "Sharply raises user's Special Defense.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::ConfuseRay, "Barrier", "Sharply raises user's Defense.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Conversion, "Confuse Ray", "Confuses opponent.", Type::Ghost, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::DefenseCurl, "Conversion", "Changes user's type to that of its first move.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::Disable, "Defense Curl", "Raises user's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0, StatusEffect::None },
{ AbilityId::DoubleTeam, "Disable", "Opponent can't use its last attack for a few turns.", Type::Normal, AbilityCategory::Status, 0, 140, 20, 0, StatusEffect::None },
{ AbilityId::Flash, "Double Team", "Raises user's Evasiveness.", Type::Normal, AbilityCategory::Status, 0, 255, 15, 0, StatusEffect::None },
{ AbilityId::FocusEnergy, "Flash", "Lowers opponent's Accuracy.", Type::Normal, AbilityCategory::Status, 0, 178, 20, 0, StatusEffect::None },
{ AbilityId::Glare, "Focus Energy", "Increases critical hit ratio.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::Growl, "Glare", "Paralyzes opponent.", Type::Normal, AbilityCategory::Status, 0, 191, 30, 0, StatusEffect::None },
{ AbilityId::Growth, "Growl", "Lowers opponent's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0, StatusEffect::None },
{ AbilityId::Harden, "Growth", "Raises user's Attack and Special Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0, StatusEffect::None },
{ AbilityId::Haze, "Harden", "Raises user's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::Hypnosis, "Haze", "Resets all stat changes.", Type::Ice, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::Kinesis, "Hypnosis", "Puts opponent to sleep.", Type::Psychic, AbilityCategory::Status, 0, 153, 20, 0, StatusEffect::None },
{ AbilityId::LeechSeed, "Kinesis", "Lowers opponent's Accuracy.", Type::Psychic, AbilityCategory::Status, 0, 204, 15, 0, StatusEffect::None },
{ AbilityId::Leer, "Leech Seed", "Drains HP from opponent each turn.", Type::Grass, AbilityCategory::Status, 0, 229, 10, 0, StatusEffect::None },
{ AbilityId::LightScreen, "Leer", "Lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 76, StatusEffect::None },
{ AbilityId::LovelyKiss, "Light Screen", "Halves damage from Special attacks for 5 turns.", Type::Psychic, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::Meditate, "Lovely Kiss", "Puts opponent to sleep.", Type::Normal, AbilityCategory::Status, 0, 191, 10, 0, StatusEffect::None },
{ AbilityId::Metronome, "Meditate", "Raises user's Attack.", Type::Psychic, AbilityCategory::Status, 0, 255, 40, 0, StatusEffect::None },
{ AbilityId::Mimic, "Metronome", "User performs almost any move in the game at random.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::Minimize, "Mimic", "Copies the opponent's last move.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::MirrorMove, "Minimize", "Sharply raises user's Evasiveness.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::Mist, "Mirror Move", "User performs the opponent's last move.", Type::Flying, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::PoisonGas, "Mist", "User's stats cannot be changed for a period of time.", Type::Ice, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::PoisonPowder, "Poison Gas", "Poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 140, 40, 0, StatusEffect::None },
{ AbilityId::Recover, "Poison Powder", "Poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 191, 35, 0, StatusEffect::None },
{ AbilityId::Reflect, "Recover", "User recovers half its max HP.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::Rest, "Reflect", "Halves damage from AbilityCategory::Physical attacks for 5 turns.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Roar, "Rest", "User sleeps for 2 turns, but user is fully healed.", Type::Psychic, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::SandAttack, "Roar", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Screech, "Sand Attack", "Lowers opponent's Accuracy.", Type::Ground, AbilityCategory::Status, 0, 255, 15, 0, StatusEffect::None },
{ AbilityId::Sharpen, "Screech", "Sharply lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 216, 40, 0, StatusEffect::None },
{ AbilityId::Sing, "Sharpen", "Raises user's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 0, StatusEffect::None },
{ AbilityId::SleepPowder, "Sing", "Puts opponent to sleep.", Type::Normal, AbilityCategory::Status, 0, 140, 15, 0, StatusEffect::None },
{ AbilityId::Smokescreen, "Sleep Powder", "Puts opponent to sleep.", Type::Grass, AbilityCategory::Status, 0, 191, 15, 0, StatusEffect::None },
{ AbilityId::SoftBoiled, "Smokescreen", "Lowers opponent's Accuracy.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Splash, "Soft-Boiled", "User recovers half its max HP.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::Spore, "Splash", "Doesn't do ANYTHING.", Type::Normal, AbilityCategory::Status, 0, 255, 40, 0, StatusEffect::None },
{ AbilityId::StringShot, "Spore", "Puts opponent to sleep.", Type::Grass, AbilityCategory::Status, 0, 255, 15, 0, StatusEffect::None },
{ AbilityId::StunSpore, "String Shot", "Sharply lowers opponent's Speed.", Type::Bug, AbilityCategory::Status, 0, 242, 40, 0, StatusEffect::None },
{ AbilityId::Substitute, "Stun Spore", "Paralyzes opponent.", Type::Grass, AbilityCategory::Status, 0, 191, 30, 0, StatusEffect::None },
{ AbilityId::Supersonic, "Substitute", "Uses HP to creates a decoy that takes hits.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::SwordsDance, "Supersonic", "Confuses opponent.", Type::Normal, AbilityCategory::Status, 0, 140, 20, 0, StatusEffect::None },
{ AbilityId::TailWhip, "Swords Dance", "Sharply raises user's Attack.", Type::Normal, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Teleport, "Tail Whip", "Lowers opponent's Defense.", Type::Normal, AbilityCategory::Status, 0, 255, 30, 76, StatusEffect::None },
{ AbilityId::ThunderWave, "Teleport", "Allows user to flee wild battles; also warps player to last PokeCenter.", Type::Psychic, AbilityCategory::Status, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Toxic, "Thunder Wave", "Paralyzes opponent.", Type::Electric, AbilityCategory::Status, 0, 255, 20, 25, StatusEffect::None },
{ AbilityId::Transform, "Toxic", "Badly poisons opponent.", Type::Poison, AbilityCategory::Status, 0, 216, 10, 0, StatusEffect::None },
{ AbilityId::Whirlwind, "Transform", "User takes on the form and attacks of the opponent.", Type::Normal, AbilityCategory::Status, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::Withdraw, "Whirlwind", "In battles, the opponent switches. In the wild, the Pokemon runs.", Type::Normal, AbilityCategory::Status, 0, 216, 20, 0, StatusEffect::None },
{ AbilityId::Withdraw, "Withdraw", "Raises user's Defense.", Type::Water, AbilityCategory::Status, 0, 255, 40, 0, StatusEffect::None },
{ AbilityId::Absorb, "Absorb", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 20, 255, 25, 0, StatusEffect::None },
{ AbilityId::Acid, "Acid", "May lower opponent's Special Defense.", Type::Poison, AbilityCategory::Special, 40, 255, 30, 25, StatusEffect::SpDef1x },
{ AbilityId::AuroraBeam, "Aurora Beam", "May lower opponent's Attack.", Type::Ice, AbilityCategory::Special, 65, 255, 20, 25, StatusEffect::SpAtk1x },
{ AbilityId::Barrage, "Barrage", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0, StatusEffect::None },
{ AbilityId::Bide, "Bide", "User takes damage for two turns then strikes back double.", Type::Normal, AbilityCategory::Physical, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::Bind, "Bind", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, AbilityCategory::Physical, 15, 191, 20, 0, StatusEffect::Bind },
{ AbilityId::Bite, "Bite", "May cause flinching.", Type::Dark, AbilityCategory::Physical, 60, 255, 25, 0, StatusEffect::Flinch },
{ AbilityId::Blizzard, "Blizzard", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 110, 229, 5, 25, StatusEffect::Freeze },
{ AbilityId::BodySlam, "Body Slam", "May paralyze opponent.", Type::Normal, AbilityCategory::Physical, 85, 255, 15, 76, StatusEffect::Paralyze },
{ AbilityId::BoneClub, "Bone Club", "May cause flinching.", Type::Ground, AbilityCategory::Physical, 65, 216, 20, 25, StatusEffect::Flinch },
{ AbilityId::Bonemerang, "Bonemerang", "Hits twice in one turn.", Type::Ground, AbilityCategory::Physical, 50, 229, 10, 0, StatusEffect::None },
{ AbilityId::Bubble, "Bubble", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 40, 255, 30, 25, StatusEffect::Speed1x },
{ AbilityId::BubbleBeam, "Bubble Beam", "May lower opponent's Speed.", Type::Water, AbilityCategory::Special, 65, 255, 20, 25, StatusEffect::Speed1x },
{ AbilityId::Clamp, "Clamp", "Traps opponent, damaging them for 4-5 turns.", Type::Water, AbilityCategory::Physical, 35, 191, 10, 0, StatusEffect::Bind },
{ AbilityId::CometPunch, "Comet Punch", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 18, 216, 15, 0, StatusEffect::None },
{ AbilityId::Confusion, "Confusion", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 50, 255, 25, 25, StatusEffect::Confuse },
{ AbilityId::Constrict, "Constrict", "May lower opponent's Speed by one stage.", Type::Normal, AbilityCategory::Physical, 10, 255, 35, 25, StatusEffect::Speed1x },
{ AbilityId::Counter, "Counter", "When hit by a Physical Attack, user strikes back with 2x power.", Type::Fighting, AbilityCategory::Physical, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::Crabhammer, "Crabhammer", "High critical hit ratio.", Type::Water, AbilityCategory::Physical, 100, 216, 10, 0, StatusEffect::None },
{ AbilityId::Cut, "Cut", "", Type::Normal, AbilityCategory::Physical, 50, 242, 30, 0, StatusEffect::None },
{ AbilityId::Dig, "Dig", "Digs underground on first turn, attacks on second. Can also escape from caves.", Type::Ground, AbilityCategory::Physical, 80, 255, 10, 0, StatusEffect::None },
{ AbilityId::DizzyPunch, "Dizzy Punch", "May confuse opponent.", Type::Normal, AbilityCategory::Physical, 70, 255, 10, 51, StatusEffect::Confuse },
{ AbilityId::DoubleKick, "Double Kick", "Hits twice in one turn.", Type::Fighting, AbilityCategory::Physical, 30, 255, 30, 0, StatusEffect::None },
{ AbilityId::DoubleSlap, "Double Slap", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 10, 0, StatusEffect::None },
{ AbilityId::DoubleEdge, "Double-Edge", "User receives recoil damage.", Type::Normal, AbilityCategory::Physical, 120, 255, 15, 0, StatusEffect::None },
{ AbilityId::DragonRage, "Dragon Rage", "Always inflicts 40 HP.", Type::Dragon, AbilityCategory::Special, 0, 255, 10, 0, StatusEffect::None },
{ AbilityId::DreamEater, "Dream Eater", "User recovers half the HP inflicted on a sleeping opponent.", Type::Psychic, AbilityCategory::Special, 100, 255, 15, 0, StatusEffect::None },
{ AbilityId::DrillPeck, "Drill Peck", "", Type::Flying, AbilityCategory::Physical, 80, 255, 20, 0, StatusEffect::None },
{ AbilityId::Earthquake, "Earthquake", "Power is doubled if opponent is underground from using Dig.", Type::Ground, AbilityCategory::Physical, 100, 255, 10, 0, StatusEffect::None },
{ AbilityId::EggBomb, "Egg Bomb", "", Type::Normal, AbilityCategory::Physical, 100, 191, 10, 0, StatusEffect::None },
{ AbilityId::Ember, "Ember", "May burn opponent.", Type::Fire, AbilityCategory::Special, 40, 255, 25, 25, StatusEffect::Burn },
{ AbilityId::Explosion, "Explosion", "User faints.", Type::Normal, AbilityCategory::Physical, 250, 255, 5, 0, StatusEffect::None },
{ AbilityId::FireBlast, "Fire Blast", "May burn opponent.", Type::Fire, AbilityCategory::Special, 110, 216, 5, 25, StatusEffect::Burn },
{ AbilityId::FirePunch, "Fire Punch", "May burn opponent.", Type::Fire, AbilityCategory::Physical, 75, 255, 15, 25, StatusEffect::Burn },
{ AbilityId::FireSpin, "Fire Spin", "Traps opponent, damaging them for 4-5 turns.", Type::Fire, AbilityCategory::Special, 35, 178, 15, 0, StatusEffect::Bind },
{ AbilityId::Fissure, "Fissure", "One-Hit-KO, if it hits.", Type::Ground, AbilityCategory::Physical, 0, 76, 5, 0, StatusEffect::None },
{ AbilityId::Flamethrower, "Flamethrower", "May burn opponent.", Type::Fire, AbilityCategory::Special, 90, 255, 15, 25, StatusEffect::Burn },
{ AbilityId::Fly, "Fly", "Flies up on first turn, attacks on second turn.", Type::Flying, AbilityCategory::Physical, 90, 242, 15, 0, StatusEffect::None },
{ AbilityId::FuryAttack, "Fury Attack", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0, StatusEffect::None },
{ AbilityId::FurySwipes, "Fury Swipes", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 18, 204, 15, 0, StatusEffect::None },
{ AbilityId::Guillotine, "Guillotine", "One-Hit-KO, if it hits.", Type::Normal, AbilityCategory::Physical, 0, 76, 5, 0, StatusEffect::None },
{ AbilityId::Gust, "Gust", "Hits Pokemon using Fly/Bounce with double power.", Type::Flying, AbilityCategory::Special, 40, 255, 35, 0, StatusEffect::None },
{ AbilityId::Headbutt, "Headbutt", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 70, 255, 15, 76, StatusEffect::Flinch },
{ AbilityId::HighJumpKick, "High Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, AbilityCategory::Physical, 130, 229, 10, 0, StatusEffect::None },
{ AbilityId::HornAttack, "Horn Attack", "", Type::Normal, AbilityCategory::Physical, 65, 255, 25, 0, StatusEffect::None },
{ AbilityId::HornDrill, "Horn Drill", "One-Hit-KO, if it hits.", Type::Normal, AbilityCategory::Physical, 0, 76, 5, 0, StatusEffect::None },
{ AbilityId::HydroPump, "Hydro Pump", "", Type::Water, AbilityCategory::Special, 110, 204, 5, 0, StatusEffect::None },
{ AbilityId::HyperBeam, "Hyper Beam", "User must recharge next turn.", Type::Normal, AbilityCategory::Special, 150, 229, 5, 0, StatusEffect::None },
{ AbilityId::HyperFang, "Hyper Fang", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 80, 229, 15, 25, StatusEffect::Flinch },
{ AbilityId::IceBeam, "Ice Beam", "May freeze opponent.", Type::Ice, AbilityCategory::Special, 90, 255, 10, 25, StatusEffect::Freeze },
{ AbilityId::IcePunch, "Ice Punch", "May freeze opponent.", Type::Ice, AbilityCategory::Physical, 75, 255, 15, 25, StatusEffect::Freeze },
{ AbilityId::JumpKick, "Jump Kick", "If it misses, the user loses half their HP.", Type::Fighting, AbilityCategory::Physical, 100, 242, 10, 0, StatusEffect::None },
{ AbilityId::KarateChop, "Karate Chop", "High critical hit ratio.", Type::Fighting, AbilityCategory::Physical, 50, 255, 25, 0, StatusEffect::None },
{ AbilityId::LeechLife, "Leech Life", "User recovers half the HP inflicted on opponent.", Type::Bug, AbilityCategory::Physical, 80, 255, 10, 0, StatusEffect::None },
{ AbilityId::Lick, "Lick", "May paralyze opponent.", Type::Ghost, AbilityCategory::Physical, 30, 255, 30, 76, StatusEffect::Paralyze },
{ AbilityId::LowKick, "Low Kick", "The heavier the opponent, the stronger the attack.", Type::Fighting, AbilityCategory::Physical, 0, 229, 20, 76, StatusEffect::Flinch }, // TODO: Description is from gen III+, status effect is from gen I.
{ AbilityId::MegaDrain, "Mega Drain", "User recovers half the HP inflicted on opponent.", Type::Grass, AbilityCategory::Special, 40, 255, 15, 0, StatusEffect::None },
{ AbilityId::MegaKick, "Mega Kick", "", Type::Normal, AbilityCategory::Physical, 120, 191, 5, 0, StatusEffect::None },
{ AbilityId::MegaPunch, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0, StatusEffect::None },
{ AbilityId::NightShade, "Night Shade", "Inflicts damage equal to user's level.", Type::Ghost, AbilityCategory::Special, 0, 255, 15, 0, StatusEffect::None },
{ AbilityId::PayDay, "Pay Day", "A small amount of money is gained after the battle resolves.", Type::Normal, AbilityCategory::Physical, 40, 255, 20, 0, StatusEffect::None },
{ AbilityId::Peck, "Peck", "", Type::Flying, AbilityCategory::Physical, 35, 255, 35, 0, StatusEffect::None },
{ AbilityId::PetalDance, "Petal Dance", "User attacks for 2-3 turns but then becomes confused.", Type::Grass, AbilityCategory::Special, 120, 255, 10, 0, StatusEffect::None },
{ AbilityId::PinMissile, "Pin Missile", "Hits 2-5 times in one turn.", Type::Bug, AbilityCategory::Physical, 25, 216, 20, 0, StatusEffect::None },
{ AbilityId::PoisonSting, "Poison Sting", "May poison the opponent.", Type::Poison, AbilityCategory::Physical, 15, 255, 35, 51, StatusEffect::Poison },
{ AbilityId::Pound, "Pound", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0, StatusEffect::None },
{ AbilityId::Psybeam, "Psybeam", "May confuse opponent.", Type::Psychic, AbilityCategory::Special, 65, 255, 20, 25, StatusEffect::Confuse },
{ AbilityId::Psychic, "Psychic", "May lower opponent's Special Defense.", Type::Psychic, AbilityCategory::Special, 90, 255, 10, 25, StatusEffect::SpDef1x },
{ AbilityId::Psywave, "Psywave", "Inflicts damage 50-150% of user's level.", Type::Psychic, AbilityCategory::Special, 0, 204, 15, 0, StatusEffect::None },
{ AbilityId::QuickAttack, "Quick Attack", "User attacks first.", Type::Normal, AbilityCategory::Physical, 40, 255, 30, 0, StatusEffect::None },
{ AbilityId::Rage, "Rage", "Raises user's Attack when hit.", Type::Normal, AbilityCategory::Physical, 20, 255, 20, 0, StatusEffect::None }, // TODO: This is an Exception!!!! Raises user's attack.
{ AbilityId::RazorLeaf, "Razor Leaf", "High critical hit ratio.", Type::Grass, AbilityCategory::Physical, 55, 242, 25, 0, StatusEffect::None },
{ AbilityId::RazorWind, "Razor Wind", "Charges on first turn, attacks on second. High critical hit ratio.", Type::Normal, AbilityCategory::Special, 80, 191, 10, 0, StatusEffect::None },
{ AbilityId::RockSlide, "Rock Slide", "May cause flinching.", Type::Rock, AbilityCategory::Physical, 75, 229, 10, 76, StatusEffect::Flinch },
{ AbilityId::RockThrow, "Rock Throw", "", Type::Rock, AbilityCategory::Physical, 50, 64.7, 15, 0, StatusEffect::None },
{ AbilityId::RollingKick, "Rolling Kick", "May cause flinching.", Type::Fighting, AbilityCategory::Physical, 60, 216, 15, 76, StatusEffect::Flinch },
{ AbilityId::Scratch, "Scratch", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0, StatusEffect::None },
{ AbilityId::SeismicToss, "Seismic Toss", "Inflicts damage equal to user's level.", Type::Fighting, AbilityCategory::Physical, 0, 255, 20, 0, StatusEffect::None },
{ AbilityId::SelfDestruct, "Self-Destruct", "User faints.", Type::Normal, AbilityCategory::Physical, 200, 255, 5, 0, StatusEffect::None },
{ AbilityId::SkullBash, "Skull Bash", "Raises Defense on first turn, attacks on second.", Type::Normal, AbilityCategory::Physical, 130, 255, 10, 0, StatusEffect::None }, // TODO: This is an Exception!!!! Raises user's defense for 1 turn.
{ AbilityId::SkyAttack, "Sky Attack", "Charges on first turn, attacks on second. May cause flinching.", Type::Flying, AbilityCategory::Physical, 140, 229, 5, 76, StatusEffect::Flinch }, // TODO: FYI, in gen I, this didn't have a chance to flinch. Was added in gen III+, along with increased critical hit ratio.
{ AbilityId::Slam, "Slam", "", Type::Normal, AbilityCategory::Physical, 80, 191, 20, 0, StatusEffect::None },
{ AbilityId::Slash, "Slash", "High critical hit ratio.", Type::Normal, AbilityCategory::Physical, 70, 255, 20, 0, StatusEffect::None },
{ AbilityId::Sludge, "Sludge", "May poison opponent.", Type::Poison, AbilityCategory::Special, 65, 255, 20, 76, StatusEffect::Poison }, // TODO: Has a 40% (102) chance of a status effect in some gens?
{ AbilityId::Smog, "Smog", "May poison opponent.", Type::Poison, AbilityCategory::Special, 30, 178, 20, 102, StatusEffect::Poison },
{ AbilityId::SolarBeam, "Solar Beam", "Charges on first turn, attacks on second.", Type::Grass, AbilityCategory::Special, 120, 255, 10, 0, StatusEffect::None },
{ AbilityId::SonicBoom, "Sonic Boom", "Always inflicts 20 HP.", Type::Normal, AbilityCategory::Special, 0, 229, 20, 0, StatusEffect::None },
{ AbilityId::SpikeCannon, "Spike Cannon", "Hits 2-5 times in one turn.", Type::Normal, AbilityCategory::Physical, 20, 255, 15, 0, StatusEffect::None },
{ AbilityId::Stomp, "Stomp", "May cause flinching.", Type::Normal, AbilityCategory::Physical, 65, 255, 20, 76, StatusEffect::Flinch },
{ AbilityId::Strength, "Strength", "", Type::Normal, AbilityCategory::Physical, 80, 255, 15, 0, StatusEffect::None },
{ AbilityId::Struggle, "Struggle", "Only usable when all PP are gone. Hurts the user.", Type::Normal, AbilityCategory::Physical, 50, 255, 0, 0, StatusEffect::None },
{ AbilityId::Submission, "Submission", "User receives recoil damage.", Type::Fighting, AbilityCategory::Physical, 80, 204, 20, 0, StatusEffect::None },
{ AbilityId::SuperFang, "Super Fang", "Always takes off half of the opponent's HP.", Type::Normal, AbilityCategory::Physical, 0, 229, 10, 0, StatusEffect::None },
{ AbilityId::Surf, "Surf", "Hits all adjacent Pokemon.", Type::Water, AbilityCategory::Special, 90, 255, 15, 0, StatusEffect::None },
{ AbilityId::Swift, "Swift", "Ignores Accuracy and Evasiveness.", Type::Normal, AbilityCategory::Special, 60, 255, 20, 0, StatusEffect::None },
{ AbilityId::Tackle, "Tackle", "", Type::Normal, AbilityCategory::Physical, 40, 242, 35, 0, StatusEffect::None },
{ AbilityId::TakeDown, "Take Down", "User receives recoil damage.", Type::Normal, AbilityCategory::Physical, 90, 216, 20, 0, StatusEffect::None },
{ AbilityId::Thrash, "Thrash", "User attacks for 2-3 turns but then becomes confused.", Type::Normal, AbilityCategory::Physical, 120, 255, 10, 0, StatusEffect::None },
{ AbilityId::Thunder, "Thunder", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 110, 178, 10, 25, StatusEffect::Paralyze },
{ AbilityId::ThunderPunch, "Thunder Punch", "May paralyze opponent.", Type::Electric, AbilityCategory::Physical, 75, 255, 15, 25, StatusEffect::Paralyze },
{ AbilityId::ThunderShock, "Thunder Shock", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 40, 255, 30, 0, StatusEffect::Paralyze },
{ AbilityId::Thunderbolt, "Thunderbolt", "May paralyze opponent.", Type::Electric, AbilityCategory::Special, 90, 255, 15, 25, StatusEffect::Paralyze },
{ AbilityId::TriAttack, "Tri Attack", "May paralyze, burn or freeze opponent.", Type::Normal, AbilityCategory::Special, 80, 255, 10, 0, StatusEffect::BurnFreezeParalyze },
{ AbilityId::Twineedle, "Twineedle", "Hits twice in one turn. May poison opponent.", Type::Bug, AbilityCategory::Physical, 25, 255, 20, 51, StatusEffect::Poison },
{ AbilityId::ViceGrip, "Vice Grip", "", Type::Normal, AbilityCategory::Physical, 55, 255, 30, 0, StatusEffect::None },
{ AbilityId::VineWhip, "Vine Whip", "", Type::Grass, AbilityCategory::Physical, 45, 255, 25, 0, StatusEffect::None },
{ AbilityId::WaterGun, "Water Gun", "", Type::Water, AbilityCategory::Special, 40, 255, 25, 0, StatusEffect::None },
{ AbilityId::Waterfall, "Waterfall", "May cause flinching.", Type::Water, AbilityCategory::Physical, 80, 255, 15, 51, StatusEffect::Flinch },
{ AbilityId::WingAttack, "Wing Attack", "", Type::Flying, AbilityCategory::Physical, 60, 255, 35, 0, StatusEffect::None },
{ AbilityId::Wrap, "Wrap", "Traps opponent, damaging them for 4-5 turns.", Type::Normal, AbilityCategory::Physical, 15, 216, 20, 0, StatusEffect::Bind }
}

;
