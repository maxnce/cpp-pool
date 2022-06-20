/*
** EPITECH PROJECT, 2022
** day07pm
** File description:
** KreogCom
*/

#include "KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial)
: m_serial {serial}, _x {x}, _y {y}
{
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    if (!this->getCom()) {
        this->_next = new KreogCom(x, y, serial);
        return;
    }
    KreogCom* next = this->getCom();
    this->_next = new KreogCom(x, y, serial);
    this->_next->setNext(next);
}

KreogCom *KreogCom::getCom()
{
    return this->_next;
}

void KreogCom::removeCom()
{
    KreogCom *temp = this;
    if (temp->_next == nullptr)
        return;
    KreogCom *del = temp->_next;
    temp->setNext(temp->getCom()->getCom());
    delete del;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *temp = this->_next;
    if (temp != nullptr) {
        while (temp != nullptr) {
            temp->ping();
            temp = temp->_next;
        }
    }
    this->ping();
}

void KreogCom::setNext(KreogCom *next)
{
    this->_next = next;
}