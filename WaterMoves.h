#ifndef WATERMOVES_H
#define WATERMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib> // rand()
//file fo rthe water abilities
//they all inherit from the Ability class
class WaterSlide : public Ability {
    //public members
public:
//constructorfor the waterslide ability
    WaterSlide();
    //use function implementation
    void use(Character& user, Character& target) override;
};
//puddle ability class
class Puddle : public Ability {
public:
//constructor for puddle ability
    Puddle();
    //use function implementation
    void use(Character& user, Character& target) override;
};
//tiddle wave ability class
class TiddleWave : public Ability {
public:
//constructor for tiddle wave ability
    TiddleWave();
    //use function implementation
    void use(Character& user, Character& target) override;
};
//aqua whip ability class
class AquaWhip : public Ability {
public:
//constructor for aqua whip ability
    AquaWhip();
    //use function implementation
    void use(Character& user, Character& target) override;
};
//hydro cannon ability class
class HydroCannon : public Ability {
    public:
    //constructor for hydro cannon ability
        HydroCannon();
        //use function implementation
        void use(Character& user, Character& target) override;
    };

#endif