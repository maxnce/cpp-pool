/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** list_utils
*/

#include "list.h"
#include <stdlib.h>

bool list_is_empty(list_t list)
{
    return (list == NULL);
}

void list_clear(list_t *front_ptr)
{
    list_t data = *front_ptr;
    list_t temp = data;
    data = data->next;

    for (; data != NULL; data = data->next) {
        free(temp);
        temp = data;
    }
    free(temp);
    *front_ptr = NULL;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (; list != NULL; list = list->next)
        val_disp(list->value);
}