#ifndef LAVALION_H
#define LAVALION_H

#include "Fire.h"
//derived class for lava lion character which inherits from Fire class
class LavaLion : public Fire {
public:
    // constructor
    LavaLion(int level);

    //meember functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif