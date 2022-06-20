/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_to_int
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return 0;
    return atoi(this->str);
}