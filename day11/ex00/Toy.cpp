/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : _name {new std::string("toy")}, _picture {new Picture()}, _type {BASIC_TOY}
{
}

Toy::Toy(ToyType type, const std::string &name, const std::string &fp)
{
    this->_type = type;
    this->_name = new std::string(name);
    this->_picture = new Picture(fp);
}

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string Toy::getName() const
{
    return *this->_name;
}

void Toy::setName(const std::string &name)
{
    this->_name = new std::string(name);
}

bool Toy::setAscii(const std::string &file)
{
    return this->_picture->getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return this->_picture->data;
}