/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg{
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string name);
                std::string getName(void);
                int getAge(void);
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ensign {
            public:
                Ensign(std::string name);
            private:
                std::string _name;
        };
        class Ship {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                void promote(Federation::Starfleet::Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core = NULL;
                Federation::Starfleet::Captain *_captain = NULL;
                Destination _location = EARTH;
                Destination _home = EARTH;
                int _shield = 100;
                int _photonTorpedo;
        };
    };
    class Ship {
        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            WarpSystem::Core *getCore(void);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp = 1;
            WarpSystem::Core *_core;
            Destination _location = VULCAN;
            Destination _home = VULCAN;
    };
};

#endif /* !FEDERATION_HPP_ */
