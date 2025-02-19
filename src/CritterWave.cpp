#include "../include/CritterWave.h"

#include <iostream>

/**
 * @brief Constructor for CritterWave.
 * @param level Difficulty level
 * @param entryX Entry X-coordinate
 * @param entryY Entry Y-coordinate
 */
CritterWave::CritterWave(int level, int entryX, int entryY) : waveLevel(level) {
    for (int i = 0; i < waveLevel + 2; i++) {
        critters.push_back(std::make_unique<Critter>(level, entryX, entryY));  // ✅ Fixed
    }
}

/**
 * @brief Move all critters toward the exit.
 * @param exitX Exit X-coordinate
 * @param exitY Exit Y-coordinate
 */
void CritterWave::moveCritters(int exitX, int exitY) {
    for (auto& critter : critters) {
        if (!critter->isDead()) {  // ✅ Fixed (use ->)
            critter->move(exitX, exitY);  // ✅ Fixed
        }
    }
}

/**
 * @brief Apply damage to all critters in the wave.
 * @param towerDamage Damage dealt per critter
 */
void CritterWave::attackCritters(int towerDamage) {
    for (auto& critter : critters) {
        if (!critter->isDead()) {  // ✅ Fixed
            critter->takeDamage(towerDamage);  // ✅ Fixed
        }
    }
}

/**
 * @brief Display all critters' statuses.
 */
void CritterWave::displayCritters() const {
    for (const auto& critter : critters) {
        critter->displayStatus();  // ✅ Fixed
    }
}

/**
 * @brief Check if all critters are dead.
 * @return True if all critters are eliminated, false otherwise.
 */
bool CritterWave::allDead() const {
    for (const auto& critter : critters) {
        if (!critter->isDead()) return false;  // ✅ Fixed
    }
    return true;
}

/**
 * @brief Get the total reward for defeating all critters.
 * @return Total reward points
 */
int CritterWave::getTotalReward() const {
    int total = 0;
    for (const auto& critter : critters) {
        if (critter->isDead()) {
            total += critter->getReward();  // ✅ Fixed
        }
    }
    return total;
}

/**
 * @brief Get the total remaining strength of all critters.
 * @return Total strength value
 */
int CritterWave::getTotalStrength() const {
    int total = 0;
    for (const auto& critter : critters) {
        if (!critter->isDead()) {
            total += critter->getStrength();  // ✅ Fixed
        }
    }
    return total;
}

