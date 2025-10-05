#include "Water.h"
#include <iostream>

Water::Water(std::string name, int level) {
    this->name  = name;
    this->level = level;
    this->setType(Attribute::WATER);

    // Install the 4 water moves
    abilities.push_back(new WaterSlide());      //index 0
    abilities.push_back(new Puddle());          //index 1
    abilities.push_back(new TiddleWave());      //index 2
    abilities.push_back(new AquaWhip());        //index 3
}

const std::vector<Ability*>& Water::getAbilities() const {
    return abilities;
}

// Access the Ability* at `abilities[index]` and call its `use()` function.
void Water::useAbility(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << this->getName() << " tried to use an invalid move index.\n";
        return;
    }
    abilities[index]->use(*this, target);
}

Water::~Water() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}