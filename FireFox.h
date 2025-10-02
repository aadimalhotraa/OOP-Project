#ifndef FIREFOX_H
#define FIREFOX_H
#include "Fire.h"
class FireFox:public Fire{
    public: 
    
    FireFox(int level);
    void levelUp() override;
};
#endif