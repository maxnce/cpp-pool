/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <sstream>

Picture::Picture() : data {new std::string("")}
{
}

Picture::Picture(const std::string &file)
{
    this->data = new std::string("");
    getPictureFromFile(file);
}

Picture::Picture(const Picture &pic)
{
    data = new std::string(*pic.data);
}

Picture::~Picture()
{
}

Picture &Picture::operator=(const Picture &copy)
{
    if (this != &copy) {
        delete data;
        data = new std::string(*copy.data);
    }
    return *this;
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream contents(file);
    std::stringstream temp;

    if (contents.fail()) {
        *data = "ERROR";
        return false;
    }
    temp << contents.rdbuf();
    *data = temp.str();
    return true;
}
