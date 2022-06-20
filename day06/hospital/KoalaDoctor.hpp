/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <string>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();

        /* Methods */
        void diagnose(SickKoala *patient);
        void timeCheck();
        std::string getName(void);

    protected:
        bool _is_working; 
    private:
        std::string name;
};

#endif /* !KOALADOCTOR_HPP_ */
