#include "Light.h"
#include "LuminousAngel.h"
LuminousAngel::LuminousAngel() : Light() {
    name = "Luminous Angel";
    health = 100;
    damage = 110;
    defence = 25;
    critChance = 0.2;
    speed = 100;
    level = 1;
};

bool LuminousAngel::holyShield(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<8){ //80% hit chance of the attack
        // increases own defence
        double calc = 1.10*this->defence;
        this->defence = calc;
        return true;
    }
    else{
        return false;
    }
};

void LuminousAngel::sunRay(Character &target) {
    double calc = target.getHealth() - this->damage;
    target.setHealth(calc);
};