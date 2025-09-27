#include "Dark.h"
#include "DarkKnight.h"

DarkKnight::DarkKnight() : Dark() {
    name = "Dark Knight";
    health = 150;
    damage = 180;
    defence = 30;
    critChance = 0.2;
    speed = 40;
    level = 1;
};
void DarkKnight::nightClaw(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.3);
    target.setHealth(calc);
};
void DarkKnight::sneakAttack(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.4);
    target.setHealth(calc);
};
