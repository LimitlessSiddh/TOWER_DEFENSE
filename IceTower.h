#ifndef ICE_TOWER_H
#define ICE_TOWER_H
#include "Tower.h"
class IceTower : public Tower {
public:
    IceTower();
    void attack() override;
};
#endif
