//type class for thge light chracter
#ifndef LIGHT_H
#define LIGHT_H
#include "Character.h"
#include <string>
#include <iostream>

class Light : public Character {
    public:
        // constructors
        Light();
        Light(std::string name, double health, double attack, double defence, double critChance, int speed, int level);

        // overiden virtual functions
        virtual void takeDamage(int amount) override;
        virtual void attackTarget(Character& target) override;
        //light abilities
        virtual void lightningStrike(Character& target);
        virtual void electricWings(Character& target);

        // destructor
       virtual ~Light();
};
#endif