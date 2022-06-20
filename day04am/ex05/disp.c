/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** disp
*/

#include <stdio.h>

void disp_int_array(int *array, size_t nmemb)
{
    for (int i = 0; i < nmemb; i++)
        printf("%d\n", array[i]);
}

void disp_array(const void *array, size_t nmemb, size_t size,
void (*print)(const void *))
{
    for (int i = 0; i < nmemb; i++) {
        print(array);
        array += size;
    }
}
