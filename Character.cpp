#include "Character.h"
#include <string>

// Constructor
Character::Character(){
    name = "unknow name";
    health = 20;
    attack = 15;
    defence = 15;
    critChance = 1.1;
    speed = 15;
    level = 1;
}

Character::Character(std::string name, double health, double attack, double defence, double critChance, int speed, int level){
    this-> name = name;
    this-> health = health;
    this-> attack = attack;
    this-> defence = defence;
    this-> critChance = critChance;
    this-> speed = speed;
    this-> level = level;
}

// Getters and setters
std::string Character::getName()    {return name;}
double  Character::getHealth()      {return health;}
double  Character::getAttack()      {return attack;}
double  Character::getDefence()     {return defence;}
double  Character::getCritChance()  {return critChance;}
int     Character::getSpeed()       {return speed;}
int     Character::getLevel()       {return level;}

void Character::setName(std::string name)       {this-> name = name;}  
void Character::setHealth(double health)        {this->health = health;}        
void Character::setAttack(double attack)        {this-> attack = attack;}         
void Character::setDefence(double defence)      {this-> defence = defence;}      
void Character::setCritChance(double critChance){this->critChance = critChance;}
void Character::setSpeed(int speed)             {this->speed = speed;}            
void Character::setLevel(int level)             {this->level = level;}              

// Vitrual deconstuctor
Character::~Character(){}