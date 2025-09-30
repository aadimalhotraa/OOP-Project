#ifndef PREDATORYBUTTERFLY_H
#define PREDATORYBUTTERFLY_H
#include "Grass.h"
class PredatoryButterfly:public Grass{
public:
PredatoryButterfly(int level);
//the unique attacks for the predatory butterfly enemy
bool leafBlade(Character &target);
bool spore(Character &target);
};
#endif