/*
** EPITECH PROJECT, 2022
** day06
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"
#include <iostream>

SickKoalaList::SickKoalaList(SickKoala *koala) : current_koala {koala}, next {nullptr}
{}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    return (this->next == nullptr);
}

void SickKoalaList::append(SickKoalaList *list)
{
    SickKoalaList *temp = this;
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

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *temp = this;
    while (temp != nullptr) {
        if (temp->current_koala->getName().compare(name) == 0)
            return (current_koala);
        temp = temp->next;
    }
    return nullptr;
}

SickKoala *SickKoalaList::getContent(void)
{
    return this->current_koala;
}

SickKoalaList *SickKoalaList::getNext(void)
{
    return this->next;
}

void SickKoalaList::dump(void)
{
    SickKoalaList *temp = this;
    std::cout << "Patients:";
    while (!temp->isEnd()) {
        std::cout << " " << temp->current_koala->getName() << ",";
        temp = temp->next;
    }
    std::cout << " " << temp->current_koala->getName() << "." << std::endl;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *to_remove)
{
    SickKoalaList *temp = this;
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

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *temp = this;
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

bool SickKoalaList::some(SickKoalaList *to_find)
{
    SickKoalaList *temp = this;
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