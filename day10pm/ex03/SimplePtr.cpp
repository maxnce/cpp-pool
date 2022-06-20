/*
** EPITECH PROJECT, 2022
** day10pm
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr)
{
    this->_rawPtr = rawPtr;
}

SimplePtr::~SimplePtr()
{
    delete this->_rawPtr;
}

BaseComponent *SimplePtr::get() const
{
    return this->_rawPtr;
}
