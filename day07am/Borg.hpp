/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ensign;
        class Ship;
    };
    class Ship;
};

namespace Borg{
    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency(void);
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair(void);

        protected:
        private:
            int _side = 300;
            short _maxWarp = 9;
            WarpSystem::Core *_core;
            Destination _home = UNICOMPLEX;
            Destination _location = UNICOMPLEX;
            int _shield = 100;
            int _weaponFrequency;
            short _repair;
    };
}

#endif /* !BORG_HPP_ */
