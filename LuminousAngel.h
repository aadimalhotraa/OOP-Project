#ifndef LUMINOUSANGEL_H
#define  LUMINOUSANGEL_H

#include "Light.h"
//derived class for luminous angel character which inherits from Light class
class LuminousAngel:public Light{
public:
    // constructor
    LuminousAngel(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif
