#ifndef LIGHTMOVES_H
#define LIGHTMOVES_H

#include "Ability.h"
#include <cstdlib>
#include <iostream>
//derived classes for light attribute abilities
//inherits from Ability class
class HolyShield : public Ability {
public:
//holy shield constructor
    HolyShield();
    //uses holy shield ability
    void use(Character& user, Character& target) override;
};
//sun ray ability class
class SunRay : public Ability {
public:
//sun ray constructor
    SunRay();
    //uses sun ray ability
    void use(Character& user, Character& target) override;
};
//radiant beam ability class    
class RadiantBeam : public Ability {
public:
//radiant beam constructor
    RadiantBeam();
    //uses radiant beam ability
    void use(Character& user, Character& target) override;
};
//purify ability class
class Purify : public Ability {
public:
//purify constructor
    Purify();
    //uses purify ability
    void use(Character& user, Character& target) override;
};
//electric wings ability class
class ElectricWings : public Ability {
    public:
    //electric wings constructor
        ElectricWings();
        //uses electric wings ability
        void use(Character& user, Character& target) override;
    };

#endif