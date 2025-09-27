#include "FireFox.h"
#include "Fire.h"

FireFox::FireFox() : Fire() {
    name = "Fire Fox";
    health = 100;
    damage = 120;
    defence = 20;
    critChance = 0.1;
    speed = 80;
    level = 1;
};


void FireFox::flameBurst(Character &target) {
    // Area damage attack
    double calc = target.getHealth() - (this->damage * 0.8);
    target.setHealth(calc);
};

void FireFox::fireBall(Character &target) {
    // Ranged attack
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};