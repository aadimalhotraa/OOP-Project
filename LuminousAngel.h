#ifndef LUMINOUSANGEL_H
#define  LUMINOUSANGEL_H

#include "Light.h"

class LuminousAngel:public Light{
public:
    // constructor
    LuminousAngel(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif
