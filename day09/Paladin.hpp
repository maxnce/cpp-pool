/*
** EPITECH PROJECT, 2022
** day09
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_
#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : virtual public Knight, virtual public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int attack();
        int special();
        void rest();

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
