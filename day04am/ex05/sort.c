/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** sort
*/

#include <stdlib.h>
#include <string.h>

void sort_int_array(int *array, size_t nmemb)
{
    for (int i = 0; i < (int)nmemb; i++)
        for (int j = i + 1; j < (int)nmemb; j++)
            array[i] > array[j] ? my_swap(array[i], array[j]) : 0;
}

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void modify_array(void *array, size_t size, int i, int j)
{
    void *iptr = array + (i * size);
    void *jptr = array + (j * size);
    char temp[size];
    char temp2[size];
    memmove(temp, iptr, size);
    memmove(temp2, jptr, size);
    memmove(iptr, temp2, size);
    memmove(jptr, temp, size);
}

void sort_array(void *array, size_t nmemb, size_t size,
int (*compar)(const void *, const void *))
{
    for (int i = 0; i < (int)nmemb; i++)
        for (int j = i + 1; j < (int)nmemb; j++)
            compar(array + (i * size), array + (j * size)) > 0 ?
            modify_array(array, size, i, j) : 0;
}
