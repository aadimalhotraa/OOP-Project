#include "Battle.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>


Battle::Battle() { std::srand((unsigned)std::time(nullptr)); }
Battle::~Battle() {}

// ---------- helpers: normalize names & build asset path ----------
static std::string NormalizeName(const std::string& s) {
    std::string out; out.reserve(s.size());
    for (unsigned char ch : s) if (std::isalnum(ch)) out.push_back((char)ch);
    return out; // e.g. "Sea Serpent" -> "SeaSerpent"
}
std::string Battle::nameToPng(const std::string& n) {
    return "assets/" + NormalizeName(n) + ".png";
}

// ---------- factories ----------
Character* Battle::createByIndex(int idx, int level) {
    switch (idx) {
        case 0: return new RockTurtle(level);
        case 1: return new PredatoryButterfly(level);
        case 2: return new ThunderBat(level);
        case 3: return new LuminousAngel(level);
        case 4: return new Demon(level);
        case 5: return new DarkKnight(level);
        case 6: return new FireFox(level);
        case 7: return new LavaLion(level);
        case 8: return new Shark(level);
        case 9: return new SeaSerpent(level);
        default: return nullptr;
    }
}
Character* Battle::createByName(const std::string& n, int level) {
    std::string key = NormalizeName(n);
    if (key=="RockTurtle")         return new RockTurtle(level);
    if (key=="PredatoryButterfly") return new PredatoryButterfly(level);
    if (key=="ThunderBat")         return new ThunderBat(level);
    if (key=="LuminousAngel")      return new LuminousAngel(level);
    if (key=="Demon")              return new Demon(level);
    if (key=="DarkKnight")         return new DarkKnight(level);
    if (key=="FireFox")            return new FireFox(level);
    if (key=="LavaLion")           return new LavaLion(level);
    if (key=="Shark")              return new Shark(level);
    if (key=="SeaSerpent")         return new SeaSerpent(level);
    return nullptr;
}

// bucket: 1=Grass, 2=Light, 3=Dark, 4=Fire, 5=Water
static inline int coin(){ return std::rand() & 1; }
Character* Battle::createRandomFromBucket(int bucket, int level) {
    switch (bucket) {
        case 1: return coin()? (Character*)new RockTurtle(level)        : new PredatoryButterfly(level);
        case 2: return coin()? (Character*)new ThunderBat(level)        : new LuminousAngel(level);
        case 3: return coin()? (Character*)new Demon(level)             : new DarkKnight(level);
        case 4: return coin()? (Character*)new FireFox(level)           : new LavaLion(level);
        case 5: return coin()? (Character*)new Shark(level)             : new SeaSerpent(level);
        default: return nullptr;
    }
}

// ---------- selection UI ----------
Character* Battle::chooseCharacter() {
    const int W=800, H=450;
    InitWindow(W, H, "OOPMON - Choose Attribute");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ONE)   || IsKeyPressed(KEY_KP_1)) { auto p=createRandomFromBucket(1,1); CloseWindow(); return p; }
        if (IsKeyPressed(KEY_TWO)   || IsKeyPressed(KEY_KP_2)) { auto p=createRandomFromBucket(2,1); CloseWindow(); return p; }
        if (IsKeyPressed(KEY_THREE) || IsKeyPressed(KEY_KP_3)) { auto p=createRandomFromBucket(3,1); CloseWindow(); return p; }
        if (IsKeyPressed(KEY_FOUR)  || IsKeyPressed(KEY_KP_4)) { auto p=createRandomFromBucket(4,1); CloseWindow(); return p; }
        if (IsKeyPressed(KEY_FIVE)  || IsKeyPressed(KEY_KP_5)) { auto p=createRandomFromBucket(5,1); CloseWindow(); return p; }

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawText("Choose the attribute of your character:", 65, 60, 35, BLUE);
        DrawText("1. Grass", 80, 140, 26, DARKPURPLE);
        DrawText("2. Light", 80, 175, 26, DARKPURPLE);
        DrawText("3. Dark",  80, 210, 26, DARKPURPLE);
        DrawText("4. Fire",  80, 245, 26, DARKPURPLE);
        DrawText("5. Water", 80, 280, 26, DARKPURPLE);
        DrawText("ESC to quit", 80, 320, 20, DARKGRAY);
        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE)) { CloseWindow(); return nullptr; }
    }
    CloseWindow();
    return nullptr;
}

void Battle::setOwn() {} // not used

// ---------- interactive battle ----------
int Battle::runSpriteBattle(Character* player, const std::string& playerPng,
                            Character* foe,    const std::string& foePng)
{
    const int W = 1280, H = 720;
    InitWindow(W, H, "OOPMON - Battle");
    SetTargetFPS(60);

    Texture2D texP = LoadTexture(playerPng.c_str());
    Texture2D texE = LoadTexture(foePng.c_str());
    if (texP.width <= 0) TraceLog(LOG_WARNING, "Failed to load player texture: %s", playerPng.c_str());
    if (texE.width <= 0) TraceLog(LOG_WARNING, "Failed to load enemy texture: %s", foePng.c_str());
    GenTextureMipmaps(&texP); SetTextureFilter(texP, TEXTURE_FILTER_TRILINEAR);
    GenTextureMipmaps(&texE); SetTextureFilter(texE, TEXTURE_FILTER_TRILINEAR);

    Vector2 posP{ 320.f, 520.f }, posE{ 960.f, 450.f }; // enemy location
    auto scaleFor = [](Texture2D t, float targetH){ return (t.height>0) ? targetH/(float)t.height : 1.f; };
    float sP = scaleFor(texP, 300.f);
    float sE = scaleFor(texE, 300.f);

    const double startHP_P = player->getHealth();
    const double startHP_E = foe->getHealth();

    auto drawBar = [](double hp, double startHp, float x, float y, float W, float H){
        DrawRectangleRounded({x,y,W,H},0.35f,8, Color{0,0,0,140});
        double t = (startHp > 0.0) ? hp / startHp : 0.0;
        if (t < 0.0) { t = 0.0; }
        if (t > 1.0) { t = 1.0; }
        unsigned char r = (unsigned char)(255*(1.0 - t));
        unsigned char g = (unsigned char)(255*(t));
        DrawRectangleRounded({x+3,y+3,(float)((W-6)*t),H-6},0.35f,8, Color{r,g,64,220});
    };

    auto enemyMoveIndex = [](const Character* c)->int {
        const auto& mv = c->getAbilities();
        if (mv.empty()) return -1;
        return std::rand() % (int)mv.size();
    };

    // tiny message log (last 4 lines)
    std::deque<std::string> log;
    auto addMsg = [&](const std::string& s){
        log.push_back(s);
        if (log.size() > 4) log.pop_front();
    };
    addMsg("A wild " + foe->getName() + " appeared!");

    // one action (adds up to 3 lines)
    auto doMove = [&](Character* attacker, Character* target, int moveIndex){
        auto& move = attacker->getAbilities()[moveIndex];

        addMsg(attacker->getName() + std::string(" used ") + move->getName() + "!");
        double before = target->getHealth();
        move->use(*attacker, *target);
        double diff = before - target->getHealth();

        if (target->getHealth() <= 0.0) {
            addMsg("It dealt " + std::to_string((int)std::round(std::max(0.0, diff))) + " damage.");
            addMsg(target->getName() + " fainted!");
        } else if (diff <= 0.1) {
            addMsg("It missed!");
        } else {
            addMsg("It dealt " + std::to_string((int)std::round(diff)) + " damage.");
        }
    };

    // key arrays to support up to 4 moves (uses 1–4 and KP_1–KP_4)
    const KeyboardKey topKeys[4] = { KEY_ONE, KEY_TWO, KEY_THREE, KEY_FOUR };
    const KeyboardKey kpKeys[4]  = { KEY_KP_1, KEY_KP_2, KEY_KP_3, KEY_KP_4 };

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ESCAPE)) { UnloadTexture(texP); UnloadTexture(texE); CloseWindow(); return -1; }

        // ----- draw -----
        BeginDrawing();
        ClearBackground(Color{30,36,46,255});
        DrawRectangle(0, 560, W, 160, Color{25,110,80,255});

        // sprites
        Rectangle srcP{0,0,(float)texP.width,(float)texP.height};
        Rectangle dstP{posP.x,posP.y,texP.width*sP,texP.height*sP};
        Vector2   orgP{dstP.width*0.5f,dstP.height};
        DrawTexturePro(texP, srcP, dstP, orgP, 0, WHITE);
        DrawEllipse((int)posP.x,(int)posP.y+8,(int)(dstP.width*0.35f),12,Color{0,0,0,60});

        Rectangle srcE{0,0,-(float)texE.width,(float)texE.height};
        Rectangle dstE{posE.x,posE.y,texE.width*sE,texE.height*sE};
        Vector2   orgE{dstE.width*0.5f,dstE.height};
        DrawTexturePro(texE, srcE, dstE, orgE, 0, WHITE);
        DrawEllipse((int)posE.x,(int)posE.y+8,(int)(dstE.width*0.35f),12,Color{0,0,0,60});

        // names + HP bars
        DrawText(player->getName().c_str(), 40, 40, 28, RAYWHITE);
        drawBar(player->getHealth(), startHP_P, 40, 80, 360, 22);
        DrawText(foe->getName().c_str(), W-420, 40, 28, RAYWHITE);
        drawBar(foe->getHealth(), startHP_E, W-420, 80, 360, 22);

        // message log (last up to 4 lines)
        int y = H - 180;
        for (const auto& line : log) {
                int textWidth = MeasureText(line.c_str(), 22);
                int x = W - textWidth - 60; // 60-pixel padding from right edge
                DrawText(line.c_str(), x, y, 22, YELLOW);
                y += 24;
            }

        // move list
        const auto& myMoves = player->getAbilities();
        DrawText("Choose your move:", 40, H-140, 24, SKYBLUE);
        int baseY = H - 110;
        for (int i = 0; i < (int)myMoves.size() && i < 4; ++i) {
            DrawText(TextFormat("%d) %s", i+1, myMoves[i]->getName().c_str()),
                     60, baseY + i*26, 22, RAYWHITE);
        }
        DrawText("Press 1 2 3 | ESC quits", 40, H-30, 20, LIGHTGRAY);
        EndDrawing();

        // ----- input -> resolve one full turn -----
        int chosen = -1;
        for (int i = 0; i < (int)myMoves.size() && i < 4; ++i) {
            if (IsKeyPressed(topKeys[i]) || IsKeyPressed(kpKeys[i])) { chosen = i; break; }
        }
        if (chosen < 0) continue; // wait for valid key

        bool playerFirst = (player->getSpeed() > foe->getSpeed());
        if (player->getSpeed() == foe->getSpeed()) playerFirst = (std::rand() & 1);

        if (playerFirst) {
            doMove(player, foe, chosen);
            if (foe->getHealth() <= 0.0) { UnloadTexture(texP); UnloadTexture(texE); CloseWindow(); return 1; }
            int em = enemyMoveIndex(foe);
            if (em >= 0) doMove(foe, player, em);
            if (player->getHealth() <= 0.0) { UnloadTexture(texP); UnloadTexture(texE); CloseWindow(); return 0; }
        } else {
            int em = enemyMoveIndex(foe);
            if (em >= 0) doMove(foe, player, em);
            if (player->getHealth() <= 0.0) { UnloadTexture(texP); UnloadTexture(texE); CloseWindow(); return 0; }
            doMove(player, foe, chosen);
            if (foe->getHealth() <= 0.0) { UnloadTexture(texP); UnloadTexture(texE); CloseWindow(); return 1; }
        }
        // loop continues for next turn
    }

    // window X
    UnloadTexture(texP);
    UnloadTexture(texE);
    CloseWindow();
    return -1;
}