#include "PredatoryButterfly.h"

PredatoryButterfly::PredatoryButterfly(int level): Grass("Predatory Butterfly", level){
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 20 + (3 * level);
    abilities.push_back(new RootBind());        // index 1
    abilities.push_back(new LeafBlade());       // index 2
}

void PredatoryButterfly::levelUp(){
    this->level++;
    this->health += 3;
    this->attack += 2;
    this-> defence += 5;
    this-> speed += 3;
}

void PredatoryButterfly::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 20 + (3 * level);
}