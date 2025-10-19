#ifndef SEASERPENT_H
#define SEASERPENT_H

#include "Water.h"
//derived class for sea serpent character which inherits from Water class
class SeaSerpent : public Water {
public:
    // constructor
    SeaSerpent(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif