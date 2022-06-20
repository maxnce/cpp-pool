/*
** EPITECH PROJECT, 2022
** day04am
** File description:
** pyramid
*/

int is_smallest(int a, int b)
{
    return a > b ? b : a;
}

int pyramid_locator(unsigned int size, const unsigned int **map, int x, int y)
{
    if (size == 1 || size == 0)
        return map[x][y];
    return is_smallest(map[x][y] + pyramid_locator(size - 1, map, x + 1, y),
    map[x][y] + pyramid_locator(size - 1, map, x + 1, y + 1));
}

int pyramid_path(unsigned int size, const unsigned int **map)
{
    return pyramid_locator(size, map, 0, 0);
}