/*
** EPITECH PROJECT, 2020
** my_navy
** File description:
** map-desu
*/

#include <unistd.h>
#include <stdlib.h>

char **map_maker3(char **rsl)
{
    for (int i = 2; i < 10; i++) {
        rsl[i][0] = ((i - 1) + '0');
        rsl[i][1] = '|';
        for (int j = 2; j < 17; j++)
            if (j % 2 == 0)
                rsl[i][j] = '.';
            else
                rsl[i][j] = ' ';
    }
    return rsl;
}

char **map_maker2(char **rsl)
{
    int l = 'A';

    rsl[0][0] = ' ';
    rsl[0][1] = '|';
    for (int j = 2; j < 17; j++)
        if (j % 2 == 0)
            rsl[0][j] = l++;
        else
            rsl[0][j] = ' ';
    for (int j = 0; j < 17; j++)
        if (j == 1)
            rsl[1][j] = '+';
        else
            rsl[1][j] = '-';
    return map_maker3(rsl);
}

char **map_maker(void)
{
    char **rsl = (char **)malloc(11 * sizeof(char *));

    if (rsl == NULL)
        return NULL;
    rsl[10] = NULL;
    for (int i = 0; i < 10; i++) {
        rsl[i] = (char *)malloc((17 + 1) * sizeof(char));
        if (rsl[i] == NULL)
            return NULL;
        rsl[i][17] = '\0';
    }
    rsl = map_maker2(rsl);
    return rsl;
}