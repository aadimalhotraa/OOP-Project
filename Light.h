#ifndef LIGHT_H
#define LIGHT_H
#include "Character.h"
#include "Attribute.h"
#include "LightMoves.h"
#include <vector>
class Light : public Character {
    protected:
        std::vector<Ability*> abilities;
    public:
        // constructor
        Light(std::string name, int level);

        const std::vector<Ability*>& getAbilities() const;
        void useAbility(int index, Character& target);

        virtual ~Light();
};
#endif