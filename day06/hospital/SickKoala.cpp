/*
** EPITECH PROJECT, 2022
** day06
** File description:
** SickKoala
*/

#include "SickKoala.hpp"
#include <iostream>

SickKoala::SickKoala(std::string name) : name {name} {};

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
        return true;
    }
    if (drug == "Kinder") {
        std::cout << "Mr." << this->name << ": There is a toy inside!" << std::endl;
        return true;
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return false;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

void SickKoala::overDrive(std::string sentence)
{
    size_t i = sentence.find("Kreog!");
    while (i != std::string::npos) {
        sentence.replace(i, 6, "1337!");
        i = sentence.find("Kreog!");
    }
    std::cout << "Mr." << this->name << ": " << sentence << std::endl;
}

std::string SickKoala::getName(void) {
    return this->name;
}