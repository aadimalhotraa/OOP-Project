#include "FireFox.h"
#include "Fire.h"

FireFox::FireFox(int level) {
    this->name = "Fire Fox";
    this->health = 20 + (3 * level);
    this->damage = 25 + (5 * level);
    this->defence = 15 + (5 * level);
    this->critChance = 1.25 + (0.01 * level);
    if (this->critChance > 1.4) {
    this->critChance = 1.4;     //cap of 1.4
    }
    this->speed = 15 + (3 * level);
    this->level = level;
}


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