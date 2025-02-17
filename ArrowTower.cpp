#include "ArrowTower.h"
ArrowTower::ArrowTower() : Tower(100, 5, 25, 3) {}
void ArrowTower::attack() {
    std::cout << "Arrow Tower attacks with piercing arrows!\n";
}
