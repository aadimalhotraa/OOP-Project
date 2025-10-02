#include "ThunderBat.h"
#include "Light.h"
ThunderBat::ThunderBat(int level) {
    this->name = "Thunder Bat";
    this->health = 40 + (10 * level);    
    this->damage = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.25 + (0.01 * level);
    if (this->critChance > 1.4) {
    this->critChance = 1.4;             // cap of 1.4
    }     
    this->speed = 15 + (2 * level);
    this->level = level;
}
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
bool ThunderBat::purify(Character &target) {
    double calc = target.getHealth() + 50;
    target.setHealth(calc);
    return true;
};

void ThunderBat::levelUp(){
    this->level++;
    this->health += 10;
    this->damage += 2;
    this-> defence += 2;
    if (this->critChance < 1.4) {
    this->critChance += 0.01;     //cap of 1.4
    }
    this-> speed += 2;
}