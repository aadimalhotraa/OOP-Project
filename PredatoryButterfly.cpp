#include "Grass.h"
#include "PredatoryButterfly.h"

PredatoryButterfly::PredatoryButterfly(int level) {
    this->name = "Predatory Butterfly";
    this->health = 20 + (3 * level);
    this->damage = 15 + (2 * level);
    this->defence = 25 + (5 * level);
    this->critChance = 1.1;
    this->speed = 20 + (3 * level);
    this->level = level;
}
bool PredatoryButterfly::leafBlade(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.3);
    target.setHealth(calc);
    return true;
};
//for spore im not sure what we want to do yet