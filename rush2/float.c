/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class base;
    float val;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->val = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

char *Float_str(FloatClass *this)
{
    char *str = malloc(128);
    snprintf(str, 128, "<Float (%.6f)>", this->val);
    return (str);
}

Object *Float_add(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((FloatClass *)a)->val + ((FloatClass *)b)->val);
    return (res);
}

Object *Float_sub(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((FloatClass *)a)->val - ((FloatClass *)b)->val);
    return (res);
}

Object *Float_mul(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((FloatClass *)a)->val * ((FloatClass *)b)->val);
    return (res);
}

Object *Float_div(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    if (((FloatClass *)b)->val == 0)
        raise("Division by zero");
    res = new(((Class *)a), ((FloatClass *)a)->val / ((FloatClass *)b)->val);
    return (res);
}

bool Float_eq(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((FloatClass *)a)->val == ((FloatClass *)b)->val);
}

bool Float_gt(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((FloatClass *)a)->val > ((FloatClass *)b)->val);
}

bool Float_lt(const Object *a, const Object *b)
{
    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    return (((FloatClass *)a)->val < ((FloatClass *)b)->val);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .val = (float)0
};

const Class   *Float = (const Class *)&_description;
