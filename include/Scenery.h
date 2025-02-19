#ifndef SCENERY_H
#define SCENERY_H

/**
 * @class Scenery
 * @brief Represents non-path areas of the game where towers can be placed.
 *
 * Scenery cells allow tower placement but cannot be traversed by critters.
 */
class Scenery {
public:
    /**
     * @brief Get the character symbol representing scenery.
     * @return 'S' character
     */
    static char getSymbol() { return 'S'; }
};

#endif
