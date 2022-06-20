/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_clear
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void clear(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this->str = strdup("");
}