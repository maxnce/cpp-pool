/*
** EPITECH PROJECT, 2022
** day08
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
}

DroidMemory::DroidMemory(const DroidMemory &copy)
{
    this->Exp = copy.getSafeExp();
    this->Fingerprint = copy.getSafeFingerprint();
}

DroidMemory::~DroidMemory()
{
}

DroidMemory &DroidMemory::operator=(const DroidMemory &copy)
{
    DroidMemory *temp = new DroidMemory(copy);
    return (*temp);
}

void DroidMemory::setExp(size_t xp)
{
    this->Exp = xp;
}

size_t &DroidMemory::getExp()
{
    return this->Exp;
}

size_t DroidMemory::getSafeExp() const
{
    return this->Exp;
}

void DroidMemory::setFingerprint(size_t fp)
{
    this->Fingerprint = fp;
}

size_t &DroidMemory::getFingerprint()
{
    return this->Fingerprint;
}

size_t DroidMemory::getSafeFingerprint() const
{
    return this->Fingerprint;
}

DroidMemory &DroidMemory::operator<<(DroidMemory &right)
{
    this->Exp += right.getExp();
    this->Fingerprint = this->Fingerprint ^ right.getFingerprint();
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &right)
{
    right.getExp() += this->getExp();
    right.getFingerprint() = right.getFingerprint() ^ this->Fingerprint;
    return right;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &right)
{
    return operator<<(right);
}

DroidMemory &DroidMemory::operator+=(size_t xp)
{
    this->Exp += xp;
    this->Fingerprint = this->Fingerprint ^ xp;
    return *this;
}

DroidMemory &DroidMemory::operator+(size_t xp)
{
    DroidMemory *temp = new DroidMemory;
    temp->setExp(xp + this->Exp);
    temp->setFingerprint(this->Fingerprint ^ xp);
    return *temp;
}

DroidMemory &DroidMemory::operator+(DroidMemory &right)
{
    DroidMemory *temp = new DroidMemory;
    temp->setExp(this->Exp + right.getExp());
    temp->setFingerprint(this->Fingerprint ^ right.getFingerprint());
    return *temp;
}

std::ostream &operator<<(std::ostream &s, const DroidMemory &mem)
{
    s << "DroidMemory '" << mem.getSafeFingerprint() << "', " << mem.getSafeExp();
    return s;
}

bool DroidMemory::operator==(DroidMemory &other) const
{
    return (this->Exp == other.getExp()
        && this->Fingerprint == other.getFingerprint());
}

bool DroidMemory::operator!=(DroidMemory &other) const
{
    return !(this->Exp == other.getExp()
        && this->Fingerprint == other.getFingerprint());
}

bool DroidMemory::operator<=(DroidMemory &other) const
{
    return (this->Exp <= other.getExp());
}

bool DroidMemory::operator>=(DroidMemory &other) const
{
    return (this->Exp >= other.getExp());
}

bool DroidMemory::operator<(DroidMemory &other) const
{
    return (this->Exp < other.getExp());
}

bool DroidMemory::operator>(DroidMemory &other) const
{
    return (this->Exp > other.getExp());
}

bool DroidMemory::operator<=(size_t other) const
{
    return (this->Exp <= other);
}

bool DroidMemory::operator>=(size_t other) const
{
    return (this->Exp >= other);
}

bool DroidMemory::operator<(size_t other) const
{
    return (this->Exp < other);
}

bool DroidMemory::operator>(size_t other) const
{
    return (this->Exp > other);
}