/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_cstr
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this)
        return NULL;
    return this->str;
}