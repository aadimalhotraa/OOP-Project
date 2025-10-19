#include "Battle.h"
#include "raylib.h"
#include <iostream>
//function to choose character based on attribute
Character* Battle::chooseCharacter(){
    //intialise the size of the window
    const int screenWidth = 800;
    const int screenHeight = 450;
//initialise the window
    InitWindow(screenWidth, screenHeight,"OOPMON");
    std::vector<Character*> characters;
//set the frame rate
    SetTargetFPS(60); 
    srand(time(NULL));
    //while loop to keep the window open until a key is pressed
    while (!WindowShouldClose()) 
    {
    //check for key presses to choose character attribute
    //one: for grass, two: for light, three: for dark, four: for fire, five: for water
        if (IsKeyPressed(KEY_ONE)) { 
            //randomly choose between the two grass characters
            int r = rand() % 2;
            //push the characters into a vector
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

    //drawing the interfce    
        BeginDrawing();
    //set background colour
        ClearBackground(LIGHTGRAY);
    //display text options
        DrawText("Choose the attribute of your character:", 65, 60, 35, BLUE);

        DrawText("1. Grass", 80, 140, 26, DARKPURPLE);
        DrawText("2. Light", 80, 175, 26, DARKPURPLE);
        DrawText("3. Dark", 80, 210, 26, DARKPURPLE);
        DrawText("4. Fire", 80, 245, 26, DARKPURPLE);
        DrawText("5. Water", 80, 280, 26, DARKPURPLE);

        EndDrawing();
    }

   //close the window
    CloseWindow(); 
}
//setter for own character
void Battle::setOwn(){
    //calls the choose character function and sets the own character pointer
    this->own=chooseCharacter();
}
//function to choose enemy based on level
Character* Battle::chooseEnemy(int level){
    //seed for random number generation
    srand(time(NULL));
    //vector to hold possible enemies
    std::vector<Character*> enemies;
//pushing all possible enemies into the vector
    enemies.push_back(new RockTurtle(level));
    enemies.push_back(new PredatoryButterfly(level));
    enemies.push_back(new ThunderBat(level));
    enemies.push_back(new LuminousAngel(level));
    enemies.push_back(new Demon(level));
    enemies.push_back(new DarkKnight(level));
    enemies.push_back(new FireFox(level));
    enemies.push_back(new LavaLion(level));
    enemies.push_back(new Shark(level));
    enemies.push_back(new SeaSerpent(level));
//randomly select an enemy that is not the same as the own character
    while(true){
        int r=rand()%10;
        if(enemies[r]->getName()==own->getName())
        continue;

        else
        //gives a different enemy
        return enemies[r];
    }
    
}
//setter for enemy character
void Battle::setEnemy(){
    //calls the choose enemy function and sets the enemy character pointer
    this->enemy=chooseEnemy(own->getLevel());
}
//function to execute enemy move
void Battle::executeEnemyMove(Character *ch, Character *atk){
    //randomly select an ability from the enemy's abilities and use it on the own character
    int enemyAbi;
    std::vector<Ability*> enemy;
    enemy=atk->getAbilities();
    enemyAbi=enemy.size();
    int ranEnemy= rand()%enemyAbi;
    atk->useAbility(ranEnemy, *ch);
}
//unction to show vicotruy interface
void Battle::createSuccessInterface(Character* ch, Character* atk){
    const int screenWidth = 800; 
    const int screenHeight = 450; 
    InitWindow(screenWidth, screenHeight,"OOPMON"); 
    SetTargetFPS(60); 
    srand(time(NULL));
    //while loop to keep the window open until a key is pressed
    while (!WindowShouldClose()) 
    { 
        //check for key presses to continue the game or exit
        if(IsKeyPressed(KEY_Y)){
            //level up own character and set new enemy
            ch->levelUp();
            setEnemy();
            //start a new battle
            executeBattle(ch,enemy);
        }
        if(IsKeyPressed(KEY_N)){
            CloseWindow();
            return;
        }
//drawing the interface
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Congratulations! You won that round ", 65, 60, 35, GREEN);
        DrawText("Do you want to Continue the Game?(Y/N) ", 65, 130, 35, GREEN);
        EndDrawing();
    }
}
//function to show defeat interface
void Battle::createFailureInterface(Character* ch, Character* atk){
    const int screenWidth = 800; 
    const int screenHeight = 450; 
    InitWindow(screenWidth, screenHeight,"OOPMON"); 
    SetTargetFPS(60); 
    srand(time(NULL));
    //while loop to keep the window open until a key is pressed
    while (!WindowShouldClose()) 
    { 
        //check for key presses to retry or exit
        if(IsKeyPressed(KEY_Y)){
            setOwn();
            setEnemy();
            executeBattle(own,enemy);
        }
        if(IsKeyPressed(KEY_N)){
            CloseWindow();
            return;
        }
        //drawing the interface for the defeat
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Oops! You lost that round ", 65, 60, 35, RED);
        DrawText("Do you want to try again?(Y/N) ", 65, 130, 35, RED);
        EndDrawing();
        
    }
}
//function to execute the battle
void Battle::executeBattle(Character* ch, Character* atk){ 
    const int screenWidth = 800; 
    const int screenHeight = 450; 
    InitWindow(screenWidth, screenHeight,"OOPMON"); 
    SetTargetFPS(60); 
    srand(time(NULL)); 
    //helps in displaying name on top
    std::string message1= ch->getName()+" (You)"; 
    std::string message2=atk->getName(); 
    //getting the max for each to calculate ration
    //initialising variables
    double ownDamage, ownDefence, ownHealth, enemyDamage, enemyDefence, enemyHealth; 
    ownDamage=ch->getAttack(); 
    ownDefence=ch->getDefence(); 
    ownHealth=ch->getHealth(); 
    enemyDamage=atk->getAttack(); 
    enemyDefence=atk->getDefence(); 
    enemyHealth=atk->getHealth(); 
    //initialising Rectangles
    Rectangle ownDamageBar = { 150, 120, 150, 40 };
    Rectangle enemyDamageBar = { 550, 120, 150, 40 };
    Rectangle ownHealthBar = { 150, 180, 150, 40 };
    Rectangle enemyHealthBar = { 550, 180, 150, 40 };
    Rectangle ownDefenceBar = { 160, 240, 150, 40 };
    Rectangle enemyDefenceBar = { 560, 240, 150, 40 };
    // getting abilities and listing them
    std::vector<Ability*> own;
    int ownAbi;
    own=ch->getAbilities();
    ownAbi=own.size();
    //while loop to keep the window open until a key is pressed
    while (!WindowShouldClose()) 
    { 
        //check for key presses to choose ability
        if (IsKeyPressed(KEY_ONE)){
            //use the chosen ability on the enemy character
            ch->useAbility(0,*atk);
            executeEnemyMove(ch, atk);
        }
        if (IsKeyPressed(KEY_TWO)){
            //use the chosen ability on the enemy character
            ch->useAbility(1,*atk);
            executeEnemyMove(ch, atk);
        }
        //
        if (IsKeyPressed(KEY_THREE)){
            //use the chosen ability on the enemy character
            ch->useAbility(2,*atk);
            executeEnemyMove(ch, atk);
        }
        //these following code dynamically updates the bars based on current stats
        float ownDamageRatio = ch->getAttack() / ownDamage;
        float enemyDamageRatio = atk->getAttack() / enemyDamage;
        float ownHealthRatio = ch->getHealth() / ownHealth;
        float enemyHealthRatio = atk->getHealth() / enemyHealth;
        float ownDefenceRatio = ch->getDefence() / ownDefence;
        float enemyDefenceRatio = atk->getDefence() / enemyDefence;
//filled parts of the bars
        Rectangle ownDamageBarFilledPart = {
            ownDamageBar.x,
            ownDamageBar.y,
            ownDamageBar.width * ownDamageRatio,
            ownDamageBar.height
        };
        //filled parts of the bars
        Rectangle enemyDamageBarFilledPart = {
            enemyDamageBar.x,
            enemyDamageBar.y,
            enemyDamageBar.width * enemyDamageRatio,
            enemyDamageBar.height
        };
        //filled parts of the bars
        Rectangle ownHealthBarFilledPart = {
            ownHealthBar.x,
            ownHealthBar.y,
            ownHealthBar.width * ownHealthRatio,
            ownHealthBar.height
        };
        //filled parts of the bars
        Rectangle enemyHealthBarFilledPart = {
            enemyHealthBar.x,
            enemyHealthBar.y,
            enemyHealthBar.width * enemyHealthRatio,
            enemyHealthBar.height
        };
        Rectangle ownDefenceBarFilledPart = {
            ownDefenceBar.x,
            ownDefenceBar.y,
            ownDefenceBar.width * ownDefenceRatio,
            ownDefenceBar.height
        };
        Rectangle enemyDefenceBarFilledPart = {
            enemyDefenceBar.x,
            enemyDefenceBar.y,
            enemyDefenceBar.width * enemyDefenceRatio,
            enemyDefenceBar.height
        };
        


//draw battle interface
        BeginDrawing(); 
        ClearBackground(BLACK); 
        //drawing text
        DrawText(message1.c_str(), 50, 50, 25, BLUE); 
        DrawText(message2.c_str(), 450, 50, 25, BLUE); 
        //drawing labels
        DrawText("Damage", 50, 120, 25, BLUE); 
        DrawText("Damage", 450, 120, 25, BLUE); 
        DrawText("Health", 50, 180, 25, BLUE); 
        DrawText("Health", 450, 180, 25, BLUE); 
        DrawText("Defence", 50, 240, 25, BLUE); 
        DrawText("Defence", 450, 240, 25, BLUE); 
        //drawing rectangles / empty stat vars
        DrawRectangleRec(ownHealthBar, GRAY);
        DrawRectangleRec(enemyHealthBar, GRAY);
        DrawRectangleRec(ownDamageBar, GRAY);
        DrawRectangleRec(enemyDamageBar, GRAY);
        DrawRectangleRec(ownDefenceBar, GRAY);
        DrawRectangleRec(enemyDefenceBar, GRAY);
        //colouring the rectangles dynamically
        DrawRectangleRec(enemyDefenceBarFilledPart, GREEN);
        DrawRectangleRec(ownDefenceBarFilledPart, GREEN);
        DrawRectangleRec(enemyHealthBarFilledPart, GREEN);
        DrawRectangleRec(ownHealthBarFilledPart, GREEN);
        DrawRectangleRec(enemyDamageBarFilledPart, GREEN);
        DrawRectangleRec(ownDamageBarFilledPart, GREEN);

        //listing abilities
        DrawText("Abilities", 50, 290, 25, BLUE);
        for(int i=0; i<ownAbi; i++){
            std::string abiName=std::to_string(i + 1) + ". " +own[i]->getName();
            DrawText(abiName.c_str(), 50, 320+(30*i), 25, BLUE);  
        }
        EndDrawing(); 
//check for win/loss conditions
        if(ch->getHealth()<=0){
            CloseWindow();
            createFailureInterface(ch, atk);
            break;

        }
//enemy defeated
        if(atk->getHealth()<=0){
            CloseWindow();
            createSuccessInterface(ch, atk);
            break;

        } 

    } 
     
       
    } 

//main function to run the battle system
int main(){
    //initialise battle object
    Battle battle;
    //set own and enemy characters
    battle.setOwn();
    battle.setEnemy();
    
//initialise window parameters
    const int screenWidth = 800;
    const int screenHeight = 450;
//display own character name
    InitWindow(screenWidth, screenHeight,"OOPMON");
//set frame rate
    SetTargetFPS(60); 
    bool text=true;
    //Displays the character name
    //while loop to keep the window open until a key is pressed
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        //display text
        if(text){
        //the message to be displayed
        std::string message1="Your character is " + battle.own->getName();
        DrawText(message1.c_str(), 65, 130, 40, GREEN);
        DrawText("Press 1 to continue", 65, 280, 26, GREEN);
        }
        //check for key press to continue
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
        //display text
        if(text){
        std::string message1="Your enemy is " + battle.enemy->getName();
        DrawText(message1.c_str(), 65, 130, 40, RED);
        DrawText("Press 1 to continue", 65, 280, 26, RED);
        }
        if (IsKeyPressed(KEY_ONE)){
            CloseWindow();
            break;
        }
        EndDrawing(); 
    }
    battle.executeBattle(battle.own,battle.enemy);
}

