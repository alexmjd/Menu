#include <SFML/Graphics.hpp>
#include <button.h>

int main() {

    const float windowWidth(800), windowHeight(600);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    window.setFramerateLimit(60);

    Button button(windowWidth / 3, windowHeight / 2);
    Button button2(2 * (windowWidth / 3), windowHeight / 2);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed &&
                (event.key.code == sf::Keyboard::Left)) {
                button.setSelected(true);
                button2.setSelected(false);
            }
            if (event.type == sf::Event::KeyPressed &&
                (event.key.code == sf::Keyboard::Right)) {
                button.setSelected(false);
                button2.setSelected(true);
            }
        }

        window.clear(sf::Color::Black);

        button.changeAspect();
        button2.changeAspect();

        window.draw(button.getRectangle());
        window.draw(button.getTextButton());

        window.draw(button2.getRectangle());
        window.draw(button2.getTextButton());

        window.display();
    }

    return 0;
}
