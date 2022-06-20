/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** int_list_dump
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

void int_list_dump(int_list_t list)
{
    for (; list != NULL; list = list->next) {
        printf("%d\n", list->value);
    }
}
