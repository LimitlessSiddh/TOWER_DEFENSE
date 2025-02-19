#include "CharacterObserver.h"

CharacterObserver::CharacterObserver(std::shared_ptr<Character> c) : character(c) {}

void CharacterObserver::update() {
    std::cout << "⚡ Character Updated! ⚡\n";
    std::cout << "Name: " << character->getName() << "\n";
    std::cout << "Health: " << character->getHealth() << "\n";
    std::cout << "Attack Power: " << character->getAttackPower() << "\n\n";
}
