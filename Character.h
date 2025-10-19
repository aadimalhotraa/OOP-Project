#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Attribute.h"
#include "Ability.h"
#include <vector>
//abstract base class for all characters in the game
class Character{
//protected members
    protected:
    //character attributes
        std::string name;
        double health;
        double attack;
        double defence;
        double critChance;
        int speed;
        int level;
        //elemental attribute
        Attribute type = Attribute::NONE;
    //public members
    public:
        // Constructors
        Character();
        Character(std::string name, double health, double damage , double defence, double critChance, int speed, int level);

        // Getters and setters
        std::string getName();
        void setName(std::string name);         // name
        double getHealth();
        void setHealth(double health);          // health
        double getAttack();
        void setAttack(double attack);          // attack
        double getDefence();
        void setDefence(double defence);        // defence
        double getCritChance();
        void setCritChance(double critChance);  // crit chance
        int getSpeed();
        void setSpeed(int speed);               // speed
        int getLevel();
        void setLevel(int level);               // level
        Attribute getType();
        void setType(Attribute type);           // attribute

        // Virtual functions
        //apply damage to character
        virtual void takeDamage(int amount);
        //set stats based on level
        virtual void setStats(int level) = 0;
        //level up character
        virtual void levelUp() = 0;
        //get abilities of character
        virtual const std::vector<Ability*>& getAbilities() const = 0;
        //use ability on target character
        virtual void useAbility(int index, Character& target) = 0;
        // Vitrual deconstuctor
        virtual ~Character();
};
#endif