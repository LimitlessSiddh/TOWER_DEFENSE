#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @class Observer
 * @brief Interface for Observer Pattern.
 *
 * Observers must implement `update()` to be notified of changes.
 */
class Observer {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Observer() {}

    /**
     * @brief Method called when an observed object is updated.
     */
    virtual void update() = 0;
};

#endif
