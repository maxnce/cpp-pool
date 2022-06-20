/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_print
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void print(const string_t *this)
{
    printf("%s", this->str);
}