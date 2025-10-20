#ifndef GRASSMOVES_H
#define GRASSMOVES_H

#include "Ability.h"
#include <iostream>
#include <cstdlib>  // rand()
//derived classes for grass attribute abilities
//inherits from Ability class
class VineWhip : public Ability {
public:
//vine whip constructor
    VineWhip();
    bool use(Character& user, Character& target) override;
};
//root bind ability class
class RootBind : public Ability {
public:
//root bind constructor
    RootBind();
    bool use(Character& user, Character& target) override;
};
//leaf blade ability class
class LeafBlade : public Ability {
public:
//leaf blade constructor
    LeafBlade();
    bool use(Character& user, Character& target) override;
};
//spore ability class
class Spore : public Ability {
public:
//spore constructor
    Spore();
    bool use(Character& user, Character& target) override;
};
//seed bullet ability class
class SeedBullet : public Ability {
    public:
    //seed bullet constructor
        SeedBullet();
        bool use(Character& user, Character& target) override;
    };
#endif