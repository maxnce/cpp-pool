/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
        Picture(const Picture &pic);
        ~Picture();

        Picture &operator=(const Picture &copy);

        std::string *data;
        bool getPictureFromFile(const std::string &file);

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
