#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H
#include "Dark.h"
class DarkKnight:public Dark{
    public:
    //the unique attacks for the dark knight enemy
    virtual bool nightClaw (Character &target);
    virtual void sneakAttack (Character &target);

};
#endif