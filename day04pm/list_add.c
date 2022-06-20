/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** list_add
*/

#include "list.h"
#include <stdlib.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_front = malloc(sizeof(node_t));

    if (new_front == NULL)
        return false;
    new_front->value = elem;
    new_front->next = *front_ptr;
    *front_ptr = new_front;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new_back = malloc(sizeof(node_t));
    list_t data = *front_ptr;

    if (new_back == NULL)
        return false;
    new_back->value = elem;
    new_back->next = NULL;
    if (data == NULL)
        *front_ptr = new_back;
    else {
        for (; data->next != NULL; data = data->next);
        data->next = new_back;
    }
    return true;
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t new_back;
    list_t data = *front_ptr;

    if (list_get_size(data) < position)
        return false;
    if (position == 0){
        list_add_elem_at_front(front_ptr, elem);
        return true;
    }
    if (list_get_size(data) == position)
        return list_add_elem_at_back(front_ptr, elem);
    new_back = malloc(sizeof(node_t));
    if (new_back == NULL)
        return false;
    for (unsigned int i = 1; i < position; i++, data = data->next);
    new_back->value = elem;
    new_back->next = data->next;
    data->next = new_back;
    return true;
}
