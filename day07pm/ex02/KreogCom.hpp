/*
** EPITECH PROJECT, 2022
** day07pm
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();

        void ping() const;
        void locateSquad() const;

        int getX();
        int getY();

    private:
        void setNext(KreogCom *);
        void removeLastCom();
        KreogCom *_next = nullptr;
        const int m_serial;
        const int _x;
        const int _y;
};

#endif /* !KREOGCOM_HPP_ */
