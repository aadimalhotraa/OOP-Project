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
    : Ability("Fire Ball", Attribute::FIRE, 40, 0.95, "A blazing fireball.") {}
//uses fire ball ability
void FireBall::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        //print miss message
        std::cout << user.getName() << " missed " << getName() << "!" << std::endl;
        return;
    }
//calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (atk * getDamage() / 100.0) - def;
//ensure damage is not negative
    if (raw < 0)
        raw = 0;
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

}
// ---------------- Flame Burst ----------------
FlameBurst::FlameBurst()
    : Ability("Flame Burst", Attribute::FIRE, 80, 0.9, "A powerful explosion of flame.") {}
//flame burst ability implementation
void FlameBurst::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }


    // flame burst reduces opopnents health by 20%
    if(target.getHealth()<10)
        target.setHealth(0);
    else{
        double currHealth = target.getHealth() * 0.2;
        target.setHealth(currHealth*0.8);
    }
}

// ---------------- Ember Storm ----------------
EmberStorm::EmberStorm()
    : Ability("Ember Storm", Attribute::FIRE, 70, 0.8, "A storm of burning embers.") {}
//uses ember storm ability
void EmberStorm::use(Character &user, Character &target)
{
    // check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    // reduce oponents defence by 10%
    double currentDef = target.getDefence();
    target.setDefence( currentDef*0.90);

}

// ---------------- Infernal Slash ----------------
InfernalSlash::InfernalSlash()
    : Ability("Infernal Slash", Attribute::FIRE, 40, 0.95, "A flaming blade attack.") {}
//uses infernal slash ability
void InfernalSlash::use(Character &user, Character &target)
{
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
//calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0)
        raw = 0;
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

}

// ---------------- Blaze kick----------------

BlazeKick::BlazeKick()
    : Ability("Blaze Kick", Attribute::FIRE, 20, 1, "A fiery kick attack.") {}
//uses blaze kick ability
void BlazeKick::use(Character &user, Character &target)
{
    // check if the ability hits based on hit chance
    if (!doesHit(getHitChance()))
    {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    // blaze kick reduces opopnets damage by 25%
    double currentAtk = target.getAttack();
    target.setAttack(currentAtk*0.75);

}
