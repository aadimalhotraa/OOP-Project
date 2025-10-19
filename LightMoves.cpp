#include "LightMoves.h"
#include "Character.h"
#include "Attribute.h" // for typeMultiplier()
#include <cmath>
#include <algorithm>
//critical hit damage multiplier
constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage
//random hit check based on chance
static bool doesHit(double chance)
{
    //if chance is greater than random number return true
    if ((rand() % 101) <= (chance * 100))
        return true;
    else
        return false;
}

// ---------------- Holy Shield ----------------
//constructor implementation
//creates holy shield ability
HolyShield::HolyShield()
    : Ability("Holy Shield", Attribute::LIGHT, 20, 0.8, "A bash with consecrated light.") {}
//uses holy shield ability
void HolyShield::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    // increase defence by 10%
    double newDef = user.getDefence()*1.1;
    if(newDef >= (15+ (2 * user.getLevel())))
    return;
    else
    user.setDefence(newDef);
}

// ---------------- Sun Ray ----------------
//constructor implementation
SunRay::SunRay()
    : Ability("Sun Ray", Attribute::LIGHT, 30, 1.0, "A focused beam of sunlight.") {}
//uses sun ray ability
void SunRay::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
//calculate damage using users attack and targets defence
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;
//apply type multiplier
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    //if critical hit then multiply damage
    if (crit)
        raw *= CRIT_MULT;
//apply damage to target
    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
}

// ---------------- Radiant Beam ----------------
RadiantBeam::RadiantBeam()
    : Ability("Radiant Beam", Attribute::LIGHT, 50, 0.8, "A powerful blast of radiant energy.") {}
//uses radiant beam ability
void RadiantBeam::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    //increases health by 25%
    double newHealth = user.getHealth()*1.15;
    if(newHealth >= (150 + (10 * user.getLevel())))
        return;
    else
    user.setHealth(newHealth);
}

// ---------------- Purify ----------------
Purify::Purify()
    : Ability("Purify", Attribute::LIGHT, 0, 1.0, "A cleansing light that purifies evil.") {}
//uses purify ability
void Purify::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << "'s " << getName() << " failed.\n";
        return;
    }

    // damages target by 30% of their current health
    double maxHealth = target.getHealth();
    target.setHealth(maxHealth*0.70);
}
// ---------------- ElectricWings ----------------
//constructor implementation
ElectricWings::ElectricWings()
    : Ability("Electric Wings", Attribute::LIGHT, 15, 1.0, "Strikes with electrified wings.") {}
    //uses electric wings ability
void ElectricWings::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    //calculate damage by using users attack and targets defence
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    //if raw damage is less than 0 set it to 0
    if (raw < 0)
        raw = 0;
        //point multiplier based on type effectiveness
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;
    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
}
