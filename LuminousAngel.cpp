#include "Light.h"
#include "LuminousAngel.h"
LuminousAngel::LuminousAngel() : Light() {
    name = "Luminous Angel";
    health = 100;
    damage = 110;
    defence = 25;
    critChance = 0.2;
    speed = 100;
    level = 1;
};

void LuminousAngel::holyShield(Character &target) {
    // increases own defence temporarily
    double calc = this->defence + 20;
    this->defence = calc;
};

void LuminousAngel::sunRay(Character &target) {
    double calc = target.getHealth() - (this->damage * 0.5);
    target.setHealth(calc);
};