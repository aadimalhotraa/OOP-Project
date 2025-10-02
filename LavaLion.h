#ifndef LAVALION_H
#define LAVALION_H

#include "Fire.h"

class LavaLion : public Fire {
public:
    LavaLion(int level);
    void levelUp() override;
};

#endif