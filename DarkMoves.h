#ifndef DARKMOVES_H
#define DARKMOVES_H

#include "Ability.h"
#include <cstdlib>
#include <iostream>
//dervied classes for dark attribute abilities
class ShadowStrike : public Ability {
public:
//constructor implementation
//it wll be the same for all the other ones which are given below 
    ShadowStrike();
    //uses shadow strike ability
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