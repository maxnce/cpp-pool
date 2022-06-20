/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"
#include <iostream>

void Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    auto firePtr = this->firePtr;
    (ship->*firePtr)(target);
}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    auto movePtr = this->movePtr;
    return (ship->*movePtr)(dest);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    auto destroyPtr = this->destroyPtr;
    (ship->*destroyPtr)(target);
}
