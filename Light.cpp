#include "Light.h"
#include <iostream>

Light::Light(std::string name, int level) {
    this->name  = name;
    this->level = level;
    this->setType(Attribute::LIGHT);

    // Install the 4 light moves
    abilities.push_back(new HolyShield());      // index 0
    
}

const std::vector<Ability*>& Light::getAbilities() const {
    return abilities;
}

// Access the Ability* at `abilities[index]` and call its `use()` function.
bool Light::useAbility(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << this->getName() << " tried to use an invalid move index.\n";
        return;
    }
    
    bool result=abilities[index]->use(*this, target);
    return result;
}

Light::~Light() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}