#ifndef FIREFOX_H
#define FIREFOX_H
#include "Fire.h"
class FireFox:public Fire{
    public:
    virtual bool flameBurst(Character &target);    // special move that does area damage
    virtual bool fireBall(Character &target);
    

};
#endif