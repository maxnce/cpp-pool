/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_length
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int length(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return -1;
    return (int)strlen(this->str);
}