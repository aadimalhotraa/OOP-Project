#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "Attribute.h"

class Character; // declare that this exist somewhere in the code
class Ability{
    protected:
        std::string abilityName;
        Attribute type;
        double damage;
        double hitChance;
        std::string description;        // include this so that in gui you can see what abilty does if you hover and click a particular button
    public:
    Ability(std::string abilityName, Attribute type, double damage, double hitChance, std::string description);
    
    std::string& name();
    Attribute type();
    int power();
    double hitChance();
    std::string& description();

    virtual bool use(Character& user, Character& target) = 0;
    virtual ~Ability();
};

#endif