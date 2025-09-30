#ifndef DEMON_H
#define DEMON_H
#include "Dark.h"
class Demon:public Dark{
    public:
    Demon(int level);
    //the unique attacks for the demon enemy
    void shadowStrike(Character &target);
    bool voidPulse(Character &target);

};
#endif