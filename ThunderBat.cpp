#include "ThunderBat.h"
#include "Light.h"
ThunderBat::ThunderBat() : Light() {
    name = "Thunder Bat";
    health = 100;
    damage = 80;
    defence = 15;
    critChance = 0.1;
    speed = 110;
    level = 1;
};  
bool ThunderBat::radiantBeam(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<8){ //80% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.5);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
};

//purify heals 50 percent of max health
void ThunderBat::purify(Character &target) {
    double calc = target.getHealth() + 50;
    target.setHealth(calc);
};