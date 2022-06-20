/*
** EPITECH PROJECT, 2022
** day09
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
#define POISONPOTION_HPP_

#include "IPotion.hpp"

class PoisonPotion : virtual public IPotion {
    public:
        PoisonPotion();
        ~PoisonPotion();

        int getType() const override;
        int getValue() const override;
        virtual bool isParent() const {
            return false;
        }

    protected:
    private:
};

#endif /* !POISONPOTION_HPP_ */
