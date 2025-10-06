#include "Dark.h"
#include <iostream>

Dark::Dark(std::string name, int level) {
    this->name = name; 
    this->level = level;
    setType(Attribute::DARK);

    abilities.push_back(new ShadowStrike());    // index 0
       
}

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

Dark::~Dark() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}
