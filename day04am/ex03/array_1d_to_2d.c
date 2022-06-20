/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** array_1d_to_2d
*/

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int **tab = *res;
    int count = 0;

    tab = malloc(sizeof(int *) * (height + 1));
    tab[height] = NULL;
    for (int i = 0; i < height; i++) {
        tab[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++, count++)
            tab[i][j] = array[count];
    }
    *res = tab;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}
