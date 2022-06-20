/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "ModulList.hpp"
#include "Sys.hpp"

class IMonitorDisplay {
    public:
        IMonitorDisplay(int x, int y) {_win_x = x; _win_y = y;};
        ~IMonitorDisplay() {};

        virtual void event(ListModul *mod) = 0;
        virtual void display(int &x, int &y, SystemProperties _info, IMonitorModule *tmp) = 0; 
        virtual void clear(bool stat) = 0;
        virtual bool isActive() = 0;
    protected:
        bool _active = true;
        int _win_x;
        int _win_y;
};

#endif /* !IMONITORDISPLAY_HPP_ */
