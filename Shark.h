#ifndef SHARK_H
#define SHARK_H
#include "Water.h"
class Shark:public Water{
    public:
    //unique attacks for the shark enemy
    Shark(int level);
    bool tidalWave(Character &target);
    void aquaWhip(Character &target);

};
#endif