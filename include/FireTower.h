#ifndef FIRE_TOWER_H
#define FIRE_TOWER_H

#include "Tower.h"

/**
 * @class FireTower
 * @brief A tower that deals fire damage to critters.
 */
class FireTower : public Tower {
public:
    /**
     * @brief Constructor for the Fire Tower.
     */
    FireTower();

    /**
     * @brief Attack function that burns critters.
     */
    void attack() override;
};

#endif
