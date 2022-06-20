/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Woody
*/

#include "Woody.hpp"
#include <iostream>

Woody::Woody(const std::string &name, const std::string &fp) : Toy(WOODY, name, fp)
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std::string &sentence)
{
    std::cout << "WOODY: " << this->getName() << " \"" << sentence << "\""<< std::endl;
    return true;
}