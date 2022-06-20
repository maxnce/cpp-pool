/*
** EPITECH PROJECT, 2022
** day09
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
#define IPOTION_HPP_

class IPotion {
    public:
        IPotion() {};
        ~IPotion() {};
        virtual int getType() const = 0;
        virtual int getValue() const = 0;
        bool isParent() const {
            return true;
        }

    protected:
        int type = -1;
        int health;
        int power;
    private:
};

#endif /* !IPOTION_HPP_ */
