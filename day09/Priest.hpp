/*
** EPITECH PROJECT, 2022
** day09
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : virtual public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        virtual void rest() override;

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
