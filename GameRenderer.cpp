#include "GameRenderer.h"

GameRenderer::GameRenderer(int width, int height) 
    : window(sf::VideoMode(sf::Vector2u(width * 50, height * 50)), "Tower Defense Game") {
    
    if (!loadFont("arial.ttf")) {
        std::cerr << "Error loading font arial.ttf!\n";
    }

    text.setFont(font);
    text.setString(""); // Initialize text correctly
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    tile.setSize(sf::Vector2f(50, 50)); // Ensure tile is initialized
}

bool GameRenderer::loadFont(const std::string& fontPath) {
    return font.openFromFile(fontPath);
}

void GameRenderer::handleEvents() {
    while (auto event = window.pollEvent()) { // Correct usage of std::optional
        if (event->type == sf::Event::Closed) {
            window.close();
        }
    }
}


void GameRenderer::drawMap(const Map& gameMap) {
    window.clear();

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            tile.setPosition(sf::Vector2f(x * 50, y * 50));  // Fix for SFML 3.0

            if (gameMap.getCellType(x, y) == 'P') {
                tile.setFillColor(sf::Color(150, 75, 0));  // Brown path
            } else {
                tile.setFillColor(sf::Color(0, 100, 0));  // Green scenery
            }

            window.draw(tile);
        }
    }

    window.display();
}

void GameRenderer::run(Map& gameMap) {
    while (window.isOpen()) {
        handleEvents();
        drawMap(gameMap);
    }
}






