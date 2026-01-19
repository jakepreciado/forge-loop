#include "Game.h"
#include <iostream>
#include <algorithm>

// Constructor
// (Sets isRunning == true)
Game::Game() {
    player = new Player("Hero");

    enemies.push_back(new Enemy("Goblin"));
    enemies.push_back(new Enemy("Orc"));
    enemies.push_back(new Enemy("Troll"));

    isRunning = true;
}

// Destructor - Cleans up dynamically allocated memory for player and enemies
Game::~Game() {
    delete player;
    for (Enemy* e : enemies) {
        delete e;
    }
}

// Handles player turn logic. 
// (Can choose 1-3)
void Game::PlayerTurn() {
    // An STD/list of enemies to display
    std::vector<Enemy*> aliveEnemies;
    for (Enemy* e : enemies)
        if (e->IsAlive()) aliveEnemies.push_back(e);

    if (aliveEnemies.empty()) return;

    // Action menu
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
        std::cout << "Choose enemy to attack: "; // Selects target for attack
        int targetChoice;
        std::cin >> targetChoice;

        if (targetChoice >= 1 && targetChoice <= (int)aliveEnemies.size()) {
            player->Attack(*aliveEnemies[targetChoice - 1]);
            if (!aliveEnemies[targetChoice - 1]->IsAlive()) {
                std::cout << aliveEnemies[targetChoice - 1]->GetName()
                    << " has been slain!\n";
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
        std::cout << "Choose enemy for special attack: "; // Selects target for attack
        std::cin >> targetChoice;

        if (targetChoice >= 1 && targetChoice <= (int)aliveEnemies.size()) {
            player->SpecialAttack(*aliveEnemies[targetChoice - 1]);
            // Removes enemy if defeated
            if (!aliveEnemies[targetChoice - 1]->IsAlive()) {
                std::cout << aliveEnemies[targetChoice - 1]->GetName()
                    << " has been slain!\n";
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

// Handles enemy turn
// Each enemy still alive attacks the player
void Game::EnemyTurn() {
    for (Enemy* e : enemies) {
        if (e->IsAlive()) {
            std::cout << "\n" << e->GetName() << "'s turn!\n";
            e->Attack(*player);
        }
    }
}

// Game Loop - Runs until all enemies or player is defeated
void Game::Run() {

    std::cout << "Welcome to ForgeLoop, Hero!\n";
    std::cout << "Prepare yourself for battle and FORGE your way to victory.\n";

    while (isRunning) {
        if (!player->IsAlive()) {
            std::cout << "\nYou have been slain!\n";
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
            std::cout << "\nYou slain all the enemies! You are a true Hero!\n";
            isRunning = false;
            break;
        }

        PlayerTurn();
        EnemyTurn();
    }
}
