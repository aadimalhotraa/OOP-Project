#include "LavaLion.h"
#include "Fire.h"
LavaLion::LavaLion(int level) {
    this->name = "Lava Lion";
    this->health = 20 + (3 * level);     
    this->damage = 25 + (5 * level);      
    this->defence = 20 + (3 * level);     
    this->speed = 15 + (2 * level);
    this->level = level;
}
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

void LavaLion::levelUp(){
    this->level++;
    this->health += 3;
    this->damage += 5;
    this-> defence += 3;
    this-> speed += 2;
}