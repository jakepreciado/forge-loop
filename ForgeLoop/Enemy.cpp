#include "Enemy.h"
#include <iostream>

// Constructor
// Default health == 50 and attack power == 10 for all enemies
Enemy::Enemy(const std::string& name)
    : Actor(name, 50, 10) {
} 

void Enemy::Attack(Actor& target) {
    std::cout << "[Enemy] ";
    Actor::Attack(target); // reuses base class logic
}
