#include "../include/IceTower.h"
#include <iostream>

IceTower::IceTower() : Tower(180, 3, 30, 2) {}

void IceTower::attack() {
    std::cout << "Ice Tower attacks and slows enemies!\n";
}
