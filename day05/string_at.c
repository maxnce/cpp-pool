/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_at
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL || strlen(this->str) <= pos)
        return (-1);
    return (this->str[pos]);
}