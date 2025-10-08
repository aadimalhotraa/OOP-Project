#include "ThunderBat.h"

ThunderBat::ThunderBat(int level): Light("Thunder Bat", level){
    this->health = 40 + (10 * level);    
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    if (this->critChance > 0.4) {
    this->critChance = 0.4;             // cap of 0.4
    }     
    this->speed = 15 + (2 * level);
    abilities.push_back(new Purify()); 
    abilities.push_back(new ElectricWings()); 
}

void ThunderBat::levelUp(){
    this->level++;
    this->health += 10;
    this->attack += 2;
    this-> defence += 2;
    if (this->critChance < 0.4) {
    this->critChance += 0.01;     //cap of 0.4
    }
    this-> speed += 2;
}

void ThunderBat::setStats(int level){
    this->health = 40 + (10 * level);    
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    if (this->critChance > 0.4) {
    this->critChance = 0.4;             // cap of 0.4
    }     
    this->speed = 15 + (2 * level);
}