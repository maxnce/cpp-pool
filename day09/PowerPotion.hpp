/*
** EPITECH PROJECT, 2022
** day09
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
#define POWERPOTION_HPP_

#include "IPotion.hpp"

class PowerPotion : virtual public IPotion {
    public:
        PowerPotion();
        ~PowerPotion();

        int getType() const override;
        int getValue() const override;
        virtual bool isParent() const {
            return false;
        }

    protected:
    private:
};

#endif /* !POWERPOTION_HPP_ */
