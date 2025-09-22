#include "Attribute.h"

std::string to_string(Attribute a) {
    switch (a) {
        case Attribute::NONE:  return "None";
        case Attribute::FIRE:  return "Fire";
        case Attribute::WATER: return "Water";
        case Attribute::GRASS: return "Grass";
        case Attribute::DARK:  return "Dark";
        case Attribute::LIGHT: return "Light";
    }
    return "Unknown";
}

double typeMultiplier(Attribute atk, Attribute def) {
    if (atk == Attribute::NONE || def == Attribute::NONE) return 1.0;

    // Fire/Water/Grass
    if (atk == Attribute::FIRE  && def == Attribute::GRASS) return 1.5;
    if (atk == Attribute::GRASS && def == Attribute::WATER) return 1.5;
    if (atk == Attribute::WATER && def == Attribute::FIRE)  return 1.5;

    if (atk == Attribute::FIRE  && def == Attribute::WATER) return 0.75;
    if (atk == Attribute::GRASS && def == Attribute::FIRE)  return 0.75;
    if (atk == Attribute::WATER && def == Attribute::GRASS) return 0.75;

    // Light vs Dark
    if (atk == Attribute::LIGHT && def == Attribute::DARK) return 1.5;
    if (atk == Attribute::DARK  && def == Attribute::LIGHT) return 1.5;

    return 1.0; // neutral
}