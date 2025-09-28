#include "Shark.h"
#include "Water.h"

Shark::Shark() : Water() {
    name = "Shark";
    health = 110;
    damage = 140;
    defence = 15;
    critChance = 0.1;
    speed = 75;
    level = 1;
};

bool Shark::tidalWave(Character &target) {
    //self healing attack
    int randomNum = rand() % 11; 

    if(randomNum<6){ //60% hit chance of the attack
        if(this->health<80){
            this->health=this->health+ 0.25*this->health;
        }
        else{
        this->health=100;
        }
        return true;
    }
    else{
        return false;
    }
};

void Shark::aquaWhip(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.9);
    target.setHealth(calc);
};