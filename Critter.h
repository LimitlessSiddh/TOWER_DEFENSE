#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>

class Critter {
private:
    int health;
    int speed;
    int strength;
    int reward;
    int level;
    int x, y; // Critter position

public:
    Critter(int lvl, int startX, int startY);

    void move(int targetX, int targetY);  // Move towards exit
    void takeDamage(int dmg);
    bool isDead() const;
    int getReward() const;
    int getStrength() const;
    void displayStatus() const;
    
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif
