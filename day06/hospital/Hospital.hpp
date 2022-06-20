/*
** EPITECH PROJECT, 2022
** day06
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "SickKoalaList.hpp"
#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"

class Hospital {
    public:
        Hospital();
        ~Hospital();
        void run(void);
        void addDoctor(KoalaDoctorList *new_doctor);
        void addNurse(KoalaNurseList *new_nurse);
        void addSick(SickKoalaList *new_sick);

        SickKoalaList *patients;
        KoalaNurseList *nurses;
        KoalaDoctorList *doctors;
    protected:
    private:
};

#endif /* !HOSPITAL_HPP_ */
