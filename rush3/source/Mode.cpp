#include "Mode.hpp"
#include <ncurses.h>
#include "IMonitorModule.hpp"

const char *moduleTypeStrings[] = {"Core Monitor", "HostName", "OS & Kernel", "Time", "Ram", "Gpu"};

/*///////////////////SFML/////////////////////*/

mySfml::mySfml(int x, int y) : IMonitorDisplay(x, y), _win(sf::VideoMode(x, y), "KREOOG")
{
    texture.loadFromFile("source/font.jpg");
    _window = new sf::Sprite(texture);
}

mySfml::~mySfml()
{
}

void mySfml::event(ListModul *mod)
{
    (void)mod;
    while (_win.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _win.close();
    }
    if (!(_win.isOpen()))
        _active = false;
}

void mySfml::clear(bool stat)
{
    if (stat == true) {
        _win.clear();
        _win.draw(*_window);
    } else 
        _win.display();
}

void mySfml::display(int &x, int &y, SystemProperties info, IMonitorModule *tmp)
{
    if (x + 200 >= _win_x) {
        y +=160;
        x = 0;
    }
    if (tmp->getActive())
        tmp->display(x, y, info, &_win, &texture);
}

/**************Ncurse*****************/
myNcurse::myNcurse(int x, int y) : IMonitorDisplay(x, y)
{
    initscr();
    curs_set(0);
    noecho();
    start_color();
    nodelay(stdscr, true);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
}

myNcurse::~myNcurse()
{
    endwin();
}

void myNcurse::clear(bool stat)
{
    if (stat == true)
    { //true execute avant affichage false apre
        erase();
        timeout(1000);
    }
}

void myNcurse::display(int &x, int &y, SystemProperties info, IMonitorModule *tmp)
{
    if (tmp->getActive())
        tmp->display(x, y, info);
    else
    {
        attron(COLOR_PAIR(tmp->getSelect() ? 4 : 3));
        mvprintw(LINES - 1, 17 * static_cast<int>(tmp->getType()), moduleTypeStrings[tmp->getType()]);
        attroff(COLOR_PAIR(tmp->getSelect() ? 4 : 3));
    }
}

void myNcurse::event(ListModul *mod)
{
    refresh();
    ListModul *temp = mod;
    int key;
    if (COLS < 40)
    {
        while (COLS < 40)
        {
            erase();
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2, COLS / 2 - 7, "Too small terminal");
            attroff(COLOR_PAIR(1));
            refresh();
        }
    }
    key = getch();
    clear(true);
    switch (key)
    {
    case 'q':
        if (temp->getModul()->getSelect())
        {
            temp->getModul()->setSelect(false);
            for (; temp->getNext() != NULL; temp = temp->getNext())
                ;
            temp->getModul()->setSelect(true);
            return;
        }
        for (; !temp->getNext()->getModul()->getSelect(); temp = temp->getNext())
            ;
        temp->getModul()->setSelect(true);
        temp->getNext()->getModul()->setSelect(false);
        return;
    case 'd':
        if (temp->getModul()->getSelect())
        {
            temp->getModul()->setSelect(false);
            temp->getNext()->getModul()->setSelect(true);
            break;
        }
        for (; !temp->getNext()->getModul()->getSelect(); temp = temp->getNext())
            ;
        if (!temp->getNext()->getNext())
        {
            mod->getModul()->setSelect(true);
        }
        else
        {
            temp->getNext()->getNext()->getModul()->setSelect(true);
        }
        temp->getNext()->getModul()->setSelect(false);
        return;
        break;
    case 'p':
        for (; !temp->getModul()->getSelect(); temp = temp->getNext())
            ;
        temp->getModul()->setActive(!temp->getModul()->getActive());
        break;
    default:
        return;
    }
}
/******************************************/
