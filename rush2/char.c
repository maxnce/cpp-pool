/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class base;
    char val;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->val = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

char *Char_str(CharClass *this)
{
    char *str = malloc(128);
    snprintf(str, 128, "<Char (%c)>", this->val);
    return (str);
}

Object *Char_add(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((CharClass *)a)->val + ((CharClass *)b)->val);
    return (res);
}

Object *Char_sub(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((CharClass *)a)->val - ((CharClass *)b)->val);
    return (res);
}

Object *Char_mul(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((CharClass *)a)->val * ((CharClass *)b)->val);
    return (res);
}

Object *Char_div(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    if (((CharClass *)b)->val == 0)
        raise("Division by zero");
    res = new(((Class *)a), ((CharClass *)a)->val / ((CharClass *)b)->val);
    return (res);
}

bool Char_eq(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((CharClass *)a)->val == ((CharClass *)b)->val);
}

bool Char_gt(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((CharClass *)a)->val > ((CharClass *)b)->val);
}

bool Char_lt(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((CharClass *)a)->val < ((CharClass *)b)->val);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .val = '0'
};

const Class   *Char = (const Class *)&_description;
