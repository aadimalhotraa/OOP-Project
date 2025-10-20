#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <string>
//all the elements in the game
enum class Attribute {NONE,FIRE,WATER,GRASS,DARK,LIGHT};
//function to convert attribute enum to string
std::string to_string(Attribute a);
//calculate the damage muplitplier based on the attacking and defending attributes
double typeMultiplier(Attribute atk, Attribute def);

#endif