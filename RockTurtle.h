#ifndef ROCKTURTLE_H
#define ROCKTURTLE_H
#include "Grass.h"
class RockTurtle:public Grass{
    public:
    //the unique attacks for the rock turtle enemy
 virtual void vineWhip(Character& target);
 virtual void rootBind(Character& target);

};
#endif