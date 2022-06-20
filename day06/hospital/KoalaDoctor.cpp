/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"
#include <iostream>
#include <fstream>

KoalaDoctor::KoalaDoctor(std::string name) : name {name}
{
    this->_is_working = false;
    std::cout << "Dr." << this->name << ": I'm Dr." << this->name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {}

void KoalaDoctor::timeCheck(void)
{
    if (this->_is_working)
        std::cout << "Dr." << this->name <<": Time to go home to my eucalyptus forest!" << std::endl;
    else
        std::cout << "Dr." << this->name <<": Time to get to work!" << std::endl;
    this->_is_working = !this->_is_working;
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string drugs[5] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};
    if (patient == NULL)
        return ;
    std::cout << "Dr." << this->name <<": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    std::string filename(patient->getName() + ".report");
    std::ofstream report(filename.c_str());
    if (report.fail())
        return;
    patient->poke();
    report << drugs[random() % 5];
}

std::string KoalaDoctor::getName(void)
{
    return (this->name);
}