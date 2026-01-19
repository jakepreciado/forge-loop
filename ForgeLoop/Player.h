#pragma once
#include "Actor.h"

class Player : public Actor {
private:
    int specialCooldown; //Number of turns before player can use special attack again

public:
    Player(const std::string& name);

    void Attack(Actor& target) override; // override virtual function with player specific behavior
    void Heal(); // Restores health, reduces cool down by 1 turn
    void SpecialAttack(Actor& target); // Bigger attack that deals more damage. Only used when specialCooldown == 0

    bool CanUseSpecial() const; // Returns true if specialCooldown == 0     
};
