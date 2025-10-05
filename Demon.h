#ifndef DEMON_H
#define DEMON_H

#include "Dark.h"

class Demon : public Dark {
public:
    Demon(int level);
    void levelUp() override;
};
#endif