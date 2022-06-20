/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <exception>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>

class Shell {
    public:

        class Warning : public std::exception {
            public:
                Warning(std::string msg = "") {this->_msg = msg;}
                const char *what() const noexcept override { return _msg.c_str();}
            private:
                std::string _msg;
        };

        class Error : public std::exception {
            public:
                Error(std::string msg = "") {this->_msg = msg;}
                const char *what() const noexcept override { return _msg.c_str();}
            private:
                std::string _msg;
        };

        Shell(std::istream &is) : _stream {is} {
        };
        ~Shell();

        void next() {
            std::string temp;
            getline(_stream, temp);
            if (_stream.eof())
                throw Error("End of input");
            if(_stream.fail() || _stream.bad())
                throw Error("Input failed");
            line = std::stringstream(temp);
        }

        template<typename T>
        T extract()
        {
            T res;
            std::string temp;

            if (!(line >> res)) {
                throw Warning("Invalid conversion");
            }
            getline(line, temp, ' ');
            getline(line, temp);
            line = std::stringstream(temp);
            return res;
        }

    protected:
    private:
        std::istream &_stream;
        std::stringstream line;
};

#endif /* !SHELL_HPP_ */
