/*
** EPITECH PROJECT, 2022
** day10am
** File description:
** Mixer
*/

#ifndef MIXER_HPP_
#define MIXER_HPP_
#include "MixerBase.hpp"

class Mixer : public MixerBase {
    public:
        Mixer();
        ~Mixer();

        void plugMixer(void);

    protected:
    private:
};

#endif /* !MIXER_HPP_ */
