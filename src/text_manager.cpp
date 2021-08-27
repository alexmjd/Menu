//
// Created by alexandre majda on 30/12/2020.
//

#include <text_manager.h>


TextManager::TextManager() {
    loadFont();
    _text.setString("Basic Button");
}

/**
 * Set font path by OS. Default font is arial (define in header file)
 * @param font
 */
void TextManager::loadFont(std::string strFont) {
    std::string _path;

    #if _WIN64
        _path = "C:\\Windows\\Fonts\\";
    #elif __MACH__
        _path = "/System/Library/Fonts/Supplemental/";
    #elif __linux__
        strFont = "Quicksand-Regular.ttf";
        _path = "../assets/fonts/";
    #endif

    _path += strFont;

    if (!_font.loadFromFile(_path))
        std::cout << "Error loading font." << std::endl;
}

sf::Text& TextManager::getText() {
    return _text;
}

/**
 * Set the font for the Text object (avoid SEGFAULT)
 * Set the text's string
 * Set origin involving text's string size
 *
 * @param str   string that would be display
 * @param posX  text position X (horizontal)
 * @param posY  text position Y (vertical)
 */
void TextManager::setText(std::string str, float posX, float posY) {
    _text.setFont(_font);
    _text.setString(str);
    _text.setPosition(posX, posY);
    _text.setOrigin(_text.getGlobalBounds().width / 2, _text.getGlobalBounds().height);
}