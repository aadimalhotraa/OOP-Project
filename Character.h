#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{

    protected:
        std::string name;
        double health;
        double damage;
        double defence;
        double critChance;
        int speed;
        int level;
    public:
        // Constructors
        Character();
        Character(std::string name, double health, double damage , double defence, double critChance, int speed, int level);

        // Getters and setters
        std::string getName();
        void setName(std::string name);         // name
        double getHealth();
        void setHealth(double health);          // health
        double getDamage();
        void setDamage(double attack);          // attack
        double getDefence();
        void setDefence(double defence);        // defence
        double getCritChance();
        void setCritChance(double critChance);  // crit chance
        int getSpeed();
        void setSpeed(int speed);               // speed
        int getLevel();
        void setLevel(int level);               // level

        // Virtual functions
        virtual void takeDamage(int amount) = 0;
        virtual void attackTarget(Character& target) = 0;
        virtual void levelUp() = 0;
        
        // Vitrual deconstuctor
        virtual ~Character();
};
#endif