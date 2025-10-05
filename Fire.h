#ifndef FIRE_H
#define FIRE_H

#include "Character.h"
#include "Attribute.h"
#include "FireMoves.h"
#include <vector>

class Fire : public Character {
    protected:
        std::vector<Ability*> abilities;
    public:
        // constructor
        Fire(std::string name, int level);

        const std::vector<Ability*>& getAbilities() const;
        void useAbility(int index, Character& target);

        ~Fire() override;
};

#endif