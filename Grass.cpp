#include "Grass.h"
#include <iostream>
//contructor implementation for the grass class
//takes in name and level of the grass character
//inherits from the Character class
Grass::Grass(std::string name, int level) {
    //initialising name and level
    this->name  = name;
    this->level = level;
    //setting the attribute type to grass
    this->setType(Attribute::GRASS);
//add abilities to the grass character
    abilities.push_back(new VineWhip());        // index 0
   
}
//returns the vector of abilities
const std::vector<Ability*>& Grass::getAbilities() const {
    return abilities;
}
//use ability on target character
//
void Grass::useAbility(int index, Character& target) {
    //check for valid index
    if (index < 0 || index >= static_cast<int>(abilities.size())) {
        std::cout << getName() << " tried to use an invalid move index.\n";
        return;
    }
    //use the ability on the target character
    abilities[index]->use(*this, target);
}
//destructor implementation
Grass::~Grass() {
    for (Ability* a : abilities) delete a;
}

