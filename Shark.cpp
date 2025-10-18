#include "Shark.h"

Shark::Shark(int level): Water("Shark", level){
    this->health = 150+(10*level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
    abilities.push_back(new Puddle());          //index 1
    abilities.push_back(new TiddleWave());      //index 2
}

void Shark::levelUp(){
    this->level++;
    this->health += 3;
    this->attack += 3;
    this-> defence += 2;
    this-> speed += 5;
}

void Shark::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 20 + (3 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
}