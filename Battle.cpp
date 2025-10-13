#include "Battle.h"
#include "raylib.h"
Character* Battle::chooseCharacter(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight,"OOPMON");
    std::vector<Character*> characters;

    SetTargetFPS(60); 
    srand(time(NULL));
    
    while (!WindowShouldClose()) 
    {
       
        if (IsKeyPressed(KEY_ONE)) { 
            int r = rand() % 2;
            characters.push_back(new RockTurtle(1));
            characters.push_back(new PredatoryButterfly(1));
            CloseWindow(); 
            return characters[r]; 
        }
        if (IsKeyPressed(KEY_TWO)) { 
            int r = rand() % 2;
            characters.push_back(new ThunderBat(1));
            characters.push_back(new LuminousAngel(1));
            CloseWindow(); 
            return characters[r];
        }
        if (IsKeyPressed(KEY_THREE)) { 
            int r = rand() % 2;
            characters.push_back(new Demon(1));
            characters.push_back(new DarkKnight(1));
            CloseWindow(); 
            return characters[r];
        }
        if (IsKeyPressed(KEY_FOUR)) { 
            int r = rand() % 2;
            characters.push_back(new FireFox(1));
            characters.push_back(new LavaLion(1));
            CloseWindow(); 
            return characters[r];
            
        }
        if (IsKeyPressed(KEY_FIVE)) { 
            int r = rand() % 2;
            characters.push_back(new Shark(1));
            characters.push_back(new SeaSerpent(1));
            CloseWindow(); 
            return characters[r];
        }

        
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        DrawText("Choose the attribute of your character:", 65, 60, 35, BLUE);

        DrawText("1. Grass", 80, 140, 26, DARKPURPLE);
        DrawText("2. Light", 80, 175, 26, DARKPURPLE);
        DrawText("3. Dark", 80, 210, 26, DARKPURPLE);
        DrawText("4. Fire", 80, 245, 26, DARKPURPLE);
        DrawText("5. Water", 80, 280, 26, DARKPURPLE);

        EndDrawing();
    }

   
    CloseWindow(); 
}

void Battle::setOwn(){
    this->own=chooseCharacter();
}

Character* Battle::chooseEnemy(){
    srand(time(NULL));
    std::vector<Character*> enemies;

    enemies.push_back(new RockTurtle(1));
    enemies.push_back(new PredatoryButterfly(1));
    enemies.push_back(new ThunderBat(1));
    enemies.push_back(new LuminousAngel(1));
    enemies.push_back(new Demon(1));
    enemies.push_back(new DarkKnight(1));
    enemies.push_back(new FireFox(1));
    enemies.push_back(new LavaLion(1));
    enemies.push_back(new Shark(1));
    enemies.push_back(new SeaSerpent(1));

    while(true){
        int r=rand()%10;
        if(enemies[r]->getName()==own->getName())
        continue;

        else
        return enemies[r];
    }
    
}





void Battle::setEnemy(){
    this->enemy=chooseEnemy();
}
//MAIN GAME*********************************************************************
int main(){
    Battle battle;

    battle.setEnemy();
    battle.setOwn();

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight,"OOPMON");

    SetTargetFPS(60); 
    bool text=true;
    //Displays the character name
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        if(text){
        std::string message1="Your character is " + battle.own->getName();
        DrawText(message1.c_str(), 65, 130, 45, GREEN);
        DrawText("Press 1 to continue", 65, 280, 26, GREEN);
        }
        if (IsKeyPressed(KEY_ONE)){
            CloseWindow();
            break;
        }
        EndDrawing();
    }


    //Displays the enemy name
    InitWindow(screenWidth, screenHeight,"OOPMON");
    SetTargetFPS(60); 
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        if(text){
        std::string message1="Your enemy is " + battle.enemy->getName();
        DrawText(message1.c_str(), 65, 130, 45, RED);
        DrawText("Press 1 to continue", 65, 280, 26, RED);
        }
        if (IsKeyPressed(KEY_ONE)){
            CloseWindow();
            break;
        }
        EndDrawing(); 
    }
    CloseWindow(); 
}