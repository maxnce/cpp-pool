/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** Borg
*/

#include "Borg.hpp"
#include "Federation.hpp"
#include <iostream>

Borg::Ship::Ship(int weaponFrequency, short repair)
: _weaponFrequency {weaponFrequency}, _repair {repair}
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl
    << "Your biological characteristics and technologies will be assimilated." << std::endl
    << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore(void)
{
    if (this->_core == NULL)
        return;
    if (this->_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp > this->_maxWarp || d == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move(int warp)
{
    if (warp > this->_maxWarp || this->_home == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Borg::Ship::move(Destination d)
{
    if (d == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move(void)
{
    if (this->_home == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

int Borg::Ship::getShield(void)
{
    return (this->_shield);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency(void)
{
    return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair(void)
{
    return this->_repair;
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    if (target == NULL)
        return;
    target->setShield(target->getShield() - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}
void Borg::Ship::fire(Federation::Ship *target)
{
    if (target == NULL || !target->getCore())
        return;
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair(void)
{
    if (this->_repair > 0) {
        this->_repair--;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
        this->_shield = 100;
    } else {
        std::cout << "Energy cells depleted, shield weakening.\n" << std::endl;
    }
}