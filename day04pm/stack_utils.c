/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** stack_utils
*/

#include "list.h"
#include "stack.h"
#include <stdlib.h>

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}

void stack_clear(stack_t *stack_ptr)
{
    list_clear(stack_ptr);
}
