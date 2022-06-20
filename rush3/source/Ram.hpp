/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "IMonitorModule.hpp"
#include <ncurses.h>
#include <SFML/Graphics.hpp>

class Ram : public IMonitorModule {
    public:
        Ram();
        ~Ram();

        void setActive(bool activate) {this->_isActivated = activate;};
        void display(int &x, int &y, SystemProperties sys);
    void display(int &x, int &y, SystemProperties sys, sf::RenderWindow *win, sf::Texture *tex);
        moduleType getType() const {return this->_modType;};
        bool getActive() const {return this->_isActivated;};
        bool getSelect(void) const {return this->_isSelected;};
        void setSelect(bool select) {_isSelected = select;};

    protected:
    private:
        WINDOW *tempBox;
    sf::RectangleShape *_box;
    sf::RectangleShape *_border;
    sf::RectangleShape *_bar;
    sf::Text _texte;
    sf::Text _texte2;
    sf::Font font;
    float _x;
    float _y;
    
};

#endif /* !RAM_HPP_ */
