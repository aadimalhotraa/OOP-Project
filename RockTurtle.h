#ifndef ROCKTURTLE_H
#define ROCKTURTLE_H

#include "Grass.h"
//derived class for rock turtle character which inherits from Grass class
class RockTurtle : public Grass {
public:
    // constructor
    RockTurtle(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif