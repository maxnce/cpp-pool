/*
** EPITECH PROJECT, 2022
** day07am
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

bool WarpSystem::QuantumReactor::isStable(void)
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *reactor)
: _coreReactor {reactor}
{}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return this->_coreReactor;
}