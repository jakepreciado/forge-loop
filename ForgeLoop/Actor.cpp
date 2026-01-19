#include "Actor.h"
#include <iostream>

// Constructor
Actor::Actor(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {
}

// Displays and applies attack damage
void Actor::Attack(Actor& target) {
    std::cout << name << " attacks " << target.GetName()
        << " for " << attackPower << " damage.\n";

    target.TakeDamage(attackPower);
}

// Computes and displays damage taken by entity
void Actor::TakeDamage(int amount) {
    health -= amount;

    if (health < 0) {
        health = 0;
    }

    std::cout << name << " now has " << health << " health.\n";
}

// Returns true if health > 0
bool Actor::IsAlive() const {
    return health > 0;
}

// Returns entity's health value
int Actor::GetHealth() const {
    return health;
}

// Returns entity's name
std::string Actor::GetName() const {
    return name;
}