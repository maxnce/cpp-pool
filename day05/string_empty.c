/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_empty
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int empty(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return 1;
    return 0;
}