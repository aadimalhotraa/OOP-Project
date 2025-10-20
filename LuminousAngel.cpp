#include "LuminousAngel.h"
//creates luminous angel with base stats and abilities
//scales stats according to level
LuminousAngel::LuminousAngel(int level): Light("Luminous Angel", level){
    //base level stats with scaling according to level increase
    this->health = 150+(10*level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
    //adding abilities
    abilities.push_back(new SunRay());          // index 1
    abilities.push_back(new RadiantBeam());     // index 2
}
//levels up luminous angel increasing stats
void LuminousAngel::levelUp(){
    //increase level by 1 and scale stats
    this->level++;
    this->health = 150+(10*level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->speed = 15 + (2 * level);
}
//sets stats based on level
void LuminousAngel::setStats(int level){
    //sets stats based on level with scaling
    this->health = 40 + (10 * level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
}