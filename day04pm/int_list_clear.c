/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** int_list_clear
*/

#include "int_list.h"
#include <stdlib.h>

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t data = *front_ptr;
    int_list_t temp = data;
    data = data->next;

    for (; data != NULL; data = data->next) {
        free(temp);
        temp = data;
    }
    free(temp);
    *front_ptr = NULL;
}
