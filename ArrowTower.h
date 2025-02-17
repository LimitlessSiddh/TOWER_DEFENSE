#ifndef ARROW_TOWER_H
#define ARROW_TOWER_H
#include "Tower.h"
class ArrowTower : public Tower {
public:
    ArrowTower();
    void attack() override;
};
#endif
