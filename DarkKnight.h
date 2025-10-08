#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include "Dark.h"

class DarkKnight : public Dark {
public:
    // consturctor
    DarkKnight(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif