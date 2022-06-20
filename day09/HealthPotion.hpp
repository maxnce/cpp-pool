/*
** EPITECH PROJECT, 2022
** day09
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
#define HEALTHPOTION_HPP_

#include "IPotion.hpp"

class HealthPotion : virtual public IPotion {
    public:
        HealthPotion();
        ~HealthPotion();

        int getType() const override;
        int getValue() const override;
        bool isParent() const {
            return false;
        }

    protected:
    private:
};

#endif /* !HEALTHPOTION_HPP_ */
