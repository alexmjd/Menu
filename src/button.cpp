//
// Created by alexandre majda on 28/12/2020.
//

#include "button.h"
#include <iostream>

Button::Button() {
    _rect.setSize(sf::Vector2(_buttonWidth, _buttonHeight));
    _rect.setOrigin(_buttonWidth / 2, _buttonHeight /2);
    _rect.setPosition(_buttonWidth / 2, _buttonHeight /2);

    setFontPath();

    _text.setFillColor(sf::Color::Red);
    _text.setCharacterSize(40);
}

Button::~Button() {}

sf::RectangleShape Button::getRectangle() const {
    return _rect;
}

void Button::setRectanglePosition(float x, float y) {
    _rect.setPosition(x, y);
}

void Button::setTextButton(std::string str) {
    // Setting font here to avoid SEGFAULT
    _text.setFont(_font);
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

int Button::getIndex() const {
    return _index;
}

void Button::setIndex(int i) {
    _index = i;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(_rect);
    window.draw(_text);
}

/**
 * Change button if selected
 */
void Button::changeAspect() {
    if (isSelected()) {
        _rect.setFillColor(sf::Color::Green);
        _text.setFillColor(sf::Color::White);
    } else {
        _rect.setFillColor(sf::Color::White);
        _text.setFillColor(sf::Color::Red);
    }
}

/**
 * Set font path by OS. Default font is arial
 * @param font
 */
void Button::setFontPath(std::string font) {
    // Different path by OS
#if _WIN64
    _path = "C:\\Windows\\Fonts\\";
#elif __MACH__
    _path = "/System/Library/Fonts/Supplemental/";
#endif

    _path += font;

    if (!_font.loadFromFile(_path))
        std::cout << "Error loading font." << std::endl;
}