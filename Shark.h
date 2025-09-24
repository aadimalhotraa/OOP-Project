#ifndef SHARK_H
#define SHARK_H
#include "Water.h"
class Shark:public Water{
    public:
    virtual void tidalWave(Character &target);
    virtual void aquaWhip(Character &target);

};
#endif