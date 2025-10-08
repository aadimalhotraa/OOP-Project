#ifndef LAVALION_H
#define LAVALION_H

#include "Fire.h"

class LavaLion : public Fire {
public:
    // constructor
    LavaLion(int level);

    //meember functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif