#include "Dark.h"
#include "Demon.h"

Demon::Demon() : Dark() {
    name = "Demon";
    health = 100;
    damage = 200;
    defence = 40;
    critChance = 0.25;
    speed = 50;
    level = 1;
};

void Demon::shadowStrike(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};
bool Demon::voidPulse(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<7){ //70% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.8);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
};