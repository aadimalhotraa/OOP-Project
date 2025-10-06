#include "Grass.h"
#include <iostream>

Grass::Grass(std::string name, int level) {
    this->name  = name;
    this->level = level;
    this->setType(Attribute::GRASS);

    abilities.push_back(new VineWhip());        // index 0
   
}

const std::vector<Ability*>& Grass::getAbilities() const {
    return abilities;
}

void Grass::useAbility(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << getName() << " tried to use an invalid move index.\n";
        return;
    }
    abilities[index]->use(*this, target);
}

Grass::~Grass() {
    for (Ability* a : abilities) delete a;
}

