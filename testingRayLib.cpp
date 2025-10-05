
#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - format text");

  
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

            ClearBackground(LIGHTGRAY);
            DrawText("Choose the attribute of your character:",65, 60, 35, BLUE);



            DrawText("1. Grass", 80, 140, 26, DARKPURPLE);
            DrawText("2. Light", 80, 175, 26, DARKPURPLE);
            DrawText("3. Dark", 80, 210, 26, DARKPURPLE);
            DrawText("4. Fire", 80, 245, 26, DARKPURPLE);
            DrawText("5. Water", 80, 280, 26, DARKPURPLE);

            

        EndDrawing();

    
   
}
return 0;
}