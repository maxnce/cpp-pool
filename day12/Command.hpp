/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <map>
#include <string>
#include <functional>

class Command {
    public:
        Command();
        ~Command();

        class Error : public std::exception {
            public:
                Error(std::string msg = "") {this->_msg = msg;}
                const char *what() const noexcept override { return _msg.c_str();}
            private:
                std::string _msg;
        };

        void registerCommand(const std::string &name, const std::function<void()>& function);

        void executeCommand(const std::string &name);

    protected:
    private:
        std::map<std::string, std::function<void()>> _map;
};

#endif /* !COMMAND_HPP_ */
