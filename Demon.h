#ifndef DEMON_H
#define DEMON_H
#include "Dark.h"
class Demon:public Dark{
    public:
    Demon(int level);
    //the unique attacks for the demon enemy
    bool shadowStrike(Character &target);
    bool voidPulse(Character &target);

    void levelUp() override;
};
#endif