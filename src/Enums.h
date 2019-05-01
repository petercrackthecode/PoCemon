#ifndef ENUMS_H
#define ENUMS_H

/*
 // Treat these as const during a fight:
    int hp; // Need Getter
    int atk; // Need Getter
    int def; // Need Getter
    int speed; // Need Getter
    int spAtk; // Need Getter
    int spDef; // Need Getter
 * */

enum class BasicAttribute {
    id,
    level,
    name,
    type1,
    type2
};

enum class Stat
{
    None,
    Hp,
    Atk,
    Def,
    Speed,
    SpAttack,
    SpDefense,
    Accuracy,
    Evasion,
    CriticalHitRatio
};


enum class StatusEffect
{
    None,
    Flinch,
    Bind,
    Burn,
    Confuse,
    Freeze,
    Paralyze,
    Poison,
    PoisonBadly,
    Rest,
    Sleep,
    BurnFreezeParalyze,
    Hp,
    Atk1x,
    Atk2x,
    Atk3x,
    Def1x,
    Def2x,
    Def3x,
    Speed1x,
    Speed2x,
    Speed3x,
    SpAtk1x,
    SpAtk2x,
    SpAtk3x,
    SpDef1x,
    SpDef2x,
    SpDef3x,
    Accuracy1x,
    Accuracy2x,
    Accuracy3x,
    Evasion1x,
    Evasion2x,
    Evasion3x,
    CriticalHitRatio1x,
    CriticalHitRatio2x,
    CriticalHitRatio3x
};


enum class AbilityCategory
{
    None,
    Physical,
    Status,
    Special
};

enum class Type
{
    undefined,
    Normal,
    Fighting,
    Flying,
    Poison,
    Ground,
    Rock,
    Bug,
    Ghost,
    Steel,
    Fire,
    Water,
    Grass,
    Electric,
    Psychic,
    Ice,
    Dragon,
    Dark,
    Fairy
};

// We might want to switch the Type enum to a
// namespaced enum or global enum in the future...
//
//namespace Type
//{
//	enum Type
//	{
//		None,
//		Normal,
//		Fighting,
//		Flying,
//		Poison,
//		Ground,
//		Rock,
//		Bug,
//		Ghost,
//		Steel,
//		Fire,
//		Water,
//		Grass,
//		Electric,
//		Psychic,
//		Ice,
//		Dragon,
//		Dark,
//		Fairy
//	};
//}

// A PoCemon's ID number.
enum class PkmnId
{
    MissingNo,
    Bulbasaur,
    Ivysaur,
    Venusaur,
    Charmander,
    Charmeleon,
    Charizard,
    Squirtle,
    Wartortle,
    Blastoise,
    Caterpie,
    Metapod,
    Butterfree,
    Weedle,
    Kakuna,
    Beedrill,
    Pidgey,
    Pidgeotto,
    Pidgeot,
    Rattata,
    Raticate,
    Spearow,
    Fearow,
    Ekans,
    Arbok,
    Pikachu,
    Raichu,
    Sandshrew,
    Sandslash,
    Nidorana,
    Nidorina,
    Nidoqueen,
    Nidorano,
    Nidorino,
    Nidoking,
    Clefairy,
    Clefable,
    Vulpix,
    Ninetales,
    Jigglypuff,
    Wigglytuff,
    Zubat,
    Golbat,
    Oddish,
    Gloom,
    Vileplume,
    Paras,
    Parasect,
    Venonat,
    Venomoth,
    Diglett,
    Dugtrio,
    Meowth,
    Persian,
    Psyduck,
    Golduck,
    Mankey,
    Primeape,
    Growlithe,
    Arcanine,
    Poliwag,
    Poliwhirl,
    Poliwrath,
    Abra,
    Kadabra,
    Alakazam,
    Machop,
    Machoke,
    Machamp,
    Bellsprout,
    Weepinbell,
    Victreebel,
    Tentacool,
    Tentacruel,
    Geodude,
    Graveler,
    Golem,
    Ponyta,
    Rapidash,
    Slowpoke,
    Slowbro,
    Magnemite,
    Magneton,
    Farfetchd,
    Doduo,
    Dodrio,
    Seel,
    Dewgong,
    Grimer,
    Muk,
    Shellder,
    Cloyster,
    Gastly,
    Haunter,
    Gengar,
    Onix,
    Drowzee,
    Hypno,
    Krabby,
    Kingler,
    Voltorb,
    Electrode,
    Exeggcute,
    Exeggutor,
    Cubone,
    Marowak,
    Hitmonlee,
    Hitmonchan,
    Lickitung,
    Koffing,
    Weezing,
    Rhyhorn,
    Rhydon,
    Chansey,
    Tangela,
    Kangaskhan,
    Horsea,
    Seadra,
    Goldeen,
    Seaking,
    Staryu,
    Starmie,
    MrMime,
    Scyther,
    Jynx,
    Electabuzz,
    Magmar,
    Pinsir,
    Tauros,
    Magikarp,
    Gyarados,
    Lapras,
    Ditto,
    Eevee,
    Vaporeon,
    Jolteon,
    Flareon,
    Porygon,
    Omanyte,
    Omastar,
    Kabuto,
    Kabutops,
    Aerodactyl,
    Snorlax,
    Articuno,
    Zapdos,
    Moltres,
    Dratini,
    Dragonair,
    Dragonite,
    Mewtwo,
    Mew
};

enum class AbilityId
{
    undefined = 0,
    Absorb = 71,
    Acid = 51,
    AcidArmor = 151,
    Agility = 97,
    Amnesia = 133,
    AuroraBeam = 62,
    Barrage = 140,
    Barrier = 112,
    Bide = 117,
    Bind = 20,
    Bite = 44,
    Blizzard = 59,
    BodySlam = 34,
    BoneClub = 125,
    Bonemerang = 155,
    Bubble = 145,
    BubbleBeam = 61,
    Clamp = 128,
    CometPunch = 4,
    ConfuseRay = 109,
    Confusion = 93,
    Constrict = 132,
    Conversion = 160,
    Counter = 68,
    Crabhammer = 152,
    Cut = 15,
    DefenseCurl = 111,
    Dig = 91,
    Disable = 50,
    DizzyPunch = 146,
    DoubleKick = 24,
    DoubleSlap = 3,
    DoubleTeam = 104,
    DoubleEdge = 38,
    DragonRage = 82,
    DreamEater = 138,
    DrillPeck = 65,
    Earthquake = 89,
    EggBomb = 121,
    Ember = 52,
    Explosion = 153,
    FireBlast = 126,
    FirePunch = 7,
    FireSpin = 83,
    Fissure = 90,
    Flamethrower = 53,
    Flash = 148,
    Fly = 19,
    FocusEnergy = 116,
    FuryAttack = 31,
    FurySwipes = 154,
    Glare = 137,
    Growl = 45,
    Growth = 74,
    Guillotine = 12,
    Gust = 16,
    Harden = 106,
    Haze = 114,
    Headbutt = 29,
    HighJumpKick = 136,
    HornAttack = 30,
    HornDrill = 32,
    HydroPump = 56,
    HyperBeam = 63,
    HyperFang = 158,
    Hypnosis = 95,
    IceBeam = 58,
    IcePunch = 8,
    JumpKick = 26,
    KarateChop = 2,
    Kinesis = 134,
    LeechLife = 141,
    LeechSeed = 73,
    Leer = 43,
    Lick = 122,
    LightScreen = 113,
    LovelyKiss = 142,
    LowKick = 67,
    Meditate = 96,
    MegaDrain = 72,
    MegaKick = 25,
    MegaPunch = 5,
    Metronome = 118,
    Mimic = 102,
    Minimize = 107,
    MirrorMove = 119,
    Mist = 54,
    NightShade = 101,
    PayDay = 6,
    Peck = 64,
    PetalDance = 80,
    PinMissile = 42,
    PoisonGas = 139,
    PoisonPowder = 77,
    PoisonSting = 40,
    Pound = 1,
    Psybeam = 60,
    Psychic = 94,
    Psywave = 149,
    QuickAttack = 98,
    Rage = 99,
    RazorLeaf = 75,
    RazorWind = 13,
    Recover = 105,
    Reflect = 115,
    Rest = 156,
    Roar = 46,
    RockSlide = 157,
    RockThrow = 88,
    RollingKick = 27,
    SandAttack = 28,
    Scratch = 10,
    Screech = 103,
    SeismicToss = 69,
    SelfDestruct = 120,
    Sharpen = 159,
    Sing = 47,
    SkullBash = 130,
    SkyAttack = 143,
    Slam = 21,
    Slash = 163,
    SleepPowder = 79,
    Sludge = 124,
    Smog = 123,
    Smokescreen = 108,
    SoftBoiled = 135,
    SolarBeam = 76,
    SonicBoom = 49,
    SpikeCannon = 131,
    Splash = 150,
    Spore = 147,
    Stomp = 23,
    Strength = 70,
    StringShot = 81,
    Struggle = 165,
    StunSpore = 78,
    Submission = 66,
    Substitute = 164,
    SuperFang = 162,
    Supersonic = 48,
    Surf = 57,
    Swift = 129,
    SwordsDance = 14,
    Tackle = 33,
    TailWhip = 39,
    TakeDown = 36,
    Teleport = 100,
    Thrash = 37,
    Thunder = 87,
    ThunderPunch = 9,
    ThunderShock = 84,
    ThunderWave = 86,
    Thunderbolt = 85,
    Toxic = 92,
    Transform = 144,
    TriAttack = 161,
    Twineedle = 41,
    ViceGrip = 11,
    VineWhip = 22,
    WaterGun = 55,
    Waterfall = 127,
    Whirlwind = 18,
    WingAttack = 17,
    Withdraw = 110,
    Wrap = 35
};



#endif
