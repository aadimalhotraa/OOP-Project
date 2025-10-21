#include "Scoreboard.h"
#include "raylib.h"
#include <algorithm>
#include "Battle.h"

Scoreboard::Scoreboard(){
    
}

std::string Scoreboard::getName(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Enter Your Name - OOPMON");
    SetTargetFPS(60);

    std::string playerName = "";
    const int maxChars = 20;  // limit to prevent overly long names

    while (!WindowShouldClose()) {
        // --- Handle character input ---
        int key = GetCharPressed();
        while (key > 0) {
            // Allow letters, digits, punctuation, and spaces
            if (((key >= 32 && key <= 125)) && playerName.length() < maxChars) {
                playerName += (char)key;
            }
            key = GetCharPressed();
        }

        // Handle backspace (delete last character)
        if (IsKeyPressed(KEY_BACKSPACE) && !playerName.empty()) {
            playerName.pop_back();
        }

        // Press ENTER to confirm name
        if (IsKeyPressed(KEY_ENTER) && !playerName.empty()) {
            break;  // exit input loop
        }

        // --- Drawing ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Enter your name:", 200, 150, 30, DARKGRAY);
        DrawText(playerName.c_str(), 200, 200, 40, BLUE);
        DrawText("(Press ENTER to confirm)", 200, 260, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return playerName;
}

void Scoreboard::writeInfo(std::string userName, int userLevel) {
    std::ofstream file("Scoreboard.txt", std::ios::app);
    if (file.is_open()) {
        file << userName << ":" << userLevel << std::endl;
        file.close();
        std::cout << "Wrote to file: " << userName << ":" << userLevel << std::endl;
    } else {
        std::cout << "Could not open Scoreboard.txt\n";
    }
}



void Scoreboard::displayScoreboard() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "OOPMON - Scoreboard");
    SetTargetFPS(60);

    //Read file
    std::ifstream file("Scoreboard.txt");
    std::vector<std::pair <std::string, int> > scores;
    std::string line;

    while (std::getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string name = line.substr(0, pos);
            try {
                int level = std::stoi(line.substr(pos + 1));
                scores.push_back({name, level});
            } catch (...) {
                std::cerr << "FAIL!!to parse level for line: " << line << std::endl;
            }
        }
    }
    

    // Sort in descending order
    std::sort(scores.begin(), scores.end(),
          [](const auto &a, const auto &b) { return a.second > b.second; });

    file.close();

    // Draw scoreboard 
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)){
            fight->chooseCharacter();
            break;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("TOP SCORES", 300, 40, 30, DARKGRAY);
        if (IsKeyPressed(KEY_ENTER)){
            fight->executeBattle(fight->own,fight->enemy);
        }

        int y = 100;
        int rank = 1;
        for (auto &entry : scores) {
            std::string line = std::to_string(rank) + ". " + entry.first + " - " + std::to_string(entry.second);
            DrawText(line.c_str(), 250, y, 25, BLUE);
            y += 30;
            if (++rank > 10) break; // show top 10 only
        }

        DrawText("(Press ESC to return)", 280, 400, 20, GRAY);
        EndDrawing();
    }

    CloseWindow();
}



Scoreboard::~Scoreboard(){
    file.close();
}
