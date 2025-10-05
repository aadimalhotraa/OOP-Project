#ifndef ROCKTURTLE_H
#define ROCKTURTLE_H

#include "Grass.h"

class RockTurtle : public Grass {
public:
    RockTurtle(int level);

    void levelUp() override;
};

#endif