#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Observer.h"

/**
 * @class ItemContainer
 * @brief Represents a container for storing game items.
 *
 * Implements the Observer pattern to notify observers when items are added or removed.
 */
class ItemContainer {
private:
    std::vector<std::string> items; /**< List of items in the container */
    std::vector<std::shared_ptr<Observer>> observers; /**< Observers watching this container */

public:
    /**
     * @brief Constructor for ItemContainer.
     */
    ItemContainer() {}

    /**
     * @brief Attach an observer to the item container.
     * @param observer The observer to be added.
     */
    void attachObserver(std::shared_ptr<Observer> observer);

    /**
     * @brief Notify all observers when an update occurs.
     */
    void notifyObservers();

    /**
     * @brief Add an item to the container.
     * @param item Name of the item to add.
     */
    void addItem(const std::string& item);

    /**
     * @brief Remove an item from the container.
     * @param item Name of the item to remove.
     */
    void removeItem(const std::string& item);

    /**
     * @brief Get the list of items in the container.
     * @return List of item names.
     */
    std::vector<std::string> getItems() const;
};

#endif
