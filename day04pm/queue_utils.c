/*
** EPITECH PROJECT, 2022
** day04pm
** File description:
** queue_utils
*/

#include "list.h"
#include "queue.h"
#include <stdlib.h>


unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}

void queue_clear(queue_t *queue_ptr)
{
    list_clear(queue_ptr);
}
