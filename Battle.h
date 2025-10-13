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
class Battle{
    public:
    Character* chooseCharacter();
    Character* chooseEnemy();
    void executeMove(Character* ch, Character* atk);
    void executeBattle(Character* ch, Character* atk);
    void createGraphicInterface(Character* ch, Character* atk);
    void setOwn();
    void setEnemy();
    Character* own;
    Character* enemy;
};
#endif