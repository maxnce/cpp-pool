/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <string>
#include <exception>

class Stack {
    public:
        Stack();
        ~Stack();

        class Error : public std::exception {
            public:
                Error(std::string msg = "") {this->_msg = msg;}
                const char *what() const noexcept override { return _msg.c_str();}
            private:
                std::string _msg;
        };

        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();

    protected:
    private:
        std::stack<double> _stack;
};

#endif /* !STACK_HPP_ */
