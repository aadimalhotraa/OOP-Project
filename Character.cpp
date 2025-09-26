#include "Character.h"
#include <string>

// Constructor
Character::Character(){
    name = "unknow name";
    health = 0;
    damage = 0;
    defence = 0;
    critChance = 0;
    speed = 0;
    level = 0;
}

Character::Character(std::string name, double health, double attack, double defence, double critChance, int speed, int level){
    this-> name = name;
    this-> health = health;
    this-> damage = attack;
    this-> defence = defence;
    this-> critChance = critChance;
    this-> speed = speed;
    this-> level = level;
}

// Getters and setters
std::string Character::getName()    {return name;}
double  Character::getHealth()      {return health;}
double  Character::getDamage()      {return damage;}
double  Character::getDefence()     {return defence;}
double  Character::getCritChance()  {return critChance;}
int     Character::getSpeed()       {return speed;}
int     Character::getLevel()       {return level;}

void Character::setName(std::string name)       {this-> name = name;}  
void Character::setHealth(double health)        {this->health = health;}        
void Character::setDamage(double attack)        {this-> damage = attack;}         
void Character::setDefence(double defence)      {this-> defence = defence;}      
void Character::setCritChance(double critChance){this->critChance = critChance;}
void Character::setSpeed(int speed)             {this->speed = speed;}            
void Character::setLevel(int level)             {this->level = level;}              

// Vitrual deconstuctor
Character::~Character(){}