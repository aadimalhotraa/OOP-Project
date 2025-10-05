#ifndef PREDATORYBUTTERFLY_H
#define PREDATORYBUTTERFLY_H

#include "Grass.h"
class PredatoryButterfly : public Grass {
public:
    PredatoryButterfly(int level);

    void levelUp() override;
};

#endif