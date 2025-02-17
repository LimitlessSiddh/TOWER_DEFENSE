#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <memory>
#include "Path.h"
#include "Scenery.h"
#include "Tower.h"

class Map {
private:
    int width, height;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<std::shared_ptr<Tower>>> towers; // Store towers
    std::pair<int, int> entryPoint, exitPoint;
    
    bool isValidPath(); // Checks if path is connected

public:
    Map(int w, int h);
    
    void setCell(int x, int y, char type);
    void setEntryPoint(int x, int y);
    void setExitPoint(int x, int y);
    char getCellType(int x, int y) const; // New function to access cell type
    
    bool placeTower(int x, int y, std::shared_ptr<Tower> tower); // New function
    void display() const;
    bool validateMap();
};

#endif

