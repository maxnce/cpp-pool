/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** list_del
*/

#include "list.h"
#include <stdlib.h>

bool list_del_elem_at_front(list_t *list)
{
    list_t data = *list;
    list_t to_free = data;

    if (data == NULL)
        return false;
    data = data->next;
    *list = data;
    free(to_free);
    return (true);
}

bool list_del_elem_at_back(list_t *list)
{
    list_t data = *list;

    if (data == NULL)
        return false;
    if (list_get_size(data) == 1)
        list_del_elem_at_front(list);
    for (; data->next->next != NULL; data = data->next);
    free(data->next);
    data->next = NULL;
    return (true);
}

bool list_del_elem_at_position(list_t *list, unsigned int position)
{
    list_t data = *list;
    if (data == NULL || list_get_size(data) - 1 < position)
        return false;
    if (position == 0)
        return list_del_elem_at_front(list);
    if (position == list_get_size(data))
        return list_del_elem_at_back(list);
    for (unsigned int i = 1; i < position; data = data->next, i++);
    list_t to_free = data->next;
    data->next = data->next->next;
    free(to_free);
    return (true);
}