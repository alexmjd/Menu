#include <SFML/Graphics.hpp>
#include <button.h>

int main() {

    const float windowWidth(800), windowHeight(600);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    Button button(windowWidth, windowHeight);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(button.getRectangle());
        button.setText(window);

        window.display();
    }

    return 0;
}
