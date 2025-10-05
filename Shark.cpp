#include "Shark.h"

Shark::Shark(int level): Water("Shark", level){
    this->health = 20 + (3 * level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
}

void Shark::levelUp(){
    this->level++;
    this->health += 3;
    this->attack += 3;
    this-> defence += 2;
    this-> speed += 5;
}