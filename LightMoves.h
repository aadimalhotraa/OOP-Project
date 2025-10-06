#ifndef LIGHTMOVES_H
#define LIGHTMOVES_H

#include "Ability.h"
#include <cstdlib>
#include <iostream>

class HolyShield : public Ability {
public:
    HolyShield();
    void use(Character& user, Character& target) override;
};

class SunRay : public Ability {
public:
    SunRay();
    void use(Character& user, Character& target) override;
};

class RadiantBeam : public Ability {
public:
    RadiantBeam();
    void use(Character& user, Character& target) override;
};

class Purify : public Ability {
public:
    Purify();
    void use(Character& user, Character& target) override;
};

class ElectricWings : public Ability {
    public:
        ElectricWings();
        void use(Character& user, Character& target) override;
    };

#endif