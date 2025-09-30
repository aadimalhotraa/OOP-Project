#ifndef THUNDERBAT_H
#define THUNDERBAT_H
#include "Light.h"
class ThunderBat:public Light{
    public:
    ThunderBat(int level);
    bool radiantBeam(Character &target);
    bool purify(Character &target);
};
#endif