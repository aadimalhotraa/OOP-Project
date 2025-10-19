#ifndef THUNDERBAT_H
#define THUNDERBAT_H

#include "Light.h"
//derived class for thunder bat character which inherits from Light class
class ThunderBat : public Light {
public:
    // constructor
    ThunderBat(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif