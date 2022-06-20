/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include <iostream>
#include <array>

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


FruitBox *const *LittleHand::organizeCoconut(Coconut const *const *coconuts)
{
    size_t coconutsNb = 0;
    int coconutIndex = 0;
    while (coconuts[coconutsNb] != nullptr) coconutsNb++;
    FruitBox **boxes = new FruitBox*[coconutsNb];
    size_t compare = coconutsNb % 6 != 0 ? (coconutsNb / 6) + 1 : (coconutsNb / 6);

    for (size_t i = 0; i < compare; i++) {
        boxes[i] = new FruitBox(6);
        for (size_t j = 0; j < 6  && coconuts[coconutIndex] != nullptr; j++, coconutIndex++) {
            boxes[i]->putFruit((Fruit *)coconuts[coconutIndex]);
        }
    }
    boxes[coconutsNb] = nullptr;
    return boxes;
}

void LittleHand::plugMixer(MixerBase &mixer)
{
    Mixer *test = reinterpret_cast<Mixer *>(&mixer);
    if (!test) return;
    test->plugMixer();
}