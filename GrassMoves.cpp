#include "GrassMoves.h"
#include "Character.h"
#include "Attribute.h"   // for typeMultiplier()
#include <cmath>
#include <algorithm>
//critical hit damage multiplier
constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage
//random hit check based on chance
static bool doesHit(double chance) {
    //if chance is greater than random number return true
    if((rand() % 101) <= (chance * 100))
    return true;
    else
    return false;
}
// ---------------- Vine Whip ----------------
//constructor implementation
VineWhip::VineWhip()
    : Ability("Vine Whip", Attribute::GRASS, 40, 1.0, "A quick lash with vines.") {}

bool VineWhip::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
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
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;
//apply damage to target
    target.takeDamage(raw);
    return true;
}

// ---------------- Root Bind ----------------
//constructor implementation
RootBind::RootBind()
    : Ability("Root Bind", Attribute::GRASS, 70, 0.5, "Strong vines wrap around the foe.") {}

bool RootBind::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
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
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;
//apply damage to target
    int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    //this lands a critical hti with 1.5 times the damage for the opponenet
    // and traps them for the next turn
    std::cout << user.getName() << " trapped " << target.getName()
              << " with " << getName() << " for " << dmg << " damage"
              << (crit ? " (CRIT!)" : "") << "!\n";
    return true;
}

// ---------------- Leaf Blade ----------------
//constructor implementation
LeafBlade::LeafBlade()
    : Ability("Leaf Blade", Attribute::GRASS, 30, 1.0, "A swift slash of leaves.") {}

bool LeafBlade::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        
        return false;
    }
   
    //this attack redcues opponent health  by 15 percent 
    double maxHealth = target.getHealth();
    if(maxHealth<20)
    target.setHealth(0);
    else
    target.setHealth(0.85*maxHealth);
    return true;
}

// ---------------- Spore ----------------
//constructor implementation of spore ability
Spore::Spore()
    : Ability("Spore", Attribute::GRASS, 0, 0.5, "Releases spores that could weaken the enemy.") {}

bool Spore::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }
    //redcues oppotnets defense to 0
    target.setDefence(0);
    return true;
    
}

// ---------------- SeedBullet ----------------
//constructor implementation of seed bullet ability
SeedBullet::SeedBullet()
    : Ability("Seed Bullet", Attribute::GRASS, 20, 0.6, "A fast-moving seed attack.") {}
bool SeedBullet::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return false;
    }       
    // redcues oppoenents health by 30%
    double maxHealth = target.getHealth();
    if(maxHealth<20)
    target.setHealth(0);
    else
    target.setHealth(0.70*maxHealth);
    return true;
}
