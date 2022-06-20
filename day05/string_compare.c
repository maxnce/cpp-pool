/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_compare
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || this->str == NULL)
        return (1);
    if (str == NULL || str->str == NULL)
        return (-1);
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || this->str == NULL)
        return (1);
    if (str == NULL)
        return (-1);
    return strcmp(this->str, str);
}