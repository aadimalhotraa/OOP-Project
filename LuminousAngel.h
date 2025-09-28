#ifndef LUMINOUSANGEL_H
#define  LUMINOUSANGEL_H
#include "Light.h"
class LuminousAngel:public Light{
public:
virtual bool holyShield(Character &target); 
virtual void sunRay(Character &target);   
}; 
#endif