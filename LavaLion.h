#ifndef LAVALION_H
#define LAVALION_H
#include "Fire.h"
class LavaLion:public Fire{
    public:
    virtual void emberStorm(Character &target);    // special move that does damage and lowers enemy attack
    virtual void infernalSlash(Character &target); // special move that does high damage but lowers user's defence
};
#endif