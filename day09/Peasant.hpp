/*
** EPITECH PROJECT, 2022
** day09
** File description:
** Peasant
*/

#include <string>
#include "ICharacter.hpp"

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

class Peasant : virtual public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;

        virtual int attack() override;
        virtual int special() override;
        virtual void rest() override;
        virtual void damage(int damage) final;
        void drink(const IPotion &potion) override;
        void drink(const HealthPotion &potion) override;
        void drink(const PoisonPotion &potion) override;
        void drink(const PowerPotion &potion) override;

    protected:
        std::string *_name;
        int _power;
        int _hp = 100;
};

#endif /* !PEASANT_HPP_ */
