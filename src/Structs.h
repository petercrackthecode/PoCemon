#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <queue>
#include "Ability.h"
#include "Enums.h"
#include "Player.h"
#include "randomGenerator.h"

struct AbilityOutcome
{
    Ability *ability;
    bool hit; // false = ability missed.
    bool criticalHit; // true = critical hit.

    int damageDealt;
    int hpHealed;

    bool statusEffectTriggered;
    
    
    std::queue<std::string> messages;
};


struct BattleEvent
{
    BEvtType type;
    Pocemon *source;
    Pocemon *target;
    Ability *abilitySource;
    Player *playerSource;
    StatusEffect effectSource;
    bool isSucess;
    int amount;

    BattleEvent() : type{ BEvtType::Undefined }, source{ nullptr }, target{ nullptr }, abilitySource{ nullptr }, playerSource{ nullptr }, effectSource{ StatusEffect::None }, isSucess{ true }, amount{ 0 }
    {}
    
    BattleEvent(const BEvtType &tempType, Pocemon *sourceTemp, Pocemon *tempTarget, Ability *tempAbilitySource, bool tempIsSuccess = false, int tempAmount = 0) : type{ tempType }, source{ sourceTemp }, target{ tempTarget }, abilitySource{ tempAbilitySource }, playerSource{ nullptr }, effectSource{ StatusEffect::None }, isSucess{ tempIsSuccess }, amount{ tempAmount }
    {}

    BattleEvent(const BEvtType &tempType, Pocemon *sourceTemp, Player &tempPlayerSource) : type{ tempType }, source{ sourceTemp }, target{ nullptr }, abilitySource{ nullptr }, playerSource{ &tempPlayerSource }, effectSource{ StatusEffect::None }, isSucess{ true }, amount{ 0 }
    {}

    std::string toString() const
    {
        std::string msg;

        switch (type) {
        case (BEvtType::PocemonDeployed):
            if (randomGenerator(0, 1))
                msg = this->playerSource->getName() + " sent out " + this->source->getName() + "!";
            else
                msg = "Go! " + this->source->getName() + "!";
            break;
        case (BEvtType::PocemonWithdrawn):
            if (randomGenerator(0, 1))
                msg = this->playerSource->getName() + " withdrew " + this->source->getName() + "!";
            else
                msg = this->source->getName() + "! Come back!";
            break;
        case (BEvtType::AbilityUsed):
            msg = this->source->getName() + " used " + this->abilitySource->getName() + "!";
            break;
        case (BEvtType::AbilityMissed):
            msg = this->source->getName() + " missed!";
            break;
        case (BEvtType::AbilityDamageDealt):
            msg = this->source->getName() + " dealt " + std::to_string(amount) + " damage to " + this->target->getName() + "!";
            break;
        case (BEvtType::AbilityHpHealed):
            break;
        case (BEvtType::CriticalHit):
            msg = "Critical hit!";
            break;
        case (BEvtType::Effective):
            if (isSucess)
                msg = "It's super effective!";
            else
                msg = "It's not very effective...";
            break;
        case (BEvtType::StatusEffectApplied):
            msg = this->source->getName();
            switch (effectSource) {
            case (StatusEffect::Rest):
                msg += " fell asleep and became healthy!";
                break;
            case (StatusEffect::Paralyze):
                msg += " is paralyzed! It may not attack!";
                break;
            case (StatusEffect::Poison):
                msg += " is poisoned!";
                break;
            case (StatusEffect::PoisonBadly):
                msg += " is badly poisoned!";
                break;
            default:
                msg = "undefined"; // TODO: Class exception.
                break;
            }
            break;
        case (BEvtType::StatusEffectRemoved):
            break;
        case (BEvtType::StatusEffectDamageDealt):
            msg = this->source->getName();
            switch (effectSource) {
            case (StatusEffect::Burn):
                msg += " is hurt by the burn! (" + std::to_string(amount) + ")";
                break;
            case (StatusEffect::Confuse):
                msg += " hurt itself in confusion! (" + std::to_string(amount) + ")";
                break;
            case (StatusEffect::Poison):
                msg += " is hurt by poison! (" + std::to_string(amount) + ")";
                break;
            case (StatusEffect::PoisonBadly):
                msg += " is hurt badly by poison! (" + std::to_string(amount) + ")";
                break;
            default:
                msg = "undefined"; // TODO: Class exception.
                break;
            }
            break;
        case (BEvtType::StatusEffectHpHealed):
            msg = this->source->getName() + " regained " + std::to_string(amount) + " health!";
            break;
        case (BEvtType::PocemonFainted):
            msg = this->target->getName() + " fainted!";
            break;
        case (BEvtType::PlayerDefeated):
            msg = this->playerSource->getName() + " has been defeated!";
            break;
        default:
            throw "Invalid case"; // TODO: Class exception.
            break;
        }

        return msg;
    }
};


#endif
