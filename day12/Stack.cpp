/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Stack
*/

#include "Stack.hpp"
#include <iostream>

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(double value)
{
    this->_stack.push(value);
}

double Stack::pop()
{
    double res;
    if (this->_stack.size() == 0) {
        throw Error("Empty stack");
    }
    res = this->_stack.top();
    this->_stack.pop();
    return res;
}

double Stack::top() const {
    if (this->_stack.size() == 0) {
        throw Error("Empty stack");
    }
    return this->_stack.top();
}

void Stack::add()
{
    double a;
    double b;
    if (this->_stack.size() < 2) {
        throw Error("Not enough operands");
    }
    a = this->top();
    this->_stack.pop();
    b = this->top();
    this->_stack.pop();
    double c = a + b;
    this->_stack.push(c);
}

void Stack::sub()
{
    double a;
    double b;
    if (this->_stack.size() < 2) {
        throw Error("Not enough operands");
    }
    a = this->top();
    this->_stack.pop();
    b = this->top();
    this->_stack.pop();
    double c = a - b;
    this->_stack.push(c);
}

void Stack::mul()
{
    double a;
    double b;
    if (this->_stack.size() < 2) {
        throw Error("Not enough operands");
    }
    a = this->top();
    this->_stack.pop();
    b = this->top();
    this->_stack.pop();
    double c = a * b;
    this->_stack.push(c);
}

void Stack::div()
{
    double a;
    double b;
    if (this->_stack.size() < 2) {
        throw Error("Not enough operands");
    }
    a = this->top();
    this->_stack.pop();
    b = this->top();
    if (b == 0) {
        this->_stack.push(a);
        throw Error("Division by zero");
    }
    this->_stack.pop();
    double c = a / b;
    this->_stack.push(c);
}