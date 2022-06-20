/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_find
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *temp;

    if (this == NULL || this->str == NULL || str == NULL ||
    str->str == NULL || pos > strlen(this->str) ||
    strlen(str->str) > strlen(this->str) - pos)
        return -1;
    temp = strstr(this->str, str->str);
    return (temp == NULL ? -1 : temp - this->str);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *temp;

    if (this == NULL || this->str == NULL || str == NULL ||
    pos > strlen(this->str) || strlen(str) > strlen(this->str) - pos)
        return -1;
    temp = strstr(this->str, str);
    return (temp == NULL ? -1 : temp - this->str);
}