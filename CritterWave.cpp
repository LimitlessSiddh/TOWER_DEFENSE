#include "CritterWave.h"
#include <iostream>

CritterWave::CritterWave(int level, int entryX, int entryY) : waveLevel(level) {
    for (int i = 0; i < waveLevel + 2; i++) {  // Each wave gets harder
        critters.emplace_back(level, entryX, entryY);
    }
}

void CritterWave::moveCritters(int exitX, int exitY) {
    for (auto& critter : critters) {
        if (!critter.isDead()) {
            critter.move(exitX, exitY);
        }
    }
}

void CritterWave::attackCritters(int towerDamage) {
    for (auto& critter : critters) {
        if (!critter.isDead()) {
            critter.takeDamage(towerDamage);
        }
    }
}

void CritterWave::displayCritters() const {
    for (const auto& critter : critters) {
        critter.displayStatus();
    }
}

bool CritterWave::allDead() const {
    for (const auto& critter : critters) {
        if (!critter.isDead()) return false;
    }
    return true;
}

int CritterWave::getTotalReward() const {
    int total = 0;
    for (const auto& critter : critters) {
        if (critter.isDead()) {
            total += critter.getReward();
        }
    }
    return total;
}

int CritterWave::getTotalStrength() const {
    int total = 0;
    for (const auto& critter : critters) {
        if (!critter.isDead()) {
            total += critter.getStrength();
        }
    }
    return total;
}
