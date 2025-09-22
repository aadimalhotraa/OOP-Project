#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Ability.h"
#include <string>

class Player: public Character{
    private:
        std::string playerName;
    public:
        void levelUp();


};
#endif