//
// Created by Bilbhur on 28/12/2020.
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
        button.setTextButton("Button " + std::to_string(button.getIndex()));
        button.changeAspect();
        button.draw(window);
    }
}

std::vector<Button>& Menu::getMenuElements() {
    return _menuElements;
}

/**
 * Find in the current menu which item is selected and return its index
 * @return
 */
int Menu::getSelectedButtonIndex()
{
    // Use lambda as predicate to return which object is selected in the vector
    auto it = std::find_if(_menuElements.begin(), _menuElements.end(), [&](Button const& obj) {
        return obj.isSelected();
    });
    return it->getIndex();
}

/**
 * On moving (left / right)
 * Set current selected button to false
 * Move the cursor depending on which key is pressed
 * @param event
 * @param index
 */
void Menu::moveCursor(sf::Event &event, int index) {

    if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
        getMenuElements()[index].setSelected(false);

    if (event.key.code == sf::Keyboard::Left) {
        if (index == 0)
            getMenuElements()[getMenuElements().size() - 1].setSelected(true);
        else
            getMenuElements()[index-1].setSelected(true);
    } else if (event.key.code == sf::Keyboard::Right) {
        if (index == (int)getMenuElements().size() - 1)
            getMenuElements()[0].setSelected(true);
        else
            getMenuElements()[index+1].setSelected(true);
    }
}

/**
 * Trigger the button with selected state and run some code
 * @param event
 * @param index
 */
std::string Menu::triggerButton(sf::Event &event) {

    std::string test = "";
    if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
        test = "Validation on " + std::to_string(getSelectedButtonIndex());
    return test;
}