/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** Admiral
*/

#include "Admiral.hpp"
#include <iostream>

Federation::Starfleet::Admiral::Admiral(std::string name)
: _name {name}
{
    std::cout << "Admiral " << name << " ready for action." << std::endl;
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    auto firePtr = this->firePtr;
    if (target == NULL || ship == NULL)
        return;
    std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
    (ship->*firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    auto movePtr = this->movePtr;
    if (ship == NULL)
        return false;
    return (ship->*movePtr)(dest);
}
