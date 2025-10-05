#ifndef LUMINOUSANGEL_H
#define  LUMINOUSANGEL_H

#include "Light.h"

class LuminousAngel:public Light{
public:

    LuminousAngel(int level);

    void levelUp() override;
};

#endif
