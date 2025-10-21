#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>
#include <vector>
#include <fstream>

class Battle;

// Scoreboard class to manage high scores
class Scoreboard {
public:
// Constructor
Scoreboard();
//inputs the name of the user
std::string getName();
//writes the user info into the file
void writeInfo(std::string userName, int userLevel);
// Display the scoreboard
void displayScoreboard();
~Scoreboard();
private:
std::fstream file;
std::vector<std::string> information;
Battle* fight;

};
#endif