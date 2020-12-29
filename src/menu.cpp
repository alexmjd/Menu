//
// Created by alexandre majda on 28/12/2020.
//

#include <menu.h>
#include <iostream>

Menu::Menu() {
    fillMenu(3);
}

Menu::~Menu() {}

/**
 * Put `limit` buttons in the menu
 */
void Menu::fillMenu(int limit) {
    for (int i = 0; i < limit; i++) {
        Button button;
        button.setIndex(i);
        _menuElements.push_back(button);
    }
    _menuElements[0].setSelected(true);
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
    for(Button button: _menuElements) {
        std::cout << "Button index :: " << button.getIndex() << std::endl;
        button.setTextButton("Button " + std::to_string(button.getIndex()));
        button.changeAspect();
        button.draw(window);
    }
}

std::vector<Button>& Menu::getMenuElements() {
    return _menuElements;
}

int Menu::getSelectedButtonIndex()
{
    auto it = std::find_if(_menuElements.begin(), _menuElements.end(), [&](Button const& obj) {return obj.isSelected();});
    return it->getIndex();
}