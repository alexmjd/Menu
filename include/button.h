//
// Created by alexandre majda on 28/12/2020.
//

#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {

private:
    sf::RectangleShape _rect;

    float _buttonWidth{200.f};
    float _buttonHeight{150.f};

public:
    Button();
    Button(float windowX, float windowY);
    ~Button();

    sf::RectangleShape getRectangle() const;
    void setText(sf::RenderWindow& window);
};


#endif //MENU_BUTTON_H
