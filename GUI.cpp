#include "raylib.h"
#include <iostream>
//main function for the gui.cpp
int main(void)
{
    //initialise the window
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Automatic Health Bar");
//initialise health variables
    float maxHealth = 100.0f;
    float health = maxHealth;
//define health bar rectangles
    Rectangle healthBar = { 50, 50, 400, 40 };
    Rectangle healthBar2 = { 50, 50, 400, 40 };
    

    // Example: predefined health values (simulating damage over time)
    float healthValues[] = { 100, 80, 60, 50, 30, 10, 0 };
    int index = 0;
    float delay = 0.0f; // timer for animation
//set frame rate
    SetTargetFPS(60);
//whiile loop to keep the window open
    while (!WindowShouldClose())
    {
        // Automatic "animation" every 1 second
        delay += GetFrameTime();
        //if delay is greater than 1 second update health
        if (delay >= 1.0f && index < sizeof(healthValues)/sizeof(healthValues[0]))
        {
            health = healthValues[index];
            index++;
            delay = 0.0f;
        }
//calculate fill ratio
        float fillRatio = health / maxHealth;
//define filled part of health bar
        Rectangle filledPart = {
            healthBar.x,
            healthBar.y,
            healthBar.width * fillRatio,
            healthBar.height
        };
//determine bar color based on health percentage
        Color barColor = GREEN;
        if (fillRatio < 0.3f) barColor = RED;
        else if (fillRatio < 0.6f) barColor = ORANGE;
//drawing the health bar
        BeginDrawing();
        ClearBackground(RAYWHITE);
//draw health bar text
        DrawText("Automatic Health Bar", 200, 150, 20, DARKGRAY);
//draw health bar rectangles
        DrawRectangleRec(healthBar, GRAY);
        DrawRectangleRec(filledPart, barColor);
        DrawRectangleLinesEx(healthBar, 3, BLACK);
//draw health text
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "Health: %.0f / %.0f", health, maxHealth);
        DrawText(buffer, 200, 260, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
