//grass type character
#ifndef GRASS_H
#define GRASS_H
#include "Character.h"
#include <string>
#include <iostream>

class Grass : public Character {
    public:
        // constructors
        Grass();
        Grass(std::string name, double health, double attack, double defence, double critChance, int speed, int level);

        // overiden virtual functions
        virtual void takeDamage(int amount) override;
        virtual void attackTarget(Character& target) override;
        //grass types methods
        virtual bool seedBullet(Character &target);
        virtual bool solarBeam(Character &target);
        
        // destructor
        virtual ~Grass() = default;
};
#endif