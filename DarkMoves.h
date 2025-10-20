#ifndef DARKMOVES_H
#define DARKMOVES_H

#include "Ability.h"
#include <cstdlib>
#include <iostream>

class ShadowStrike : public Ability {
public:
    ShadowStrike();
    bool use(Character& user, Character& target) override;
};

class VoidPulse : public Ability {
public:
    VoidPulse();
    bool use(Character& user, Character& target) override;
};

class NightClaw : public Ability {
public:
    NightClaw();
    bool use(Character& user, Character& target) override;
};

class SneakAttack : public Ability {
public:
    SneakAttack();
   bool use(Character& user, Character& target) override;
};
class SuckerPunch : public Ability {
public:
    SuckerPunch();
    bool use(Character& user, Character& target) override;
};

#endif