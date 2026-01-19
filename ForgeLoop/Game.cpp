#include "Game.h"
#include <iostream>
#include <algorithm>

Game::Game() {
    player = new Player("Hero");

    enemies.push_back(new Enemy("Goblin"));
    enemies.push_back(new Enemy("Orc"));
    enemies.push_back(new Enemy("Troll"));

    isRunning = true;
}

Game::~Game() {
    delete player;
    for (Enemy* e : enemies) {
        delete e;
    }
}

void Game::PlayerTurn() {
    std::vector<Enemy*> aliveEnemies;
    for (Enemy* e : enemies)
        if (e->IsAlive()) aliveEnemies.push_back(e);

    if (aliveEnemies.empty()) return;

    std::cout << "\nYour turn! Choose an action:\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Heal\n";
    std::cout << "3. Special Attack\n";
    std::cout << "Enter choice: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: // Attack
        for (size_t i = 0; i < aliveEnemies.size(); i++) {
            std::cout << i + 1 << ". " << aliveEnemies[i]->GetName()
                << " (" << aliveEnemies[i]->GetHealth() << " HP)\n";
        }
        std::cout << "Choose enemy to attack: ";
        int targetChoice;
        std::cin >> targetChoice;
        if (targetChoice >= 1 && targetChoice <= (int)aliveEnemies.size()) {
            player->Attack(*aliveEnemies[targetChoice - 1]);
            if (!aliveEnemies[targetChoice - 1]->IsAlive()) {
                std::cout << aliveEnemies[targetChoice - 1]->GetName()
                    << " has been defeated!\n";
                enemies.erase(std::remove(enemies.begin(), enemies.end(),
                    aliveEnemies[targetChoice - 1]),
                    enemies.end());
            }
        }
        else {
            std::cout << "Invalid enemy choice!\n";
        }
        break;
    case 2: // Heal
        player->Heal();
        break;
    case 3: // Special Attack
        for (size_t i = 0; i < aliveEnemies.size(); i++) {
            std::cout << i + 1 << ". " << aliveEnemies[i]->GetName()
                << " (" << aliveEnemies[i]->GetHealth() << " HP)\n";
        }
        std::cout << "Choose enemy for special attack: ";
        std::cin >> targetChoice;
        if (targetChoice >= 1 && targetChoice <= (int)aliveEnemies.size()) {
            player->SpecialAttack(*aliveEnemies[targetChoice - 1]);
            if (!aliveEnemies[targetChoice - 1]->IsAlive()) {
                std::cout << aliveEnemies[targetChoice - 1]->GetName()
                    << " has been defeated!\n";
                enemies.erase(std::remove(enemies.begin(), enemies.end(),
                    aliveEnemies[targetChoice - 1]),
                    enemies.end());
            }
        }
        else {
            std::cout << "Invalid enemy choice!\n";
        }
        break;
    default:
        std::cout << "Invalid action, you miss your turn!\n";
    }
}


void Game::EnemyTurn() {
    for (Enemy* e : enemies) {
        if (e->IsAlive()) {
            std::cout << "\n" << e->GetName() << "'s turn!\n";
            e->Attack(*player);
        }
    }
}

void Game::Run() {
    while (isRunning) {
        if (!player->IsAlive()) {
            std::cout << "\nYou have been defeated!\n";
            isRunning = false;
            break;
        }

        bool anyEnemiesAlive = false;
        for (Enemy* e : enemies) {
            if (e->IsAlive()) {
                anyEnemiesAlive = true;
                break;
            }
        }
        if (!anyEnemiesAlive) {
            std::cout << "\nYou defeated all the enemies! Victory!\n";
            isRunning = false;
            break;
        }

        PlayerTurn();
        EnemyTurn();
    }
}
