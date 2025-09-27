#include "Character.h"
#include "Water.h"

Water::Water(){
    name = "unknow name";
    health = 100;
    damage = 100;
    defence = 0;
    critChance = 0;
    speed = 0;
    level = 0;
}
void Water::aquaJet(Character &target){
    double calc = target.getHealth() - (this->damage * 0.15);
    target.setHealth(calc);
};

void Water::hydeoCannon(Character &target){
    double calc = target.getHealth() - (this->damage * 0.25);
    target.setHealth(calc);
};
//attacks the target
void Water::attackTarget(Character &target){
    double calc=target.getHealth()-this->damage;
    target.setHealth(calc);
}
//take damage
void Water::takeDamage(int amount){
    double calc=this->health-amount;
    this->health=calc;
};