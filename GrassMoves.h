#ifndef GRASSMOVES_H
#define GRASSMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib>  // rand()

class VineWhip : public Ability {
public:
    VineWhip();
    void use(Character& user, Character& target) override;
};

class RootBind : public Ability {
public:
    RootBind();
    void use(Character& user, Character& target) override;
};

class LeafBlade : public Ability {
public:
    LeafBlade();
    void use(Character& user, Character& target) override;
};

class Spore : public Ability {
public:
    Spore();
    void use(Character& user, Character& target) override;
};
class SeedBullet : public Ability {
    public:
        SeedBullet();
        void use(Character& user, Character& target) override;
    };
#endif