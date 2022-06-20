/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Coconut.hpp"
#include "MixerBase.hpp"
#include "Mixer.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();

        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        static FruitBox *const *organizeCoconut(Coconut const *const *coconuts);
        static void plugMixer(MixerBase &mixer);
    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
