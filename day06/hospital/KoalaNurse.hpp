/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaNurse
*/

#include <string>
#include "SickKoala.hpp"

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();

        /* Methods */
        void giveDrug(std::string drug, SickKoala *sick_koala);
        std::string readReport(std::string filename);
        void timeCheck(void);
        int getID(void);

    protected:
    private:
        bool _is_working;
        int id;
};

#endif /* !KOALANURSE_HPP_ */
