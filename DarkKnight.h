#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include "Dark.h"
//derived class for dark knight character which inherits from Dark class
class DarkKnight : public Dark {
public:
    // consturctor
    DarkKnight(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif