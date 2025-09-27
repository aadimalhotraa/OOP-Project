#ifndef SEASERPENT_H
#define SEASERPENT_H
#include "Water.h"
class SeaSerpent:public Water{
    public:
    //the unique attacks for this water enemy
    virtual void waterSlide(Character &target);
    virtual void puddle(Character &target);

};
#endif