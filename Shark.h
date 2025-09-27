#ifndef SHARK_H
#define SHARK_H
#include "Water.h"
class Shark:public Water{
    public:
    //unique attacks for the shark enemy
    virtual void tidalWave(Character &target);
    virtual void aquaWhip(Character &target);

};
#endif