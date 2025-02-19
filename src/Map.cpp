#include "Map.h"
#include "Tower.h"  // ✅ Now included in the .cpp file

Map::Map(int w, int h) : width(w), height(h), grid(h, std::vector<char>(w, 'S')), towers(h, std::vector<std::shared_ptr<Tower>>(w, nullptr)) {}

void Map::setCell(int x, int y, char type) {
    grid[y][x] = type;
    notifyObservers();
}

void Map::setEntryPoint(int x, int y) {
    entryPoint = {x, y};
    setCell(x, y, 'P');
}

void Map::setExitPoint(int x, int y) {
    exitPoint = {x, y};
    setCell(x, y, 'P');
}

bool Map::placeTower(int x, int y, std::shared_ptr<Tower> tower) {
    if (grid[y][x] == 'S' && towers[y][x] == nullptr) {
        towers[y][x] = tower;
        notifyObservers();
        return true;
    }
    return false;
}

void Map::attachObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Map::notifyObservers() {
    for (auto& observer : observers) {
        observer->update();
    }
}

void Map::display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (towers[i][j] != nullptr) {
                std::cout << "T ";
            } else {
                std::cout << grid[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
