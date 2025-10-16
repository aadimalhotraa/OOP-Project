#ifndef BATTLE_H
#define BATTLE_H

#include "raylib.h"
#include <string>

class Character;

class Battle {
public:
    Battle();
    ~Battle();

    // Attribute bucket selection UI (1..5 → random species @Lv1)
    Character* chooseCharacter();
    void setOwn();

    // Run Battle
    // Returns: 1 = player win, 0 = player loss, -1 = user quit (ESC/X).
    int runSpriteBattle(Character* player, const std::string& playerPng,
                        Character* foe,    const std::string& foePng);

    
    Character* createByIndex(int idx, int level);             // 0..9
    Character* createByName(const std::string& name, int level);
    static std::string nameToPng(const std::string& name);

private:
    Character* createRandomFromBucket(int bucket, int level); // 1..5
};

#endif