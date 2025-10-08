#ifndef FIREFOX_H
#define FIREFOX_H

#include "Fire.h"

class FireFox:public Fire{
public: 
    // constuctor
    FireFox(int level);

    //member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif