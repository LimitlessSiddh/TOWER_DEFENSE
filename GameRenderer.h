#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

class GameRenderer {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape tile;

    void handleEvents(); // New function to handle events

public:
    GameRenderer(int width, int height);
    bool loadFont(const std::string& fontPath); // New function to load font safely
    void drawMap(const Map& gameMap);
    void run(Map& gameMap);
};

#endif

