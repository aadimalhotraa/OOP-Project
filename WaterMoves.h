#ifndef WATERMOVES_H
#define WATERMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib> // rand()

class WaterSlide : public Ability {
public:
    WaterSlide();
    bool use(Character& user, Character& target) override;
};

class Puddle : public Ability {
public:
    Puddle();
    bool use(Character& user, Character& target) override;
};

class TiddleWave : public Ability {
public:
    TiddleWave();
    bool use(Character& user, Character& target) override;
};

class AquaWhip : public Ability {
public:
    AquaWhip();
    bool use(Character& user, Character& target) override;
};

class HydroCannon : public Ability {
    public:
        HydroCannon();
        bool use(Character& user, Character& target) override;
    };

#endif