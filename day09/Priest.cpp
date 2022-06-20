/*
** EPITECH PROJECT, 2022
** day09
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << *this->_name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << *this->_name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return ;
    }
    if (this->_power < 0) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return ;
    }
    this->_power = 100;
    this->_hp = 100;
    std::cout << *this->_name << " prays." << std::endl;
}
