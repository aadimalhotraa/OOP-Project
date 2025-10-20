#ifndef LIGHTMOVES_H
#define LIGHTMOVES_H

#include "Ability.h"
#include <cstdlib>
#include <iostream>

class HolyShield : public Ability {
public:
    HolyShield();
    bool use(Character& user, Character& target) override;
};

class SunRay : public Ability {
public:
    SunRay();
    bool use(Character& user, Character& target) override;
};

class RadiantBeam : public Ability {
public:
    RadiantBeam();
    bool use(Character& user, Character& target) override;
};

class Purify : public Ability {
public:
    Purify();
    bool use(Character& user, Character& target) override;
};

class ElectricWings : public Ability {
    public:
        ElectricWings();
       bool use(Character& user, Character& target) override;
    };

#endif