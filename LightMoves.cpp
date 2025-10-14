#include "LightMoves.h"
#include "Character.h"
#include "Attribute.h" // for typeMultiplier()
#include <cmath>
#include <algorithm>

constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage

static bool doesHit(double chance)
{
    if ((rand() % 101) <= (chance * 100))
        return true;
    else
        return false;
}

// ---------------- Holy Shield ----------------
HolyShield::HolyShield()
    : Ability("Holy Shield", Attribute::LIGHT, 20, 0.8, "A bash with consecrated light.") {}

void HolyShield::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    // holysheild self heals  and increases defense by 10%
    double maxHealth = user.getHealth();
    double healAmount = maxHealth * 0.1;
    user.takeDamage(-healAmount); // healing by negative damage
    // increase defence by 10%
    double currentDef = user.getDefence();
    double defIncrease = currentDef * 0.1;
    user.setDefence(currentDef + defIncrease);

    std::cout << user.getName() << " struck with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << user.getName() << " healed for " << healAmount << " health and increased defence by " << defIncrease << "!\n";
}

// ---------------- Sun Ray ----------------
SunRay::SunRay()
    : Ability("Sun Ray", Attribute::LIGHT, 30, 1.0, "A focused beam of sunlight.") {}

void SunRay::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " fired " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Radiant Beam ----------------
RadiantBeam::RadiantBeam()
    : Ability("Radiant Beam", Attribute::LIGHT, 50, 0.8, "A powerful blast of radiant energy.") {}

void RadiantBeam::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;

    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);

    std::cout << user.getName() << " unleashed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Purify ----------------
Purify::Purify()
    : Ability("Purify", Attribute::LIGHT, 0, 1.0, "A cleansing light that purifies evil.") {}

void Purify::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << "'s " << getName() << " failed.\n";
        return;
    }

    // Currently no damage; could be healing or debuff later
    // heals target by 30% of their max health
    double maxHealth = target.getHealth();
    double healAmount = maxHealth * 0.3;
    target.takeDamage(-healAmount); // healing by negative damage
    std::cout << user.getName() << " used " << getName()
              << " on " << target.getName()
              << "! " << target.getName() << " is surrounded by purifying light!\n";
    std::cout << target.getName() << " healed for " << healAmount << " health!\n";
}
// ---------------- ElectricWings ----------------
ElectricWings::ElectricWings()
    : Ability("Electric Wings", Attribute::LIGHT, 15, 1.0, "Strikes with electrified wings.") {}
void ElectricWings::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;
    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    // electric wings slows the opponent speed by 10%
    int currentSpeed = target.getSpeed();
    double speedReduction = currentSpeed * 0.1;
    target.setSpeed(currentSpeed - speedReduction);
    std::cout << user.getName() << " struck with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s speed is reduced by " << speedReduction << "\n";
}
