#ifndef GRASS_H
#define GRASS_H

#include "Character.h"
#include "Attribute.h"
#include "GrassMoves.h"
#include <vector>

class Grass : public Character {
protected:
    std::vector<Ability*> abilities;

public:
    Grass(std::string name, int level);

    const std::vector<Ability*>& getAbilities() const;
    bool useAbility(int index, Character& target);

    virtual ~Grass();
};

#endif