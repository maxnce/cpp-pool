/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** Ram
*/

#include "Ram.hpp"

Ram::Ram() : IMonitorModule(RAM)
{
    this->_ncursesWidth = 50;
    _x = 250.0;
    _y = 150.0;
    _box = new sf::RectangleShape();
    _box->setSize(sf::Vector2f(_x, _y));
    _box->setOutlineThickness(5.0);
    _box->setOutlineColor(sf::Color(242, 98, 247));

    _border = new sf::RectangleShape();
    _border->setSize(sf::Vector2f(100, 30));
    _border->setFillColor(sf::Color(255, 146, 8));
    
    _bar = new sf::RectangleShape();
    _bar->setFillColor(sf::Color(255, 236, 8));

    
    font.loadFromFile("ARIAL.TTF");
    _texte.setFont(font);
    _texte.setCharacterSize(16);
    _texte.setFillColor(sf::Color(40,255,40));
    _texte2.setFont(font);
    _texte2.setCharacterSize(16);
    _texte2.setFillColor(sf::Color(255,20,30));
}

Ram::~Ram()
{
}

void Ram::display(int &x, int &y, SystemProperties sys)
{
    if (("Monitor core: " + sys.getMachine()).length() + 5 > 30) {
        this->_ncursesWidth = ("RAM: " + sys.getMachine()).length() + 10;
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
    mvprintw(y * 5, x - this->_ncursesWidth + 2, "> RAM");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(this->getSelect() ? 4 : 3));
    mvprintw(y * 5, x - 2, "X");
    attroff(COLOR_PAIR(this->getSelect() ? 4 : 3));
    long long ram = atoll(sys.getTotalRam().c_str()) / 1000;
    long long usedRam = (ram * 1000 - atoll(sys.getFreeRam().c_str())) / 1000;
    mvprintw(y * 5 + 2, x - this->_ncursesWidth + 6, (std::string("Used ram: ") + std::to_string(usedRam) + "MiB / " + std::to_string(ram) + "MiB").c_str());
    mvprintw(y * 5 + 3, x - this->_ncursesWidth + 6, std::string("0%%").c_str());
    mvprintw(y * 5 + 3, x - this->_ncursesWidth + 32, std::string("100%%").c_str());
    for (int i = 1; i < 21; i++) {
        attron(COLOR_PAIR((static_cast<double>(usedRam) / static_cast<double>(ram)) * 100 < 5 * i ? 3 : 2));
        mvprintw(y * 5 + 3, x - this->_ncursesWidth + 9 + i, "|");
        attroff(COLOR_PAIR(2));
    }
    wrefresh(tempBox);
}

void Ram::display(int &x, int &y, SystemProperties sys, sf::RenderWindow *win, sf::Texture *text)
{
    sf::Vector2f vec(x + 10, y+10);
    sf::Vector2f size = _box->getSize();
    long long ram = atoll(sys.getTotalRam().c_str()) / 1000;
    long long usedRam = (ram * 1000 - atoll(sys.getFreeRam().c_str())) / 1000;
    double res = (usedRam *100 / ram);

    _box->setTexture(&(*text));
    _box->setTextureRect(sf::Rect<int>(vec.x, vec.y, size.x, size.y));
    _box->setPosition(vec);
    win->draw(*this->_box);
    
    _bar->setPosition(sf::Vector2f(vec.x + 50, vec.y + 102));
    _border->setPosition(sf::Vector2f(vec.x + 50, vec.y + 100));
    _bar->setSize(sf::Vector2f(res, 25));
    win->draw(*this->_border);
    win->draw(*this->_bar);
    
    _texte2.setString("Ram");
    _texte2.setPosition(sf::Vector2f(vec.x, vec.y));
    win->draw(_texte2);

    _texte.setString("Used ram:" + std::to_string(usedRam) + "MiB / " + std::to_string(ram) + "MiB");
    _texte.setPosition(sf::Vector2f(vec.x + 10, vec.y + (size.y/2) -10));
    win->draw(_texte);

    _texte.setString("0%");
    _texte.setPosition(sf::Vector2f(vec.x + 5, vec.y +100));
    win->draw(_texte);
    _texte.setString("100%");
    _texte.setPosition(sf::Vector2f(vec.x + 152, vec.y +100));
    win->draw(_texte);
    x = x + _x;
}
