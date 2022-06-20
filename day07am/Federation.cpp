/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** Federation
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
: _length {length}, _width {width}, _name {name}, _maxWarp {maxWarp}, _photonTorpedo {torpedo}
{
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    if (this->_photonTorpedo != 0)
        std::cout << "Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship()
: _length {289}, _width {132}, _name {(std::string)"Entreprise"}, _maxWarp {6}, _photonTorpedo {0}
{
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
: _length {length}, _width {width}, _name {name}
{
    this->_maxWarp = 1;
    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    if (this->_core == NULL)
        return;
    std::cout << "USS " << this->_name
    << ": The core is " << (this->_core->checkReactor()->isStable() ? "stable" : "unstable")
    << " at the time."<< std::endl;
}

void Federation::Ship::checkCore(void)
{
    if (this->_core == NULL)
        return;
    std::cout << this->_name
    << ": The core is " << (this->_core->checkReactor()->isStable() ? "stable" : "unstable")
    << " at the time."<< std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
: _name {name}
{}

std::string Federation::Starfleet::Captain::getName(void)
{
    return this->_name;
}

int Federation::Starfleet::Captain::getAge(void)
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    if (captain == NULL)
        return;
    this->_captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS "
    << this->_name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
: _name {name}
{
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp > this->_maxWarp || d == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Ship::move(int warp)
{
    if (warp > this->_maxWarp || this->_home == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Federation::Ship::move(Destination d)
{
    if (d == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Ship::move(void)
{
    if (this->_home == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp > this->_maxWarp || d == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp > this->_maxWarp || this->_home == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Starfleet::Ship::move(void)
{
    if (this->_home == this->_location || !this->_core || !this->_core->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

int Federation::Starfleet::Ship::getShield(void)
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo(void)
{
    return this->_photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (target == NULL)
        return ;
    if (this->_photonTorpedo >= 1) {
        this->_photonTorpedo--;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50);
        if (this->_photonTorpedo == 0)
            std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    } else
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (target == NULL)
        return ;
    if (this->_photonTorpedo >= torpedoes) {
        this->_photonTorpedo -= torpedoes;
        std::cout << this->_name << ": Firing on target." << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50 * torpedoes);
        if (this->_photonTorpedo == 0)
            std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    } else
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return (this->_core);
}