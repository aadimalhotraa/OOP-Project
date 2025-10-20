#include "FireMoves.h"
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

// ---------------- Fire Ball ----------------
FireBall::FireBall()
    : Ability("Fire Ball", Attribute::FIRE, 40, 0.95, "A blazing fireball.") {}

bool FireBall::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!" << std::endl;
        return false;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (atk * getDamage() / 100.0) - def;

    if (raw < 0)
        raw = 0;

    raw *= typeMultiplier(getType(), target.getType());

    // fireball does 1.5times damage to players health
    raw *= 1.5;

    bool crit = doesHit(user.getCritChance());
    if (crit)
        raw *= CRIT_MULT;

    target.takeDamage(raw);
    return true;

}
// ---------------- Flame Burst ----------------
FlameBurst::FlameBurst()
    : Ability("Flame Burst", Attribute::FIRE, 80, 0.9, "A powerful explosion of flame.") {}

bool FlameBurst::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }


    // flame burst reduces opopnents health by 20%
    if(target.getHealth()<10)
        target.setHealth(0);
    else{
        double currHealth = target.getHealth() * 0.2;
        target.setHealth(currHealth*0.8);
    }
    return true;
}

// ---------------- Ember Storm ----------------
EmberStorm::EmberStorm()
    : Ability("Ember Storm", Attribute::FIRE, 70, 0.8, "A storm of burning embers.") {}

bool EmberStorm::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }
    // reduce oponents defence by 10%
    double currentDef = target.getDefence();
    target.setDefence( currentDef*0.90);
    return true;

}

// ---------------- Infernal Slash ----------------
InfernalSlash::InfernalSlash()
    : Ability("Infernal Slash", Attribute::FIRE, 40, 0.95, "A flaming blade attack.") {}

bool InfernalSlash::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;

    raw *= typeMultiplier(getType(), target.getType());

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
    : Ability("Blaze Kick", Attribute::FIRE, 20, 1, "A fiery kick attack.") {}

bool BlazeKick::use(Character &user, Character &target)
{
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }

    // blaze kick reduces opopnets damage by 25%
    double currentAtk = target.getAttack();
    target.setAttack(currentAtk*0.75);
    return true;

}
