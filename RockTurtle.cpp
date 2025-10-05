#include "RockTurtle.h"

RockTurtle::RockTurtle(int level): Grass("Rock Turtle", level){
    this->health = 30 + (6 * level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
}

void RockTurtle::levelUp(){
    this->level++;
    this->health += 6;
    this->attack += 2;
    this-> defence += 5;
    this-> speed += 2;
}