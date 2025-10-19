#ifndef FIREFOX_H
#define FIREFOX_H

#include "Fire.h"
//derived class for fire fox character which inherits from Fire class
class FireFox:public Fire{
    //public members
public: 
    // constuctor
    FireFox(int level);

    //member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif