#include <SFML/Graphics.hpp>
#include <button.h>
#include <menu.h>
#include <iostream>

int main() {

    const float windowWidth(1200), windowHeight(700);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    window.setFramerateLimit(60);

    Menu menu;

    int index;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed &&
                (event.key.code == sf::Keyboard::Left)) {
                index = menu.getSelectedButtonIndex();
                for(Button button : menu.getMenuElements())
                    button.setSelected(false);
                if (index == 0)
                    index = menu.getMenuElements().size();
                menu.getMenuElements()[index].setSelected(true);
            }
            if (event.type == sf::Event::KeyPressed &&
                (event.key.code == sf::Keyboard::Right)) {
                index = menu.getSelectedButtonIndex();
                for(Button button : menu.getMenuElements())
                    button.setSelected(false);
                if (index ==(int) menu.getMenuElements().size())
                    index = 0;
                menu.getMenuElements()[index].setSelected(true);
            }
        }

        window.clear(sf::Color::Black);


        menu.setRectanglesPosition(windowWidth, windowHeight);
        menu.draw(window);

        window.display();
    }

    return 0;
}
