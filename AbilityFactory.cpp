#include <map>
#include "AbilityFactory.h"
#include "Ability.h"
#include "AttackAbility.h"
#include "Enums.h"

std::map<AbilityId, Ability*> AbilityFactory::allAbilities;

void AbilityFactory::init()
{
    if (allAbilities.size() > 0)
        throw "Ability Factory has already been initialized."; // TODO: Exception class.


    // Pure Damage Abilities
    allAbilities.emplace(AbilityId::Cut, new AttackAbility(AbilityId::Cut, "Cut", "", Type::Normal, AbilityCategory::Physical, 50, 242, 30, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::DrillPeck, new AttackAbility(AbilityId::DrillPeck, "Drill Peck", "", Type::Flying, AbilityCategory::Physical, 80, 255, 20, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::EggBomb, new AttackAbility(AbilityId::EggBomb, "Egg Bomb", "", Type::Normal, AbilityCategory::Physical, 100, 191, 10, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::HornAttack, new AttackAbility(AbilityId::HornAttack, "Horn Attack", "", Type::Normal, AbilityCategory::Physical, 65, 255, 25, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::HydroPump, new AttackAbility(AbilityId::HydroPump, "Hydro Pump", "", Type::Water, AbilityCategory::Special, 110, 204, 5, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::MegaKick, new AttackAbility(AbilityId::MegaKick, "Mega Kick", "", Type::Normal, AbilityCategory::Physical, 120, 191, 5, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::MegaPunch, new AttackAbility(AbilityId::MegaPunch, "Mega Punch", "", Type::Normal, AbilityCategory::Physical, 80, 216, 20, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::PayDay, new AttackAbility(AbilityId::PayDay, "Pay Day", "A small amount of money is gained after the battle resolves.", Type::Normal, AbilityCategory::Physical, 40, 255, 20, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Peck, new AttackAbility(AbilityId::Peck, "Peck", "", Type::Flying, AbilityCategory::Physical, 35, 255, 35, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Pound, new AttackAbility(AbilityId::Pound, "Pound", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::RockThrow, new AttackAbility(AbilityId::RockThrow, "Rock Throw", "", Type::Rock, AbilityCategory::Physical, 50, 64.7, 15, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Scratch, new AttackAbility(AbilityId::Scratch, "Scratch", "", Type::Normal, AbilityCategory::Physical, 40, 255, 35, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Slam, new AttackAbility(AbilityId::Slam, "Slam", "", Type::Normal, AbilityCategory::Physical, 80, 191, 20, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Strength, new AttackAbility(AbilityId::Strength, "Strength", "", Type::Normal, AbilityCategory::Physical, 80, 255, 15, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Surf, new AttackAbility(AbilityId::Surf, "Surf", "Hits all adjacent Pokemon.", Type::Water, AbilityCategory::Special, 90, 255, 15, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::Tackle, new AttackAbility(AbilityId::Tackle, "Tackle", "", Type::Normal, AbilityCategory::Physical, 40, 242, 35, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::ViceGrip, new AttackAbility(AbilityId::ViceGrip, "Vice Grip", "", Type::Normal, AbilityCategory::Physical, 55, 255, 30, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::VineWhip, new AttackAbility(AbilityId::VineWhip, "Vine Whip", "", Type::Grass, AbilityCategory::Physical, 45, 255, 25, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::WaterGun, new AttackAbility(AbilityId::WaterGun, "Water Gun", "", Type::Water, AbilityCategory::Special, 40, 255, 25, 0, StatusEffect::None));
    allAbilities.emplace(AbilityId::WingAttack, new AttackAbility(AbilityId::WingAttack, "Wing Attack", "", Type::Flying, AbilityCategory::Physical, 60, 255, 35, 0, StatusEffect::None));

    return;
}

Ability* AbilityFactory::getAbility(const AbilityId &abilityId)
{
    if (allAbilities.count(abilityId) != 1)
        throw "Ability doesn't exist."; // TODO: Exception class.

    return allAbilities[abilityId];
}