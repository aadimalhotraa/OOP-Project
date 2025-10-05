#ifndef SHARK_H
#define SHARK_H

#include "Water.h"

class Shark : public Water {
public:
    Shark(int level);

    void levelUp() override;
};

#endif