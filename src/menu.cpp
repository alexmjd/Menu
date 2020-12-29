//
// Created by alexandre majda on 28/12/2020.
//

#include "menu.h"

Menu::Menu() {
    fillMenu(4);
}

Menu::~Menu() {}

/**
 * Put `limit` buttons in the menu
 */
void Menu::fillMenu(int limit) {
    for (int i = 1; i < limit; i++) {
        Button button;
        _menuElements.push_back(button);
    }
//    _menuElements[0].setSelected(true);
}

/**
 * Place each button in the menu
 * @param windowX
 * @param windowY
 */
void Menu::setRectanglesPosition(float windowX, float windowY) {
    float x;
    for (unsigned long i = 1; i < _menuElements.size()+1; i++) {
        x = windowX * i / (_menuElements.size()+1);
        _menuElements[i-1].setRectanglePosition(x, windowY / 2);
    }
}

/**
 * Draw each button with their own text
 * @param window
 */
void Menu::draw(sf::RenderWindow& window) {
    int i = 1;
    for(Button button: _menuElements) {
        button.setTextButton("Button " + std::to_string(i));
        button.changeAspect();
        window.draw(button.getRectangle());
        window.draw(button.getTextButton());
        i++;
    }
}

std::vector<Button>& Menu::getMenuElements() {
    return _menuElements;
}

int Menu::getSelectedButtonIndex()
{
    bool test = true;
    auto it = find_if(_menuElements.begin(), _menuElements.end(), [&test](const Button& obj) {return obj.isSelected() == test;});

    if (it != _menuElements.end())
    {
        // found element. it is an iterator to the first matching element.
        // if you really need the index, you can also get it:
        return std::distance(_menuElements.begin(), it);
//        auto index = std::distance(_menuElements.begin(), it);
    }
    return 0;

    int index = 0;
    for(Button button: _menuElements) {
        if (!button.isSelected())
            index++;
        else
            break;
    }

    if (index == (int)_menuElements.size())
        return 0;
    return index;
}