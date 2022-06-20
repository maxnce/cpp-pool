/*
** EPITECH PROJECT, 2022
** day11
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_
#include "Toy.hpp"
#include <string>

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();

        static void tellMeAStory(std::string fp, Toy toy1, bool (Toy::*func1)(const std::string &), Toy toy2, bool (Toy::*func2)(const std::string &));

    protected:
    private:
};

#endif /* !TOYSTORY_HPP_ */
