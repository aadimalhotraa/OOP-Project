#include "Dark.h"
#include "DarkKnight.h"

DarkKnight::DarkKnight() : Dark() {
    name = "Dark Knight";
    health = 150;
    damage = 180;
    defence = 30;
    critChance = 0.2;
    speed = 40;
    level = 1;
};
bool DarkKnight::nightClaw(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<8){ //80% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.3);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
};
void DarkKnight::sneakAttack(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};
