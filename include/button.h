//
// Created by alexandre majda on 28/12/2020.
//

#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {

private:
    sf::RectangleShape _rect;
    sf::Font _font;
    sf::Text _text;

    float _buttonWidth{200.f};
    float _buttonHeight{150.f};

    bool _selected{false};

public:
    Button();
    Button(float windowX, float windowY);
    ~Button();

    sf::RectangleShape getRectangle() const;
    void setRectanglePosition(float x, float y);

    sf::Text getTextButton() const;
    void setTextButton(std::string str);

    bool isSelected() const;
    void setSelected(bool select);

    void changeAspect();
};


#endif //MENU_BUTTON_H
