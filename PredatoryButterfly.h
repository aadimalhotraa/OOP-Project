#ifndef PREDATORYBUTTERFLY_H
#define PREDATORYBUTTERFLY_H

#include "Grass.h"
//derived class for predatory butterfly character which inherits from Grass class
class PredatoryButterfly : public Grass {
public:
    // constructor
    PredatoryButterfly(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif