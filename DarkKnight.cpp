#include "Dark.h"
#include "DarkKnight.h"

DarkKnight::DarkKnight(int level): Dark("Dark Knight", level){
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    this->critChance = 0.5 + (0.02 * level);
    if (this->critChance > 0.8) {
    this->critChance = 0.8;             // cap of 0.8
    }
    this->speed = 15 + (2 * level);
    abilities.push_back(new VoidPulse());       // index 1
    abilities.push_back(new NightClaw());       // index 2
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
void DarkKnight::setStats(int level){
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    this->critChance = 0.5 + (0.02 * level);
    if (this->critChance > 0.8) {
    this->critChance = 0.8;             // cap of 1.8
    }
    this->speed = 15 + (2 * level);
}
