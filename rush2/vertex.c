/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** vertex
*/

#include <stdio.h>
#include "vertex.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

char *Vertex_str(VertexClass *this)
{
    char *str = malloc(47);
    snprintf(str, 47, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

Object *Vertex_add(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((VertexClass *)a)->x + ((VertexClass *)b)->x,
    ((VertexClass *)a)->y + ((VertexClass *)b)->y,
    ((VertexClass *)a)->z + ((VertexClass *)b)->z);
    return res;
}

Object *Vertex_sub(const Object *a, const Object *b)
{
    Object *res;

    if (((Class *)a)->__name__ != ((Class *)b)->__name__)
        raise("Different classes");
    res = new(((Class *)a), ((VertexClass *)a)->x - ((VertexClass *)b)->x,
    ((VertexClass *)a)->y - ((VertexClass *)b)->y,
    ((VertexClass *)a)->z - ((VertexClass *)b)->z);
    return res;
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;