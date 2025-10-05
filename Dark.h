#ifndef DARK_H
#define DARK_H

#include <vector>
#include "Character.h"
#include "Attribute.h"
#include "DarkMoves.h"

class Dark : public Character {
protected:
    std::vector<Ability*> abilities;

public:
    // constructor
    Dark(std::string name, int level);

    const std::vector<Ability*>& getAbilities() const;
    void useAbility(int index, Character& target);

    ~Dark() override;
};

#endif