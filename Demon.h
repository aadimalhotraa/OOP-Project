#ifndef DEMON_H
#define DEMON_H
#include "Dark.h"
class Demon:public Dark{
    public:
    //the unique attacks for the demon enemy
    virtual void shadowStrike(Character &target);
    virtual bool voidPulse(Character &target);

};
#endif