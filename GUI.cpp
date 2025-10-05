
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
            DrawText("Fire Fox (you)",65, 60, 35, BLUE);



            DrawText("Health : 70", 80, 140, 26, DARKPURPLE);
            DrawText("Attack : 15", 80, 175, 26, DARKPURPLE);
            DrawText("Defense : 20", 80, 210, 26, DARKPURPLE);
            DrawText("Level : 1", 80, 245, 26, DARKPURPLE);
            DrawText("You attack first!", 80, 300, 26, DARKPURPLE);
           

            

        EndDrawing();
        if (IsKeyPressed(KEY_Y))
        {
            CloseWindow();  // Close the Raylib window
            break;          // Exit the loop immediately
        }

    
   
}

 //--------------------------------------------------------------------------------------


 InitWindow(screenWidth, screenHeight, "raylib [text] example - format text");


 SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
 //--------------------------------------------------------------------------------------

 // Main game loop
 while (!WindowShouldClose())    // Detect window close button or ESC key
 {

     BeginDrawing();


         ClearBackground(LIGHTGRAY);
         DrawText("Rock Turtle (Enemy)",65, 60, 35, BLUE);


         DrawText("Fire Fox threw a fireball at Rock Turtle!", 80, 150, 26, DARKPURPLE);
         DrawText("Health : 70", 80, 210, 26, DARKPURPLE);
         DrawText("Attack : 15", 80, 245, 26, DARKPURPLE);
         DrawText("Defense : 20", 80, 280, 26, DARKPURPLE);
         DrawText("Level : 1", 80, 315, 26, DARKPURPLE);
         
         
         if (IsKeyPressed(KEY_RIGHT))
         {
             CloseWindow();  // Close the Raylib window
             break;          // Exit the loop immediately
         }

         

     EndDrawing();

 

}
return 0;
}