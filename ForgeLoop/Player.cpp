#include "Player.h"
#include <iostream>

// Constructor
// Default health == 100 and attack power == 20 for player
Player::Player(const std::string& name)
    : Actor(name, 100, 20), specialCooldown(0) {
}

// Base attack move
void Player::Attack(Actor& target) {
    std::cout << "[Player] ";
    Actor::Attack(target);
    if (specialCooldown > 0)
        specialCooldown--;
}

// Heals player by 20 HP
void Player::Heal() {
    int healAmount = 20;
    health += healAmount;
    if (health > 100) health = 100; // Max HP == 100
    std::cout << "[Player] " << name << "drinks a potion and heals for " << healAmount
        << " HP. Current health: " << health << "\n";

    if (specialCooldown > 0)
        specialCooldown--;
}

// Special attack move. Can be used only if specialCooldown == 0
void Player::SpecialAttack(Actor& target) {
    if (specialCooldown == 0) {
        int damage = attackPower * 2; // Double damage
        std::cout << "[Player] " << name << " uses SPECIAL ATTACK on "
            << target.GetName() << " for " << damage << " damage!\n";
        target.TakeDamage(damage);
        specialCooldown = 3; // Cooldown == 3 turns
    }
    else {
        std::cout << "[Player] Special attack not ready! Turns left: "
            << specialCooldown << "\n";
    }
}

// Returns true if specialCooldown == 0
bool Player::CanUseSpecial() const {
    return specialCooldown == 0;
}