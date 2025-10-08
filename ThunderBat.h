#ifndef THUNDERBAT_H
#define THUNDERBAT_H

#include "Light.h"

class ThunderBat : public Light {
public:
    // constructor
    ThunderBat(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif