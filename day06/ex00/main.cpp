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

int main(int ac, char **av)
{
    std::ifstream file;

    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 84;
        }
    for (int i = 1; i < ac; i++) {
        std::ifstream file(av[i]);
        if (file.fail())
            std::cerr << "my_cat: " << av[1] << ": No such file or directory" << std::endl;
        if (file.is_open())
            while (!file.eof()) {
                char c;
                file.get(c);
                if (!file.eof())
                    std::cout << c;
            }
    }
    return 0;
}