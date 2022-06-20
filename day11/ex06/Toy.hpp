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
        virtual bool speak(const std::string &);
        virtual bool speak_es(const std::string &);
        static class Error {
            public:
                enum errorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };
                Error(const std::string &message, const std::string &func, errorType type) {
                    this->message = new std::string(message);
                    this->func = new std::string(func);
                    this->type = type;
                };
                std::string what() const;
                std::string where() const;
                errorType type;
            private:
                std::string *message;
                std::string *func;
        } err;
        Error getLastError();


    protected:
    private:
        Error *_err = nullptr;
        std::string *_name;
        Picture *_picture;
        ToyType _type;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */
