/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_append
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *temp;
    if (this == NULL || this->str == NULL || ap == NULL || ap->str == NULL)
        return;
    temp = strdup(ap->str);
    this->str = realloc(this->str, strlen(temp) + strlen(this->str) + 1);
    this->str = strcat(this->str, temp);
    free(temp);
}

void append_c(string_t *this, const char *ap)
{
    if (this == NULL || this->str == NULL || ap == NULL)
        return;
    this->str = realloc(this->str, strlen(ap) + strlen(this->str) + 1);
    this->str = strcat(this->str, ap);
}