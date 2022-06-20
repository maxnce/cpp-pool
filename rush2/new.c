/*
** EPITECH PROJECT, 2022
** B-PDG-300-LYN-3-1-PDGRUSH2-adrien.bonvallet
** File description:
** new
*/

#include "new.h"
#include "player.h"

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__ != NULL)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}

Object *va_new(const Class *class, va_list* ap)
{
    Class* obj = malloc(class->__size__);

    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, ap);
    return (obj);
}

Object *new(const Class *class, ...)
{
    va_list parametersInfos;
    Class* obj = malloc(class->__size__);

    if (obj == NULL)
        raise("Not enough memory");
    va_start(parametersInfos, class);
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, &parametersInfos);
    return (obj);
}