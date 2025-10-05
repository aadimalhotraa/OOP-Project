#include "LightMoves.h"
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

// ---------------- Holy Shield ----------------
HolyShield::HolyShield()
    : Ability("Holy Shield", Attribute::LIGHT, 20, 0.8, "A bash with consecrated light.") {}

void HolyShield::use(Character& user, Character& target) {
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

    std::cout << user.getName() << " struck with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Sun Ray ----------------
SunRay::SunRay()
    : Ability("Sun Ray", Attribute::LIGHT, 30, 1.0, "A focused beam of sunlight.") {}

void SunRay::use(Character& user, Character& target) {
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

    std::cout << user.getName() << " fired " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Radiant Beam ----------------
RadiantBeam::RadiantBeam()
    : Ability("Radiant Beam", Attribute::LIGHT, 50, 0.8, "A powerful blast of radiant energy.") {}

void RadiantBeam::use(Character& user, Character& target) {
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

// ---------------- Purify ----------------
Purify::Purify()
    : Ability("Purify", Attribute::LIGHT, 0, 1.0, "A cleansing light that purifies evil.") {}

void Purify::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << "'s " << getName() << " failed.\n";
        return;
    }

    // Currently no damage; could be healing or debuff later
    std::cout << user.getName() << " used " << getName()
              << " on " << target.getName()
              << "! " << target.getName() << " is surrounded by purifying light!\n";
}