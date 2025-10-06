#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <string>

enum class Attribute {NONE,FIRE,WATER,GRASS,DARK,LIGHT};
std::string to_string(Attribute a);
double typeMultiplier(Attribute atk, Attribute def);

#endif