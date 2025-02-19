#ifndef ICE_TOWER_H
#define ICE_TOWER_H

#include "Tower.h"

/**
 * @class IceTower
 * @brief A tower that slows down critters by freezing them.
 */
class IceTower : public Tower {
public:
    /**
     * @brief Constructor for the Ice Tower.
     */
    IceTower();

    /**
     * @brief Attack function that slows critters.
     */
    void attack() override;
};

#endif
