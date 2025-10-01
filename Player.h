#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Fire.h"
#include "Water.h"
#include "Grass.h"
#include "Dark.h"
#include "Light.h"
#include <string>

class Player: public Character{
    private:
        std::string playerName;
        int kills;              // every 5 kills learn ability this variable is to keep track
    public:
        void levelUp();

};
#endif