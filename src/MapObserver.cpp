#include "MapObserver.h"

MapObserver::MapObserver(std::shared_ptr<Map> m) : map(m) {}

void MapObserver::update() {
    std::cout << "🗺️  Map Updated! Displaying new map state:\n";
    map->display();
}
