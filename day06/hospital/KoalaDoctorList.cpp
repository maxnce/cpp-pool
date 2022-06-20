/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"
#include <iostream>

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koala) : current_koala {koala}, next {nullptr}
{}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    return (this->next == nullptr);
}

void KoalaDoctorList::append(KoalaDoctorList *list)
{
    KoalaDoctorList *temp = this;
    if (this->some(list))
        return ;
    if (this->current_koala == NULL) {
        this->current_koala = list->current_koala;
        this->next = list->next;
        return ;
        }
    while (!temp->isEnd())
        temp = temp->next;
    temp->next = list;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *temp = this;
    while (temp != nullptr) {
        if (temp->current_koala->getName().compare(name) == 0)
            return (current_koala);
        temp = temp->next;
    }
    return nullptr;
}

KoalaDoctor *KoalaDoctorList::getContent(void)
{
    return this->current_koala;
}

KoalaDoctorList *KoalaDoctorList::getNext(void)
{
    return this->next;
}

void KoalaDoctorList::dump(void)
{
    KoalaDoctorList *temp = this;
    std::cout << "Doctors:";
    while (!temp->isEnd()) {
        std::cout << " " << temp->current_koala->getName() << ",";
        temp = temp->next;
    }
    std::cout << " " << temp->current_koala->getName() << "." << std::endl;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *to_remove)
{
    KoalaDoctorList *temp = this;
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *temp = this;
    if (this->current_koala && this->current_koala->getName().compare(name) == 0){
        temp = this->next;
        this->next = NULL;
        return temp;
    }
    while (!temp->next->isEnd()) {
        if (temp->next->current_koala && temp->next->current_koala->getName().compare(name) == 0) {
            temp->next = temp->next->next;
            return this;
        }
        temp = temp->next;
    }
    if (temp->next && temp->next->current_koala->getName().compare(name) == 0)
        temp->next = nullptr;
    return this;
}

bool KoalaDoctorList::some(KoalaDoctorList *to_find)
{
    KoalaDoctorList *temp = this;
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