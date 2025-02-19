#ifndef ARROW_TOWER_H
#define ARROW_TOWER_H

#include "Tower.h"

/**
 * @class ArrowTower
 * @brief A tower that fires piercing arrows at critters.
 */
class ArrowTower : public Tower {
public:
    /**
     * @brief Constructor for the Arrow Tower.
     */
    ArrowTower();

    /**
     * @brief Attack function that fires arrows at critters.
     */
    void attack() override;
};

#endif
