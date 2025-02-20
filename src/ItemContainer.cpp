#include "ItemContainer.h"

void ItemContainer::attachObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void ItemContainer::notifyObservers() {
    for (auto& observer : observers) {
        observer->update();
    }
}

void ItemContainer::addItem(const std::string& item) {
    items.push_back(item);
    std::cout << "🛒 Item added: " << item << std::endl;
    notifyObservers();
}

void ItemContainer::removeItem(const std::string& item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        std::cout << "🗑️  Item removed: " << item << std::endl;
        notifyObservers();
    } else {
        std::cout << "⚠️  Item not found: " << item << std::endl;
    }
}

std::vector<std::string> ItemContainer::getItems() const {
    return items;
}
