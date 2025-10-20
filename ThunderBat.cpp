#include "ThunderBat.h"
//creates thunder bat with base stats and abilities
//scales stats according to level
//constructor implementation
//initialises the thunder bat character with its name and level
//sets base stats and abilities
//scales stats according to level
ThunderBat::ThunderBat(int level): Light("Thunder Bat", level){
    this->health = 150+(10*level);    
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    if (this->critChance > 0.4) {
    this->critChance = 0.4;             // cap of 0.4
    }     
    this->speed = 15 + (2 * level);
    abilities.push_back(new Purify()); 
    abilities.push_back(new ElectricWings()); 
}
//levels up thunder bat increasing stats
void ThunderBat::levelUp(){
    this->level++;
    this->health = 150+(10*level);    
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    if (this->critChance < 0.4) {
    this->critChance += 0.01;     //cap of 0.4
    }
    this-> speed += 2;
}
//sets stats based on level
void ThunderBat::setStats(int level){
    this->health = 40 + (10 * level);    
    this->attack = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 0.25 + (0.01 * level);
    if (this->critChance > 0.4) {
    this->critChance = 0.4;             // cap of 0.4
    }     
    this->speed = 15 + (2 * level);
}