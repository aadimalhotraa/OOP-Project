#ifndef LUMINOUSANGEL_H
#define  LUMINOUSANGEL_H
#include "Light.h"
class LuminousAngel:public Light{
    public:
        LuminousAngel(int level);
        bool holyShield(Character &target); 
        bool sunRay(Character &target);   

        void levelUp() override;
}; 
#endif