/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** print
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *dup = strdup((char *)str);
    int j = strlen(str) - 1;
    char temp;

    for (int i = 0; i <= j; i++, j--) {
        temp = dup[i];
        dup[i] = dup[j];
        dup[j] = temp;
    }
    printf("%s\n", dup);
    free(dup);
}

void print_upper(const char *str)
{
    char *dup = strdup((char *)str);
    for (int i = 0; dup[i]; i++) {
        if (dup[i] >= 'a' && dup[i] <= 'z')
            dup[i] -= 32;
    }
    printf("%s\n", dup);
    free(dup);
}

void print_42(const char *str)
{
    printf("%d\n", 42);
}

void do_action(action_t action, const char *str)
{
    void (*pt_normal)(const char *) = print_normal;
    void (*pt_reverse)(const char *) = print_reverse;
    void (*pt_upper)(const char *) = print_upper;
    void (*pt_42)(const char *) = print_42;
    void (*action_functions[])(const char *) =
    {pt_normal, pt_reverse, pt_upper, pt_42};
    action_functions[action](str);
}
