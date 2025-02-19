#ifndef CHARACTER_OBSERVER_H
#define CHARACTER_OBSERVER_H

#include "Observer.h"
#include "Character.h"
#include <memory>
#include <iostream>

/**
 * @class CharacterObserver
 * @brief Observer that monitors a Character and updates when notified.
 */
class CharacterObserver : public Observer {
private:
    std::shared_ptr<Character> character; /**< Character being observed */

public:
    /**
     * @brief Constructor for CharacterObserver.
     * @param c The character to observe.
     */
    CharacterObserver(std::shared_ptr<Character> c);

    /**
     * @brief Update method called when the character changes.
     */
    void update() override;
};

#endif
