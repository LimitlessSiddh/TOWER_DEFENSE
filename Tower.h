#ifndef TOWER_H
#define TOWER_H
#include <iostream>

class Tower {
protected:
    int cost, range, power, fireRate;
public:
    Tower(int c, int r, int p, int f);
    virtual void attack() = 0;
    virtual ~Tower() {}
};
#endif
