#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "Attribute.h"

class Character; // declare that this exist somewhere in the code
class Ability {
protected:
    std::string abilityName;
    Attribute   type;
    double      damage;
    double      hitChance;
    std::string description;

public:
    Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description);
    
    // Getters
    std::string  getName();
    Attribute    getType();
    double       getDamage();
    double       getHitChance();
    std::string  getDescription();

    virtual void use(Character& user, Character& target) = 0;
    virtual ~Ability();

};
#endif