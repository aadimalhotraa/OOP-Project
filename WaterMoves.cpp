#include "WaterMoves.h"
#include "Character.h"
#include "Attribute.h"   // for typeMultiplier()
#include <cmath>
#include <algorithm>

constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage


static bool doesHit(double chance) {
    if((rand() % 101) <= (chance * 100))
    return true;
    else
    return false;
}

// ---------------- Water Slide ----------------
WaterSlide::WaterSlide()
    : Ability("Water Slide", Attribute::WATER, 40, 1.0, "A fast sliding water attack.") {}

void WaterSlide::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage()/100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " unleashed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Puddle ----------------
Puddle::Puddle()
    : Ability("Puddle", Attribute::WATER, 30, 0.7, "A sloppy splash of water.") {}

void Puddle::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage()/100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " splashed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Tiddle Wave ----------------
TiddleWave::TiddleWave()
    : Ability("Tiddle Wave", Attribute::WATER, 40, 0.6, "A small but strong tidal wave.") {}

void TiddleWave::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage()/100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " summoned " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Aqua Whip ----------------
AquaWhip::AquaWhip()
    : Ability("Aqua Whip", Attribute::WATER, 90, 1.0, "A furious lash of water.") {}

void AquaWhip::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage()/100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " struck with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}