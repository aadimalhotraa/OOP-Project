#include "Battle.h"
#include "raylib.h"
#include <iostream>
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

Character* Battle::chooseEnemy(int level){
    srand(time(NULL));
    std::vector<Character*> enemies;

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

    while(true){
        int r=rand()%10;
        if(enemies[r]->getName()==own->getName())
        continue;

        else
        return enemies[r];
    }
    
}

void Battle::setEnemy(){
    this->enemy=chooseEnemy(own->getLevel());
}
bool Battle::executeEnemyMove(Character *ch, Character *atk){
    int enemyAbi;
    std::vector<Ability*> enemy;
    enemy=atk->getAbilities();
    enemyAbi=enemy.size();
    int ranEnemy= rand()%enemyAbi;
    bool enemyResult=atk->useAbility(ranEnemy, *ch);
    return enemyResult;
}
void Battle::createSuccessInterface(Character* ch, Character* atk){
    const int screenWidth = 800; 
    const int screenHeight = 450; 
    InitWindow(screenWidth, screenHeight,"OOPMON"); 
    SetTargetFPS(60); 
    srand(time(NULL));
    while (!WindowShouldClose()) 
    { 
        if(IsKeyPressed(KEY_Y)){
            ch->levelUp();
            setEnemy();
            executeBattle(ch,enemy);
        }
        if(IsKeyPressed(KEY_N)){
            CloseWindow();
            return;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Congratulations! You won that round ", 65, 60, 35, GREEN);
        DrawText("Do you want to Continue the Game?(Y/N) ", 65, 130, 35, GREEN);
        EndDrawing();
    }
}
void Battle::createFailureInterface(Character* ch, Character* atk){
    const int screenWidth = 800; 
    const int screenHeight = 450; 
    InitWindow(screenWidth, screenHeight,"OOPMON"); 
    SetTargetFPS(60); 
    srand(time(NULL));
    while (!WindowShouldClose()) 
    { 
        if(IsKeyPressed(KEY_Y)){
            setOwn();
            setEnemy();
            executeBattle(own,enemy);
        }
        if(IsKeyPressed(KEY_N)){
            CloseWindow();
            return;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Oops! You lost that round ", 65, 60, 35, RED);
        DrawText("Do you want to try again?(Y/N) ", 65, 130, 35, RED);
        EndDrawing();
        
    }
}

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
    // getting abilities and listing
    std::vector<Ability*> own;
    int ownAbi;
    own=ch->getAbilities();
    ownAbi=own.size();
    bool ownResult, enemyResult;
    std::string ownMessage, enemyMessage;
    while (!WindowShouldClose()) 
    { 
        if (IsKeyPressed(KEY_ONE)){
            ownResult=ch->useAbility(0,*atk);
            enemyResult=executeEnemyMove(ch, atk);
            if(ownResult){
                ownMessage= ch->getName()+" attacked "+atk->getName();
            }
            else{
                 enemyMessage= ch->getName()+" missed";
            }
            if(enemyResult){
                 ownMessage= atk->getName()+" attacked "+ ch->getName();
            }
            else{
                 enemyMessage= atk->getName()+" missed";
            }
        }
        if (IsKeyPressed(KEY_TWO)){
            ownResult=ch->useAbility(1,*atk);
            enemyResult=executeEnemyMove(ch, atk);
            if(ownResult){
                 ownMessage= ch->getName()+" attacked "+atk->getName();
            }
            else{
                enemyMessage= ch->getName()+" missed";
            }
            if(enemyResult){
                 ownMessage= atk->getName()+" attacked "+ ch->getName();
            }
            else{
                 enemyMessage= atk->getName()+" missed";
            }
        }
        if (IsKeyPressed(KEY_THREE)){
            ownResult=ch->useAbility(2,*atk);
            enemyResult=executeEnemyMove(ch, atk);
            if(ownResult){
                 ownMessage= ch->getName()+" attacked "+atk->getName();
            }
            else{
                 enemyMessage= ch->getName()+" missed";
            }
            if(enemyResult){
                 ownMessage= atk->getName()+" attacked "+ ch->getName();
            }
            else{
                 enemyMessage= atk->getName()+" missed";
            }
        }
        float ownDamageRatio = ch->getAttack() / ownDamage;
        float enemyDamageRatio = atk->getAttack() / enemyDamage;
        float ownHealthRatio = ch->getHealth() / ownHealth;
        float enemyHealthRatio = atk->getHealth() / enemyHealth;
        float ownDefenceRatio = ch->getDefence() / ownDefence;
        float enemyDefenceRatio = atk->getDefence() / enemyDefence;

        Rectangle ownDamageBarFilledPart = {
            ownDamageBar.x,
            ownDamageBar.y,
            ownDamageBar.width * ownDamageRatio,
            ownDamageBar.height
        };
        Rectangle enemyDamageBarFilledPart = {
            enemyDamageBar.x,
            enemyDamageBar.y,
            enemyDamageBar.width * enemyDamageRatio,
            enemyDamageBar.height
        };
        Rectangle ownHealthBarFilledPart = {
            ownHealthBar.x,
            ownHealthBar.y,
            ownHealthBar.width * ownHealthRatio,
            ownHealthBar.height
        };
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
        



        BeginDrawing(); 
        ClearBackground(BLACK); 
        DrawText(message1.c_str(), 50, 50, 25, BLUE); 
        DrawText(message2.c_str(), 450, 50, 25, BLUE); 
        DrawText("Damage", 50, 120, 25, BLUE); 
        DrawText("Damage", 450, 120, 25, BLUE); 
        DrawText("Health", 50, 180, 25, BLUE); 
        DrawText("Health", 450, 180, 25, BLUE); 
        DrawText("Defence", 50, 240, 25, BLUE); 
        DrawText("Defence", 450, 240, 25, BLUE); 
        //drawing rectangles
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
        
        if (!ownMessage.empty())
        DrawText(ownMessage.c_str(), 50, 400, 25, YELLOW);
        EndDrawing(); 

        if(ch->getHealth()<=0){
            CloseWindow();
            createFailureInterface(ch, atk);
            break;

        }

        if(atk->getHealth()<=0){
            CloseWindow();
            createSuccessInterface(ch, atk);
            break;

        } 

    } 
     
       
    } 


int main(){
    Battle battle;
    battle.setOwn();
    battle.setEnemy();
    

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
        DrawText(message1.c_str(), 65, 130, 40, GREEN);
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

