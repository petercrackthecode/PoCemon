#include <iostream>
#include "PoCemon.h"
#include "PoCemonData.h"
#include "AttackAbility.h"
#include "Enums.h"

using namespace std;

		void kate() {

			AttackAbility attack(2, "Kate", "Hi there", Type::Normal, AbilityCategory::Physical, 3, 4, 5, 0);
			Pocemon Kate(PkmnId::Abra, 1);
			Pocemon Person(PkmnId::Abra, 1);
			Kate.doDamage(attack, Person);
			
            cin.get();
			
			}

