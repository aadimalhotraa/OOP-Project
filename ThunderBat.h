#ifndef THUNDERBAT_H
#define THUNDERBAT_H
#include "Light.h"
class ThunderBat:public Light{
    protected:
    virtual void radiantBeam(Character &target);
    virtual void purify(Character &target);
};
#endif