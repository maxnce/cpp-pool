/*
** EPITECH PROJECT, 2022
** day06
** File description:
** SickKoala
*/

#include <string>

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

class SickKoala {
    public:
        /* Ctor & Dtor */
        SickKoala(std::string name);
        ~SickKoala();

        /* Fields */
        bool takeDrug(std::string drug);
        void overDrive(std::string sentence);
        std::string getName(void);

        /* Methods */
        
        void poke(void);
    protected:
    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */
