#pragma once
#include "Actor.h"

class Player : public Actor {
private:
    int specialCooldown; 

public:
    Player(const std::string& name);

    void Attack(Actor& target) override;
    void Heal();                    
    void SpecialAttack(Actor& target); 

    bool CanUseSpecial() const;       
};
