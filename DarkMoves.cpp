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

bool ShadowStrike::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        return false;
    }
    //shadow strike reduces oponents defence by 50 percent
   
    double defReduction = target.getDefence() * 0.5;
    if(defReduction<1.5)
    target.setDefence(0);
    else
    target.setDefence(defReduction);
    user.setHealth(user.getHealth()+0);
    return true;
}

// ---------------- Void Pulse ----------------
//constructor implementation
VoidPulse::VoidPulse()
    : Ability("Void pulse", Attribute::DARK, 80, 0.7, "A heavy pulse of void energy.") {}

bool VoidPulse::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        return false;
    }
    //calculate damage
    double atk = user.getAttack();
    double def = target.getDefence();
    double raw = atk + (getDamage() / 100.0) * atk - def;
    if (raw < 0) 
    raw = 10;
//apply type multiplier and critical hit
    raw *= typeMultiplier(getType(), target.getType());
    bool crit = doesHit(user.getCritChance());
    if (crit) raw *= CRIT_MULT;
    int dmg = static_cast<int>(std::round(raw));
    target.takeDamage(dmg);
    return true;
}

// ---------------- Night Claw ----------------
NightClaw::NightClaw()
    : Ability("Night claw", Attribute::DARK, 30, 0.8, "A swift tearing slash.") {}

bool NightClaw::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        return false;
    }
    //redcues oppoentns damage by 10 percent and increases characterss damage by that ammount
    double defReduction = target.getDefence() * 0.1;
    if(defReduction<1.5)
    target.setDefence(0);
    else
    target.setDefence(defReduction);
    user.setHealth(user.getHealth()+0);
    return true;
    return true;
}

// ---------------- Sneak Attack ----------------
SneakAttack::SneakAttack()
    : Ability("Sneak attack", Attribute::DARK, 40, 1.0, "A well-timed ambush.") {}

bool SneakAttack::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        return false;
    }

    //redcues opponents defence to 0
    target.setDefence(0);
    user.setHealth(user.getHealth()+0);
    return true;

}
// ---------------- Sucker Punch ----------------
SuckerPunch::SuckerPunch()
    : Ability("Sucker Punch", Attribute::DARK, 19, 1.0, "A quick and unexpected punch.") {} 
bool SuckerPunch::use(Character& user, Character& target) {
    if (!doesHit(getHitChance())) {
        return false;
    }
     //calculate damage
     double atk = user.getAttack();
     double def = target.getDefence();
     double raw = atk + (getDamage() / 100.0) * atk - def;
     if (raw < 0) 
     raw = 10;
 //apply type multiplier and critical hit
     raw *= typeMultiplier(getType(), target.getType());
     bool crit = doesHit(user.getCritChance());
     if (crit) raw *= CRIT_MULT;
     int dmg = static_cast<int>(std::round(raw));
     target.takeDamage(dmg);       
    return true;
    
}


