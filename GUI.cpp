#include "raylib.h"
#include <iostream>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Automatic Health Bar");

    float maxHealth = 100.0f;
    float health = maxHealth;

    Rectangle healthBar = { 50, 50, 400, 40 };
    Rectangle healthBar2 = { 50, 50, 400, 40 };
    

    // Example: predefined health values (simulating damage over time)
    float healthValues[] = { 100, 80, 60, 50, 30, 10, 0 };
    int index = 0;
    float delay = 0.0f; // timer for animation

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Automatic "animation" every 1 second
        delay += GetFrameTime();
        if (delay >= 1.0f && index < sizeof(healthValues)/sizeof(healthValues[0]))
        {
            health = healthValues[index];
            index++;
            delay = 0.0f;
        }

        float fillRatio = health / maxHealth;

        Rectangle filledPart = {
            healthBar.x,
            healthBar.y,
            healthBar.width * fillRatio,
            healthBar.height
        };

        Color barColor = GREEN;
        if (fillRatio < 0.3f) barColor = RED;
        else if (fillRatio < 0.6f) barColor = ORANGE;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Automatic Health Bar", 200, 150, 20, DARKGRAY);

        DrawRectangleRec(healthBar, GRAY);
        DrawRectangleRec(filledPart, barColor);
        DrawRectangleLinesEx(healthBar, 3, BLACK);

        char buffer[32];
        snprintf(buffer, sizeof(buffer), "Health: %.0f / %.0f", health, maxHealth);
        DrawText(buffer, 200, 260, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
