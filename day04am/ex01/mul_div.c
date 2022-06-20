/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** mult_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = b == 0 ? 42 : a / b;
}

void mul_div_short(int *a, int *b)
{
    int temp = *a;
    *a = temp * *b;
    *b = *b == 0 ? 42 : (temp / *b);
}
