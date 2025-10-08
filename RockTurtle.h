#ifndef ROCKTURTLE_H
#define ROCKTURTLE_H

#include "Grass.h"

class RockTurtle : public Grass {
public:
    // constructor
    RockTurtle(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif