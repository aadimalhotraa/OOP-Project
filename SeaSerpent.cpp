#include "SeaSerpent.h"

SeaSerpent::SeaSerpent(int level): Water("Sea Serpent", level){
    this->health = 30 + (6 * level);
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
    abilities.push_back(new AquaWhip()); 
    abilities.push_back(new HydroCannon()); 
}

void SeaSerpent::levelUp(){
    this->level++;
    this->health += 6;
    this->attack += 2;
    this-> defence += 2;
    this-> speed += 5;
}