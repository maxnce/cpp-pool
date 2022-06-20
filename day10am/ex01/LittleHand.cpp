/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include <iostream>
#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitNode *temp = unsorted.head();
    FruitNode *base = unsorted.head();

    while (temp != nullptr && temp->fruit != nullptr) {
        if (dynamic_cast<Lime *>(temp->fruit)) {
            if (limes.putFruit(temp->fruit)) {
                temp->fruit = temp->next ? temp->next->fruit : nullptr;
                temp->next = temp->next ? temp->next->next : nullptr;
            } else temp = temp->next;
        } else if (dynamic_cast<Lemon *>(temp->fruit)) {
            if (lemons.putFruit(temp->fruit)) {
                temp->fruit = temp->next != nullptr && temp->next->fruit != nullptr ? temp->next->fruit : nullptr;
                temp->next = temp->next != nullptr ? temp->next->next : nullptr;
            } else temp = temp->next;
        } else if (dynamic_cast<Banana *>(temp->fruit)) {
            if (bananas.putFruit(temp->fruit)) {
                temp->fruit = temp->next ? temp->next->fruit : nullptr;
                temp->next = temp->next ? temp->next->next : nullptr;
            } else temp = temp->next;
        } else temp = temp->next;
    }
    while (base != nullptr) {
        if (base->next != nullptr && base->next->fruit == nullptr)
            base->next = nullptr;
        base = base->next;
    }
}