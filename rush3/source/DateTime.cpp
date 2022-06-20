/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** DateTime
*/

#include "DateTime.hpp"

DateTime::DateTime() : IMonitorModule(DATETIME)
{
    this->_ncursesWidth = 40;

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

DateTime::~DateTime()
{
}
void DateTime::display(int &x, int &y, SystemProperties sys)
{
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
    mvprintw(y * 5, x - this->_ncursesWidth + 2, "> Date and time");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(this->getSelect() ? 4 : 3));
    mvprintw(y * 5, x - 2, "X");
    attroff(COLOR_PAIR(this->getSelect() ? 4 : 3));
    mvprintw(y * 5 + 2, x - this->_ncursesWidth + 6, ("¤" + sys.getDate().substr(0, 24)).c_str());
    wrefresh(tempBox);
}


void DateTime::display(int &x, int &y, SystemProperties sys, sf::RenderWindow *win, sf::Texture *text)
{
    sf::Vector2f vec(x+10, y+10);
    sf::Vector2f size = _box->getSize();

    _box->setTexture(&(*text));
    _box->setTextureRect(sf::Rect<int>(vec.x, vec.y, size.x, size.y));
    _box->setPosition(vec);
    win->draw(*this->_box);
    _texte2.setString("Date and time:");
    _texte2.setPosition(sf::Vector2f(vec.x, vec.y));
    win->draw(_texte2);
    _texte.setString(sys.getDate().substr(0, 24));
    _texte.setPosition(sf::Vector2f(vec.x + 10, vec.y + (size.y/2) -10));
    win->draw(_texte);
    x = x + _x;
}
