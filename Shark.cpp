#include "Shark.h"
#include "Water.h"

Shark::Shark(int level){
    this-> name = "Shark";
    this-> health = 20 + (3 * level);
    this-> damage = 20 + (3 * level);
    this-> defence = 15 + (2 * level);
    this-> critChance = 1.1;
    this-> speed = 25 + (5 * level);
    this-> level = level;
}
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

bool Shark::aquaWhip(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.9);
    target.setHealth(calc);
    return true;
};

void Shark::levelUp(){
    this->level++;
    this->health += 3;
    this->damage += 3;
    this-> defence += 2;
    this-> speed += 5;
}