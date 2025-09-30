#ifndef SEASERPENT_H
#define SEASERPENT_H
#include "Water.h"
class SeaSerpent:public Water{
    public:
    //the unique attacks for this water enemy
    SeaSerpent(int level);
    void waterSlide(Character &target);
    bool puddle(Character &target);

};
#endif