#ifndef THUNDERBAT_H
#define THUNDERBAT_H

#include "Light.h"

class ThunderBat : public Light {
public:
    ThunderBat(int level);

    void levelUp() override;
};

#endif