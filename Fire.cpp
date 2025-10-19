#include "Fire.h"
#include <iostream>
//contructor implementation for the fure class
//takes in name and level of the fire character
//inherits from the Character class
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
void Fire::useAbility(int index, Character& target) {
    //check for valid index
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        //if invalid index, print error message
        std::cout << this->getName() << " tried to use an invalid move index.\n";
        return;
    }
    //use the ability on the target character
    abilities[index]->use(*this, target);
}
//destructor implementation
Fire::~Fire() {
    for (Ability* a : abilities) delete a;
    abilities.clear();
}