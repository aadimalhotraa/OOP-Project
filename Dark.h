//dark enemy class
#ifndef DARK_H
#define DARK_H
#include "Character.h"
#include <string>
#include <iostream>
class Dark : public Character {
    public:
        // constructors
        Dark();
        Dark(std::string name, double health, double attack, double defence, double critChance, int speed, int level);

        // overiden virtual functions
        void takeDamage(int amount) override;
        void attackTarget(Character& target) override;

        //dark types methods
        virtual bool suckerPunch(Character& target);
        virtual bool confusionAttack(Character& target);

        // destructor
        virtual ~Dark() = default;
};
#endif