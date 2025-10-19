#include "DarkMoves.h"
#include "Character.h"
#include "Attribute.h"   // for typeMultiplier()
#include <cmath>
#include <algorithm>
//critical hit damage multiplier 
constexpr double CRIT_MULT = 1.5; // all crits deal 1.5x damage
//random hit check based on chance
static bool doesHit(double chance) {

        return ((double)rand() / RAND_MAX) <= chance;

}

// ---------------- Shadow Strike ----------------
ShadowStrike::ShadowStrike()
    : Ability("Shadow strike", Attribute::DARK, 40, 1.0, "A precise strike from the shadows.") {}
//uses shadow strike ability
void ShadowStrike::use(Character& user, Character& target) {
//check if the ability hits based on hit chance
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    //shadow strike redces oponents defence by 50 percent
    double currentDef = target.getDefence();
    double defReduction = currentDef * 0.5;
    target.setDefence(currentDef - defReduction);
}

// ---------------- Void Pulse ----------------
//constructor implementation
VoidPulse::VoidPulse()
    : Ability("Void pulse", Attribute::DARK, 80, 0.7, "A heavy pulse of void energy.") {}
//uses void pulse ability
void VoidPulse::use(Character& user, Character& target) {
    //check if the ability hits based on hit chance
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    //calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0) raw = 0;
//apply type multiplier and critical hit
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;
    int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    //this attack redcues opponent health  by 15 percent 
    double maxHealth = target.getHealth();
    target.setHealth(0.85*maxHealth);
     //this attack redcues opponent speed  by 15 percent 
    double currentSpeed = target.getSpeed();
    target.setSpeed(currentSpeed*0.85);
}

// ---------------- Night Claw ----------------
NightClaw::NightClaw()
    : Ability("Night claw", Attribute::DARK, 30, 0.8, "A swift tearing slash.") {}
//uses night claw ability
void NightClaw::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }
    //redcues oppoentns damage by 10 percent and increases characterss damage by that ammount
    double currentAtk = target.getAttack();
    double atkReduction = currentAtk * 0.1;
    target.setAttack(currentAtk - atkReduction);
    user.setAttack(user.getAttack() + atkReduction);
}

// ---------------- Sneak Attack ----------------
SneakAttack::SneakAttack()
    : Ability("Sneak attack", Attribute::DARK, 40, 1.0, "A well-timed ambush.") {}
//uses sneak attack ability
void SneakAttack::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }

    //redcues oppoents damage to 0
    target.setAttack(0);

}
// ---------------- Sucker Punch ----------------
SuckerPunch::SuckerPunch()
    : Ability("Sucker Punch", Attribute::DARK, 19, 1.0, "A quick and unexpected punch.") {} 
    //uses sucker punch ability
void SuckerPunch::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        std::cout << user.getName() << " missed " << getName() << "!\n";
        return;
    }       
   
    // sucker punch increases users speed by 10%
    user.setSpeed(user.getSpeed() + 10);
    
}


