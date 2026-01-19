#include "Actor.h"
#include <iostream>

Actor::Actor(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {
}

void Actor::Attack(Actor& target) {
    std::cout << name << " attacks " << target.GetName()
        << " for " << attackPower << " damage.\n";

    target.TakeDamage(attackPower);
}

void Actor::TakeDamage(int amount) {
    health -= amount;

    if (health < 0) {
        health = 0;
    }

    std::cout << name << " now has " << health << " health.\n";
}

bool Actor::IsAlive() const {
    return health > 0;
}

int Actor::GetHealth() const {
    return health;
}

std::string Actor::GetName() const {
    return name;
}