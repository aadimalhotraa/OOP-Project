//code for the water type character
#ifndef WATER_H
#define WATER_H
#include "Character.h"
#include <string>
#include <iostream>
class Water : public Character {
    public:
        // constructors
        Water();
        Water(std::string name, double health, double attack, double defence, double critChance, int speed, int level);

        // overiden virtual functions
        void takeDamage(int amount) override;
        void attackTarget(Character& target) override;
        //water types methods
        virtual void aquaJet(Character &target);
        virtual void hydeoCannon(Character &target);
       
       

        // destructor
        ~Water() override;
};
#endif