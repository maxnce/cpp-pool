/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** uniq
*/

#include <stdlib.h>
#include <string.h>

void free_ref(int **reference, int *final, size_t nmemb)
{
    free(reference);
    free(final);
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int **reference = malloc(sizeof(char *) * nmemb);
    int *final;
    size_t tempnmemb = nmemb;
    int count = 0;
    for (int i = 0; i < nmemb; i++)
        reference[i] = &array[i];
    for (int i = 0; i < nmemb; i++){
        for (int j = i + 1; j < nmemb && reference[i] != NULL; j++)
            array[i] == array[j] ?
            int_erase_reference(reference, j, &tempnmemb) : 0;
    }
    final = malloc(sizeof(int) * tempnmemb);
    for (int i = 0; i < tempnmemb; count++) {
        if (reference[count] != NULL) {
            final[i] = *reference[count];
            i++;
        }
    }
    memmove(array, final, 4 * tempnmemb);
    free_ref(reference, final, nmemb);
    return (tempnmemb);
}

void int_erase_reference(int **reference, int j, int *tempnmemb)
{
    reference[j] = NULL;
    (*tempnmemb)--;
}

void erase_reference(void **reference, int j, int *tempnmemb)
{
    reference[j] = NULL;
    (*tempnmemb)--;
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
int (*compar) (const void *, const void *))
{
    void **reference = malloc(sizeof(void *) * nmemb);
    void *final;
    int count = 0;
    int tempnmemb = nmemb;
    for (int i = 0; i < nmemb; i++)
        reference[i] = array + (i * size);
    for (int i = 0; i < nmemb; i++){
        for (int j = i + 1; j < nmemb && reference[i] != NULL; j++) {
            compar(array + size * i, array + size * j) == 0 ?
            erase_reference(reference, j, &tempnmemb) : 0;
        }
    }
    final = malloc(sizeof(void *) * tempnmemb);
    for (int i = 0; i < tempnmemb; count++) {
        if (reference[count] != NULL)
            memmove(final + i++ * size, reference[count], size);
        }
    memmove(array, final, size * tempnmemb);
    free(final);
    free(reference);
    return (tempnmemb);
}
