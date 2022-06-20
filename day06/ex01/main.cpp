/*
** EPITECH PROJECT, 2022
** day06
** File description:
** main
*/

#include <iostream>
#include <ios>
#include <string>
#include <fstream>
#include <iomanip>

int main(void)
{
    float temp;
    std::string type;

    std::cin >> temp >> type;
    std::cout << std::fixed << std::setw(16) << std::setprecision(3);
    if (type == "Celsius") {
        std::cout << temp / (5.0 / 9.0) + 32.0 << "      Fahrenheit" << std::endl;
    } else {
        if (type == "Fahrenheit") {
            std::cout << (5.0 / 9.0) * (temp - 32) << "         Celsius" << std::endl;
            return 0;
            }
        return 84;
    }
    return 0;
}