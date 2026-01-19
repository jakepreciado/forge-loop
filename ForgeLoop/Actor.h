#pragma once
#include <string>

// Base clase for player and enemy entities
class Actor {
protected:
    std::string name;
    int health;
    int attackPower;

public:
    // Constructor
    Actor(const std::string& name, int health, int attackPower);
    virtual ~Actor() = default;

    virtual void Attack(Actor& target); // Virtual function: Attacks target and deals damage
    virtual void TakeDamage(int amount); // Virtual function: Reduces targets health

    bool IsAlive() const; // Returns true if health > 0
    int GetHealth() const; // Returns health state entity
    std::string GetName() const;
};