/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"
#include <iostream>

KoalaNurseList::KoalaNurseList(KoalaNurse *koala) : current_koala {koala}, next {nullptr}
{}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    return (this->next == nullptr);
}

void KoalaNurseList::append(KoalaNurseList *list)
{
    KoalaNurseList *temp = this;
    if (this->some(list))
        return;
    if (this->current_koala == NULL) {
        this->current_koala = list->current_koala;
        this->next = list->next;
        return ;
        }
    while (!temp->isEnd())
        temp = temp->next;
    temp->next = list;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *temp = this;
    while (temp != nullptr) {
        if (temp->current_koala->getID() == id)
            return (current_koala);
        temp = temp->next;
    }
    return nullptr;
}

KoalaNurse *KoalaNurseList::getContent(void)
{
    return this->current_koala;
}

KoalaNurseList *KoalaNurseList::getNext(void)
{
    return this->next;
}

void KoalaNurseList::dump(void)
{
    KoalaNurseList *temp = this;
    std::cout << "Nurses:";
    while (!temp->isEnd()) {
        std::cout << " " << temp->current_koala->getID() << ",";
        temp = temp->next;
    }
    std::cout << " " << temp->current_koala->getID() << "." << std::endl;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *to_remove)
{
    KoalaNurseList *temp = this;
    if (this == to_remove)
        return this->next;
    while (!temp->next->isEnd()) {
        if (temp->next == to_remove) {
            temp->next = temp->next->next;
            return this;
        }
        temp = temp->next;
    }
    if (temp->next == to_remove)
        temp->next = nullptr;
    return this;
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *temp = this;
    if (this->current_koala && this->current_koala->getID() == id){
        temp = this->next;
        this->next = NULL;
        return temp;
    }
    while (!temp->next->isEnd()) {
        if (temp->next->current_koala && temp->next->current_koala->getID() == id) {
            temp->next = temp->next->next;
            return this;
        }
        temp = temp->next;
    }
    if (temp->next && temp->next->current_koala->getID() == id)
        temp->next = nullptr;
    return this;
}

bool KoalaNurseList::some(KoalaNurseList *to_find)
{
    KoalaNurseList *temp = this;
    if (this == to_find)
        return true;
    if (temp->isEnd())
        return false;
    while (!temp->next->isEnd()) {
        if (temp->next == to_find)
            return true;
        temp = temp->next;
    }
    return temp->next == to_find;
}