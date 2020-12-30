//
// Created by alexandre majda on 30/12/2020.
//

#ifndef MENU_TEXT_MANAGER_H
#define MENU_TEXT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class TextManager {
private:

//    static TextManager _instance;

    sf::Text _text;
    sf::Font _font;


//    TextManager(TextManager &textManager) = delete;
//    void operator=(const TextManager &) = delete;

public:
    TextManager();
//    TextManager(const TextManager&) = delete;
//    TextManager(TextManager&&) = delete;
//    TextManager& operator=(const TextManager&) = delete;
//    TextManager& operator=(TextManager&&) = delete;

    sf::Text& getText();
    void setText(std::string str, float posX, float posY);

//    static TextManager &getInstance();
    void loadFont(std::string strFont = "arial.ttf");

};

#endif //MENU_TEXT_MANAGER_H
