/*
** EPITECH PROJECT, 2022
** day06
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *koala);
        ~SickKoalaList();

        /* Methods */
        bool isEnd(void);
        void append(SickKoalaList *to_append);
        SickKoala *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *to_remove);
        SickKoalaList *removeFromName(std::string name);
        SickKoala *getContent(void);
        SickKoalaList *getNext(void);
        void dump(void);
        bool some(SickKoalaList *to_find);
        
    protected:
    private:
        SickKoala *current_koala;
        SickKoalaList *next;
};

#endif /* !SICKKOALALIST_HPP_ */
