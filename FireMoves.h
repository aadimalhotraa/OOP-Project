#ifndef FIREMOVES_H
#define FIREMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib> // rand()

class FlameBurst : public Ability {
public:
    FlameBurst();
    void use(Character& user, Character& target) override;
};

class FireBall : public Ability {
public:
    FireBall();
    void use(Character& user, Character& target) override;
};

class EmberStorm : public Ability {
public:
    EmberStorm();
    void use(Character& user, Character& target) override;
};

class InfernalSlash : public Ability {
public:
    InfernalSlash();
    void use(Character& user, Character& target) override;
};

#endif