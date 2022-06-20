/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_
#include "Federation.hpp"

namespace Federation::Starfleet {
    class Admiral {
        public:
            Admiral(std::string name);
            void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
            bool move(Federation::Starfleet::Ship *ship, Destination dest);

            bool (Federation::Starfleet::Ship::*movePtr)(Destination d) = &Federation::Starfleet::Ship::move;
            void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *target) = &Federation::Starfleet::Ship::fire;
        private:
            std::string _name;
    };
};

#endif /* !ADMIRAL_HPP_ */
