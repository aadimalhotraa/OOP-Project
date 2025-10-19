#include "LavaLion.h"
//creates lava lion with base stats and abilities
//scales stats according to level
LavaLion::LavaLion(int level): Fire("Lava Lion", level){
    //base level stats with scaling according to level increase
    this->health = 150+(10*level);    
    this->attack = 25 + (5 * level);      
    this->defence = 20 + (3 * level);
    //critical chance
    this->critChance = 0.10;
    this->speed = 15 + (2 * level);
    //adding abilities
    abilities.push_back(new InfernalSlash()); 
    abilities.push_back(new BlazeKick()); 
}
//levels up lava lion increasing stats
void LavaLion::levelUp(){
    this->level++;
    //scale stats
    //base level stats with scaling according to level increase
    this->health = 150+(10*level);    
    this->attack = 25 + (5 * level);      
    this->defence = 20 + (3 * level);
    this-> speed += 2;
}
//sets stats based on level
void LavaLion::setStats(int level){
    this->health = 20 + (3 * level);     
    this->attack = 25 + (5 * level);      
    this->defence = 20 + (3 * level);
    this->critChance = 0.10;
    this->speed = 15 + (2 * level);
}