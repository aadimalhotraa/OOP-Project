#ifndef GRASSMOVES_H
#define GRASSMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib>  // rand()

class VineWhip : public Ability {
public:
    VineWhip();
    bool use(Character& user, Character& target) override;
};

class RootBind : public Ability {
public:
    RootBind();
    bool use(Character& user, Character& target) override;
};

class LeafBlade : public Ability {
public:
    LeafBlade();
    bool use(Character& user, Character& target) override;
};

class Spore : public Ability {
public:
    Spore();
    bool use(Character& user, Character& target) override;
};
class SeedBullet : public Ability {
    public:
        SeedBullet();
        bool use(Character& user, Character& target) override;
    };
#endif