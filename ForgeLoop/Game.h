#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game {
private:
    Player* player;
    std::vector<Enemy*> enemies; 
    bool isRunning;

public:
    Game();
    ~Game();

    void Run();    // Main game loop
    void PlayerTurn();
    void EnemyTurn();
};
