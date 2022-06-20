/*
** EPITECH PROJECT, 2022
** day09
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << *this->_name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << *this->_name << " takes off his armor." << std::endl;
}

// int Knight::getPower() const
// {
//     return this->_power;
// }

// int Knight::getHp() const
// {
//     return this->_hp;
// }

// const std::string &knight::getName() const
// {
//     return *this->_name;
// }

int Knight::attack()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() <= 9) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << *this->_name << " strikes with his sword." << std::endl;
    this->_power -= 10;
    return 20;
}

int Knight::special()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power <= 29) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << *this->_name << " impales his enemy." << std::endl;
    this->_power -= 30;
    return 50;
}

void Knight::rest()
{
    if (this->_hp <= 0) {
        std::cout << *this->_name << " is out of combat." << std::endl;
        return ;
    }
    if (this->_power < 0) {
        std::cout << *this->_name << " is out of power." << std::endl;
        return ;
    }
    if (this->_power + 50 > 100)
        this->_power = 100;
    else
        this->_power += 50;
    std::cout << *this->_name << " eats." << std::endl;
}
