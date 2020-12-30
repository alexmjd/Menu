#include <SFML/Graphics.hpp>
#include <menu.h>
#include <iostream>

int main() {

    const float windowWidth(1200), windowHeight(700);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    window.setFramerateLimit(60);

    std::string _path;
    sf::Font font;
    sf::Text t;

    #if _WIN64
        _path = "C:\\Windows\\Fonts\\";
    #elif __MACH__
        _path = "/System/Library/Fonts/Supplemental/";
    #endif

    _path += "arial.ttf";

    if (!font.loadFromFile(_path))
        std::cout << "Error loading font." << std::endl;

    t.setFont(font);
    t.setFillColor(sf::Color::White);
    t.setPosition(windowWidth/2, windowHeight);
    t.setOrigin(t.getGlobalBounds().width / 2, t.getGlobalBounds().height*2);

    Menu menu;
    std::string str;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed) {
//                buttonIndex = menu.getSelectedButtonIndex();
                menu.moveCursor(event, menu.getSelectedButtonIndex());
                str = menu.triggerButton(event);
                t.setString(str);
                // Need to setup origin when you change the string of sf::Text
                t.setOrigin(t.getGlobalBounds().width / 2, t.getGlobalBounds().height*2);
            }
        }

        window.clear(sf::Color::Black);

        menu.setRectanglesPosition(windowWidth, windowHeight);
        menu.draw(window);
        window.draw(t);

        window.display();
    }

    return 0;
}
