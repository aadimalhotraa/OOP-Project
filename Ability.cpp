#include "Ability.h"
#include "Character.h"
#include "Attribute.h"
//constructor implementation
Ability::Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description){
    //name of the abilioty
    this->abilityName = abilityName;
    //type of the ability
    this->type        = type;
    //damage done by the ability
    this->damage      = damage;
    //chance to nhit thje target
    this->hitChance   = hitChance;
    //descprtion of the ability
    this->description = description;
}
//getters implementation
std::string        Ability::getName()       { return abilityName; }
Attribute          Ability::getType()       { return type; }
double             Ability::getDamage()     { return damage; }
double             Ability::getHitChance()  { return hitChance; }
std::string        Ability::getDescription(){ return description; }
//virtual destructor implementation
Ability::~Ability(){}
