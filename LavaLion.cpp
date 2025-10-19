#include "LavaLion.h"
LavaLion::LavaLion(int level): Fire("Lava Lion", level){
    this->health = 150+(10*level);    
    this->attack = 25 + (5 * level);      
    this->defence = 20 + (3 * level);
    this->critChance = 0.10;
    this->speed = 15 + (2 * level);
    abilities.push_back(new InfernalSlash()); 
    abilities.push_back(new BlazeKick()); 
}
void LavaLion::levelUp(){
    this->level++;
    this->health = 150+(10*level);    
    this->attack = 25 + (5 * level);      
    this->defence = 20 + (3 * level);
    this-> speed += 2;
}

void LavaLion::setStats(int level){
    this->health = 20 + (3 * level);     
    this->attack = 25 + (5 * level);      
    this->defence = 20 + (3 * level);
    this->critChance = 0.10;
    this->speed = 15 + (2 * level);
}