#ifndef SEASERPENT_H
#define SEASERPENT_H
#include "Water.h"
class SeaSerpent:public Water{
    public:
    virtual void waterSlide(Character &target);
    virtual void puddle(Character &target);

};
#endif