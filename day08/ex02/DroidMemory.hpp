/*
** EPITECH PROJECT, 2022
** day08
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>
#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        DroidMemory(const DroidMemory &copy);
        ~DroidMemory();

        size_t &getExp(void);
        size_t &getFingerprint(void);
        size_t getSafeExp() const;
        size_t getSafeFingerprint() const;
        void setExp(size_t);
        void setFingerprint(size_t);

        DroidMemory &operator<<(DroidMemory &);
        DroidMemory &operator>>(DroidMemory &);
        DroidMemory &operator+=(DroidMemory &);
        DroidMemory &operator+=(size_t);
        DroidMemory &operator+(DroidMemory &);
        DroidMemory &operator+(size_t);
        DroidMemory &operator=(const DroidMemory &copy);
        bool operator==(DroidMemory &) const;
        bool operator!=(DroidMemory &) const;
        bool operator<=(DroidMemory &) const;
        bool operator>=(DroidMemory &) const;
        bool operator<(DroidMemory &) const;
        bool operator>(DroidMemory &) const;
        bool operator<=(size_t) const;
        bool operator>=(size_t) const;
        bool operator<(size_t) const;
        bool operator>(size_t) const;

    private:
        size_t Fingerprint = random();
        size_t Exp = 0;
};

std::ostream &operator<<(std::ostream &s, const DroidMemory &droid);

#endif /* !DROIDMEMORY_HPP_ */
