#include "DarkMoves.h"
#include "Character.h"
#include "Attribute.h"   // for typeMultiplier()
#include <cmath>
#include <algorithm>

constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage

static bool doesHit(double chance) {
    if ((rand() % 101) <= (chance * 100))
        return true;
    else
        return false;
}

// ---------------- Shadow Strike ----------------
ShadowStrike::ShadowStrike()
    : Ability("Shadow strike", Attribute::DARK, 40, 1.0, "A precise strike from the shadows.") {}

void ShadowStrike::use(Character& user, Character& target) {
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

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    //shadow strike redces oponents defence by 50 percetn
    double currentDef = target.getDefence();
    double defReduction = currentDef * 0.5;
    target.setDefence(currentDef - defReduction);
    
    std::cout << user.getName() << " struck from the shadows with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s defence is reduced by " << defReduction << "\n";
}

// ---------------- Void Pulse ----------------
VoidPulse::VoidPulse()
    : Ability("Void pulse", Attribute::DARK, 80, 0.7, "A heavy pulse of void energy.") {}

void VoidPulse::use(Character& user, Character& target) {
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

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    // void pulse reduces opponents attack by 20%
    double currentAtk = target.getAttack();
    double atkReduction = currentAtk * 0.2;
    target.setAttack(currentAtk - atkReduction);

    std::cout << user.getName() << " unleashed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s attack is reduced by " << atkReduction << "\n";    
}

// ---------------- Night Claw ----------------
NightClaw::NightClaw()
    : Ability("Night claw", Attribute::DARK, 30, 0.8, "A swift tearing slash.") {}

void NightClaw::use(Character& user, Character& target) {
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

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    //redcues oppoentns damage by 10 percent and increases characterss damage by that ammount
    double currentAtk = target.getAttack();
    double atkReduction = currentAtk * 0.1;
    target.setAttack(currentAtk - atkReduction);
    user.setAttack(user.getAttack() + atkReduction);

    std::cout << user.getName() << " slashed with " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s attack is reduced by " << atkReduction << "\n";
    std::cout << user.getName() << "'s attack is increased by " << atk
                << " by stealing " << atkReduction << " from " << target.getName() << "\n";
}

// ---------------- Sneak Attack ----------------
SneakAttack::SneakAttack()
    : Ability("Sneak attack", Attribute::DARK, 40, 1.0, "A well-timed ambush.") {}

void SneakAttack::use(Character& user, Character& target) {
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

    int dmg = (int)std::round(raw);
    target.takeDamage(dmg);
    //redcues oppoents damage to 0
    target.setAttack(0);

    std::cout << user.getName() << " performed " << getName()
              << " for " << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << target.getName() << "'s attack is reduced to 0 by the sneak attack!\n";
}
// ---------------- Sucker Punch ----------------
SuckerPunch::SuckerPunch()
    : Ability("Sucker Punch", Attribute::DARK, 19, 1.0, "A quick and unexpected punch.") {} 
void SuckerPunch::use(Character& user, Character& target) {
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
    // sucker punch increases users speed by 10%
    user.setSpeed(user.getSpeed() + 10);
    std::cout << user.getName() << " punched " << target.getName()
              << " with " << getName() << " for "
              << dmg << " damage" << (crit ? " (CRIT!)" : "") << "!\n";
    std::cout << user.getName() << "'s speed is increased by 10!\n";    
}


