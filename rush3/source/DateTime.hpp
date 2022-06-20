/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** Hostname
*/

#ifndef DATETIME_HPP_
#define DATETIME_HPP_

#include "IMonitorModule.hpp"
#include <ncurses.h>

class DateTime : public IMonitorModule {
    public:
        DateTime();
        ~DateTime();

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
    sf::Text _texte;
    sf::Text _texte2;
    sf::Font font;
    float _x;
    float _y;
};

#endif /* !HOSTNAME_HPP_ */
