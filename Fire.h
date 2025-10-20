#ifndef FIRE_H
#define FIRE_H

#include "Character.h"
#include "Attribute.h"
#include "FireMoves.h"
#include <vector>
//derived class for fire attribute characters
//inherits from Character class
class Fire : public Character {
    //protected members which hold abilities
    protected:
        std::vector<Ability*> abilities;
    public:
        // constructor
        Fire(std::string name, int level);
//function to get the abilities of the fire character
        const std::vector<Ability*>& getAbilities() const;
        bool useAbility(int index, Character& target);

        virtual ~Fire();
};

#endif