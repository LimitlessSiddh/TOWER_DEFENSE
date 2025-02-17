#include "Map.h"
#include "FireTower.h"
#include "IceTower.h"
#include "ArrowTower.h"
#include "GameRenderer.h"
#include <memory>

int main() {
    Map gameMap(10, 10);
    
    // Set entry and exit points
    gameMap.setEntryPoint(0, 5);
    gameMap.setExitPoint(9, 5);

    // Create a continuous path
    for (int i = 1; i < 9; i++) {
        gameMap.setCell(i, 5, Path::getSymbol());
    }

    // 🚀 Attempt to place towers
    std::shared_ptr<FireTower> fire = std::make_shared<FireTower>();
    std::shared_ptr<IceTower> ice = std::make_shared<IceTower>();
    std::shared_ptr<ArrowTower> arrow = std::make_shared<ArrowTower>();

    gameMap.placeTower(2, 2, fire);  // ✅ Valid (on Scenery)
    gameMap.placeTower(5, 5, ice);   // ❌ Invalid (on Path)
    gameMap.placeTower(3, 3, arrow); // ✅ Valid (on Scenery)

    // Initialize and run the game renderer
    GameRenderer renderer(10, 10);
    renderer.run(gameMap);

    return 0;
}

