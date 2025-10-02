#include "Light.h"
#include "LuminousAngel.h"

LuminousAngel::LuminousAngel(int level) {
    this->name = "Luminous Angel";
    this->health = 40 + (10 * level);
    this->damage = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
    this->level = level;
}

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

bool LuminousAngel::sunRay(Character &target) {
    double calc = target.getHealth() - this->damage;
    target.setHealth(calc);
    return true;
};

void LuminousAngel::levelUp(){
    this->level++;
    this->health += 10;
    this->damage += 3;
    this-> defence += 2;
    this-> speed += 2;
}