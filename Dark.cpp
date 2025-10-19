#include "Dark.h"
#include <iostream>
//constructor implementation
//initialises the dark character with its name and level 
Dark::Dark(std::string name, int level) {
    this->name = name; 
    this->level = level;
    setType(Attribute::DARK);
//add abilities to the dark character
    abilities.push_back(new ShadowStrike());    // index 0
       
}
//returns the vector of abilities
const std::vector<Ability*>& Dark::getAbilities() const {
    return abilities;
}

// Access the Ability* at `abilities[index]` and call its `use()` function.
void Dark::useAbility(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << this->getName() << " tried to use an invalid move index.\n";
        return;
    }
    abilities[index]->use(*this, target);
}
//destructor implementation
Dark::~Dark() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}
