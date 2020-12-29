//
// Created by alexandre majda on 28/12/2020.
//

#include "menu.h"

void Menu::fillMenu() {
    for (int i = 1; i < 4; i++) {
        Button button;
//        button.setRectanglePosition(i * x/2 , y/2);
//        Button button(i * (x / _menuElements.size()), y / 2);
        button.setTextButton("Button " + std::to_string(i));
//        button.setRectanglePosition(x * i / (_menuElements.size()+1), y / 2);
        _menuElements.push_back(button);
    }
}

void Menu::setRectanglesPosition(float windowX, float windowY) {
    float x;
    for (unsigned long i = 1; i < _menuElements.size()+1; i++) {
        x = windowX * i / (_menuElements.size()+1);
        _menuElements[i-1].setRectanglePosition(x, windowY / 2);
    }
}

void Menu::draw(sf::RenderWindow& window) {
    sf::Text text;
    int i = 1;
    for(Button button: _menuElements) {
        window.draw(button.getRectangle());
//        text = button.getTextButton();
//        text.setPosition(button.getRectangle().getPosition().x, button.getRectangle().getPosition().y);
//        window.draw(text);
        button.setTextButton("Button " + std::to_string(i));
        window.draw(button.getTextButton());
        i++;
    }
}