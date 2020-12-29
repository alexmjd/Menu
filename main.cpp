#include <SFML/Graphics.hpp>
#include <button.h>
#include <menu.h>
#include <iostream>

int main() {

    const float windowWidth(1200), windowHeight(700);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    window.setFramerateLimit(60);

    Menu menu;

//    int index;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed &&
                (event.key.code == sf::Keyboard::Left)) {
                // GetSelectedIndex
                int i = menu.getSelectedButtonIndex();
                menu.getMenuElements()[i].setSelected(false);
                if (i == 0)
                    menu.getMenuElements()[menu.getMenuElements().size() - 1].setSelected(true);
                else
                    menu.getMenuElements()[i-1].setSelected(true);

            }
            if (event.type == sf::Event::KeyPressed &&
                (event.key.code == sf::Keyboard::Right)) {
                int i = menu.getSelectedButtonIndex();
                menu.getMenuElements()[i].setSelected(false);
                if (i == (int)menu.getMenuElements().size() - 1)
                    menu.getMenuElements()[0].setSelected(true);
                else
                    menu.getMenuElements()[i+1].setSelected(true);
            }
        }

        window.clear(sf::Color::Black);


        menu.setRectanglesPosition(windowWidth, windowHeight);
        menu.draw(window);

        window.display();
    }

    return 0;
}
