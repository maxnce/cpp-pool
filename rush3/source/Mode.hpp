

#ifndef MODE_H
#define MODE_H
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include "IMonitorModule.hpp"
#include "ModulList.hpp"
#include "IMonitorDisplay.hpp"

class mySfml : public IMonitorDisplay {
public:
    mySfml(int x, int y);
    ~mySfml();
    void event(ListModul *mod);
    void display(int &x, int &y, SystemProperties _info, IMonitorModule *tmp);
    void clear(bool stat);
    bool isActive() {
        return this->_active;
    };
private:
    sf::RenderWindow _win;
    sf::Event _event;
    sf::Sprite *_window;
    sf::Texture texture;
};




class myNcurse : public IMonitorDisplay {
public:
    myNcurse(int x, int y);
    ~myNcurse();
    void event(ListModul *mod);
    void display(int &x, int &y, SystemProperties _info, IMonitorModule *tmp); 
    void clear(bool stat);
    bool isActive() {
        return this->_active;
    };
  
private:
};
#endif
