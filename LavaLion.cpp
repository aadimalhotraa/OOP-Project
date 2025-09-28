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

bool LavaLion::emberStorm(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<8){ //80% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.7);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
};
bool LavaLion::infernalSlash(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<9){ //90% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.4);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
};