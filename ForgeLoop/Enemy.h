#pragma once
#include "Actor.h"

class Enemy : public Actor {
public:
    Enemy(const std::string& name);
    void Attack(Actor& target) override; // override virtual function with enemy specific bahevior
};
