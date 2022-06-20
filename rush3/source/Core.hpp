
#ifndef CORE_H
#define CORE_H

#include "ModulList.hpp"
#include "Mode.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

enum displayType {
    TEXT,
    GRAPHICAL
};

class Core {
public:
    Core(displayType type);
    ~Core();
    void display();
    void event();
    void update_core();
    bool isFunctionnal();
    IMonitorModule *generate_mod(moduleType mod);
        
private:
    IMonitorDisplay *_graph; //sfml or ncurse
    SystemProperties _info; // for the info
    displayType _type;
    bool _works;
    ListModul *_modul;

};
#endif
