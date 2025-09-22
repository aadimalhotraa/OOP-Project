#include "Ability.h"
#include "Character.h"

Ability::Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description){
    this->abilityName = abilityName;
    this->type = type;
    this->damage = damage;
    this->hitChance = hitChance;
    this->description = description;
}
Ability::~Ability(){}
