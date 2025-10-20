#ifndef DEMON_H
#define DEMON_H

#include "Dark.h"

class Demon : public Dark {
public:
    // constructor
    Demon(int level);

    // member functions
    void levelUp() override;
    //defined in Demon.cpp
    void setStats(int level) override;
};
#endif