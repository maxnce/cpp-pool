/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** concat
*/

#include "concat.h"

int my_strlen(char const *str)
{
    int i = 0;
    int total = 0;

    while (str[i] != '\0') {
        total++;
        i++;
    }
    return (total);
}

void concat_strings(const char *str1, const char *str2, char **res)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);
    char *test = *res;

    test = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
    test[len_str1 + len_str2] = '\0';
    for (int i = 0; i < len_str1; i++)
        test[i] = str1[i];
    for (int j = 0; j < len_str2; j++)
        test[len_str1 + j] = str2[j];
    *res = test;
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &(str->res));
}
