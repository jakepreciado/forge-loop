#pragma once
#include <string>

class Actor {
protected:
    std::string name;
    int health;
    int attackPower;

public:
    Actor(const std::string& name, int health, int attackPower);
    virtual ~Actor() = default;

    virtual void Attack(Actor& target);
    virtual void TakeDamage(int amount);

    bool IsAlive() const;
    int GetHealth() const;
    std::string GetName() const;
};