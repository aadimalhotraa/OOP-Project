#include "Ability.h"
#include "Character.h"

Ability::Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description){
    this->abilityName = abilityName;
    this->type        = type;
    this->damage      = damage;
    this->hitChance   = hitChance;
    this->description = description;
}
std::string& Ability::getName()             { return abilityName; }
Attribute          Ability::getType()       { return type; }
double             Ability::getDamage()     { return damage; }
double             Ability::getHitChance()  { return hitChance; }
std::string& Ability::getDescription()      { return description; }
Ability::~Ability(){}
