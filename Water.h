#ifndef WATER_H
#define WATER_H

#include "Character.h"
#include "Attribute.h"
#include "WaterMoves.h"
#include <vector>
//derived class for water attribute characters
//inherits from Character class
//
class Water : public Character {
    //protected members
    protected:
    //vector to hold abilities of water character
        std::vector<Ability*> abilities;
        //public members
    public:
        // constructor
        Water(std::string name, int level);
//function to get the abilities of the water character
        const std::vector<Ability*>& getAbilities() const;
        bool useAbility(int index, Character& target);

        virtual ~Water();
};
#endif