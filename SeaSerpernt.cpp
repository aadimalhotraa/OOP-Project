#include "SeaSerpent.h"
#include "Water.h"

SeaSerpent::SeaSerpent() : Water() {
    name = "Sea Serpent";
    health = 100;
    damage = 130;
    defence = 25;
    critChance = 0.15;
    speed = 60;
    level = 1;
};

void SeaSerpent::waterSlide(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};

void SeaSerpent::puddle(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.3);
    target.setHealth(calc);
};