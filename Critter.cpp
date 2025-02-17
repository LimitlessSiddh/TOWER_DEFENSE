#include "Critter.h"
#include <cmath>  // For movement calculations

Critter::Critter(int lvl, int startX, int startY) 
    : level(lvl), health(50 + lvl * 10), speed(1 + lvl / 2), strength(5 + lvl * 2), reward(10 + lvl * 5), x(startX), y(startY) {}

void Critter::move(int targetX, int targetY) {
    if (x < targetX) x += speed;
    else if (x > targetX) x -= speed;

    if (y < targetY) y += speed;
    else if (y > targetY) y -= speed;
}

void Critter::takeDamage(int dmg) {
    health -= dmg;
    if (health <= 0) {
        std::cout << "Critter died!\n";
    }
}

bool Critter::isDead() const {
    return health <= 0;
}

int Critter::getReward() const {
    return reward;
}

int Critter::getStrength() const {
    return strength;
}

void Critter::displayStatus() const {
    std::cout << "Critter (Level " << level << ") | HP: " << health << " | Speed: " << speed 
              << " | Position: (" << x << "," << y << ")\n";
}
