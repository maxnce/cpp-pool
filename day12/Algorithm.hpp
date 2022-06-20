/*
** EPITECH PROJECT, 2022
** day12
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <algorithm>

template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
constexpr T min(T a, T b)
{
    return std::min(a, b);
}

template<typename T>
constexpr T max(T a, T b)
{
    return std::max(a, b);
}

template<typename T>
constexpr T clamp(T a, T b, T c)
{
    if (a < b) {
        return b;
    } else if (c < a) {
        return c;
        } else return a;
}

#endif /* !ALGORITHM_HPP_ */
