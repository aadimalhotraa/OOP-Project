#ifndef GRASS_H
#define GRASS_H

#include "Character.h"
#include "Attribute.h"
#include "GrassMoves.h"
#include <vector>
//derived class for grass attribute characters
//inherits from Character class
class Grass : public Character {
    //protected members which hold abilities
protected:
//vector to hold abilities
    std::vector<Ability*> abilities;
//public members
public:
// constructor
    Grass(std::string name, int level);
//function to get the abilities of the grass character
    const std::vector<Ability*>& getAbilities() const;
    bool useAbility(int index, Character& target);

    virtual ~Grass();
};

#endif