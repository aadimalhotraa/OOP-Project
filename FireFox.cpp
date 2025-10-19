#include "FireFox.h"
//constructor implementation
//creates fire fox with base stats and abilities
//scales stats according to level
FireFox::FireFox(int level): Fire("Fire Fox", level){
    //base level stats with scaling according to level increase
    this->health = 150+(10*level);
    this->attack = 25 + (5 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    //cap crit chance at 0.4
    if (this->critChance > 0.4) {
    this->critChance = 0.4;     //cap of 0.4
    }
    //speed scaling
    this->speed = 15 + (2 * level);
    abilities.push_back(new FlameBurst());      //index 1
    abilities.push_back(new EmberStorm());      //index 2
}
//levels up fire fox increasing stats
void FireFox::levelUp(){
    //increase level by 1 and scale stats
    this->level++;
    this->health = 150+(10*level);
    this->attack = 25 + (5 * level);
    this->defence = 15 + (2 * level);
    //increase crit chance with cap of 0.4
    if (this->critChance < 0.4) {
    this->critChance += 0.01;     //cap of 0.4
    }
    this-> speed += 2;
}
//sets stats based on level
void FireFox::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 25 + (5 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    //cap crit chance at 0.4
    if (this->critChance > 0.4) {
    this->critChance = 0.4;     //cap of 0.4
    }
    this->speed = 15 + (2 * level);
}