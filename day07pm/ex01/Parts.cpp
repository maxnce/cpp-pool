/*
** EPITECH PROJECT, 2022
** day07pm
** File description:
** Parts
*/

#include "Parts.hpp"
#include <iostream>

Arms::Arms(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Head::Head(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Legs::Legs(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

bool Legs::isFunctional(void) const
{
    return this->_functional;
}

bool Arms::isFunctional(void) const
{
    return this->_functional;
}

bool Head::isFunctional(void) const
{
    return this->_functional;
}

std::string Legs::serial(void)
{
    return this->_serial;
}
std::string Arms::serial(void)
{
    return this->_serial;
}
std::string Head::serial(void)
{
    return this->_serial;
}

void Legs::informations(void) const
{
    std::cout << "\t[Parts] Legs " << this->_serial << " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}

void Arms::informations(void) const
{
    std::cout << "\t[Parts] Arms " << this->_serial << " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}

void Head::informations(void) const
{
    std::cout << "\t[Parts] Head " << this->_serial << " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}