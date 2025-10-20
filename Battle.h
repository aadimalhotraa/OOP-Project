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

class Battle{
    public:
    Character* chooseCharacter(Attribute ch);
    Character* chooseCharacter();
    Character* chooseEnemy(int level);
    bool executeEnemyMove(Character* ch, Character* atk);
    void executeOwnMove(Character* ch, Character* atk);
    void createSuccessInterface(Character* ch, Character* atk);
    void createFailureInterface(Character* ch, Character* atk);
    void executeBattle(Character* ch, Character* atk);
    void setOwn();
    void setEnemy();
    Character* own;
    Character* enemy;
};
#endif