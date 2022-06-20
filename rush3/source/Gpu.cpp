/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** Gpu
*/

#include "Gpu.hpp"
#include <sstream>

Gpu::Gpu() : IMonitorModule(GPU)
{
    this->_ncursesWidth = 90;
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

Gpu::~Gpu()
{
}

void Gpu::getGpuStats(SystemProperties sys, float stats[])
{

    for (int i = 0; i < atoi(sys.getCpuCores().c_str()); i++) {
        std::string line = parse("cpu" + std::to_string(i), "/proc/stat").substr(5);
        std::stringstream linestream(line);
        int user;
        int nice;
        int system;
        int idle;
        int iowait;
        int irq;
        int softirq;
        int steal;
        int guest;
        int guest_nice;
        linestream >> user;
        linestream >> nice;
        linestream >> system;
        linestream >> idle;
        linestream >> iowait;
        linestream >> irq;
        linestream >> softirq;
        linestream >> steal;
        linestream >> guest;
        linestream >> guest_nice;
        stats[i] = 100.0 -
        ((static_cast<float>((idle + iowait)) /
        static_cast<float>((user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice))) * 100.0);
    }

}

void Gpu::display(int &x, int &y, SystemProperties sys)
{
    if (x + this->_ncursesWidth > COLS) {
        x = this->_ncursesWidth;
        y++;
    } else {
        x += this->_ncursesWidth;
    }
    tempBox = subwin(stdscr, 25, this->_ncursesWidth, y * 5, x - this->_ncursesWidth);
    wclear(tempBox);
    wborder(tempBox, 0, 0, 0, 0, 0, 0, 0, 0);
    attron(COLOR_PAIR(1));
    mvprintw(y * 5, x - this->_ncursesWidth + 2, ("> GPU" + sys.getCpuModel()).c_str());
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(this->getSelect() ? 4 : 3));
    mvprintw(y * 5, x - 2, "X");
    attroff(COLOR_PAIR(this->getSelect() ? 4 : 3));
    int cpuCounter = 0;
    float gpuStats[128];
    getGpuStats(sys, gpuStats);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < atoi(sys.getCpuCores().c_str()) / 4 && cpuCounter < atoi(sys.getCpuCores().c_str()); j++, cpuCounter++) {
            WINDOW *temp = subwin(stdscr, 10, 20, y * 5 + (j * 10 + 2), x - this->_ncursesWidth + (i * 20 + 4));
            wborder(temp, 0, 0, 0, 0, 0, 0, 0, 0);
            mvwprintw(temp, 8, 1, std::string("0%%").c_str());
            mvwprintw(temp, 1, 1, std::string("100%%").c_str());
            for (int i = 0; i < 8; i++) {
                attron(COLOR_PAIR(gpuStats[cpuCounter] < 12.5 * i ? 3 : 2));
                mvwprintw(temp, 8 - i, 6, "-");
                attroff(COLOR_PAIR(2));
            }
            mvwprintw(temp,  0, 2, ("CPU " + std::to_string(cpuCounter) + ": " + std::to_string(gpuStats[cpuCounter]) + "%%").c_str());
            wrefresh(temp);
        }
    }
    wrefresh(tempBox);
}

void Gpu::display(int &x, int &y, SystemProperties sys, sf::RenderWindow *win, sf::Texture *text)
{
    sf::Vector2f vec(x + 10, y+10);
    sf::Vector2f size = _box->getSize();
    (void)sys;

    _box->setTexture(&(*text));
    _box->setTextureRect(sf::Rect<int>(vec.x, vec.y, size.x, size.y));
    _box->setPosition(vec);
    win->draw(*this->_box);
    _texte2.setString("GPU:");
    _texte2.setPosition(sf::Vector2f(vec.x, vec.y));
    win->draw(_texte2);
    x = x + _x;
}
