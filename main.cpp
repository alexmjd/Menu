#include <SFML/Graphics.hpp>
#include <menu.h>
#include <iostream>

int main() {

    const float windowWidth(1200), windowHeight(700);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    window.setFramerateLimit(60);

    Menu menu;
    int buttonIndex;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                buttonIndex = menu.getSelectedButtonIndex();
                menu.triggerButton(event, buttonIndex);
                menu.moveCursor(event, buttonIndex);
            }
        }

        window.clear(sf::Color::Black);

        menu.setRectanglesPosition(windowWidth, windowHeight);
        menu.draw(window);

        window.display();
    }

    return 0;
}
