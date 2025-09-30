#ifndef ROCKTURTLE_H
#define ROCKTURTLE_H
#include "Grass.h"
class RockTurtle:public Grass{
public:
RockTurtle(int level);
//the unique attacks for the rock turtle enemy
void vineWhip(Character& target);
bool rootBind(Character& target);

};
#endif