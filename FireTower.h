#ifndef FIRE_TOWER_H
#define FIRE_TOWER_H
#include "Tower.h"
class FireTower : public Tower {
public:
    FireTower();
    void attack() override;
};
#endif
