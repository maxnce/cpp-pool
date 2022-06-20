/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &fp = "buzz.txt");
        ~Buzz();

        void speak(const std::string &) override;
        bool speak_es(const std::string &) override;

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
