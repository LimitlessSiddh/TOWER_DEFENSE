#include "Character.h"
#include <iostream>

Character::Character(std::string n, int h, int a) : name(n), health(h), attackPower(a) {}

void Character::attachObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Character::notifyObservers() {
    for (auto& observer : observers) {
        observer->update();
    }
}

void Character::setHealth(int h) {
    health = h;
    notifyObservers();
}

void Character::setAttackPower(int a) {
    attackPower = a;
    notifyObservers();
}
