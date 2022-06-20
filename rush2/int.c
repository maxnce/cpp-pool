/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class base;
    int val;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->val = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

char *Int_str(IntClass *this)
{
    char *str = malloc(128);
    snprintf(str, 128, "<Int (%d)>", this->val);
    return (str);
}

Object *Int_add(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((IntClass *)a)->val + ((IntClass *)b)->val);
    return (res);
}

Object *Int_sub(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((IntClass *)a)->val - ((IntClass *)b)->val);
    return (res);
}

Object *Int_mul(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((IntClass *)a)->val * ((IntClass *)b)->val);
    return (res);
}

Object *Int_div(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    if (((IntClass *)b)->val == 0)
        raise("Division by zero");
    res = new(((Class *)a), ((IntClass *)a)->val / ((IntClass *)b)->val);
    return (res);
}

bool Int_eq(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((IntClass *)a)->val == ((IntClass *)b)->val);
}

bool Int_gt(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((IntClass *)a)->val > ((IntClass *)b)->val);
}

bool Int_lt(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((IntClass *)a)->val < ((IntClass *)b)->val);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .val = 0
};

const Class   *Int = (const Class *)&_description;
