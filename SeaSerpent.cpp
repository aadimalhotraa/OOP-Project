#include "SeaSerpent.h"
#include "Water.h"

SeaSerpent::SeaSerpent(int level) {
    this->name = "Sea Serpent";
    this->health = 30 + (6 * level);
    this->damage = 15 + (2 * level);
    this->defence = 15 + (2 * level);
    this->critChance = 1.1;
    this->speed = 25 + (5 * level);
    this->level = level;
}

bool SeaSerpent::waterSlide(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
    return true;
    
};

bool SeaSerpent::puddle(Character &target) {
    int randomNum = rand() % 11; 

    if(randomNum<7){ //70% hit chance of the attack
        double calc = target.getHealth() - (this->damage * 0.3);
        target.setHealth(calc);
        return true;
    }
    else{
        return false;
    }
};

void SeaSerpent::levelUp(){
    this->level++;
    this->health += 5;
    this->damage += 2;
    this-> defence += 2;
    this-> speed += 5;
}