#include "DarkMoves.h"
#include "Character.h"
#include "Attribute.h"   // for typeMultiplier()
#include <cmath>
#include <algorithm>

constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage

static bool doesHit(double chance) {
    if ((rand() % 101) <= (chance * 100))
        return true;
    else
        return false;
}

// ---------------- Shadow Strike ----------------
ShadowStrike::ShadowStrike()
    : Ability("Shadow strike", Attribute::DARK, 40, 1.0, "A precise strike from the shadows.") {}

void ShadowStrike::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " struck from the shadows with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Void Pulse ----------------
VoidPulse::VoidPulse()
    : Ability("Void pulse", Attribute::DARK, 80, 0.7, "A heavy pulse of void energy.") {}

void VoidPulse::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " unleashed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Night Claw ----------------
NightClaw::NightClaw()
    : Ability("Night claw", Attribute::DARK, 30, 0.8, "A swift tearing slash.") {}

void NightClaw::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " slashed with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Sneak Attack ----------------
SneakAttack::SneakAttack()
    : Ability("Sneak attack", Attribute::DARK, 40, 1.0, "A well-timed ambush.") {}

void SneakAttack::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0) raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " performed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}