/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** int_list_get_size
*/

#include "int_list.h"
#include <stdlib.h>

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int size = 0;
    for (; list != NULL; size++, list = list->next);
    return size;
}

int int_list_get_elem_at_front(int_list_t list)
{
    return (list == NULL ? 0 : list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return 0;
    for (; list->next != NULL; list = list->next);
    return (list->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    if (list == NULL || int_list_get_size(list) <= position)
        return 0;
    if (position == 0)
        return int_list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position; list = list->next, i++);
    return (list->value);
}
