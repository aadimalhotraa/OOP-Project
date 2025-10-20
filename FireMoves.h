#ifndef FIREMOVES_H
#define FIREMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib> // rand()

class FlameBurst : public Ability {
public:
    FlameBurst();
    bool use(Character& user, Character& target) override;
};

class FireBall : public Ability {
public:
    FireBall();
    bool use(Character& user, Character& target) override;
};

class EmberStorm : public Ability {
public:
    EmberStorm();
    bool use(Character& user, Character& target) override;
};

class InfernalSlash : public Ability {
public:
    InfernalSlash();
    bool use(Character& user, Character& target) override;
};
class BlazeKick : public Ability {
    public:
        BlazeKick();
        bool use(Character& user, Character& target) override;
    };

#endif