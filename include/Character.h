#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <memory>
#include "Observer.h"

/**
 * @class Character
 * @brief Represents a game character and notifies observers of changes.
 */
class Character {
private:
    std::string name; /**< Character's name */
    int health; /**< Character's health */
    int attackPower; /**< Character's attack power */
    std::vector<std::shared_ptr<Observer>> observers; /**< List of observers watching this Character */

public:
    /**
     * @brief Constructor for Character.
     * @param n Name of the character
     * @param h Health points
     * @param a Attack power
     */
    Character(std::string n, int h, int a);

    /**
     * @brief Attach an observer to the character.
     * @param observer The observer to be added.
     */
    void attachObserver(std::shared_ptr<Observer> observer);

    /**
     * @brief Notify all observers of a change.
     */
    void notifyObservers();

    /**
     * @brief Set character health and notify observers.
     * @param h New health value
     */
    void setHealth(int h);

    /**
     * @brief Set attack power and notify observers.
     * @param a New attack power value
     */
    void setAttackPower(int a);

    /**
     * @brief Get the character's name.
     * @return Character's name
     */
    std::string getName() const { return name; }

    /**
     * @brief Get the character's health.
     * @return Character's health
     */
    int getHealth() const { return health; }

    /**
     * @brief Get the character's attack power.
     * @return Character's attack power
     */
    int getAttackPower() const { return attackPower; }
};

#endif
