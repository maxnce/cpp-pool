/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>
#include "Sys.hpp"
#include <SFML/Graphics.hpp>

enum moduleType {
    MONITOR,
    HOSTNAME,
    OSKERNEL,
    DATETIME,
    RAM,
    GPU
};

class IMonitorModule {
    public:
        IMonitorModule(moduleType modType) {_modType = modType;};
        ~IMonitorModule() {};

        virtual void setActive(bool activate) = 0;
        virtual void display(int &x, int &y, SystemProperties sys) = 0;
    virtual void display(int &x, int &y, SystemProperties sys, sf::RenderWindow *win, sf::Texture *text) = 0;
        virtual moduleType getType(void) const = 0;
        virtual bool getActive(void) const = 0;
        virtual bool getSelect(void) const = 0;
        virtual void setSelect(bool select) = 0;

    protected:
        moduleType _modType;
        bool _isActivated = true;
        int _ncursesWidth = 40;
        bool _isSelected = false;
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
