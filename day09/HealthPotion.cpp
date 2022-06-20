/*
** EPITECH PROJECT, 2022
** day09
** File description:
** HealthPotion
*/

#include "HealthPotion.hpp"

HealthPotion::HealthPotion()
{
    this->type = 0;
    this->health = 50;
    this->power = 0;
}

HealthPotion::~HealthPotion()
{
}

int HealthPotion::getType() const
{
    return this->type;
}

int HealthPotion::getValue() const
{
    return this->health;
}
