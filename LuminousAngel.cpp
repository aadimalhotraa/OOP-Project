#include "LuminousAngel.h"

LuminousAngel::LuminousAngel(int level): Light("Luminous Angel", level){
    this->health = 40 + (10 * level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
}

void LuminousAngel::levelUp(){
    this->level++;
    this->health += 10;
    this->attack += 3;
    this-> defence += 2;
    this-> speed += 2;
}