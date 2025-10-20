#include "Character.h"
#include <iostream>

// Constructor
Character::Character(){
    name = "unknow name";
    health = 0;
    attack = 0;
    defence = 0;
    critChance = 0;
    speed = 0;
    level = 0;
}
//parametised constructor
Character::Character(std::string name, double health, double attack, double defence, double critChance, int speed, int level){
    //initialising the character attributes
    this-> name = name;
    //health
    this-> health = health;
    //attack
    this-> attack = attack;
    //defence
    this-> defence = defence;
    //critical chance
    this-> critChance = critChance;
    //speed
    this-> speed = speed;
    //level
    this-> level = level;
}

// Getters and setters
///gets the character name
std::string Character::getName()    {return name;}
//gets the character health
double  Character::getHealth()      {return health;}
//gets the character attack
double  Character::getAttack()      {return attack;}
//gets the character defence
double  Character::getDefence()     {return defence;}
//gets the character critical chance
double  Character::getCritChance()  {return critChance;}
//gets the character speed
int     Character::getSpeed()       {return speed;}
//gets the character level
int     Character::getLevel()       {return level;}
//gets the character attribute
Attribute Character::getType()      { return type;}
//setters implementation
void Character::setName(std::string name)       {this-> name = name;}  
void Character::setHealth(double health)        {this->health = health;}        
void Character::setAttack(double attack)        {this-> attack = attack;}         
void Character::setDefence(double defence)      {this-> defence = defence;}      
void Character::setCritChance(double critChance){this->critChance = critChance;}
void Character::setSpeed(int speed)             {this->speed = speed;}            
void Character::setLevel(int level)             {this->level = level;}              
void Character::setType(Attribute type)         {this-> type = type; }

//apply damage to charater and check for deafeat
void Character::takeDamage(int amount) {
    //if damage amount is negative set it to 0
    if (amount < 0) amount = 0;
    //reduce health by damage amount
    health = std::max(0.0, health - static_cast<double>(amount));
    if (health <= 0.0) {
        std::cout << name << " fainted!\n";
    }
}
// Vitrual deconstuctor
Character::~Character(){}