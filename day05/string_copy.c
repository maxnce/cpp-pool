/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_copy
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    if (pos > strlen(this->str))
        return 0;
    strncpy(s, this->str + pos, n);
    return n + pos > strlen(this->str) ? strlen(s) + 1 : strlen(s);
}