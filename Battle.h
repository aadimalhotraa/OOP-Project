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
#include "Scoreboard.h"
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
    bool createSuccessInterface();
    bool createFailureInterface();
    //function to start the battle
    bool executeBattle(Character* ch, Character* atk);
    //function for intial board
    void showIntroAndInstructions();
    //setters for own and enemy characters
    void setOwn();
    void setEnemy();
    void displayOwn();
    void displayEnemy();
    //pointer to own and enemy characters
    Character* own;
    Character* enemy;
    //scoreboard
    Scoreboard* scoreboard;
};
#endif