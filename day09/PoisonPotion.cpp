/*
** EPITECH PROJECT, 2022
** day09
** File description:
** PoisonPotion
*/

#include "PoisonPotion.hpp"

PoisonPotion::PoisonPotion()
{
    this->type = 0;
    this->health = -50;
    this->power = 0;
}

PoisonPotion::~PoisonPotion()
{
}

int PoisonPotion::getType() const
{
    return this->type;
}

int PoisonPotion::getValue() const
{
    return this->health;
}
