/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Buzz
*/

#include "Buzz.hpp"
#include <iostream>

Buzz::Buzz(const std::string &name, const std::string &fp) : Toy(BUZZ, name, fp)
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(const std::string &sentence)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << sentence << "\""<< std::endl;
    return true;
}

bool Buzz::speak_es(const std::string &sentence)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << sentence << "\" senorita"<< std::endl;
    return true;
}
