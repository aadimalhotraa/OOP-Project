#ifndef DEMON_H
#define DEMON_H
#include "Dark.h"
class Demon:public Dark{
    public:
    virtual double shadowStrike();
    virtual double voidPulse();

};
#endif