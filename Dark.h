#ifndef DARK_H
#define DARK_H

#include <vector>
#include "Character.h"
#include "Attribute.h"
#include "DarkMoves.h"
//derived class for dark attribute characters
//inherits from Character class
class Dark : public Character {
    //protected members
protected:
//vector to hold abilities of dark character
    std::vector<Ability*> abilities;
//public members
public:
    // constructor
    Dark(std::string name, int level);
//function to get the abilities of the dark character
    const std::vector<Ability*>& getAbilities() const;
    //function to use ability on target character
    void useAbility(int index, Character& target);
//destructor
    virtual ~Dark();
};

#endif