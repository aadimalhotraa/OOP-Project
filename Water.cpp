#include "Water.h"
#include <iostream>
//constructor implementation of Water class
//initialises the water character with its name and level
//sets attribute to WATER
Water::Water(std::string name, int level) {
    this->name  = name;
    this->level = level;
    this->setType(Attribute::WATER);
//adding abilities to the water character
    // Install the 4 water moves
    abilities.push_back(new WaterSlide());      //index 0
    
}
//returns the vector of abilities
//function to get the abilities of the water character
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
//destructor implementation
Water::~Water() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}