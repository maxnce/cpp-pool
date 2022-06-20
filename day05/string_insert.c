/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_insert
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (this == NULL || this->str == NULL || str == NULL ||
    str->str == NULL)
        return ;
    insert_c(this, pos, str->str);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    if (this == NULL || this->str == NULL || str == NULL)
        return ;
    if (pos > strlen(this->str))
        this->append_c(this, str);
    this->str = realloc(this->str, strlen(this->str) + strlen(str) + 1);
    memmove(this->str + pos + strlen(str), this->str + pos, strlen(str));
    memmove(this->str + pos, str, strlen(str));
}