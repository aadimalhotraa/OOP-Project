#ifndef SEASERPENT_H
#define SEASERPENT_H

#include "Water.h"

class SeaSerpent : public Water {
public:
    // constructor
    SeaSerpent(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif