#include "Shark.h"
#include "Water.h"

Shark::Shark() : Water() {
    name = "Shark";
    health = 110;
    damage = 140;
    defence = 15;
    critChance = 0.1;
    speed = 75;
    level = 1;
};

void Shark::tidalWave(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};

void Shark::aquaWhip(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.9);
    target.setHealth(calc);
};