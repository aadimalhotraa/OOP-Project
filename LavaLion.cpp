#include "LavaLion.h"
#include "Fire.h"

LavaLion::LavaLion() : Fire() {
    name = "Lava Lion";
    health = 120;
    damage = 180;
    defence = 30;
    critChance = 0.2;
    speed = 70;
    level = 1;
};

void LavaLion::emberStorm(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.7);
    target.setHealth(calc);
};
void LavaLion::infernalSlash(Character &target) {
   
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};