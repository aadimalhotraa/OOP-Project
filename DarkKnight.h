#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include "Dark.h"

class DarkKnight : public Dark {
public:
    DarkKnight(int level);
    
    void levelUp() override;
};
#endif