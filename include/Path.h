#ifndef PATH_H
#define PATH_H

/**
 * @class Path
 * @brief Represents the path that critters follow.
 *
 * Path cells cannot have towers and only critters can move on them.
 */
class Path {
public:
    /**
     * @brief Get the character symbol representing a path.
     * @return 'P' character
     */
    static char getSymbol() { return 'P'; }
};

#endif
