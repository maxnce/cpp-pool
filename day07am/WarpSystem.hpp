/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            bool isStable(void);
            void setStability(bool stability);

        protected:
        private:
            bool _stability = true;
    };

    class Core {
        public:
            Core(QuantumReactor *reactor);
            QuantumReactor *checkReactor(void);

        private:
            QuantumReactor *_coreReactor;
    };
};

#endif /* !WARPSYSTEM_HPP_ */
