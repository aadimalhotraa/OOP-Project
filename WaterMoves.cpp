#include "WaterMoves.h"
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

// ---------------- Water Slide ----------------
WaterSlide::WaterSlide()
    : Ability("Water Slide", Attribute::WATER, 40, 1.0, "A fast sliding water attack.") {}

void WaterSlide::use(Character &user, Character &target)
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
}

// ---------------- Puddle ----------------
Puddle::Puddle()
    : Ability("Puddle", Attribute::WATER, 30, 0.7, "A sloppy splash of water.") {}

void Puddle::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    // puddle reeduces opoents defence by 15%
    double currentDefence = target.getDefence();
    target.setSpeed(currentDefence*0.85);
}

// ---------------- Tiddle Wave ----------------
TiddleWave::TiddleWave()
    : Ability("Tiddle Wave", Attribute::WATER, 40, 0.6, "A small but strong tidal wave.") {}

void TiddleWave::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    // self heals by 25 percent of current health
    double newHealth = user.getHealth()*1.25;
    if(newHealth >= (150 + (10 * user.getLevel())))
        return;
    else
    user.setHealth(newHealth);
}

// ---------------- Aqua Whip ----------------
AquaWhip::AquaWhip()
    : Ability("Aqua Whip", Attribute::WATER, 90, 1.0, "A furious lash of water.") {}

void AquaWhip::use(Character &user, Character &target)
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

     int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
}
// ---------------- Hydrocanon ----------------
HydroCannon::HydroCannon()
    : Ability("Hydrocannon", Attribute::WATER, 25, 1.0, "A massive cannon of water.") {}
void HydroCannon::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    // hydrocannon  reduces oppoents health and defence by 10%
    
    double currHealth = target.getHealth();
    if(currHealth<10)
    target.setHealth(0);
    else
    target.setHealth(currHealth*0.9);

    
    double currentDef = target.getDefence();
    if(currentDef<2.5)
    target.setDefence(0);
    else
    target.setDefence(currentDef*0.9);
};