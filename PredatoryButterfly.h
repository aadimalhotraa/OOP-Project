#ifndef PREDATORYBUTTERFLY_H
#define PREDATORYBUTTERFLY_H
#include "Grass.h"
class PredatoryButterfly:public Grass{
public:
//the unique attacks for the predatory butterfly enemy
virtual void leafBlade(Character &target);
virtual void spore(Character &target);
};
#endif