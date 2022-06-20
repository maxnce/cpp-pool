/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string_split
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

string_t **split_s(const string_t *this, char separator)
{
    char separators[2] = {separator, '\0'};
    char *token = strtok(this->str, separators);
    string_t **tab = malloc(sizeof(string_t *));
    int i = 1;

    for (; token != NULL; i++, token = strtok(NULL, separators)) {
        tab = realloc(tab, i * (sizeof(string_t *) + 1));
        string_t *temp = malloc(sizeof(string_t));
        string_init(temp, token);
        tab[i - 1] = temp;
    }
    tab[i - 1] = NULL;
    return tab;
}

char **split_c(const string_t *this, char separator)
{
    char separators[2] = {separator, '\0'};
    char *token = strtok(this->str, separators);
    char **tab = malloc(sizeof(char *));
    int i = 1;

    for (; token != NULL; i++, token = strtok(NULL, separators)) {
        tab = realloc(tab, i * (sizeof(string_t *) + 1));
        tab[i - 1] = token;
    }
    tab[i - 1] = NULL;
    return tab;
}