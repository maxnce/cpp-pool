/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:

        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        Toy();
        Toy(const Toy &toy);
        Toy(ToyType type, const std::string &name, const std::string &fp);
        ~Toy() {};

        Toy &operator=(const Toy &);
        Toy &operator<<(const std::string &);
        
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;
        virtual void speak(const std::string &);


    protected:
    private:
        std::string *_name;
        Picture *_picture;
        ToyType _type;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */
