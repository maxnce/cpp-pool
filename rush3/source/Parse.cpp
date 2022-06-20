/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** parser
*/

#include <fstream>
#include <iostream>

std::string parse(std::string toGet, std::string file)
{
    std::ifstream f(file);
    std::string line;
    if (f.is_open()) {
        while (getline(f, line)) {
            if (line.find(toGet) != std::string::npos)
                return line;
        }
    }
    return std::string("");
}