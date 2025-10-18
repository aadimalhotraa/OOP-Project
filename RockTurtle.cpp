#include "RockTurtle.h"

RockTurtle::RockTurtle(int level): Grass("Rock Turtle", level){
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
    abilities.push_back(new Spore());
    abilities.push_back(new SeedBullet());      
}

void RockTurtle::levelUp(){
    this->level++;
    this->health += 6;
    this->attack += 2;
    this-> defence += 5;
    this-> speed += 2;
}

void RockTurtle::setStats(int level){
    this->health = 30 + (6 * level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
}