/*
** EPITECH PROJECT, 2022
** day11
** File description:
** ToyStory
*/

#include "ToyStory.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "Buzz.hpp"
#include "Woody.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void ToyStory::tellMeAStory(std::string fp, Toy toy1, bool (Toy::*func1)(const std::string &), Toy toy2, bool (Toy::*func2)(const std::string &))
{
    std::ifstream story(fp);
    bool isFirstToyTurn = true;
    bool hasError = false;

    if (story.fail()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    std::cout << toy1.getAscii() << std::endl << toy2.getAscii() << std::endl;
    for (std::string action; std::getline(story, action) ;)
    {
        hasError = false;
        if (std::strncmp(action.c_str(), "picture:", 8) == 0) {
            std::string fp = action.substr(8);
            if (!(isFirstToyTurn ? toy1 : toy2).setAscii(fp)) {
                hasError = true;
                std::cout << (isFirstToyTurn ? toy1 : toy2).getLastError().where() << ": " << (isFirstToyTurn ? toy1 : toy2).getLastError().what() << std::endl;
                return ;
            }
            std::cout << (isFirstToyTurn ? toy1 : toy2).getAscii() << std::endl;
        } else {
            if (isFirstToyTurn) {
                hasError = (toy1.*func1)(action);
            } else {
                hasError = (toy2.*func2)(action);
            } if (!hasError) {
                std::cout << (isFirstToyTurn ? toy1 : toy2).getLastError().where() << ": " << (isFirstToyTurn ? toy1 : toy2).getLastError().what() << std::endl;
                return ;
            }
        }
    }
}