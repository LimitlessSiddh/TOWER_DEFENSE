#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <memory>  // ✅ Needed for std::shared_ptr
#include "Observer.h" // ✅ Include Observer

// ✅ Forward declaration of Tower class
class Tower;  

/**
 * @class Map
 * @brief Represents the game grid with path and scenery.
 *
 * The Map class manages the layout of the game, ensuring
 * that critters follow a defined path and towers can only be
 * placed on valid scenery cells.
 */
class Map {
private:
    int width, height;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<std::shared_ptr<Tower>>> towers; /**< Stores Tower pointers */
    std::pair<int, int> entryPoint, exitPoint;
    std::vector<std::shared_ptr<Observer>> observers; /**< List of observers watching this Map */

public:
    Map(int w, int h);
    void setCell(int x, int y, char type);
    void setEntryPoint(int x, int y);
    void setExitPoint(int x, int y);
    bool placeTower(int x, int y, std::shared_ptr<Tower> tower);
    
    /**
     * @brief Attach an observer to the map.
     * @param observer The observer to be added.
     */
    void attachObserver(std::shared_ptr<Observer> observer);

    /**
     * @brief Notify all observers of a change.
     */
    void notifyObservers();

    /**
     * @brief Display the current map state.
     */
    void display() const;
};

#endif

