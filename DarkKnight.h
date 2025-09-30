#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H
#include "Dark.h"
class DarkKnight:public Dark{
    public:
    DarkKnight(int level);
    //the unique attacks for the dark knight enemy
    bool nightClaw (Character &target);
    void sneakAttack (Character &target);

};
#endif