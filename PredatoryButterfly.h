#ifndef PREDATORYBUTTERFLY_H
#define PREDATORYBUTTERFLY_H

#include "Grass.h"

class PredatoryButterfly : public Grass {
public:
    // constructor
    PredatoryButterfly(int level);

    // member functions
    void levelUp() override;
    void setStats(int level) override;
};
#endif