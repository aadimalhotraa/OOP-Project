#include "Light.h"
#include <iostream>

Light::Light(std::string name, int level) {
    this->name  = name;
    this->level = level;
    this->setType(Attribute::LIGHT);

    // Install the 4 light moves
    abilities.push_back(new HolyShield());      // index 0
    abilities.push_back(new SunRay());          // index 1
    abilities.push_back(new RadiantBeam());     // index 2
    abilities.push_back(new Purify());          // index 3
}

const std::vector<Ability*>& Light::getAbilities() const {
    return abilities;
}

// Access the Ability* at `abilities[index]` and call its `use()` function.
void Light::useAbility(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << this->getName() << " tried to use an invalid move index.\n";
        return;
    }
    abilities[index]->use(*this, target);
}

Light::~Light() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}