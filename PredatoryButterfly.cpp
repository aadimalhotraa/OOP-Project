#include "Grass.h"
#include "PredatoryButterfly.h"

PredatoryButterfly::PredatoryButterfly() : Grass() {
    name = "Predatory Butterfly";
    health = 100;
    damage = 90;
    defence = 20;
    critChance = 0.15;
    speed = 90;
    level = 1;
};

void PredatoryButterfly::leafBlade(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.3);
    target.setHealth(calc);
};
//for spore im not sure what we want to do yet