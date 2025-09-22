#include "Ability.h"
#include "Character.h"

Ability::Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description){
    this->abilityName = abilityName;
    this->type = type;
    this->damage = damage;
    this->hitChance = hitChance;
    this->description = description;
}
Ability::~Ability() = default;

std::string& Ability::name() const { return n; }
Attribute Ability::type() const { return type; }
int Ability::power() const { return power_; }
double Ability::hitChance() const { return hitChance_; }
const std::string& Ability::description() const { return desc_; }