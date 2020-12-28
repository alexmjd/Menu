//
// Created by alexandre majda on 28/12/2020.
//

#include "button.h"
#include <iostream>

Button::Button(float windowX, float windowY) {
    _rect.setSize(sf::Vector2(_buttonWidth, _buttonHeight));
    _rect.setOrigin(_buttonWidth / 2, _buttonHeight /2);
    _rect.setPosition(windowX, windowY);

    std::string path;
#if _WIN64
    path = "C:\\Windows\\Fonts\\";
#elif __MACH__
    path = "/System/Library/Fonts/Supplemental/";
#endif
    path += "arial.ttf";

    if (!_font.loadFromFile(path))
        std::cout << "Error loading font." << std::endl;


    _text.setFont(_font);
    _text.setFillColor(sf::Color::Red);
    _text.setCharacterSize(40);
    setTextButton("I am a button");
}

Button::~Button() {}

sf::RectangleShape Button::getRectangle() const {
    return _rect;
}

void Button::setRectanglePosition(float x, float y) {
    _rect.setPosition(x, y);
}

void Button::setTextButton(std::string str) {
    _text.setString(str);
    _text.setOrigin(_text.getGlobalBounds().width / 2, _text.getLocalBounds().height);
    _text.setPosition(_rect.getPosition().x, _rect.getPosition().y);
}

sf::Text Button::getTextButton() const {
    return _text;
}

bool Button::isSelected() const {
    return _selected;
}

void Button::setSelected(bool select) {
    _selected = select;
}

void Button::changeAspect() {
    if (isSelected()) {
        _rect.setFillColor(sf::Color::Green);
        _text.setFillColor(sf::Color::White);
    } else {
        _rect.setFillColor(sf::Color::White);
        _text.setFillColor(sf::Color::Red);
    }
}
