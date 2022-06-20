/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include "Borg.hpp"

namespace Borg {
    class BorgQueen {
        public:
            void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
            bool move(Borg::Ship *ship, Destination dest);
            void destroy(Borg::Ship *ship, Federation::Ship *target);

            bool (Borg::Ship::*movePtr)(Destination) = &Borg::Ship::move;
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *) = &Borg::Ship::fire;
            void (Borg::Ship::*destroyPtr)(Federation::Ship *) = &Borg::Ship::fire;

        protected:
        private:
    };
};

#endif /* !BORGQUEEN_HPP_ */
