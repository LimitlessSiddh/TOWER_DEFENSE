#include "../include/FireTower.h"
#include <iostream>

FireTower::FireTower() : Tower(200, 3, 40, 1) {}

void FireTower::attack() {
    std::cout << "Fire Tower attacks and burns enemies!\n";
}
