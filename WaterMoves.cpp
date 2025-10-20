#include "WaterMoves.h"
#include "Character.h"
#include "Attribute.h" // for typeMultiplier()
#include <cmath>
#include <algorithm>
constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage
// Helper function to determine if an attack hits based on chance
static bool doesHit(double chance)
{
    // Generate a random number between 0 and 100 and compare to chance
    if ((rand() % 101) <= (chance * 100))
        return true;
    else
        return false;
}

// ---------------- Water Slide ----------------
// Constructor
WaterSlide::WaterSlide()
    : Ability("Water Slide", Attribute::WATER, 40, 1.0, "A fast sliding water attack.") {}

bool WaterSlide::use(Character &user, Character &target)
{
    // Check if the attack hits
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }
// Calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;
// Apply type multiplier and check for critical hit
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;
// Round damage to nearest integer and apply to target
    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    return true;
}

// ---------------- Puddle ----------------
// Constructor
Puddle::Puddle()
    : Ability("Puddle", Attribute::WATER, 30, 0.7, "A sloppy splash of water.") {}

bool Puddle::use(Character &user, Character &target)
{
    // Check if the attack hits
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }
    // puddle reeduces opoents defence by 15%
    double currentDefence = target.getDefence();
    target.setSpeed(currentDefence*0.85);
    return true;
}

// ---------------- Tiddle Wave ----------------
// Constructor
TiddleWave::TiddleWave()
    : Ability("Tiddle Wave", Attribute::WATER, 40, 0.6, "A small but strong tidal wave.") {}

bool TiddleWave::use(Character &user, Character &target)
{
    // Check if the attack hits
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }

    // self heals by 25 percent of current health
    double newHealth = user.getHealth()*1.25;
    if(newHealth >= (150 + (10 * user.getLevel())))
        return false;
    else{
    user.setHealth(newHealth);
    return true;
    }
}

// ---------------- Aqua Whip ----------------
// Constructor
AquaWhip::AquaWhip()
    : Ability("Aqua Whip", Attribute::WATER, 90, 1.0, "A furious lash of water.") {}

bool AquaWhip::use(Character &user, Character &target)
{
    // Check if the attack hits
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return true;
    }
// Calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;
// Apply type multiplier and check for critical hit
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;
// Round damage to nearest integer and apply to target
     int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    return true;
}
// ---------------- Hydrocanon ----------------
// Constructor
HydroCannon::HydroCannon()
    : Ability("Hydrocannon", Attribute::WATER, 25, 1.0, "A massive cannon of water.") {}
bool HydroCannon::use(Character &user, Character &target)
{
    // Check if the attack hits
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return true;
    }
    // hydrocannon  reduces oppoents health and defence by 10%
    double currHealth = target.getHealth();
    if(currHealth<10)
    target.setHealth(0);
    else
    target.setHealth(currHealth*0.9);

    // reducing defence
    double currentDef = target.getDefence();
    if(currentDef<2.5)
    target.setDefence(0);
    else
    target.setDefence(currentDef*0.9);
    return true;
};