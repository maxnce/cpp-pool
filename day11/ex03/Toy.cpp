/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Toy
*/

#include "Toy.hpp"
#include <iostream>

Toy::Toy() : _name {new std::string("toy")}, _picture {new Picture()}, _type {BASIC_TOY}
{
}

Toy::Toy(ToyType type, const std::string &name, const std::string &fp)
{
    this->_type = type;
    this->_name = new std::string(name);
    this->_picture = new Picture(fp);
}

Toy::Toy(const Toy &toy)
{
    this->_type = toy.getType();
    this->_name = new std::string(toy.getName());
    this->_picture = new Picture(*toy._picture);
}

Toy &Toy::operator=(const Toy &toy)
{
    if (this != &toy) {
        // delete this->_picture;
        // delete this->_name;
        this->_picture = new Picture(*toy._picture);
        this->_type = toy.getType();
        this->_name = new std::string(toy.getName());
    }
    return *this;
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
    return *this->_picture->data;
}

void Toy::speak(const std::string &sentence)
{
    std::cout << *this->_name << " \"" << sentence << "\"" << std::endl;
}