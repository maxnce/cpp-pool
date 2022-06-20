/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *koala);
        ~KoalaNurseList();

        /* Methods */
        bool isEnd(void);
        void append(KoalaNurseList *to_append);
        KoalaNurse *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *to_remove);
        KoalaNurseList *removeFromID(int id);
        KoalaNurse *getContent(void);
        KoalaNurseList *getNext(void);
        void dump(void);
        bool some(KoalaNurseList *to_find);

    protected:
    private:
        KoalaNurse *current_koala;
        KoalaNurseList *next;
};

#endif /* !KOALANURSELIST_HPP_ */
