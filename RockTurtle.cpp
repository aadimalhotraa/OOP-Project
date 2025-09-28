#include "RockTurtle.h"
#include "Grass.h"
#include <iostream>
RockTurtle::RockTurtle() : Grass() {
    name = "Rock Turtle";
    health = 100;
    damage = 100;
    defence = 50;
    critChance = 0.1;
    speed = 30;
    level = 1;
};
void RockTurtle::vineWhip(Character &target) {      
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
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
