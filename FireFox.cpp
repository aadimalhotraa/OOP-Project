#include "FireFox.h"

FireFox::FireFox(int level): Fire("Fire Fox", level){
    this->health = 20 + (3 * level);
    this->attack = 25 + (5 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    if (this->critChance > 0.4) {
    this->critChance = 0.4;     //cap of 0.4
    }
    this->speed = 15 + (2 * level);
    abilities.push_back(new FlameBurst());      //index 1
    abilities.push_back(new EmberStorm());      //index 2
}
void FireFox::levelUp(){
    this->level++;
    this->health += 3;
    this->attack += 5;
    this-> defence += 2;
    if (this->critChance < 0.4) {
    this->critChance += 0.01;     //cap of 0.4
    }
    this-> speed += 2;
}

void FireFox::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 25 + (5 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    if (this->critChance > 0.4) {
    this->critChance = 0.4;     //cap of 0.4
    }
    this->speed = 15 + (2 * level);
}