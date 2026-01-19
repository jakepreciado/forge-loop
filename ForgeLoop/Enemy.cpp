#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& name)
    : Actor(name, 50, 10) {
} // default health and attack power

void Enemy::Attack(Actor& target) {
    std::cout << "[Enemy] ";
    Actor::Attack(target); // reuse base class logic
}
