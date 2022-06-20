/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Command
*/

#include "Command.hpp"

Command::Command()
{
}

Command::~Command()
{
}

void Command::registerCommand(const std::string &name, const std::function<void()>& function)
{
    if (_map.count(name) > 0)
        throw Error("Already registered command");
    else _map[name] = function;
}

void Command::executeCommand(const std::string &name)
{
    if (_map.count(name) == 0)
        throw Error("Unknow command");
    else _map[name]();
}