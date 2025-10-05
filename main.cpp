#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

#include "Shark.h"
#include "SeaSerpent.h"
#include "FireFox.h"
#include "LavaLion.h"
#include "RockTurtle.h"
#include "PredatoryButterfly.h"
#include "Demon.h"
#include "DarkKnight.h"
#include "ThunderBat.h"
#include "LuminousAngel.h"

using std::cout;
using std::endl;

// ------------------- Utility functions -------------------
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

static void useRandomMoveFor(Character* who, Character& target) {
    if (auto* f = dynamic_cast<Fire*>(who)) {
        int i = std::rand() % static_cast<int>(f->getAbilities().size());
        f->useAbility(i, target);
    } else if (auto* w = dynamic_cast<Water*>(who)) {
        int i = std::rand() % static_cast<int>(w->getAbilities().size());
        w->useAbility(i, target);
    } else if (auto* g = dynamic_cast<Grass*>(who)) {
        int i = std::rand() % static_cast<int>(g->getAbilities().size());
        g->useAbility(i, target);
    } else if (auto* d = dynamic_cast<Dark*>(who)) {
        int i = std::rand() % static_cast<int>(d->getAbilities().size());
        d->useAbility(i, target);
    } else if (auto* l = dynamic_cast<Light*>(who)) {
        int i = std::rand() % static_cast<int>(l->getAbilities().size());
        l->useAbility(i, target);
    }
}

// Random enemy factory
static std::unique_ptr<Character> makeRandomEnemy(int levelMin=9, int levelMax=12) {
    int lvl = levelMin + (std::rand() % (levelMax - levelMin + 1));
    switch (std::rand() % 9) {  // removed VineBeast case
        case 0: return std::make_unique<SeaSerpent>(lvl);
        case 1: return std::make_unique<FireFox>(lvl);
        case 2: return std::make_unique<LavaLion>(lvl);
        case 3: return std::make_unique<RockTurtle>(lvl);
        case 4: return std::make_unique<PredatoryButterfly>(lvl);
        case 5: return std::make_unique<Demon>(lvl);
        case 6: return std::make_unique<DarkKnight>(lvl);
        case 7: return std::make_unique<ThunderBat>(lvl);
        default: return std::make_unique<LuminousAngel>(lvl);
    }
}

// Speed-based battle round
static void oneRound(Character& A, Character& B) {
    Character* first;
    Character* second;

    if (A.getSpeed() > B.getSpeed())      { first = &A; second = &B; }
    else if (B.getSpeed() > A.getSpeed()) { first = &B; second = &A; }
    else { if (std::rand() % 2) { first = &A; second = &B; } else { first = &B; second = &A; } }

    cout << "--- " << first->getName() << " acts ---\n";
    useRandomMoveFor(first, *second);
    if (second->getHealth() <= 0) return;

    cout << "--- " << second->getName() << " acts ---\n";
    useRandomMoveFor(second, *first);
}

// One complete battle (returns true if player wins)
static bool runBattle(Shark& player, Character& enemy) {
    cout << "⚔️  " << player.getName() << " vs " << enemy.getName() << " ⚔️\n";
    cout << "Player:\n"; printStats(player);
    cout << "Enemy:\n";  printStats(enemy);
    cout << "\n";

    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        oneRound(player, enemy);
        cout << "\nHP now — "
             << player.getName() << ": " << player.getHealth()
             << " | " << enemy.getName()  << ": " << enemy.getHealth() << "\n\n";
    }

    if (player.getHealth() > 0 && enemy.getHealth() <= 0) {
        cout << enemy.getName() << " fainted!\n🎉 You win!\n\n";
        return true;
    } else if (enemy.getHealth() > 0 && player.getHealth() <= 0) {
        cout << player.getName() << " fainted!\n💀 You lose.\n\n";
        return false;
    } else {
        cout << "It's a draw.\n\n";
        return false;
    }
}

// ------------------- main -------------------
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Shark player(10);

    // ---------- Battle 1 ----------
    auto enemy1 = makeRandomEnemy();
    double startHP1 = player.getHealth();

    cout << "🔥 Battle 1 Start! 🔥\n\n";
    bool won1 = runBattle(player, *enemy1);

    if (won1) {
        cout << "Restoring HP to: " << startHP1 << "\n";
        player.setHealth(startHP1);

        cout << "\n🏆 BEFORE level up:\n"; printStats(player);
        cout << "\n✨ Leveling up...\n"; player.levelUp();
        cout << "\nAFTER level up:\n"; printStats(player);
        cout << "\n";
    }

    if (!won1) return 0;

    // ---------- Battle 2 ----------
    auto enemy2 = makeRandomEnemy();
    double startHP2 = player.getHealth();

    cout << "🔥 Battle 2 Start! 🔥\n\n";
    bool won2 = runBattle(player, *enemy2);

    if (won2) {
        cout << "Restoring HP to: " << startHP2 << "\n";
        player.setHealth(startHP2);

        cout << "\n🏆 BEFORE level up:\n"; printStats(player);
        cout << "\n✨ Leveling up...\n"; player.levelUp();
        cout << "\nAFTER level up:\n"; printStats(player);
        cout << "\n";
    }

    cout << "🏁 Battles finished!\n";
    return 0;
}
