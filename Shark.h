#ifndef SHARK_H
#define SHARK_H

#include "Water.h"

class Shark : public Water {
public:
    // constructor
    Shark(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif