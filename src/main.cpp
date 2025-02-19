#include "Map.h"
#include "FireTower.h"
#include "IceTower.h"
#include "ArrowTower.h"
#include "CritterWave.h"
#include "Character.h"         // ✅ Added Character Class
#include "CharacterObserver.h" // ✅ Added Observer Pattern
#include <iostream>
#include <memory>  // ✅ Needed for smart pointers

/**
 * @file main.cpp
 * @brief Entry point for the Tower Defense game.
 *
 * This file initializes the game map, places towers, and simulates a basic game loop.
 * It also integrates the Observer pattern with Character tracking.
 */

/**
 * @brief Displays the game instructions.
 */
void displayInstructions() {
    std::cout << "\n===== Tower Defense Game =====\n";
    std::cout << "Controls:\n";
    std::cout << "  'n' - Advance to the next wave step\n";
    std::cout << "  'c' - Modify character stats\n";
    std::cout << "  'q' - Quit the game\n";
    std::cout << "==============================\n";
}

/**
 * @brief Initializes the game map and sets up the game.
 * @return The initialized game map.
 */
Map initializeGame() {
    Map gameMap(10, 10);
    gameMap.setEntryPoint(0, 5);
    gameMap.setExitPoint(9, 5);

    for (int i = 1; i < 9; i++) {
        gameMap.setCell(i, 5, 'P');
    }

    return gameMap;
}

/**
 * @brief Places towers on the map.
 * @param gameMap The game map to place towers on.
 */
void placeTowers(Map& gameMap) {
    std::shared_ptr<Tower> fireTower = std::make_shared<FireTower>();
    std::shared_ptr<Tower> iceTower = std::make_shared<IceTower>();
    std::shared_ptr<Tower> arrowTower = std::make_shared<ArrowTower>();

    gameMap.placeTower(2, 2, fireTower);
    gameMap.placeTower(4, 4, iceTower);
    gameMap.placeTower(6, 6, arrowTower);
}

/**
 * @brief Runs the game loop where critters move and towers attack.
 * @param gameMap The game map.
 * @param hero The character being observed.
 */
void runGame(Map& gameMap, std::shared_ptr<Character> hero) {
    CritterWave wave(1, 0, 5);
    int exitX = 9, exitY = 5;
    char command;

    displayInstructions();
    std::cout << "\nInitial Game State:\n";
    gameMap.display();

    while (!wave.allDead()) {
        std::cout << "\nEnter command: ";
        std::cin >> command;

        if (command == 'q') {
            std::cout << "Game Over. Exiting...\n";
            break;
        } else if (command == 'n') {
            wave.moveCritters(exitX, exitY);
            gameMap.display();
            wave.attackCritters(30);
            wave.displayCritters();
        } else if (command == 'c') {
            // ✅ Modify Character Stats to Trigger Observer Updates
            int newHealth, newAttack;
            std::cout << "Enter new health: ";
            std::cin >> newHealth;
            hero->setHealth(newHealth);

            std::cout << "Enter new attack power: ";
            std::cin >> newAttack;
            hero->setAttackPower(newAttack);
        } else {
            std::cout << "Invalid command! Please enter 'n', 'c', or 'q'.\n";
        }
    }

    if (wave.allDead()) {
        std::cout << "Wave cleared! All critters defeated.\n";
    }
}

/**
 * @brief Main function for the Tower Defense game.
 *
 * - Initializes a 10x10 game map.
 * - Places towers on the map using shared pointers.
 * - Displays the initial game state.
 * - Runs a simple game loop where critters move and towers attack.
 * - Integrates the Observer pattern with a Character.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    // ✅ Initialize Character and Observer
    std::shared_ptr<Character> hero = std::make_shared<Character>("Hero", 100, 50);
    std::shared_ptr<CharacterObserver> observer = std::make_shared<CharacterObserver>(hero);
    hero->attachObserver(observer);

    std::cout << "Character Initialized: " << hero->getName() << " (HP: " << hero->getHealth() << ", AP: " << hero->getAttackPower() << ")\n\n";

    // ✅ Initialize game map and towers
    Map gameMap = initializeGame();
    placeTowers(gameMap);

    // ✅ Run the game loop
    runGame(gameMap, hero);

    return 0;
}




