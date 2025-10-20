#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"
#include "Attribute.h"
#include "FireFox.h" 
#include "LavaLion.h" 
#include "DarkKnight.h"
#include "Demon.h" 
#include "LuminousAngel.h" 
#include "PredatoryButterfly.h"
#include "RockTurtle.h" 
#include "SeaSerpent.h"
#include "Shark.h"
#include "ThunderBat.h" 
#include "string.h"
#include <thread>
#include <chrono>
//battle class which essentially manages the whole battle system and gui of the game
class Battle{
    //public members
    public:
    //functions
    //function to choose character based on attribute
    Character* chooseCharacter(Attribute ch);
    Character* chooseCharacter();
    //function to choose enemy based on level
    Character* chooseEnemy(int level);
    bool executeEnemyMove(Character* ch, Character* atk);
    void executeOwnMove(Character* ch, Character* atk);
    void createSuccessInterface(Character* ch, Character* atk);
    void createFailureInterface(Character* ch, Character* atk);
    //function to start the battle
    void executeBattle(Character* ch, Character* atk);
    //setters for own and enemy characters
    void setOwn();
    void setEnemy();
    //pointer to own and enemy characters
    Character* own;
    Character* enemy;
};
#endif