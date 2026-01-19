#include "Player.h"
#include <iostream>

Player::Player(const std::string& name)
    : Actor(name, 100, 20), specialCooldown(0) {
}

void Player::Attack(Actor& target) {
    std::cout << "[Player] ";
    Actor::Attack(target);
    if (specialCooldown > 0)
        specialCooldown--;
}

void Player::Heal() {
    int healAmount = 20;
    health += healAmount;
    if (health > 100) health = 100; 
    std::cout << "[Player] " << name << "drinks a potion and heals for " << healAmount
        << " HP. Current health: " << health << "\n";

    if (specialCooldown > 0)
        specialCooldown--;
}

void Player::SpecialAttack(Actor& target) {
    if (specialCooldown == 0) {
        int damage = attackPower * 2; 
        std::cout << "[Player] " << name << " uses SPECIAL ATTACK on "
            << target.GetName() << " for " << damage << " damage!\n";
        target.TakeDamage(damage);
        specialCooldown = 3; 
    }
    else {
        std::cout << "[Player] Special attack not ready! Turns left: "
            << specialCooldown << "\n";
    }
}

bool Player::CanUseSpecial() const {
    return specialCooldown == 0;
}