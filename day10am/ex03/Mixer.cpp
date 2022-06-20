/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** Mixer
*/

#include "Mixer.hpp"

int mixFruits(FruitBox &fruits)
{
    int vitamins = 0;
    FruitNode *temp = fruits.head();

    while (temp != nullptr) {
        vitamins += temp->fruit->getVitamins();
        temp = temp->next;
    }
    return vitamins;
}

Mixer::Mixer()
{
    this->_plugged = false;
    this->_mixfunc = &mixFruits;
}

Mixer::~Mixer()
{
}

void Mixer::plugMixer()
{
    this->_plugged = true;
}