/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** main
*/

#include <iostream>
#include <exception>
#include <string>
#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cout << "Usage: ./MyGKrellm [-g/-t] {flags}" << std::endl;
        throw std::invalid_argument("av[1]");
    } else {
        if (ac >= 2 && (!std::string(av[1]).compare("-g") || !std::string(av[1]).compare("-t"))) {
            Core c(!std::string(av[1]).compare("-g") ? GRAPHICAL : TEXT);
            while (c.isFunctionnal() == true) {
                c.event();
                c.update_core();
                c.display();
            }
            return (0);
        }
        throw std::invalid_argument("av[1]");
    }
    return EXIT_SUCCESS;
}
