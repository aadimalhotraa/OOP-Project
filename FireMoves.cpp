#include "FireMoves.h"
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

// ---------------- Fire Ball ----------------
FireBall::FireBall()
    : Ability("Fire Ball", Attribute::FIRE, 40, 0.8, "A blazing fireball.") {}

void FireBall::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!"<<std::endl;
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (atk*getDamage()/100.0) - def;

    if (raw < 0) 
    raw = 0;

    raw *= typeMultiplier(getType(), target.getType());

    //fireball does 1.5times damage to players health
    raw *= 1.5;

    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;

    target.takeDamage(raw);

    std::cout << user.getName() << " hurled " << getName()
              << " at " << target.getName() << " for "
              << raw << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}
// ---------------- Flame Burst ----------------
FlameBurst::FlameBurst()
    : Ability("Flame Burst", Attribute::FIRE, 80, 0.7, "A powerful explosion of flame.") {}

void FlameBurst::use(Character& user, Character& target) {
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

    target.takeDamage(raw);
    //flame burst reduces opopnents health by 20%
   double healthReduction = target.getHealth() * 0.2;
   target.takeDamage(healthReduction);
    std::cout << user.getName() << " unleashed " << getName()
              << " on " << target.getName() << " for "
              << raw << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s health is further reduced by"<< healthReduction<< "\n";
}

// ---------------- Ember Storm ----------------
EmberStorm::EmberStorm()
    : Ability("Ember Storm", Attribute::FIRE, 70, 0.8, "A storm of burning embers.") {}

void EmberStorm::use(Character& user, Character& target) {
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

   
    target.takeDamage(raw);
    //reduce oponents defence by 10%^
    double currentDef = target.getDefence();
    double defReduction = currentDef * 0.1;
    target.setDefence(std::max(0.0, currentDef - defReduction));

    std::cout << user.getName() << " summoned " << getName()
              << " on " << target.getName() << " for "
              << raw << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s defence is reduced by "<< defReduction << "\n";
}

// ---------------- Infernal Slash ----------------
InfernalSlash::InfernalSlash()
    : Ability("Infernal Slash", Attribute::FIRE, 40, 0.9, "A flaming blade attack.") {}

void InfernalSlash::use(Character& user, Character& target) {
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
    //increases cirictical damaghe
    if(crit){
        //increase critical damage by 15%
        raw *= (CRIT_MULT + 0.15);
    }
    
    target.takeDamage(raw);

    std::cout << user.getName() << " slashed " << target.getName()
              << " with " << getName() << " for "
              << raw << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Blaze kick----------------

BlazeKick::BlazeKick()
    : Ability("Blaze Kick", Attribute::FIRE, 20, 1, "A fiery kick attack.") {}

void BlazeKick::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage()/100.0) * atk - def;
    if (raw < 0) raw = 0;
    
    raw*= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;
    target.takeDamage(raw);
    //blaze kick reduces opopnets damage by 25%
    double currentAtk = target.getAttack();
    double atkReduction = currentAtk * 0.25;
    target.setAttack(std::max(0.0, currentAtk - atkReduction)); 
    std::cout << user.getName() << " kicked " << target.getName()
              << " with " << getName() << " for "
              << raw << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s attack is reduced by "<< atkReduction << "\n";
}
