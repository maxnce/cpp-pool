/*
** EPITECH PROJECT, 2022
** day06
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"
#include <iostream>
#include <fstream>

KoalaNurse::KoalaNurse(int id) : id {id}
{
    this->_is_working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::timeCheck(void)
{
    if (this->_is_working)
        std::cout << "Nurse " << this->id <<": Time to go home to my eucalyptus forest!" << std::endl;
    else
        std::cout << "Nurse " << this->id <<": Time to get to work!" << std::endl;
    this->_is_working = !this->_is_working;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *sick_koala)
{
    if (sick_koala == NULL)
        return;
    sick_koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string extension(".report");
    std::string err("");
    std::string drug("");

    if (filename.length() <= 7 || filename.compare(filename.length() - 7, 7, extension) != 0)
        return err;
    std::ifstream file(filename);
    if (file.fail())
        return err;
    getline(file, drug);
    if (drug.empty())
        return err;
    std::string koala_name(filename.substr(0, filename.length() - 7));
    std::cout << "Nurse " << this->id << ": Kreog! Mr." << koala_name << " needs a " << drug << "!" << std::endl;
    return drug;
}

int KoalaNurse::getID(void)
{
    return this->id;
}