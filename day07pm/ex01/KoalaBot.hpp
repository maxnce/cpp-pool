/*
** EPITECH PROJECT, 2022
** day07pm
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_
#include "Parts.hpp"
#include <memory>

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        void setParts(const Head &head);
        void setParts(const Arms &arms);
        void setParts(const Legs &legs);
        void swapParts(Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void informations(void) const;
        bool status(void) const;

        std::unique_ptr<const Head> head;
        std::unique_ptr<const Arms> arms;
        std::unique_ptr<const Legs> legs;
    private:
        std::string _serial;
};

#endif /* !KOALABOT_HPP_ */
