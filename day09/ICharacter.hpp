/*
** EPITECH PROJECT, 2022
** day09
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"

class ICharacter {
    public:
        ICharacter() {};
        virtual ~ICharacter() {};

        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual const std::string &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual void damage(int damage) = 0;
        virtual void drink(const IPotion &potion) = 0;
        virtual void drink(const HealthPotion &potion) = 0;
        virtual void drink(const PoisonPotion &potion) = 0;
        virtual void drink(const PowerPotion &potion) = 0;

    protected:
        std::string *_name;
        int _power;
        int _hp = 100;
    private:
};

#endif /* !ICHARACTER_HPP_ */
