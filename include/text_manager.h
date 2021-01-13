//
// Created by alexandre majda on 30/12/2020.
//

#ifndef MENU_TEXT_MANAGER_H
#define MENU_TEXT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class TextManager {
private:


    sf::Text _text;
    sf::Font _font;


public:
    TextManager();

    sf::Text& getText();
    void setText(std::string str, float posX, float posY);

    void loadFont(std::string strFont = "arial.ttf");

};

#endif //MENU_TEXT_MANAGER_H
