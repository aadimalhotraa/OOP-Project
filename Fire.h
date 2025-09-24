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

    // overiden virtual functions
    void takeDamage(int amount) override;
    void attackTarget(Character &target) override;
    // fire types methods
    void blazekick(Character &target);     // special move that does extra damage
    void fireSpin(Character &target);      // special move that does damage over time
    void flameBurst(Character &target);    // special move that does area damage
    void emberStorm(Character &target);    // special move that does damage and lowers enemy attack
    void infernalSlash(Character &target); // special move that does high damage but lowers user's defence
    // Destructor
    ~Fire() override;
};

#endif