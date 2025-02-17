#ifndef CRITTERWAVE_H
#define CRITTERWAVE_H

#include "Critter.h"
#include <vector>

class CritterWave {
private:
    std::vector<Critter> critters;
    int waveLevel;

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
