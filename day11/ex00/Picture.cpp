/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <sstream>

Picture::Picture() : data {""}
{
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream contents(file);
    std::stringstream temp;

    if (contents.fail()) {
        data = "ERROR";
        return false;
    }
    temp << contents.rdbuf();
    data = temp.str();
    return true;
}
