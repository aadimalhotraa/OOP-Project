#include "PredatoryButterfly.h"
//creates predatory butterfly with base stats and abilities
PredatoryButterfly::PredatoryButterfly(int level): Grass("Predatory Butterfly", level){
    //base level stats with scaling according to level increase
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 20 + (3 * level);
    //adding abilities
    abilities.push_back(new RootBind());        // index 1
    abilities.push_back(new LeafBlade());       // index 2
}
//levels up predatory butterfly increasing stats
void PredatoryButterfly::levelUp(){
    //increase level by 1 and scale stats
    this->level++;
    this->health = 150+(10*level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this-> speed += 3;
}
//sets stats based on level
void PredatoryButterfly::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 20 + (3 * level);
}