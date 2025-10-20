#include "Dark.h"
#include "DarkKnight.h"
//creates dark knight with base stats and abilites
DarkKnight::DarkKnight(int level): Dark("Dark Knight", level){
    //base level stats with scaling
    this->health = 150 + (10*level);
    this->attack = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    this->critChance = 0.5 + (0.02 * level);
    //cap crit chance at 0.8
    if (this->critChance > 0.8) {
    this->critChance = 0.8;             // cap of 0.8
    }
    this->speed = 15 + (2 * level);
    abilities.push_back(new VoidPulse());       // index 1
    abilities.push_back(new NightClaw());       // index 2
}
//levels up dark knight increasing stats
void DarkKnight::levelUp(){
    //increase level by 1 and scale stats
    this->level++;
    this->health = 150 + (10*level);
    this->attack = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    if (this->critChance < 1.8) {
    this->critChance += 0.02;     //cap of 1.8
    }
    this->speed += 2;
}
//sets stats based on level
void DarkKnight::setStats(int level){
    //sets stats based on level with scaling
    this->health = 20 + (3 * level);
    this->attack = 15 + (2 * level);
    this->defence = 20 + (3 * level);
    this->critChance = 0.5 + (0.02 * level);
    if (this->critChance > 0.8) {
    this->critChance = 0.8;             // cap of 1.8
    }
    this->speed = 15 + (2 * level);
}
