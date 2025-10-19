#include "SeaSerpent.h"
//creates sea serpent with base stats and abilities
//scales stats according to level
SeaSerpent::SeaSerpent(int level): Water("Sea Serpent", level){
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
    abilities.push_back(new AquaWhip()); 
    abilities.push_back(new HydroCannon()); 
}
//levels up sea serpent increasing stats
//scales stats according to level
void SeaSerpent::levelUp(){
    this->level++;
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this-> speed += 5;
}
//sets stats based on level
void SeaSerpent::setStats(int level){
    this->health = 30 + (6 * level);
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level); 
}