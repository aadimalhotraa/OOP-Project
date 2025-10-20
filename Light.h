#ifndef LIGHT_H
#define LIGHT_H

#include "Character.h"
#include "Attribute.h"
#include "LightMoves.h"
#include <vector>
//derived class for light attribute characters
//inherits from Character class
//creates light character with base stats and abilities
//scales stats according to level
class Light : public Character {
    //protected members which hold abilities
    protected:
    //vector to hold abilities
        std::vector<Ability*> abilities;
    public:
        // constructor
        Light(std::string name, int level);
//function to get the abilities of the light character
        const std::vector<Ability*>& getAbilities() const;
        bool useAbility(int index, Character& target);

        virtual ~Light();
};
#endif