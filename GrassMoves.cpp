#include "GrassMoves.h"
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
// ---------------- Vine Whip ----------------
VineWhip::VineWhip()
    : Ability("Vine Whip", Attribute::GRASS, 40, 1.0, "A quick lash with vines.") {}

void VineWhip::use(Character& user, Character& target) {
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

    int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);

    std::cout << user.getName() << " lashed " << target.getName()
              << " with " << getName() << " for " << dmg << " damage"
              << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Root Bind ----------------
RootBind::RootBind()
    : Ability("Root Bind", Attribute::GRASS, 70, 0.5, "Strong vines wrap around the foe.") {}

void RootBind::use(Character& user, Character& target) {
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

    int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    //this lands a critical hti with 1.5 times the damage for the opponenet
    
    std::cout << user.getName() << " trapped " << target.getName()
              << " with " << getName() << " for " << dmg << " damage"
              << (crit ? " (CRIT!)" : "") << "!\n";
}

// ---------------- Leaf Blade ----------------
LeafBlade::LeafBlade()
    : Ability("Leaf Blade", Attribute::GRASS, 30, 1.0, "A swift slash of leaves.") {}

void LeafBlade::use(Character& user, Character& target) {
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

    int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    //this attack redcues oppoent health and speed by 15 percent 
    double maxHealth = target.getHealth();
    double healthReduction = maxHealth * 0.15;
    target.takeDamage(healthReduction);
    double currentSpeed = target.getSpeed();
    double speedReduction = currentSpeed * 0.15;
    target.setSpeed(currentSpeed - speedReduction);

    std::cout << user.getName() << " sliced " << target.getName()
              << " with " << getName() << " for " << dmg << " damage"
              << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << " lost an additional " << healthReduction << " health and speed is reduced by " << speedReduction << "!\n";
}

// ---------------- Spore ----------------
Spore::Spore()
    : Ability("Spore", Attribute::GRASS, 0, 0.7, "Releases spores that could weaken the enemy.") {}

void Spore::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    //redcues oppotnets defense to 0
    target.setDefence(0);
    std::cout << user.getName() << " released " << getName()
              << "! " << target.getName()
              << " seems weakened! (no direct damage yet)\n";
    
}

// ---------------- SeedBullet ----------------
SeedBullet::SeedBullet()
    : Ability("Seed Bullet", Attribute::GRASS, 20, 1.0, "A fast-moving seed attack.") {}
void SeedBullet::use(Character& user, Character& target) {
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
     int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    // redcues oppoenents health by 30%
    double healthReduction = target.getHealth() * 0.3;
    target.takeDamage(healthReduction);
    std::cout << user.getName() << " fired " << getName()
              << " at " << target.getName() << " for "
              << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s health is reduced by " << healthReduction << "\n";
}
