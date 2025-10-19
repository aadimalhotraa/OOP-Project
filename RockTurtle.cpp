#include "RockTurtle.h"
//creates rock turtle with base stats and abilities
//scales stats according to level
RockTurtle::RockTurtle(int level): Grass("Rock Turtle", level){
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
    abilities.push_back(new Spore());
    abilities.push_back(new SeedBullet());      
}
//levels up rock turtle increasing stats
//scales stats according to level
void RockTurtle::levelUp(){
    this->level++;
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this-> speed += 2;
}
//sets stats based on level
void RockTurtle::setStats(int level){
    this->health = 30 + (6 * level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
}