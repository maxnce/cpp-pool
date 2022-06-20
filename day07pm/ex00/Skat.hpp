/*
** EPITECH PROJECT, 2022
** day07pm
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        const std::string &name();

        void shareStimPaks(int number, int &stock);
        void addStimPaks(int number);
        void useStimPaks();
        void status() const;

    private:
        const std::string _name;
        int _stimPaks;
};

#endif /* !SKAT_HPP_ */
