//
// Created by alexandre majda on 28/12/2020.
//

#ifndef MENU_MENU_H
#define MENU_MENU_H

#include <button.h>

class Menu {

private:
    std::vector<Button> _menuElements;
public:

    void fillMenu();
    void draw(sf::RenderWindow& window);
    void setRectanglesPosition(float windowX, float windowY);

};


#endif //MENU_MENU_H
