#include "Dark.h"
#include "Character.h"

Dark::Dark(){
    name = "unknow name";
    health = 100;
    damage = 100;
    defence = 0;
    critChance = 0;
    speed = 0;
    level = 0;
}
Dark::Dark(std::string name, double health, double attack, double defence, double critChance, int speed, int level){
    this->name = name;
    this->health = health;      
    this->damage = attack;
    this->defence = defence;
    this->critChance = critChance;
    this->speed = speed;
    this->level = level;
};

bool Dark::suckerPunch(Character &target){
    double calc = target.getHealth() - (this->damage * 0.19);
    target.setHealth(calc);
    return true;
};

bool Dark::confusionAttack(Character &target){
    target.setCritChance(0);
    return false;
};
//attacks the target
void Dark::attackTarget(Character &target){
    double calc=target.getHealth()-this->damage;
    target.setHealth(calc);
}
//take damage
void Dark::takeDamage(int amount){
    double calc=this->health-amount;            
    this->health=calc;
};

