/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(int vitamins, std::string name)
{
    this->_vitamins = vitamins;
    this->_name = name;
}

Fruit::~Fruit()
{
}

std::string Fruit::getName()
{
    return this->_name;
}

int Fruit::getVitamins()
{
    return this->_vitamins;
}