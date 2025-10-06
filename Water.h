#ifndef WATER_H
#define WATER_H

#include "Character.h"
#include "Attribute.h"
#include "WaterMoves.h"
#include <vector>
class Water : public Character {
    protected:
        std::vector<Ability*> abilities;
    public:
        // constructor
        Water(std::string name, int level);

        const std::vector<Ability*>& getAbilities() const;
        void useAbility(int index, Character& target);

        virtual ~Water();
};
#endif