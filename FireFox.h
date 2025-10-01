#ifndef FIREFOX_H
#define FIREFOX_H
#include "Fire.h"
class FireFox:public Fire{
    public:
    FireFox(int level);
    bool flameBurst(Character &target);    // special move that does area damage
    bool fireBall(Character &target);
    
    void levelUp() override;
};
#endif