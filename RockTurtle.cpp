#include "RockTurtle.h"
#include "Grass.h"
#include <iostream>
RockTurtle::RockTurtle(int level) {
    this->name = "Rock Turtle";
    this->health = 30 + (6 * level);
    this->damage = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 15 + (2 * level);
    this->level = level;
}
bool RockTurtle::vineWhip(Character &target) {      
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
    return true;
};
bool RockTurtle::rootBind(Character &target) {
    
    int randomNum = rand() % 11; 

    if(randomNum<=5){ //50% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.7);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
}

void RockTurtle::levelUp(){
    this->level++;
    this->health += 6;
    this->damage += 2;
    this-> defence += 5;
    this-> speed += 2;
}