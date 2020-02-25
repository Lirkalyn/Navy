/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** switchs
*/

#include <stdlib.h>

char *replace_str_n(char *str, int *src, int pos)
{
    int i;
    int j;
    int len;
    char *res;

    *src = pos;
    for (len = 0; str[len] != '\0'; len++);
    res = (char *)malloc((len - 1) * sizeof(char));
    res[(len - 2)] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    j = (i + 2);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}