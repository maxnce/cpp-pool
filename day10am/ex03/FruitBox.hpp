/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"

typedef struct FruitNode_t FruitNode;
struct FruitNode_t {
    Fruit *fruit = nullptr;
    FruitNode *next = nullptr;
    bool slotEmpty = true;
};

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();

        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;

        FruitBox(const FruitBox&) = delete;
        void operator=(const FruitBox&) = delete;

    protected:
    private:
        int size;
        FruitNode  *fruitList = nullptr;
};

#endif /* !FRUITBOX_HPP_ */
