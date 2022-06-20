/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include <iostream>

FruitBox::FruitBox(int size)
{
    this->size = size;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    int nbFruits = 0;
    FruitNode *temp = this->fruitList;

    for (; nbFruits < this->size && temp != nullptr; nbFruits++, temp = temp->next);
    return nbFruits;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *temp = this->fruitList;
    if (nbFruits() == this->size)
        return false;
    for (int i = 0; i < this->size && temp != nullptr; i++, temp = temp->next) {
        if (temp->fruit == f)
            return false;
    }
    if (nbFruits() == 0) {
        this->fruitList = new FruitNode;
        this->fruitList->fruit = f;
        this->fruitList->slotEmpty = false;
        return true;
    }
    temp = this->fruitList;
    for (int i = 0; i < this->size && temp->next != nullptr; i++, temp = temp->next);
    temp->next = new FruitNode;
    temp->next->fruit = f;
    temp->next->slotEmpty = false;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    if (this->fruitList == nullptr)
        return nullptr;
    Fruit *res = this->fruitList->fruit;
    this->fruitList = this->fruitList->next;
    return res;
}

FruitNode *FruitBox::head() const
{
    return this->fruitList;
}