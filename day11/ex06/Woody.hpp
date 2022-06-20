/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &fp = "woody.txt");
        ~Woody();
        bool speak(const std::string &);

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
