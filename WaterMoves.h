#ifndef WATERMOVES_H
#define WATERMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib> // rand()

class WaterSlide : public Ability {
public:
    WaterSlide();
    void use(Character& user, Character& target) override;
};

class Puddle : public Ability {
public:
    Puddle();
    void use(Character& user, Character& target) override;
};

class TiddleWave : public Ability {
public:
    TiddleWave();
    void use(Character& user, Character& target) override;
};

class AquaWhip : public Ability {
public:
    AquaWhip();
    void use(Character& user, Character& target) override;
};

class HydroCannon : public Ability {
    public:
        HydroCannon();
        void use(Character& user, Character& target) override;
    };

#endif