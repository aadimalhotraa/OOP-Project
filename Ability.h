#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "Attribute.h"

class Character; // declare that this exist somewhere in the code
// Abstract base class for abilities,to be inherited by specific ability types
class Ability {
//protected members
protected:
//ability atributes
    std::string abilityName;
    Attribute   type;
    double      damage;
    double      hitChance;
    std::string description;
//public members
public:
//constructor, 
    Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description);
//getters which return the ability attributes
    std::string  getName();
    Attribute    getType();
    double       getDamage();
    double       getHitChance();
    std::string  getDescription();

    virtual bool use(Character& user, Character& target) = 0;
    virtual ~Ability();

};
#endif