// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "FireFox.h"
#include "LavaLion.h"

using std::cout;
using std::endl;

void printStats(Character& c) {
    cout << c.getName()
         << " | Lvl: "  << c.getLevel()
         << " | HP: "   << c.getHealth()
         << " | ATK: "  << c.getAttack()
         << " | DEF: "  << c.getDefence()
         << " | SPD: "  << c.getSpeed()
         << " | CRIT: " << c.getCritChance()
         << endl;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create fighters (adjust levels to taste)
    FireFox  fox(10);
    LavaLion lava(10);

    cout << "🔥 Battle Start! 🔥\n\n";
    cout << "Initial stats:\n";
    printStats(fox);
    printStats(lava);
    cout << "\n";

    while (fox.getHealth() > 0 && lava.getHealth() > 0) {
        // Determine order by speed each round (accounts for buffs/debuffs if you add them later)
        Character* first;
        Character* second;

        if (fox.getSpeed() > lava.getSpeed()) {
            first = &fox;  second = &lava;
        } else if (lava.getSpeed() > fox.getSpeed()) {
            first = &lava; second = &fox;
        } else {
            // same speed → randomize who goes first
            if (std::rand() % 2 == 0) { first = &fox; second = &lava; }
            else                      { first = &lava; second = &fox; }
        }

        // Convenience lambdas to use a random ability (both are Fire-derived, so they have abilities)
        auto useRandomMove = [](Fire& user, Character& target) {
            int idx = std::rand() % static_cast<int>(user.getAbilities().size());
            user.useAbility(idx, target);
        };

        cout << "--- " << first->getName() << " acts ---\n";
        useRandomMove(*static_cast<Fire*>(first), *second);

        if (second->getHealth() <= 0) break;

        cout << "--- " << second->getName() << " acts ---\n";
        useRandomMove(*static_cast<Fire*>(second), *first);

        cout << "\nHP after the round:\n";
        cout << fox.getName()  << " HP: " << fox.getHealth()
             << " | " << lava.getName() << " HP: " << lava.getHealth() << "\n\n";
    }

    // Decide winner and level up
    Character* winner = nullptr;
    if (fox.getHealth() > 0 && lava.getHealth() <= 0) {
        winner = &fox;
        cout << lava.getName() << " fainted!\n";
    } else if (lava.getHealth() > 0 && fox.getHealth() <= 0) {
        winner = &lava;
        cout << fox.getName() << " fainted!\n";
    } else {
        cout << "It's a draw—no level up.\n";
        return 0;
    }

    cout << "\n🏆 Winner before level up:\n";
    printStats(*winner);

    cout << "\n✨ Leveling up the winner...\n";
    winner->levelUp();

    cout << "\nWinner after level up:\n";
    printStats(*winner);

    return 0;
}
