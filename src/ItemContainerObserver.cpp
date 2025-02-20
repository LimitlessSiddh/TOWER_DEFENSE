#include "ItemContainerObserver.h"

ItemContainerObserver::ItemContainerObserver(std::shared_ptr<ItemContainer> c) : container(c) {}

void ItemContainerObserver::update() {
    std::cout << "📦 Item Container Updated! Current Items:\n";
    std::vector<std::string> items = container->getItems();
    
    if (items.empty()) {
        std::cout << "[Empty]\n";
    } else {
        for (const auto& item : items) {
            std::cout << " - " << item << "\n";
        }
    }
    std::cout << std::endl;
}
