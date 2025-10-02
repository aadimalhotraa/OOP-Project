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
Water::Water(std::string name, double health, double attack, double defence, double critChance, int speed, int level){
    this->name = name;
    this->health = health;      
    this->damage = attack;
    this->defence = defence;
    this->critChance = critChance;
    this->speed = speed;
    this->level = level;
};
bool Water::aquaJet(Character &target){
    double calc = target.getHealth() - (this->damage * 0.15);
    target.setHealth(calc);
    return true;
};

bool Water::hydroCannon(Character &target){
    double calc = target.getHealth() - (this->damage * 0.25);
    target.setHealth(calc);
    return true;
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