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
void Fire::blazekick(Character &target){
    //reduces the damage the opponent can inflict
    double calc=(0.75* target.getDamage());
    target.setDamage(calc);
}
void Fire::fireSpin(Character &target){
    //Attacks only if the defence is stronger
    if(target.getDefence()< this->defence) {
    double calc=target.getHealth()-20;
    target.setHealth(calc);
    }
}