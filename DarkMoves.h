#ifndef DARKMOVES_H
#define DARKMOVES_H

#include "Ability.h"
#include <cstdlib>
#include <iostream>

class ShadowStrike : public Ability {
public:
    ShadowStrike();
    void use(Character& user, Character& target) override;
};

class VoidPulse : public Ability {
public:
    VoidPulse();
    void use(Character& user, Character& target) override;
};

class NightClaw : public Ability {
public:
    NightClaw();
    void use(Character& user, Character& target) override;
};

class SneakAttack : public Ability {
public:
    SneakAttack();
    void use(Character& user, Character& target) override;
};
class SuckerPunch : public Ability {
public:
    SuckerPunch();
    void use(Character& user, Character& target) override;
};

#endif