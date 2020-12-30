//
// Created by Bilbhur on 28/12/2020.
//

#include "button.h"
#include <iostream>

Button::Button() {
    _rect.setSize(sf::Vector2(_buttonWidth, _buttonHeight));
    _rect.setOrigin(_buttonWidth / 2, _buttonHeight /2);
    _rect.setPosition(_buttonWidth / 2, _buttonHeight /2);
}

Button::~Button() {}

sf::RectangleShape Button::getRectangle() const {
    return _rect;
}

void Button::setRectanglePosition(float x, float y) {
    _rect.setPosition(x, y);
}

void Button::setTextButton(std::string str) {
    _textManager.setText(str, _rect.getPosition().x, _rect.getPosition().y);
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
    window.draw(_textManager.getText());
}

/**
 * Change button if selected
 */
void Button::changeAspect() {
    if (isSelected()) {
        _rect.setFillColor(sf::Color::Green);
        _textManager.getText().setFillColor(sf::Color::White);
    } else {
        _rect.setFillColor(sf::Color::White);
        _textManager.getText().setFillColor(sf::Color::Red);
    }
}
