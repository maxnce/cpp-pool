/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <string>
#include <exception>
#include <iostream>
#include <functional>

template<typename T, size_t N>
class Array {
    public:
        T array[N];
        Array() {};
        ~Array() {};

        T &operator[](int n) {
            if (static_cast<size_t>(n) < N)
                return this->array[n];
            throw std::range_error("Out of range");
            return array[0];
        }

        T operator[](int n) const {
            if (static_cast<size_t>(n) < N)
                return this->array[n];
            throw std::range_error("Out of range");
            return array[0];
        }

        std::size_t size() const {
            return N;
        }

        void forEach(const std::function<void(const T&)>& task) const {
            size_t i = 0;
            for (;i < N;i++)
                task(array[i]);
        }

        template<typename U>
        Array<U, N> convert(const std::function<U(const T&)> & converter) const {
            Array<U, N> temp;
            size_t i = 0;
            for (;i < N;i++)
                temp[i] = converter(array[i]);
            return temp;
        }

    protected:
    private:
};


template<typename T, size_t N>
std::ostream &operator<<(std::ostream &os, Array<T, N> arr)
{
    os << "[";
    os << arr[0];
    for (size_t i = 1; i < N; i++) {
        os << ", " << arr[i];
    }
    os << "]";
    return os;
}

#endif /* !ARRAY_HPP_ */
