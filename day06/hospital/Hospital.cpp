/*
** EPITECH PROJECT, 2022
** day06
** File description:
** Hospital
*/

#include "Hospital.hpp"
#include <iostream>

Hospital::Hospital() : patients {new SickKoalaList(nullptr)}, nurses {new KoalaNurseList(nullptr)}, doctors {new KoalaDoctorList(nullptr)}
{
}

Hospital::~Hospital()
{
    delete this->patients;
    delete this->nurses;
    delete this->doctors;
}

void Hospital::addDoctor(KoalaDoctorList *new_doctor)
{
    if (new_doctor->getContent() == nullptr)
        return ;
    if (this->doctors->some(new_doctor))
        return ;
    this->doctors->append(new_doctor);
    std::cout << "[HOSPITAL] Doctor " << new_doctor->getContent()->getName() << " just arrived!" << std::endl;
    new_doctor->getContent()->timeCheck();
}

void Hospital::addNurse(KoalaNurseList *new_nurse)
{
    if (new_nurse->getContent() == nullptr)
        return ;
    if (this->nurses->some(new_nurse))
        return ;
    this->nurses->append(new_nurse);
    std::cout << "[HOSPITAL] Nurse " << new_nurse->getContent()->getID() << " just arrived!" << std::endl;
    new_nurse->getContent()->timeCheck();
}

void Hospital::addSick(SickKoalaList *new_sick)
{
    if (new_sick->getContent() == nullptr)
        return ;
    if (this->patients->some(new_sick))
        return ;
    this->patients->append(new_sick);
    std::cout << "[HOSPITAL] Patient " << new_sick->getContent()->getName() << " just arrived!" << std::endl;
}

void Hospital::run(void)
{
    KoalaDoctorList *temp_doctor = this->doctors;
    KoalaNurseList *temp_nurses = this->nurses;
    SickKoalaList *temp_sicks = this->patients;
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;

    this->doctors->dump();
    this->nurses->dump();
    this->patients->dump();
    std::cout << std::endl;

    if (temp_doctor->isEnd() || temp_nurses->isEnd() || temp_sicks->isEnd())
        return;
    
    for (; !temp_sicks->isEnd(); temp_sicks = temp_sicks->getNext()) {
        temp_doctor->getContent()->diagnose(temp_sicks->getContent());
        temp_nurses->getContent()->giveDrug(temp_nurses->getContent()->readReport(temp_sicks->getContent()->getName() + ".report"),
        temp_sicks->getContent());
        temp_doctor = temp_doctor->isEnd() ? this->doctors : temp_doctor->getNext();
        temp_nurses = temp_nurses->isEnd() ? this->nurses : temp_nurses->getNext();
    }
    temp_doctor->getContent()->diagnose(temp_sicks->getContent());
    temp_nurses->getContent()->giveDrug(temp_nurses->getContent()->readReport(temp_sicks->getContent()->getName() + ".report"),
    temp_sicks->getContent());

    temp_doctor = this->doctors;
    temp_nurses = this->nurses;

    for (; !temp_nurses->isEnd(); temp_nurses = temp_nurses->getNext())
        temp_nurses->getContent()->timeCheck();
    temp_nurses->getContent()->timeCheck();

    for (; !temp_doctor->isEnd(); temp_doctor = temp_doctor->getNext())
        temp_doctor->getContent()->timeCheck();
    temp_doctor->getContent()->timeCheck();
}