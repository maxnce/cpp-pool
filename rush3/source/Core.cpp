/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** Core
*/

#include "Core.hpp"
#include "Hostname.hpp"

#include "DateTime.hpp"
#include "Kernel.hpp"
#include "Monitor.hpp"
#include "Ram.hpp"
#include "ModulList.hpp"
#include "Gpu.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

bool Core::isFunctionnal()
{
    return (_graph->isActive());
}

Core::Core(displayType type)
{
    std::string path = "modul.config";
    std::ifstream file(path);
    std::string fileLine;

    if (!(file.is_open())) {
        std::cerr << "be sure to have modul.config readable" << std::endl;
    }
    _type = type;
    _modul = new ListModul();
    _modul->addModul(generate_mod(MONITOR));
    _modul->addModul(generate_mod(HOSTNAME));
    _modul->addModul(generate_mod(OSKERNEL));
    _modul->addModul(generate_mod(DATETIME));
    _modul->addModul(generate_mod(RAM));
    _modul->addModul(generate_mod(GPU));
    while (getline(file, fileLine)) {
        std::stringstream lineStream(fileLine);
        int type;
        bool isEnabled;
        ListModul *temp = _modul;
        lineStream >> type;
        lineStream >> isEnabled;
        for (; temp; temp = temp->getNext()) {
            if (temp->getModul()->getType() == static_cast<moduleType>(type)) {
                temp->getModul()->setActive(isEnabled);
            }
        }
    }
    _modul->getModul()->setSelect(true);
    if (type == GRAPHICAL)
        _graph = new mySfml(1280, 700);
    else
        _graph = new myNcurse(800, 600);
}

Core::~Core()
{
}

IMonitorModule *Core::generate_mod(moduleType mod)
{
    switch (mod) {
    case OSKERNEL:
        return (new Kernel());
    case HOSTNAME:
        return (new Hostname());
    case DATETIME:
        return (new DateTime());
    case MONITOR:
        return (new Monitor());
    case RAM:
        return (new Ram());
    case GPU:
        return (new Gpu());
    default:
        return (NULL);
    }
    return (NULL);
}

void Core::update_core()
{
    _info = SystemProperties();
}


void Core::display()
{
    int x = 0;
    int y = 0;

    _graph->clear(true);
    for (ListModul *it = _modul; it != NULL; it = it->getNext()) {
        _graph->display(x, y, _info, it->getModul());    
    }
    _graph->clear(false); //enefectif for ncuse, display window for sfml

}

void Core::event()
{
    _graph->event(_modul);
} 
