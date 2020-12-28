//
// Created by alexandre majda on 28/12/2020.
//

#include "button.h"
#include <iostream>

Button::Button(float windowX, float windowY) {
    _rect.setSize(sf::Vector2(_buttonWidth, _buttonHeight));
    _rect.setOrigin(_buttonWidth / 2, _buttonHeight /2);
    _rect.setPosition(windowX / 2, windowY / 2);
}

Button::~Button() {}

sf::RectangleShape Button::getRectangle() const {
    return _rect;
}

void Button::setText(sf::RenderWindow &window) {
    sf::Font font;

    if (!font.loadFromFile("../assets/fonts/Quicksand-Bold.ttf"))
        std::cout << "Error loading font." << std::endl;

    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(40);
    text.setString("I am a button");

    text.setOrigin(text.getLocalBounds().width / 2 , text.getLocalBounds().height);
    text.setPosition(_rect.getPosition().x, _rect.getPosition().y);

    window.draw(text);
}