#include "Fire.h"
Fire::Fire(){
    name = "unknow name";
    health = 100;
    damage = 150;
    defence = 0;
    critChance = 0;
    speed = 0;
    level = 0;
}
Fire::Fire(std::string name, double health, double attack, double defence, double critChance, int speed, int level){
    this->name = name;
    this->health = health;      
    this->damage = attack;
    this->defence = defence;
    this->critChance = critChance;
    this->speed = speed;
    this->level = level;
};
bool Fire::blazekick(Character &target){
    //reduces the damage the opponent can inflict
    double calc=(0.75* target.getDamage());
    target.setDamage(calc);
    return true;
}
bool Fire::fireSpin(Character &target){
    //Attacks only if the defence is stronger
    if(target.getDefence()< this->defence) {
    double calc=target.getHealth()-20;
    target.setHealth(calc);
    return true;
    }
    else
    return false;
}
//attacks the target
void Fire::attackTarget(Character &target){
    double calc=target.getHealth()-this->damage;
    target.setHealth(calc);
}
//take damage
void Fire::takeDamage(int amount){
    double calc=this->health-amount;
    this->health=calc;
};