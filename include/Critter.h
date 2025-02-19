#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>

/**
 * @class Critter
 * @brief Represents an enemy unit in the Tower Defense game.
 *
 * Critters move along the path and take damage from towers.
 */
class Critter {
private:
    int health;
    int speed;
    int strength;
    int reward;
    int level;
    int x, y; /**< Current position of the critter */

public:
    /**
     * @brief Constructor for the Critter class.
     * @param lvl Level of the critter
     * @param startX Initial X-coordinate
     * @param startY Initial Y-coordinate
     */
    Critter(int lvl, int startX, int startY);

    /**
     * @brief Move towards a target location.
     * @param targetX X-coordinate of target
     * @param targetY Y-coordinate of target
     */
    void move(int targetX, int targetY);

    /**
     * @brief Take damage from a tower attack.
     * @param dmg Amount of damage taken
     */
    void takeDamage(int dmg);

    /**
     * @brief Check if the critter is dead.
     * @return True if dead, otherwise false.
     */
    bool isDead() const;

    /**
     * @brief Get the reward points for defeating the critter.
     * @return Reward points
     */
    int getReward() const;

    /**
     * @brief Get the critter's attack strength.
     * @return Strength value
     */
    int getStrength() const;

    /**
     * @brief Display the critter's status.
     */
    void displayStatus() const;
    
    /**
     * @brief Get the X-coordinate of the critter.
     * @return X-coordinate
     */
    int getX() const { return x; }

    /**
     * @brief Get the Y-coordinate of the critter.
     * @return Y-coordinate
     */
    int getY() const { return y; }
};

#endif


