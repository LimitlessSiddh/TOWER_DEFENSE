#include "Map.h"
#include "FireTower.h"
#include "IceTower.h"
#include "ArrowTower.h"
#include "CritterWave.h"
#include "Character.h"
#include "CharacterObserver.h"
#include "MapObserver.h"
#include "ItemContainer.h"
#include "ItemContainerObserver.h"
#include <iostream>
#include <memory>

/**
 * @file main.cpp
 * @brief Entry point for the Tower Defense game.
 *
 * This file initializes the game, places towers, and simulates a basic game loop.
 * It also integrates the Observer pattern for Character, Map, and ItemContainer.
 */

/**
 * @brief Displays the game instructions.
 */
void displayInstructions() {
    std::cout << "\n===== Tower Defense Game =====\n";
    std::cout << "Controls:\n";
    std::cout << "  'n' - Advance to the next wave step\n";
    std::cout << "  'c' - Modify character stats\n";
    std::cout << "  'm' - Modify the map (add tower)\n";
    std::cout << "  'i' - Modify inventory (add/remove items)\n";
    std::cout << "  'q' - Quit the game\n";
    std::cout << "==============================\n";
}

/**
 * @brief Initializes the game map with a predefined layout.
 * @return A shared pointer to the initialized Map.
 */
std::shared_ptr<Map> initializeGame() {
    auto gameMap = std::make_shared<Map>(10, 10);
    gameMap->setEntryPoint(0, 5);
    gameMap->setExitPoint(9, 5);
    for (int i = 1; i < 9; i++) {
        gameMap->setCell(i, 5, 'P');
    }
    return gameMap;
}

/**
 * @brief Runs the game loop where critters move, towers attack, and the player interacts.
 * @param gameMap The game map.
 * @param hero The player character.
 * @param inventory The player's inventory.
 */
void runGame(std::shared_ptr<Map> gameMap, std::shared_ptr<Character> hero, std::shared_ptr<ItemContainer> inventory) {
    CritterWave wave(1, 0, 5);
    int exitX = 9, exitY = 5;
    char command;

    displayInstructions();
    while (!wave.allDead()) {
        std::cout << "\nEnter command: ";
        std::cin >> command;

        if (command == 'q') {
            std::cout << "Game Over. Exiting...\n";
            break;
        } else if (command == 'n') {
            wave.moveCritters(exitX, exitY);
            wave.attackCritters(30);
            wave.displayCritters();
        } else if (command == 'c') {
            int newHealth, newAttack;
            std::cout << "Enter new health: ";
            std::cin >> newHealth;
            hero->setHealth(newHealth);

            std::cout << "Enter new attack power: ";
            std::cin >> newAttack;
            hero->setAttackPower(newAttack);
        } else if (command == 'm') {
            int x, y;
            std::cout << "Enter tower position (x y): ";
            std::cin >> x >> y;
            auto newTower = std::make_shared<ArrowTower>();
            if (!gameMap->placeTower(x, y, newTower)) {
                std::cout << "⚠️ Cannot place tower there!\n";
            }
        } else if (command == 'i') {
            std::string action, item;
            std::cout << "Enter action ('add' or 'remove') followed by item name: ";
            std::cin >> action >> item;
            if (action == "add") {
                inventory->addItem(item);
            } else if (action == "remove") {
                inventory->removeItem(item);
            } else {
                std::cout << "⚠️ Invalid action. Use 'add' or 'remove'.\n";
            }
        } else {
            std::cout << "⚠️ Invalid command! Please enter 'n', 'c', 'm', 'i', or 'q'.\n";
        }
    }

    if (wave.allDead()) {
        std::cout << "🎉 Wave cleared! All critters defeated.\n";
    }
}

/**
 * @brief Main function for the Tower Defense game.
 *
 * - Initializes the game map.
 * - Creates and observes the character.
 * - Creates and observes the item container.
 * - Runs the game loop.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    // ✅ Initialize Character and attach observer
    auto hero = std::make_shared<Character>("Hero", 100, 50);
    auto heroObserver = std::make_shared<CharacterObserver>(hero);
    hero->attachObserver(heroObserver);

    std::cout << "🎭 Character Initialized: " << hero->getName()
              << " (HP: " << hero->getHealth() << ", AP: " << hero->getAttackPower() << ")\n\n";

    // ✅ Initialize Map and attach observer
    auto gameMap = initializeGame();
    auto mapObserver = std::make_shared<MapObserver>(gameMap);
    gameMap->attachObserver(mapObserver);

    // ✅ Initialize Inventory and attach observer
    auto inventory = std::make_shared<ItemContainer>();
    auto inventoryObserver = std::make_shared<ItemContainerObserver>(inventory);
    inventory->attachObserver(inventoryObserver);

    // ✅ Run the game loop
    runGame(gameMap, hero, inventory);

    return 0;
}





