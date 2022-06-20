/*
** EPITECH PROJECT, 2022
** day09
** File description:
** PowerPotion
*/

#include "PowerPotion.hpp"

PowerPotion::PowerPotion()
{
    this->type = 1;
    this->health = 0;
    this->power = 50;
}

PowerPotion::~PowerPotion()
{
}

int PowerPotion::getType() const
{
    return this->type;
}

int PowerPotion::getValue() const
{
    return this->power;
}
