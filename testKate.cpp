#include <iostream>
#include <PoCemon.h>
#include <Combat.h>
#include <Enums.h>
#include <PoCemonData.h>
using namespace std;

	// I guess the bot is better
	// We don't have to repeat what we say

	void kate()
	{
		/////////////////////////////////////////////////////////
		//getters and for stats of the Pokemon in PoCemon.h /////
		/////////////////////////////////////////////////////////
		void Pocemon::getHp() {
			return hp;
		}
		void Pocemon::getAtk() {
			return atk;
		}
		void Pocemon::getDef() {
			return def;
		}
		void Pocemon::getSpeed() {
			return speed;
		}
		void Pocemon::getSpAtk() {
			return spAtk;
		}
		void Pocemon::getSpDef() {
			return spDef;
		}
		/* int Pocemon::setHp(int hpTEMP) {
			hp = hpTEMP;
		}
		int Pocemon::setAtk(int atkTEMP) {
			atk = atkTEMP;
		}
		int Pocemon::setDef(int defTEMP) {
			def = defTEMP;
		}
		int Pocemon::setSpeed(int speedTEMP) {
			speed = speedTEMP;
		}
		int Pocemon::setSpAtk(int spAtkTEMP) {
			spAtk = spAtkTEMP;
		}
		int Pocemon::setSpDef(int spDefTEMP) {
			spDef = spDefTEMP;
		}
		*/
		/////////////////////////////////////////////////////////
		//getters for current stats of the Pokemon in PoCemon.h//
		/////////////////////////////////////////////////////////
		void Pocemon::getCURHp() {
			return hp;
		}
		void Pocemon::getCURAtk() {
			return atk;
		}
		void Pocemon::getCURDef() {
			return def;
		}
		void Pocemon::getCURSpeed() {
			return speed;
		}
		void Pocemon::getCURSpAtk() {
			return spAtk;
		}
		void Pocemon::getCURSpDef() {
			return spDef;
		}

		/////////////////////////////////////////////////////////
		////////getters for description of Pocemon in PoCemon.h//
		/////////////////////////////////////////////////////////
		PkmnId Pocemon::getId() {
			return id;
		}
		int Pocemon::getLevel() {
			return level;
		}
		std::string Pocemon::getName() {
			return name;
		}
		Type Pocemon::getType1() {
			return type1;
		}
		Type Pocemon::getType2() {
			return type2;
		}


		/////////////////////////////////////////////////////////
		/////////////////damage function/////////////////////////
		/////////////////////////////////////////////////////////

		void PoCemon::doDamage(const Type &typeATK, const int &power, Pocemon *pocemon1, Pocemon *pocemon2) {
			// You're welcome
			// I feel like a bot.
			// The next AI? artificial intelligence. Like siri or Google Now.
			// Peter will be the next one.
			// No Siri can't help you code, can it?
			// 'cause I'm not a bot.
			// actually, I don't like to be a bot, maybe we can use phone? Is it ok?
			// will call you.

			//calculating damage for pocemon1
			modifier = Combat::getDmgMultiplier(typeATK, (pocemon->Pocemon::getType1()), (pocemon->Pocemon::getType2()));
			int damage = ((((2 + (2 * (pocemon->Pocemon::getCURLevel()) / 5))* power * ((pocemon->Pocemon::getCURAtk()) / pocemon->Pocemon::getCURDef())) / 50) + 2)*modifier;
			//doing damage to pocemon1
			/*first - figure out what type of the attack it is, them do damage to a specefic zone */
			/*
			PHYSICAL (for the attack and defense)
	 Normal
	 Fighting
	 Flying
	 Ground
	 Rock
	 Bug
	 Ghost
	 Poison
	 Steel
			SPECIAL (for special attack and defence)
	 Water
	 Grass
	 Fire
	 Ice
	 Electric
	 Psychic
	 Dragon
	 Dark

			 HP drain, the moves that do not exist on the attack list.
	Absorb
	Bouncy Bubble
	Drain Punch
	Draining Kiss
	Dream Eater
	Giga Drain
	Horn Leech
	Leech Life
	Leech Seed
	Mega Drain
	Oblivion Wing
	Parabolic Charge
			*/



		}

