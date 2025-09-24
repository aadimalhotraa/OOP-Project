#ifndef THUNDERBAT_H
#define THUNDERBAT_H
#include "Light.h"
class ThunderBat:public Light{
    protected:
    virtual double sunRay();
    virtual double purify();
};
#endif