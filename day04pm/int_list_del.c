/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** int_list_get_size
*/

#include "int_list.h"
#include <stdlib.h>

bool int_list_del_elem_at_front(int_list_t *list)
{
    int_list_t data = *list;
    int_list_t to_free = data;
    if (data == NULL)
        return false;
    data = data->next;
    *list = data;
    free(to_free);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *list)
{
    int_list_t data = *list;

    if (data == NULL)
        return false;
    if (int_list_get_size(data) == 1)
        int_list_del_elem_at_front(list);
    for (; data->next->next != NULL; data = data->next);
    free(data->next);
    data->next = NULL;
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *list, unsigned int position)
{
    int_list_t data = *list;
    if (data == NULL || int_list_get_size(data) - 1 < position)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(list);
    if (position == int_list_get_size(data))
        return int_list_get_elem_at_back(list);
    for (unsigned int i = 1; i < position; data = data->next, i++);
    int_list_t to_free = data->next;
    data->next = data->next->next;
    free(to_free);
    return (true);
}
