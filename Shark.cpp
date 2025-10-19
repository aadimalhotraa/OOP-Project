#include "Shark.h"
//creates shark with base stats and abilities
Shark::Shark(int level): Water("Shark", level){
    //base level stats with scaling according to level increase
    this->health = 150+(10*level);
    //attack
    this->attack = 20 + (3 * level);
    //defence
    this->defence = 15 + (2 * level);
    //critical chance
    this->critChance = 1.1;
    //speed
    this->speed = 25 + (5 * level);
    //adding abilities
    abilities.push_back(new Puddle());          //index 1
    abilities.push_back(new TiddleWave());      //index 2
}
// levels up shark increasing stats
void Shark::levelUp(){
    this->level++;
    this->health = 150+(10*level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this-> speed += 5;
}
//sets stats based on level
void Shark::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
}