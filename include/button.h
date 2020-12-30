//
// Created by Bilbhur on 28/12/2020.
//

#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <SFML/Graphics.hpp>
#include <text_manager.h>

class Button {

private:
    sf::RectangleShape _rect;

    TextManager _textManager;

    float _buttonWidth{200.f};
    float _buttonHeight{150.f};

    int _index;
    std::string _path;
    bool _selected{false};

public:
    Button();
    Button(float windowX, float windowY);
    ~Button();

    sf::RectangleShape getRectangle() const;
    void setRectanglePosition(float x, float y);

    void setTextButton(std::string str);

    bool isSelected() const;
    void setSelected(bool select);

    int getIndex() const;
    void setIndex(int i);

    void changeAspect();
    void draw(sf::RenderWindow& window);
};


#endif //MENU_BUTTON_H
