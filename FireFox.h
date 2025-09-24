#ifndef FIREFOX_H
#define FIREFOX_H
#include "Fire.h"
class FireFox:public Fire{
    public:
    virtual void flameBurst(Character &target);    // special move that does area damage
    virtual void fireBall(Character &target);
    

};
#endif