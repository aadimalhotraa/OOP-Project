#ifndef PREDATORYBUTTERFLY_H
#define PREDATORYBUTTERFLY_H
#include "Grass.h"
class PredatoryButterfly:public Grass{
public:
PredatoryButterfly(int level);
//the unique attacks for the predatory butterfly enemy
void leafBlade(Character &target);
void spore(Character &target);
};
#endif