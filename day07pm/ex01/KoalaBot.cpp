/*
** EPITECH PROJECT, 2022
** day07pm
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include <iostream>

KoalaBot::KoalaBot(std::string serial)
: head {new Head}, arms {new Arms}, legs {new Legs}
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot(void)
{
    this->head.release();
    this->arms.release();
    this->legs.release();
}

void KoalaBot::setParts(const Head &head)
{
    this->head.reset(&head);
}

void KoalaBot::setParts(const Arms &arms)
{
    this->arms.reset(&arms);
}

void KoalaBot::setParts(const Legs &legs)
{
    this->legs.reset(&legs);
}

void KoalaBot::swapParts(Head &head)
{
    const Head test = *this->head.get();
    this->head.release();
    this->head.reset(new Head(head));
    head = test;
}

void KoalaBot::swapParts(Arms &arms)
{
    const Arms test = *this->arms.get();
    this->arms.release();
    this->arms.reset(new Arms(arms));
    arms = test;
}

void KoalaBot::swapParts(Legs &legs)
{
    const Legs test = *this->legs.get();
    this->legs.release();
    this->legs.reset(new Legs(legs));
    legs = test;
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->arms->informations();
    this->legs->informations();
    this->head->informations();
}

bool KoalaBot::status(void) const
{
    return (this->arms->isFunctional() && this->head->isFunctional() && this->legs->isFunctional());
}