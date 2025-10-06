#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"
#include "Attribute.h"
class Battle{
    Character* chooseCharacter(Attribute ch);
    Character* chooseEnemy();
    void executeMove(Character* ch, Character* atk);
    void executeBattle(Character* ch, Character* atk);
    void createGraphicInterface(Character* ch, Character* atk);
};
#endif