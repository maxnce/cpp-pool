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
            ALIEN
        };

        Toy();
        Toy(ToyType type, const std::string &name, const std::string &fp);
        ~Toy() {};
        
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;


    protected:
    private:
        std::string *_name;
        Picture *_picture;
        ToyType _type;
};

#endif /* !TOY_HPP_ */
