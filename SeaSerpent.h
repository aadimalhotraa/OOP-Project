#ifndef SEASERPENT_H
#define SEASERPENT_H

#include "Water.h"

class SeaSerpent : public Water {
    public:
        SeaSerpent(int level);

        void levelUp() override;
};

#endif