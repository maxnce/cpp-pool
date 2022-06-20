/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** Kernel
*/

#include "Kernel.hpp"

Kernel::Kernel() : IMonitorModule(OSKERNEL)
{
    this->_ncursesWidth = 30;
    _x = 250.0;
    _y = 150.0;
    _box = new sf::RectangleShape();
    _box->setSize(sf::Vector2f(_x, _y));
    _box->setOutlineThickness(5.0);
    _box->setOutlineColor(sf::Color(242, 98, 247));
    font.loadFromFile("ARIAL.TTF");
    _texte.setFont(font);
    _texte.setCharacterSize(16);
    _texte.setFillColor(sf::Color(40,255,40));
    _texte2.setFont(font);
    _texte2.setCharacterSize(16);
    _texte2.setFillColor(sf::Color(255,20,30));
}

Kernel::~Kernel()
{
}

void Kernel::display(int &x, int &y, SystemProperties sys)
{
    if (("Kernel: " + sys.getRelease()).length() + 5 > 30 || ("OS:  " + sys.getSysName()).length() + 5 > 30) {
        this->_ncursesWidth = std::max(("Kernel: " + sys.getRelease()).length(), ("OS:  " + sys.getSysName()).length()) + 10;
    } 
    if (x + this->_ncursesWidth > COLS) {
        x = this->_ncursesWidth;
        y++;
    } else {
        x += this->_ncursesWidth;
    }
    tempBox = subwin(stdscr, 5, this->_ncursesWidth, y * 5, x - this->_ncursesWidth);
    wclear(tempBox);
    wborder(tempBox, 0, 0, 0, 0, 0, 0, 0, 0);
    attron(COLOR_PAIR(1));
    mvprintw(y * 5, x - this->_ncursesWidth + 2, "> OS & Kernel");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(this->getSelect() ? 4 : 3));
    mvprintw(y * 5, x - 2, "X");
    attroff(COLOR_PAIR(this->getSelect() ? 4 : 3));
    mvprintw(y * 5 + 2, x - this->_ncursesWidth + 6, ("OS: " + sys.getSysName()).c_str());
    mvprintw(y * 5 + 3, x - this->_ncursesWidth + 6, ("Kernel: " + sys.getRelease()).c_str());
    wrefresh(tempBox);
}

void Kernel::display(int &x, int &y, SystemProperties sys, sf::RenderWindow *win, sf::Texture *text)
{
    sf::Vector2f vec(x +10, y+10);
    sf::Vector2f size = _box->getSize();

    _box->setTexture(&(*text));
    _box->setTextureRect(sf::Rect<int>(vec.x, vec.y, size.x, size.y));
    _box->setPosition(vec);
    win->draw(*this->_box);
    _texte2.setString("OS & Kernel:");
    _texte2.setPosition(sf::Vector2f(vec.x, vec.y));
    win->draw(_texte2);
    
    _texte.setString(("OS: " + sys.getSysName()).c_str());
    _texte.setPosition(sf::Vector2f(vec.x + 10, vec.y + (size.y/2) -10));
    win->draw(_texte);
    _texte.setString(("Kernel: " + sys.getRelease()).c_str());
    _texte.setPosition(sf::Vector2f(vec.x + 10, vec.y + (size.y/2) + 8));
    win->draw(_texte);
    x = x + _x;
}
