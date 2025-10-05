#include "Dark.h"
#include "DarkKnight.h"

DarkKnight::DarkKnight(int level): Dark("Demon", level){
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    this->critChance = 1.5 + (0.02 * level);
    if (this->critChance > 1.8) {
    this->critChance = 1.8;             // cap of 1.8
    }
    this->speed = 15 + (2 * level);
}

void DarkKnight::levelUp(){
    this->level++;
    this->health += 3;
    this->attack += 2;
    this->defence += 3;
    if (this->critChance < 1.8) {
    this->critChance += 0.02;     //cap of 1.8
    }
    this->speed += 2;
}
