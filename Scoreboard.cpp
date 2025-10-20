#include "Scoreboard.h"
#include "raylib.h"
#include <algorithm>

Scoreboard::Scoreboard(){
    //function loads scores when the scoreboard is created
}

void Scoreboard::updateScore(const std::string& playerName, const std::string& charName, int win, int loss, int Level) {
    //these lines check if a player exsits or not
    for(int i = 0; i < (int)playerNames.size();i++){
        if(playerNames[i] == playerName) {
            //updates attributes beklow to specific player
            wins[i] = win;
            losses[i] = loss;
            Levels[i] = Level;
            charNames[i] = charName;
            //saves to file
            //saveScores();
            return;
        }
    }
//adds new player if certin player doesnt exist
playerNames.push_back(playerName);
charNames.push_back(charName);
wins.push_back(win);
losses.push_back(loss);
Levels.push_back(Level);
//saveScores();
}

void Scoreboard::displayScoreboard() const {
     //intialise the size of the window
    const int screenWidth = 800;
    const int screenHeight = 450;
    //creating scoreboard window
    InitWindow(screenWidth,screenHeight,"OOPMON - Scoreboard");
    //set fram rate
    SetTargetFPS(60);
    //keep window unil key is pressed
    while(! WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        // title of the scoreboard
        DrawText("SCOREBOARD",280,30,40,YELLOW);
        //headers foir column for data tbalke 
        DrawText("Player", 50, 100, 25, BLUE); 
        DrawText("Character", 200, 100, 25, BLUE); 
        DrawText("Wins", 400, 100, 25, BLUE); 
        DrawText("losses", 500, 100, 25, BLUE); 
        DrawText("level", 600, 100, 25, BLUE); 
        //player data rows
        int y = 140;
        for(int i = 0; i < (int)playerNames.size() && i < 5; i++) {
            //show up to 5 players
            //player names
            DrawText(playerNames[i].c_str(),50,y,20,WHITE);
            //charactyer names
            DrawText(charNames[i].c_str(),250,y,20,WHITE);
            //Wins
            DrawText(TextFormat("%d",wins[i]),450,y,20,GREEN);
            //losses
            DrawText(TextFormat("%d",losses[i]),550,y,20,RED);
            //level
            DrawText(TextFormat("%d",Levels[i]),450,y,20,BLUE);
            //move next row
            y += 40;
            
        }
        //Draw instructions to close score
            DrawText("press any key to close",250,350,25,WHITE);

            EndDrawing();
            //exit if key is pressed
            if (GetKeyPressed() != 0) break;
    }
    //close 
    CloseWindow();

}

