/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
    public:
        Fruit(int vitamins, std::string name);
        virtual ~Fruit();
        virtual std::string getName();
        virtual int getVitamins();

    protected:
        int _vitamins;
        std::string _name;
    private:
};

#endif /* !FRUIT_HPP_ */
