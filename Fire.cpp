#include "Fire.h"
#include <iostream>

Fire::Fire(std::string name, int level) {
    this->name  = name;
    this->level = level;
    this->setType(Attribute::FIRE);

    // Install the 4 fire moves
    abilities.push_back(new FireBall());        //index 0
   
}

const std::vector<Ability*>& Fire::getAbilities() const {
    return abilities;
}

// Access the Ability* at `abilities[index]` and call its `use()` function.
bool Fire::useAbility(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << this->getName() << " tried to use an invalid move index.\n";
        return;
    }
    bool result=abilities[index]->use(*this, target);
    return result;
}

Fire::~Fire() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}