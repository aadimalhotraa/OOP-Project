#ifndef FIREMOVES_H
#define FIREMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib> // rand()

//derived classes for fire attribute abilities
//inherits from Ability class
class FlameBurst : public Ability {
//public members
public:
//flame burst constructor
    FlameBurst();
    bool use(Character& user, Character& target) override;
};
//fire ball ability class
class FireBall : public Ability {
public:
//fire ball constructor
    FireBall();
    bool use(Character& user, Character& target) override;
};
//ember storm ability class
class EmberStorm : public Ability {
public:
//ember storm constructor
    EmberStorm();
    bool use(Character& user, Character& target) override;
};
//infernal slash ability class
class InfernalSlash : public Ability {
public:
    InfernalSlash();
    bool use(Character& user, Character& target) override;
};
//blaze kick ability class
class BlazeKick : public Ability {
    public:
        BlazeKick();
        bool use(Character& user, Character& target) override;
    };

#endif