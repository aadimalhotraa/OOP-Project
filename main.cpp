#include <iostream>
#include "Shark.h"
#include "SeaSerpent.h"
#include "LavaLion.h"
#include "FireFox.h"
#include "RockTurtle.h"
#include "PredatoryButterfly.h"
#include "Demon.h"
#include "DarkKnight.h"
#include "ThunderBat.h"
#include "LuminousAngel.h"

using namespace std;

void printStats(Character& c) {
    cout << c.getName()
         << " | Lvl: "  << c.getLevel()
         << " | HP: "   << c.getHealth()
         << " | ATK: "  << c.getDamage()
         << " | DEF: "  << c.getDefence()
         << " | SPD: "  << c.getSpeed()
         << " | CRIT: " << c.getCritChance()
         << endl;
}
int main(){

// Create monsters at level 1
    FireFox fox(1);
    LavaLion lion(1);
    Shark shark(1);

    cout << "=== Initial Stats (Level 1) ===\n";
    printStats(fox);
    printStats(lion);
    printStats(shark);

    cout << "\nLeveling each monster up 3 times...\n\n";

    for (int i = 0; i < 3; i++) {
        fox.levelUp();
        lion.levelUp();
        shark.levelUp();
    }

    cout << "=== Stats After 3 Level Ups ===\n";
    printStats(fox);
    printStats(lion);
    printStats(shark);

    return 0;
}