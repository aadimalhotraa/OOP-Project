// this is the test code for the fire class
#ifndef FIRE_H
#define FIRE_H

#include "Character.h"
#include <string>
#include <iostream>

class Fire : public Character
{
public:
    // constructors
    Fire();
    Fire(std::string name, double health, double attack, double defence, double critChance, int speed, int level);
    // fire types methods
    virtual void blazekick(Character &target); // special move that does extra damage
    virtual void fireSpin(Character &target);  // special move that does damage over time

    // attacks the target
    virtual void attackTarget(Character &target) override;
    virtual void takeDamage(int amount) override;
    // Destructor
    virtual ~Fire();
};

#endif