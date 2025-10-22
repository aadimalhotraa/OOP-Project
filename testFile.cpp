#include <iostream>
#include <cassert>
#include "Character.h"
#include "Ability.h"
#include "FireMoves.h"
#include "WaterMoves.h"
#include "LightMoves.h"
#include "DarkMoves.h"
#include "GrassMoves.h"
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
//tests if the character is created or not 
bool testCharacter(){
    //these lines test character creation
    std::cout <<"testing character creation";

    //create firefox
    FireFox* fox = new FireFox(1);
    //check creation
    if(fox->getName() != "Fire Fox"){
        std::cout << "failed(wrong name)\n";
        return false;
    }
    //level
     if(fox->getLevel() != 1){
        std::cout << "failed (wrong level)\n";
        return false;
    }
    //health
     if(fox->getHealth() <= 0){
        std::cout << "failed (invalid health)\n";
        return false;
    }
    std::cout << "passed\n";
    delete fox;
    return true;
}

bool testDamage() {
        //test damage
    std::cout <<"testing damagfe";
    FireFox* fox = new FireFox(1);
    double startHealth = fox -> getHealth();
    //deal 50 dmaage
    fox -> takeDamage(50);
    if(fox-> getHealth() != startHealth -50){
        std::cout << "failed\n";
        return false;
    }
     std::cout << "passed\n";
    delete fox;
    return true;
}

bool testFaint() {
        //test fainting
    std::cout <<"testing fainting";
    FireFox* fox = new FireFox(1);
    double startHealth = fox -> getHealth();
    //deal large dmaage
    fox -> takeDamage(999);
    if(fox-> getHealth() != 0){
        std::cout << "failed\n";
        return false;
    }
     std::cout << "passed\n";
    delete fox;
    return true;
}


bool testLevelUp() {
        //test leveling
    std::cout <<"testing level";
    FireFox* fox = new FireFox(1);
     double startAttack = fox -> getAttack();
    double startHealth = fox -> getHealth();
    //test leveling
    fox -> levelUp();
    //expecting increasing stats
    if(fox-> getHealth() <= startHealth){
        std::cout << "failed(health didnt increase)\n";
        return false;
    }
    if(fox-> getAttack() <= startAttack){
        std::cout << "failed(attakc didnt increase)\n";
        return false;
    }
     if(fox-> getLevel() != 2){
        std::cout << "failed(level didnt go up)\n";
        return false;
    }
    std::cout << "passed\n";
    delete fox;
    return true;
}

bool testAbility (){
    //tests an ability used on character
    std::cout << "tests fireball";
    FireFox* attacker = new FireFox(1);
    RockTurtle* defender = new RockTurtle(1);
    FireBall* ability = new FireBall();
    //
    double startHealth = defender -> getHealth();
    //using fiureball
    bool hit = ability-> use(*attacker,*defender);
    
    if(!hit){
        //if missed health should remian
        if(defender->getHealth() != startHealth){
            std::cout << "failed\n";
        return false;
        }
    } else {
        //if hit, health drops or else it fails
         if(defender->getHealth() >= startHealth){
            std::cout << "failed\n";
        return false;
        }
    }
    std::cout << "test passed\n";
    delete attacker;
    delete defender;
    delete ability;
    return true;
}

//main file to run all thetests

int main() {
    std::cout << "simple tests";
    int passed= 0;
    int number = 0;
//run the tests and then increment the number of times its passed
    if(testCharacter()) passed++; number++;
    if(testDamage()) passed++; number++;
    if(testFaint()) passed++; number++;
    if(testAbility()) passed++; number++;
    if(testLevelUp()) passed++; number++;
//print message for tests passed
std::cout << "number of tests passed are:" << passed;
//if passed tests equals total tests then success if not counts as fail
if (passed == number)
{
   std::cout << "success all tests passed\n";
   return 0;
} else {
    std::cout << "some tests failed retry";
    return 1;
}

}