#include "FireMoves.h"
#include "Character.h"
#include "Attribute.h" // for typeMultiplier()
#include <cmath>
#include <algorithm>
//critical hit damage multiplier
constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage
//random hit check based on chance
static bool doesHit(double chance)
{
    // generate a random number between 0 and 100 and compare with chance
    if ((rand() % 101) <= (chance * 100))
        return true;
    else
        return false;
}

// ---------------- Fire Ball ----------------
FireBall::FireBall()
    : Ability("Fire Ball", Attribute::FIRE, 40, 0.60, "Deals 40 damage.") {}

bool FireBall::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        return false;
    }
//calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (atk * getDamage() / 100.0) - def;
//ensure damage is not negative
    if (raw < 0)
        raw = 10;
//apply type multiplier
    raw *= typeMultiplier(getType(), target.getType());

    // fireball does 1.5times damage to players health
    raw *= 1.5;
//check for critical hit
    bool crit = doesHit(user.getCritChance());
    //if critical hit, apply critical multiplier
    if (crit)
        raw *= CRIT_MULT;

    target.takeDamage(raw);
    return true;

}
// ---------------- Flame Burst ----------------
FlameBurst::FlameBurst()
    : Ability("Flame Burst", Attribute::FIRE, 80, 0.9, "Deals 80 damage.") {}

bool FlameBurst::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }


    // flame burst reduces opopnents health by 20%
    if(target.getHealth()<17)
        target.setHealth(0);
    else{
        double currHealth = target.getHealth();
        target.setHealth(currHealth*0.8);
    }
    return true;
}

// ---------------- Ember Storm ----------------
EmberStorm::EmberStorm()
    : Ability("Ember Storm", Attribute::FIRE, 70, 0.8, "Deals 70 damage.") {}

bool EmberStorm::use(Character &user, Character &target)
{
    // check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        return false;
    }
    // reduce oponents defence by 10%
    if(target.getDefence()<2)
        target.setDefence(0);
    else{
        double currDefence = target.getDefence();
        target.setHealth(currDefence*0.8);
    }
    user.setHealth(user.getHealth()+0);
    return true;

}

// ---------------- Infernal Slash ----------------
InfernalSlash::InfernalSlash()
    : Ability("Infernal Slash", Attribute::FIRE, 40, 0.95, "Deals 40 damage.") {}

bool InfernalSlash::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        return false;
    }
//calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 10;
//apply type multiplier
    raw *= typeMultiplier(getType(), target.getType());
//check for critical hit
    bool crit = doesHit(user.getCritChance());
    // increases cirictical damaghe
    if (crit)
    {
        // increase critical damage by 15%
        raw *= (CRIT_MULT + 0.15);
    }

    target.takeDamage(raw);
    return true;

}

// ---------------- Blaze kick----------------

BlazeKick::BlazeKick()
    : Ability("Blaze Kick", Attribute::FIRE, 20, 1, "Deals 20 damage.") {}

bool BlazeKick::use(Character &user, Character &target)
{
    // check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }

    // blaze kick reduces opopnets damage by 25%
    double currentAtk = target.getAttack();
    if(currentAtk<6)
    target.setAttack(0);
    else
    target.setAttack(currentAtk*0.75);
    return true;

}
