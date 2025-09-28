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


bool FireFox::flameBurst(Character &target) {
    // Area damage attack
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

bool FireFox::fireBall(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<8){ //80% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 1.5);
        target.setHealth(calc);
        return true;
    }

    else{
        return false;
    }
};