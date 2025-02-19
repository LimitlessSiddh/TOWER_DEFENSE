#ifndef CRITTERWAVE_H
#define CRITTERWAVE_H

#include "Critter.h"
#include <vector>
#include <memory>  // ✅ Needed for std::unique_ptr

/**
 * @class CritterWave
 * @brief Manages waves of critters in the game.
 */
class CritterWave {
private:
    std::vector<std::unique_ptr<Critter>> critters; /**< List of critters in the wave */
    int waveLevel; /**< Difficulty level of the wave */

public:
    CritterWave(int level, int entryX, int entryY);
    void moveCritters(int exitX, int exitY);
    void attackCritters(int towerDamage);
    void displayCritters() const;
    bool allDead() const;
    int getTotalReward() const;
    int getTotalStrength() const;
};

#endif
