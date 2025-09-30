#include "Dark.h"
#include "DarkKnight.h"

DarkKnight::DarkKnight(int level) {
    this->name = "Dark Knight";
    this->health = 20 + (3 * level);
    this->damage = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    this->critChance = 1.5;
    this->speed = 15 + (3 * level);
    this->level = level;
}
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
bool DarkKnight::sneakAttack(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
    return true;
};
