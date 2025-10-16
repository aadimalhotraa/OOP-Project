#include "raylib.h"
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Battle.h"
#include "Character.h"

int main() {
    std::srand((unsigned)std::time(nullptr));

    Battle battle;

    // Choose your species once @ Lv1
    std::unique_ptr<Character> chosen(battle.chooseCharacter());
    if (!chosen) return 0;

    std::string mySpecies = chosen->getName();
    int playerLevel = 1;

    bool running = true;
    while (running) {
        // Fresh player at current level
        std::unique_ptr<Character> player(battle.createByName(mySpecies, playerLevel));
        if (!player) break;

        // Enemy level scales with you
        int enemyLevel = playerLevel + (std::rand()%4 - 1); // -1..+2
        if (enemyLevel < 1) enemyLevel = 1;
        if (enemyLevel > playerLevel + 4) enemyLevel = playerLevel + 4;

        // Pick enemy species != player's (use nameToPng to normalize)
        std::unique_ptr<Character> enemy;
        for (int tries=0; tries<50 && !enemy; ++tries) {
            int idx = std::rand() % 10;
            std::unique_ptr<Character> cand(battle.createByIndex(idx, enemyLevel));
            if (cand && Battle::nameToPng(cand->getName()) != Battle::nameToPng(mySpecies))
                enemy = std::move(cand);
        }
        if (!enemy) enemy.reset(battle.createByIndex(0, enemyLevel));

        // Run battle
        int outcome = battle.runSpriteBattle(
            player.get(), Battle::nameToPng(player->getName()),
            enemy.get(),  Battle::nameToPng(enemy->getName())
        );
        if (outcome == -1) { running = false; break; }

        // Result screen
        const int W=800, H=450;
        InitWindow(W, H, "OOPMON - Result");
        SetTargetFPS(60);

        bool advance = false;
        while (!WindowShouldClose()) {
            if (IsKeyPressed(KEY_ESCAPE)) { running = false; break; }
            BeginDrawing();
            ClearBackground(BLACK);
            if (outcome == 1) {
                DrawText(TextFormat("You WIN! %s (Lv %d) defeated %s (Lv %d)",
                                    player->getName().c_str(), playerLevel,
                                    enemy->getName().c_str(), enemyLevel),
                         40, 120, 24, GREEN);
                DrawText("Press C to continue (level up) | Q/ESC to quit", 40, 200, 22, RAYWHITE);
            } else {
                DrawText(TextFormat("You LOST. %s (Lv %d) fell to %s (Lv %d)",
                                    player->getName().c_str(), playerLevel,
                                    enemy->getName().c_str(), enemyLevel),
                         40, 120, 24, RED);
                DrawText("Press C to retry (same level) | Q/ESC to quit", 40, 200, 22, RAYWHITE);
            }
            EndDrawing();

            if (IsKeyPressed(KEY_Q)) { running = false; break; }
            if (IsKeyPressed(KEY_C)) { advance = true; break; }
        }
        if (WindowShouldClose()) running = false;
        CloseWindow();

        if (!running) break;
        if (outcome == 1 && advance) playerLevel += 1; // level up on win
        // else: retry same level
    }

    return 0;
}