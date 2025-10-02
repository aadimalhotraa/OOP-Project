#include "Dark.h"
#include "Demon.h"

Demon::Demon(int level) {
    this->name = "Demon";
    this->health = 20 + (3 * level);     
    this->damage = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.5 + (0.02 * level);
    if (this->critChance > 1.8) {
    this->critChance = 1.8;             // cap of 1.8
    }        
    this->speed = 15 + (2 * level);
    this->level = level;
}

bool Demon::shadowStrike(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
    return true;
};
bool Demon::voidPulse(Character &target) {
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

void Demon::levelUp(){
    this->level++;
    this->health += 3;
    this->damage += 3;
    this->defence += 2;
    if (this->critChance < 1.8) {
    this->critChance += 0.02;     //cap of 1.8
    }
    this->speed += 2;
}