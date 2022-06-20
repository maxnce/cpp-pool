/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** list_get
*/

#include "list.h"
#include <stdlib.h>

unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;
    for (; list != NULL; size++, list = list->next);
    return size;
}

void *list_get_elem_at_front(list_t list)
{
    return (list == NULL ? 0 : list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return 0;
    for (; list->next != NULL; list = list->next);
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL || list_get_size(list) <= position)
        return 0;
    if (position == 0)
        return list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position; list = list->next, i++);
    return (list->value);
}
