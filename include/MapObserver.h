#ifndef MAP_OBSERVER_H
#define MAP_OBSERVER_H

#include "Observer.h"
#include "Map.h"
#include <memory>
#include <iostream>

/**
 * @class MapObserver
 * @brief Observer that monitors a Map and updates when notified.
 */
class MapObserver : public Observer {
private:
    std::shared_ptr<Map> map; /**< Map being observed */

public:
    /**
     * @brief Constructor for MapObserver.
     * @param m The map to observe.
     */
    MapObserver(std::shared_ptr<Map> m);

    /**
     * @brief Update method called when the map changes.
     */
    void update() override;
};

#endif
