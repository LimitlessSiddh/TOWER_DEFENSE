#include "Map.h"
#include <queue>

Map::Map(int w, int h) : width(w), height(h), grid(h, std::vector<char>(w, 'S')), towers(h, std::vector<std::shared_ptr<Tower>>(w, nullptr)) {}

void Map::setCell(int x, int y, char type) {
    grid[y][x] = type;
}

void Map::setEntryPoint(int x, int y) {
    entryPoint = {x, y};
    setCell(x, y, 'P');
}

void Map::setExitPoint(int x, int y) {
    exitPoint = {x, y};
    setCell(x, y, 'P');
}

// 🚀 New Function: Place Tower
bool Map::placeTower(int x, int y, std::shared_ptr<Tower> tower) {
    if (grid[y][x] == 'S' && towers[y][x] == nullptr) { // Only allow placement on 'S'
        towers[y][x] = tower;
        std::cout << "Tower placed at (" << x << ", " << y << ")\n";
        return true;
    } else {
        std::cout << "Cannot place tower at (" << x << ", " << y << "). Not a valid location!\n";
        return false;
    }
}

void Map::display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (towers[i][j] != nullptr) {
                std::cout << "T ";  // Tower
            } else {
                std::cout << grid[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

// BFS to check valid path
bool Map::isValidPath() {
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    
    q.push(entryPoint);
    visited[entryPoint.second][entryPoint.first] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == exitPoint.first && y == exitPoint.second) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < width && ny < height && !visited[ny][nx] && grid[ny][nx] == 'P') {
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    return false;
}

bool Map::validateMap() {
    return isValidPath();
}
