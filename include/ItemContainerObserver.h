#ifndef ITEMCONTAINER_OBSERVER_H
#define ITEMCONTAINER_OBSERVER_H

#include "Observer.h"
#include "ItemContainer.h"
#include <memory>
#include <iostream>

/**
 * @class ItemContainerObserver
 * @brief Observer that monitors an ItemContainer and updates when notified.
 */
class ItemContainerObserver : public Observer {
private:
    std::shared_ptr<ItemContainer> container; /**< ItemContainer being observed */

public:
    /**
     * @brief Constructor for ItemContainerObserver.
     * @param c The item container to observe.
     */
    ItemContainerObserver(std::shared_ptr<ItemContainer> c);

    /**
     * @brief Update method called when the item container changes.
     */
    void update() override;
};

#endif
