#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>
#include <vector>
#include <fstream>

// Scoreboard class to manage high scores
class Scoreboard {
private:
//all the vectors store relevent information about the player
    std::vector<std::string> playerNames;
    std::vector<std::string>  charNames;
    std::vector<int> wins;
    std::vector<int> losses;
    std::vector<int> Levels;
public:
// Constructor
Scoreboard();
//updtate score which adds new entry or updates existing one
void updateScore(const std::string& playerName, const std::string& charName, int wins, int losses, int level);
// Display the scoreboard
void displayScoreboard() const;
// Helper functions to load and save scores
//void loadScores();
//void saveScores() const;
//double winRate(int win, int loss) const;
};
#endif