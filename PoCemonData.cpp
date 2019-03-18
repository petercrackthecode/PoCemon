#include "PoCemonData.h"
#include "PoCemon.h"
#include "Enums.h"

PocemonData::PocemonData(std::string tempName,
                         Type tempType1,
                         Type tempType2,
                         int tempBaseHp,
                         int tempBaseAtk,
                         int tempBaseDef,
                         int tempBaseSpeed,
                         int tempBaseSpAtk,
                         int tempBaseSpDef)
{
    name = tempName;
    type1 = tempType1;
    type2 = tempType2;

    baseHp = tempBaseHp;
    baseAtk = tempBaseAtk;
    baseDef = tempBaseDef;
    baseSpeed = tempBaseSpeed;
    baseSpAtk = tempBaseSpAtk;
    baseSpDef = tempBaseSpDef;
}

PocemonData::PocemonData()
{
    name = "";
    type1 = Type::undefined;
    type2 = Type::undefined;

    baseHp = 0;
    baseAtk = 0;
    baseDef = 0;
    baseSpeed = 0;
    baseSpAtk = 0;
    baseSpDef = 0;
}

std::string PocemonData::getTypeName(Type type)
{
    switch (type)
    {
    case Type::undefined:
        return "-";
    case Type::Normal:
        return "Normal";
    case Type::Fighting:
        return "Fighting";
    case Type::Flying:
        return "Flying";
    case Type::Poison:
        return "Poison";
    case Type::Ground:
        return "Ground";
    case Type::Rock:
        return "Rock";
    case Type::Bug:
        return "Bug";
    case Type::Ghost:
        return "Ghost";
    case Type::Steel:
        return "Steel";
    case Type::Fire:
        return "Fire";
    case Type::Water:
        return "Water";
    case Type::Grass:
        return "Grass";
    case Type::Electric:
        return "Electric";
    case Type::Psychic:
        return "Psychic";
    case Type::Ice:
        return "Ice";
    case Type::Dragon:
        return "Dragon";
    case Type::Dark:
        return "Dark";
    case Type::Fairy:
        return "Fairy";
    default:
        return "UNDEFINED";
    }
}

const PocemonData *PocemonData::allData = PocemonData::defineAllPocemonData();

PocemonData* PocemonData::defineAllPocemonData()
{
    PocemonData* data = new PocemonData[152]{
    	Pocemon("MissingNo.", Type::undefined, Type::undefined, 1, 1, 1, 1, 1, 1),
        Pocemon("Bulbasaur", Type::Grass, Type::Poison, 45, 49, 49, 45, 65, 65),
        Pocemon("Ivysaur", Type::Grass, Type::Poison, 60, 62, 63, 60, 80, 80),
		Pocemon("Venusaur", Type::Grass, Type::Poison, 80, 82, 83, 80, 100, 100),
		Pocemon("Charmander", Type::Fire, Type::undefined, 39, 52, 43, 65, 50, 50),
		Pocemon("Charmeleon", Type::Fire, Type::undefined, 58, 64, 58, 80, 65, 65),
		Pocemon("Charizard", Type::Fire, Type::Flying, 78, 84, 78, 100, 85, 85),
		Pocemon("Squirtle", Type::Water, Type::undefined, 44, 48, 65, 43, 50, 64),
		Pocemon("Wartortle", Type::Water, Type::undefined, 59, 63, 80, 58, 65, 80),
		Pocemon("Blastoise", Type::Water, Type::undefined, 79, 83, 100, 78, 85, 105),
		Pocemon("Caterpie", Type::Bug, Type::undefined, 45, 30, 35, 45, 20, 20),
		Pocemon("Metapod", Type::Bug, Type::undefined, 50, 20, 55, 30, 25, 25),
		Pocemon("Butterfree", Type::Bug, Type::Flying, 60, 45, 50, 70, 80, 80),
		Pocemon("Weedle", Type::Bug, Type::Poison, 40, 35, 30, 50, 20, 20),
		Pocemon("Kakuna", Type::Bug, Type::Poison, 45, 25, 50, 35, 25, 25),
		Pocemon("Beedrill", Type::Bug, Type::Poison, 65, 80, 40, 75, 45, 80),
		Pocemon("Pidgey", Type::Normal, Type::Flying, 40, 45, 40, 56, 35, 35),
		Pocemon("Pidgeotto", Type::Normal, Type::Flying, 63, 60, 55, 71, 50, 50),
		Pocemon("Pidgeot", Type::Normal, Type::Flying, 83, 80, 75, 91, 70, 70),
		Pocemon("Rattata", Type::Normal, Type::undefined, 30, 56, 35, 72, 25, 35),
		Pocemon("Raticate", Type::Normal, Type::undefined, 55, 81, 60, 97, 50, 70),
		Pocemon("Spearow", Type::Normal, Type::Flying, 40, 60, 30, 70, 31, 31),
        Pocemon("Fearow", Type::Normal, Type::Flying, 65, 90, 65, 100, 61, 61),
		Pocemon("Ekans", Type::Poison, Type::undefined, 35, 60, 44, 55, 40, 54),
		Pocemon("Arbok", Type::Poison, Type::undefined, 60, 85, 69, 80, 65, 79),
		Pocemon("Pikachu", Type::Electric, Type::undefined, 35, 55, 30, 90, 50, 40),
		Pocemon("Raichu", Type::Electric, Type::undefined, 60, 90, 55, 100, 90, 80),
		        Pocemon("Sandshrew", Type::Ground, Type::undefined, 50, 75, 85, 40, 30, 30),
		        Pocemon("Sandslash", Type::Ground, Type::undefined, 75, 100, 110, 65, 55, 55),
		        Pocemon("Nidoran (f)", Type::Poison, Type::undefined, 55, 47, 52, 41, 40, 40),
		        Pocemon("Nidorina", Type::Poison, Type::undefined, 70, 62, 67, 56, 55, 55),
		        Pocemon("Nidoqueen", Type::Poison, Type::Ground, 90, 82, 87, 76, 75, 85),
		        Pocemon("Nidoran (m)", Type::Poison, Type::undefined, 46, 57, 40, 50, 40, 40),
		        Pocemon("Nidorino", Type::Poison, Type::undefined, 61, 72, 57, 65, 55, 55),
		        Pocemon("Nidoking", Type::Poison, Type::Ground, 81, 92, 77, 85, 75, 75),
		        Pocemon("Clefairy", Type::Fairy, Type::undefined, 70, 45, 48, 35, 60, 65),
		        Pocemon("Clefable", Type::Fairy, Type::undefined, 95, 70, 73, 60, 85, 90),
		        Pocemon("Vulpix", Type::Fire, Type::undefined, 38, 41, 40, 65, 65, 65),
		        Pocemon("Ninetales", Type::Fire, Type::undefined, 73, 76, 75, 100, 100, 100),
		        Pocemon("Jigglypuff", Type::Normal, Type::Fairy, 115, 45, 20, 20, 25, 25),
		        Pocemon("Wigglytuff", Type::Normal, Type::Fairy, 140, 70, 45, 45, 50, 50),
		        Pocemon("Zubat", Type::Poison, Type::Flying, 40, 45, 35, 55, 40, 40),
		        Pocemon("Golbat", Type::Poison, Type::Flying, 75, 80, 70, 90, 75, 75),
		        Pocemon("Oddish", Type::Grass, Type::Poison, 45, 50, 55, 30, 75, 65),
		        Pocemon("Gloom", Type::Grass, Type::Poison, 60, 65, 70, 40, 85, 75),
		        Pocemon("Vileplume", Type::Grass, Type::Poison, 75, 80, 85, 50, 100, 90),
		        Pocemon("Paras", Type::Bug, Type::Grass, 35, 70, 55, 25, 55, 55),
		        Pocemon("Parasect", Type::Bug, Type::Grass, 60, 95, 80, 30, 80, 80),
		        Pocemon("Venonat", Type::Bug, Type::Poison, 60, 55, 50, 45, 40, 55),
		        Pocemon("Venomoth", Type::Bug, Type::Poison, 70, 65, 60, 90, 90, 75),
		        Pocemon("Diglett", Type::Ground, Type::undefined, 10, 55, 25, 95, 45, 45),
		        Pocemon("Dugtrio", Type::Ground, Type::undefined, 35, 80, 50, 120, 70, 70),
		        Pocemon("Meowth", Type::Normal, Type::undefined, 40, 45, 35, 90, 40, 40),
		        Pocemon("Persian", Type::Normal, Type::undefined, 65, 70, 60, 115, 65, 65),
		        Pocemon("Psyduck", Type::Water, Type::undefined, 50, 52, 48, 55, 50, 50),
		        Pocemon("Golduck", Type::Water, Type::undefined, 80, 82, 78, 85, 80, 80),
		        Pocemon("Mankey", Type::Fighting, Type::undefined, 40, 80, 35, 70, 35, 45),
		        Pocemon("Primeape", Type::Fighting, Type::undefined, 65, 105, 60, 95, 60, 70),
		        Pocemon("Growlithe", Type::Fire, Type::undefined, 55, 70, 45, 60, 50, 50),
		        Pocemon("Arcanine", Type::Fire, Type::undefined, 90, 110, 80, 95, 80, 80),
		        Pocemon("Poliwag", Type::Water, Type::undefined, 40, 50, 40, 90, 40, 40),
		        Pocemon("Poliwhirl", Type::Water, Type::undefined, 65, 65, 65, 90, 50, 50),
		        Pocemon("Poliwrath", Type::Water, Type::Fighting, 90, 85, 95, 70, 70, 90),
		        Pocemon("Abra", Type::Psychic, Type::undefined, 25, 20, 15, 90, 105, 55),
		        Pocemon("Kadabra", Type::Psychic, Type::undefined, 40, 35, 30, 105, 120, 70),
		        Pocemon("Alakazam", Type::Psychic, Type::undefined, 55, 50, 45, 120, 135, 85),
		        Pocemon("Machop", Type::Fighting, Type::undefined, 70, 80, 50, 35, 35, 35),
		        Pocemon("Machoke", Type::Fighting, Type::undefined, 80, 100, 70, 45, 50, 60),
		        Pocemon("Machamp", Type::Fighting, Type::undefined, 90, 130, 80, 55, 65, 85),
		        Pocemon("Bellsprout", Type::Grass, Type::Poison, 50, 75, 35, 40, 70, 30),
		        Pocemon("Weepinbell", Type::Grass, Type::Poison, 65, 90, 50, 55, 85, 45),
		        Pocemon("Victreebel", Type::Grass, Type::Poison, 80, 105, 65, 70, 100, 60),
		        Pocemon("Tentacool", Type::Water, Type::Poison, 40, 40, 35, 70, 100, 100),
		        Pocemon("Tentacruel", Type::Water, Type::Poison, 80, 70, 65, 100, 120, 120),
		        Pocemon("Geodude", Type::Rock, Type::Ground, 40, 80, 100, 20, 30, 30),
		        Pocemon("Graveler", Type::Rock, Type::Ground, 55, 95, 115, 35, 45, 45),
		        Pocemon("Golem", Type::Rock, Type::Ground, 80, 110, 130, 45, 55, 65),
		        Pocemon("Ponyta", Type::Fire, Type::undefined, 50, 85, 55, 90, 65, 65),
		        Pocemon("Rapidash", Type::Fire, Type::undefined, 65, 100, 70, 105, 80, 80),
		        Pocemon("Slowpoke", Type::Water, Type::Psychic, 90, 65, 65, 15, 40, 40),
		        Pocemon("Slowbro", Type::Water, Type::Psychic, 95, 75, 110, 30, 80, 80),
		        Pocemon("Magnemite", Type::Electric, Type::Steel, 25, 35, 70, 45, 95, 55),
		        Pocemon("Magneton", Type::Electric, Type::Steel, 50, 60, 95, 70, 120, 70),
		        Pocemon("Farfetch'd", Type::Normal, Type::Flying, 52, 65, 55, 60, 58, 62),
		        Pocemon("Doduo", Type::Normal, Type::Flying, 35, 85, 45, 75, 35, 35),
		        Pocemon("Dodrio", Type::Normal, Type::Flying, 60, 110, 70, 100, 60, 60),
		        Pocemon("Seel", Type::Water, Type::undefined, 65, 45, 55, 45, 70, 70),
		        Pocemon("Dewgong", Type::Water, Type::Ice, 90, 70, 80, 70, 95, 95),
		        Pocemon("Grimer", Type::Poison, Type::undefined, 80, 80, 50, 25, 40, 50),
		        Pocemon("Muk", Type::Poison, Type::undefined, 105, 105, 75, 50, 65, 100),
		        Pocemon("Shellder", Type::Water, Type::undefined, 30, 65, 100, 40, 45, 25),
		        Pocemon("Cloyster", Type::Water, Type::Ice, 50, 95, 180, 70, 85, 45),
		        Pocemon("Gastly", Type::Ghost, Type::Poison, 30, 35, 30, 80, 100, 35),
		        Pocemon("Haunter", Type::Ghost, Type::Poison, 45, 50, 45, 95, 115, 55),
		        Pocemon("Gengar", Type::Ghost, Type::Poison, 60, 65, 60, 110, 130, 75),
		        Pocemon("Onix", Type::Rock, Type::Ground, 35, 45, 160, 70, 30, 45),
		        Pocemon("Drowzee", Type::Psychic, Type::undefined, 60, 48, 45, 42, 90, 90),
		        Pocemon("Hypno", Type::Psychic, Type::undefined, 85, 73, 70, 67, 115, 115),
		        Pocemon("Krabby", Type::Water, Type::undefined, 30, 105, 90, 50, 25, 25),
		        Pocemon("Kingler", Type::Water, Type::undefined, 55, 130, 115, 75, 50, 50),
		        Pocemon("Voltorb", Type::Electric, Type::undefined, 40, 30, 50, 100, 55, 55),
		        Pocemon("Electrode", Type::Electric, Type::undefined, 60, 50, 70, 140, 80, 80),
		        Pocemon("Exeggcute", Type::Grass, Type::Psychic, 60, 40, 80, 40, 60, 45),
		        Pocemon("Exeggutor", Type::Grass, Type::Psychic, 95, 95, 85, 55, 125, 65),
		        Pocemon("Cubone", Type::Ground, Type::undefined, 50, 50, 95, 35, 40, 50),
		        Pocemon("Marowak", Type::Ground, Type::undefined, 60, 80, 110, 45, 50, 80),
		        Pocemon("Hitmonlee", Type::Fighting, Type::undefined, 50, 120, 53, 87, 35, 110),
		        Pocemon("Hitmonchan", Type::Fighting, Type::undefined, 50, 105, 79, 76, 35, 110),
		        Pocemon("Lickitung", Type::Normal, Type::undefined, 90, 55, 75, 30, 60, 75),
		        Pocemon("Koffing", Type::Poison, Type::undefined, 40, 65, 95, 35, 60, 45),
		        Pocemon("Weezing", Type::Poison, Type::undefined, 65, 90, 120, 60, 85, 70),
		        Pocemon("Rhyhorn", Type::Ground, Type::Rock, 80, 85, 95, 25, 30, 30),
		        Pocemon("Rhydon", Type::Ground, Type::Rock, 105, 130, 120, 40, 45, 45),
		        Pocemon("Chansey", Type::Normal, Type::undefined, 250, 5, 5, 50, 105, 105),
		        Pocemon("Tangela", Type::Grass, Type::undefined, 65, 55, 115, 60, 100, 40),
		        Pocemon("Kangaskhan", Type::Normal, Type::undefined, 105, 95, 80, 90, 40, 80),
		        Pocemon("Horsea", Type::Water, Type::undefined, 30, 40, 70, 60, 70, 25),
		        Pocemon("Seadra", Type::Water, Type::undefined, 55, 65, 95, 85, 95, 45),
		        Pocemon("Goldeen", Type::Water, Type::undefined, 45, 67, 60, 63, 50, 50),
		        Pocemon("Seaking", Type::Water, Type::undefined, 80, 92, 65, 68, 80, 80),
		        Pocemon("Staryu", Type::Water, Type::undefined, 30, 45, 55, 85, 70, 55),
		        Pocemon("Starmie", Type::Water, Type::Psychic, 60, 75, 85, 115, 100, 85),
		        Pocemon("Mr. Mime", Type::Psychic, Type::Fairy, 40, 45, 65, 90, 100, 120),
		        Pocemon("Scyther", Type::Bug, Type::Flying, 70, 110, 80, 105, 55, 80),
		        Pocemon("Jynx", Type::Ice, Type::Psychic, 65, 50, 35, 95, 95, 95),
		        Pocemon("Electabuzz", Type::Electric, Type::undefined, 65, 83, 57, 105, 85, 85),
		        Pocemon("Magmar", Type::Fire, Type::undefined, 65, 95, 57, 93, 85, 85),
		        Pocemon("Pinsir", Type::Bug, Type::undefined, 65, 125, 100, 85, 55, 70),
		        Pocemon("Tauros", Type::Normal, Type::undefined, 75, 100, 95, 110, 70, 70),
		        Pocemon("Magikarp", Type::Water, Type::undefined, 20, 10, 55, 80, 20, 20),
		        Pocemon("Gyarados", Type::Water, Type::Flying, 95, 125, 79, 81, 100, 100),
		        Pocemon("Lapras", Type::Water, Type::Ice, 130, 85, 80, 60, 95, 95),
		        Pocemon("Ditto", Type::Normal, Type::undefined, 48, 48, 48, 48, 48, 48),
		        Pocemon("Eevee", Type::Normal, Type::undefined, 55, 55, 50, 55, 65, 65),
		        Pocemon("Vaporeon", Type::Water, Type::undefined, 130, 65, 60, 65, 110, 95),
		        Pocemon("Jolteon", Type::Electric, Type::undefined, 65, 65, 60, 130, 110, 95),
		        Pocemon("Flareon", Type::Fire, Type::undefined, 65, 130, 60, 65, 110, 110),
		        Pocemon("Porygon", Type::Normal, Type::undefined, 65, 60, 70, 40, 75, 75),
		        Pocemon("Omanyte", Type::Rock, Type::Water, 35, 40, 100, 35, 90, 55),
		        Pocemon("Omastar", Type::Rock, Type::Water, 70, 60, 125, 55, 115, 70),
		        Pocemon("Kabuto", Type::Rock, Type::Water, 30, 80, 90, 55, 45, 45),
		        Pocemon("Kabutops", Type::Rock, Type::Water, 60, 115, 105, 80, 70, 70),
		        Pocemon("Aerodactyl", Type::Rock, Type::Flying, 80, 105, 65, 130, 60, 75),
		        Pocemon("Snorlax", Type::Normal, Type::undefined, 160, 110, 65, 30, 65, 110),
		        Pocemon("Articuno", Type::Ice, Type::Flying, 90, 85, 100, 85, 125, 125),
		        Pocemon("Zapdos", Type::Electric, Type::Flying, 90, 90, 85, 100, 125, 90),
		        Pocemon("Moltres", Type::Fire, Type::Flying, 90, 100, 90, 90, 125, 85),
		        Pocemon("Dratini", Type::Dragon, Type::undefined, 41, 64, 45, 50, 50, 50),
		        Pocemon("Dragonair", Type::Dragon, Type::undefined, 61, 84, 65, 70, 70, 70),
		        Pocemon("Dragonite", Type::Dragon, Type::Flying, 91, 134, 95, 80, 100, 100),
		        Pocemon("Mewtwo", Type::Psychic, Type::undefined, 106, 110, 90, 130, 154, 90),
				Pocemon("Mew", Type::Psychic, Type::undefined, 100, 100, 100, 100, 100, 100),
    };

    return data;
}
