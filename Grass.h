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
        void takeDamage(int amount) override;
        void attackTarget(Character& target) override;
        //grass types methods
        void applyHeal(double percentage);
        double getHealingBonus() const;
        void seedBullet(Character &target);
        void vineWhip(Character &target);
        void solarBeam(Character &target);
        void leafBlade(Character &target);
        void spore(Character &target);

        // destructor
        ~Grass() override;
};
#endif