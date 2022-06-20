/*
** EPITECH PROJECT, 2022
** day08
** File description:
** Droid
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid(std::string serial)
{
    this->Id = serial;
    this->Status = new std::string("Standing by");
    this->BattleData = new DroidMemory;
    std::cout << "Droid '" << this->getId() << "' Activated" << std::endl;
}

Droid::Droid(const Droid &replicate)
{
    this->Id = replicate.getId();
    this->Status = new std::string(*replicate.getStatus());
    this->Energy = replicate.getEnergy();
    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete this->Status;
    std::cout << "Droid '" << this->getId() << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(const Droid &other)
{
    this->setId(other.getId());
    this->setStatus(new std::string(*other.getStatus()));
    this->setEnergy(other.getEnergy());
    return *this;
}

bool Droid::operator==(const Droid &other) const
{
    return (this->getStatus()->compare(*other.getStatus()) == 0);
}

bool Droid::operator!=(const Droid &other) const
{
    return !(this->getStatus()->compare(*other.getStatus()) == 0);
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        energy = 100;
    this->Energy = energy;
}

void Droid::setId(std::string id)
{
    this->Id = id;
}

void Droid::setStatus(std::string *status)
{
    delete this->Status;
    this->Status = status;
}

std::string Droid::getId(void) const
{
    return this->Id;
}

size_t Droid::getEnergy(void) const
{
    return this->Energy;
}

size_t Droid::getAttack(void) const
{
    return (this->Attack);
}

size_t Droid::getToughness(void) const
{
    return (this->Toughness);
}

std::string *Droid::getStatus(void) const
{
    return this->Status;
}

Droid &Droid::operator<<(size_t &energy)
{
    if (this->getEnergy() == 100 || energy == 0)
        return *this;
    if (this->getEnergy() + energy > 100) {
        size_t diff = 100 - this->getEnergy();
        this->setEnergy(100);
        energy -= diff;
        return *this;
    }
    this->setEnergy(this->getEnergy() + energy);
    energy = 0;
    return *this;
}

std::ostream &operator<<(std::ostream &s, const Droid &droid)
{
    s << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return s;
}

void Droid::setBattleData(DroidMemory *data)
{
    this->BattleData = data;
}

DroidMemory *Droid::getBattleData(void) const
{
    return this->BattleData;
}