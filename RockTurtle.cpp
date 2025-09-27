#include "RockTurtle.h"
#include "Grass.h"
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
void RockTurtle::rootBind(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.7);
    target.setHealth(calc);
};