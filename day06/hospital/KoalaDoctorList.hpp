/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *koala);
        ~KoalaDoctorList();

        /* Methods */
        bool isEnd(void);
        void append(KoalaDoctorList *to_append);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *to_remove);
        KoalaDoctorList *removeFromName(std::string name);
        KoalaDoctor *getContent(void);
        KoalaDoctorList *getNext(void);
        void dump(void);
        bool some(KoalaDoctorList *to_find);

    protected:
    private:
        KoalaDoctor *current_koala;
        KoalaDoctorList *next;
};

#endif /* !KOALADOCTORLIST_HPP_ */
