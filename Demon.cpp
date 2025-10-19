#include "Demon.h"
//creates demon with base stats and leveling
Demon::Demon(int level): Dark("Demon", level){
    this->health = 150+(10*level);     
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.5 + (0.02 * level);
    if (this->critChance > 0.8) {
    this->critChance = 0.8;             // cap of 0.8
    }        
    this->speed = 15 + (2 * level);
    //adding demon specific abilities
    abilities.push_back(new SneakAttack());  
    abilities.push_back(new SuckerPunch());  
}
//levels up demon increasing stats
void Demon::levelUp(){
    this->level++;
    this->health = 150+(10*level);     
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    if (this->critChance < 0.8) {
    this->critChance += 0.02;     //cap of 0.8
    }
    this->speed += 2;
}
//sets stats based on level
//scales stats according to level
void Demon::setStats(int level){
    this->health = 20 + (3 * level);     
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.5 + (0.02 * level);
    if (this->critChance > 0.8) {
    this->critChance = 0.8;             // cap of 0.8
    }        
    this->speed = 15 + (2 * level);
}