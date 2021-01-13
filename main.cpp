#include <SFML/Graphics.hpp>
#include <menu.h>
#include <iostream>
#include <text_manager.h>

int main() {

    const float windowWidth(2500), windowHeight(1500);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    window.setFramerateLimit(60);


    TextManager textManager;

    Menu menu;
    std::string str;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                menu.moveCursor(event, menu.getSelectedButtonIndex());
                str = menu.triggerButton(event);
                textManager.setText(str, windowWidth/2, windowHeight);

                // Dunno why i need to reset textOrigin, while it's already done in `textManager.setText()`
                textManager.getText().setOrigin(textManager.getText().getGlobalBounds().width /2, textManager.getText().getGlobalBounds().height*2);
            }
        }

        window.clear(sf::Color::Black);

        menu.setRectanglesPosition(windowWidth, windowHeight);
        menu.draw(window);
        window.draw(textManager.getText());

        window.display();
    }

    return 0;
}
