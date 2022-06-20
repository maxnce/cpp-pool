/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** int_list_add_elem_at_front
*/

#include "int_list.h"
#include <stdlib.h>

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new_front = malloc(sizeof(int_node_t));

    if (new_front == NULL)
        return false;
    new_front->value = elem;
    new_front->next = *front_ptr;
    *front_ptr = new_front;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new_back = malloc(sizeof(int_node_t));
    int_list_t data = *front_ptr;

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

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_list_t new_back;
    int_list_t data = *front_ptr;

    if (position == 0){
        int_list_add_elem_at_front(front_ptr, elem);
        return true;
    }
    if (int_list_get_size(data) < position)
        return false;
    if (int_list_get_size(data) == position)
        return int_list_add_elem_at_back(front_ptr, elem);
    new_back = malloc(sizeof(int_node_t));
    if (new_back == NULL)
        return false;
    for (unsigned int i = 1; i < position; i++, data = data->next);
    new_back->value = elem;
    new_back->next = data->next;
    data->next = new_back;

    return true;
}
